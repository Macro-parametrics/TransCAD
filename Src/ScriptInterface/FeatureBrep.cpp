#include "stdafx.h"
#include "FeatureBrep.h"
#include "Part.h"
#include <io.h>

FeatureBrep::FeatureBrep(Part * pPart, int featureType) 
	: Feature(pPart, featureType)
{
}

FeatureBrep::~FeatureBrep(void)
{
}

void FeatureBrep::GetInfo(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	SetName(token);

	token = StringToken::GetString( NULL, seps_blank, command );
	_filePath = token;
	
	int pathValid = _access(_filePath.c_str(), 0);

	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(!CheckExistence(GetName()), "Enter another name!");
	TSIThrowExceptionIf<TSIArgumentException>(pathValid == -1, "Invalid file path!");
	//
	Create();
}

void FeatureBrep::AddInfo(TransCAD::IFeaturePtr spFeature)
{
	TransCAD::IStdSolidImportedBrepFeaturePtr _spFeature = spFeature;
	string name(_spFeature->GetName());
	SetName(name);
	SetType(20);

	_filePath = _spFeature->GetFilePath();
}

void FeatureBrep::Modify(char * command)
{
	token = StringToken::GetString( NULL, seps_blank, command );
	_filePath = token;
	
	int pathValid = _access(_filePath.c_str(), 0);
	
	TSIThrowExceptionIf<TSIArgumentException>(!CheckValid(token), "Insufficient input parameters!");
	TSIThrowExceptionIf<TSIArgumentException>(pathValid == -1, "Invalid file path!");
}

void FeatureBrep::Create(void)
{
	GetPart()->GetFeaturesPtr()->AddNewSolidImportedBrepFeature(GetName().c_str(), _filePath.c_str());
}

void FeatureBrep::AskInfo(void)
{
	char buffer[500];
	
	if (!IsModified() && !IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"importbrep %s %s", GetName().c_str(), _filePath.c_str());
	}
	else if (IsModified())
	{
		sprintf_s(buffer, sizeof(buffer),"modify %s %s", GetName().c_str(), _filePath.c_str());
	}
	else if (IsDeleted())
	{
		sprintf_s(buffer, sizeof(buffer),"delete %s",GetName().c_str());
	}

	cout << buffer << endl;
}

void FeatureBrep::Help(void)
{
	cout << " [importbrep p1 p2]" << endl;
	cout << " -p1 : " << "Brep Solid Name" << endl;
	cout << " -p2 : " << "File Path" << endl;
	cout << " [EXAMPLE 1] " << "importbrep Solid1 C:\\K1.stp" << endl;
	cout << " [EXAMPLE 2] " << "importbrep Solid1 C:\\K1.sat" << endl;
	cout << " [EXAMPLE 3] " << "importbrep Solid1 C:\\K1.igs" << endl;
	cout << " [NOTE] " << "This function is for importing a brep solid" << endl;
	cout << " [NOTE] " << "Supporting Formats: .stp, .sat, .igs" << endl;
}