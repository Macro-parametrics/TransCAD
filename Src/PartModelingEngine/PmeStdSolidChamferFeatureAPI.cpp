#include "stdafx.h"
#include ".\PmeStdSolidChamferFeatureAPI.h"
#include ".\PmeReferences.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidChamferFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"


void PmeStdSolidChamferFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeChamferType chamferType,
	PmeHReferences hSelectedEdges,
	PmeHReference hSelectedFace,
	double length,
	double value,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hSelectedEdges);
	PmeReferences * pSelectedEdges = PME_HANDLE2REFERENCES(hSelectedEdges);

	PmeReference * pSelectedFace = 0;
	if(hSelectedFace)
		pSelectedFace = PME_HANDLE2REFERENCE(hSelectedFace);
	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidChamferFeature * pFeature = new PmeStdSolidChamferFeature(pPart, chamferType, pSelectedEdges, pSelectedFace, length, value);
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

void PmeStdSolidChamferFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hSelectedEdges,
	double length,
    PmeHFeature & hFeature
)
{
	PmeStdSolidChamferFeatureAPI::Create(hPart, name, PmeChamferType_Length, hSelectedEdges, 0, length, length, hFeature);
}

void PmeStdSolidChamferFeatureAPI::GetChamferType(PmeHFeature hFeature, PmeChamferType & chamferType)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	chamferType = pStdSolidChamferFeature->GetChamferType();
}

void PmeStdSolidChamferFeatureAPI::GetSelectedEdges(PmeHFeature hFeature, PmeHReferences & hSelectedEdges)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	PmeReferences * pSelectedEdges = pStdSolidChamferFeature->GetSelectedEdges();
	hSelectedEdges = PME_REFERENCES2HANDLE(pSelectedEdges);
}

void PmeStdSolidChamferFeatureAPI::GetSelectedFace(PmeHFeature hFeature, PmeHReference & hSelectedFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	PmeReference * pSelectedFace = pStdSolidChamferFeature->GetSelectedFace();
	if(pSelectedFace)
        hSelectedFace = PME_REFERENCE2HANDLE(pSelectedFace);
	else
		hSelectedFace = 0;
}

void PmeStdSolidChamferFeatureAPI::GetLength(PmeHFeature hFeature, double & length)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	length = pStdSolidChamferFeature->GetLength();
}

void PmeStdSolidChamferFeatureAPI::GetValue(PmeHFeature hFeature, double & value)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	value = pStdSolidChamferFeature->GetValue();
}

void PmeStdSolidChamferFeatureAPI::GetStartPoint(PmeHFeature hFeature, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	position = pStdSolidChamferFeature->GetStartPoint();
}

void PmeStdSolidChamferFeatureAPI::GetEndPoint(PmeHFeature hFeature, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	position = pStdSolidChamferFeature->GetEndPoint();
}

void PmeStdSolidChamferFeatureAPI::GetStartPointAt(PmeHFeature hFeature, int index, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	position = pStdSolidChamferFeature->GetStartPointAt(index);
}

void PmeStdSolidChamferFeatureAPI::GetEndPointAt(PmeHFeature hFeature, int index, SPAposition & position)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	position = pStdSolidChamferFeature->GetEndPointAt(index);
}

void PmeStdSolidChamferFeatureAPI::SetChamferType(PmeHFeature hFeature, PmeChamferType chamferType)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	pStdSolidChamferFeature->SetChamferType(chamferType);
}

void PmeStdSolidChamferFeatureAPI::SetSelectedEdges(PmeHFeature hFeature, PmeHReferences hSelectedEdges)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	PmeReferences * pSelectedEdges = PME_HANDLE2REFERENCES(hSelectedEdges);
	pStdSolidChamferFeature->SetSelectedEdges(pSelectedEdges);
}

void PmeStdSolidChamferFeatureAPI::SetLength(PmeHFeature hFeature, double length)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidChamferFeature)));
	PmeStdSolidChamferFeature * pStdSolidChamferFeature = static_cast<PmeStdSolidChamferFeature *>(pFeature);

	pStdSolidChamferFeature->SetLength(length);
}