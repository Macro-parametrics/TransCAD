#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchLineAPI
{
public:
    static void GetStartPoint(PmeHStdSketchGeometry hLine, PmeHStdSketchGeometry & hStartPoint);
    static void GetEndPoint(PmeHStdSketchGeometry hLine, PmeHStdSketchGeometry & hEndPoint);
};