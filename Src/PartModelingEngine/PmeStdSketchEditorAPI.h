#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeSamePointsType.h"

class PME_API PmeStdSketchEditorAPI
{
public:
    static void Close(PmeHStdSketchEditor & hEditor);

	static void CreateLine(PmeHStdSketchEditor hEditor, const CString & name, double startX, double startY, double endX, double endY, PmeHStdSketchGeometry & hLine);
	static void CreateCenterline(PmeHStdSketchEditor hEditor, const CString & name, double startX, double startY, double endX, double endY, PmeHStdSketchGeometry & hCenterline);
	static void CreateCircle(PmeHStdSketchEditor hEditor, const CString & name, double centerX, double centerY, double radius, PmeHStdSketchGeometry & hCircle);
	static void CreateCircularArc(PmeHStdSketchEditor hEditor, const CString & name, double centerX, double centerY, double radius, double startAngle, double endAngle, PmeHStdSketchGeometry & hArc);
	static void CreateCircularArcFromCenterStartEnd(PmeHStdSketchEditor hEditor, const CString & name, double centerX, double centerY, double startX, double startY, double endX, double endY, PmeHStdSketchGeometry & hArc);
	static void CreateCircularArcFrom3Points(PmeHStdSketchEditor hEditor, const CString & name, double startX, double startY, double intermediateX, double intermediateY, double endX, double endY, PmeHStdSketchGeometry & hArc);

	static void GetPoints(PmeHStdSketchGeometry hLine, PmeHStdSketchGeometry & hStartPoint, PmeHStdSketchGeometry & hEndPoint);

	static void CreateCoincident(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hFirstGeometry, PmeSamePointsType firstType, PmeHReference hSecondGeometry, PmeSamePointsType secondType, PmeHStdSketchConstraint & hConstraint);
	static void CreatePerpendicular(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hReferenceEdit, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint);
	static void CreateParallel(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hReferenceEdit, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint);
	static void CreateHorizontal(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint);
	static void CreateVertical(PmeHStdSketchEditor hEditor, const CString & name, PmeHReference hTarget, PmeHStdSketchConstraint & hConstraint);
	static void DeleteItemByName(PmeHStdSketchEditor hEditor, CString & name);
};