#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeatureShell : public Feature
{
public:
	FeatureShell(Part * pPart, int featureType);	// 기본 생성자
	FeatureShell(FeatureShell & pFeature)			// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_innerThickness = pFeature._innerThickness;
		_outerThickness = pFeature._outerThickness;
	}

	virtual ~FeatureShell(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	double _innerThickness, _outerThickness;
};