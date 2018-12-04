#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchControlPointAPI
{
public:
	static void GetPosition(PmeHStdSketchGeometry hControlPoint, double & x, double & y);
};