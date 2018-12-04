#include "stdafx.h"
#include ".\PmeStdSolidCutRevolveFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidCutRevolveFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidCutRevolveFeatureAPI::Create
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

	PmeStdSolidCutRevolveFeature * pFeature = new PmeStdSolidCutRevolveFeature(pPart, pProfileSketchReference, startAngle, startCondition, endAngle, endCondition, isFlip);
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

void PmeStdSolidCutRevolveFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	PmeReference * pReference = pStdSolidCutRevolveFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidCutRevolveFeatureAPI::GetStartAngle(PmeHFeature hFeature, double & startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	startAngle = pStdSolidCutRevolveFeature->GetStartAngle();
}

void PmeStdSolidCutRevolveFeatureAPI::GetStartCondition(PmeHFeature hFeature, PmeStdRevolveEndType & startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	startCondition = pStdSolidCutRevolveFeature->GetStartCondition();
}

void PmeStdSolidCutRevolveFeatureAPI::GetEndAngle(PmeHFeature hFeature, double & endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	endAngle = pStdSolidCutRevolveFeature->GetEndAngle();
}

void PmeStdSolidCutRevolveFeatureAPI::GetEndCondition(PmeHFeature hFeature, PmeStdRevolveEndType & endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	endCondition = pStdSolidCutRevolveFeature->GetEndCondition();
}

void PmeStdSolidCutRevolveFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	isFlip = pStdSolidCutRevolveFeature->IsFlip();
}

void PmeStdSolidCutRevolveFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidCutRevolveFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidCutRevolveFeatureAPI::SetStartAngle(PmeHFeature hFeature, double startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	pStdSolidCutRevolveFeature->SetStartAngle(startAngle);
}

void PmeStdSolidCutRevolveFeatureAPI::SetEndAngle(PmeHFeature hFeature, double endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	pStdSolidCutRevolveFeature->SetEndAngle(endAngle);
}

void PmeStdSolidCutRevolveFeatureAPI::SetFlip(PmeHFeature hFeature, bool isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)));
	PmeStdSolidCutRevolveFeature * pStdSolidCutRevolveFeature = static_cast<PmeStdSolidCutRevolveFeature *>(pFeature);

	pStdSolidCutRevolveFeature->SetFlip(isFlip);
}