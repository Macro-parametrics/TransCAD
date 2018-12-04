#include "stdafx.h"
#include "SketchItemPolygon.h"
#include "SketchItemLine.h"


SketchItemPolygon::SketchItemPolygon(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemPolygon::~SketchItemPolygon(void)
{
}

void SketchItemPolygon::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_edgeNumber = atoi(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_length = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_edgeNumber <= 2, "The number of edges should be greater than two!");
	TSIThrowExceptionIf<TSIArgumentException>(_length <= 0, "Length should be greater than zero!");
	
	Create();
}

void SketchItemPolygon::Create(void)
{
	SetAllPoints();

	int _index = 1;	// 라인 넘버

	for (int i = 0; i < _edgeNumber; ++i)
	{
		char _lineName[256];
		sprintf_s(_lineName, "Line%d", _index);// 라인 이름

		// 같은 이름의 Sketch item 이 존재하지 않을 때 까지 index 증가
		while (GetSketch()->GetSketchItemByName(_lineName) != NULL)
		{
			_index ++;
			sprintf_s(_lineName, "Line%d", _index);// 라인 이름
		}
		
		Point2D sP, eP;
		sP = _points[i];
		
		if (i == _edgeNumber - 1)
			eP = _points[0];
		else
			eP = _points[i+1];

		SketchItemLine * pLine = new SketchItemLine(GetSketch(), (int)0, _lineName, sP, eP);
		GetSketch()->SetSketchItem(pLine);
		pLine->Create();
		pLine->SetCreated(true);

		_index ++;
	}
}

void SketchItemPolygon::SetAllPoints(void)
{
	// 정n각형의 한 내각
	double angle = PI*(_edgeNumber-2)/_edgeNumber;
	
	// 회전 행렬 (반시계)
	Matrix2D rotMat;
	rotMat.SetRows(Vector2D(cos(angle), -sin(angle)), Vector2D(sin(angle), cos(angle)));
	
	// 시작 점
	_points.push_back(Point2D(0,0));

	// 시작 벡터
	Vector2D vec(1, 0);

	// 점의 좌표를 순서대로 구한다
	for (int i = 0; i < _edgeNumber - 1; ++i)
	{
		vec = MrMath::Multiply(rotMat, vec); // 벡터를 내각만큼 회전

		 // 점 좌표 구해서 저장하기
		Point2D temp(_points[i] + vec*_length);
		_points.push_back(temp);

		vec = vec*(-1);	// 벡터 방향 180도 전환
	}

	// 다각형의 면적, 중점
	double area = 0, centerX = 0, centerY = 0;
	
	for (int i = 0; i < _edgeNumber - 1; ++i)
	{
		area = area + (_points[i].X()*_points[i+1].Y() - _points[i+1].X()*_points[i].Y());
		centerX = centerX + (_points[i].X() + _points[i+1].X())*(_points[i].X()*_points[i+1].Y() - _points[i+1].X()*_points[i].Y());
		centerY = centerY + (_points[i].Y() + _points[i+1].Y())*(_points[i].X()*_points[i+1].Y() - _points[i+1].X()*_points[i].Y());
	}
	
	area = abs(0.5*area);
	centerX = abs(centerX/(6*area));
	centerY = abs(centerY/(6*area));

	// 다각형의 중점을 원점으로 위치시키기
	for (int i = 0; i < _edgeNumber; ++i)
	{
		// 중점을 원점으로 이동
		Point2D temp(_points[i].X() - centerX, _points[i].Y() - centerY);
		
		// 소수점 아래 9번 째 자리에서 반올림
		temp.X(MrMath::Round(temp.X()));
		temp.Y(MrMath::Round(temp.Y()));
		
		// 저장
		_points[i].SetXY(temp);
	}
}

void SketchItemPolygon::Help(void)
{
	cout << " [createpolygon p1 p2]" << endl;
	cout << " -p1 : " << "The number of edges" << endl;
	cout << " -p2 : " << "Length of an edge" << endl;
	cout << " [EXAMPLE] " << "createpolygon 5 20" << endl;
	cout << " [NOTE 1] " << "This function is for creating a regular polygon" << endl;
	cout << " [NOTE 2] " << "This function should be called after 'opensketch' function" << endl;
}