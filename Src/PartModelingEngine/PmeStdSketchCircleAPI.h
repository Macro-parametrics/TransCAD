#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchCircleAPI
{
public:
    static void GetCenterPoint(PmeHStdSketchGeometry hCircle, PmeHStdSketchGeometry & hCenterPoint);
    static void GetRadius(PmeHStdSketchGeometry hCircle, double & radius);
};