#include "stdafx.h"
#include "FeatureOffset.h"
#include "Part.h"


FeatureOffset::FeatureOffset(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureOffset::~FeatureOffset(void)
{
}

void FeatureOffset::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_offsetThickness = atof(token.c_str());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_offsetThickness <= 0, "Offset thicknesses should be greater than zero!");

	if (GetPart()->GetCurrentReferencePtr())
	{
		SetReferencesPtr(GetPart()->GetPartPtr()->CreateReferences());
		GetReferencesPtr()->Add(GetPart()->GetCurrentReferencePtr());
		GetPart()->SetCurrentReferencePtr(NULL);
	}
	else if (GetPart()->GetCurrentReferencesPtr())
	{
		SetReferencesPtr(GetPart()->GetCurrentReferencesPtr());
		GetPart()->SetCurrentReferencesPtr(NULL);
	}

	AddReference(GetReferencesPtr());
	Create();
}

void FeatureOffset::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidOffsetFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(19);

	_offsetThickness = _spFeature->GetOffsetThickness();
	SetReferencesPtr(_spFeature->GetTargetFaces());
	
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeatureOffset::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_offsetThickness = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_offsetThickness <= 0, "Offset thicknesses should be greater than zero!");
}

void FeatureOffset::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidOffsetFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _offsetThickness);
}

void FeatureOffset::AskInfo()
{
	char buffer[500];
	
	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createoffset %s %f", GetName().c_str(), _offsetThickness);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f", GetName().c_str(), _offsetThickness);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureOffset::Help(void)
{
	cout << " [createoffset p1 p2]" << endl;
	cout << " -p1 : " << "Offset Name" << endl;
	cout << " -p2 : " << "Offset Thickness" << endl;
	cout << " [EXAMPLE] " << "createoffset Offset1 20" << endl;
	cout << " [NOTE] " << "Need to select a face before" << endl;
}