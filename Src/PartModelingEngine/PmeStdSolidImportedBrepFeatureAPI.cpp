#include "stdafx.h"
#include ".\PmeStdSolidImportedBrepFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidImportedBrepFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeUtility.h"

void PmeStdSolidImportedBrepFeatureAPI::Create
(
	PmeHPart hPart
	, const CString & name
	, const CString & filePath
	, PmeHFeature & hFeature
)
{
	PmePart * pPart = PME_HANDLE2PART(hPart);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pPart);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pPart->IsInstanceOf(PME_RUNTIME_TYPE(PmePart)));

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidImportedBrepFeature * pFeature = new PmeStdSolidImportedBrepFeature(pPart, filePath);
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

void PmeStdSolidImportedBrepFeatureAPI::GetFilePath(PmeHFeature hFeature, CString & filePath)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidImportedBrepFeature)));
	PmeStdSolidImportedBrepFeature * PStdSolidImportedBrepFeature = static_cast<PmeStdSolidImportedBrepFeature *>(pFeature);

	filePath = PStdSolidImportedBrepFeature->GetFilePath();
}