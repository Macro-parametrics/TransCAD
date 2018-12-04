#include "stdafx.h"
#include ".\PmeExplicitModelAPI.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"

void PmeExplicitModelAPI::GetSolid(PmeHExplicitModel hExplicitModel, PmeHExplicitModelObject & hObject)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModel);
	PmeExplicitModel * pExplicitModel = PME_HANDLE2EXPLICITMODEL(hExplicitModel);

	PmeSolid * pSolid = pExplicitModel->GetSolid();
	hObject = PME_EXPLICITMODELOBJECT2HANDLE(pSolid);
}

void PmeExplicitModelAPI::GetSolid2(PmeHExplicitModel hExplicitModel, PmeHSolid & hSolid)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModel);
	PmeExplicitModel * pExplicitModel = PME_HANDLE2EXPLICITMODEL(hExplicitModel);

	PmeSolid * pSolid = pExplicitModel->GetSolid();
	hSolid = PME_SOLID2HANDLE(pSolid);
}

void PmeExplicitModelAPI::GetItem( PmeHExplicitModel hExplicitModel, PmeHExplicitModelObject & hObject, int index )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModel);
	PmeExplicitModel * pExplicitModel = PME_HANDLE2EXPLICITMODEL(hExplicitModel);

	PmeExplicitModelObject * pObject = pExplicitModel->GetItem(index);
	hObject = PME_EXPLICITMODELOBJECT2HANDLE(pObject);
}

void PmeExplicitModelAPI::GetSize( PmeHExplicitModel hExplicitModel, int & size )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModel);
	PmeExplicitModel * pExplicitModel = PME_HANDLE2EXPLICITMODEL(hExplicitModel);
	
	size = pExplicitModel->GetSize();
}

void PmeExplicitModelAPI::DeleteItem(PmeHExplicitModel hExplicitModel, int index)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModel);
	PmeExplicitModel * pExplicitModel = PME_HANDLE2EXPLICITMODEL(hExplicitModel);
	
	for (int i = 0; i < (int)pExplicitModel->GetSize(); ++i)
	{
			pExplicitModel->Delete(i);
	}
}

void PmeExplicitModelAPI::DeleteItemByName(PmeHExplicitModel hExplicitModel, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hExplicitModel);
	PmeExplicitModel * pExplicitModel = PME_HANDLE2EXPLICITMODEL(hExplicitModel);
	
	for (int i = 0; i < (int)pExplicitModel->GetSize(); ++i)
	{
		if (pExplicitModel->GetItem(i)->GetName() == name)
			pExplicitModel->Delete(i);
	}
}