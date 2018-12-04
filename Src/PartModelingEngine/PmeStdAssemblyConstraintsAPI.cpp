#include "stdafx.h"
#include ".\PmeStdAssemblyConstraintsAPI.h"
#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeStdAssemblyConstraints.h"
#include ".\PmeBaseList.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"

void PmeStdAssemblyConstraintsAPI::Delete(PmeHStdAssemblyConstraints & hConstraints)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);

	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);
	delete pConstraints;

	hConstraints = 0;
}

void PmeStdAssemblyConstraintsAPI::GetSize(PmeHStdAssemblyConstraints hConstraints, int & size)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);
	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);
	
	size = pConstraints->GetSize();
}

void PmeStdAssemblyConstraintsAPI::GetItem(PmeHStdAssemblyConstraints hConstraints, int index, PmeHStdAssemblyConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);

	hConstraint = 0;
	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pConstraints->GetSize() <= index || index < 0);

    hConstraint = pConstraints->GetItem(index);
}

void PmeStdAssemblyConstraintsAPI::FindByItem(PmeHStdAssemblyConstraints hConstraints, PmeHStdAssemblyConstraint hConstraint, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);
	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);

	index = pConstraints->Find(PME_HANDLE2STDASSEMBLYCONSTRAINT(hConstraint));
}

void PmeStdAssemblyConstraintsAPI::FindByName(PmeHStdAssemblyConstraints hConstraints, CString name, PmeHStdAssemblyConstraint & hConstraint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);
	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);

	for (int i = 0; i < pConstraints->GetSize(); ++i)
	{
		if (pConstraints->GetItem(i)->GetName() == name)
		{
			hConstraint = pConstraints->GetItem(i);
			return;
		}
	}
}

void PmeStdAssemblyConstraintsAPI::DeleteItem(PmeHStdAssemblyConstraints hConstraints, int index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);
	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);

	pConstraints->Delete(index);
}

void PmeStdAssemblyConstraintsAPI::Add( PmeHStdAssemblyConstraints hConstraints, PmeHStdAssemblyConstraint hConstraint )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraints);
	PmeStdAssemblyConstraints * pConstraints = PME_HANDLE2STDASSEMBLYCONSTRAINTS(hConstraints);

	pConstraints->Add( PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint ) );
}
