#include "stdafx.h"
#include "FeatureDraft.h"
#include "Part.h"


FeatureDraft::FeatureDraft(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureDraft::~FeatureDraft(void)
{
}

void FeatureDraft::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

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
	_draftAngle = atof(token.c_str());

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(_org == _dir, "Origin and direction should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_draftAngle <= 0, "Draft angle should be greater than zero!");

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

void FeatureDraft::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidDraftFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(18);

	_spFeature->GetPullingDirection(&_org[0], &_org[1], &_org[2], &_dir[0], &_dir[1], &_dir[2]);
	_draftAngle = _spFeature->GetDraftAngle();
	SetReferencesPtr(_spFeature->GetTargetFaces());
	
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeatureDraft::Modify(char * command)
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
	_draftAngle = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_org == _dir, "Origin and direction should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_draftAngle <= 0, "Draft angle should be greater than zero!");
}

void FeatureDraft::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidDraftFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], _draftAngle);
}

void FeatureDraft::AskInfo()
{
	char buffer[500];
	
	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createdraft %s %f %f %f %f %f %f %f", GetName().c_str(), _org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], _draftAngle);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f %f", GetName().c_str(), _org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], _draftAngle);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureDraft::Help(void)
{
	cout << " [createdraft p1 p2 p3 p4 p5 p6 p7 p8]" << endl;
	cout << " -p1 : " << "Draft Name" << endl;
	cout << " -p2 : " << "Pulling Origin (X)" << endl;
	cout << " -p3 : " << "Pulling Origin (Y)" << endl;
	cout << " -p4 : " << "Pulling Origin (Z)" << endl;
	cout << " -p5 : " << "Pulling Direction (X)" << endl;
	cout << " -p6 : " << "Pulling Direction (Y)" << endl;
	cout << " -p7 : " << "Pulling Direction (Z)" << endl;
	cout << " -p8 : " << "Draft Angle" << endl;
	cout << " [EXAMPLE] " << "createdraft Draft1 0 0 0 0 0 1 30" << endl;
	cout << " [NOTE] " << "Need to select a face before" << endl;
}