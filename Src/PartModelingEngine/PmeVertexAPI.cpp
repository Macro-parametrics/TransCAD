#include "stdafx.h"
#include ".\PmeVertexAPI.h"
#include ".\PmeVertex.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeVertexAPI::GetName(PmeHVertex hVertex, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVertex);
	PmeVertex * pVertex = PME_HANDLE2VERTEX(hVertex);	

	name = pVertex->GetName();
}

void PmeVertexAPI::GetCoordinates(PmeHVertex hVertex, MrPosition & coordinates)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hVertex);
	PmeVertex * pVertex = PME_HANDLE2VERTEX(hVertex);

	coordinates = pVertex->GetCoordinates();
}