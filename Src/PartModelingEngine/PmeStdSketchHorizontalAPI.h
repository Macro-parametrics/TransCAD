#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeSamePointsType.h"

class PME_API PmeStdSketchHorizontalAPI
{
public:
    static void GetReferenceEdit(PmeHStdSketchConstraint hHorizontal, PmeHReference & hReferenceEdit);
    static void GetTarget(PmeHStdSketchConstraint hHorizontal, PmeHReference & hTarget);
};