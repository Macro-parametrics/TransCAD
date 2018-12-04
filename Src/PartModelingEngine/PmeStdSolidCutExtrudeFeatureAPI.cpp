#include "stdafx.h"
#include ".\PmeStdSolidCutExtrudeFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidCutExtrudeFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

PME_API void PmeStdSolidCutExtrudeFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hProfileSketch,
    double startDepth,
    PmeStdExtrudeEndType startCondition,
    double endDepth,
    PmeStdExtrudeEndType endCondition,
    bool isFlip,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hProfileSketch);
	PmeReference * pProfileSketchReference = PME_HANDLE2REFERENCE(hProfileSketch);
	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidCutExtrudeFeature * pFeature = new PmeStdSolidCutExtrudeFeature(pPart, pProfileSketchReference, startDepth, startCondition, endDepth, endCondition, isFlip);
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

void PmeStdSolidCutExtrudeFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	PmeReference * pReference = pStdSolidCutExtrudeFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidCutExtrudeFeatureAPI::GetStartDepth(PmeHFeature hFeature, double & startDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	startDepth = pStdSolidCutExtrudeFeature->GetStartDepth();
}

void PmeStdSolidCutExtrudeFeatureAPI::GetStartCondition(PmeHFeature hFeature, PmeStdExtrudeEndType & startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	startCondition = pStdSolidCutExtrudeFeature->GetStartCondition();
}

void PmeStdSolidCutExtrudeFeatureAPI::GetEndDepth(PmeHFeature hFeature, double & endDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	endDepth = pStdSolidCutExtrudeFeature->GetEndDepth();
}

void PmeStdSolidCutExtrudeFeatureAPI::GetEndCondition(PmeHFeature hFeature, PmeStdExtrudeEndType & endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	endCondition = pStdSolidCutExtrudeFeature->GetEndCondition();
}

void PmeStdSolidCutExtrudeFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	isFlip = pStdSolidCutExtrudeFeature->IsFlip();
}

void PmeStdSolidCutExtrudeFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidCutExtrudeFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidCutExtrudeFeatureAPI::SetStartDepth(PmeHFeature hFeature, double startDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	pStdSolidCutExtrudeFeature->SetStartDepth(startDepth);
}

void PmeStdSolidCutExtrudeFeatureAPI::SetStartCondition(PmeHFeature hFeature, PmeStdExtrudeEndType startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	pStdSolidCutExtrudeFeature->SetStartCondition(startCondition);
}

void PmeStdSolidCutExtrudeFeatureAPI::SetEndDepth(PmeHFeature hFeature, double endDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	pStdSolidCutExtrudeFeature->SetEndDepth(endDepth);
}

void PmeStdSolidCutExtrudeFeatureAPI::SetEndCondition(PmeHFeature hFeature, PmeStdExtrudeEndType endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	pStdSolidCutExtrudeFeature->SetEndCondition(endCondition);
}

void PmeStdSolidCutExtrudeFeatureAPI::SetFlip(PmeHFeature hFeature, bool isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)));
	PmeStdSolidCutExtrudeFeature * pStdSolidCutExtrudeFeature = static_cast<PmeStdSolidCutExtrudeFeature *>(pFeature);

	pStdSolidCutExtrudeFeature->SetFlip(isFlip);
}