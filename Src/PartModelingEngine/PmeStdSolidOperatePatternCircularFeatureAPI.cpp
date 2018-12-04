#include "stdafx.h"
#include ".\PmeStdSolidOperatePatternCircularFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeArgumentOutOfRangeException.h"
#include ".\PmeReference.h"
#include ".\PmeReferences.h"
#include ".\PmeUtility.h"
#include ".\PmeStdSolidOperatePatternCircularFeature.h"

void PmeStdSolidOperatePatternCircularFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReferences hTargetFeatures,
    const MrAxis1 & centerAxis,
    int angleNumber,
    double angleIncrement,
	int radialNumber,
    double radialSpacing,
    bool radialAlignment,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(angleNumber < 1);
	PmeThrowExceptionIf<PmeArgumentException>(angleIncrement < 0);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFeatures);
	PmeReferences * pTargetFeatures = PME_HANDLE2REFERENCES(hTargetFeatures);
		
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidOperatePatternCircularFeature * pFeature = new PmeStdSolidOperatePatternCircularFeature(
		pPart, pTargetFeatures, centerAxis, angleNumber, angleIncrement, radialNumber, radialSpacing, radialAlignment);

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

void PmeStdSolidOperatePatternCircularFeatureAPI::GetTargetFeatures(PmeHFeature hFeature, PmeHReferences & hTargetFeatures)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	PmeReferences * pReferences = pSolidOperatePatternCircularFeature->GetTargetFeatures();
	hTargetFeatures = PME_REFERENCES2HANDLE(pReferences);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::GetCenterAxis(PmeHFeature hFeature, MrAxis1 & centerAxis)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	centerAxis = pSolidOperatePatternCircularFeature->GetCenterAxis();
}

void PmeStdSolidOperatePatternCircularFeatureAPI::GetAngleNumber(PmeHFeature hFeature, int & angleNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	angleNumber = pSolidOperatePatternCircularFeature->GetAngleNumber();
}

void PmeStdSolidOperatePatternCircularFeatureAPI::GetAngleIncrement(PmeHFeature hFeature, double & angleIncrement)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	angleIncrement = pSolidOperatePatternCircularFeature->GetAngleIncrement();
}

void PmeStdSolidOperatePatternCircularFeatureAPI::GetRadialNumber(PmeHFeature hFeature, int & radialNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	radialNumber = pSolidOperatePatternCircularFeature->GetRadialNumber();
}

void PmeStdSolidOperatePatternCircularFeatureAPI::GetRadialSpacing(PmeHFeature hFeature, double & radialSpacing)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	radialSpacing = pSolidOperatePatternCircularFeature->GetRadialSpacing();
}

void PmeStdSolidOperatePatternCircularFeatureAPI::IsRadialAlignment(PmeHFeature hFeature, bool & isRadialAlignment)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);

	isRadialAlignment = pSolidOperatePatternCircularFeature->IsRadialAnignment();
}


void PmeStdSolidOperatePatternCircularFeatureAPI::SetTargetFeatures(PmeHFeature hFeature, PmeHReferences hTargetFeatures)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hTargetFeatures);
	pSolidOperatePatternCircularFeature->SetTargetFeatures(pReferences);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::SetCenterAxis(PmeHFeature hFeature, MrAxis1 centerAxis)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	pSolidOperatePatternCircularFeature->SetCenterAxis(centerAxis);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::SetAngleNumber(PmeHFeature hFeature, int angleNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	pSolidOperatePatternCircularFeature->SetAngleNumber(angleNumber);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::SetAngleIncrement(PmeHFeature hFeature, double angleIncrement)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	pSolidOperatePatternCircularFeature->SetAngleIncrement(angleIncrement);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialNumber(PmeHFeature hFeature, int radialNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	pSolidOperatePatternCircularFeature->SetRadialNumber(radialNumber);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialSpacing(PmeHFeature hFeature, double radialSpacing)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	pSolidOperatePatternCircularFeature->SetRadialSpacing(radialSpacing);
}

void PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialAlignment(PmeHFeature hFeature, bool isRadialAlignment)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)));
	PmeStdSolidOperatePatternCircularFeature * pSolidOperatePatternCircularFeature = static_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
	
	pSolidOperatePatternCircularFeature->SetRadialAlignment(isRadialAlignment);
}
