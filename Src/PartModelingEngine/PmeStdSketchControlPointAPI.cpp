#include "stdafx.h"
#include ".\PmeStdSketchControlPointAPI.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchControlPointAPI::GetPosition(PmeHStdSketchGeometry hControlPoint, double & x, double & y)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hControlPoint);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hControlPoint);	
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchControlPoint)));
	PmeStdSketchControlPoint * pControlPoint = static_cast<PmeStdSketchControlPoint *>(pGeometry);

	x = pControlPoint->GetX();
	y = pControlPoint->GetY();
}