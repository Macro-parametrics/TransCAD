#include "stdafx.h"
#include "SketchItemCenterLine.h"


SketchItemCenterLine::SketchItemCenterLine(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemCenterLine::~SketchItemCenterLine(void)
{
}

void SketchItemCenterLine::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_startPoint.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_startPoint.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_endPoint.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_endPoint.Y(atof(token.c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(_startPoint == _endPoint, "Start and end points should be different!");

	Create();
}

void SketchItemCenterLine::AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem)
{
	TransCAD::IStdSketchCenterlinePtr _spSketchItem = spSketchItem;
	
	string name = _spSketchItem->GetName();
	SetName(name);
	SetType(1);

	_startPoint.SetXY(_spSketchItem->GetStartPoint()->GetX(), _spSketchItem->GetStartPoint()->GetY());
	_endPoint.SetXY(_spSketchItem->GetEndPoint()->GetX(), _spSketchItem->GetEndPoint()->GetY());
}

void SketchItemCenterLine::Create(void)
{
	GetSketch()->GetEditorPtr()->Create2DCenterline2Points(GetName().c_str(), _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
}

void SketchItemCenterLine::Modify(char * command)
{
	Point2D startPoint, endPoint;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	startPoint.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	startPoint.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	endPoint.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	endPoint.Y(atof(token.c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(startPoint == endPoint, "Start and end points should be different!");

	_startPoint = startPoint;
	_endPoint = endPoint;
}

void SketchItemCenterLine::AskInfo(void)
{
	char buffer[250];
	
	if (GetSketch()->IsModified())
	{
		if (IsModified())
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f", GetName().c_str(), _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
		else
			sprintf_s(buffer, sizeof(buffer),"createcenterline %s %f %f %f %f", GetName().c_str(), _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
	}
	else
	{
		sprintf_s(buffer, sizeof(buffer),"createcenterline %s %f %f %f %f", GetName().c_str(), _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
	}
	
	cout << buffer << endl;
}

void SketchItemCenterLine::Help(void)
{
	cout << " [createcenterline p1 p2 p3 p4 p5]" << endl;
	cout << " -p1 : " << "Center Line Name" << endl;
	cout << " -p2 : " << "Start Point (X)" << endl;
	cout << " -p3 : " << "Start Point (Y)" << endl;
	cout << " -p4 : " << "End Point (X)" << endl;
	cout << " -p5 : " << "End Point (Y)" << endl;
	cout << " [EXAMPLE] " << "createcenterline CenterLine1 0 0 100 0" << endl;
	cout << " [NOTE] " << "This function should be called after 'opensketch' function" << endl;
}