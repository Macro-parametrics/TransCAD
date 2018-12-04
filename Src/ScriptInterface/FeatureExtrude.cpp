#include "stdafx.h"
#include "FeatureExtrude.h"
#include "FeatureSketch.h"
#include "Part.h"


FeatureExtrude::FeatureExtrude(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureExtrude::~FeatureExtrude(void)
{
}

void FeatureExtrude::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_sketchName = token;
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_startDepth = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_startCond = (TransCAD::StdExtrudeEndType)atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_endDepth = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_endCond = (TransCAD::StdExtrudeEndType)atoi(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	SetReferencePtr(GetPart()->GetPartPtr()->SelectObjectByName(_sketchName.c_str()));

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencePtr() == NULL, "Invalid sketch name!");
	TSIThrowExceptionIf<TSIArgumentException>(_startDepth < 0 || _endDepth < 0, "Both depths should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(!(_startCond == 0 || _startCond == 1) || !(_endCond == 0 || _endCond == 1), "Both conditions should be either 0 or 1!");
	TSIThrowExceptionIf<TSIArgumentException>(_startDepth == 0 && _endDepth == 0 && _startCond == 0 && _endCond == 0, "Both depths and both conditions should not be 0 at the same time!");

	AddReference(GetReferencePtr());
	Create();
}

void FeatureExtrude::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	if (GetType() == 1)
	{
		TransCAD::IStdSolidProtrusionExtrudeFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(1);

		_sketchName = _spFeature->GetProfileSketch()->GetReferenceeName();
		_startDepth = _spFeature->GetStartDepth();
		_startCond = _spFeature->GetStartCondition();
		_endDepth = _spFeature->GetEndDepth();
		_endCond = _spFeature->GetEndCondition();
		_isFlip = _spFeature->GetIsFlip();
	}
	else
	{
		TransCAD::IStdSolidCutExtrudeFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(2);

		_sketchName = _spFeature->GetProfileSketch()->GetReferenceeName();
		_startDepth = _spFeature->GetStartDepth();
		_startCond = _spFeature->GetStartCondition();
		_endDepth = _spFeature->GetEndDepth();
		_endCond = _spFeature->GetEndCondition();
		_isFlip = _spFeature->GetIsFlip();
	}

	SetReferencePtr(GetPart()->GetPartPtr()->SelectObjectByName(_sketchName.c_str()));
	assert(GetReferencePtr());
	AddReference(GetReferencePtr());
}

void FeatureExtrude::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_startDepth = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_startCond = (TransCAD::StdExtrudeEndType)atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_endDepth = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_endCond = (TransCAD::StdExtrudeEndType)atoi(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_startDepth < 0 || _endDepth < 0, "Both depths should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(!(_startCond == 0 || _startCond == 1) || !(_endCond == 0 || _endCond == 1), "Both conditions should be either 0 or 1!");
	TSIThrowExceptionIf<TSIArgumentException>(_startDepth == 0 && _endDepth == 0 && _startCond == 0 && _endCond == 0, "Both depths and both conditions should not be 0 at the same time!");
}

void FeatureExtrude::Create(void)
{
	FeatureSketch * pProfile = dynamic_cast<FeatureSketch *>(GetPart()->GetFeatureByName(_sketchName));
	TSIThrowExceptionIf<TSIArgumentException>(pProfile->GetCloseness() == 0 || pProfile->GetCloseness() == 2, "The profile sketch is not closed!");

	if (GetType() == 1)
		GetPart()->GetFeaturesPtr()->AddNewSolidProtrusionExtrudeFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _startDepth, _startCond, _endDepth, _endCond, _isFlip);	
	else if (GetType() == 2)
		GetPart()->GetFeaturesPtr()->AddNewSolidCutExtrudeFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _startDepth, _startCond, _endDepth, _endCond, _isFlip);
}

void FeatureExtrude::AskInfo(void)
{
	char buffer[500];
	
	int startCond = 0, endCond = 0, flip = 0;

	if (_startCond == TransCAD::ThroughAll)
		startCond = 1;

	if (_endCond == TransCAD::ThroughAll)
		endCond = 1;
		
	if (_isFlip == VARIANT_TRUE)
		flip = 1;

	if (!IsModified() && !IsDeleted())
	{
		if (GetType() == 1)
			sprintf_s(buffer, sizeof(buffer),"createproextrude %s %s %f %d %f %d %d",GetName().c_str(), _sketchName.c_str(), _startDepth, startCond, _endDepth, endCond, flip);
		else if (GetType() == 2)
			sprintf_s(buffer, sizeof(buffer),"createcutextrude %s %s %f %d %f %d %d",GetName().c_str(), _sketchName.c_str(), _startDepth, startCond, _endDepth, endCond, flip);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %d %f %d %d",GetName().c_str(), _startDepth, startCond, _endDepth, endCond, flip);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureExtrude::Help(void)
{
	if (GetType() == 1)
	{
		cout << " [createproextrude p1 p2 p3 p4 p5 p6 p7]" << endl;
		cout << " -p1 : " << "Protrusion Extrude Name" << endl;
		cout << " -p2 : " << "Sketch Name" << endl;
		cout << " -p3 : " << "Start Depth" << endl;
		cout << " -p4 : " << "Start Condition (0:Blind, 1:ThroughAll)" << endl;
		cout << " -p5 : " << "End Depth" << endl;
		cout << " -p6 : " << "End Condition (0:Blind, 1:ThroughAll)" << endl;
		cout << " -p7 : " << "isFlip (0:False, 1:True)" << endl;
		cout << " [EXAMPLE] " << "createproextrude Extrude1 Sketch1 100 0 0 0 0" << endl;
	}
	else if (GetType() == 2)
	{
		cout << " [createcutextrude p1 p2 p3 p4 p5 p6 p7]" << endl;
		cout << " -p1 : " << "Cut Extrude Name" << endl;
		cout << " -p2 : " << "Sketch Name" << endl;
		cout << " -p3 : " << "Start Depth" << endl;
		cout << " -p4 : " << "Start Condition (0:Blind, 1:ThroughAll)" << endl;
		cout << " -p5 : " << "End Depth" << endl;
		cout << " -p6 : " << "End Condition (0:Blind, 1:ThroughAll)" << endl;
		cout << " -p7 : " << "isFlip (0:False, 1:True)" << endl;
		cout << " [EXAMPLE] " << "createcutextrude Cut1 Sketch1 30 0 0 0 0" << endl;
	}
}