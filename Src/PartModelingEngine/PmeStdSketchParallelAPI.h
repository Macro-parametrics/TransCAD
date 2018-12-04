#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeSamePointsType.h"

class PME_API PmeStdSketchParallelAPI
{
public:
    static void GetReferenceEdit(PmeHStdSketchConstraint hParallel, PmeHReference & hReferenceEdit);
    static void GetTarget(PmeHStdSketchConstraint hParallel, PmeHReference & hTarget);
};