#include "stdafx.h"
#include ".\PmeStdAssemblyConstraintAPI.h"
#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdAssemblyConstraintAPI::GetName(PmeHStdAssemblyConstraint hStdAssemblyConstraint, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hStdAssemblyConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT(hStdAssemblyConstraint);	
	//PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdAssemblyConstraint)));

	name = pConstraint->GetName();
}

void PmeStdAssemblyConstraintAPI::GetType(PmeHStdAssemblyConstraint hStdAssemblyConstraint, PmeStdAssemblyConstraintType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hStdAssemblyConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT(hStdAssemblyConstraint);	
	//PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdAssemblyConstraint)));

	type = pConstraint->GetType();
}

// 17-06-20 Ãß°¡
void PmeStdAssemblyConstraintAPI::SetName( PmeHStdAssemblyConstraint hStdAssemblyConstraint, CString name )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hStdAssemblyConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT(hStdAssemblyConstraint);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdAssemblyConstraint)));

	pConstraint->SetName( name );
}