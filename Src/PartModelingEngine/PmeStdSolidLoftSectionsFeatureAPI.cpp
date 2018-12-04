#include "StdAfx.h"
#include "PmeStdSolidLoftSectionsFeatureAPI.h"
#include "PmeStdSolidLoftSectionsFeature.h"

#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"
#include ".\PmeReferences.h"
#include ".\PmeUtility.h"

void PmeStdSolidLoftSectionsFeatureAPI::Create
	(
	PmeHPart hPart,
	const CString & name,
	PmeHReference hSections,
	bool isCut,
	PmeHFeature & hFeature
	)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);
	PmePart * pPart = PME_HANDLE2PART(hPart);

	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeThrowExceptionIf<PmeArgumentNullException>(!hSections);
	PmeReferences * pSections = PME_HANDLE2REFERENCES(hSections);

	PmeStdSolidLoftSectionsFeature * pFeature = new PmeStdSolidLoftSectionsFeature(pPart, pSections, isCut);

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

void PmeStdSolidLoftSectionsFeatureAPI::GetLoftSections(PmeHFeature hFeature, PmeHReferences & hLoftSections)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidLoftSectionsFeature)));
	PmeStdSolidLoftSectionsFeature * pStdSolidLoftSectionsFeature = static_cast<PmeStdSolidLoftSectionsFeature *>(pFeature);

	PmeReferences * pReferences = pStdSolidLoftSectionsFeature->GetLoftSections();
	hLoftSections = PME_REFERENCES2HANDLE(pReferences);
}

void PmeStdSolidLoftSectionsFeatureAPI::IsCut(PmeHFeature hFeature, bool & isCut)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hFeature);
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hFeature);	
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pFeature->IsInstanceOf(PME_RUNTIME_TYPE(PmeStdSolidLoftSectionsFeature)));
	PmeStdSolidLoftSectionsFeature * pStdSolidLoftSectionsFeature = static_cast<PmeStdSolidLoftSectionsFeature *>(pFeature);

	isCut = pStdSolidLoftSectionsFeature->IsCut();
}