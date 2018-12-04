#include "stdafx.h"
#include "FeaturePatternRectangular.h"
#include "Part.h"


FeaturePatternRectangular::FeaturePatternRectangular(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeaturePatternRectangular::~FeaturePatternRectangular(void)
{
}

void FeaturePatternRectangular::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colDir.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colDir.Y(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colDir.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowDir.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowDir.Y(atof(token.c_str()));				
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowDir.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colSpacing = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_rowNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowSpacing = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(!GetPart()->GetCurrentReferencePtr() && !GetPart()->GetCurrentReferencesPtr(), "Select a reference first!");
	TSIThrowExceptionIf<TSIArgumentException>(_colDir == Point3D(0,0,0), "Invalid column direction!");
	TSIThrowExceptionIf<TSIArgumentException>(_rowDir == Point3D(0,0,0), "Invalid row direction!");
	TSIThrowExceptionIf<TSIArgumentException>(_colDir == _rowDir, "Two directions should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_colNumber < 1 || _rowNumber < 1, "Both instance numbers should be greater than and equal to 1!");
	TSIThrowExceptionIf<TSIArgumentException>(_colNumber == 1 && _rowNumber == 1, "Both instance numbers should not be 1 at the same time!");
	TSIThrowExceptionIf<TSIArgumentException>(_colSpacing < 0 || _rowSpacing < 0, "Both spacings should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_colSpacing == 0 && _rowSpacing == 0, "Both spacings should not be zero at the same time!");
	
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

void FeaturePatternRectangular::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidOperatePatternRectangularFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(11);
	
	double colDir[3], rowDir[3];
	_spFeature->GetColumnDirection(&colDir[0],&colDir[1],&colDir[2]);
	_spFeature->GetRowDirection(&rowDir[0],&rowDir[1],&rowDir[2]);
	_colDir.SetXYZ(colDir);
	_rowDir.SetXYZ(rowDir);

	_colNumber = _spFeature->GetColumnNumber();
	_colSpacing = _spFeature->GetColumnSpacing();

	_rowNumber = _spFeature->GetRowNumber();
	_rowSpacing = _spFeature->GetRowSpacing();

	SetReferencesPtr(_spFeature->GetTargetFeatures());
	assert(GetReferencesPtr());
	AddReference(GetReferencesPtr());
}

void FeaturePatternRectangular::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_colDir.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colDir.Y(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colDir.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowDir.X(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowDir.Y(atof(token.c_str()));				
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowDir.Z(atof(token.c_str()));
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_colSpacing = atof(token.c_str());

	token = StringToken::GetString( NULL, seps_blank, command );
	_rowNumber = atoi(token.c_str());
	
	token = StringToken::GetString( NULL, seps_blank, command );
	_rowSpacing = atof(token.c_str());
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(_colDir == Point3D(0,0,0), "Invalid column direction!");
	TSIThrowExceptionIf<TSIArgumentException>(_rowDir == Point3D(0,0,0), "Invalid row direction!");
	TSIThrowExceptionIf<TSIArgumentException>(_colDir == _rowDir, "Two directions should be different!");
	TSIThrowExceptionIf<TSIArgumentException>(_colNumber < 1 || _rowNumber < 1, "Both instance numbers should be greater than and equal to 1!");
	TSIThrowExceptionIf<TSIArgumentException>(_colNumber == 1 && _rowNumber == 1, "Both instance numbers should not be 1 at the same time!");
	TSIThrowExceptionIf<TSIArgumentException>(_colSpacing < 0 || _rowSpacing < 0, "Both spacings should be greater than and equal to zero!");
	TSIThrowExceptionIf<TSIArgumentException>(_colSpacing == 0 && _rowSpacing == 0, "Both spacings should not be zero at the same time!");
}

void FeaturePatternRectangular::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidOperatePatternRectangularFeature(GetName().c_str(), GetReference()->GetReferencesPtr(), _colSpacing, _colDir[0], _colDir[1], _colDir[2], _colNumber, 
																									_rowSpacing, _rowDir[0], _rowDir[1], _rowDir[2], _rowNumber);
}

void FeaturePatternRectangular::AskInfo(void)
{
	char buffer[500];

	if (!IsModified() && !IsDeleted())
	{
		GetReference()->AskInfo();
		sprintf_s(buffer, sizeof(buffer),"createrectpattern %s %f %f %f %f %f %f %d %f %d %f", GetName().c_str(), 
			_colDir[0], _colDir[1], _colDir[2], _rowDir[0], _rowDir[1], _rowDir[2], _colNumber, _colSpacing, _rowNumber, _rowSpacing);
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %f %f %f %f %f %f %d %f %d %f", GetName().c_str(), 
			_colDir[0], _colDir[1], _colDir[2], _rowDir[0], _rowDir[1], _rowDir[2], _colNumber, _colSpacing, _rowNumber, _rowSpacing);
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeaturePatternRectangular::Help(void)
{
	cout << " [createrectpattern p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11]" << endl;
	cout << " -p1 : " << "Rectangular Pattern Name" << endl;
	cout << " -p2 : " << "Column Direction (X)" << endl;
	cout << " -p3 : " << "Column Direction (Y)" << endl;
	cout << " -p4 : " << "Column Direction (Z)" << endl;
	cout << " -p5 : " << "Row Direction (X)" << endl;
	cout << " -p6 : " << "Row Direction (Y)" << endl;
	cout << " -p7 : " << "Row Direction (Z)" << endl;
	cout << " -p8 : " << "Column Instance Number" << endl;
	cout << " -p9 : " << "Column Spacing" << endl;
	cout << " -p10 : " << "Row Instance Number" << endl;
	cout << " -p11 : " << "Row Spacing" << endl;
	cout << " [EXAMPLE] " << "createrectpattern Pattern1 1 0 0 0 1 0 3 20 2 30" << endl;
	cout << " [NOTE] " << "Need to select more than one target feature before" << endl;
}