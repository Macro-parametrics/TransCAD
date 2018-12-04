#include "stdafx.h"
#include ".\PmeFaceAPI.h"
#include ".\PmeFace.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeFaceAPI::GetName(PmeHFace hFace, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);	

	name = pFace->GetName();
}

void PmeFaceAPI::GetType(PmeHFace hFace, PmeFaceType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);

	type = pFace->GetFaceType();
}

void PmeFaceAPI::GetEdges(PmeHFace hFace, PmeHEdges & hEdges)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	PmeEdges * pEdges= pFace->GetEdges();
	hEdges = PME_EDGES2HANDLE(pEdges);
}

void PmeFaceAPI::GetVertices(PmeHFace hFace, PmeHVertices & hVertices)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	PmeVertices * pVertices= pFace->GetVertices();
	hVertices = PME_VERTICES2HANDLE(pVertices);
}

void PmeFaceAPI::GetCentroid(PmeHFace hFace, MrPosition & centroid)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	centroid = pFace->GetCentroid();
}

void PmeFaceAPI::GetXDirection(PmeHFace hFace, MrDirection & xDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	xDirection = pFace->GetXDirection();
}

void PmeFaceAPI::GetYDirection(PmeHFace hFace, MrDirection & yDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	yDirection = pFace->GetYDirection();
}

void PmeFaceAPI::GetZDirection(PmeHFace hFace, MrDirection & zDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	zDirection = pFace->GetZDirection();
}

void PmeFaceAPI::GetArea(PmeHFace hFace, double & area)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFace->IsInstanceOf(PME_RUNTIME_TYPE(PmeFace)));

	area = pFace->GetArea();
}