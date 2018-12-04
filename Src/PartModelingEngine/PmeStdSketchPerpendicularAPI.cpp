#include "stdafx.h"
#include ".\PmeStdSketchPerpendicularAPI.h"
#include ".\PmeStdSketchPerpendicular.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchPerpendicularAPI::GetReferenceEdit(PmeHStdSketchConstraint hPerpendicular, PmeHReference & hReferenceEdit)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPerpendicular);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hPerpendicular);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchPerpendicular)));
	PmeStdSketchPerpendicular * pPerpendicular = static_cast<PmeStdSketchPerpendicular *>(pConstraint);

	PmeReference * pReferenceEdit = pPerpendicular->GetReferenceEdit();
    hReferenceEdit = PME_REFERENCE2HANDLE(pReferenceEdit);
}

void PmeStdSketchPerpendicularAPI::GetTarget(PmeHStdSketchConstraint hPerpendicular, PmeHReference & hTarget)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPerpendicular);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hPerpendicular);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchPerpendicular)));
	PmeStdSketchPerpendicular * pPerpendicular = static_cast<PmeStdSketchPerpendicular *>(pConstraint);

	PmeReference * pTarget = pPerpendicular->GetTarget();
	hTarget = PME_REFERENCE2HANDLE(pTarget);
}
