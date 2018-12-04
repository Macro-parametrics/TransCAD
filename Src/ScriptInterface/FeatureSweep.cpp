#include "stdafx.h"
#include "FeatureSweep.h"
#include "FeatureSketch.h"
#include "Part.h"


FeatureSweep::FeatureSweep(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureSweep::~FeatureSweep(void)
{
}

void FeatureSweep::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);
	
	SetReferencesPtr(GetPart()->GetPartPtr()->CreateReferences());

	for (int i = 0; i < 2; ++i)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		_sweepSketchName.push_back(token);

		SetReferencePtr(GetPart()->GetPartPtr()->SelectObjectByName(_sweepSketchName[i].c_str()));

		if (GetReferencePtr())
			GetReferencesPtr()->Add(GetReferencePtr());
	}
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencesPtr()->GetCount() <= 1, "Enter two valid sketches!");
	TSIThrowExceptionIf<TSIArgumentException>(_sweepSketchName[0] == _sweepSketchName[1], "Two sketches should be different!");
	
	AddReference(GetReferencesPtr());
	Create();
}

void FeatureSweep::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	if (GetType() == 4)
	{
		TransCAD::IStdSolidProtrusionSweepFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(4);

		SetReferencesPtr(GetPart()->GetPartPtr()->CreateReferences());
		GetReferencesPtr()->Add(_spFeature->GetProfileSketch());
		GetReferencesPtr()->Add(_spFeature->GetGuideCurve());
	}
	else
	{
		TransCAD::IStdSolidCutSweepFeaturePtr _spFeature = spFeature;
		string name(_spFeature->GetName());
		SetName(name);
		SetType(5);

		SetReferencesPtr(GetPart()->GetPartPtr()->CreateReferences());
		GetReferencesPtr()->Add(_spFeature->GetProfileSketch());
		GetReferencesPtr()->Add(_spFeature->GetGuideCurve());
	}
	
	assert(GetReferencesPtr()->GetCount() == 2);

	for (int i = 1; i <= 2; ++i)
		_sweepSketchName.push_back((string)GetReferencesPtr()->GetItem(i)->GetReferenceeName());

	AddReference(GetReferencesPtr());
}

void FeatureSweep::Modify(char * command)
{
	// 필요 여부 판단 후 추가
}

void FeatureSweep::Create(void)
{
	FeatureSketch * pProfile = dynamic_cast<FeatureSketch *>(GetPart()->GetFeatureByName(_sweepSketchName[0]));
	TSIThrowExceptionIf<TSIArgumentException>(pProfile->GetCloseness() == 0 || pProfile->GetCloseness() == 2, "The profile sketch is not closed!");

	FeatureSketch * pGuide = dynamic_cast<FeatureSketch *>(GetPart()->GetFeatureByName(_sweepSketchName[1]));
	TSIThrowExceptionIf<TSIArgumentException>(pGuide->GetCloseness() == 0, "The guide sketch is not connected!");
	
	if (GetType() == 4)
		GetPart()->GetFeaturesPtr()->AddNewSolidProtrusionSweepFeature(GetName().c_str(), GetReference()->GetReferencesPtr()->GetItem(1), GetReference()->GetReferencesPtr()->GetItem(2));
	else
		GetPart()->GetFeaturesPtr()->AddNewSolidCutSweepFeature(GetName().c_str(), GetReference()->GetReferencesPtr()->GetItem(1), GetReference()->GetReferencesPtr()->GetItem(2));
}

void FeatureSweep::AskInfo(void)
{
	char buffer[500];
	
	if (!IsModified() && !IsDeleted())
	{
		if (GetType() == 4)
			sprintf_s(buffer, sizeof(buffer),"createprosweep %s %s %s", GetName().c_str(), _sweepSketchName[0].c_str(), _sweepSketchName[1].c_str());
		else if (GetType() == 5)
			sprintf_s(buffer, sizeof(buffer),"createcutsweep %s %s %s", GetName().c_str(), _sweepSketchName[0].c_str(), _sweepSketchName[1].c_str());
	}
	else if (IsModified())
	{
		// 수정 지원 X	
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureSweep::Help(void)
{
	if (GetType() == 4)
	{
		cout << " [createprosweep p1 p2 p3]" << endl;
		cout << " -p1 : " << "Protrusion Sweep Name" << endl;
		cout << " -p2 : " << "Profile Sketch Name" << endl;
		cout << " -p3 : " << "Guide Sketch Name" << endl;
		cout << " [EXAMPLE] " << "createprosweep Sweep1 Sketch1 Sketch2" << endl;
	}
	else if (GetType() == 5)
	{
		cout << " [createcutsweep p1 p2 p3]" << endl;
		cout << " -p1 : " << "Cut Sweep Name" << endl;
		cout << " -p2 : " << "Profile Sketch Name" << endl;
		cout << " -p3 : " << "Guide Sketch Name" << endl;
		cout << " [EXAMPLE] " << "createcutsweep Sweep1 Sketch1 Sketch2" << endl;
	}
}