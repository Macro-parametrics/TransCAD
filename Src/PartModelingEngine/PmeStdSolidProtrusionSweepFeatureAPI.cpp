#include "stdafx.h"
#include ".\PmeStdSolidProtrusionSweepFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidProtrusionSweepFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidProtrusionSweepFeatureAPI::Create
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

	PmeStdSolidProtrusionSweepFeature * pFeature = new PmeStdSolidProtrusionSweepFeature(pPart, pProfileSketchReference, pGuideCurveReference);
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

void PmeStdSolidProtrusionSweepFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionSweepFeature)));
	PmeStdSolidProtrusionSweepFeature * pStdSolidProtrusionSweepFeature = static_cast<PmeStdSolidProtrusionSweepFeature *>(pFeature);

	PmeReference * pReference = pStdSolidProtrusionSweepFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidProtrusionSweepFeatureAPI::GetGuideCurve(PmeHFeature hFeature, PmeHReference & hGuideCurve)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionSweepFeature)));
	PmeStdSolidProtrusionSweepFeature * pStdSolidProtrusionSweepFeature = static_cast<PmeStdSolidProtrusionSweepFeature *>(pFeature);

	PmeReference * pReference = pStdSolidProtrusionSweepFeature->GetGuideCurve();
	hGuideCurve = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidProtrusionSweepFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionSweepFeature)));
	PmeStdSolidProtrusionSweepFeature * pStdSolidProtrusionSweepFeature = static_cast<PmeStdSolidProtrusionSweepFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidProtrusionSweepFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidProtrusionSweepFeatureAPI::SetGuideCurve(PmeHFeature hFeature, PmeHReference hGuideCurve)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionSweepFeature)));
	PmeStdSolidProtrusionSweepFeature * pStdSolidProtrusionSweepFeature = static_cast<PmeStdSolidProtrusionSweepFeature *>(pFeature);

	PmeReference * pGuideCurve = PME_HANDLE2REFERENCE(hGuideCurve);
	pStdSolidProtrusionSweepFeature->SetGuideCurve(pGuideCurve);
}