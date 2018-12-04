#pragma once
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchCenterline.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchCircularArc.h"
class PmeReference;
class PmeSketch;

class PmeSketchUtility
{
public:
	static PmeSketch * GetSketch(PmeReference * pReference);
	static void CreateWire(PmeReference * pReference, BODY **& ppWires, int & nWire);
	static void CreateWire(PmeReference * pReference, BODY *& pWire);
	static MrAxis2 GetCoordinateSystem(PmeReference * pReference);
	static MrAxis1 GetRevolutionAxis(PmeReference * pReference);
	static EDGE * CreateEdgeFromGeometry(PmeStdSketchGeometry * pGeometry);
	static EDGE * CreateEdgeFromSketchLine(PmeStdSketchLine * pLine);
	static EDGE * CreateEdgeFromSketchCircle(PmeStdSketchCircle * pCircle);
	static EDGE * CreateEdgeFromSketchCircularArc(PmeStdSketchCircularArc * pArc);
};