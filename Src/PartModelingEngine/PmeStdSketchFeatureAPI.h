#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchFeatureAPI
{
public:
    static void Create(PmeHPart hPart, const CString & name, PmeHReference hSketchPlane, PmeHFeature & hFeature);

	static void OpenEditor(PmeHFeature hFeature, PmeHStdSketchEditor & hEditor);
	static void OpenEditor(PmeHFeature hFeature, bool activateDcm, PmeHStdSketchEditor & hEditor);

	static void GetSketchPlane(PmeHFeature hFeature, PmeHReference & hSketchPlane);

	static void SetCoordinateSystem(PmeHFeature hFeature, MrAxis2 coordinateSystem);
	static void GetCoordinateSystem(PmeHFeature hFeature, MrAxis2 & coordinateSystem);

	static void GetOrigin(PmeHFeature hFeature, PmeHStdSketchOrigin & hOrigin);
	static void GetHDirection(PmeHFeature hFeature, PmeHStdSketchHDirection & hHDirection);
	static void GetVDirection(PmeHFeature hFeature, PmeHStdSketchVDirection & hVDirection);

	static void IsInversed(PmeHFeature hFeature, bool & isInversed);
	static void HasCenterLine(PmeHFeature hFeature, bool & hasCenterLine);

	static void GetGeometries(PmeHFeature hFeature, PmeHStdSketchGeometries & hGeometries);
	static void GetConstraints(PmeHFeature hFeature, PmeHStdSketchConstraints & hConstraints);
	static void DeleteByName(PmeHFeature hFeature, CString & name);
};