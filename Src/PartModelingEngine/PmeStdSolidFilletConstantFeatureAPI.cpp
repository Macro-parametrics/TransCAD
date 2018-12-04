#include "stdafx.h"
#include ".\PmeStdSolidFilletConstantFeatureAPI.h"
#include ".\PmeReferences.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidFilletConstantFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"


void PmeStdSolidFilletConstantFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReferences hFilletEdges,
    double radius,
	PmePropagationType propagation,    
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hFilletEdges);
	PmeReferences * pFilletEdges = PME_HANDLE2REFERENCES(hFilletEdges);
	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidFilletConstantFeature * pFeature = new PmeStdSolidFilletConstantFeature(pPart, pFilletEdges, radius, propagation);
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

void PmeStdSolidFilletConstantFeatureAPI::GetFilletEdges(PmeHFeature hFeature, PmeHReferences & hFilletEdges)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	PmeReferences * pFilletEdges = pStdSolidFilletConstantFeature->GetFilletEdges();
	hFilletEdges = PME_REFERENCES2HANDLE(pFilletEdges);
}

void PmeStdSolidFilletConstantFeatureAPI::GetRadius(PmeHFeature hFeature, double & radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	radius = pStdSolidFilletConstantFeature->GetRadius();
}

void PmeStdSolidFilletConstantFeatureAPI::GetStartPoint(PmeHFeature hFeature, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	position = pStdSolidFilletConstantFeature->GetStartPoint();
}

void PmeStdSolidFilletConstantFeatureAPI::GetEndPoint(PmeHFeature hFeature, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	position = pStdSolidFilletConstantFeature->GetEndPoint();
}

void PmeStdSolidFilletConstantFeatureAPI::GetPropagationType(PmeHFeature hFeature, PmePropagationType & propagation)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	propagation = pStdSolidFilletConstantFeature->GetPropagation();
}

void PmeStdSolidFilletConstantFeatureAPI::GetStartPointAt(PmeHFeature hFeature, int index, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	position = pStdSolidFilletConstantFeature->GetStartPointAt(index);
}

void PmeStdSolidFilletConstantFeatureAPI::GetEndPointAt(PmeHFeature hFeature, int index, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	position = pStdSolidFilletConstantFeature->GetEndPointAt(index);
}

void PmeStdSolidFilletConstantFeatureAPI::SetFilletEdges(PmeHFeature hFeature, PmeHReferences hFilletEdges)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	PmeReferences * pFilletEdges = PME_HANDLE2REFERENCES(hFilletEdges);
	pStdSolidFilletConstantFeature->SetFilletEdges(pFilletEdges);
}

void PmeStdSolidFilletConstantFeatureAPI::SetRadius(PmeHFeature hFeature, double radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	pStdSolidFilletConstantFeature->SetRadius(radius);
}

void PmeStdSolidFilletConstantFeatureAPI::SetPropagationType(PmeHFeature hFeature, PmePropagationType propagation)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidFilletConstantFeature)));
	PmeStdSolidFilletConstantFeature * pStdSolidFilletConstantFeature = static_cast<PmeStdSolidFilletConstantFeature *>(pFeature);

	pStdSolidFilletConstantFeature->SetPropagation(propagation);
}