#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeSamePointsType.h"

class PME_API PmeStdSketchCoincidentAPI
{
public:
    static void GetFirstGeometry(PmeHStdSketchConstraint hCoincident, PmeHReference & hFirstGeometry);
    static void GetSecondGeometry(PmeHStdSketchConstraint hCoincident, PmeHReference & hSecondGeometry);
	static void GetFirstObjectType(PmeHStdSketchConstraint hCoincident, PmeSamePointsType & firstType);
	static void GetSecondObjectType(PmeHStdSketchConstraint hCoincident, PmeSamePointsType & secondType);
};