#include "StdAfx.h"
#include ".\PmeSketchGeometryReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeStdSketchFeature.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeSketchGeometryReference, PmeReference)

PmeSketchGeometryReference::PmeSketchGeometryReference(PmePart * pPart, PmeStdSketchGeometry * pGeometry)
: PmeReference(pPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!pGeometry);

	CString persistentName;
	CString sketchName;
	CString geoName;
	
	sketchName = pGeometry->GetSketchFeature()->GetName();
	geoName = pGeometry->GetName(); 

	persistentName.Format("%s,%s,0,0,0,0,SketchSegment", sketchName, geoName);

	SetReferenceeName(persistentName);
}

PmeSketchGeometryReference::~PmeSketchGeometryReference(void)
{
}