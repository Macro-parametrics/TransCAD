#include "stdafx.h"
#include ".\PmeStdSolidProtrusionRevolveFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidProtrusionRevolveFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidProtrusionRevolveFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hProfileSketch,
    double startAngle,
    PmeStdRevolveEndType startCondition,
    double endAngle,
    PmeStdRevolveEndType endCondition,
    bool isFlip,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hProfileSketch);
	PmeReference * pProfileSketchReference = PME_HANDLE2REFERENCE(hProfileSketch);
	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidProtrusionRevolveFeature * pFeature = new PmeStdSolidProtrusionRevolveFeature(pPart, pProfileSketchReference, startAngle, startCondition, endAngle, endCondition, isFlip);
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

void PmeStdSolidProtrusionRevolveFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	PmeReference * pReference = pStdSolidProtrusionRevolveFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidProtrusionRevolveFeatureAPI::GetStartAngle(PmeHFeature hFeature, double & startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	startAngle = pStdSolidProtrusionRevolveFeature->GetStartAngle();
}

void PmeStdSolidProtrusionRevolveFeatureAPI::GetStartCondition(PmeHFeature hFeature, PmeStdRevolveEndType & startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	startCondition = pStdSolidProtrusionRevolveFeature->GetStartCondition();
}

void PmeStdSolidProtrusionRevolveFeatureAPI::GetEndAngle(PmeHFeature hFeature, double & endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	endAngle = pStdSolidProtrusionRevolveFeature->GetEndAngle();
}

void PmeStdSolidProtrusionRevolveFeatureAPI::GetEndCondition(PmeHFeature hFeature, PmeStdRevolveEndType & endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	endCondition = pStdSolidProtrusionRevolveFeature->GetEndCondition();
}

void PmeStdSolidProtrusionRevolveFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	isFlip = pStdSolidProtrusionRevolveFeature->IsFlip();
}

void PmeStdSolidProtrusionRevolveFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidProtrusionRevolveFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidProtrusionRevolveFeatureAPI::SetStartAngle(PmeHFeature hFeature, double startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	pStdSolidProtrusionRevolveFeature->SetStartAngle(startAngle);
}

void PmeStdSolidProtrusionRevolveFeatureAPI::SetEndAngle(PmeHFeature hFeature, double endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	pStdSolidProtrusionRevolveFeature->SetEndAngle(endAngle);
}

void PmeStdSolidProtrusionRevolveFeatureAPI::SetFlip(PmeHFeature hFeature, bool isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)));
	PmeStdSolidProtrusionRevolveFeature * pStdSolidProtrusionRevolveFeature = static_cast<PmeStdSolidProtrusionRevolveFeature *>(pFeature);

	pStdSolidProtrusionRevolveFeature->SetFlip(isFlip);
}