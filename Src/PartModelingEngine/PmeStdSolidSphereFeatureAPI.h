#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidSphereFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart
		, const MrPosition & location
		, double radius
		, PmeHFeature & hFeature
	);
};