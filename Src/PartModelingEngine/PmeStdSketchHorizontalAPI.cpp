#include "stdafx.h"
#include ".\PmeStdSketchHorizontalAPI.h"
#include ".\PmeStdSketchHorizontal.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchHorizontalAPI::GetTarget(PmeHStdSketchConstraint hHorizontal, PmeHReference & hTarget)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hHorizontal);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hHorizontal);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchHorizontal)));
	PmeStdSketchHorizontal * pHorizontal = static_cast<PmeStdSketchHorizontal *>(pConstraint);

	PmeReference * pTarget = pHorizontal->GetTarget();
	hTarget = PME_REFERENCE2HANDLE(pTarget);
}
