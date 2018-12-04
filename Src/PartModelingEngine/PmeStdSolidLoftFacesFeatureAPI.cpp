#include "StdAfx.h"
#include "PmeStdSolidLoftFacesFeatureAPI.h"
#include "PmeStdSolidLoftFacesFeature.h"

#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidLoftFacesFeatureAPI::Create
	(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hFace1,
	double param1,
	PmeHReference hFace2,
	double param2,
	PmeHFeature & hFeature
	)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace1);
	PmeReference * pFace1 = PME_HANDLE2REFERENCE(hFace1);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hFace2);
	PmeReference * pFace2 = PME_HANDLE2REFERENCE(hFace2);

	PmeStdSolidLoftFacesFeature * pFeature = new PmeStdSolidLoftFacesFeature(pPart, pFace1, param1, pFace2,param2);

	if(name.IsEmpty())
		pFeature->GiveDefaultName();
	else
		pFeature->SetName(name);

	pFeatures->Add(pFeature);
	pPart->UpdateLast();

	hFeature = PME_FEATURE2HANDLE(pFeature);
	if(hFeature)
	{
		PME_UPDATE_FEATURE(hPart, hFeature, PmeUpdateState_Add);
	}

	PmeHExplicitModelObject hSolid = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetSolid());
	if(hSolid)
	{
		PME_UPDATE_EXPLICITMODELOBJECT(hPart, hSolid, PmeUpdateState_Update);
	}
}

void PmeStdSolidLoftFacesFeatureAPI::GetFace1(PmeHFeature hFeature, PmeHReference & hFace1)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidLoftFacesFeature)));
	PmeStdSolidLoftFacesFeature * pStdSolidLoftFacesFeature = static_cast<PmeStdSolidLoftFacesFeature *>(pFeature);

	PmeReference * pReference = pStdSolidLoftFacesFeature->GetFace1();
	hFace1 = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidLoftFacesFeatureAPI::GetParam1(PmeHFeature hFeature, double & param1)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidLoftFacesFeature)));
	PmeStdSolidLoftFacesFeature * pStdSolidLoftFacesFeature = static_cast<PmeStdSolidLoftFacesFeature *>(pFeature);

	param1 = pStdSolidLoftFacesFeature->GetParam1();
}

void PmeStdSolidLoftFacesFeatureAPI::GetFace2(PmeHFeature hFeature, PmeHReference & hFace2)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidLoftFacesFeature)));
	PmeStdSolidLoftFacesFeature * pStdSolidLoftFacesFeature = static_cast<PmeStdSolidLoftFacesFeature *>(pFeature);

	PmeReference * pReference = pStdSolidLoftFacesFeature->GetFace2();
	hFace2 = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidLoftFacesFeatureAPI::GetParam2(PmeHFeature hFeature, double & param2)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidLoftFacesFeature)));
	PmeStdSolidLoftFacesFeature * pStdSolidLoftFacesFeature = static_cast<PmeStdSolidLoftFacesFeature *>(pFeature);

	param2 = pStdSolidLoftFacesFeature->GetParam2();
}