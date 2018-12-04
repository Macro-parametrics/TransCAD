#include "StdAfx.h"
#include ".\pmestdsolidholecounterboredfeatureapi.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidHoleCounterboredFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

PME_API void PmeStdSolidHoleCounterboredFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hTargetFace,
	double centerX,
	double centerY,
	double centerZ,
	double startRadius,
	double startDepth,
	double endRadius,
	double endDepth,
	double angle,
	PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFace);
	PmeReference * pTargetFaceReference = PME_HANDLE2REFERENCE(hTargetFace);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidHoleCounterboredFeature * pFeature = new PmeStdSolidHoleCounterboredFeature(pPart, pTargetFaceReference, centerX, centerY, centerZ, startRadius, startDepth, endRadius, endDepth, angle);
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

void PmeStdSolidHoleCounterboredFeatureAPI::GetTargetFace(PmeHFeature hFeature, PmeHReference & hTargetFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	PmeReference * pReference = pStdSolidHoleCounterboredFeature->GetTargetFace();
	hTargetFace = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetCenterX(PmeHFeature hFeature, double & centerX)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	centerX = pStdSolidHoleCounterboredFeature->GetCenterX();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetCenterY(PmeHFeature hFeature, double & centerY)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	centerY = pStdSolidHoleCounterboredFeature->GetCenterY();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetCenterZ(PmeHFeature hFeature, double & centerZ)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	centerZ = pStdSolidHoleCounterboredFeature->GetCenterZ();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetStartRadius(PmeHFeature hFeature, double & startRadius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	startRadius = pStdSolidHoleCounterboredFeature->GetStartRadius();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetStartDepth(PmeHFeature hFeature, double & startDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	startDepth = pStdSolidHoleCounterboredFeature->GetStartDepth();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetEndRadius(PmeHFeature hFeature, double & endRadius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	endRadius = pStdSolidHoleCounterboredFeature->GetEndRadius();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetEndDepth(PmeHFeature hFeature, double & endDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	endDepth = pStdSolidHoleCounterboredFeature->GetEndDepth();
}

void PmeStdSolidHoleCounterboredFeatureAPI::GetAngle(PmeHFeature hFeature, double & angle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	angle = pStdSolidHoleCounterboredFeature->GetAngle();
}


void PmeStdSolidHoleCounterboredFeatureAPI::SetTargetFace(PmeHFeature hFeature, PmeHReference hTargetFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);

	PmeReference * pTargetFace = PME_HANDLE2REFERENCE(hTargetFace);
	pStdSolidHoleCounterboredFeature->SetTargetFace(pTargetFace);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetCenterX(PmeHFeature hFeature, double centerX)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetCenterX(centerX);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetCenterY(PmeHFeature hFeature, double centerY)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetCenterY(centerY);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetCenterZ(PmeHFeature hFeature, double centerZ)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetCenterZ(centerZ);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetStartRadius(PmeHFeature hFeature, double startRadius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetStartRadius(startRadius);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetStartDepth(PmeHFeature hFeature, double startDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetStartDepth(startDepth);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetEndRadius(PmeHFeature hFeature, double endRadius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetEndRadius(endRadius);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetEndDepth(PmeHFeature hFeature, double endDepth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetEndDepth(endDepth);
}

void PmeStdSolidHoleCounterboredFeatureAPI::SetBottomAngle(PmeHFeature hFeature, double bottomAngle)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleCounterboredFeature)));
	PmeStdSolidHoleCounterboredFeature * pStdSolidHoleCounterboredFeature = static_cast<PmeStdSolidHoleCounterboredFeature *>(pFeature);
	
	pStdSolidHoleCounterboredFeature->SetBottomAngle(bottomAngle);
}
