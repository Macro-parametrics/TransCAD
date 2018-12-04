#pragma once
#include "TransCADScript.h"
#include "Feature.h"

class FeatureDatumPlaneOffset : public Feature
{
public:
	FeatureDatumPlaneOffset(Part * pPart, int featureType);
	FeatureDatumPlaneOffset(FeatureDatumPlaneOffset & pFeature) // 복사 생성자.
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_offset = pFeature._offset;
		_isFlip = pFeature._isFlip;
	}

	virtual ~FeatureDatumPlaneOffset(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);
	
	void AskInfo(void);
	void Help(void);

private:
	double _offset;
	VARIANT_BOOL _isFlip;
};