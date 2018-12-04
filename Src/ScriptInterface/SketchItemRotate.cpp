#include "stdafx.h"
#include "SketchItemRotate.h"
#include "SketchItemLine.h"
#include "SketchItemCenterLine.h"
#include "SketchItemArc.h"
#include "SketchItemCircle.h"


SketchItemRotate::SketchItemRotate(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemRotate::~SketchItemRotate(void)
{
}

void SketchItemRotate::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_rotCenter.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_rotCenter.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_rotAngle = atof(token.c_str());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
		
	Create();
}

void SketchItemRotate::Create(void)
{
	RotateAllPoints();
	
	for (int i = 0; i < GetSketch()->GetSketchItemListSize(); ++i)
	{
		// 스케치 요소 삭제
		GetSketch()->GetEditorPtr()->DeleteByName(GetSketch()->GetSketchItem(i)->GetName().c_str());
		// 스케치 요소 재 생성
		GetSketch()->GetSketchItem(i)->Create();
		GetSketch()->GetSketchItem(i)->SetModified(true);
	}
}

void SketchItemRotate::RotateAllPoints(void)
{
	// 회전 각도 및 Sin, Cos 값
	_rotAngle = _rotAngle * PI / 180;
	double s = sin(_rotAngle), c = cos(_rotAngle);
	
	// 회전 행렬
	_rotMatrix.SetRows(Vector2D(c, -s), Vector2D(s, c));

	// 회전 중심과 각 점을 잇는 벡터
	Vector2D vec;
	
	// 현재의 모든 스케치 요소를 입력된 값 만큼 회전
	for (int i = 0; i < GetSketch()->GetSketchItemListSize(); ++i)
	{
		// Line인 경우
		if (GetSketch()->GetSketchItem(i)->GetType() == 0)
		{
			SketchItemLine * pLine = (SketchItemLine *)GetSketch()->GetSketchItem(i);
			Point2D sP = pLine->GetStartPoint();
			Point2D eP = pLine->GetEndPoint();
			
			vec = sP - _rotCenter;
			sP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전
			
			vec = eP - _rotCenter;
			eP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전

			pLine->SetStartPoint(sP);
			pLine->SetEndPoint(eP);
		}
		// CenterLine인 경우
		else if (GetSketch()->GetSketchItem(i)->GetType() == 1)
		{
			SketchItemCenterLine * pCenterLine = (SketchItemCenterLine *)GetSketch()->GetSketchItem(i);
			
			Point2D sP = pCenterLine->GetStartPoint();
			Point2D eP = pCenterLine->GetEndPoint();
			
			vec = sP - _rotCenter;
			sP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전
			
			vec = eP - _rotCenter;
			eP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전

			pCenterLine->SetStartPoint(sP);
			pCenterLine->SetEndPoint(eP);
		}
		// Circle인 경우
		else if (GetSketch()->GetSketchItem(i)->GetType() == 2)
		{
			SketchItemCircle * pCircle = (SketchItemCircle *)GetSketch()->GetSketchItem(i);
			
			Point2D cP = pCircle->GetCenterPoint();
			
			vec = cP - _rotCenter;
			cP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전

			pCircle->SetCenterPoint(cP);
		}
		// Arc인 경우
		else if (GetSketch()->GetSketchItem(i)->GetType() == 3)
		{
			SketchItemArc * pArc = (SketchItemArc *)GetSketch()->GetSketchItem(i);
			
			Point2D cP = pArc->GetCenterPoint();
			Point2D sP = pArc->GetStartPoint();
			Point2D eP = pArc->GetEndPoint();
			
			vec = cP - _rotCenter;
			cP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전

			vec = sP - _rotCenter;
			sP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전
			
			vec = eP - _rotCenter;
			eP = _rotCenter + MrMath::Multiply(_rotMatrix, vec); // 벡터를 회전

			pArc->SetCenterPoint(cP);
			pArc->SetStartPoint(sP);
			pArc->SetEndPoint(eP);
		}
	}
}

void SketchItemRotate::Help(void)
{
	cout << " [rotatesketch p1 p2 p3]" << endl;
	cout << " -p1 : " << "Center of Rotation (X)" << endl;
	cout << " -p2 : " << "Center of Rotation (Y)" << endl;
	cout << " -p3 : " << "Rotational Angle" << endl;
	cout << " [EXAMPLE] " << "rotatesketch 10 10 90" << endl;
	cout << " [NOTE 1] " << "This function is for rotating a sketch" << endl;
	cout << " [NOTE 2] " << "This function should be called after 'opensketch' function" << endl;
}