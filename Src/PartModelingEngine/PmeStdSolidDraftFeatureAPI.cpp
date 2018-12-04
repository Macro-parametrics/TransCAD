#include "stdafx.h"
#include ".\PmeStdSolidDraftFeatureAPI.h"
#include ".\PmeReferences.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidDraftFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"


void PmeStdSolidDraftFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReferences hTargetFaces,
	const MrAxis1 & pullingDirection,
	double draftAngle,
	PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFaces);
	PmeReferences * pTargetFaces = PME_HANDLE2REFERENCES(hTargetFaces);

	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidDraftFeature * pFeature = new PmeStdSolidDraftFeature(pPart, pTargetFaces, pullingDirection, draftAngle);
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

void PmeStdSolidDraftFeatureAPI::GetTargetFaces(PmeHFeature hFeature, PmeHReferences & hTargetFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidDraftFeature)));
	PmeStdSolidDraftFeature * pStdSolidDraftFeature = static_cast<PmeStdSolidDraftFeature *>(pFeature);

	PmeReferences * pTargetFaces = pStdSolidDraftFeature->GetTargetFaces();
	hTargetFaces = PME_REFERENCES2HANDLE(pTargetFaces);
}

void PmeStdSolidDraftFeatureAPI::GetPullingDirection(PmeHFeature hFeature, MrAxis1 & pullingDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidDraftFeature)));
	PmeStdSolidDraftFeature * pStdSolidDraftFeature = static_cast<PmeStdSolidDraftFeature *>(pFeature);

	pullingDirection = pStdSolidDraftFeature->GetPullingDirection();
}

void PmeStdSolidDraftFeatureAPI::GetDraftAngle(PmeHFeature hFeature, double & draftAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidDraftFeature)));
	PmeStdSolidDraftFeature * pStdSolidDraftFeature = static_cast<PmeStdSolidDraftFeature *>(pFeature);

	draftAngle = pStdSolidDraftFeature->GetDraftAngle();
}


void PmeStdSolidDraftFeatureAPI::SetTargetFaces(PmeHFeature hFeature, PmeHReferences hTargetFaces)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidDraftFeature)));
	PmeStdSolidDraftFeature * pStdSolidDraftFeature = static_cast<PmeStdSolidDraftFeature *>(pFeature);

	PmeReferences * pTargetFaces = PME_HANDLE2REFERENCES(hTargetFaces);
	pStdSolidDraftFeature->SetTargetFaces(pTargetFaces);
}

void PmeStdSolidDraftFeatureAPI::SetPullingDirection(PmeHFeature hFeature, MrAxis1 pullingDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidDraftFeature)));
	PmeStdSolidDraftFeature * pStdSolidDraftFeature = static_cast<PmeStdSolidDraftFeature *>(pFeature);

	pStdSolidDraftFeature->SetPullingDirection(pullingDirection);
}

void PmeStdSolidDraftFeatureAPI::SetDraftAngle(PmeHFeature hFeature, double draftAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidDraftFeature)));
	PmeStdSolidDraftFeature * pStdSolidDraftFeature = static_cast<PmeStdSolidDraftFeature *>(pFeature);

	pStdSolidDraftFeature->SetDraftAngle(draftAngle);
}