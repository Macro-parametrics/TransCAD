#include "stdafx.h"
#include "SketchItemTranslate.h"
#include "SketchItemLine.h"
#include "SketchItemCenterLine.h"
#include "SketchItemArc.h"
#include "SketchItemCircle.h"


SketchItemTranslate::SketchItemTranslate(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemTranslate::~SketchItemTranslate(void)
{
}

void SketchItemTranslate::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_translation.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_translation.Y(atof(token.c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
			
	Create();
}

void SketchItemTranslate::Create(void)
{
	TranslateAllPoints();
	
	for (int i = 0; i < GetSketch()->GetSketchItemListSize(); ++i)
	{
		// 스케치 요소 삭제
		GetSketch()->GetEditorPtr()->DeleteByName(GetSketch()->GetSketchItem(i)->GetName().c_str());
		// 스케치 요소 재 생성
		GetSketch()->GetSketchItem(i)->Create();
		GetSketch()->GetSketchItem(i)->SetModified(true);
	}
}

void SketchItemTranslate::TranslateAllPoints(void)
{
	// 현재의 모든 스케치 요소를 입력된 값 만큼 이동
	for (int i = 0; i < GetSketch()->GetSketchItemListSize(); ++i)
	{
		// Line인 경우
		if (GetSketch()->GetSketchItem(i)->GetType() == 0)
		{
			SketchItemLine * pLine = (SketchItemLine *)GetSketch()->GetSketchItem(i);
			Point2D sP = pLine->GetStartPoint();
			Point2D eP = pLine->GetEndPoint();
			
			pLine->SetStartPoint(sP + _translation);
			pLine->SetEndPoint(eP + _translation);
		}
		// CenterLine인 경우
		else if (GetSketch()->GetSketchItem(i)->GetType() == 1)
		{
			SketchItemCenterLine * pCenterLine = (SketchItemCenterLine *)GetSketch()->GetSketchItem(i);
			
			Point2D sP = pCenterLine->GetStartPoint();
			Point2D eP = pCenterLine->GetEndPoint();
			
			pCenterLine->SetStartPoint(sP + _translation);
			pCenterLine->SetEndPoint(eP + _translation);
		}
		// Circle인 경우
		else if (GetSketch()->GetSketchItem(i)->GetType() == 2)
		{
			SketchItemCircle * pCircle = (SketchItemCircle *)GetSketch()->GetSketchItem(i);
			
			Point2D cP = pCircle->GetCenterPoint();
			
			pCircle->SetCenterPoint(cP + _translation);
		}
		// Arc인 경우
		else if (GetSketch()->GetSketchItem(i)->GetType() == 3)
		{
			SketchItemArc * pArc = (SketchItemArc *)GetSketch()->GetSketchItem(i);
			
			Point2D cP = pArc->GetCenterPoint();
			Point2D sP = pArc->GetStartPoint();
			Point2D eP = pArc->GetEndPoint();
			
			pArc->SetCenterPoint(cP + _translation);
			pArc->SetStartPoint(sP + _translation);
			pArc->SetEndPoint(eP + _translation);
		}
	}
}

void SketchItemTranslate::Help(void)
{
	cout << " [translatesketch p1 p2]" << endl;
	cout << " -p1 : " << "Translation (X)" << endl;
	cout << " -p2 : " << "Translation (Y)" << endl;
	cout << " [EXAMPLE] " << "translatesketch 50 -50" << endl;
	cout << " [NOTE 1] " << "This function is for translating a sketch" << endl;
	cout << " [NOTE 2] " << "This function should be called after 'opensketch' function" << endl;
}