#include "stdafx.h"
#include ".\PmeStdSolidShellFeatureAPI.h"
#include ".\PmeReferences.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidShellFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"


void PmeStdSolidShellFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReferences hTargetFaces,
	double innerThickness,
	double outerThickness,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFaces);
	PmeReferences * pTargetFaces = PME_HANDLE2REFERENCES(hTargetFaces);

	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidShellFeature * pFeature = new PmeStdSolidShellFeature(pPart, pTargetFaces, innerThickness, outerThickness);
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

void PmeStdSolidShellFeatureAPI::GetTargetFaces(PmeHFeature hFeature, PmeHReferences & hTargetFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidShellFeature)));
	PmeStdSolidShellFeature * pStdSolidShellFeature = static_cast<PmeStdSolidShellFeature *>(pFeature);

	PmeReferences * pTargetFaces = pStdSolidShellFeature->GetTargetFaces();
	hTargetFaces = PME_REFERENCES2HANDLE(pTargetFaces);
}

void PmeStdSolidShellFeatureAPI::GetInnerThickness(PmeHFeature hFeature, double & innerThickness)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidShellFeature)));
	PmeStdSolidShellFeature * pStdSolidShellFeature = static_cast<PmeStdSolidShellFeature *>(pFeature);

	innerThickness = pStdSolidShellFeature->GetInnerThickness();
}

void PmeStdSolidShellFeatureAPI::GetOuterThickness(PmeHFeature hFeature, double & outerThickness)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidShellFeature)));
	PmeStdSolidShellFeature * pStdSolidShellFeature = static_cast<PmeStdSolidShellFeature *>(pFeature);

	outerThickness = pStdSolidShellFeature->GetOuterThickness();
}


void PmeStdSolidShellFeatureAPI::SetTargetFaces(PmeHFeature hFeature, PmeHReferences hTargetFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidShellFeature)));
	PmeStdSolidShellFeature * pStdSolidShellFeature = static_cast<PmeStdSolidShellFeature *>(pFeature);

	PmeReferences * pTargetFaces = PME_HANDLE2REFERENCES(hTargetFaces);
	pStdSolidShellFeature->SetTargetFaces(pTargetFaces);
}

void PmeStdSolidShellFeatureAPI::SetInnerThickness(PmeHFeature hFeature, double innerThickness)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidShellFeature)));
	PmeStdSolidShellFeature * pStdSolidShellFeature = static_cast<PmeStdSolidShellFeature *>(pFeature);

	pStdSolidShellFeature->SetInnerThickness(innerThickness);
}

void PmeStdSolidShellFeatureAPI::SetOuterThickness(PmeHFeature hFeature, double outerThickness)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidShellFeature)));
	PmeStdSolidShellFeature * pStdSolidShellFeature = static_cast<PmeStdSolidShellFeature *>(pFeature);

	pStdSolidShellFeature->SetOuterThickness(outerThickness);
}