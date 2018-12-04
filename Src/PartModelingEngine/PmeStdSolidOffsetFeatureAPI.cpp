#include "stdafx.h"
#include ".\PmeStdSolidOffsetFeatureAPI.h"
#include ".\PmeReferences.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidOffsetFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"


void PmeStdSolidOffsetFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReferences hTargetFaces,
	double thickness,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFaces);
	PmeReferences * pTargetFaces = PME_HANDLE2REFERENCES(hTargetFaces);

	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidOffsetFeature * pFeature = new PmeStdSolidOffsetFeature(pPart, pTargetFaces, thickness);
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

void PmeStdSolidOffsetFeatureAPI::GetTargetFaces(PmeHFeature hFeature, PmeHReferences & hTargetFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOffsetFeature)));
	PmeStdSolidOffsetFeature * pStdSolidOffsetFeature = static_cast<PmeStdSolidOffsetFeature *>(pFeature);

	PmeReferences * pTargetFaces = pStdSolidOffsetFeature->GetTargetFaces();
	hTargetFaces = PME_REFERENCES2HANDLE(pTargetFaces);
}

void PmeStdSolidOffsetFeatureAPI::GetThickness(PmeHFeature hFeature, double & thickness)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOffsetFeature)));
	PmeStdSolidOffsetFeature * pStdSolidOffsetFeature = static_cast<PmeStdSolidOffsetFeature *>(pFeature);

	thickness = pStdSolidOffsetFeature->GetThickness();
}


void PmeStdSolidOffsetFeatureAPI::SetTargetFaces(PmeHFeature hFeature, PmeHReferences hTargetFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOffsetFeature)));
	PmeStdSolidOffsetFeature * pStdSolidOffsetFeature = static_cast<PmeStdSolidOffsetFeature *>(pFeature);

	PmeReferences * pTargetFaces = PME_HANDLE2REFERENCES(hTargetFaces);
	pStdSolidOffsetFeature->SetTargetFaces(pTargetFaces);
}

void PmeStdSolidOffsetFeatureAPI::SetThickness(PmeHFeature hFeature, double thickness)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOffsetFeature)));
	PmeStdSolidOffsetFeature * pStdSolidOffsetFeature = static_cast<PmeStdSolidOffsetFeature *>(pFeature);

	pStdSolidOffsetFeature->SetThickness(thickness);
}
