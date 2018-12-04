#include "StdAfx.h"
#include ".\pmexmlmacroreader.h"
#include ".\PmeAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeFileNotFoundException.h"
#include "PmeHandleMacro.h"
#include "PmeComponent.h"
#include "PmePart.h"
#include "PmeUtility.h"

#include <vector>

using namespace std;

PmeXmlMacroReader::PmeXmlMacroReader(PmeHPart hPart, CString filename)
: m_hPart(hPart)
, m_filename(filename)
, m_hSketchEditor(0)
{
}

PmeXmlMacroReader::PmeXmlMacroReader(PmeAssembly* pAssembly, CString filename)
	:m_pAssembly(pAssembly)
	, m_filename(filename)
	, m_hSketchEditor(0)
{
}

PmeXmlMacroReader::~PmeXmlMacroReader(void)
{
}

void PmeXmlMacroReader::Read(void)
{
	HRESULT hr;

	MSXML2::IXMLDOMDocumentPtr spDOMDoc;
	
	hr = CoInitialize(NULL);
	hr = spDOMDoc.CreateInstance("msxml2.domdocument");

	_variant_t varXml(m_filename);
	_variant_t varOut((bool)TRUE);
	
	varOut = spDOMDoc->load(varXml);

	PmeThrowExceptionIf<PmeFileNotFoundException>(varOut.boolVal == VARIANT_FALSE);

	MSXML2::IXMLDOMElementPtr spDOMElement = spDOMDoc->documentElement;
	
	USES_CONVERSION;
	CString strModel;
	strModel.Format("%s", const_cast<LPCTSTR>(OLE2T(spDOMElement->nodeName)));

	if(strModel != _T("MACRO_PARAMETRICS"))
	{
		TRACE(_T("This is an invalid file.\n"));
	}
	else
	{
        ReadCommands(spDOMElement);
	}

	CoUninitialize();
}

void PmeXmlMacroReader::ReadAssembly(void)
{
	HRESULT hr;

	MSXML2::IXMLDOMDocumentPtr spDOMDoc;

	hr = CoInitialize(NULL);
	hr = spDOMDoc.CreateInstance("msxml2.domdocument");

	_variant_t varXml(m_filename);
	_variant_t varOut((bool)TRUE);

	varOut = spDOMDoc->load(varXml);

	PmeThrowExceptionIf<PmeFileNotFoundException>(varOut.boolVal == VARIANT_FALSE);

	MSXML2::IXMLDOMElementPtr spDOMElement = spDOMDoc->documentElement;
	    
	USES_CONVERSION;
	CString strModel;
	strModel.Format("%s", const_cast<LPCTSTR>(OLE2T(spDOMElement->nodeName)));

	if(strModel != _T("MACRO_PARAMETRICS"))
	{
		TRACE(_T("This is an invalid file.\n"));
	}
	else
	{
		ReadPartInfo(spDOMElement);
	}

	CoUninitialize();
}

void PmeXmlMacroReader::ReadPartInfo(MSXML2::IXMLDOMElementPtr spDOMElement)
{
	MSXML2::IXMLDOMNodeListPtr spDOMNodeList = spDOMElement->childNodes;	

	CString command,strValue;
	USES_CONVERSION;
	

	for(int i = 0; i < spDOMNodeList->length; i ++)
	{
		MSXML2::IXMLDOMNodePtr spDOMNode = spDOMNodeList->Getitem(i);
		
		MSXML2::IXMLDOMNodeListPtr spDOMNodeList2 = spDOMNode->childNodes;

		PmePartAPI::Create(m_hPart);
		PmePartAPI::SetParentName(m_hPart,GetChildStr(spDOMNodeList2,0));
		PmePartAPI::SetName(m_hPart,GetChildStr(spDOMNodeList2,1));
		//if brep part 이면 brep 파일 위치 읽어서 읽어야 한다.......
		for(int j = 0; j < spDOMNodeList2->length; j ++)
		{
			MSXML2::IXMLDOMNodePtr spDOMNode2 = spDOMNodeList2->Getitem(j);
			command.Format("%s", const_cast<LPCTSTR>(OLE2T(spDOMNode2->nodeName)));
			strValue.Format("%s",spDOMNode2->nodeValue.bstrVal);

			if(command == _T("ParentName"))
			{
			}
			else if(command == _T("PartName") )
			{
			}
			else
			{
				ReadCommand(spDOMNodeList2->Getitem(j));
			}
		}

		PmePart* pPart = PME_HANDLE2PART(m_hPart);
		PmeComponent* pComp = new PmeComponent(pPart);
				
		m_pAssembly->AddComponent(pComp);
		
		PmeHAssembly hAssembly = PME_ASSEMBLY2HANDLE(m_pAssembly);
		PmeComponent * pComponent = new PmeComponent(pPart);
		
		PmeHComponent hComponent = PME_COMPONENT2HANDLE(pComp);

		PME_UPDATE_PART(hAssembly, hComponent, PmeUpdateState_Add);
	}	

}

CString PmeXmlMacroReader::GetChildStr(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index)
{
	_variant_t value;

	value = spDOMNodeList->Getitem(index)->firstChild->nodeValue;	

	return CString(value.bstrVal);
}

void PmeXmlMacroReader::GetCoordinateValues(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index, double & x, double & y, double & z)
{	
	_variant_t value;

	value = spDOMNodeList->Getitem(index)->childNodes->Getitem(0)->firstChild->nodeValue;
	CString xValue(value.bstrVal);
	x = atof(xValue);

	value = spDOMNodeList->Getitem(index)->childNodes->Getitem(1)->firstChild->nodeValue;
	CString yValue(value.bstrVal);
	y = atof(yValue);

	value = spDOMNodeList->Getitem(index)->childNodes->Getitem(2)->firstChild->nodeValue;
	CString zValue(value.bstrVal);
	z = atof(zValue);
}

double PmeXmlMacroReader::GetChildValue(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index)
{
	_variant_t value;
	value = spDOMNodeList->Getitem(index)->firstChild->nodeValue;
	CString nodeValue(value.bstrVal);

	return atof(nodeValue);
}

bool PmeXmlMacroReader::GetChildBoolean(MSXML2::IXMLDOMNodeListPtr spDOMNodeList, int index)
{
	_variant_t value;
	value = spDOMNodeList->Getitem(index)->firstChild->nodeValue;
	CString nodeValue(value.bstrVal);

	if(nodeValue == _T("1"))
		return true;
	else
		return false;
}

MrAxis2 PmeXmlMacroReader::GetCoordinateSystem(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	double originX, originY, originZ;
	double dir1X, dir1Y, dir1Z;
	double dir2X, dir2Y, dir2Z;

	GetCoordinateValues(spChildNodes, 1, originX, originY, originZ);
	GetCoordinateValues(spChildNodes, 2, dir1X, dir1Y, dir1Z);
	GetCoordinateValues(spChildNodes, 3, dir2X, dir2Y, dir2Z);
	
	MrPosition origin(originX, originY, originZ);
	MrDirection xDir(dir1X, dir1Y, dir1Z);
	MrDirection yDir(dir2X, dir2Y, dir2Z);
	MrDirection zDir(MrMath::Cross(xDir, yDir));

	return MrAxis2(origin, zDir, xDir);
}

void PmeXmlMacroReader::AddReference(CString name, PmeHReference hReference)
{
	m_mapNameReference[name] = hReference;
}

PmeHReference PmeXmlMacroReader::FindReference(CString name)
{
	if(m_mapNameReference.find(name) == m_mapNameReference.end())
		return 0;

	return m_mapNameReference[name];
}

void PmeXmlMacroReader::ReadCommands(MSXML2::IXMLDOMElementPtr spDOMElement)
{
	MSXML2::IXMLDOMNodeListPtr spDOMNodeList = spDOMElement->childNodes;	
	
	//PmePartAPI::Create(m_hPart);
	//PmePartAPI::RegisterEventListener(m_hPart, this);	

	for(int i = 0; i < spDOMNodeList->length; i ++)
	{
		ReadCommand(spDOMNodeList->Getitem(i));
	}	
}

void PmeXmlMacroReader::ReadCommand(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	CString command;
	USES_CONVERSION;
	command.Format("%s", const_cast<LPCTSTR>(OLE2T(spDOMNode->nodeName)));

	if(command == _T("SELECT_Object"))
	{
		ReadSelectObject(spDOMNode);
	}
	else if(command == _T("SKETCH_Open"))
	{
		ReadSketchOpen(spDOMNode);
	}
	else if(command == _T("SKETCH_Close"))
	{
		ReadSketchClose(spDOMNode);
	}
	else if(command == _T("SKETCH_Create_2D_Line_2Points"))
	{
		ReadSketchCreate2DLine2Points(spDOMNode);
	}
	else if(command == _T("SKETCH_Create_2D_Centerline"))
	{
		ReadSketchCreate2DCenterline2Points(spDOMNode);
	}
	else if(command == _T("SKETCH_Create_2D_Circle_CenterPoint"))
	{
		ReadSketchCreate2DCircleCenterPoint(spDOMNode);
	}
	else if(command == _T("SKETCH_Create_2D_Arc_CenterEnds"))
	{
		ReadSketchCreate2DArcCenterEnds(spDOMNode);
	}
	else if(command == _T("CONSTRAINTS_Create_Constraint_Coincident_SamePoints"))
	{
		ReadConstraintsCreateConstraintCoincidentSamePoints(spDOMNode);
	}

	else if(command == _T("CONSTRAINTS_Create_Constraint_Perpendicular"))
	{
		ReadConstraintsCreateConstraintPerpendicular(spDOMNode);
	}

	else if(command == _T("CONSTRAINTS_Create_Constraint_Parallel"))
	{
		ReadConstraintsCreateConstraintParallel(spDOMNode);
	}

	else if(command == _T("CONSTRAINTS_Create_Constraint_Horizontal"))
	{
		ReadConstraintsCreateConstraintHorizontal(spDOMNode);
	}

	else if(command == _T("CONSTRAINTS_Create_Constraint_Vertical"))
	{
		ReadConstraintsCreateConstraintVertical(spDOMNode);
	}

	else if(command == _T("SOLID_Create_Protrusion_Extrude"))
	{
		ReadSolidCreateProtrusionExtrude(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Cut_Extrude"))
	{
		ReadSolidCreateCutExtrude(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Protrusion_Sweep"))
	{
		ReadSolidCreateProtrusionSweep(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Protrusion_Revolve"))
	{
		ReadSolidCreateProtrusionRevolve(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Cut_Revolve"))
	{
		ReadSolidCreateCutRevolve(spDOMNode);
	}
	else if(command == _T("SOLID_Operate_Filleting_Fillet_Constant"))
	{
		ReadSolidOperateFilletingFilletConstant(spDOMNode);
	}
	else if(command == _T("SOLID_Operate_Filleting_Chamfer"))
	{
		ReadSolidOperateFilletingChamfer(spDOMNode);
	}
	else if(command == _T("SOLID_Operate_Pattern_Rectangular"))
	{
		ReadSolidOperatePatternRectangular(spDOMNode);
	}
	else if(command == _T("SOLID_Operate_Pattern_Circular"))
	{
		ReadSolidOperatePatternCircular(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Hole_Counterbored"))
	{
		ReadSolidCreateHoleCouneterbored(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Hole_Countersunk"))
	{
		ReadSolidCreateHoleCounetersunk(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Hole_Simple"))
	{
		ReadSolidCreateHoleSimple(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Loft_Sections"))
	{
		ReadSolidCreateLoftSections(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Cut_Sweep"))
	{
		ReadSolidCreateCutSweep(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Shell"))
	{
		ReadSolidCreateShell(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Draft"))
	{
		ReadSolidCreateDraft(spDOMNode);
	}
	else if(command == _T("SOLID_Create_Offset"))
	{
		ReadSolidCreateOffset(spDOMNode);
	}
	else if(command == _T("SOLID_Import_Brep"))
	{
		ReadSolidImportBrep(spDOMNode);
	}
	else if(command == _T("CONSTRAINTS_Create_3DReference_OffsetPlanes"))
	{
		ReadDatumPlaneOffset(spDOMNode);
	}
	else if(command == _T("CONSTRAINTS_Create_3DReference_OffsetPlanes2"))
	{
		ReadDatumPlaneOffset2(spDOMNode);
	}
	else if(command == _T("CONSTRAINTS_Create_3DReference_CoordSys"))
	{
		// 실제 내용은 ReadSketchOpen() 안에서 처리된다.
	}

	else
	{
		TRACE(_T("Invalid command.\n"));
	}
}

void PmeXmlMacroReader::ReadSelectObject(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name, type, entity;
	
	name = GetChildStr(spChildNodes, 0);
	type = GetChildStr(spChildNodes, 1);
	entity = GetChildStr(spChildNodes, 2);

	PmeHReference hReference = 0;

	if(type == _T("OBJECT"))
	{
		PmePartAPI::SelectObjectByName(m_hPart, entity, hReference);
	}
	else if(type == _T("FEATURE"))
	{
		PmePartAPI::SelectFeatureByName(m_hPart, entity, hReference);
	}
	else if(type == _T("FACE") || type == _T("EDGE"))
	{
		PmePartAPI::SelectBrepByName(m_hPart, entity, hReference);
	}

	ASSERT(hReference);

	AddReference(name, hReference);
}

void PmeXmlMacroReader::ReadSketchOpen(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name, referenceName;
	
	name = GetChildStr(spChildNodes, 0);
	referenceName = GetChildStr(spChildNodes, 1);

	PmeHReference hReference = FindReference(referenceName);
	if(!hReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hSketchFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, name, hReference, hSketchFeature);
	ASSERT(hSketchFeature);

	MSXML2::IXMLDOMNodePtr spDOMNodeNext = spDOMNode->GetnextSibling();
	MrAxis2 axis = GetCoordinateSystem(spDOMNodeNext);

	PmeStdSketchFeatureAPI::SetCoordinateSystem(hSketchFeature, axis);

	PmeStdSketchFeatureAPI::OpenEditor(hSketchFeature, false, m_hSketchEditor);
	ASSERT(m_hSketchEditor);
}

void PmeXmlMacroReader::ReadSketchClose(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
		
	name = GetChildStr(spChildNodes, 0);

	if(m_hSketchEditor)
        PmeStdSketchEditorAPI::Close(m_hSketchEditor);

	m_hSketchEditor = 0;
}

void PmeXmlMacroReader::ReadSketchCreate2DLine2Points(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;	
	double startX, startY, startZ;
	double endX, endY, endZ;

	name = GetChildStr(spChildNodes, 0);	
	GetCoordinateValues(spChildNodes, 1, startX, startY, startZ);
	GetCoordinateValues(spChildNodes, 2, endX, endY, endZ);

	PmeHStdSketchGeometry hLine = 0;
	PmeStdSketchEditorAPI::CreateLine(m_hSketchEditor, name, startX, startY, endX, endY, hLine);
}

void PmeXmlMacroReader::ReadSketchCreate2DCenterline2Points(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;	
	double startX, startY, startZ;
	double endX, endY, endZ;

	name = GetChildStr(spChildNodes, 0);	
	GetCoordinateValues(spChildNodes, 1, startX, startY, startZ);
	GetCoordinateValues(spChildNodes, 2, endX, endY, endZ);

	PmeHStdSketchGeometry hLine = 0;
	PmeStdSketchEditorAPI::CreateCenterline(m_hSketchEditor, name, startX, startY, endX, endY, hLine);
}

void PmeXmlMacroReader::ReadSketchCreate2DCircleCenterPoint(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	double centerX, centerY, centerZ;
	double radius;	

	name = GetChildStr(spChildNodes, 0);
	GetCoordinateValues(spChildNodes, 1, centerX, centerY, centerZ);
	radius = GetChildValue(spChildNodes, 2);

	PmeHStdSketchGeometry hCircle = 0;
	PmeStdSketchEditorAPI::CreateCircle(m_hSketchEditor, name, centerX, centerY, radius, hCircle);
}

void PmeXmlMacroReader::ReadSketchCreate2DArcCenterEnds(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	double centerX, centerY, centerZ;
	double startX, startY, startZ;
	double endX, endY, endZ;
	CString rotationDirection;

	name = GetChildStr(spChildNodes, 0);
	GetCoordinateValues(spChildNodes, 1, centerX, centerY, centerZ);
	GetCoordinateValues(spChildNodes, 2, startX, startY, startZ);
	GetCoordinateValues(spChildNodes, 3, endX, endY, endZ);
	rotationDirection = GetChildStr(spChildNodes, 4);

	PmeHStdSketchGeometry hArc = 0;
	PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(m_hSketchEditor, name, centerX, centerY, startX, startY, endX, endY, hArc);
}

void PmeXmlMacroReader::ReadConstraintsCreateConstraintCoincidentSamePoints(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString firstObject;
	CString firstObjectType;
	CString secondObject;
	CString secondObjectType;

	name = GetChildStr(spChildNodes, 0);
	firstObject = GetChildStr(spChildNodes, 1);
	firstObjectType = GetChildStr(spChildNodes, 2);
	secondObject = GetChildStr(spChildNodes, 3);
	secondObjectType = GetChildStr(spChildNodes, 4);

	PmeHReference hReference1 = FindReference(firstObject);
	if(!hReference1)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHReference hReference2 = FindReference(secondObject);
	if(!hReference2)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHStdSketchConstraint hCoincident = 0;
	PmeStdSketchEditorAPI::CreateCoincident(m_hSketchEditor, name, hReference1, ConvertSketchConstraintCoincidentSamePointsType(firstObjectType), hReference2, ConvertSketchConstraintCoincidentSamePointsType(secondObjectType), hCoincident);
}

void PmeXmlMacroReader::ReadConstraintsCreateConstraintPerpendicular(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString referenceEdit;
	CString target;

	name = GetChildStr(spChildNodes, 0);
	referenceEdit = GetChildStr(spChildNodes, 1);
	target = GetChildStr(spChildNodes, 2);

	PmeHReference hReference1 = FindReference(referenceEdit);
	if(!hReference1)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHReference hReference2 = FindReference(target);
	if(!hReference2)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHStdSketchConstraint hPerpendicular = 0;
	PmeStdSketchEditorAPI::CreatePerpendicular(m_hSketchEditor, name, hReference1, hReference2, hPerpendicular);
}

void PmeXmlMacroReader::ReadConstraintsCreateConstraintParallel(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString referenceEdit;
	CString target;

	name = GetChildStr(spChildNodes, 0);
	referenceEdit = GetChildStr(spChildNodes, 1);
	target = GetChildStr(spChildNodes, 2);

	PmeHReference hReference1 = FindReference(referenceEdit);
	if(!hReference1)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHReference hReference2 = FindReference(target);
	if(!hReference2)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHStdSketchConstraint hParallel = 0;
	PmeStdSketchEditorAPI::CreateParallel(m_hSketchEditor, name, hReference1, hReference2, hParallel);
}

void PmeXmlMacroReader::ReadConstraintsCreateConstraintHorizontal(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString target;

	name = GetChildStr(spChildNodes, 0);
	target = GetChildStr(spChildNodes, 1);

	PmeHReference hReference1 = FindReference(target);
	if(!hReference1)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHStdSketchConstraint hHorizontal = 0;
	PmeStdSketchEditorAPI::CreateHorizontal(m_hSketchEditor, name, hReference1, hHorizontal);
}

void PmeXmlMacroReader::ReadConstraintsCreateConstraintVertical(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString target;

	name = GetChildStr(spChildNodes, 0);
	target = GetChildStr(spChildNodes, 1);

	PmeHReference hReference1 = FindReference(target);
	if(!hReference1)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHStdSketchConstraint hVertical = 0;
	PmeStdSketchEditorAPI::CreateVertical(m_hSketchEditor, name, hReference1, hVertical);
}

PmeSamePointsType PmeXmlMacroReader::ConvertSketchConstraintCoincidentSamePointsType(CString type)
{
	if(type == _T("StartPoint"))
		return PmeSamePointsType_StartPoint;
	else if(type == _T("EndPoint"))
		return PmeSamePointsType_EndPoint;
	else if(type == _T("CenterPoint"))
		return PmeSamePointsType_CenterPoint;
	else if(type == _T("Whole"))
		return PmeSamePointsType_Whole;

	return PmeSamePointsType_Whole;
}


PmeStdExtrudeEndType PmeXmlMacroReader::ConvertSolidExtrudeEndType(CString type)
{
	if(type == _T("Dimension"))
		return PmeStdExtrudeEndType_Blind;
	else if(type == _T("ThroughAll"))
		return PmeStdExtrudeEndType_ThroughAll;

	return PmeStdExtrudeEndType_Blind;
}

PmeStdRevolveEndType PmeXmlMacroReader::ConvertSolidRevolveEndType(CString type)
{
	if(type == _T("Dimension"))
		return PmeStdRevolveEndType_Blind;

	return PmeStdRevolveEndType_Blind;
}

PmeChamferType PmeXmlMacroReader::ConvertChamferType(CString type)
{
	if(type == _T("chamfer_length"))
		return PmeChamferType_Length;

	return PmeChamferType_Angle;
}

PmePropagationType PmeXmlMacroReader::ConvertPropagationType(CString type)
{
	if(type == _T("Minimal"))
		return PmePropagationType_Minimal;

	return PmePropagationType_Tangency;
}


void PmeXmlMacroReader::ReadSolidCreateProtrusionExtrude(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString profile;
	bool flip;
	CString startType, endType;
	double startLength, endLength;

	name = GetChildStr(spChildNodes, 0);	
	profile = GetChildStr(spChildNodes, 1);		
	startLength = GetChildValue(spChildNodes, 2);
	startType = GetChildStr(spChildNodes, 3);
	endLength = GetChildValue(spChildNodes, 4);
	endType = GetChildStr(spChildNodes, 5);
	flip = GetChildBoolean(spChildNodes, 6);

	PmeHReference hReference = FindReference(profile);
	if(!hReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hProtrusionExtrudeFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, name, hReference, startLength, ConvertSolidExtrudeEndType(startType), endLength, ConvertSolidExtrudeEndType(endType), flip, hProtrusionExtrudeFeature);	
	ASSERT(hProtrusionExtrudeFeature);
}

void PmeXmlMacroReader::ReadSolidCreateCutExtrude(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString profile;
	bool flip;
	CString startType, endType;
	double startLength, endLength;

	name = GetChildStr(spChildNodes, 0);	
	profile = GetChildStr(spChildNodes, 1);		
	startLength = GetChildValue(spChildNodes, 2);
	startType = GetChildStr(spChildNodes, 3);
	endLength = GetChildValue(spChildNodes, 4);
	endType = GetChildStr(spChildNodes, 5);
	flip = GetChildBoolean(spChildNodes, 6);

	PmeHReference hReference = FindReference(profile);
	if(!hReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hCutExtrudeFeature = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, name, hReference, startLength, ConvertSolidExtrudeEndType(startType), endLength, ConvertSolidExtrudeEndType(endType), flip, hCutExtrudeFeature);	
	ASSERT(hCutExtrudeFeature);
}

void PmeXmlMacroReader::ReadSolidCreateProtrusionSweep(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString profile;
	CString guideCurve;	

	name = GetChildStr(spChildNodes, 0);	
	profile = GetChildStr(spChildNodes, 1);
	guideCurve = GetChildStr(spChildNodes, 2);

	PmeHReference hProfileReference = FindReference(profile);
	if(!hProfileReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHReference hGuideCurveReference = FindReference(guideCurve);
	if(!hGuideCurveReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hProtrusionSweepFeature = 0;
	PmeStdSolidProtrusionSweepFeatureAPI::Create(m_hPart, name, hProfileReference, hGuideCurveReference, hProtrusionSweepFeature);	
	ASSERT(hProtrusionSweepFeature);
}

void PmeXmlMacroReader::ReadSolidCreateCutSweep(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString profile;
	CString guideCurve;	

	name = GetChildStr(spChildNodes, 0);	
	profile = GetChildStr(spChildNodes, 1);
	guideCurve = GetChildStr(spChildNodes, 2);

	PmeHReference hProfileReference = FindReference(profile);
	if(!hProfileReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHReference hGuideCurveReference = FindReference(guideCurve);
	if(!hGuideCurveReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hCutSweepFeature = 0;
	PmeStdSolidCutSweepFeatureAPI::Create(m_hPart, name, hProfileReference, hGuideCurveReference, hCutSweepFeature);	
	ASSERT(hCutSweepFeature);
}

void PmeXmlMacroReader::ReadSolidCreateProtrusionRevolve(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString profile;
	bool flip;
	CString startType, endType;
	double startAngle, endAngle;

	name = GetChildStr(spChildNodes, 0);	
	profile = GetChildStr(spChildNodes, 1);		
	startAngle = GetChildValue(spChildNodes, 2);
	startType = GetChildStr(spChildNodes, 3);
	endAngle = GetChildValue(spChildNodes, 4);
	endType = GetChildStr(spChildNodes, 5);
	flip = GetChildBoolean(spChildNodes, 6);

	PmeHReference hReference = FindReference(profile);
	if(!hReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hProtrusionRevolveFeature = 0;
	PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, name, hReference, startAngle, ConvertSolidRevolveEndType(startType), endAngle, ConvertSolidRevolveEndType(endType), flip, hProtrusionRevolveFeature);
	ASSERT(hProtrusionRevolveFeature);
}

void PmeXmlMacroReader::ReadSolidCreateCutRevolve(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString profile;
	bool flip;
	CString startType, endType;
	double startAngle, endAngle;

	name = GetChildStr(spChildNodes, 0);	
	profile = GetChildStr(spChildNodes, 1);		
	startAngle = GetChildValue(spChildNodes, 2);
	startType = GetChildStr(spChildNodes, 3);
	endAngle = GetChildValue(spChildNodes, 4);
	endType = GetChildStr(spChildNodes, 5);
	flip = GetChildBoolean(spChildNodes, 6);

	PmeHReference hReference = FindReference(profile);
	if(!hReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hCutRevolveFeature = 0;
	PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, name, hReference, startAngle, ConvertSolidRevolveEndType(startType), endAngle, ConvertSolidRevolveEndType(endType), flip, hCutRevolveFeature);
	ASSERT(hCutRevolveFeature);
}

void PmeXmlMacroReader::ReadSolidOperateFilletingFilletConstant(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	int num = spChildNodes->length;
	CString name;
	double radius;
	CString propagationTypeStr; 

	name = GetChildStr(spChildNodes, 0);

	PmeHReferences hReferenceEdges = 0;
	PmeReferencesAPI::Create(hReferenceEdges);

	for(int i = 1; i < num - 2; i ++)
	{
        CString edge = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(edge);
		ASSERT(hReference);
		PmeReferencesAPI::AddItem(hReferenceEdges, hReference);
	}

	radius = GetChildValue(spChildNodes, num - 2);
	propagationTypeStr = GetChildStr(spChildNodes, num - 1);
	
	PmeHFeature hFilletFeature = 0;
	PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, name, hReferenceEdges, radius, ConvertPropagationType(propagationTypeStr), hFilletFeature);
	ASSERT(hFilletFeature);

	PmeReferencesAPI::Delete(hReferenceEdges);
}

void PmeXmlMacroReader::ReadSolidOperateFilletingChamfer(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	int num = spChildNodes->length;
	CString name;
	CString chamferTypeStr;
	double length;
	//double value;

	name = GetChildStr(spChildNodes, 0);
	
    PmeHReferences hReferenceEdges = 0;
	PmeReferencesAPI::Create(hReferenceEdges);

	for(int i = 1; i < num - 2; i ++)
	{
        CString edge = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(edge);
		
		if (hReference) 
		{
			ASSERT(hReference);
			PmeReferencesAPI::AddItem(hReferenceEdges, hReference);
		}
	}

	length = GetChildValue(spChildNodes, num - 2);
	chamferTypeStr = GetChildStr(spChildNodes, num - 1);
	//value = GetChildValue(spChildNodes, num - 1);

	PmeHFeature hChamferFeature = 0;
	PmeStdSolidChamferFeatureAPI::Create(m_hPart, name, hReferenceEdges, length, hChamferFeature);
	ASSERT(hChamferFeature);
}

void PmeXmlMacroReader::ReadSolidOperatePatternRectangular(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;
	
	int num = spChildNodes->length;
	CString name;
	name = GetChildStr(spChildNodes, 0);
	
	PmeHReferences hTargetFeatures = 0;
	PmeReferencesAPI::Create(hTargetFeatures);

	for(int i = 1; i < num - 2; i ++)
	{
        CString feature = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(feature);
		
		if (hReference)
		{
			ASSERT(hReference);
			PmeReferencesAPI::AddItem(hTargetFeatures, hReference);
		}
	}

	double x, y, z;	
	GetCoordinateValues(spChildNodes, num - 6, x, y, z);
	MrDirection columnDirection(x, y, z);
	
	GetCoordinateValues(spChildNodes, num - 5, x, y, z);
	MrDirection rowDirection(x, y, z);

	int columnNumber;
	columnNumber = (int)GetChildValue(spChildNodes, num - 4);
		
	double columnSpacing;
	columnSpacing = GetChildValue(spChildNodes, num - 3);
	
	int rowNumber;
	rowNumber = (int)GetChildValue(spChildNodes, num - 2);

	double rowSpacing;
	rowSpacing = GetChildValue(spChildNodes, num - 1);
	
	PmeHFeature hPatternFeature = 0;
	PmeStdSolidOperatePatternRectangularFeatureAPI::Create(m_hPart, name, hTargetFeatures, columnSpacing, columnDirection, columnNumber, rowSpacing, rowDirection, rowNumber, hPatternFeature);
	ASSERT(hPatternFeature);
}

void PmeXmlMacroReader::ReadSolidOperatePatternCircular(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;
	
	int num = spChildNodes->length;
	CString name;
	name = GetChildStr(spChildNodes, 0);
	
	PmeHReferences hTargetFeatures = 0;
	PmeReferencesAPI::Create(hTargetFeatures);

	for(int i = 1; i < num - 2; i ++)
	{
        CString feature = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(feature);
		
		if (hReference)
		{
			ASSERT(hReference);
			PmeReferencesAPI::AddItem(hTargetFeatures, hReference);
		}
	}

	double x, y, z;
	GetCoordinateValues(spChildNodes, num - 7, x, y, z);
	MrPosition centerPosition(x, y, z);

	GetCoordinateValues(spChildNodes, num - 6, x, y, z);
	MrDirection centerDirection(x, y, z);

	MrAxis1 centerAxis(centerPosition, centerDirection);
	
	int angleNumber;
	angleNumber = (int)GetChildValue(spChildNodes, num - 5);

	double angleIncrement;
	angleIncrement = GetChildValue(spChildNodes, num - 4);
	
	int radialNumber;
	radialNumber = (int)GetChildValue(spChildNodes, num - 3);
	
	double radialSpacing;
	radialSpacing = GetChildValue(spChildNodes, num - 2);

	bool radialAlignment;
	radialAlignment = GetChildBoolean(spChildNodes, num - 1);

	PmeHFeature hPatternFeature = 0;
	PmeStdSolidOperatePatternCircularFeatureAPI::Create(m_hPart, name, hTargetFeatures, centerAxis, angleNumber, angleIncrement, radialNumber, radialSpacing, radialAlignment, hPatternFeature);
	ASSERT(hPatternFeature);
}

void PmeXmlMacroReader::ReadSolidCreateHoleCouneterbored(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	name = GetChildStr(spChildNodes, 0);

	PmeHReference hTargetFace = 0;	
	CString targetFace = GetChildStr(spChildNodes, 1);

	hTargetFace = FindReference(targetFace);
	ASSERT(hTargetFace);

	double x, y, z;
	GetCoordinateValues(spChildNodes, 2, x, y, z);

	double startRadius;
	startRadius = GetChildValue(spChildNodes, 3);

	double startDepth;
	startDepth = GetChildValue(spChildNodes, 4);

	double endRadius;
	endRadius = GetChildValue(spChildNodes, 5);

	double endDepth;
	endDepth = GetChildValue(spChildNodes, 6);

	double bottomAngle;
	bottomAngle = GetChildValue(spChildNodes, 7);

	PmeHFeature hHoleFeature = 0;
	PmeStdSolidHoleCounterboredFeatureAPI::Create(m_hPart, name, hTargetFace, x, y, z, startRadius, startDepth, endRadius, endDepth, bottomAngle, hHoleFeature);
	ASSERT(hHoleFeature);
}

void PmeXmlMacroReader::ReadSolidCreateHoleCounetersunk(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	name = GetChildStr(spChildNodes, 0);

	PmeHReference hTargetFace = 0;	
	CString targetFace = GetChildStr(spChildNodes, 1);

	hTargetFace = FindReference(targetFace);
	ASSERT(hTargetFace);
	
	double x, y, z;
	GetCoordinateValues(spChildNodes, 2, x, y, z);

	double radius;
	radius = GetChildValue(spChildNodes, 3);

	double depth;
	depth = GetChildValue(spChildNodes, 4);

	double sinkRadius;
	sinkRadius = GetChildValue(spChildNodes, 5);

	double sinkAngle;
	sinkAngle = GetChildValue(spChildNodes, 6);

	double bottomAngle;
	bottomAngle = GetChildValue(spChildNodes, 7);

	PmeHFeature hHoleFeature = 0;
	PmeStdSolidHoleCountersunkFeatureAPI::Create(m_hPart, name, hTargetFace, x, y, z, radius, depth, sinkRadius, sinkAngle, bottomAngle, hHoleFeature);
	ASSERT(hHoleFeature);
}

void PmeXmlMacroReader::ReadSolidCreateHoleSimple(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	name = GetChildStr(spChildNodes, 0);

	PmeHReference hTargetFace = 0;	
	CString targetFace = GetChildStr(spChildNodes, 1);

	hTargetFace = FindReference(targetFace);
	ASSERT(hTargetFace);

	double x, y, z;
	GetCoordinateValues(spChildNodes, 2, x, y, z);

	double Radius;
	Radius = GetChildValue(spChildNodes, 3);

	double Depth;
	Depth = GetChildValue(spChildNodes, 4);
	
	PmeHFeature hHoleFeature = 0;
	PmeStdSolidHoleSimpleFeatureAPI::Create(m_hPart, name, hTargetFace, x, y, z, Radius, Depth, hHoleFeature);
	ASSERT(hHoleFeature);
}

void PmeXmlMacroReader::ReadSolidCreateLoftSections(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	int numberOfSections;
	CString loftSection;
	bool isCut; 

	name = GetChildStr(spChildNodes, 0);	
	numberOfSections = (int)GetChildValue(spChildNodes, 1);
	
	PmeHReference hReferences = 0;
	PmeReferencesAPI::Create(hReferences);
	for (int i = 0; i < numberOfSections; ++i )
	{
		//_variant_t value;

		CString loftsection = GetChildStr(spChildNodes, i+2);	

		PmeHReference hReference = FindReference(loftsection);
		PmeReferencesAPI::AddItem(hReferences, hReference);
	}
	
	isCut = GetChildBoolean(spChildNodes, numberOfSections + 2);

	PmeHFeature hLoftSectionsFeature = 0;
	PmeStdSolidLoftSectionsFeatureAPI::Create(m_hPart, name, hReferences, isCut, hLoftSectionsFeature);	
	ASSERT(hLoftSectionsFeature);
}

void PmeXmlMacroReader::ReadSolidCreateShell(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	int num = spChildNodes->length;
	CString name;
	double innerThickness, outerThickness;

	name = GetChildStr(spChildNodes, 0);

    PmeHReferences hTargetFaces = 0;
	PmeReferencesAPI::Create(hTargetFaces);

	for(int i = 1; i < num - 2; i ++)
	{
        CString edge = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(edge);
		
		if (hReference) 
		{
			ASSERT(hReference);
			PmeReferencesAPI::AddItem(hTargetFaces, hReference);
		}
	}

	innerThickness = GetChildValue(spChildNodes, num - 2);
	outerThickness = GetChildValue(spChildNodes, num - 1);

	PmeHFeature hShellFeature = 0;
	PmeStdSolidShellFeatureAPI::Create(m_hPart, name, hTargetFaces, innerThickness, outerThickness, hShellFeature);
	ASSERT(hShellFeature);
}

void PmeXmlMacroReader::ReadSolidCreateDraft(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	int num = spChildNodes->length;
	CString name;
	double draftAngle;

	name = GetChildStr(spChildNodes, 0);

    PmeHReferences hTargetFaces = 0;
	PmeReferencesAPI::Create(hTargetFaces);

	for(int i = 1; i < num - 3; i ++)
	{
        CString edge = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(edge);
		
		if (hReference) 
		{
			ASSERT(hReference);
			PmeReferencesAPI::AddItem(hTargetFaces, hReference);
		}
	}
	
	double x, y, z;
	GetCoordinateValues(spChildNodes, num - 3, x, y, z);
	MrPosition Origin(x, y, z);

	GetCoordinateValues(spChildNodes, num - 2, x, y, z);
	MrDirection Direction(x, y, z);

	MrAxis1 pullingDirection(Origin, Direction);

	draftAngle = GetChildValue(spChildNodes, num - 1);

	PmeHFeature hDraftFeature = 0;
	PmeStdSolidDraftFeatureAPI::Create(m_hPart, name, hTargetFaces, pullingDirection, draftAngle, hDraftFeature);
	ASSERT(hDraftFeature);
}

void PmeXmlMacroReader::ReadSolidCreateOffset(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	int num = spChildNodes->length;
	CString name;
	double offsetThickness;

	name = GetChildStr(spChildNodes, 0);

    PmeHReferences hTargetFaces = 0;
	PmeReferencesAPI::Create(hTargetFaces);

	for(int i = 1; i < num - 1; i ++)
	{
        CString edge = GetChildStr(spChildNodes, i);
		PmeHReference hReference = FindReference(edge);
		
		if (hReference) 
		{
			ASSERT(hReference);
			PmeReferencesAPI::AddItem(hTargetFaces, hReference);
		}
	}

	offsetThickness = GetChildValue(spChildNodes, num - 1);

	PmeHFeature hOffsetFeature = 0;
	PmeStdSolidOffsetFeatureAPI::Create(m_hPart, name, hTargetFaces, offsetThickness, hOffsetFeature);
	ASSERT(hOffsetFeature);
}

void PmeXmlMacroReader::ReadSolidImportBrep(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString filePath;
	
	name = GetChildStr(spChildNodes, 0);
	filePath = GetChildStr(spChildNodes, 1);
	
	PmeHFeature hImportedBrepFeature = 0;
	PmeStdSolidImportedBrepFeatureAPI::Create(m_hPart, name, filePath, hImportedBrepFeature);
	ASSERT(hImportedBrepFeature);
}

void PmeXmlMacroReader::ReadDatumPlaneOffset(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;

	CString name;
	CString selectedPlane;
	bool flip;
	double distance;

	name = GetChildStr(spChildNodes, 0);	
	selectedPlane = GetChildStr(spChildNodes, 1);		
	distance = GetChildValue(spChildNodes, 2);
	flip = GetChildBoolean(spChildNodes, 3);
	

	PmeHReference hReference = FindReference(selectedPlane);
	if(!hReference)
	{
		TRACE(_T("Invalid reference name.\n"));
		return;
	}

	PmeHFeature hDatumPlaneOffsetFeature = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, name, hReference, distance, flip, hDatumPlaneOffsetFeature);	
	ASSERT(hDatumPlaneOffsetFeature);
}

void PmeXmlMacroReader::ReadDatumPlaneOffset2(MSXML2::IXMLDOMNodePtr spDOMNode)
{
	MSXML2::IXMLDOMNodeListPtr spChildNodes = spDOMNode->childNodes;
	int num = spChildNodes->length;

	CString name;
	bool flip;

	name = GetChildStr(spChildNodes, 0);	
	
	double x, y, z;
	GetCoordinateValues(spChildNodes, num - 4, x, y, z);
	MrPosition org(x,y,z);

	GetCoordinateValues(spChildNodes, num - 3, x, y, z);
	MrDirection xdir(x,y,z);

	GetCoordinateValues(spChildNodes, num - 2, x, y, z);
	MrDirection ydir(x,y,z);

	flip = GetChildBoolean(spChildNodes, num - 1);

	PmeHFeature hDatumPlaneOffsetFeature = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create2(m_hPart, name, org.X(), org.Y(), org.Z(), xdir.X(), xdir.Y(), xdir.Z(), ydir.X(), ydir.Y(), ydir.Z(), flip, hDatumPlaneOffsetFeature);	
	ASSERT(hDatumPlaneOffsetFeature);
}