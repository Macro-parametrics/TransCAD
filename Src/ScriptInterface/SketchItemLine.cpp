#include "stdafx.h"
#include "SketchItemLine.h"


SketchItemLine::SketchItemLine(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemLine::SketchItemLine(FeatureSketch* pSketch, int sketchItemType, string name, Point2D startPoint, Point2D endPoint)
	: SketchItem (pSketch, sketchItemType)
{
	SetName(name);
	SetStartPoint(startPoint);
	SetEndPoint(endPoint);
}

SketchItemLine::~SketchItemLine(void)
{
}

void SketchItemLine::GetInfo(char * command)
{
	Point2D startPoint, endPoint;

	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	startPoint.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	startPoint.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	endPoint.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	endPoint.Y(atof(token.c_str()));
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(startPoint == endPoint, "Start and end points should be different!");
	
	SetStartPoint(startPoint);
	SetEndPoint(endPoint);
	Create();
}

void SketchItemLine::AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem)
{
	TransCAD::IStdSketchLinePtr _spSketchItem = spSketchItem;
	
	string name = _spSketchItem->GetName();
	SetName(name);
	SetType(0);

	SetStartPoint(Point2D(_spSketchItem->GetStartPoint()->GetX(), _spSketchItem->GetStartPoint()->GetY()));
	SetEndPoint(Point2D(_spSketchItem->GetEndPoint()->GetX(), _spSketchItem->GetEndPoint()->GetY()));
}

void SketchItemLine::Create(void)
{
	GetSketch()->GetEditorPtr()->Create2DLine2Points(GetName().c_str(), GetStartPoint().X(), GetStartPoint().Y(), GetEndPoint().X(), GetEndPoint().Y());
}

void SketchItemLine::Modify(char * command)
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

	SetStartPoint(startPoint);
	SetEndPoint(endPoint);
}

void SketchItemLine::AskInfo(void)
{
	char buffer[250];
	
	if (GetSketch()->IsModified())
	{
		if (IsModified())
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f", GetName().c_str(), GetStartPoint().X(), GetStartPoint().Y(), GetEndPoint().X(), GetEndPoint().Y());
		else
			sprintf_s(buffer, sizeof(buffer),"createline %s %f %f %f %f", GetName().c_str(), GetStartPoint().X(), GetStartPoint().Y(), GetEndPoint().X(), GetEndPoint().Y());
	}
	else
	{
		sprintf_s(buffer, sizeof(buffer),"createline %s %f %f %f %f", GetName().c_str(), GetStartPoint().X(), GetStartPoint().Y(), GetEndPoint().X(), GetEndPoint().Y());
	}

	cout << buffer << endl;
}

void SketchItemLine::Help(void)
{
	cout << " [createline p1 p2 p3 p4 p5]" << endl;
	cout << " -p1 : " << "Line Name" << endl;
	cout << " -p2 : " << "Start Point (X)" << endl;
	cout << " -p3 : " << "Start Point (Y)" << endl;
	cout << " -p4 : " << "End Point (X)" << endl;
	cout << " -p5 : " << "End Point (Y)" << endl;
	cout << " [EXAMPLE] " << "createline Line1 0 0 100 0" << endl;
	cout << " [NOTE] " << "This function should be called after 'opensketch' function" << endl;
}