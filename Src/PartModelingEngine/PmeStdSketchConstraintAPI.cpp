#include "stdafx.h"
#include ".\PmeStdSketchConstraintAPI.h"
#include ".\PmeStdSketchConstraint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchConstraintAPI::SetName(PmeHStdSketchConstraint hConstraint, const CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraint);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hConstraint);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchConstraint)));

	pConstraint->SetName(name);
}

void PmeStdSketchConstraintAPI::GetName(PmeHStdSketchConstraint hConstraint, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraint);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hConstraint);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchConstraint)));

	name = pConstraint->GetName();
}

void PmeStdSketchConstraintAPI::GetType(PmeHStdSketchConstraint hConstraint, PmeStdSketchConstraintType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hConstraint);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hConstraint);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchConstraint)));

	type = pConstraint->GetType();
}