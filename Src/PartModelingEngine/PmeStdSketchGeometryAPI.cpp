#include "stdafx.h"
#include ".\PmeStdSketchGeometryAPI.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeStdSketchGeometryAPI::SetName(PmeHStdSketchGeometry hGeometry, const CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hGeometry);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hGeometry);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchGeometry)));

	pGeometry->SetName(name);
}

void PmeStdSketchGeometryAPI::GetName(PmeHStdSketchGeometry hGeometry, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hGeometry);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hGeometry);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchGeometry)));

	name = pGeometry->GetName();
}

void PmeStdSketchGeometryAPI::GetType(PmeHStdSketchGeometry hGeometry, PmeStdSketchGeometryType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hGeometry);
	PmeStdSketchGeometry * pGeometry = PME_HANDLE2STDSKETCHGEOMETRY(hGeometry);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pGeometry->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSketchGeometry)));

	type = pGeometry->GetType();
}