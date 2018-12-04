#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdAssemblyConstraintsAPI
{
public:
    static void Delete(PmeHStdAssemblyConstraints & hConstraints);
	static void GetSize(PmeHStdAssemblyConstraints hConstraints, int & size);
    static void GetItem(PmeHStdAssemblyConstraints hConstraints, int index, PmeHStdAssemblyConstraint & hConstraint);
    static void FindByItem(PmeHStdAssemblyConstraints hConstraints, PmeHStdAssemblyConstraint hConstraint, int & index);
	static void FindByName(PmeHStdAssemblyConstraints hConstraints, CString name, PmeHStdAssemblyConstraint & hConstraint);
	static void DeleteItem(PmeHStdAssemblyConstraints hConstraints, int index);
	static void Add( PmeHStdAssemblyConstraints hConstraints, PmeHStdAssemblyConstraint hConstraint );
};
