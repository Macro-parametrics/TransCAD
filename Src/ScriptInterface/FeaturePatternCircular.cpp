#include "stdafx.h"
#include "FeaturePatternCircular.h"
#include "Part.h"


FeaturePatternCircular::FeaturePatternCircular(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeaturePatternCircular::~FeaturePatternCircular(void)
{
}

void FeaturePatternCircular::GetInfo(char * command)
{
	token = strtok_s( NULL, seps_blank, &command );
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
	_angNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_angIncrement = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_radNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_radSpacing = atof(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_isRadialAligned = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_org == _dir, "Origin and direction should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_angNumber < 1 || _radNumber < 1, "Both instance numbers should be greater than and equal to 1!");
	TSIThrowExceptionIf<TSIArgumentException>(_angNumber == 1 && _radNumber == 1, "Both instance numbers should not be 1 at the same time!");
	TSIThrowExceptionIf<TSIArgumentException>(_radSpacing < 0 || _angIncrement < 0, "Both spacings should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_radSpacing == 0 && _angIncrement == 0, "Both spacings should not be zero at the same time!");
	
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

void FeaturePatternCircular::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidOperatePatternCircularFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(12);
	
	double org[3], dir[3];
	_spFeature->GetCenterAxis(&org[0], &org[1], &org[2], &dir[0], &dir[1], &dir[2]);
	_org.SetXYZ(org);
	_dir.SetXYZ(dir);

	_angNumber = _spFeature->GetAngleNumber();
	_angIncrement = _spFeature->GetAngleIncrement();

	_radNumber = _spFeature->GetRadialNumber();
	_radSpacing = _spFeature->GetRadialSpacing();

	_isRadialAligned = _spFeature->GetIsRadialAnignment();
	
	SetReferencesPtr(_spFeature->GetTargetFeatures());
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeaturePatternCircular::Modify(char * command)
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
	_angNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_angIncrement = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_radNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_radSpacing = atof(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_isRadialAligned = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_org == _dir, "Origin and direction should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_angNumber < 1 || _radNumber < 1, "Both instance numbers should be greater than and equal to 1!");
	TSIThrowExceptionIf<TSIArgumentException>(_angNumber == 1 && _radNumber == 1, "Both instance numbers should not be 1 at the same time!");
	TSIThrowExceptionIf<TSIArgumentException>(_radSpacing < 0 || _angIncrement < 0, "Both spacings should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_radSpacing == 0 && _angIncrement == 0, "Both spacings should not be zero at the same time!");
}

void FeaturePatternCircular::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidOperatePatternCircularFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], 
																								_angNumber, _angIncrement, _radNumber, _radSpacing, _isRadialAligned);
}

void FeaturePatternCircular::AskInfo(void)
{
	char buffer[500];
	int radialAligned = 0;
		
	if (_isRadialAligned == VARIANT_TRUE)
		radialAligned = 1;

	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createcircpattern %s %f %f %f %f %f %f %d %f %d %f %d", GetName().c_str(), 
		_org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], _angNumber, _angIncrement, _radNumber, _radSpacing, radialAligned);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f %d %f %d %f %d", GetName().c_str(), 
		_org[0], _org[1], _org[2], _dir[0], _dir[1], _dir[2], _angNumber, _angIncrement, _radNumber, _radSpacing, radialAligned);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeaturePatternCircular::Help(void)
{
	cout << " [createcircpattern p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12]" << endl;
	cout << " -p1 : " << "Circular Pattern Name" << endl;
	cout << " -p2 : " << "Axis Origin (X)" << endl;
	cout << " -p3 : " << "Axis Origin (Y)" << endl;
	cout << " -p4 : " << "Axis Origin (Z)" << endl;
	cout << " -p5 : " << "Axis Direction (X)" << endl;
	cout << " -p6 : " << "Axis Direction (Y)" << endl;
	cout << " -p7 : " << "Axis Direction (Z)" << endl;
	cout << " -p8 : " << "Angular Instance Number" << endl;
	cout << " -p9 : " << "Angular Increment" << endl;
	cout << " -p10 : " << "Radial Instance Number" << endl;
	cout << " -p11 : " << "Radial Spacing" << endl;
	cout << " -p12 : " << "RadialAlignement (0:False, 1:True)" << endl;
	cout << " [EXAMPLE] " << "createcircpattern Pattern1 0 0 0 0 0 1 6 60 1 0 1" << endl;
	cout << " [NOTE] " << "Need to select more than one target feature before" << endl;
}