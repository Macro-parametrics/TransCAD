#include "stdafx.h"
#include "FeatureChamfer.h"
#include "Part.h"


FeatureChamfer::FeatureChamfer(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureChamfer::~FeatureChamfer(void)
{
}

void FeatureChamfer::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_length = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_length <= 0, "Length should be greater than zero!");

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

void FeatureChamfer::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidChamferFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(6);

	_length = _spFeature->GetLength();
	SetReferencesPtr(_spFeature->GetSelectedEdges());
	
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeatureChamfer::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_length = atof(token.c_str());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_length <= 0, "Length should be greater than zero!");
}

void FeatureChamfer::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidChamferFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _length);
}

void FeatureChamfer::AskInfo()
{
	char buffer[500];
	
	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createchamfer %s %f", GetName().c_str(), _length);
	}	
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f", GetName().c_str(), _length);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureChamfer::Help(void)
{
	cout << " [createchamfer p1 p2]" << endl;
	cout << " -p1 : " << "Chamfer Name" << endl;
	cout << " -p2 : " << "Length" << endl;
	cout << " [EXAMPLE] " << "createchamfer Chamfer1 10" << endl;
	cout << " [NOTE] " << "Need to select a face or an edge before" << endl;
}