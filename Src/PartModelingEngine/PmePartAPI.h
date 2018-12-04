#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

struct IPmePartEventListener
{
	virtual void OnFeaturesUpdated(PmeHUpdateInfo hInfo) = 0;
	virtual void OnExplicitModelUpdated(PmeHUpdateInfo hInfo) = 0;
};

class PME_API PmePartAPI
{
public:
    static void Create(PmeHPart & hPart);
    static void Delete(PmeHPart & hPart);
	static void ClearBody(PmeHPart & hPart);

    static void UpdateAll(PmeHPart hPart);

	static void GetFeatures(PmeHPart hPart, PmeHFeatures & hFeatures);
	static void GetExplicitModel(PmeHPart hPart, PmeHExplicitModel & hExplicitModel);
	
	static void RegisterEventListener(PmeHPart hPart, IPmePartEventListener * pListener);
	static void UnregisterEventListener(PmeHPart hPart, IPmePartEventListener * pListener);

	static void FireFeaturesUpdatedEvent(PmeHPart hPart, PmeHUpdateInfo hInfo);
	static void FireExplicitModelUpdatedEvent(PmeHPart hPart, PmeHUpdateInfo hInfo);

	static void SelectFeatureByName(PmeHPart hPart, CString name, PmeHReference & hReference);
	static void SelectObjectByName(PmeHPart hPart, CString name, PmeHReference & hReference);
	static void SelectBrepByName(PmeHPart hPart, CString name, PmeHReference & hReference);
	static void SelectPlaneByAxis(PmeHPart hPart, const MrAxis2 & axis2, PmeHReference & hReference);
	static void SelectCurveBy3Points(PmeHPart hPart, const MrPosition & start, const MrPosition & end, const MrPosition & pointOnCurve, PmeHReference & hReference);
	static void SelectCurveByPoint(PmeHPart hPart, const MrPosition & pointOnCurve, PmeHReference & hReference);

	static void SelectSketchGeometryByName(PmeHPart hPart, CString name, PmeHReference & hReference);	// 2009.10.29, Suchul Shin

	static void SaveAsXmlMacro(PmeHPart hPart, CString filename);


	static void LoadXmlMacro(CString filename, PmeHPart & hPart);
	static void LoadBrepFile(CString filename, PmeHPart & hPart);

	static void SetName(PmeHPart hPart, CString name);
	static void GetName(PmeHPart hPart, CString & name);
	static void GetUniqueName(PmeHPart hPart, CString & name);

	static void SetParentName(PmeHPart hPart, CString name);
	static void GetParentName(PmeHPart hPart, CString & name);

	static void IsBrepPart(PmeHPart hPart, BOOL& result);
	
	static void GetPlacement(PmeHPart hPart, MrAxis2 & placement);
	static void SetPlacement(PmeHPart& hPart, MrAxis2  placement);
	static void GetModellingMatrix(PmeHPart hPart, float* transform);
	//static void GetGlobalModellingMatrix(PmeHPart hPart, float* transform);

	static void Undo(PmeHPart hPart);
	static void Redo(PmeHPart hPart);
};