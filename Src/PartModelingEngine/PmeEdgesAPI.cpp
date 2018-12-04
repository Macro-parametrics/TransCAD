#include "stdafx.h"
#include ".\PmeEdgesAPI.h"
#include ".\PmeEdges.h"
#include ".\PmeEdge.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"


void PmeEdgesAPI::GetSize(PmeHEdges & hEdges, int & size)
{
	PmeEdges * pEdges = PME_HANDLE2EDGES(hEdges);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pEdges);
	
	size = pEdges->GetSize();
}

void PmeEdgesAPI::GetItem(PmeHEdges hEdges, int index, PmeHEdge & hEdge)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdges);
	hEdge = 0;
	PmeEdges * pEdges = PME_HANDLE2EDGES(hEdges);	
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pEdges->GetSize() <= index || index < 0);

    PmeEdge * pEdge = pEdges->GetItem(index);
	hEdge = PME_EDGE2HANDLE(pEdge);
}

void PmeEdgesAPI::FindByItem(PmeHEdges hEdges, PmeHEdge hEdge, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdges);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdge);
	PmeEdges * pEdges = PME_HANDLE2EDGES(hEdges);
	PmeEdge * pEdge = PME_HANDLE2EDGE(hEdge);	
	
	index = pEdges->Find(pEdge);
}