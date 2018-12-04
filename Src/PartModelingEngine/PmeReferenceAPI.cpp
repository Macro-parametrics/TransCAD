#include "stdafx.h"
#include ".\PmeReferenceAPI.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeReferenceAPI::GetName(PmeHReference hReference, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);	

	name = pReference->GetName();
}

void PmeReferenceAPI::GetPart(PmeHReference hReference, PmeHPart & hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);	

	PmePart * pPart = pReference->GetPart();
	hPart = PME_PART2HANDLE(pPart);
}

void PmeReferenceAPI::GetType(PmeHReference hReference, PmeReferenceType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);	

	type = pReference->GetReferenceType();
}

void PmeReferenceAPI::GetReferenceeName(PmeHReference hReference, CString & referenceeName)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);	

	referenceeName = pReference->GetReferenceeName();
}