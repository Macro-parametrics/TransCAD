#pragma once
#include "TransCADScript.h"
#include "Feature.h"


class FeatureRevolve : public Feature
{
public:
	FeatureRevolve(Part * pPart, int featureType);	// 기본 생성자
	FeatureRevolve(FeatureRevolve & pFeature)		// 복사 생성자
		:Feature(pFeature.GetPart(), pFeature.GetType())
	{
		CopyBasicInformation(pFeature);
		_startAngle = pFeature._startAngle;
		_endAngle = pFeature._endAngle;
		_startCond = pFeature._startCond;
		_endCond = pFeature._endCond;
		_isFlip = pFeature._isFlip;
		_sketchName = pFeature._sketchName;
		
		if (GetType() == 9)
		{
			_isCut = pFeature._isCut;
			_org = pFeature._org;
			_dir = pFeature._dir;
		}
	}

	virtual ~FeatureRevolve(void);

	void GetInfo(char * command);
	void AddInfo(TransCAD::IFeaturePtr spFeature);
	
	void Create(void);
	void Modify(char * command);

	void AskInfo(void);
	void Help(void);

private:
	double _startAngle, _endAngle;
	string _sketchName;
	TransCAD::StdRevolveEndType _startCond, _endCond;
	VARIANT_BOOL _isFlip;
	Point3D _org, _dir;		// RevolveWithAxis 용
	VARIANT_BOOL _isCut;	// RevolveWithAxis 용
};