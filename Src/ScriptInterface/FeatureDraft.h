#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeatureDraft : public Feature
{
public:
	FeatureDraft(Part * pPart, int featureType);	// 기본 생성자
	FeatureDraft(FeatureDraft & pFeature)			// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_draftAngle = pFeature._draftAngle;
		_org = pFeature._org;
		_dir = pFeature._dir;
	}

	virtual ~FeatureDraft(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	Point3D _org, _dir;
	double _draftAngle;
};