#include "stdafx.h"
#include ".\PmeStdSketchLineAPI.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchLineAPI::GetStartPoint(PmeHStdSketchGeometry hLine, PmeHStdSketchGeometry & hStartPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hLine);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hLine);	
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchLine)));
	PmeStdSketchLine * pLine = static_cast<PmeStdSketchLine *>(pGeometry);

	PmeStdSketchControlPoint * pStartPoint = pLine->GetStartPoint();
    hStartPoint = PME_STDSKETCHGEOMETRY2HANDLE(pStartPoint);
}

void PmeStdSketchLineAPI::GetEndPoint(PmeHStdSketchGeometry hLine, PmeHStdSketchGeometry & hEndPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hLine);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hLine);	
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchLine)));
	PmeStdSketchLine * pLine = static_cast<PmeStdSketchLine *>(pGeometry);

	PmeStdSketchControlPoint * pEndPoint = pLine->GetEndPoint();
    hEndPoint = PME_STDSKETCHGEOMETRY2HANDLE(pEndPoint);
}