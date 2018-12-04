#include "stdafx.h"
#include ".\PmeSolidAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeSolid.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"


void PmeSolidAPI::GetSolid(PmeHExplicitModelObject hObject, BODY *& pBody)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hObject);
	PmeExplicitModelObject * pObject = PME_HANDLE2EXPLICITMODELOBJECT(hObject);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeSolid)));

	PmeSolid * pSolid = static_cast<PmeSolid *>(pObject);
	pBody = pSolid->GetSolid();
}

void PmeSolidAPI::GetFaces(PmeHSolid hSolid, PmeHFaces & hFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hSolid);
	PmeSolid * pSolid = PME_HANDLE2SOLID(hSolid);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pSolid->IsInstanceOf(PME_RUNTIME_TYPE(PmeSolid)));

	PmeFaces * pFaces = pSolid->GetFaces();
	hFaces = PME_FACES2HANDLE(pFaces);
}

void PmeSolidAPI::GetEdges(PmeHSolid hSolid, PmeHEdges & hEdges)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hSolid);
	PmeSolid * pSolid = PME_HANDLE2SOLID(hSolid);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pSolid->IsInstanceOf(PME_RUNTIME_TYPE(PmeSolid)));

	PmeEdges * pEdges = pSolid->GetEdges();
	hEdges = PME_EDGES2HANDLE(pEdges);
}

void PmeSolidAPI::GetVertices(PmeHSolid hSolid, PmeHVertices & hVertices)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hSolid);
	PmeSolid * pSolid = PME_HANDLE2SOLID(hSolid);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pSolid->IsInstanceOf(PME_RUNTIME_TYPE(PmeSolid)));

	PmeVertices * pVertices = pSolid->GetVertices();
	hVertices = PME_VERTICES2HANDLE(pVertices);
}