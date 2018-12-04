#pragma once

#define PME_UPDATE_FEATURE(part, feature, ustate) \
{ \
    PmeHUpdateInfo hUpdatedFeatures = 0; \
	PmeUpdateInfoAPI::Create(hUpdatedFeatures); \
	PmeUpdateInfoItem infoItem; \
	infoItem.hItem = feature; \
	infoItem.state = ustate; \
	PmeUpdateInfoAPI::AddItem(hUpdatedFeatures, infoItem); \
	PmePartAPI::FireFeaturesUpdatedEvent(part, hUpdatedFeatures); \
	PmeUpdateInfoAPI::Delete(hUpdatedFeatures); \
}

#define PME_UPDATE_EXPLICITMODELOBJECT(part, object, ustate) \
{\
	PmeHUpdateInfo hUpdatedExplicitModel = 0; \
	PmeUpdateInfoAPI::Create(hUpdatedExplicitModel); \
	PmeUpdateInfoItem infoItem; \
	infoItem.hItem = object; \
	infoItem.state = ustate; \
	PmeUpdateInfoAPI::AddItem(hUpdatedExplicitModel, infoItem); \
	PmePartAPI::FireExplicitModelUpdatedEvent(part, hUpdatedExplicitModel); \
	PmeUpdateInfoAPI::Delete(hUpdatedExplicitModel); \
}

#define PME_UPDATE_PART(assembly, component, ustate) \
{ \
	PmeHUpdateInfo hUpdatedParts = 0; \
	PmeUpdateInfoAPI::Create(hUpdatedParts); \
	PmeUpdateInfoItem infoItem; \
	infoItem.hItem = component; \
	infoItem.state = ustate; \
	PmeUpdateInfoAPI::AddItem(hUpdatedParts, infoItem); \
	PmeAssemblyAPI::FirePartsUpdatedEvent(assembly, hUpdatedParts); \
	PmeUpdateInfoAPI::Delete(hUpdatedParts); \
}

#define PME_UPDATE_COMPONENT(assembly, component, ustate) \
{ \
	PmeHUpdateInfo hUpdatedComponents = 0; \
	PmeUpdateInfoAPI::Create(hUpdatedComponents); \
	PmeUpdateInfoItem infoItem; \
	infoItem.hItem = component; \
	infoItem.state = ustate; \
	PmeUpdateInfoAPI::AddItem(hUpdatedComponents, infoItem); \
	PmeAssemblyAPI::FireComponentsUpdatedEvent(assembly, hUpdatedComponents); \
	PmeUpdateInfoAPI::Delete(hUpdatedComponents); \
}

#define PME_UPDATE_ASSEMBLY(assembly, newassembly, ustate) \
{ \
	PmeHUpdateInfo hUpdatedAssemblies = 0; \
	PmeUpdateInfoAPI::Create(hUpdatedAssemblies); \
	PmeUpdateInfoItem infoItem; \
	infoItem.hItem = newassembly; \
	infoItem.state = ustate; \
	PmeUpdateInfoAPI::AddItem(hUpdatedAssemblies, infoItem); \
	PmeAssemblyAPI::FirePartsUpdatedEvent(assembly, hUpdatedAssemblies); \
	PmeUpdateInfoAPI::Delete(hUpdatedAssemblies); \
}

#define PME_UPDATE_CONSTRAINT( assembly, newconstraint, ustate) \
{ \
	PmeHUpdateInfo hUpdatedConstraints = 0; \
	PmeUpdateInfoAPI::Create(hUpdatedConstraints); \
	PmeUpdateInfoItem infoItem; \
	infoItem.hItem = newconstraint; \
	infoItem.state = ustate; \
	PmeUpdateInfoAPI::AddItem(hUpdatedConstraints, infoItem); \
	PmeAssemblyAPI::FirePartsUpdatedEvent(assembly, hUpdatedConstraints); \
	PmeUpdateInfoAPI::Delete(hUpdatedConstraints); \
}