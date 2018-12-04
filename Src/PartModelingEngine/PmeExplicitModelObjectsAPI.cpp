#include "stdafx.h"
#include ".\PmeExplicitModelObjectsAPI.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeBaseList.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"

typedef PmeBaseList<PmeHExplicitModelObject> PmeHExplicitModelObjectList;

void PmeExplicitModelObjectsAPI::Create(PmeHExplicitModelObjects & hExplicitModelObjects)
{
	PmeHExplicitModelObjectList * pExplicitModelObjects = new PmeHExplicitModelObjectList();
	hExplicitModelObjects = PME_EXPLICITMODELOBJECTS2HANDLE(pExplicitModelObjects);
}

void PmeExplicitModelObjectsAPI::Delete(PmeHExplicitModelObjects & hExplicitModelObjects)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModelObjects);
	PmeHExplicitModelObjectList * pExplicitModelObjects = PME_HANDLE2EXPLICITMODELOBJECTS(hExplicitModelObjects);
	delete pExplicitModelObjects;
	hExplicitModelObjects = 0;
}

void PmeExplicitModelObjectsAPI::AddItem(PmeHExplicitModelObjects hExplicitModelObjects, PmeHExplicitModelObject hExplicitModelObject)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModelObjects);
	PmeHExplicitModelObjectList * pExplicitModelObjects = PME_HANDLE2EXPLICITMODELOBJECTS(hExplicitModelObjects);
	pExplicitModelObjects->Add(hExplicitModelObject);
}

void PmeExplicitModelObjectsAPI::GetSize(PmeHExplicitModelObjects hExplicitModelObjects, int & size)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModelObjects);
	PmeHExplicitModelObjectList * pExplicitModelObjects = PME_HANDLE2EXPLICITMODELOBJECTS(hExplicitModelObjects);
	size = pExplicitModelObjects->GetSize();
}

void PmeExplicitModelObjectsAPI::GetItem(PmeHExplicitModelObjects hExplicitModelObjects, int index, PmeHExplicitModelObject & hExplicitModelObject)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModelObjects);

	hExplicitModelObject = 0;
	PmeHExplicitModelObjectList * pExplicitModelObjects = PME_HANDLE2EXPLICITMODELOBJECTS(hExplicitModelObjects);
	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(pExplicitModelObjects->GetSize() <= index || index < 0);
	
    hExplicitModelObject = pExplicitModelObjects->GetItem(index);
}

void PmeExplicitModelObjectsAPI::FindByItem(PmeHExplicitModelObjects hExplicitModelObjects, PmeHExplicitModelObject hExplicitModelObject, int & index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModelObjects);
	PmeHExplicitModelObjectList * pExplicitModelObjects = PME_HANDLE2EXPLICITMODELOBJECTS(hExplicitModelObjects);
	index = pExplicitModelObjects->Find(PME_HANDLE2EXPLICITMODELOBJECT(hExplicitModelObject));
}

void PmeExplicitModelObjectsAPI::DeleteItemByName(PmeHExplicitModelObjects hExplicitModelObjects, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModelObjects);
	PmeHExplicitModelObjectList * pExplicitModelObjects = PME_HANDLE2EXPLICITMODELOBJECTS(hExplicitModelObjects);
	
	for (int i = 1; i < (int)pExplicitModelObjects->GetSize(); ++i)
	{
		PmeExplicitModelObject * pExplicitModelObject = PME_HANDLE2EXPLICITMODELOBJECT(pExplicitModelObjects->GetItem(i));
		if (pExplicitModelObject->GetName() == name)
			pExplicitModelObjects->Delete(i);
	}
}