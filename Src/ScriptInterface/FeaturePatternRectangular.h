#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeaturePatternRectangular : public Feature
{
public:
	FeaturePatternRectangular(Part * pPart, int featureType);		// 기본 생성자
	FeaturePatternRectangular(FeaturePatternRectangular & pFeature) // 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_colNumber = pFeature._colNumber;
		_colSpacing = pFeature._colSpacing;
		_rowNumber = pFeature._rowNumber;
		_rowSpacing = pFeature._rowSpacing;
		//_targetFeatureName = pFeature._targetFeatureName;
		
		_colDir = pFeature._colDir;
		_rowDir = pFeature._rowDir;
	}

	virtual ~FeaturePatternRectangular(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);
	
	void AskInfo(void);
	void Help(void);

private:
	Point3D _colDir, _rowDir;
	double _colSpacing, _rowSpacing;
	int _colNumber, _rowNumber;
	string _targetFeatureName;
};