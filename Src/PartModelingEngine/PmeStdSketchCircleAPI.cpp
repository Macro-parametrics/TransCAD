#include "stdafx.h"
#include ".\PmeStdSketchCircleAPI.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchCircleAPI::GetCenterPoint(PmeHStdSketchGeometry hCircle, PmeHStdSketchGeometry & hCenterPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCircle);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hCircle);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircle)));
	PmeStdSketchCircle * pCircle = static_cast<PmeStdSketchCircle *>(pGeometry);

	PmeStdSketchControlPoint * pCenterPoint = pCircle->GetCenterPoint();
    hCenterPoint = PME_STDSKETCHGEOMETRY2HANDLE(pCenterPoint);
}

void PmeStdSketchCircleAPI::GetRadius(PmeHStdSketchGeometry hCircle, double & radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCircle);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hCircle);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircle)));
	PmeStdSketchCircle * pCircle = static_cast<PmeStdSketchCircle *>(pGeometry);

	radius = pCircle->GetRadius();
}