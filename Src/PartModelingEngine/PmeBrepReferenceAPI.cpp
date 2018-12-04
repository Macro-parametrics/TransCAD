#include "stdafx.h"
#include ".\PmeBrepReferenceAPI.h"
#include ".\PmeBrepReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeBrepReferenceAPI::GetBrepType(PmeHReference hReference, PmeBrepType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);

	PmeThrowExceptionIf<PmeArgumentTypeException>(pReference->GetReferenceType() != PmeReferenceType_Brep);
	PmeBrepReference * pBrepReference = static_cast<PmeBrepReference *>(pReference);

	type = pBrepReference->GetBrepType();
}