#include "stdafx.h"
#include "FeatureLoft.h"
#include "FeatureSketch.h"
#include "Part.h"


FeatureLoft::FeatureLoft(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureLoft::~FeatureLoft(void)
{
}

void FeatureLoft::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_isCut = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;

	token = StringToken::GetString( NULL, seps_blank, command );
	_loftSketchNum = atoi(token.c_str());
	
	SetReferencesPtr(GetPart()->GetPartPtr()->CreateReferences());

	for (int i = 0; i < _loftSketchNum; ++i)
	{
		token = StringToken::GetString( NULL, seps_blank, command );
		_loftSketchName.push_back(token);

		SetReferencePtr(GetPart()->GetPartPtr()->SelectObjectByName(_loftSketchName[i].c_str()));

		if (GetReferencePtr())
			GetReferencesPtr()->Add(GetReferencePtr());
	}
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(_loftSketchNum <= 1, "The number of sketches should be greater than 1!");
	TSIThrowExceptionIf<TSIArgumentException>(GetReferencesPtr()->GetCount() <= 1, "Enter more than two valid sketches!");
	
	AddReference(GetReferencesPtr());
	Create();
}

void FeatureLoft::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidLoftSectionsFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(17);

	_loftSketchNum = _spFeature->GetReferences()->GetCount();
	_isCut = _spFeature->GetIsCut();

	SetReferencesPtr(_spFeature->GetReferences());
	
	assert(_loftSketchNum >= 2);
	assert(GetReferencesPtr());

	for (int i = 1; i <= _loftSketchNum; ++i)
		_loftSketchName.push_back((string)GetReferencesPtr()->GetItem(i)->GetReferenceeName());

	AddReference(GetReferencesPtr());
}

void FeatureLoft::Modify(char * command)
{
	// 필요 여부 판단 후 추가
}

void FeatureLoft::Create(void)
{
	for (int i = 0; i < (int)_loftSketchName.size(); ++i)
	{
		FeatureSketch * pProfile = dynamic_cast<FeatureSketch *>(GetPart()->GetFeatureByName(_loftSketchName[i]));
		TSIThrowExceptionIf<TSIArgumentException>(pProfile->GetCloseness() == 0 || pProfile->GetCloseness() == 2, "The profile sketch is not closed!");
	}

	GetPart()->GetFeaturesPtr()->AddNewSolidLoftSectionsFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _isCut);
}

void FeatureLoft::AskInfo(void)
{
	char buffer[500];
	token.clear();

	for (int i = 0; i < (int)_loftSketchName.size(); ++i)
		token = token + _loftSketchName[i] + " ";
	
	if (!IsModified() && !IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"createloft %s %d %d %s",GetName().c_str(), _isCut, _loftSketchNum, token.c_str());
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

void FeatureLoft::Help(void)
{
	cout << " [createloft p1 p2 p3 p4 ... pn]" << endl;
	cout << " -p1 : " << "Loft Name" << endl;
	cout << " -p2 : " << "isCut (0:False, 1:True)" << endl;
	cout << " -p3 : " << "Loft Sketch Number" << endl;
	cout << " -p4 ... pn : " << "Loft Sketch Names" << endl;
	cout << " [EXAMPLE] " << "createloft Loft1 0 3 Sketch1 Sketch2 Sketch3" << endl;
}