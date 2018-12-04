#include "stdafx.h"
#include ".\PmeExplicitModelObjectAPI.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"

void PmeExplicitModelObjectAPI::GetName(PmeHExplicitModelObject hObject, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hObject);
	PmeExplicitModelObject * pObject = PME_HANDLE2EXPLICITMODELOBJECT(hObject);

	name = pObject->GetName();
}

void PmeExplicitModelObjectAPI::GetType(PmeHExplicitModelObject hObject, PmeExplicitModelObjectType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hObject);
	PmeExplicitModelObject * pObject = PME_HANDLE2EXPLICITMODELOBJECT(hObject);
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeExplicitModelObject)));

	type = pObject->GetType();	
}

void PmeExplicitModelObjectAPI::GetCreator(PmeHExplicitModelObject hObject, PmeHFeature & hFeature)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hObject);
	PmeExplicitModelObject * pObject = PME_HANDLE2EXPLICITMODELOBJECT(hObject);

	PmeFeature * pFeature = pObject->GetCreator();
	if(pFeature)
        hFeature = PME_FEATURE2HANDLE(pFeature);
	else
		hFeature = 0;
}