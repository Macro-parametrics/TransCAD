#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidHoleCounterboredFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hTargetSketch,
		double centerX,
		double centerY,
		double centerZ,
		double startRadius,
		double startDepth,
		double endRadius,
		double endDepth,
		double angle,
		PmeHFeature & hFeature
	);

	static void GetTargetFace(PmeHFeature hFeature, PmeHReference & hTargetFace);
	static void GetCenterX(PmeHFeature hFeature, double & centerX);
	static void GetCenterY(PmeHFeature hFeature, double & centerY);
	static void GetCenterZ(PmeHFeature hFeature, double & centerZ);
	static void GetStartRadius(PmeHFeature hFeature, double & startRadius);
	static void GetStartDepth(PmeHFeature hFeature, double & startDepth);
	static void GetEndRadius(PmeHFeature hFeature, double & endRadius);
	static void GetEndDepth(PmeHFeature hFeature, double & endDepth);
	static void GetAngle(PmeHFeature hFeature, double & angle);

	static void SetTargetFace(PmeHFeature hFeature, PmeHReference hTargetFace);
	static void SetCenterX(PmeHFeature hFeature, double centerX);
	static void SetCenterY(PmeHFeature hFeature, double centerY);
	static void SetCenterZ(PmeHFeature hFeature, double centerZ);
	static void SetStartRadius(PmeHFeature hFeature, double startRadius);
	static void SetStartDepth(PmeHFeature hFeature, double startDepth);
	static void SetEndRadius(PmeHFeature hFeature, double endRadius);
	static void SetEndDepth(PmeHFeature hFeature, double endDepth);
	static void SetBottomAngle(PmeHFeature hFeature, double bottomAngle);
};
