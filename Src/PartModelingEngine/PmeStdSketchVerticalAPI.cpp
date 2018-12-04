#include "stdafx.h"
#include ".\PmeStdSketchVerticalAPI.h"
#include ".\PmeStdSketchVertical.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchVerticalAPI::GetTarget(PmeHStdSketchConstraint hVertical, PmeHReference & hTarget)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVertical);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hVertical);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchVertical)));
	PmeStdSketchVertical * pVertical = static_cast<PmeStdSketchVertical *>(pConstraint);

	PmeReference * pTarget = pVertical->GetTarget();
	hTarget = PME_REFERENCE2HANDLE(pTarget);
}
