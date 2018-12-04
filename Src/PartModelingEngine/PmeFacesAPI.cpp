#include "stdafx.h"
#include ".\PmeFacesAPI.h"
#include ".\PmeFaces.h"
#include ".\PmeFace.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"


void PmeFacesAPI::GetSize(PmeHFaces & hFaces, int & size)
{
	PmeFaces * pFaces = PME_HANDLE2FACES(hFaces);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pFaces);
	
	size = pFaces->GetSize();
}

void PmeFacesAPI::GetItem(PmeHFaces hFaces, int index, PmeHFace & hFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFaces);
	hFace = 0;
	PmeFaces * pFaces = PME_HANDLE2FACES(hFaces);	
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pFaces->GetSize() <= index || index < 0);

    PmeFace * pFace = pFaces->GetItem(index);
	hFace = PME_FACE2HANDLE(pFace);
}

void PmeFacesAPI::FindByItem(PmeHFaces hFaces, PmeHFace hFace, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFaces);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace);
	PmeFaces * pFaces = PME_HANDLE2FACES(hFaces);
	PmeFace * pFace = PME_HANDLE2FACE(hFace);	
	
	index = pFaces->Find(pFace);
}