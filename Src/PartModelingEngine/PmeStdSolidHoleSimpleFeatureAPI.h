#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidHoleSimpleFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hTargetFace,
		double centerX,
		double centerY,
		double centerZ,
		double radius,
		double depth,
		PmeHFeature & hFeature
	);

	static void GetTargetFace(PmeHFeature hFeature, PmeHReference & hTargetFace);
	static void GetCenterX(PmeHFeature hFeature, double & centerX);
	static void GetCenterY(PmeHFeature hFeature, double & centerY);
	static void GetCenterZ(PmeHFeature hFeature, double & centerY);
	static void GetRadius(PmeHFeature hFeature, double & radius);
	static void GetDepth(PmeHFeature hFeature, double & depth);

	static void SetTargetFace(PmeHFeature hFeature, PmeHReference hTargetFace);
	static void SetCenterX(PmeHFeature hFeature, double centerX);
	static void SetCenterY(PmeHFeature hFeature, double centerY);
	static void SetCenterZ(PmeHFeature hFeature, double centerY);
	static void SetRadius(PmeHFeature hFeature, double radius);
	static void SetDepth(PmeHFeature hFeature, double depth);
};
