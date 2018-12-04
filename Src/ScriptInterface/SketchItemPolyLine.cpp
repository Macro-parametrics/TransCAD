#include "stdafx.h"
#include "SketchItemPolyLine.h"
#include "SketchItemLine.h"


SketchItemPolyLine::SketchItemPolyLine(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemPolyLine::~SketchItemPolyLine(void)
{
}

void SketchItemPolyLine::GetInfo(char * command)
{
	for (;;)
	{
		token = StringToken::GetString( NULL, seps_blank, command );	//첫번째 단어
		
		if (token != "FAIL")
			_pointArray.push_back(atof(token.c_str()));
		else
			break;
	}

	_pointNumber = _pointArray.size()/2; // 포인트 개수

	// 포인트의 개수가 2의 배수가 아니거나, 2개보다 적은 경우
	TSIThrowExceptionIf<TSIArgumentException>(_pointArray.size()%2 != 0 || _pointNumber < 2, "Insufficient input parameters!");

	Create(); // PolyLine 생성
}

void SketchItemPolyLine::Create(void)
{
	SetAllPoints();
	
	int _index = 1;	// 라인 넘버

	for (int i = 0; i < (int)_points.size() - 1; ++i)
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
		eP = _points[i+1];
		
		SketchItemLine * pLine = new SketchItemLine(GetSketch(), (int)0, _lineName, sP, eP);
		GetSketch()->SetSketchItem(pLine);
		pLine->Create();
		pLine->SetCreated(true);

		_index ++;
	}
}

void SketchItemPolyLine::SetAllPoints(void)
{
	for (int i = 0; i < (int)_pointArray.size(); i = i+2)
	{
		Point2D _point;

		_point.SetXY(_pointArray[i], _pointArray[i+1]);
		_points.push_back(_point);
	}

	// 시작점과 끝점이 같은 경우엔 빠져나옴
	for (int i = 0; i < (int)_points.size() - 1; ++i)
		TSIThrowExceptionIf<TSIArgumentException>(_points[i] == _points[i+1], "Two adjacent points should be different!");
}

void SketchItemPolyLine::Help(void)
{
	cout << " [createpolyline p1 p2 p3 p4 p5 ... pn]" << endl;
	cout << " -p1 : " << "First Point (X)" << endl;
	cout << " -p2 : " << "First Point (Y)" << endl;
	cout << " -p3 : " << "Second Point (X)" << endl;
	cout << " -p4 : " << "Second Point (Y)" << endl;
	cout << " -p5 ... pn : " << "From third to last points" << endl;
	cout << " [EXAMPLE] " << "createpolyline 0 0 100 0 100 100 0 100 0 0" << endl;
	cout << " [NOTE 1] " << "This function should be called after 'opensketch' function" << endl;
	cout << " [NOTE 2] " << "Line names will be automatically assigned" << endl;
}