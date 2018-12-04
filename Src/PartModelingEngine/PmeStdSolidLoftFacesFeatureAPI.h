#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidLoftFacesFeatureAPI
{
public:
	static void Create
		(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hFace1,
		double param1,
		PmeHReference hFace2,
		double param2,
		PmeHFeature & hFeature
		);

	static void GetFace1(PmeHFeature hFeature, PmeHReference & hFace1);
	static void GetParam1(PmeHFeature hFeature, double & param1);
	static void GetFace2(PmeHFeature hFeature, PmeHReference & hFace2);
	static void GetParam2(PmeHFeature hFeature, double & param2);
};
