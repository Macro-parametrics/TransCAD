#include "stdafx.h"
#include ".\PmeStdSolidProtrusionExtrudeFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidProtrusionExtrudeFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

void PmeStdSolidProtrusionExtrudeFeatureAPI::Create
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

	PmeStdSolidProtrusionExtrudeFeature * pFeature = new PmeStdSolidProtrusionExtrudeFeature(pPart, pProfileSketchReference, startDepth, startCondition, endDepth, endCondition, isFlip);
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

void PmeStdSolidProtrusionExtrudeFeatureAPI::GetProfileSketch(PmeHFeature hFeature, PmeHReference & hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	PmeReference * pReference = pStdSolidProtrusionExtrudeFeature->GetProfileSketch();
	hProfileSketch = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::GetStartDepth(PmeHFeature hFeature, double & startDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	startDepth = pStdSolidProtrusionExtrudeFeature->GetStartDepth();
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::GetStartCondition(PmeHFeature hFeature, PmeStdExtrudeEndType & startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	startCondition = pStdSolidProtrusionExtrudeFeature->GetStartCondition();
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::GetEndDepth(PmeHFeature hFeature, double & endDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	endDepth = pStdSolidProtrusionExtrudeFeature->GetEndDepth();
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::GetEndCondition(PmeHFeature hFeature, PmeStdExtrudeEndType & endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	endCondition = pStdSolidProtrusionExtrudeFeature->GetEndCondition();
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	isFlip = pStdSolidProtrusionExtrudeFeature->IsFlip();
}


void PmeStdSolidProtrusionExtrudeFeatureAPI::SetProfileSketch(PmeHFeature hFeature, PmeHReference hProfileSketch)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	PmeReference * pProfileSketch = PME_HANDLE2REFERENCE(hProfileSketch);
	pStdSolidProtrusionExtrudeFeature->SetProfileSketch(pProfileSketch);
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::SetStartDepth(PmeHFeature hFeature, double startDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	pStdSolidProtrusionExtrudeFeature->SetStartDepth(startDepth);
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::SetStartCondition(PmeHFeature hFeature, PmeStdExtrudeEndType startCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	pStdSolidProtrusionExtrudeFeature->SetStartCondition(startCondition);
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::SetEndDepth(PmeHFeature hFeature, double endDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	pStdSolidProtrusionExtrudeFeature->SetEndDepth(endDepth);
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::SetEndCondition(PmeHFeature hFeature, PmeStdExtrudeEndType endCondition)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	pStdSolidProtrusionExtrudeFeature->SetEndCondition(endCondition);
}

void PmeStdSolidProtrusionExtrudeFeatureAPI::SetFlip(PmeHFeature hFeature, bool isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)));
	PmeStdSolidProtrusionExtrudeFeature * pStdSolidProtrusionExtrudeFeature = static_cast<PmeStdSolidProtrusionExtrudeFeature *>(pFeature);

	pStdSolidProtrusionExtrudeFeature->SetFlip(isFlip);
}