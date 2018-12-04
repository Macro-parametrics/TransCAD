#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeStdSketchGeometryType.h"

class PME_API PmeStdSketchGeometryAPI
{
public:
	static void SetName(PmeHStdSketchGeometry hGeometry, const CString & name);
	static void GetName(PmeHStdSketchGeometry hGeometry, CString & name);
	static void GetType(PmeHStdSketchGeometry hGeometry, PmeStdSketchGeometryType & type);
};