#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeReferenceType.h"

class PME_API PmeReferenceAPI
{
public:
	static void GetName(PmeHReference hReference, CString & name);
	static void GetPart(PmeHReference hReference, PmeHPart & hPart);
	static void GetType(PmeHReference hReference, PmeReferenceType & type);
	static void GetReferenceeName(PmeHReference hReference, CString & referenceeName);
};