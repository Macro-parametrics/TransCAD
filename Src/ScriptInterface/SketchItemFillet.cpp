#include "stdafx.h"
#include "SketchItemFillet.h"
#include "SketchItemLine.h"
#include "SketchItemArc.h"

SketchItemFillet::SketchItemFillet(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
	_isReversed = false;
}

SketchItemFillet::~SketchItemFillet(void)
{
}

void SketchItemFillet::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_lineNames.push_back(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_lineNames.push_back(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_radius = atof(token.c_str());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetSketch()->GetSketchItemByName(_lineNames[0]) || !GetSketch()->GetSketchItemByName(_lineNames[1]), "Enter existing lines!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketch()->GetSketchItemByName(_lineNames[0])->GetType() != 0, "Only line type is allowed!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketch()->GetSketchItemByName(_lineNames[1])->GetType() != 0, "Only line type is allowed!");
	TSIThrowExceptionIf<TSIArgumentException>(_lineNames[0] == _lineNames[1], "Two lines should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_radius <= 0, "Radius should be greater than zero!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetArcCenterStartEnd(), "Invalid input parameters!");

	Create();
}

void SketchItemFillet::Create(void)
{
	SketchItemLine * pFirstLine = dynamic_cast<SketchItemLine *>(GetSketch()->GetSketchItemByName(_lineNames[0]));
	SketchItemLine * pSecondLine = dynamic_cast<SketchItemLine *>(GetSketch()->GetSketchItemByName(_lineNames[1]));
	
	// 호의 이름 설정. 기존에 존재하는 호의 개수를 구함
	int _index = 1;

	for (int i = 0; i < GetSketch()->GetSketchItemListSize(); ++i)
		if (GetSketch()->GetSketchItem(i)->GetType() == 3)
			_index++;

	char _arcName[256];
	sprintf_s(_arcName, "Arc%d", _index);

	// 두 라인과 호를 생성
	pFirstLine->Create();
	
	SketchItemArc * pArc = 0;

	if (_isReversed)
		pArc = new SketchItemArc(GetSketch(), (int)3, _arcName, _centerPoint, _contactPoint[1], _contactPoint[0]);
	else
		pArc = new SketchItemArc(GetSketch(), (int)3, _arcName, _centerPoint, _contactPoint[0], _contactPoint[1]);
	
	GetSketch()->SetSketchItem(pArc);
	pArc->Create();
	
	pSecondLine->Create();

	if (GetSketch()->IsModified())
	{
		pFirstLine->SetModified(true);
		pArc->SetCreated(true);
		pSecondLine->SetModified(true);
	}
	//
}

bool SketchItemFillet::GetArcCenterStartEnd(void)
{
	Point2D _linePoints[2][2];			// 두 라인의 시작점 및 끝점
	Point2D _intPoint, _nIntPoint[2];	// 교점(_intPoint) 및 나머지 한점 (_nIntPoint)
	Direct2D uV[2], cV;					// uV[0]: 첫 번째 라인의 방향벡터, uV[1]: 두 번째 라인의 방향 벡터, cV: 중심 벡터
	double a[2], b[2];					// y = ax + b에서의 기울기(a)와 y절편(b)
	
	SketchItemLine * pLines[2];

	// 입력 받은 두 라인의 정보를 가져옴

	for (int i = 0; i < 2; ++i)
	{
		pLines[i] = dynamic_cast<SketchItemLine *>(GetSketch()->GetSketchItemByName(_lineNames[i]));
		_linePoints[i][0].SetXY(pLines[i]->GetStartPoint());
		_linePoints[i][1].SetXY(pLines[i]->GetEndPoint());
	}

	 // 두 직선의 방정식 구하기
	for (int i = 0; i < 2; ++i)
		GetLineEquation(_linePoints[i][0], _linePoints[i][1], a[i], b[i]);

	 // 두 직선의 교점 구하기
	if (!GetIntersectingPoint(a, b, _intPoint))
		return false;

	// 각 직선에 대해 교점으로부터 더 멀리 떨어진 점 및 유닛 벡터 구하기
	for (int i = 0; i < 2; ++i)
	{
		GetDistantPoint(_intPoint, _linePoints[i][0], _linePoints[i][1], _nIntPoint[i]);
		uV[i].SetXY(_nIntPoint[i] - _intPoint);
		uV[i] = uV[i].Norm();
	}

	cV.SetXY(uV[0] + uV[1]); cV = cV.Norm();	// 두 유닛 벡터의 합벡터 (중심 벡터)
	
	// 첫 번째 유닛 벡터가 중심 벡터의 우측에 있으면 방향을 전환
	double cross = cV^uV[0];
	if ( cross < 0.0)
		_isReversed = true;

	// 최대 허용 반지름 구하기
	if (!CheckMaximumRadius(_intPoint.GetDistance(_nIntPoint[0]), _intPoint.GetDistance(_nIntPoint[1]), acos(cross)))
		return false;

	// 중점과 두 접점 구하기
	GetCircleBetweenLines(a, b, _intPoint, cV, _radius);

	// 두 라인의 좌표 수정 및 스케치에서 제거
	for (int i = 0; i < 2; ++i)
	{
		if (!IsDifferentPoint(_nIntPoint[i], _contactPoint[i]))
			return false;

		pLines[i]->SetStartPoint(_nIntPoint[i]);
		pLines[i]->SetEndPoint(_contactPoint[i]);
		
		GetSketch()->GetEditorPtr()->DeleteByName(pLines[i]->GetName().c_str());
	}

	return true;
}

void SketchItemFillet::GetCircleBetweenLines(double a[2], double b[2], Point2D intPoint, Direct2D uV, double radius)
{
	double sign1, sign2;	// +,- 부호
	double c[2];			// 원의 중심
	Direct2D cV;			// 교점과 중점을 잇는 벡터

	for (int i = 1; i <= 4; ++i)
	{
		// +,- 부호 지정
		sign1 = -1.0; sign2 = pow(-1.0 , i);
		if (i <= 2)
			sign1 = 1.0;
		
		if (a[0] == infinity)
		{
			c[0] = -b[0] + (sign1)*radius;
			c[1] = a[1]*c[0] + b[1] + (sign2)*radius*sqrt(a[1]*a[1] + 1);
		}
		else if (a[1] == infinity)
		{
			c[0] = -b[1] + (sign1)*radius;
			c[1] = a[0]*c[0] + b[0] + (sign2)*radius*sqrt(a[0]*a[0] + 1);
		}
		else
		{
			c[0] = (radius*((-1)*(sign2)*sqrt(a[0]*a[0] + 1) + (sign1)*sqrt(a[1]*a[1] + 1)) - (b[0] - b[1]))/(a[0] - a[1]);
			c[1] = a[0]*c[0] + b[0] + (sign2)*radius*sqrt(a[0]*a[0]+1);
		}
		
		// 교점과 중점을 잇는 벡터
		cV.SetXY(c[0] - intPoint.X(), c[1] - intPoint.Y());
		cV = cV.Norm();

		// 입력받은 중점 벡터(uV)와 cV가 같은 경우, 해당 점을 원의 중점으로 선정.
		if (abs(uV.X() - cV.X()) <= tolerance && abs(uV.Y() - cV.Y()) <= tolerance)
		{
			_centerPoint.SetXY(c);
			break;
		}
	}

	// 근의 공식을 통해 두 직선과 원의 두 접점의 좌표를 구함
	double A, B, C, D; // Ax + By + C = 0에서의 계수. D는 판별식의 값.

	for (int i = 0; i < 2; ++i)
	{
		if (a[i] == infinity)
			_contactPoint[i].SetXY(-b[i], _centerPoint.Y());
		else
		{
			A = a[i]*a[i] + 1;
			B = 2*(a[i]*b[i] - _centerPoint[0] - a[i]*_centerPoint[1]);
			C = _centerPoint[0]*_centerPoint[0] + _centerPoint[1]*_centerPoint[1] - 2*_centerPoint[1]*b[i] + b[i]*b[i] - radius*radius;
			
			// 판별식
			if ((D = B*B-4*A*C) < tolerance)
				D = 0.0;

			_contactPoint[i].X((-B + sqrt(D))/(2*A));
			_contactPoint[i].Y(a[i]*_contactPoint[i].X() + b[i]);
		}
	}
}

bool SketchItemFillet::CheckMaximumRadius(double dist1, double dist2, double theta)
{
	// 최대 허용 반지름
	double _maxRadius = 0;

	if (dist1 > dist2)
		_maxRadius = dist2*tan(theta);
	else
		_maxRadius = dist1*tan(theta);

	if (abs(_maxRadius) - _radius <= tolerance)
	{
		cout << "Radius should be less than " << abs(_maxRadius) << "!" << endl;
		return false;
	}
	else
		return true;
}

void SketchItemFillet::Help(void)
{
	cout << " [filletlines p1 p2 p3]" << endl;
	cout << " -p1 : " << "First Line Name" << endl;
	cout << " -p2 : " << "Second Line Name" << endl;
	cout << " -p3 : " << "Fillet Radius" << endl;
	cout << " [EXAMPLE] " << "filletlines Line1 Line2 30" << endl;
	cout << " [NOTE 1] " << "This function is for filleting two connected straight lines" << endl;
	cout << " [NOTE 2] " << "This function should be called after 'opensketch' function" << endl;
	cout << " [NOTE 3] " << "New arc name will be automatically assigned" << endl;
}