#include "StdAfx.h"
#include "PmeStdDatumPlaneOffsetFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdDatumPlaneOffsetFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeUtility.h"
#include "pmeexplicitmodelobject.h"

PME_API void PmeStdDatumPlaneOffsetFeatureAPI::Create
(
		PmeHPart hPart,
		const CString & name,
		PmeHReference hSelectedPlane,
		double distance,
		bool isFlip,
		PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);
	
	PmeThrowExceptionIf<PmeArgumentNullException>(!hSelectedPlane);
	PmeReference * pSelectedPlaneReference = PME_HANDLE2REFERENCE(hSelectedPlane);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdDatumPlaneOffsetFeature * pFeature = new PmeStdDatumPlaneOffsetFeature(pPart, pSelectedPlaneReference, distance, isFlip);
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

	PmeHExplicitModelObject hDatumPlane = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetDatumPlane());
	if(hDatumPlane)
	{
        PME_UPDATE_EXPLICITMODELOBJECT(hPart, hDatumPlane, PmeUpdateState_Update);
	}
}

PME_API void PmeStdDatumPlaneOffsetFeatureAPI::Create2
	(
	PmeHPart hPart,
	const CString & name,
	double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz,
	bool isFlip,
	PmeHFeature & hFeature
	)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdDatumPlaneOffsetFeature * pFeature = new PmeStdDatumPlaneOffsetFeature(pPart, ox,oy,oz,xx,xy,xz,yx,yy,yz, isFlip);
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

	PmeHExplicitModelObject hDatumPlane = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetDatumPlane());
	if(hDatumPlane)
	{
		PME_UPDATE_EXPLICITMODELOBJECT(hPart, hDatumPlane, PmeUpdateState_Update);
	}
}

void PmeStdDatumPlaneOffsetFeatureAPI::GetSelectedPlane(PmeHFeature hFeature, PmeHReference & hSelectedPlane)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	PmeReference * pReference = pStdDatumPlaneOffsetFeature->GetSelectedPlane();
	hSelectedPlane = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdDatumPlaneOffsetFeatureAPI::GetDistance(PmeHFeature hFeature, double & distance)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	distance = pStdDatumPlaneOffsetFeature->GetDistance();
}

void PmeStdDatumPlaneOffsetFeatureAPI::IsFlip(PmeHFeature hFeature, bool & isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	isFlip = pStdDatumPlaneOffsetFeature->IsFlip();
}

void PmeStdDatumPlaneOffsetFeatureAPI::IsFree(PmeHFeature hFeature, bool & isFree)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	isFree = pStdDatumPlaneOffsetFeature->IsFree();
}

void PmeStdDatumPlaneOffsetFeatureAPI::GetOrigin(PmeHFeature hFeature, MrPosition & origin)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	origin = pStdDatumPlaneOffsetFeature->GetOrigin();
}

void PmeStdDatumPlaneOffsetFeatureAPI::GetXDirection(PmeHFeature hFeature, MrDirection & xdir)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	xdir = pStdDatumPlaneOffsetFeature->GetXDirection();
}

void PmeStdDatumPlaneOffsetFeatureAPI::GetYDirection(PmeHFeature hFeature, MrDirection & ydir)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	ydir = pStdDatumPlaneOffsetFeature->GetYDirection();
}



void PmeStdDatumPlaneOffsetFeatureAPI::SetSelectedPlane(PmeHFeature hFeature, PmeHReference hSelectedPlane)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	PmeReference * pReference = PME_HANDLE2REFERENCE(hSelectedPlane);
	pStdDatumPlaneOffsetFeature->SetSelectedPlane(pReference);
}

void PmeStdDatumPlaneOffsetFeatureAPI::SetDistance(PmeHFeature hFeature, double distance)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	pStdDatumPlaneOffsetFeature->SetDistance(distance);
}

void PmeStdDatumPlaneOffsetFeatureAPI::SetFlip(PmeHFeature hFeature, bool isFlip)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	pStdDatumPlaneOffsetFeature->SetFlip(isFlip);
}

void PmeStdDatumPlaneOffsetFeatureAPI::SetOrigin(PmeHFeature hFeature, MrPosition origin)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	pStdDatumPlaneOffsetFeature->SetOrigin(origin);
}

void PmeStdDatumPlaneOffsetFeatureAPI::SetXDirection(PmeHFeature hFeature, MrDirection xdir)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	pStdDatumPlaneOffsetFeature->SetXDirection(xdir);
}

void PmeStdDatumPlaneOffsetFeatureAPI::SetYDirection(PmeHFeature hFeature, MrDirection ydir)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature)));
	PmeStdDatumPlaneOffsetFeature * pStdDatumPlaneOffsetFeature = static_cast<PmeStdDatumPlaneOffsetFeature *>(pFeature);

	pStdDatumPlaneOffsetFeature->SetYDirection(ydir);
}