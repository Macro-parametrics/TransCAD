#include "stdafx.h"
#include "FeatureDatumPlaneOffset.h"
#include "Part.h"


FeatureDatumPlaneOffset::FeatureDatumPlaneOffset(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureDatumPlaneOffset::~FeatureDatumPlaneOffset(void)
{
}

void FeatureDatumPlaneOffset::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_offset = atof(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;

	SetReferencePtr(GetPart()->GetCurrentReferencePtr());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencePtr() == NULL, "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_offset < 0, "Offset should be greater than and equal to zero!");

	GetPart()->SetCurrentReferencePtr(NULL);
	AddReference(GetReferencePtr());
	Create();
}

void FeatureDatumPlaneOffset::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdDatumPlaneOffsetFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(10);

	_offset = _spFeature->GetDistance();
	_isFlip = _spFeature->GetIsFlip();
	SetReferencePtr(_spFeature->GetSelectedPlane());

	assert(GetReferencePtr());
	AddReference(GetReferencePtr());
}

void FeatureDatumPlaneOffset::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_offset = atof(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_offset < 0, "Offset should be greater than and equal to zero!");
}

void FeatureDatumPlaneOffset::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewDatumPlaneOffsetFeature(GetName().c_str(), GetReference()->GetReferencePtr(), _offset, _isFlip);
}

void FeatureDatumPlaneOffset::AskInfo(void)
{
	char buffer[500];

	int flip = 0;

	if (_isFlip == VARIANT_TRUE)
		flip = 1;

	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createdatumplaneoffset %s %f %d", GetName().c_str(), _offset, flip);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %d", GetName().c_str(), _offset, flip);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureDatumPlaneOffset::Help(void)
{
	cout << " [createdatumplaneoffset p1 p2 p3]" << endl;
	cout << " -p1 : " << "DatumPlaneOffset Name" << endl;
	cout << " -p2 : " << "Distance" << endl;
	cout << " -p3 : " << "isFlip (0:False, 1:True)" << endl;
	cout << " [EXAMPLE] " << "createdatumplaneoffset Plane1 30 0" << endl;
	cout << " [NOTE] " << "Need to select a face before" << endl;
}