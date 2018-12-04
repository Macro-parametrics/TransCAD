#include "stdafx.h"
#include "FeatureDatumPlaneEquation.h"
#include "Part.h"


FeatureDatumPlaneEquation::FeatureDatumPlaneEquation(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureDatumPlaneEquation::~FeatureDatumPlaneEquation(void)
{
}

void FeatureDatumPlaneEquation::GetInfo(char * command)
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
	_xDir.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_xDir.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_xDir.Z(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_yDir.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_yDir.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_yDir.Z(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(_xDir == _yDir, "X and Y Direction must be different!");

	GetPart()->SetCurrentReferencePtr(NULL);
	Create();
}

void FeatureDatumPlaneEquation::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdDatumPlaneOffsetFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(21);

	double orgX = 0, orgY = 0, orgZ = 0;
	double xDirX = 0, xDirY = 0, xDirZ = 0;
	double yDirX = 0, yDirY = 0, yDirZ = 0;
	_spFeature->GetOrigin(&orgX, &orgY, &orgZ);
	_spFeature->GetXDirection(&xDirX, &xDirY, &xDirZ);
	_spFeature->GetYDirection(&yDirX, &yDirY, &yDirZ);

	_org.SetXYZ(orgX, orgY, orgZ);
	_xDir.SetXYZ(xDirX, xDirY, xDirZ);
	_yDir.SetXYZ(yDirX, yDirY, yDirZ);

	_isFlip = _spFeature->GetIsFlip();

	SetDepth(1);
	SetParentName("N/A");
}

void FeatureDatumPlaneEquation::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_org.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_org.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_org.Z(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_xDir.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_xDir.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_xDir.Z(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_yDir.X(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_yDir.Y(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_yDir.Z(atof(token.c_str()));

	token = StringToken::GetString( NULL, seps_blank, command );
	_isFlip = ((VARIANT_BOOL)atoi(token.c_str()))?VARIANT_TRUE:VARIANT_FALSE;
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_xDir == _yDir, "X and Y Direction must be different!");
}

void FeatureDatumPlaneEquation::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewDatumPlaneOffsetFeature2(GetName().c_str(), _org.X(), _org.Y(), _org.Z(), _xDir.X(), _xDir.Y(), _xDir.Z(), _yDir.X(), _yDir.Y(), _yDir.Z(), _isFlip);
}

void FeatureDatumPlaneEquation::AskInfo(void)
{
	char buffer[500];

	int flip = 0;

	if (_isFlip == VARIANT_TRUE)
		flip = 1;

	if (!IsModified() && !IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"createdatumplaneequation %s %f %f %f %f %f %f %f %f %f %d", GetName().c_str(), _org.X(), _org.Y(), _org.Z(), _xDir.X(), _xDir.Y(), _xDir.Z(), _yDir.X(), _yDir.Y(), _yDir.Z(), flip);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f %f %f %f %d", GetName().c_str(), _org.X(), _org.Y(), _org.Z(), _xDir.X(), _xDir.Y(), _xDir.Z(), _yDir.X(), _yDir.Y(), _yDir.Z(), flip);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureDatumPlaneEquation::Help(void)
{
	cout << " [createdatumplaneequation p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11]" << endl;
	cout << " -p1 : " << "Datum Plane Name" << endl;
	cout << " -p2 : " << "Datum Plane Origin (X)" << endl;
	cout << " -p3 : " << "Datum Plane Origin (Y)" << endl;
	cout << " -p4 : " << "Datum Plane Origin (Z)" << endl;
	cout << " -p5 : " << "Datum Plane XDirection (X)" << endl;
	cout << " -p6 : " << "Datum Plane XDirection (Y)" << endl;
	cout << " -p7 : " << "Datum Plane XDirection (Z)" << endl;
	cout << " -p8 : " << "Datum Plane YDirection (X)" << endl;
	cout << " -p9 : " << "Datum Plane YDirection (Y)" << endl;
	cout << " -p10 : " << "Datum Plane YDirection (Z)" << endl;
	cout << " -p11 : " << "isFlip (0:False, 1:True)" << endl;
	cout << " [EXAMPLE] " << "createdatumplaneequation Plane1 0 0 100 1 0 0 0 1 0 0" << endl;
}