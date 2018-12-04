#include "StdAfx.h"
#include ".\pmestdsolidholecountersunkfeatureapi.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidHoleCountersunkFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

PME_API void PmeStdSolidHoleCountersunkFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hTargetFace,
	double centerX,
	double centerY,
	double centerZ,
	double radius,
	double depth,
	double sinkRadius,
	double sinkAngle,
	double bottomAngle,
	PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFace);
	PmeReference * pTargetFaceReference = PME_HANDLE2REFERENCE(hTargetFace);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidHoleCountersunkFeature * pFeature = new PmeStdSolidHoleCountersunkFeature(pPart, pTargetFaceReference, centerX, centerY, centerZ, radius, depth, sinkRadius, sinkAngle, bottomAngle);
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

void PmeStdSolidHoleCountersunkFeatureAPI::GetTargetFace(PmeHFeature hFeature, PmeHReference & hTargetFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	PmeReference * pReference = pStdSolidHoleCountersunkFeature->GetTargetFace();
	hTargetFace = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetCenterX(PmeHFeature hFeature, double & centerX)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	centerX = pStdSolidHoleCountersunkFeature->GetCenterX();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetCenterY(PmeHFeature hFeature, double & centerY)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	centerY = pStdSolidHoleCountersunkFeature->GetCenterY();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetCenterZ(PmeHFeature hFeature, double & centerZ)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	centerZ = pStdSolidHoleCountersunkFeature->GetCenterZ();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetRadius(PmeHFeature hFeature, double & radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	radius = pStdSolidHoleCountersunkFeature->GetRadius();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetDepth(PmeHFeature hFeature, double & depth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	depth = pStdSolidHoleCountersunkFeature->GetDepth();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetSinkRadius(PmeHFeature hFeature, double & sinkRadius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	sinkRadius = pStdSolidHoleCountersunkFeature->GetSinkRadius();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetSinkAngle(PmeHFeature hFeature, double & sinkAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	sinkAngle = pStdSolidHoleCountersunkFeature->GetSinkAngle();
}

void PmeStdSolidHoleCountersunkFeatureAPI::GetBottomAngle(PmeHFeature hFeature, double & bottomAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	bottomAngle = pStdSolidHoleCountersunkFeature->GetBottomAngle();
}



void PmeStdSolidHoleCountersunkFeatureAPI::SetTargetFace(PmeHFeature hFeature, PmeHReference hTargetFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	PmeReference * pTargetFace = PME_HANDLE2REFERENCE(hTargetFace);
	pStdSolidHoleCountersunkFeature->SetTargetFace(pTargetFace);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetCenterX(PmeHFeature hFeature, double centerX)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetCenterX(centerX);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetCenterY(PmeHFeature hFeature, double centerY)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetCenterY(centerY);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetCenterZ(PmeHFeature hFeature, double centerZ)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetCenterZ(centerZ);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetRadius(PmeHFeature hFeature, double radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetRadius(radius);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetDepth(PmeHFeature hFeature, double depth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetDepth(depth);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetSinkRadius(PmeHFeature hFeature, double sinkRadius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetSinkRadius(sinkRadius);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetSinkAngle(PmeHFeature hFeature, double sinkAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetSinkAngle(sinkAngle);
}

void PmeStdSolidHoleCountersunkFeatureAPI::SetBottomAngle(PmeHFeature hFeature, double bottomAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature)));
	PmeStdSolidHoleCountersunkFeature * pStdSolidHoleCountersunkFeature = static_cast<PmeStdSolidHoleCountersunkFeature *>(pFeature);

	pStdSolidHoleCountersunkFeature->SetBottomAngle(bottomAngle);
}