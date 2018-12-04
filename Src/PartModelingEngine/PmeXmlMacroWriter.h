#pragma once

#include <fstream>
#include ".\PmeHandle.h"


class PmeXmlMacroWriter
{
public:
	PmeXmlMacroWriter(PmeHPart hPart, CString filename);
	PmeXmlMacroWriter(CString filename);
	~PmeXmlMacroWriter(void);

	void Save(void);

	void WriteHeader(void);
	void WriteParts(void);
	void WriteFooter(void);

	PmeHPart GetPart() const { return m_hPart; }
	void SetPart(PmeHPart val) { m_hPart = val; }

private:
	void WriteFeatures(void);

	void WriteStdSketchSketch(PmeHFeature hFeature);
	void WriteSketchCoordinateSystem(PmeHFeature hFeature);
	void WriteBoolean(bool isTrue);

	void WriteSolidProtrusionExtrude(PmeHFeature hFeature);
	void WriteSolidCutExtrude(PmeHFeature hFeature);
	void WriteSolidFilletConstant(PmeHFeature hFeature);
	void WriteSolidChamfer(PmeHFeature hFeature);
	void WriteSolidProtrusionSweep(PmeHFeature hFeature);
	void WriteSolidProtrusionRevolve(PmeHFeature hFeature);
	void WriteSolidCutRevolve(PmeHFeature hFeature);
	void WriteSolidOperatePatternRectangular(PmeHFeature hFeature);
	void WriteSolidOperatePatternCircular(PmeHFeature hFeature);
	void WriteSolidHoleCounterbored(PmeHFeature hFeature);
	void WriteSolidHoleCountersunk(PmeHFeature hFeature);
	void WriteDatumPlaneOffset(PmeHFeature hFeature);
	void WriteSolidLoftSections(PmeHFeature hFeature);
	void WriteSolidCutSweep(PmeHFeature hFeature);
	void WriteSolidHoleSimple(PmeHFeature hFeature);
	void WriteSolidShell(PmeHFeature hFeature);
	void WriteSolidDraft(PmeHFeature hFeature);
	void WriteSolidOffset(PmeHFeature hFeature);
	void WriteSolidImportedBrep(PmeHFeature hFeature);

	CString WriteReference(PmeHReference hReference);
	void WriteResultObjectName(CString name);
	void WriteCoordinates(double x, double y, double z);
	void WriteSketchGeometries(PmeHFeature hFeature);
	void WriteStdSketchLine(PmeHStdSketchGeometry hGeometry);
	void WriteStdSketchCircle(PmeHStdSketchGeometry hGeometry);
	void WriteStdSketchCircularArc(PmeHStdSketchGeometry hGeometry);
	void WriteStdSketchCenterline(PmeHStdSketchGeometry hGeometry);

	void WriteSketchConstraints(PmeHFeature hFeature);
	void WriteStdSketchCoincidentSamePoints(PmeHStdSketchConstraint hConstraint);
	void WriteStdSketchPerpendicular(PmeHStdSketchConstraint hConstraint);
	void WriteStdSketchParallel(PmeHStdSketchConstraint hConstraint);
	void WriteStdSketchHorizontal(PmeHStdSketchConstraint hConstraint);
	void WriteStdSketchVertical(PmeHStdSketchConstraint hConstraint);

private:
	PmeHPart m_hPart;

	std::ofstream m_fout;

	int m_constraintCount;
};
