#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"


class PME_API PmeStdSolidShellFeatureAPI
{
public:
    static void Create
		(
			PmeHPart hPart,
			const CString & name,
			PmeHReferences hTargetFaces,
			double innerThickness,
			double outerThickness,
			PmeHFeature & hFeature
		);

	static void GetTargetFaces(PmeHFeature hFeature, PmeHReferences & hTargetFaces);
	static void GetInnerThickness(PmeHFeature hFeature, double & innerThickness);
	static void GetOuterThickness(PmeHFeature hFeature, double & outerThickness);

	static void SetTargetFaces(PmeHFeature hFeature, PmeHReferences hTargetFaces);
	static void SetInnerThickness(PmeHFeature hFeature, double innerThickness);
	static void SetOuterThickness(PmeHFeature hFeature, double outerThickness);
};