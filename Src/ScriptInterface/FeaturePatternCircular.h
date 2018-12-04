#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeaturePatternCircular : public Feature
{
public:
	FeaturePatternCircular(Part * pPart, int featureType);		// 기본 생성자
	FeaturePatternCircular(FeaturePatternCircular & pFeature)	// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_angNumber = pFeature._angNumber;
		_angIncrement = pFeature._angIncrement;
		_radNumber = pFeature._radNumber;
		_radSpacing = pFeature._radSpacing;
		_isRadialAligned = pFeature._isRadialAligned;
		//_targetFeatureName = pFeature._targetFeatureName;
		
		_org = pFeature._org;
		_dir = pFeature._dir;
	}

	virtual ~FeaturePatternCircular(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	Point3D _org, _dir;
	double _angIncrement, _radSpacing;
	int _angNumber, _radNumber;
	VARIANT_BOOL _isRadialAligned;
	string _targetFeatureName;
};