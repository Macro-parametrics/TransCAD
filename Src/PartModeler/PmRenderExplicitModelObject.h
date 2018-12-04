#pragma once

class PmDocument;

HC_KEY PmRenderExplicitModelObject(PmeHExplicitModelObject hObject, PmDocument * pDocument);
void PmDeleteRenderingObject(HC_KEY hKey);
void PmClearSubKeyMap(void);

HC_KEY PmRenderSolid(PmeHExplicitModelObject hObject);
HC_KEY PmRenderDatumPlane(PmeHExplicitModelObject hObject);
HC_KEY PmRenderOffsetDatumPlane(PmeHExplicitModelObject hObject);
HC_KEY PmRenderSketch(PmeHExplicitModelObject hObject);
void PmRenderSketchLine(PmeHStdSketchGeometry hGeometry);
void PmRenderSketchCenterline(PmeHStdSketchGeometry hGeometry);
void PmRenderSketchCircle(PmeHStdSketchGeometry hGeometry);
void PmRenderSketchCircularArc(PmeHStdSketchGeometry hGeometry);