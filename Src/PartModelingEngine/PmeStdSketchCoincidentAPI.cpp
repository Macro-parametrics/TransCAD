#include "stdafx.h"
#include ".\PmeStdSketchCoincidentAPI.h"
#include ".\PmeStdSketchCoincident.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchCoincidentAPI::GetFirstGeometry(PmeHStdSketchConstraint hCoincident, PmeHReference & hFirstGeometry)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCoincident);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hCoincident);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCoincident)));
	PmeStdSketchCoincident * pCoincident = static_cast<PmeStdSketchCoincident *>(pConstraint);

	PmeReference * pFirstGeometry = pCoincident->GetFirstGeometry();
    hFirstGeometry = PME_REFERENCE2HANDLE(pFirstGeometry);
}

void PmeStdSketchCoincidentAPI::GetSecondGeometry(PmeHStdSketchConstraint hCoincident, PmeHReference & hSecondGeometry)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCoincident);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hCoincident);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCoincident)));
	PmeStdSketchCoincident * pCoincident = static_cast<PmeStdSketchCoincident *>(pConstraint);

	PmeReference * pSecondGeometry = pCoincident->GetSecondGeometry();
	hSecondGeometry = PME_REFERENCE2HANDLE(pSecondGeometry);
}

void PmeStdSketchCoincidentAPI::GetFirstObjectType(PmeHStdSketchConstraint hCoincident, PmeSamePointsType & firstType)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCoincident);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hCoincident);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCoincident)));
	PmeStdSketchCoincident * pCoincident = static_cast<PmeStdSketchCoincident *>(pConstraint);

	firstType =  pCoincident->GetFirstObjectType();
}

void PmeStdSketchCoincidentAPI::GetSecondObjectType(PmeHStdSketchConstraint hCoincident, PmeSamePointsType & secondType)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCoincident);
	PmeStdSketchConstraint * pConstraint = PME_HANDLE2STDSKETCHCONSTRAINT(hCoincident);

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCoincident)));
	PmeStdSketchCoincident * pCoincident = static_cast<PmeStdSketchCoincident *>(pConstraint);

	secondType =  pCoincident->GetSecondObjectType();
}
