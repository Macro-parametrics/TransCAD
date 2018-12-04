#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchCircularArcAPI
{
public:
	static void GetCenterPoint(PmeHStdSketchGeometry hArc, PmeHStdSketchGeometry & hCenterPoint);
    static void GetStartPoint(PmeHStdSketchGeometry hArc, PmeHStdSketchGeometry & hStartPoint);
    static void GetEndPoint(PmeHStdSketchGeometry hArc, PmeHStdSketchGeometry & hEndPoint);
    static void GetRadius(PmeHStdSketchGeometry hArc, double & radius);
    static void GetStartAngle(PmeHStdSketchGeometry hArc, double & startAngle);
    static void GetEndAngle(PmeHStdSketchGeometry hArc, double & endAngle);
};