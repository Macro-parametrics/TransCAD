#include "StdAfx.h"
#include ".\PmeStdSolidHoleSimpleFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidHoleSimpleFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeUtility.h"

PME_API void PmeStdSolidHoleSimpleFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hTargetFace,
	double centerX,
	double centerY,
	double centerZ,
	double radius,
	double depth,
	PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFace);
	PmeReference * pTargetFaceReference = PME_HANDLE2REFERENCE(hTargetFace);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidHoleSimpleFeature * pFeature = new PmeStdSolidHoleSimpleFeature(pPart, pTargetFaceReference, centerX, centerY, centerZ, radius, depth);
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

void PmeStdSolidHoleSimpleFeatureAPI::GetTargetFace(PmeHFeature hFeature, PmeHReference & hTargetFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	PmeReference * pReference = pStdSolidHoleSimpleFeature->GetTargetFace();
	hTargetFace = PME_REFERENCE2HANDLE(pReference);
}

void PmeStdSolidHoleSimpleFeatureAPI::GetCenterX(PmeHFeature hFeature, double & centerX)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	centerX = pStdSolidHoleSimpleFeature->GetCenterX();
}

void PmeStdSolidHoleSimpleFeatureAPI::GetCenterY(PmeHFeature hFeature, double & centerY)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	centerY = pStdSolidHoleSimpleFeature->GetCenterY();
}

void PmeStdSolidHoleSimpleFeatureAPI::GetCenterZ(PmeHFeature hFeature, double & centerZ)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	centerZ = pStdSolidHoleSimpleFeature->GetCenterZ();
}

void PmeStdSolidHoleSimpleFeatureAPI::GetRadius(PmeHFeature hFeature, double & radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	radius = pStdSolidHoleSimpleFeature->GetRadius();
}

void PmeStdSolidHoleSimpleFeatureAPI::GetDepth(PmeHFeature hFeature, double & depth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	depth = pStdSolidHoleSimpleFeature->GetDepth();
}

void PmeStdSolidHoleSimpleFeatureAPI::SetTargetFace(PmeHFeature hFeature, PmeHReference hTargetFace)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	PmeReference * pTargetFace = PME_HANDLE2REFERENCE(hTargetFace);
	pStdSolidHoleSimpleFeature->SetTargetFace(pTargetFace);
}

void PmeStdSolidHoleSimpleFeatureAPI::SetCenterX(PmeHFeature hFeature, double centerX)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	pStdSolidHoleSimpleFeature->SetCenterX(centerX);
}

void PmeStdSolidHoleSimpleFeatureAPI::SetCenterY(PmeHFeature hFeature, double centerY)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	pStdSolidHoleSimpleFeature->SetCenterY(centerY);
}

void PmeStdSolidHoleSimpleFeatureAPI::SetCenterZ(PmeHFeature hFeature, double centerZ)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	

	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	pStdSolidHoleSimpleFeature->SetCenterZ(centerZ);
}

void PmeStdSolidHoleSimpleFeatureAPI::SetRadius(PmeHFeature hFeature, double radius)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	pStdSolidHoleSimpleFeature->SetRadius(radius);
}

void PmeStdSolidHoleSimpleFeatureAPI::SetDepth(PmeHFeature hFeature, double depth)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature)));
	PmeStdSolidHoleSimpleFeature * pStdSolidHoleSimpleFeature = static_cast<PmeStdSolidHoleSimpleFeature *>(pFeature);

	pStdSolidHoleSimpleFeature->SetDepth(depth);
}