#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeStdSketchConstraintType.h"

class PME_API PmeStdSketchConstraintAPI
{
public:
	static void SetName(PmeHStdSketchConstraint hConstraint, const CString & name);
	static void GetName(PmeHStdSketchConstraint hConstraint, CString & name);
	static void GetType(PmeHStdSketchConstraint hConstraint, PmeStdSketchConstraintType & type);
};