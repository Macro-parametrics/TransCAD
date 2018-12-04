#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"


class PME_API PmeStdSolidDraftFeatureAPI
{
public:
    static void Create
		(
			PmeHPart hPart,
			const CString & name,
			PmeHReferences hTargetFaces,
			const MrAxis1 & pullingDirection,
			double draftAngle,
			PmeHFeature & hFeature
		);

	static void GetTargetFaces(PmeHFeature hFeature, PmeHReferences & hTargetFaces);
	static void GetPullingDirection(PmeHFeature hFeature, MrAxis1 & pullingDirection);
	static void GetDraftAngle(PmeHFeature hFeature, double & draftAngle);

	static void SetTargetFaces(PmeHFeature hFeature, PmeHReferences hTargetFaces);
	static void SetPullingDirection(PmeHFeature hFeature, MrAxis1 pullingDirection);
	static void SetDraftAngle(PmeHFeature hFeature, double draftAngle);
};