#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdDatumPlaneOffsetFeatureAPI
{
public:
	static void Create
		(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hSelectedPlane,
		double distance,
		bool isFlip,
		PmeHFeature & hFeature
		);

	static void Create2
		(
		PmeHPart hPart,
		const CString & name,
		double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz,
		bool isFlip,
		PmeHFeature & hFeature
		);

	static void GetSelectedPlane(PmeHFeature hFeature, PmeHReference & hSelectedPlane);
	static void GetDistance(PmeHFeature hFeature, double & distance);
	static void GetOrigin(PmeHFeature hFeature, MrPosition & origin);
	static void GetXDirection(PmeHFeature hFeature, MrDirection & xdir);
	static void GetYDirection(PmeHFeature hFeature, MrDirection & ydir);
	static void IsFlip(PmeHFeature hFeature, bool & isFlip);
	static void IsFree(PmeHFeature hFeature, bool & isFree);

	static void SetSelectedPlane(PmeHFeature hFeature, PmeHReference hSelectedPlane);
	static void SetDistance(PmeHFeature hFeature, double distance);
	static void SetFlip(PmeHFeature hFeature, bool isFlip);
	static void SetOrigin(PmeHFeature hFeature, MrPosition origin);
	static void SetXDirection(PmeHFeature hFeature, MrDirection xdir);
	static void SetYDirection(PmeHFeature hFeature, MrDirection ydir);
};

