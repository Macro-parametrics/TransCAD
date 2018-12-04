#pragma once

#include <fstream>
#include <map>
#include ".\PmeHandle.h"
#include ".\PmeStdExtrudeEndType.h"
#include ".\PmeStdRevolveEndType.h"
#include ".\PmeChamferType.h"
#include ".\PmePropagationType.h"
#include ".\PmeSamePointsType.h"
#include "PmeAssembly.h"

class PmeXmlMacroReader
{
public:
	PmeXmlMacroReader(PmeHPart hPart, CString filename);
	PmeXmlMacroReader(PmeAssembly* , CString );
	~PmeXmlMacroReader(void);

	void Read(void);
	void ReadAssembly(void);

private:
	void ReadPartInfo(MSXML2::IXMLDOMElementPtr spDOMElement);
	void ReadCommands(MSXML2::IXMLDOMElementPtr spDOMElement);
	void ReadCommand(MSXML2::IXMLDOMNodePtr spDOMNode);

	CString GetChildStr(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index);
	void GetCoordinateValues(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index, double & x, double & y, double & z);
	double GetChildValue(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index);
	bool GetChildBoolean(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index);
	MrAxis2 GetCoordinateSystem(MSXML2::IXMLDOMNodePtr spDOMNode);

	void AddReference(CString name, PmeHReference hReference);
	PmeHReference FindReference(CString name);

	void ReadSelectObject(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSketchOpen(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSketchClose(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSketchCreate2DLine2Points(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSketchCreate2DCenterline2Points(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSketchCreate2DCircleCenterPoint(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSketchCreate2DArcCenterEnds(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadConstraintsCreateConstraintCoincidentSamePoints(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadConstraintsCreateConstraintPerpendicular(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadConstraintsCreateConstraintParallel(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadConstraintsCreateConstraintHorizontal(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadConstraintsCreateConstraintVertical(MSXML2::IXMLDOMNodePtr spDOMNode);

	PmeSamePointsType ConvertSketchConstraintCoincidentSamePointsType(CString type);

	void ReadSolidCreateProtrusionExtrude(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidCreateCutExtrude(MSXML2::IXMLDOMNodePtr spDOMNode);

	PmeStdExtrudeEndType ConvertSolidExtrudeEndType(CString type);

	void ReadSolidOperateFilletingFilletConstant(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidOperateFilletingChamfer(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSolidCreateProtrusionSweep(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSolidCreateProtrusionRevolve(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidCreateCutRevolve(MSXML2::IXMLDOMNodePtr spDOMNode);
	PmeStdRevolveEndType ConvertSolidRevolveEndType(CString type);

	PmeChamferType ConvertChamferType(CString type);
	PmePropagationType ConvertPropagationType(CString type);

	void ReadSolidOperatePatternRectangular(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidOperatePatternCircular(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSolidCreateHoleCouneterbored(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidCreateHoleCounetersunk(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadDatumPlaneOffset(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadDatumPlaneOffset2(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSolidCreateLoftSections(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSolidCreateCutSweep(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidCreateHoleSimple(MSXML2::IXMLDOMNodePtr spDOMNode);

	void ReadSolidCreateShell(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidCreateDraft(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidCreateOffset(MSXML2::IXMLDOMNodePtr spDOMNode);
	void ReadSolidImportBrep(MSXML2::IXMLDOMNodePtr spDOMNode);

private:
	PmeHPart m_hPart;
	PmeAssembly* m_pAssembly;
	CString m_filename;

	std::map<CString, PmeHReference> m_mapNameReference;

	PmeHStdSketchEditor m_hSketchEditor;
};
