#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchConstraintsAPI
{
public:
	static void GetSize(PmeHStdSketchConstraints & hConstraints, int & size);
	static void GetItem(PmeHStdSketchConstraints & hConstraints, int index, PmeHStdSketchConstraint & hConstraint);
	static void FindByItem(PmeHStdSketchConstraints & hConstraints, PmeHStdSketchConstraint hConstraint, int & index);
};