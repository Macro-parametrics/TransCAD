#include "stdafx.h"
#include ".\PmeStdSketchParallelAPI.h"
#include ".\PmeStdSketchParallel.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchParallelAPI::GetReferenceEdit(PmeHStdSketchConstraint hParallel, PmeHReference & hReferenceEdit)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hParallel);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hParallel);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchParallel)));
	PmeStdSketchParallel * pParallel = static_cast<PmeStdSketchParallel *>(pConstraint);

	PmeReference * pReferenceEdit = pParallel->GetReferenceEdit();
    hReferenceEdit = PME_REFERENCE2HANDLE(pReferenceEdit);
}

void PmeStdSketchParallelAPI::GetTarget(PmeHStdSketchConstraint hParallel, PmeHReference & hTarget)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hParallel);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hParallel);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchParallel)));
	PmeStdSketchParallel * pParallel = static_cast<PmeStdSketchParallel *>(pConstraint);

	PmeReference * pTarget = pParallel->GetTarget();
	hTarget = PME_REFERENCE2HANDLE(pTarget);
}
