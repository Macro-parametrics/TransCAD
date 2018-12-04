#include "stdafx.h"
#include "FeatureFillet.h"
#include "Part.h"


FeatureFillet::FeatureFillet(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureFillet::~FeatureFillet(void)
{
}

void FeatureFillet::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_radius = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_propagationType = (TransCAD::PropagationType)atoi(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_radius <= 0, "Radius should be greater than zero!");
	
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

void FeatureFillet::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidFilletConstantFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(3);

	_radius = _spFeature->GetRadius();
	_propagationType = _spFeature->GetPropagation();
	SetReferencesPtr(_spFeature->GetFilletEdges());
	
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeatureFillet::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_radius = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_propagationType = (TransCAD::PropagationType)atoi(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_radius <= 0, "Radius should be greater than zero!");
}

void FeatureFillet::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidFilletConstantFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _radius, _propagationType);
}

void FeatureFillet::AskInfo(void)
{
	char buffer[500];

	int propagationType = 0;

	if (_propagationType == TransCAD::Tangency)
		propagationType = 1;

	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createfillet %s %f %d", GetName().c_str(), _radius, propagationType);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %d", GetName().c_str(), _radius, propagationType);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureFillet::Help(void)
{
	cout << " [createfillet p1 p2 p3]" << endl;
	cout << " -p1 : " << "Fillet Name" << endl;
	cout << " -p2 : " << "Radius" << endl;
	cout << " -p3 : " << "Propagation Type (0:Minimal, 1:Tangency)" << endl;
	cout << " [EXAMPLE] " << "createfillet Fillet1 10 0" << endl;
	cout << " [NOTE] " << "Need to select a face or an edge before" << endl;
}