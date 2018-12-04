#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeatureOffset : public Feature
{
public:
	FeatureOffset(Part * pPart, int featureType);	// 기본 생성자
	FeatureOffset(FeatureOffset & pFeature)			// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_offsetThickness = pFeature._offsetThickness;
	}

	virtual ~FeatureOffset(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	double _offsetThickness;
};