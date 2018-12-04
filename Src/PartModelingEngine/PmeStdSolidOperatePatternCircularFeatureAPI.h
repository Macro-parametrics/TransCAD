#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidOperatePatternCircularFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReferences hTargetFeatures,
		const MrAxis1 & centerAxis,
		int angleNumber,
		double angleIncrement, // degree
		int radialNumber,
		double radialSpacing,
		bool radialAlignment,
		PmeHFeature & hFeature
	);

	static void GetTargetFeatures(PmeHFeature hFeature, PmeHReferences & hTargetFeatures);
	static void GetCenterAxis(PmeHFeature hFeature, MrAxis1 & centerAxis);
	static void GetAngleNumber(PmeHFeature hFeature, int & angleNumber);
	static void GetAngleIncrement(PmeHFeature hFeature, double & angleIncrement);
	static void GetRadialNumber(PmeHFeature hFeature, int & radialNumber);
	static void GetRadialSpacing(PmeHFeature hFeature, double & radialSpacing);
	static void IsRadialAlignment(PmeHFeature hFeature, bool & isRadialAlignment);

	static void SetTargetFeatures(PmeHFeature hFeature, PmeHReferences hTargetFeatures);
	static void SetCenterAxis(PmeHFeature hFeature, MrAxis1 centerAxis);
	static void SetAngleNumber(PmeHFeature hFeature, int angleNumber);
	static void SetAngleIncrement(PmeHFeature hFeature, double angleIncrement);
	static void SetRadialNumber(PmeHFeature hFeature, int radialNumber);
	static void SetRadialSpacing(PmeHFeature hFeature, double radialSpacing);
	static void SetRadialAlignment(PmeHFeature hFeature, bool isRadialAlignment);
};