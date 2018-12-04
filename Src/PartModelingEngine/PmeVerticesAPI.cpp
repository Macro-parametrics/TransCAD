#include "stdafx.h"
#include ".\PmeVerticesAPI.h"
#include ".\PmeVertices.h"
#include ".\PmeVertex.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"


void PmeVerticesAPI::GetSize(PmeHVertices & hVertices, int & size)
{
	PmeVertices * pVertices = PME_HANDLE2VERTICES(hVertices);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pVertices);
	
	size = pVertices->GetSize();
}

void PmeVerticesAPI::GetItem(PmeHVertices hVertices, int index, PmeHVertex & hVertex)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVertices);
	hVertex = 0;
	PmeVertices * pVertices = PME_HANDLE2VERTICES(hVertices);	
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pVertices->GetSize() <= index || index < 0);

    PmeVertex * pVertex = pVertices->GetItem(index);
	hVertex = PME_VERTEX2HANDLE(pVertex);
}

void PmeVerticesAPI::FindByItem(PmeHVertices hVertices, PmeHVertex hVertex, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVertices);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVertex);
	PmeVertices * pVertices = PME_HANDLE2VERTICES(hVertices);
	PmeVertex * pVertex = PME_HANDLE2VERTEX(hVertex);	
	
	index = pVertices->Find(pVertex);
}