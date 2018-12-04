#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeatureLoft : public Feature
{
public:
	FeatureLoft(Part * pPart, int featureType);	// 기본 생성자
	FeatureLoft(FeatureLoft & pFeature)			// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_loftSketchNum = pFeature._loftSketchNum;
		_isCut = pFeature._isCut;
		_loftSketchName = pFeature._loftSketchName;
	}

	virtual ~FeatureLoft(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	int _loftSketchNum;
	vector<string> _loftSketchName;
	VARIANT_BOOL _isCut;
};