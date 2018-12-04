#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeStdAssemblyConstraintType.h"

class PME_API PmeStdAssemblyConstraintAPI
{
public:
	static void GetName(PmeHStdAssemblyConstraint hStdAssemblyConstraint, CString & name);
	static void SetName(PmeHStdAssemblyConstraint hStdAssemblyConstraint, CString name );
	static void GetType(PmeHStdAssemblyConstraint hStdAssemblyConstraint, PmeStdAssemblyConstraintType & type);
};

