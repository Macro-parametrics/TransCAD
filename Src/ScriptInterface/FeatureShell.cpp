#include "stdafx.h"
#include "FeatureShell.h"
#include "Part.h"


FeatureShell::FeatureShell(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureShell::~FeatureShell(void)
{
}

void FeatureShell::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_innerThickness = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_outerThickness = atof(token.c_str());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_innerThickness < 0 || _outerThickness < 0, "Both thicknesses should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_innerThickness == 0 && _outerThickness == 0, "Both thicknesses should not be zero at the same time!");

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

void FeatureShell::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidShellFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(16);

	_innerThickness = _spFeature->GetInnerThickness();
	_outerThickness = _spFeature->GetOuterThickness();
	SetReferencesPtr(_spFeature->GetTargetFaces());
	
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeatureShell::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_innerThickness = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_outerThickness = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_innerThickness < 0 || _outerThickness < 0, "Both thicknesses should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_innerThickness == 0 && _outerThickness == 0, "Both thicknesses should not be zero at the same time!");
}

void FeatureShell::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidShellFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _innerThickness, _outerThickness);
}

void FeatureShell::AskInfo()
{
	char buffer[500];
	
	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createshell %s %f %f", GetName().c_str(), _innerThickness, _outerThickness);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %f", GetName().c_str(), _innerThickness, _outerThickness);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureShell::Help(void)
{
	cout << " [createshell p1 p2 p3]" << endl;
	cout << " -p1 : " << "Shell Name" << endl;
	cout << " -p2 : " << "Inner Thickness" << endl;
	cout << " -p3 : " << "Outer Thickness" << endl;
	cout << " [EXAMPLE] " << "createshell Shell1 2 2" << endl;
	cout << " [NOTE] " << "Need to select a face before" << endl;
}