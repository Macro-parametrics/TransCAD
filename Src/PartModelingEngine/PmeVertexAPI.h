#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeVertexAPI
{
public:
	static void GetName(PmeHVertex hVertex, CString & name);
	static void GetCoordinates(PmeHVertex hVertex, MrPosition & coordinates);
};