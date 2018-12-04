#pragma once

#include ".\PmeObject.h"
#include ".\PmeBaseList.h"
#include ".\PmeStdAssemblyConstraintType.h"

class PmeStdAssemblyConstraint;

class PmeStdAssemblyConstraints
	: public PmeObject
	, public PmeBaseList<PmeStdAssemblyConstraint *>
{
	typedef PmeBaseList<PmeStdAssemblyConstraint *> BaseList;

	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyConstraints)
public:
	PmeStdAssemblyConstraints(void);
	virtual ~PmeStdAssemblyConstraints(void);
	
	void Add( PmeStdAssemblyConstraint * item );
	PmeStdAssemblyConstraint * FindByName(const CString & name) const;
};