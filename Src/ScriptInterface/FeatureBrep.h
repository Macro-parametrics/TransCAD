#pragma once
#include "TransCADScript.h"
#include "Feature.h"

class FeatureBrep : public Feature
{
public:
	FeatureBrep(Part * pPart, int featureType);
	FeatureBrep(FeatureBrep & pFeature) // 복사 생성자.
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_filePath = pFeature._filePath;
	}

	virtual ~FeatureBrep(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);
	
	void AskInfo(void);
	void Help(void);

private:
	string _filePath;
};