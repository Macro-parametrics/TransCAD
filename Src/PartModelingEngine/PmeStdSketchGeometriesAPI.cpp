#include "stdafx.h"
#include ".\PmeStdSketchGeometriesAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"
#include ".\PmeStdSketchGeometries.h"

void PmeStdSketchGeometriesAPI::GetSize(PmeHStdSketchGeometries & hGeometries, int & size)
{
	PmeStdSketchGeometries * pGeometries = PME_HANDLE2STDSKETCHGEOMETRIES(hGeometries);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pGeometries);
	size = pGeometries->GetSize();
}

void PmeStdSketchGeometriesAPI::GetItem(PmeHStdSketchGeometries & hGeometries, int index, PmeHStdSketchGeometry & hGeometry)
{
	PmeStdSketchGeometries * pGeometries = PME_HANDLE2STDSKETCHGEOMETRIES(hGeometries);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pGeometries);

	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pGeometries->GetSize() <= index || index < 0);
    hGeometry = pGeometries->GetItem(index);
}

void PmeStdSketchGeometriesAPI::FindByItem(PmeHStdSketchGeometries & hGeometries, PmeHStdSketchGeometry hGeometry, int & index)
{
	PmeStdSketchGeometries * pGeometries = PME_HANDLE2STDSKETCHGEOMETRIES(hGeometries);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pGeometries);
	index = pGeometries->Find(PME_HANDLE2STDSKETCHGEOMETRY(hGeometry));
}