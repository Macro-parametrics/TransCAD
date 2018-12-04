#include "stdafx.h"
#include ".\PmeReferencesAPI.h"
#include ".\PmeReferences.h"
#include ".\PmeReference.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"

void PmeReferencesAPI::Create(PmeHReferences & hReferences)
{
	PmeReferences * pReferences = new PmeReferences();
	hReferences = PME_REFERENCES2HANDLE(pReferences);
}

void PmeReferencesAPI::Delete(PmeHReferences & hReferences)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReferences);

	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hReferences);
	delete pReferences;

	hReferences = 0;
}

void PmeReferencesAPI::AddItem(PmeHReferences hReferences, PmeHReference hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReferences);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hReferences);	
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);
	pReferences->Add(pReference);
}

void PmeReferencesAPI::GetSize(PmeHReferences & hReferences, int & size)
{
	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hReferences);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pReferences);
	size = pReferences->GetSize();
}

void PmeReferencesAPI::GetItem(PmeHReferences hReferences, int index, PmeHReference & hReference)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReferences);
	hReference = 0;
	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hReferences);	
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pReferences->GetSize() <= index || index < 0);

    PmeReference * pReference = pReferences->GetItem(index);
	hReference = PME_REFERENCE2HANDLE(pReference);
}

void PmeReferencesAPI::FindByItem(PmeHReferences hReferences, PmeHReference hReference, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReferences);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hReference);
	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hReferences);
	PmeReference * pReference = PME_HANDLE2REFERENCE(hReference);	
	
	index = pReferences->Find(pReference);
}

void PmeReferencesAPI::Copy(PmeHReferences hSource, PmeHReferences & hNew)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hSource);
	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hSource);

	PmeReferencesAPI::Create(hNew);

	int size;
	PmeReferencesAPI::GetSize(hSource, size);

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hReference;
		PmeReferencesAPI::GetItem(hSource, i, hReference);

		PmeReferencesAPI::AddItem(hNew, hReference);
	}
}