#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeBrepType.h"

class PME_API PmeBrepReferenceAPI
{
public:
	static void GetBrepType(PmeHReference hReference, PmeBrepType & type);
};