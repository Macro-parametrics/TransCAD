#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeDatumPlaneAPI
{
public:
	static void GetLocation(PmeHExplicitModelObject hObject, MrAxis2 & location);
};