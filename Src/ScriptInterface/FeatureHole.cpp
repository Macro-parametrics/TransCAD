#include "stdafx.h"
#include "FeatureHole.h"
#include "Part.h"


FeatureHole::FeatureHole(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureHole::~FeatureHole(void)
{
}

void FeatureHole::GetInfo(char * command)
{
	token = strtok_s( NULL, seps_blank, &command );
	SetName(token);

	SetReferencePtr(GetPart()->GetCurrentReferencePtr());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.Y(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_radius1 = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_depth1 = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(_depth1 <= 0, "Depth should be greater than zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_radius1 <= 0, "Radius should be greater than zero!");

	if (GetType() != 15)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		_radius2 = atof(token.c_str());
		
		if (GetType() == 13)
		{
			token = StringToken::GetString( NULL, seps_blank, command );
			_depth2 = atof(token.c_str());

			TSIThrowExceptionIf<TSIArgumentException>(_depth2 <= 0, "Depth should be greater than zero!");
			TSIThrowExceptionIf<TSIArgumentException>(_radius2 <= 0, "Radius should be greater than zero!");
		}
		else if (GetType() == 14)
		{
			token = StringToken::GetString( NULL, seps_blank, command );
			_angle1 = atof(token.c_str());

			TSIThrowExceptionIf<TSIArgumentException>(_angle1 <= 0 || _angle1 >= 180, "Angle should be between 0 and 180!");
			TSIThrowExceptionIf<TSIArgumentException>(_radius2 <= 0, "Radius should be greater than zero!");
		}

		token = StringToken::GetString( NULL, seps_blank, command );
		_bottomAngle = atof(token.c_str());

		TSIThrowExceptionIf<TSIArgumentException>(_bottomAngle <= 0, "Bottom angle should be greater than zero");
	}

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencePtr() == NULL, "Select a reference first!");
		
	GetPart()->SetCurrentReferencePtr(NULL);
	AddReference(GetReferencePtr());
	Create();
}

void FeatureHole::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	if (GetType() == 13)
	{
		TransCAD::IStdSolidHoleCounterboredFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(13);

		double center[3];
		_spFeature->GetCenterPoint(&center[0], &center[1], &center[2]);
		_center.SetXYZ(center);

		_radius1 = _spFeature->GetStartRadius();
		_depth1 = _spFeature->GetStartDepth();
	
		_radius2 = _spFeature->GetEndRadius();
		_depth2 = _spFeature->GetEndDepth();

		_bottomAngle = _spFeature->GetAngle();
		SetReferencePtr(_spFeature->GetTargetFace());
	}
	else if (GetType() == 14)
	{
		TransCAD::IStdSolidHoleCountersunkFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(14);

		double center[3];
		_spFeature->GetCenterPoint(&center[0], &center[1], &center[2]);
		_center.SetXYZ(center);
	
		_radius1 = _spFeature->GetRadius();
		_depth1 = _spFeature->GetDepth();

		_radius2 = _spFeature->GetSinkRadius();
		_angle1 = _spFeature->GetSinkAngle();

		_bottomAngle = _spFeature->GetBottomAngle();
		SetReferencePtr(_spFeature->GetTargetFace());
	}
	else if (GetType() == 15)
	{
		TransCAD::IStdSolidHoleSimpleFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(15);

		double center[3];
		_spFeature->GetCenterPoint(&center[0], &center[1], &center[2]);
		_center.SetXYZ(center);
	
		_radius1 = _spFeature->GetRadius();
		_depth1 = _spFeature->GetDepth();
		SetReferencePtr(_spFeature->GetTargetFace());
	}

	assert(GetReferencePtr());
	AddReference(GetReferencePtr());
}

void FeatureHole::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.Y(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_center.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_radius1 = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_depth1 = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(_depth1 <= 0, "Depth should be greater than zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_radius1 <= 0, "Radius should be greater than zero!");

	if (GetType() != 15)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		_radius2 = atof(token.c_str());
		
		if (GetType() == 13)
		{
			token = StringToken::GetString( NULL, seps_blank, command );
			_depth2 = atof(token.c_str());

			TSIThrowExceptionIf<TSIArgumentException>(_depth2 <= 0, "Depth should be greater than zero!");
			TSIThrowExceptionIf<TSIArgumentException>(_radius2 <= 0, "Radius should be greater than zero!");
		}
		else if (GetType() == 14)
		{
			token = StringToken::GetString( NULL, seps_blank, command );
			_angle1 = atof(token.c_str());

			TSIThrowExceptionIf<TSIArgumentException>(_angle1 <= 0 || _angle1 >= 180, "Angle should be between 0 and 180!");
			TSIThrowExceptionIf<TSIArgumentException>(_radius2 <= 0, "Radius should be greater than zero!");
		}

		token = StringToken::GetString( NULL, seps_blank, command );
		_bottomAngle = atof(token.c_str());
		
		TSIThrowExceptionIf<TSIArgumentException>(_bottomAngle <= 0, "Bottom angle should be greater than zero");
	}

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
}

void FeatureHole::Create(void)
{
	if (GetType() == 13)
		GetPart()->GetFeaturesPtr()->AddNewSolidHoleCounterboredFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _center[0], _center[1], _center[2], 
																	_radius1, _depth1, _radius2, _depth2, _bottomAngle);
	else if (GetType() == 14)
		GetPart()->GetFeaturesPtr()->AddNewSolidHoleCountersunkFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _center[0], _center[1], _center[2], 
																	_radius1, _depth1, _radius2, _angle1, _bottomAngle);
	else if (GetType() == 15)
		GetPart()->GetFeaturesPtr()->AddNewSolidHoleSimpleFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _center[0], _center[1], _center[2], _radius1, _depth1);
}

void FeatureHole::AskInfo(void)
{
	char buffer[500];

	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();

		if (GetType() == 13)
			sprintf_s(buffer, sizeof(buffer),"createholecounterbored %s %f %f %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _center[2],
																		_radius1, _depth1, _radius2, _depth2, _bottomAngle);
		else if (GetType() == 14)
			sprintf_s(buffer, sizeof(buffer),"createholecountersunk %s %f %f %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _center[2],
																		_radius1, _depth1, _radius2, _angle1, _bottomAngle);
		else if (GetType() == 15)
			sprintf_s(buffer, sizeof(buffer),"createholesimple %s %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _center[2], _radius1, _depth1);
	}
	else if (IsModified())
	{
		if (GetType() == 13)
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _center[2],
																		_radius1, _depth1, _radius2, _depth2, _bottomAngle);
		else if (GetType() == 14)
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _center[2],
																		_radius1, _depth1, _radius2, _angle1, _bottomAngle);
		else if (GetType() == 15)
			sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f", GetName().c_str(), _center[0], _center[1], _center[2], _radius1, _depth1);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureHole::Help(void)
{
	if (GetType() == 13)
	{
		cout << " [createholecounterbored p1 p2 p3 p4 p5 p6 p7 p8 p9]" << endl;
		cout << " -p1 : " << "HoleCounterbored Name" << endl;
		cout << " -p2 : " << "Center Point (X)" << endl;
		cout << " -p3 : " << "Center Point (Y)" << endl;
		cout << " -p4 : " << "Center Point (Z)" << endl;
		cout << " -p5 : " << "Start Radius" << endl;
		cout << " -p6 : " << "Start Depth" << endl;
		cout << " -p7 : " << "End Radius" << endl;
		cout << " -p8 : " << "End Depth" << endl;
		cout << " -p9 : " << "Bottom Angle" << endl;
		cout << " [EXAMPLE] " << "createholecounterbored Hole1 0 0 0 7 5 3 20 120" << endl;
		cout << " [NOTE] " << "Need to select a face before" << endl;
	}
	else if (GetType() == 14)
	{
		cout << " [createholecountersunk p1 p2 p3 p4 p5 p6 p7 p8 p9]" << endl;
		cout << " -p1 : " << "HoleCountersunk Name" << endl;
		cout << " -p2 : " << "Center Point (X)" << endl;
		cout << " -p3 : " << "Center Point (Y)" << endl;
		cout << " -p4 : " << "Center Point (Z)" << endl;
		cout << " -p5 : " << "Radius" << endl;
		cout << " -p6 : " << "Depth" << endl;
		cout << " -p7 : " << "Sink Radius" << endl;
		cout << " -p8 : " << "Sink Angle" << endl;
		cout << " -p9 : " << "Bottom Angle" << endl;
		cout << " [EXAMPLE] " << "createholecountersunk Hole1 0 0 0 3 40 6 90 180" << endl;
		cout << " [NOTE] " << "Need to select a face before" << endl;
	}
	else if (GetType() == 15)
	{
		cout << " [createholesimple p1 p2 p3 p4 p5 p6]" << endl;
		cout << " -p1 : " << "HoleSimple Name" << endl;
		cout << " -p2 : " << "Center Point (X)" << endl;
		cout << " -p3 : " << "Center Point (Y)" << endl;
		cout << " -p4 : " << "Center Point (Z)" << endl;
		cout << " -p5 : " << "Radius" << endl;
		cout << " -p6 : " << "Depth" << endl;
		cout << " [EXAMPLE] " << "createholesimple Hole1 0 0 0 5 40" << endl;
		cout << " [NOTE] " << "Need to select a face before" << endl;
	}
}