#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"


class PME_API PmeStdSolidOffsetFeatureAPI
{
public:
    static void Create
		(
			PmeHPart hPart,
			const CString & name,
			PmeHReferences hTargetFaces,
			double thickness,
			PmeHFeature & hFeature
		);

	static void GetTargetFaces(PmeHFeature hFeature, PmeHReferences & hTargetFaces);
	static void GetThickness(PmeHFeature hFeature, double & thickness);

	static void SetTargetFaces(PmeHFeature hFeature, PmeHReferences hTargetFaces);
	static void SetThickness(PmeHFeature hFeature, double thickness);
};