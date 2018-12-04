#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeSamePointsType.h"

class PME_API PmeStdSketchPerpendicularAPI
{
public:
    static void GetReferenceEdit(PmeHStdSketchConstraint hPerpendicular, PmeHReference & hReferenceEdit);
    static void GetTarget(PmeHStdSketchConstraint hPerpendicular, PmeHReference & hTarget);
};