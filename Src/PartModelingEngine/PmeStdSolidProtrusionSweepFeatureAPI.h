#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidProtrusionSweepFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hProfileSketch,
		PmeHReference hGuideCurve,
		PmeHFeature & hFeature
	);

	static void GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch);
	static void GetGuideCurve(PmeHFeature hFeature, PmeHReference & hGuideCurve);

	static void SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch);
	static void SetGuideCurve(PmeHFeature hFeature, PmeHReference hGuideCurve);
};
