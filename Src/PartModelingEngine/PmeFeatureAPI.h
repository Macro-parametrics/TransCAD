#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeFeatureType.h"

class PME_API PmeFeatureAPI
{
public:
	static void GetName(PmeHFeature hFeature, CString & name);
	static void GetPart(PmeHFeature hFeature, PmeHPart & hPart);
	static void GetType(PmeHFeature hFeature, PmeFeatureType & type);

	static void SetName(PmeHFeature hFeature, CString name);
};

