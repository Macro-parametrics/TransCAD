#include "stdafx.h"
#include ".\PmeStdSolidSphereFeatureAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeStdSolidSphereFeature.h"
#include ".\PmeFeatures.h"
#include ".\PmeSolid.h"
#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"

void PmeStdSolidSphereFeatureAPI::Create
(
	PmeHPart hPart
	, const MrPosition & location
	, double radius
	, PmeHFeature & hFeature
)
{
	PmePart * pPart = PME_HANDLE2PART(hPart);
	PmeThrowExceptionIf<PmeArgumentNullException>(!pPart);
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pPart->IsInstanceOf(PME_RUNTIME_TYPE(PmePart)));
	
	PmeFeatures * pFeatures = pPart->GetFeatures();

	PmeStdSolidSphereFeature * pFeature = new PmeStdSolidSphereFeature(pPart, location, radius);
	pFeature->GiveDefaultName();

	pFeatures->Add(pFeature);
	pPart->UpdateLast();

	hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeHUpdateInfo hUpdatedFeatures = 0;
	PmeUpdateInfoAPI::Create(hUpdatedFeatures);

	PmeUpdateInfoItem infoItem;
	infoItem.hItem = hFeature;
	infoItem.state = PmeUpdateState_Add;

	PmeUpdateInfoAPI::AddItem(hUpdatedFeatures, infoItem);
	PmePartAPI::FireFeaturesUpdatedEvent(hPart, hUpdatedFeatures);
	PmeUpdateInfoAPI::Delete(hUpdatedFeatures);

	PmeHExplicitModelObject hSolid = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetSolid());

	PmeHUpdateInfo hUpdatedExplicitModel = 0;
	PmeUpdateInfoAPI::Create(hUpdatedExplicitModel);

	infoItem.hItem = hSolid;
	infoItem.state = PmeUpdateState_Update;

	PmeUpdateInfoAPI::AddItem(hUpdatedExplicitModel, infoItem);
	PmePartAPI::FireExplicitModelUpdatedEvent(hPart, hUpdatedExplicitModel);
	PmeUpdateInfoAPI::Delete(hUpdatedExplicitModel);
}