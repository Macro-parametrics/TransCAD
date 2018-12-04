#include "stdafx.h"
#include "FeatureRevolve.h"
#include "FeatureSketch.h"
#include "Part.h"


FeatureRevolve::FeatureRevolve(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
	_isCut = VARIANT_FALSE;
}

FeatureRevolve::~FeatureRevolve(void)
{
}

void FeatureRevolve::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_sketchName = token;

	token = StringToken::GetString( NULL, seps_blank, command );
	_startAngle = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_startCond = (TransCAD::StdRevolveEndType)atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_endAngle = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_endCond = (TransCAD::StdRevolveEndType)atoi(token.c_str());
	
	if (GetType() == 9)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		_org.X(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_org.Y(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_org.Z(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_dir.X(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_dir.Y(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_dir.Z(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_isCut = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;

		TSIThrowExceptionIf<TSIArgumentException>(_org == _dir, "Origin and direction should be different!");
	}

	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	SetReferencePtr(GetPart()->GetPartPtr()->SelectObjectByName(_sketchName.c_str()));

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencePtr() == NULL, "Invalid sketch name!");
	TSIThrowExceptionIf<TSIArgumentException>(_startAngle < 0 || _endAngle < 0, "Both angles should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_startAngle == 0 && _endAngle == 0, "Both angles should not be 0 at the same time!");
	TSIThrowExceptionIf<TSIArgumentException>(!(_startCond == 0 || _startCond == 1) || !(_endCond == 0 || _endCond == 1), "Both conditions should be either 0 or 1!");
	
	AddReference(GetReferencePtr());
	Create();
}

void FeatureRevolve::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	if (GetType() == 7)
	{
		TransCAD::IStdSolidProtrusionRevolveFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(7);

		_sketchName = _spFeature->GetProfileSketch()->GetReferenceeName();
		_startAngle = _spFeature->GetStartAngle();
		_startCond = _spFeature->GetStartCondition();
		_endAngle = _spFeature->GetEndAngle();
		_endCond = _spFeature->GetEndCondition();
		_isFlip = _spFeature->GetIsFlip();
	}
	else if (GetType() == 8)
	{
		TransCAD::IStdSolidCutRevolveFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(8);

		_sketchName = _spFeature->GetProfileSketch()->GetReferenceeName();
		_startAngle = _spFeature->GetStartAngle();
		_startCond = _spFeature->GetStartCondition();
		_endAngle = _spFeature->GetEndAngle();
		_endCond = _spFeature->GetEndCondition();
		_isFlip = _spFeature->GetIsFlip();
	}
	else if (GetType() == 9)
	{
		TransCAD::IStdSolidRevolveWithExternalAxisFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(9);

		double org[3], dir[3];
		_spFeature->GetRevolveAxis(&org[0], &org[1], &org[2], &dir[0], &dir[1], &dir[2]);
		_org.SetXYZ(org); _dir.SetXYZ(dir);
		_sketchName = _spFeature->GetProfileSketch()->GetReferenceeName();
		_startAngle = _spFeature->GetStartAngle();
		_startCond = _spFeature->GetStartCondition();
		_endAngle = _spFeature->GetEndAngle();
		_endCond = _spFeature->GetEndCondition();
		_isFlip = _spFeature->GetIsFlip();
		_isCut = _spFeature->GetIsCut();
	}
	
	SetReferencePtr(GetPart()->GetPartPtr()->SelectObjectByName(_sketchName.c_str()));
	assert(GetReferencePtr());
	AddReference(GetReferencePtr());
}

void FeatureRevolve::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_startAngle = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_startCond = (TransCAD::StdRevolveEndType)atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_endAngle = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_endCond = (TransCAD::StdRevolveEndType)atoi(token.c_str());

	if (GetType() == 9)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		_org.X(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_org.Y(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_org.Z(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_dir.X(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_dir.Y(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_dir.Z(atof(token.c_str()));

		token = StringToken::GetString( NULL, seps_blank, command );
		_isCut = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;

		TSIThrowExceptionIf<TSIArgumentException>(_org == _dir, "Origin and direction should be different!");
	}

	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_startAngle < 0 || _endAngle < 0, "Both angles should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_startAngle == 0 && _endAngle == 0, "Both angles should not be 0 at the same time!");
	TSIThrowExceptionIf<TSIArgumentException>(!(_startCond == 0 || _startCond == 1) || !(_endCond == 0 || _endCond == 1), "Both conditions should be either 0 or 1!");
}

void FeatureRevolve::Create(void)
{
	FeatureSketch * pProfile = dynamic_cast<FeatureSketch *>(GetPart()->GetFeatureByName(_sketchName));
	TSIThrowExceptionIf<TSIArgumentException>(pProfile->GetCloseness() == 0 || pProfile->GetCloseness() == 2, "The profile sketch is not closed!");
	
	if (GetType() == 7)
		GetPart()->GetFeaturesPtr()->AddNewSolidProtrusionRevolveFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _startAngle, _startCond, _endAngle, _endCond, _isFlip);	
	else if (GetType() == 8)
		GetPart()->GetFeaturesPtr()->AddNewSolidCutRevolveFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _startAngle, _startCond, _endAngle, _endCond, _isFlip);
	else if (GetType() == 9)
		GetPart()->GetFeaturesPtr()->AddNewSolidRevolveWithExternalAxisFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _startAngle, _startCond, _endAngle, _endCond,
																		_org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], _isCut, _isFlip);
}

void FeatureRevolve::AskInfo(void)
{
	char buffer[500];
	int flip = 0;
	int cut = 0;

	if (_isFlip == VARIANT_TRUE)
		flip = 1;
	if (_isCut == VARIANT_TRUE)
		cut = 1;

	if (!IsModified() && !IsDeleted())
	{
		if (GetType() == 7)
			sprintf_s(buffer, sizeof(buffer),"createprorevolve %s %s %f 0 %f 0 %d", GetName().c_str(), _sketchName.c_str(), _startAngle, _endAngle, flip);
		else if (GetType() == 8)
			sprintf_s(buffer, sizeof(buffer),"createcutrevolve %s %s %f 0 %f 0 %d", GetName().c_str(), _sketchName.c_str(), _startAngle, _endAngle, flip);
		else if (GetType() == 9)
			sprintf_s(buffer, sizeof(buffer),"createrevolvewithaxis %s %s %f 0 %f 0 %f %f %f %f %f %f %d %d", GetName().c_str(), _sketchName.c_str(), 
															_startAngle, _endAngle, _org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], cut, flip);
	}
	else if (IsModified())
	{
		if (GetType() == 7)
			sprintf_s(buffer, sizeof(buffer),"modify %s %f 0 %f 0 %d", GetName().c_str(), _startAngle, _endAngle, flip);
		else if (GetType() == 8)
			sprintf_s(buffer, sizeof(buffer),"modify %s %f 0 %f 0 %d", GetName().c_str(), _startAngle, _endAngle, flip);
		else if (GetType() == 9)
			sprintf_s(buffer, sizeof(buffer),"modify %s %f 0 %f 0 %f %f %f %f %f %f %d %d", GetName().c_str(),
															_startAngle, _endAngle, _org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], cut, flip);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureRevolve::Help(void)
{
	if (GetType() == 7)
	{
		cout << " [createprorevolve p1 p2 p3 p4 p5 p6 p7]" << endl;
		cout << " -p1 : " << "Protrusion Revolve Name" << endl;
		cout << " -p2 : " << "Sketch Name" << endl;
		cout << " -p3 : " << "Start Angle" << endl;
		cout << " -p4 : " << "Start Condition (0:Blind)" << endl;
		cout << " -p5 : " << "End Angle" << endl;
		cout << " -p6 : " << "End Condition (0:Blind)" << endl;
		cout << " -p7 : " << "isFlip (0:False, 1:True)" << endl;
		cout << " [EXAMPLE] " << "createprorevolve Revolve1 Sketch1 360 0 0 0 0" << endl;
		cout << " [NOTE] " << "The target sketch must include a centerline" << endl;
	}
	else if (GetType() == 8)
	{
		cout << " [createcutrevolve p1 p2 p3 p4 p5 p6 p7]" << endl;
		cout << " -p1 : " << "Cut Revolve Name" << endl;
		cout << " -p2 : " << "Sketch Name" << endl;
		cout << " -p3 : " << "Start Angle" << endl;
		cout << " -p4 : " << "Start Condition (0:Blind)" << endl;
		cout << " -p5 : " << "End Angle" << endl;
		cout << " -p6 : " << "End Condition (0:Blind)" << endl;
		cout << " -p7 : " << "isFlip (0:False, 1:True)" << endl;
		cout << " [EXAMPLE] " << "createcutrevolve Revolve1 Sketch1 360 0 0 0 0" << endl;
		cout << " [NOTE] " << "The target sketch must include a centerline" << endl;
	}
	else if (GetType() == 9)
	{
		cout << " [createrevolvewithaxis p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14]" << endl;
		cout << " -p1 : " << "Revolve Name" << endl;
		cout << " -p2 : " << "Sketch Name" << endl;
		cout << " -p3 : " << "Start Angle" << endl;
		cout << " -p4 : " << "Start Condition (0:Blind)" << endl;
		cout << " -p5 : " << "End Angle" << endl;
		cout << " -p6 : " << "End Condition (0:Blind)" << endl;
		cout << " -p7 : " << "Axis Origin (X)" << endl;
		cout << " -p8 : " << "Axis Origin (Y)" << endl;
		cout << " -p9 : " << "Axis Origin (Z)" << endl;
		cout << " -p10 : " << "Axis Direction (X)" << endl;
		cout << " -p11 : " << "Axis Direction (Y)" << endl;
		cout << " -p12 : " << "Axis Direction (Z)" << endl;
		cout << " -p13 : " << "isCut (0:False, 1:True)" << endl;
		cout << " -p14 : " << "isFlip (0:False, 1:True)" << endl;
		cout << " [EXAMPLE] " << "createrevolvewithaxis Revolve1 Sketch1 360 0 0 0 0 0 0 0 0 1 0 0" << endl;
	}
}