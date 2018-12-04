#include "stdafx.h"
#include "SketchItemArc.h"


SketchItemArc::SketchItemArc(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemArc::SketchItemArc(FeatureSketch* pSketch, int sketchItemType, string name, Point2D center, Point2D startPoint, Point2D endPoint)
	: SketchItem (pSketch, sketchItemType)
{
	SetName(name);
	_center = center;
	_startPoint = startPoint;
	_endPoint = endPoint;
}

SketchItemArc::~SketchItemArc(void)
{
}

void SketchItemArc::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );	//첫번째 단어
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_center.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.Y(atof(token.c_str()));

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
	TSIThrowExceptionIf<TSIArgumentException>(_startPoint == _center, "Start and center points should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_center == _endPoint, "Center and end points should be different!");

	Create();
}

void SketchItemArc::AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem)
{
	TransCAD::IStdSketchCircularArcPtr _spSketchItem = spSketchItem;

	string name = _spSketchItem->GetName();
	SetName(name);
	SetType(3);

	_center.SetXY(_spSketchItem->GetCenterPoint()->GetX(), _spSketchItem->GetCenterPoint()->GetY());
	_startPoint.SetXY(_spSketchItem->GetStartPoint()->GetX(), _spSketchItem->GetStartPoint()->GetY());
	_endPoint.SetXY(_spSketchItem->GetEndPoint()->GetX(), _spSketchItem->GetEndPoint()->GetY());
}

void SketchItemArc::Create(void)
{
	GetSketch()->GetEditorPtr()->Create2DArcCenterStartEnd(GetName().c_str(), _center[0], _center[1], _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
}

void SketchItemArc::Modify(char * command)
{
	Point2D center, startPoint, endPoint;

	token = StringToken::GetString( NULL, seps_blank, command );
	center.X(atof(token.c_str()));
	token = StringToken::GetString( NULL, seps_blank, command );
	center.Y(atof(token.c_str()));

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
	TSIThrowExceptionIf<TSIArgumentException>(startPoint == center, "Start and center points should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(center == endPoint, "Center and end points should be different!");

	_center = center;
	_startPoint = startPoint;
	_endPoint = endPoint;
}

void SketchItemArc::AskInfo(void)
{
	char buffer[250];

	if (GetSketch()->IsModified())
	{
		if (IsModified())
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
		else
			sprintf_s(buffer, sizeof(buffer),"createarc %s %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
	}
	else
	{
		sprintf_s(buffer, sizeof(buffer),"createarc %s %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _startPoint[0], _startPoint[1], _endPoint[0], _endPoint[1]);
	}

	cout << buffer << endl;
}

void SketchItemArc::Help(void)
{
	cout << " [createarc p1 p2 p3 p4 p5 p6 p7]" << endl;
	cout << " -p1 : " << "Arc Name" << endl;
	cout << " -p2 : " << "Center Point (X)" << endl;
	cout << " -p3 : " << "Center Point (Y)" << endl;
	cout << " -p4 : " << "Start Point (X)" << endl;
	cout << " -p5 : " << "Start Point (Y)" << endl;
	cout << " -p6 : " << "End Point (X)" << endl;
	cout << " -p7 : " << "End Point (Y)" << endl;
	cout << " [EXAMPLE] " << "createarc Arc1 0 0 30 0 0 30" << endl;
	cout << " [NOTE] " << "This function should be called after 'opensketch' function" << endl;
}