#include "stdafx.h"
#include ".\PmeStdSolidCutSweepFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidCutSweepFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidCutSweepFeatureAPI::Create
	(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hProfileSketch,
	PmeHReference hGuideCurve,
	PmeHFeature & hFeature
	)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hProfileSketch);
	PmeReference * pProfileSketchReference = PME_HANDLE2REFERENCE(hProfileSketch);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hGuideCurve);
	PmeReference * pGuideCurveReference = PME_HANDLE2REFERENCE(hGuideCurve);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidCutSweepFeature * pFeature = new PmeStdSolidCutSweepFeature(pPart, pProfileSketchReference, pGuideCurveReference);
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

void PmeStdSolidCutSweepFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutSweepFeature)));
	PmeStdSolidCutSweepFeature * pStdSolidCutSweepFeature = static_cast<PmeStdSolidCutSweepFeature *>(pFeature);

	PmeReference * pReference = pStdSolidCutSweepFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidCutSweepFeatureAPI::GetGuideCurve(PmeHFeature hFeature, PmeHReference & hGuideCurve)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutSweepFeature)));
	PmeStdSolidCutSweepFeature * pStdSolidCutSweepFeature = static_cast<PmeStdSolidCutSweepFeature *>(pFeature);

	PmeReference * pReference = pStdSolidCutSweepFeature->GetGuideCurve();
	hGuideCurve = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidCutSweepFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutSweepFeature)));
	PmeStdSolidCutSweepFeature * pStdSolidCutSweepFeature = static_cast<PmeStdSolidCutSweepFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidCutSweepFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidCutSweepFeatureAPI::SetGuideCurve(PmeHFeature hFeature, PmeHReference hGuideCurve)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutSweepFeature)));
	PmeStdSolidCutSweepFeature * pStdSolidCutSweepFeature = static_cast<PmeStdSolidCutSweepFeature *>(pFeature);

	PmeReference * pGuideCurve = PME_HANDLE2REFERENCE(hGuideCurve);
	pStdSolidCutSweepFeature->SetGuideCurve(pGuideCurve);
}