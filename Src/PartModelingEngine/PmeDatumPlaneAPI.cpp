#include "stdafx.h"
#include ".\PmeDatumPlaneAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeDatumPlane.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"

void PmeDatumPlaneAPI::GetLocation(PmeHExplicitModelObject hObject, MrAxis2 & location)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hObject);
	PmeExplicitModelObject * pObject = PME_HANDLE2EXPLICITMODELOBJECT(hObject);	
	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pObject->IsInstanceOf(PME_RUNTIME_TYPE(PmeDatumPlane)));

	PmeDatumPlane * pDatumPlane = static_cast<PmeDatumPlane *>(pObject);

	location = pDatumPlane->GetLocation();
}