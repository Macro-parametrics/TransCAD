#include "stdafx.h"
#include "SketchItemCircle.h"


SketchItemCircle::SketchItemCircle(FeatureSketch * pSketch, int sketchItemType)
	: SketchItem (pSketch, sketchItemType)
{
}

SketchItemCircle::~SketchItemCircle(void)
{
}

void SketchItemCircle::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );	//첫번째 단어
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_center.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_center.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_radius = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(_radius == 0, "Radius should be greater than zero!");

	Create();
}

void SketchItemCircle::AddInfo(TransCAD::IStdSketchGeometryPtr spSketchItem)
{
	TransCAD::IStdSketchCirclePtr _spSketchItem = spSketchItem;

	string name = _spSketchItem->GetName();
	SetName(name);
	SetType(2);

	_center.SetXY(_spSketchItem->GetCenterPoint()->GetX(), _spSketchItem->GetCenterPoint()->GetY());
	
	_radius = _spSketchItem->GetRadius();
}

void SketchItemCircle::Create(void)
{
	GetSketch()->GetEditorPtr()->Create2DCircleCenterPoint(GetName().c_str(), _center[0], _center[1], _radius);
}

void SketchItemCircle::Modify(char * command)
{
	Point2D center;
	double radius;

	token = StringToken::GetString( NULL, seps_blank, command );
	center.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	center.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	radius = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(radius == 0, "Radius should be greater than zero!");

	_center = center;
	_radius = radius;
}

void SketchItemCircle::AskInfo(void)
{
	char buffer[250];

	if (GetSketch()->IsModified())
	{
		if (IsModified())
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f", GetName().c_str(), _center[0], _center[1], _radius);
		else
			sprintf_s(buffer, sizeof(buffer),"createcircle %s %f %f %f", GetName().c_str(), _center[0], _center[1], _radius);
	}
	else
	{
		sprintf_s(buffer, sizeof(buffer),"createcircle %s %f %f %f", GetName().c_str(), _center[0], _center[1], _radius);
	}

	cout << buffer << endl;
}

void SketchItemCircle::Help(void)
{
	cout << " [createcircle p1 p2 p3 p4]" << endl;
	cout << " -p1 : " << "Circle Name" << endl;
	cout << " -p2 : " << "Center Point (X)" << endl;
	cout << " -p3 : " << "Center Point (Y)" << endl;
	cout << " -p4 : " << "Radius" << endl;
	cout << " [EXAMPLE] " << "createcircle Circle1 0 0 30" << endl;
	cout << " [NOTE] " << "This function should be called after 'opensketch' function" << endl;
}