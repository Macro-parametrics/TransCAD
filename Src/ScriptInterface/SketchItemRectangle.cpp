#include "stdafx.h"
#include "SketchItemRectangle.h"
#include "SketchItemLine.h"


SketchItemRectangle::SketchItemRectangle(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemRectangle::~SketchItemRectangle(void)
{
}

void SketchItemRectangle::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_points[0].X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_points[0].Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_points[2].X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_points[2].Y(atof(token.c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_points[0].X() == _points[2].X() && _points[0].Y() == _points[2].Y(), "Two points should be different!"); // 시작점과 끝점이 같은 경우

	Create();
}

void SketchItemRectangle::Create(void)
{
	SetAllPoints();

	int _index = 1; // 라인 넘버

	for (int i = 0; i < 4; ++i)
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

		if (i == 3) // 마지막 라인은 시작점과 연결
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

void SketchItemRectangle::SetAllPoints(void)
{
	// 입력받은 두 점으로부터 다른 두 점 생성
	if (abs(_points[0].X() - _points[2].X()) == 0) // x 좌표가 같은 경우, 두 점을 대각선으로 하는 정사각형
	{
		_points[1].X(_points[0].X() + (_points[0].Y() + _points[2].Y())/2);
		_points[1].Y((_points[0].Y() + _points[2].Y())/2);

		_points[3].X(_points[0].X() - (_points[0].Y() + _points[2].Y())/2);
		_points[3].Y((_points[0].Y() + _points[2].Y())/2);
	}
	else if (abs(_points[0].Y() - _points[2].Y()) == 0) // y 좌표가 같은 경우, 두 점을 대각선으로 하는 정사각형
	{
		_points[1].X((_points[0].X() + _points[2].X())/2);
		_points[1].Y(_points[0].Y() + (_points[0].X() + _points[2].X())/2);

		_points[3].X((_points[0].X() + _points[2].X())/2);
		_points[3].Y(_points[0].Y() - (_points[0].X() + _points[2].X())/2);
	}
	else // 일반적인 경우
	{
		_points[1].X(_points[0].X());
		_points[1].Y(_points[2].Y());

		_points[3].X(_points[2].X());
		_points[3].Y(_points[0].Y());
	}
}

void SketchItemRectangle::Help(void)
{
	cout << " [createrectangle p1 p2 p3 p4]" << endl;
	cout << " -p1 : " << "First Point (X)" << endl;
	cout << " -p2 : " << "First Point (Y)" << endl;
	cout << " -p3 : " << "Second Point (X)" << endl;
	cout << " -p4 : " << "Second Point (Y)" << endl;
	cout << " [EXAMPLE] " << "createrectangle 0 0 100 100" << endl;
	cout << " [NOTE 1] " << "This function should be called after 'opensketch' function" << endl;
	cout << " [NOTE 2] " << "Line names will be automatically assigned clockwise" << endl;
}