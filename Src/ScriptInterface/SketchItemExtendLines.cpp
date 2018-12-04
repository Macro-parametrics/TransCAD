#include "stdafx.h"
#include "SketchItemExtendLines.h"
#include "SketchItemLine.h"
#include "SketchItemArc.h"

SketchItemExtendLines::SketchItemExtendLines(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemExtendLines::~SketchItemExtendLines(void)
{
}

void SketchItemExtendLines::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_lineNames.push_back(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_lineNames.push_back(token);

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetSketch()->GetSketchItemByName(_lineNames[0]) || !GetSketch()->GetSketchItemByName(_lineNames[1]), "Enter existing lines!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketch()->GetSketchItemByName(_lineNames[0])->GetType() != 0, "Only line type is allowed!");
	TSIThrowExceptionIf<TSIArgumentException>(GetSketch()->GetSketchItemByName(_lineNames[1])->GetType() != 0, "Only line type is allowed!");
	TSIThrowExceptionIf<TSIArgumentException>(_lineNames[0] == _lineNames[1], "Two lines should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetInterSectingPoint(), "Invalid input parameters!");

	Create();
}

void SketchItemExtendLines::Create(void)
{
	SketchItemLine * pFirstLine = dynamic_cast<SketchItemLine *>(GetSketch()->GetSketchItemByName(_lineNames[0]));
	SketchItemLine * pSecondLine = dynamic_cast<SketchItemLine *>(GetSketch()->GetSketchItemByName(_lineNames[1]));

	// 두 라인을 생성
	pFirstLine->Create();
	pSecondLine->Create();
	//

	if (GetSketch()->IsModified())
	{
		pFirstLine->SetModified(true);
		pSecondLine->SetModified(true);
	}
}

bool SketchItemExtendLines::GetInterSectingPoint(void)
{
	Point2D _linePoints[2][2];			// 두 라인의 시작점 및 끝점
	Point2D _intPoint, _nIntPoint[2];	// 교점(_intPoint) 및 나머지 한점 (_nIntPoint)
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

	// 각 직선에 대해 교점으로부터 더 멀리 떨어진 점 구하기
	for (int i = 0; i < 2; ++i)
		GetDistantPoint(_intPoint, _linePoints[i][0], _linePoints[i][1], _nIntPoint[i]);

	// 두 라인의 좌표 수정 및 스케치에서 제거
	for (int i = 0; i < 2; ++i)
	{
		pLines[i]->SetStartPoint(_nIntPoint[i]);
		pLines[i]->SetEndPoint(_intPoint);
		
		GetSketch()->GetEditorPtr()->DeleteByName(pLines[i]->GetName().c_str());
	}

	return true;
}

void SketchItemExtendLines::Help(void)
{
	cout << " [extendlines p1 p2]" << endl;
	cout << " -p1 : " << "First Line Name" << endl;
	cout << " -p2 : " << "Second Line Name" << endl;
	cout << " [EXAMPLE] " << "extendlines Line1 Line2" << endl;
	cout << " [NOTE 1] " << "This function is for connecting two disconnected straight lines by extending them" << endl;
	cout << " [NOTE 2] " << "This function should be called after 'opensketch' function" << endl;
}