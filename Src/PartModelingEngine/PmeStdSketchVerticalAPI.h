#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeSamePointsType.h"

class PME_API PmeStdSketchVerticalAPI
{
public:
    static void GetReferenceEdit(PmeHStdSketchConstraint hVertical, PmeHReference & hReferenceEdit);
    static void GetTarget(PmeHStdSketchConstraint hVertical, PmeHReference & hTarget);
};