#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchCenterlineAPI
{
public:
	static void GetStartPoint(PmeHStdSketchGeometry hCenterline, PmeHStdSketchGeometry & hStartPoint);
	static void GetEndPoint(PmeHStdSketchGeometry hCenterline, PmeHStdSketchGeometry & hEndPoint);
};