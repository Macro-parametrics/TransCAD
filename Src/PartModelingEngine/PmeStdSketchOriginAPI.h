#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchOriginAPI
{
public:
	static void GetName(PmeHStdSketchOrigin hOrigin, CString & name);
};