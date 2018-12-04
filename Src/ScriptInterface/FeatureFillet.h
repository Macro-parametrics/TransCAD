#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeatureFillet : public Feature
{
public:
	FeatureFillet(Part * pPart, int featureType);	// 기본 생성자
	FeatureFillet(FeatureFillet & pFeature)			// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_radius = pFeature._radius;
		_propagationType = pFeature._propagationType;
	}

	virtual ~FeatureFillet(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	double _radius;
	TransCAD::PropagationType _propagationType;
};