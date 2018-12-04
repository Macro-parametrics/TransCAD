#include "stdafx.h"
#include ".\PmeStdSketchCircularArcAPI.h"
#include ".\PmeStdSketchCircularArc.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchCircularArcAPI::GetCenterPoint(PmeHStdSketchGeometry hArc, PmeHStdSketchGeometry & hCenterPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hArc);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hArc);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircularArc)));
	PmeStdSketchCircularArc * pArc = static_cast<PmeStdSketchCircularArc *>(pGeometry);

	PmeStdSketchControlPoint * pCenterPoint = pArc->GetCenterPoint();
    hCenterPoint = PME_STDSKETCHGEOMETRY2HANDLE(pCenterPoint);
}

void PmeStdSketchCircularArcAPI::GetStartPoint(PmeHStdSketchGeometry hArc, PmeHStdSketchGeometry & hStartPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hArc);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hArc);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircularArc)));
	PmeStdSketchCircularArc * pArc = static_cast<PmeStdSketchCircularArc *>(pGeometry);

	PmeStdSketchControlPoint * pStartPoint = pArc->GetStartPoint();
    hStartPoint = PME_STDSKETCHGEOMETRY2HANDLE(pStartPoint);
}

void PmeStdSketchCircularArcAPI::GetEndPoint(PmeHStdSketchGeometry hArc, PmeHStdSketchGeometry & hEndPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hArc);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hArc);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircularArc)));
	PmeStdSketchCircularArc * pArc = static_cast<PmeStdSketchCircularArc *>(pGeometry);

	PmeStdSketchControlPoint * pEndPoint = pArc->GetEndPoint();
    hEndPoint = PME_STDSKETCHGEOMETRY2HANDLE(pEndPoint);
}

void PmeStdSketchCircularArcAPI::GetRadius(PmeHStdSketchGeometry hArc, double & radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hArc);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hArc);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircularArc)));
	PmeStdSketchCircularArc * pArc = static_cast<PmeStdSketchCircularArc *>(pGeometry);

	radius = pArc->GetRadius();
}

void PmeStdSketchCircularArcAPI::GetStartAngle(PmeHStdSketchGeometry hArc, double & startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hArc);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hArc);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircularArc)));
	PmeStdSketchCircularArc * pArc = static_cast<PmeStdSketchCircularArc *>(pGeometry);

	startAngle = pArc->GetStartAngle();
}

void PmeStdSketchCircularArcAPI::GetEndAngle(PmeHStdSketchGeometry hArc, double & endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hArc);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hArc);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchCircularArc)));
	PmeStdSketchCircularArc * pArc = static_cast<PmeStdSketchCircularArc *>(pGeometry);

	endAngle = pArc->GetEndAngle();
}