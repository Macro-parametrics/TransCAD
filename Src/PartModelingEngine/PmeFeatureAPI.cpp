#include "stdafx.h"
#include ".\PmeFeatureAPI.h"
#include ".\PmeFeature.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"

void PmeFeatureAPI::GetName(PmeHFeature hFeature, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeFeature)));

	name = pFeature->GetName();
}

void PmeFeatureAPI::GetPart(PmeHFeature hFeature, PmeHPart & hPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeFeature)));

	PmePart * pPart = pFeature->GetPart();
	hPart = PME_PART2HANDLE(pPart);
}

void PmeFeatureAPI::GetType(PmeHFeature hFeature, PmeFeatureType & type)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeFeature)));

	type = pFeature->GetFeatureType();
}

void PmeFeatureAPI::SetName(PmeHFeature hFeature, CString name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeFeature)));

	pFeature->SetName(name);
}
