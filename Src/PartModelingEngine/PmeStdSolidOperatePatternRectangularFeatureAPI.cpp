#include "stdafx.h"
#include ".\PmeStdSolidOperatePatternRectangularFeatureAPI.h"
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
#include ".\PmeStdSolidOperatePatternRectangularFeature.h"

void PmeStdSolidOperatePatternRectangularFeatureAPI::Create
(
	PmeHPart hPart,
	const CString & name,
	PmeHReferences hTargetFeatures,
    double columnSpacing,
	const MrDirection & columnDirection,
	int columnNumber,
	double rowSpacing,
	const MrDirection & rowDirection,
	int rowNumber,
    PmeHFeature & hFeature
)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeThrowExceptionIf<PmeArgumentOutOfRangeException>(columnNumber < 1 || rowNumber < 1);
	PmeThrowExceptionIf<PmeArgumentException>(columnSpacing < 0 || rowSpacing < 0);
	PmeThrowExceptionIf<PmeArgumentException>(MrMath::IsParallel(columnDirection, rowDirection));

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTargetFeatures);
	PmeReferences * pTargetFeatures = PME_HANDLE2REFERENCES(hTargetFeatures);
		
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidOperatePatternRectangularFeature * pFeature = new PmeStdSolidOperatePatternRectangularFeature(
		pPart, pTargetFeatures,
		columnSpacing, columnDirection, columnNumber,
		rowSpacing, rowDirection, rowNumber);

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

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetTargetFeatures(PmeHFeature hFeature, PmeHReferences & hTargetFeatures)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	PmeReferences * pReferences = pSolidOperatePatternRectangularFeature->GetTargetFeatures();
	hTargetFeatures = PME_REFERENCES2HANDLE(pReferences);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnSpacing(PmeHFeature hFeature, double & columnSpacing)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	columnSpacing = pSolidOperatePatternRectangularFeature->GetColumnSpacing();
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnDirection(PmeHFeature hFeature, MrDirection & columnDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	columnDirection = pSolidOperatePatternRectangularFeature->GetColumnDirection();
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnNumber(PmeHFeature hFeature, int & columnNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	columnNumber = pSolidOperatePatternRectangularFeature->GetColumnNumber();
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowSpacing(PmeHFeature hFeature, double & rowSpacing)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	rowSpacing = pSolidOperatePatternRectangularFeature->GetRowSpacing();
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowDirection(PmeHFeature hFeature, MrDirection & rowDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	rowDirection = pSolidOperatePatternRectangularFeature->GetRowDirection();
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowNumber(PmeHFeature hFeature, int & rowNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	rowNumber = pSolidOperatePatternRectangularFeature->GetRowNumber();
}


void PmeStdSolidOperatePatternRectangularFeatureAPI::SetTargetFeatures(PmeHFeature hFeature, PmeHReferences hTargetFeatures)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	PmeReferences * pReferences = PME_HANDLE2REFERENCES(hTargetFeatures);
	pSolidOperatePatternRectangularFeature->SetTargetFeatures(pReferences);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnSpacing(PmeHFeature hFeature, double columnSpacing)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	pSolidOperatePatternRectangularFeature->SetColumnSpacing(columnSpacing);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnDirection(PmeHFeature hFeature, MrDirection columnDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	pSolidOperatePatternRectangularFeature->SetColumnDirection(columnDirection);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnNumber(PmeHFeature hFeature, int columnNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	pSolidOperatePatternRectangularFeature->SetColumnNumber(columnNumber);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowSpacing(PmeHFeature hFeature, double rowSpacing)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	pSolidOperatePatternRectangularFeature->SetRowSpacing(rowSpacing);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowDirection(PmeHFeature hFeature, MrDirection rowDirection)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	pSolidOperatePatternRectangularFeature->SetRowDirection(rowDirection);
}

void PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowNumber(PmeHFeature hFeature, int rowNumber)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)));
	PmeStdSolidOperatePatternRectangularFeature * pSolidOperatePatternRectangularFeature = static_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);

	pSolidOperatePatternRectangularFeature->SetRowNumber(rowNumber);
}
