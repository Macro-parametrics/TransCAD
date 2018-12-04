#pragma once
#include "TransCADScript.h"
#include "Feature.h"

class FeatureDatumPlaneEquation : public Feature
{
public:
	FeatureDatumPlaneEquation(Part * pPart, int featureType);
	FeatureDatumPlaneEquation(FeatureDatumPlaneEquation & pFeature) // 복사 생성자.
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_org = pFeature._org;
		_xDir = pFeature._xDir;
		_yDir = pFeature._yDir;
		_isFlip = pFeature._isFlip;
	}

	virtual ~FeatureDatumPlaneEquation(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);
	
	void AskInfo(void);
	void Help(void);

private:
	Point3D _org, _xDir, _yDir;
	VARIANT_BOOL _isFlip;
};