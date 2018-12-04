#include "stdafx.h"
#include ".\PmeStdSketchCenterlineAPI.h"
#include ".\PmeStdSketchCenterline.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchCenterlineAPI::GetStartPoint(PmeHStdSketchGeometry hCenterline, PmeHStdSketchGeometry & hStartPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCenterline);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hCenterline);	
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCenterline)));
	PmeStdSketchCenterline * pCenterline = static_cast<PmeStdSketchCenterline *>(pGeometry);

	PmeStdSketchControlPoint * pStartPoint = pCenterline->GetStartPoint();
    hStartPoint = PME_STDSKETCHGEOMETRY2HANDLE(pStartPoint);
}

void PmeStdSketchCenterlineAPI::GetEndPoint(PmeHStdSketchGeometry hCenterline, PmeHStdSketchGeometry & hEndPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hCenterline);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hCenterline);	
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCenterline)));
	PmeStdSketchCenterline * pCenterline = static_cast<PmeStdSketchCenterline *>(pGeometry);

	PmeStdSketchControlPoint * pEndPoint = pCenterline->GetEndPoint();
    hEndPoint = PME_STDSKETCHGEOMETRY2HANDLE(pEndPoint);
}