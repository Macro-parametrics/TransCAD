#include "stdafx.h"
#include ".\PmeEdgeAPI.h"
#include ".\PmeEdge.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeEdgeAPI::GetName(PmeHEdge hEdge, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdge);
	PmeEdge * pEdge = PME_HANDLE2EDGE(hEdge);	

	name = pEdge->GetName();
}

void PmeEdgeAPI::GetType(PmeHEdge hEdge, PmeEdgeType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdge);
	PmeEdge * pEdge = PME_HANDLE2EDGE(hEdge);

	type = pEdge->GetEdgeType();
}

void PmeEdgeAPI::GetStartPoint(PmeHEdge hEdge, PmeHVertex & startPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdge);
	PmeEdge * pEdge = PME_HANDLE2EDGE(hEdge);

	startPoint = pEdge->GetStartPoint();
}

void PmeEdgeAPI::GetEndPoint(PmeHEdge hEdge, PmeHVertex & endPoint)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hEdge);
	PmeEdge * pEdge = PME_HANDLE2EDGE(hEdge);

	endPoint = pEdge->GetEndPoint();
}