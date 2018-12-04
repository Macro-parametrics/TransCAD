#pragma once

class AssemDocument;

HC_KEY AssemRenderComponent(PmeHComponent hComponent, AssemDocument * pDocument);

HC_KEY AssemRenderSubComponent(PmeHComponent hComponent, AssemDocument * pDocument);
HC_KEY AssemRenderSubPart(PmeHPart hPart, HC_KEY hOwnerKey, AssemDocument * pDocument);

HC_KEY AssemRenderSolid(PmeHExplicitModelObject hObject, HC_KEY hOwnerKey);

void AssemRenderDefaultDatumPlane(PmeHExplicitModelObject hObject);
void AssemRenderDatumPlane(PmeHExplicitModelObject hObject, HC_KEY hOwnerKey);

void AssemDeleteRenderingObject(PmeHComponent hComponent);

