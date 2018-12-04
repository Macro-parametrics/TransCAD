#include "stdafx.h"
#include ".\PmeStdSolidRevolveWithExternalAxisFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidRevolveWithExternalAxisFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hProfileSketch,
    double startAngle,
    PmeStdRevolveEndType startCondition,
    double endAngle,
    PmeStdRevolveEndType endCondition,
	const MrAxis1 & revolveAxis,
	bool isCut,
	bool isFlip,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hProfileSketch);
	PmeReference * pProfileSketchReference = PME_HANDLE2REFERENCE(hProfileSketch);
	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidRevolveWithExternalAxisFeature * pFeature = new PmeStdSolidRevolveWithExternalAxisFeature(pPart, pProfileSketchReference, startAngle, startCondition, endAngle, endCondition, revolveAxis, isCut, isFlip);
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

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	PmeReference * pReference = pStdSolidRevolveFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetStartAngle(PmeHFeature hFeature, double & startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	startAngle = pStdSolidRevolveFeature->GetStartAngle();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetStartCondition(PmeHFeature hFeature, PmeStdRevolveEndType & startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	startCondition = pStdSolidRevolveFeature->GetStartCondition();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetEndAngle(PmeHFeature hFeature, double & endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	endAngle = pStdSolidRevolveFeature->GetEndAngle();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetEndCondition(PmeHFeature hFeature, PmeStdRevolveEndType & endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	endCondition = pStdSolidRevolveFeature->GetEndCondition();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetRevolveAxis(PmeHFeature hFeature, MrAxis1 & revolveAxis)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	revolveAxis = pStdSolidRevolveFeature->GetRevolveAxis();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::IsCut(PmeHFeature hFeature, bool & isCut)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	isCut = pStdSolidRevolveFeature->IsCut();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	isFlip = pStdSolidRevolveFeature->IsFlip();
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidRevolveFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetStartAngle(PmeHFeature hFeature, double startAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	pStdSolidRevolveFeature->SetStartAngle(startAngle);
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetEndAngle(PmeHFeature hFeature, double endAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);
	
	pStdSolidRevolveFeature->SetEndAngle(endAngle);
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetFlip(PmeHFeature hFeature, bool isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	pStdSolidRevolveFeature->SetFlip(isFlip);
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetRevolveAxis(PmeHFeature hFeature, MrAxis1 revolveAxis)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	pStdSolidRevolveFeature->SetRevolveAxis(revolveAxis);
}

void PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetCut(PmeHFeature hFeature, bool isCut)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)));
	PmeStdSolidRevolveWithExternalAxisFeature * pStdSolidRevolveFeature = static_cast<PmeStdSolidRevolveWithExternalAxisFeature *>(pFeature);

	pStdSolidRevolveFeature->SetCut(isCut);
}