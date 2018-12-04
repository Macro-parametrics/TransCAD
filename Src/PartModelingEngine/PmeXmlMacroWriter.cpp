#include "StdAfx.h"
#include <vector>
#include ".\pmexmlmacrowriter.h"
#include ".\PmeAPI.h"
#include ".\StringOut.h"

using namespace std;

PmeXmlMacroWriter::PmeXmlMacroWriter(PmeHPart hPart, CString filename)
: m_hPart(hPart)
, m_fout(filename.GetBuffer())
, m_constraintCount(0)
{	
	m_fout.setf(ios::showpoint);
	m_fout.precision(12);
}

PmeXmlMacroWriter::PmeXmlMacroWriter(CString filename)
	: m_fout(filename.GetBuffer())
	, m_constraintCount(0)
{	
	m_fout.setf(ios::showpoint);
	m_fout.precision(12);
}


PmeXmlMacroWriter::~PmeXmlMacroWriter(void)
{
	m_fout.close();
}

void PmeXmlMacroWriter::Save(void)
{
	WriteHeader();
	WriteFeatures();
	WriteFooter();
}


void PmeXmlMacroWriter::WriteHeader( void )
{
	m_fout << "<?xml version='1.0' ?>" << endl;  // Beginning of XML Document
	m_fout << "<MACRO_PARAMETRICS>" << endl;
}

void PmeXmlMacroWriter::WriteParts( void )
{
	CString strName, strParentName;
	
	PmePartAPI::GetName(m_hPart,strName);
	PmePartAPI::GetParentName(m_hPart,strParentName);

	m_fout << "<Part>" << endl;	
	m_fout << "<ParentName>" << strParentName << "</ParentName>" << endl;	
	m_fout << "<PartName>" << strName << "</PartName>" << endl;	
	//이것도 마찬가지로 서피스파트이면.....서피스 파트를 내보내는 태그있어야된다.
	//<FilePath> strPath </FilePath>
	WriteFeatures();

	m_fout << "</Part>" << endl;	
}

void PmeXmlMacroWriter::WriteFooter( void )
{
	m_fout << "</MACRO_PARAMETRICS>" << endl;	
}

CString PmeXmlMacroWriter::WriteReference(PmeHReference hReference)
{	
	CString name;
	PmeReferenceAPI::GetName(hReference, name);

	PmeReferenceType type;
	PmeReferenceAPI::GetType(hReference, type);

    CString referenceeName;
	PmeReferenceAPI::GetReferenceeName(hReference, referenceeName);

	m_fout << "<SELECT_Object>" << endl;
		WriteResultObjectName(name);

		switch(type)
		{
		case PmeReferenceType_Feature:
			m_fout << "<type_edit>FEATURE</type_edit>" << endl;
			break;
		case PmeReferenceType_ExplicitModelObject:
			m_fout << "<type_edit>OBJECT</type_edit>" << endl;
			break;
		case PmeReferenceType_Brep:
			{
				PmeBrepType brepType;
				PmeBrepReferenceAPI::GetBrepType(hReference, brepType);

				switch(brepType)
				{
				case PmeBrepType_Vertex:
					m_fout << "<type_edit>VERTEX</type_edit>" << endl;
					break;
				case PmeBrepType_Edge:
					m_fout << "<type_edit>EDGE</type_edit>" << endl;
					break;
				case PmeBrepType_Face:
					m_fout << "<type_edit>FACE</type_edit>" << endl;
					break;
				}
			}
			break;
		case PmeReferenceType_SketchGeometry:
			m_fout << "<type_edit>SKETCHSEGMENT</type_edit>" << endl;
			break;
		}
		
		m_fout << "<entity>" << referenceeName << "</entity>" << endl;
		m_fout << "<picking_point>" << endl;
			WriteCoordinates(0.0, 0.0, 0.0);
		m_fout << "</picking_point>" << endl;
	m_fout << "</SELECT_Object>" << endl;	

	return name;
}

void PmeXmlMacroWriter::WriteResultObjectName(CString name)
{
	m_fout << "<result_object_name>" << name << "</result_object_name>" << endl;
}

void PmeXmlMacroWriter::WriteCoordinates(double x, double y, double z)
{
	m_fout << "<coordinates>" << x << "</coordinates>" << endl;
	m_fout << "<coordinates>" << y << "</coordinates>" << endl;
	m_fout << "<coordinates>" << z << "</coordinates>" << endl;
}

void PmeXmlMacroWriter::WriteBoolean(bool isTrue)
{
	if(isTrue)
		m_fout << _T("1");
	else
		m_fout << _T("0");
}

void PmeXmlMacroWriter::WriteFeatures(void)
{
	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	int size;
	PmeFeaturesAPI::GetSize(hFeatures, size);

	for(int i = 0; i < size; ++ i)
	{
		PmeHFeature hFeature;
		PmeFeaturesAPI::GetItem(hFeatures, i, hFeature);

		PmeFeatureType type;
		PmeFeatureAPI::GetType(hFeature, type);

		switch(type)
		{
		case PmeFeatureType_StdDefaultDatumPlaneFeature:
			// Do Nothing.
			break;
		case PmeFeatureType_StdSketchFeature:
			WriteStdSketchSketch(hFeature);
			break;
		case PmeFeatureType_StdSolidProtrusionExtrudeFeature:
			WriteSolidProtrusionExtrude(hFeature);
			break;
		case PmeFeatureType_StdSolidCutExtrudeFeature:
			WriteSolidCutExtrude(hFeature);
			break;
		case PmeFeatureType_StdSolidFilletConstantFeature:
			WriteSolidFilletConstant(hFeature);
			break;
		case PmeFeatureType_StdSolidChamferFeature:
			WriteSolidChamfer(hFeature);
			break;
		case PmeFeatureType_StdSolidProtrusionSweepFeature:
			WriteSolidProtrusionSweep(hFeature);
			break;
		case PmeFeatureType_StdSolidProtrusionRevolveFeature:
			WriteSolidProtrusionRevolve(hFeature);
			break;
		case PmeFeatureType_StdSolidCutRevolveFeature:
			WriteSolidCutRevolve(hFeature);
			break;
		case PmeFeatureType_StdSolidOperatePatternRectangularFeature:
			WriteSolidOperatePatternRectangular(hFeature);
			break;
		case PmeFeatureType_StdSolidOperatePatternCircularFeature:
			WriteSolidOperatePatternCircular(hFeature);
			break;
		case PmeFeatureType_StdSolidHoleCounterboredFeature:
			WriteSolidHoleCounterbored(hFeature);
			break;
		case PmeFeatureType_StdSolidHoleCountersunkFeature:
			WriteSolidHoleCountersunk(hFeature);
			break;
		case PmeFeatureType_StdDatumPlaneOffsetFeature:
			WriteDatumPlaneOffset(hFeature);
			break;
		case PmeFeatureType_StdSolidLoftSectionsFeature:
			WriteSolidLoftSections(hFeature);
			break;
		case PmeFeatureType_StdSolidCutSweepFeature:
			WriteSolidCutSweep(hFeature);
			break;
		case PmeFeatureType_StdSolidHoleSimpleFeature:
			WriteSolidHoleSimple(hFeature);
			break;
		case PmeFeatureType_StdSolidShellFeature:
			WriteSolidShell(hFeature);
			break;
		case PmeFeatureType_StdSolidDraftFeature:
			WriteSolidDraft(hFeature);
			break;
		case PmeFeatureType_StdSolidOffsetFeature:
			WriteSolidOffset(hFeature);
			break;
		case PmeFeatureType_StdSolidImportedBrepFeature:
			WriteSolidImportedBrep(hFeature);
			break;
		}
	}
}

void PmeXmlMacroWriter::WriteStdSketchSketch(PmeHFeature hFeature)
{
	PmeHReference hSketchPlane;
	PmeStdSketchFeatureAPI::GetSketchPlane(hFeature, hSketchPlane);
	CString planeReference = WriteReference(hSketchPlane);

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);
	
	m_fout << "<SKETCH_Open>" << endl;
		WriteResultObjectName(name);
		m_fout << "<reference_edit>" << planeReference << "</reference_edit>" << endl;
	m_fout << "</SKETCH_Open>" << endl;

	WriteSketchCoordinateSystem(hFeature);
	WriteSketchGeometries(hFeature);
	WriteSketchConstraints(hFeature);

	m_fout << "<SKETCH_Close>" << endl;
		WriteResultObjectName(name);
	m_fout << "</SKETCH_Close>" << endl;
}

void PmeXmlMacroWriter::WriteSketchCoordinateSystem(PmeHFeature hFeature)
{
	CString name;
	name.Format("Constraint%d", m_constraintCount ++);	

	MrAxis2 coordinateSystem;
	PmeStdSketchFeatureAPI::GetCoordinateSystem(hFeature, coordinateSystem);

	MrPosition origin = coordinateSystem.Location();
	MrDirection xDir = coordinateSystem.XDirection();
	MrDirection yDir = coordinateSystem.YDirection();

	m_fout << "<CONSTRAINTS_Create_3DReference_CoordSys>" << endl;
		WriteResultObjectName(name);
		
		m_fout << "<origin>" << endl;
			WriteCoordinates(origin.X(), origin.Y(), origin.Z());
		m_fout << "</origin>" << endl;

		m_fout << "<first_direction>" << endl;
			WriteCoordinates(xDir.X(), xDir.Y(), xDir.Z());
		m_fout << "</first_direction>" << endl;

		m_fout << "<second_direction>" << endl;
			WriteCoordinates(yDir.X(), yDir.Y(), yDir.Z());
		m_fout << "</second_direction>" << endl;

	m_fout << "</CONSTRAINTS_Create_3DReference_CoordSys>" << endl;
}

void PmeXmlMacroWriter::WriteSketchGeometries(PmeHFeature hFeature)
{
	PmeHStdSketchGeometries hGeometries;
	PmeStdSketchFeatureAPI::GetGeometries(hFeature, hGeometries);

	int size;
	PmeStdSketchGeometriesAPI::GetSize(hGeometries, size);

	for(int i = 0; i < size; ++ i)
	{
		PmeHStdSketchGeometry hGeometry;
		PmeStdSketchGeometriesAPI::GetItem(hGeometries, i, hGeometry);

		PmeStdSketchGeometryType type;
		PmeStdSketchGeometryAPI::GetType(hGeometry, type);

		switch(type)
		{
		case PmeStdSketchGeometryType_Line:
			WriteStdSketchLine(hGeometry);
			break;
		case PmeStdSketchGeometryType_Circle:
			WriteStdSketchCircle(hGeometry);
			break;
		case PmeStdSketchGeometryType_CircularArc:
			WriteStdSketchCircularArc(hGeometry);
			break;
		case PmeStdSketchGeometryType_Centerline:
			WriteStdSketchCenterline(hGeometry);
			break;
		}
	}
}

void PmeXmlMacroWriter::WriteStdSketchLine(PmeHStdSketchGeometry hGeometry)
{
	CString name;
	PmeStdSketchGeometryAPI::GetName(hGeometry, name);		
	
	m_fout << "<SKETCH_Create_2D_Line_2Points>" << endl;
		WriteResultObjectName(name);

		PmeHStdSketchGeometry hStartPoint;
		PmeStdSketchLineAPI::GetStartPoint(hGeometry, hStartPoint);

		double x, y;
		PmeStdSketchControlPointAPI::GetPosition(hStartPoint, x, y);

		m_fout << "<start_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</start_point>" << endl;

		PmeHStdSketchGeometry hEndPoint;
		PmeStdSketchLineAPI::GetEndPoint(hGeometry, hEndPoint);

		PmeStdSketchControlPointAPI::GetPosition(hEndPoint, x, y);

		m_fout << "<end_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</end_point>" << endl;

	m_fout << "</SKETCH_Create_2D_Line_2Points>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchCircle(PmeHStdSketchGeometry hGeometry)
{
	CString name;
	PmeStdSketchGeometryAPI::GetName(hGeometry, name);		
	
	m_fout << "<SKETCH_Create_2D_Circle_CenterPoint>" << endl;

		WriteResultObjectName(name);

		PmeHStdSketchGeometry hCenterPoint;
		PmeStdSketchCircleAPI::GetCenterPoint(hGeometry, hCenterPoint);

		double x, y;
		PmeStdSketchControlPointAPI::GetPosition(hCenterPoint, x, y);

		m_fout << "<center_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</center_point>" << endl;

		
		double radius;
		PmeStdSketchCircleAPI::GetRadius(hGeometry, radius);

		m_fout << "<radius>" << radius << "</radius>" << endl;

	m_fout << "</SKETCH_Create_2D_Circle_CenterPoint>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchCircularArc(PmeHStdSketchGeometry hGeometry)
{
	CString name;
	PmeStdSketchGeometryAPI::GetName(hGeometry, name);		
	
	m_fout << "<SKETCH_Create_2D_Arc_CenterEnds>" << endl;

		WriteResultObjectName(name);

		PmeHStdSketchGeometry hCenterPoint;
		PmeStdSketchCircularArcAPI::GetCenterPoint(hGeometry, hCenterPoint);

		PmeHStdSketchGeometry hStartPoint;
		PmeStdSketchCircularArcAPI::GetStartPoint(hGeometry, hStartPoint);

		PmeHStdSketchGeometry hEndPoint;
		PmeStdSketchCircularArcAPI::GetEndPoint(hGeometry, hEndPoint);

		double x, y;
		PmeStdSketchControlPointAPI::GetPosition(hCenterPoint, x, y);

		m_fout << "<center_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</center_point>" << endl;

		PmeStdSketchControlPointAPI::GetPosition(hStartPoint, x, y);

		m_fout << "<start_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</start_point>" << endl;

		PmeStdSketchControlPointAPI::GetPosition(hEndPoint, x, y);

		m_fout << "<end_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</end_point>" << endl;

		m_fout << "<own_rotation_direction>ccw</own_rotation_direction>" << endl;

	m_fout << "</SKETCH_Create_2D_Arc_CenterEnds>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchCenterline(PmeHStdSketchGeometry hGeometry)
{
	CString name;
	PmeStdSketchGeometryAPI::GetName(hGeometry, name);		
	
	m_fout << "<SKETCH_Create_2D_Centerline>" << endl;
		WriteResultObjectName(name);

		PmeHStdSketchGeometry hStartPoint;
		PmeStdSketchCenterlineAPI::GetStartPoint(hGeometry, hStartPoint);

		double x, y;
		PmeStdSketchControlPointAPI::GetPosition(hStartPoint, x, y);

		m_fout << "<start_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</start_point>" << endl;

		PmeHStdSketchGeometry hEndPoint;
		PmeStdSketchCenterlineAPI::GetEndPoint(hGeometry, hEndPoint);

		PmeStdSketchControlPointAPI::GetPosition(hEndPoint, x, y);

		m_fout << "<end_point>" << endl;
			WriteCoordinates(x, y, 0.0);
		m_fout << "</end_point>" << endl;

	m_fout << "</SKETCH_Create_2D_Centerline>" << endl;
}


void PmeXmlMacroWriter::WriteSolidProtrusionExtrude(PmeHFeature hFeature)
{
	CString conditions[3] = {_T("Dimension"), _T("ThroughAll"), _T("ThroughNext")};

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hProfileSketch;
	PmeStdSolidProtrusionExtrudeFeatureAPI::GetProfileSketch(hFeature, hProfileSketch);
	
	CString profileSketchName = WriteReference(hProfileSketch);

	bool isFlip;
	PmeStdSolidProtrusionExtrudeFeatureAPI::IsFlip(hFeature, isFlip);

	m_fout << "<SOLID_Create_Protrusion_Extrude>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<profile_sketch>" << profileSketchName << "</profile_sketch>" << endl;
		
		PmeStdExtrudeEndType startCondition;
		PmeStdSolidProtrusionExtrudeFeatureAPI::GetStartCondition(hFeature, startCondition);

		double startDepth;
		PmeStdSolidProtrusionExtrudeFeatureAPI::GetStartDepth(hFeature, startDepth);
		
		m_fout << "<start_depth>" << startDepth << "</start_depth>" << endl;
		m_fout << "<start_condition>" << conditions[startCondition] << "</start_condition>" << endl;
		
		PmeStdExtrudeEndType endCondition;
		PmeStdSolidProtrusionExtrudeFeatureAPI::GetEndCondition(hFeature, endCondition);

		double endDepth;
		PmeStdSolidProtrusionExtrudeFeatureAPI::GetEndDepth(hFeature, endDepth);

		m_fout << "<end_depth>" << endDepth << "</end_depth>" << endl;
		m_fout << "<end_condition>" << conditions[endCondition] << "</end_condition>" << endl;
				
		m_fout << "<flip>";
			WriteBoolean(isFlip);
		m_fout << "</flip>" << endl;

	m_fout << "</SOLID_Create_Protrusion_Extrude>" << endl;
}

void PmeXmlMacroWriter::WriteSolidCutExtrude(PmeHFeature hFeature)
{
	CString conditions[3] = {_T("Dimension"), _T("ThroughAll"), _T("ThroughNext")};

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hProfileSketch;
	PmeStdSolidCutExtrudeFeatureAPI::GetProfileSketch(hFeature, hProfileSketch);

	CString profileSketchName = WriteReference(hProfileSketch);

	bool isFlip;
	PmeStdSolidCutExtrudeFeatureAPI::IsFlip(hFeature, isFlip);

	m_fout << "<SOLID_Create_Cut_Extrude>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<profile_sketch>" << profileSketchName << "</profile_sketch>" << endl;
		
		PmeStdExtrudeEndType startCondition;
		PmeStdSolidCutExtrudeFeatureAPI::GetStartCondition(hFeature, startCondition);

		double startDepth;
		PmeStdSolidCutExtrudeFeatureAPI::GetStartDepth(hFeature, startDepth);

		m_fout << "<start_depth>" << startDepth << "</start_depth>" << endl;
		m_fout << "<start_condition>" << conditions[startCondition] << "</start_condition>" << endl;
		
		PmeStdExtrudeEndType endCondition;
		PmeStdSolidCutExtrudeFeatureAPI::GetEndCondition(hFeature, endCondition);

		double endDepth;
		PmeStdSolidCutExtrudeFeatureAPI::GetEndDepth(hFeature, endDepth);

		m_fout << "<end_depth>" << endDepth << "</end_depth>" << endl;
		m_fout << "<end_condition>" << conditions[endCondition] << "</end_condition>" << endl;
				
		m_fout << "<flip>";
			WriteBoolean(isFlip);
		m_fout << "</flip>" << endl;

	m_fout << "</SOLID_Create_Cut_Extrude>" << endl;
}

void PmeXmlMacroWriter::WriteSolidProtrusionSweep(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hProfileSketch;
	PmeStdSolidProtrusionSweepFeatureAPI::GetProfileSketch(hFeature, hProfileSketch);

	CString profileSketchName = WriteReference(hProfileSketch);

	PmeHReference hGuideCurve;
	PmeStdSolidProtrusionSweepFeatureAPI::GetGuideCurve(hFeature, hGuideCurve);

	CString guideCurveName = WriteReference(hGuideCurve);

	m_fout << "<SOLID_Create_Protrusion_Sweep>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<profile_sketch>" << profileSketchName << "</profile_sketch>" << endl;
		m_fout << "<guide_curve>" << guideCurveName << "</guide_curve>" << endl;
		
	m_fout << "</SOLID_Create_Protrusion_Sweep>" << endl;
}

void PmeXmlMacroWriter::WriteSolidCutSweep(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hProfileSketch;
	PmeStdSolidCutSweepFeatureAPI::GetProfileSketch(hFeature, hProfileSketch);

	CString profileSketchName = WriteReference(hProfileSketch);

	PmeHReference hGuideCurve;
	PmeStdSolidCutSweepFeatureAPI::GetGuideCurve(hFeature, hGuideCurve);

	CString guideCurveName = WriteReference(hGuideCurve);

	m_fout << "<SOLID_Create_Cut_Sweep>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<profile_sketch>" << profileSketchName << "</profile_sketch>" << endl;
		m_fout << "<guide_curve>" << guideCurveName << "</guide_curve>" << endl;
		
	m_fout << "</SOLID_Create_Cut_Sweep>" << endl;
}

void PmeXmlMacroWriter::WriteSolidProtrusionRevolve(PmeHFeature hFeature)
{
	CString conditions[3] = {_T("Dimension"), _T("ThroughAll"), _T("ThroughNext")};

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hProfileSketch;
	PmeStdSolidProtrusionRevolveFeatureAPI::GetProfileSketch(hFeature, hProfileSketch);

	CString profileSketchName = WriteReference(hProfileSketch);

	bool isFlip;
	PmeStdSolidProtrusionRevolveFeatureAPI::IsFlip(hFeature, isFlip);

	m_fout << "<SOLID_Create_Protrusion_Revolve>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<profile_sketch>" << profileSketchName << "</profile_sketch>" << endl;

		PmeStdRevolveEndType startCondition;
		PmeStdSolidProtrusionRevolveFeatureAPI::GetStartCondition(hFeature, startCondition);

		double startAngle;
		PmeStdSolidProtrusionRevolveFeatureAPI::GetStartAngle(hFeature, startAngle);

		m_fout << "<start_angle>" << startAngle << "</start_angle>" << endl;
		m_fout << "<start_condition>" << conditions[startCondition] << "</start_condition>" << endl;
		
		PmeStdRevolveEndType endCondition;
		PmeStdSolidProtrusionRevolveFeatureAPI::GetEndCondition(hFeature, endCondition);

		double endAngle;
		PmeStdSolidProtrusionRevolveFeatureAPI::GetEndAngle(hFeature, endAngle);

		m_fout << "<end_angle>" << endAngle << "</end_angle>" << endl;
		m_fout << "<end_condition>" << conditions[endCondition] << "</end_condition>" << endl;
						
		m_fout << "<flip>";
			WriteBoolean(isFlip);
		m_fout << "</flip>" << endl;

	m_fout << "</SOLID_Create_Protrusion_Revolve>" << endl;
}

void PmeXmlMacroWriter::WriteSolidCutRevolve(PmeHFeature hFeature)
{
	CString conditions[3] = {_T("Dimension"), _T("ThroughAll"), _T("ThroughNext")};

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hProfileSketch;
	PmeStdSolidCutRevolveFeatureAPI::GetProfileSketch(hFeature, hProfileSketch);

	CString profileSketchName = WriteReference(hProfileSketch);

	bool isFlip;
	PmeStdSolidCutRevolveFeatureAPI::IsFlip(hFeature, isFlip);

	m_fout << "<SOLID_Create_Cut_Revolve>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<profile_sketch>" << profileSketchName << "</profile_sketch>" << endl;

		PmeStdRevolveEndType startCondition;
		PmeStdSolidCutRevolveFeatureAPI::GetStartCondition(hFeature, startCondition);

		double startAngle;
		PmeStdSolidCutRevolveFeatureAPI::GetStartAngle(hFeature, startAngle);

		m_fout << "<start_angle>" << startAngle << "</start_angle>" << endl;
		m_fout << "<start_condition>" << conditions[startCondition] << "</start_condition>" << endl;
		
		PmeStdRevolveEndType endCondition;
		PmeStdSolidCutRevolveFeatureAPI::GetEndCondition(hFeature, endCondition);

		double endAngle;
		PmeStdSolidCutRevolveFeatureAPI::GetEndAngle(hFeature, endAngle);

		m_fout << "<end_angle>" << endAngle << "</end_angle>" << endl;
		m_fout << "<end_condition>" << conditions[endCondition] << "</end_condition>" << endl;
						
		m_fout << "<flip>";
			WriteBoolean(isFlip);
		m_fout << "</flip>" << endl;

	m_fout << "</SOLID_Create_Cut_Revolve>" << endl;
}

void PmeXmlMacroWriter::WriteSolidFilletConstant(PmeHFeature hFeature)
{
	CString propagationStr[2] = {_T("Minimal"), _T("Tangency")};

	PmeHReferences hFilletEdges;
	PmeStdSolidFilletConstantFeatureAPI::GetFilletEdges(hFeature, hFilletEdges);

	int size;
	PmeReferencesAPI::GetSize(hFilletEdges, size);

	vector<CString> edgeNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hEdge;
		PmeReferencesAPI::GetItem(hFilletEdges, i, hEdge);

		CString edgeName = WriteReference(hEdge);
		edgeNames.push_back(edgeName);
	}

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Operate_Filleting_Fillet_Constant>" << endl;
		WriteResultObjectName(name);

		vector<CString>::iterator it = edgeNames.begin();
		while(it != edgeNames.end())
		{
			m_fout << "<selected_objects>" << (*it) << "</selected_objects>" << endl;
			it ++;
		}

		double radius;
		PmeStdSolidFilletConstantFeatureAPI::GetRadius(hFeature, radius);		

		m_fout << "<radius>" << radius << "</radius>" << endl;

		PmePropagationType propagation;
		PmeStdSolidFilletConstantFeatureAPI::GetPropagationType(hFeature, propagation);

		m_fout << "<propagation>" << propagationStr[propagation] << "</propagation>" << endl;

	m_fout << "</SOLID_Operate_Filleting_Fillet_Constant>" << endl;
}

void PmeXmlMacroWriter::WriteSolidChamfer(PmeHFeature hFeature)
{
	CString chamferTypeStr[2] = {_T("chamfer_length"), _T("chamfer_angle")};

	PmeHReferences hSelectedEdges;
	PmeStdSolidChamferFeatureAPI::GetSelectedEdges(hFeature, hSelectedEdges);

	int size;
	PmeReferencesAPI::GetSize(hSelectedEdges, size);

	vector<CString> edgeNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hEdge;
		PmeReferencesAPI::GetItem(hSelectedEdges, i, hEdge);

		CString edgeName = WriteReference(hEdge);
		edgeNames.push_back(edgeName);
	}

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Operate_Filleting_Chamfer>" << endl;
		WriteResultObjectName(name);

		vector<CString>::iterator it = edgeNames.begin();
		while(it != edgeNames.end())
		{
			m_fout << "<selected_objects>" << (*it) << "</selected_objects>" << endl;
			it ++;
		}
		
		double length;
		PmeStdSolidChamferFeatureAPI::GetLength(hFeature, length);
		m_fout << "<length>" << length << "</length>" << endl;
		
		PmeChamferType chamferType;
		PmeStdSolidChamferFeatureAPI::GetChamferType(hFeature, chamferType);
		m_fout << "<chamfer_type>" << chamferTypeStr[chamferType] << "</chamfer_type>" << endl;

	m_fout << "</SOLID_Operate_Filleting_Chamfer>" << endl;
}

void PmeXmlMacroWriter::WriteSolidOperatePatternRectangular(PmeHFeature hFeature)
{
	PmeHReferences hTargetFeatures;
	PmeStdSolidOperatePatternRectangularFeatureAPI::GetTargetFeatures(hFeature, hTargetFeatures);

	int size;
	PmeReferencesAPI::GetSize(hTargetFeatures, size);

	vector<CString> featureNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hFeature;
		PmeReferencesAPI::GetItem(hTargetFeatures, i, hFeature);

		CString featureName = WriteReference(hFeature);
		featureNames.push_back(featureName);
	}

	//CString targetFeatureName = WriteReference(hTargetFeature);

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Operate_Pattern_Rectangular>" << endl;
		WriteResultObjectName(name);
		
		//m_fout << "<selected_object>" << targetFeatureName << "</selected_object>" << endl;
		vector<CString>::iterator it = featureNames.begin();
		while(it != featureNames.end())
		{
			m_fout << "<selected_objects>" << (*it) << "</selected_objects>" << endl;
			it ++;
		}

		MrDirection columnDirection;
		PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnDirection(hFeature, columnDirection);

		m_fout << "<column_direction>" << endl;
		WriteCoordinates(columnDirection.X(), columnDirection.Y(), columnDirection.Z());
		m_fout << "</column_direction>" << endl;
		
		MrDirection rowDirection;
		PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowDirection(hFeature, rowDirection);

		m_fout << "<row_direction>" << endl;
		WriteCoordinates(rowDirection.X(), rowDirection.Y(), rowDirection.Z());
		m_fout << "</row_direction>" << endl;

		int columnNumber;
		PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnNumber(hFeature, columnNumber);
		m_fout << "<column_number>" << columnNumber << "</column_number>" << endl;
		
		double columnSpacing;
		PmeStdSolidOperatePatternRectangularFeatureAPI::GetColumnSpacing(hFeature, columnSpacing);
		m_fout << "<column_spacing>" << columnSpacing << "</column_spacing>" << endl;
		
		int rowNumber;
		PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowNumber(hFeature, rowNumber);
		m_fout << "<row_number>" << rowNumber << "</row_number>" << endl;

		double rowSpacing;
		PmeStdSolidOperatePatternRectangularFeatureAPI::GetRowSpacing(hFeature, rowSpacing);
		m_fout << "<row_spacing>" << rowSpacing << "</row_spacing>" << endl;

	m_fout << "</SOLID_Operate_Pattern_Rectangular>" << endl;
}

void PmeXmlMacroWriter::WriteSolidOperatePatternCircular(PmeHFeature hFeature)
{
	PmeHReferences hTargetFeatures;
	PmeStdSolidOperatePatternCircularFeatureAPI::GetTargetFeatures(hFeature, hTargetFeatures);

	int size;
	PmeReferencesAPI::GetSize(hTargetFeatures, size);

	vector<CString> featureNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hFeature;
		PmeReferencesAPI::GetItem(hTargetFeatures, i, hFeature);

		CString featureName = WriteReference(hFeature);
		featureNames.push_back(featureName);
	}

	//CString targetFeatureName = WriteReference(hTargetFeature);

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Operate_Pattern_Circular>" << endl;
		WriteResultObjectName(name);
		
		vector<CString>::iterator it = featureNames.begin();
		while(it != featureNames.end())
		{
			m_fout << "<selected_objects>" << (*it) << "</selected_objects>" << endl;
			it ++;
		}

		MrAxis1 centerAxis;
		PmeStdSolidOperatePatternCircularFeatureAPI::GetCenterAxis(hFeature, centerAxis);

		m_fout << "<center_position>" << endl;
		WriteCoordinates(centerAxis.Location().X(), centerAxis.Location().Y(), centerAxis.Location().Z());
		m_fout << "</center_position>" << endl;

		m_fout << "<center_axis>" << endl;
		WriteCoordinates(centerAxis.Direction().X(), centerAxis.Direction().Y(), centerAxis.Direction().Z());
		m_fout << "</center_axis>" << endl;

		int angleNumber;
		PmeStdSolidOperatePatternCircularFeatureAPI::GetAngleNumber(hFeature, angleNumber);
		m_fout << "<angle_number>" << angleNumber << "</angle_number>" << endl;

		double angleIncrement;
		PmeStdSolidOperatePatternCircularFeatureAPI::GetAngleIncrement(hFeature, angleIncrement);
		m_fout << "<angle_increment>" << angleIncrement << "</angle_increment>" << endl;

		int radialNumber;
		PmeStdSolidOperatePatternCircularFeatureAPI::GetRadialNumber(hFeature, radialNumber);
		m_fout << "<radial_number>" << radialNumber << "</radial_number>" << endl;

		double radialSpacing;
		PmeStdSolidOperatePatternCircularFeatureAPI::GetRadialSpacing(hFeature, radialSpacing);
		m_fout << "<radial_spacing>" << radialSpacing << "</radial_spacing>" << endl;

		bool isRadialAlignment;
		PmeStdSolidOperatePatternCircularFeatureAPI::IsRadialAlignment(hFeature, isRadialAlignment);

		m_fout << "<radial_alignment>";
		WriteBoolean(isRadialAlignment);
		m_fout << "</radial_alignment>" << endl;

	m_fout << "</SOLID_Operate_Pattern_Circular>" << endl;
}

void PmeXmlMacroWriter::WriteSolidHoleCounterbored(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hTargetFace;
	PmeStdSolidHoleCounterboredFeatureAPI::GetTargetFace(hFeature, hTargetFace);
	CString targetFaceName = WriteReference(hTargetFace);
	
	m_fout << "<SOLID_Create_Hole_Counterbored>" << endl;

	WriteResultObjectName(name);

	m_fout << "<target_face>" << targetFaceName << "</target_face>" << endl;
	
	double x, y, z;
	PmeStdSolidHoleCounterboredFeatureAPI::GetCenterX(hFeature, x);
	PmeStdSolidHoleCounterboredFeatureAPI::GetCenterY(hFeature, y);
	PmeStdSolidHoleCounterboredFeatureAPI::GetCenterZ(hFeature, z);	
	
	m_fout << "<center_position>" << endl;
	WriteCoordinates(x, y, z);
	m_fout << "</center_position>" << endl;

	double startRadius;
	PmeStdSolidHoleCounterboredFeatureAPI::GetStartRadius(hFeature, startRadius);
	m_fout << "<upper_hole_radius>" << startRadius << "</upper_hole_radius>" << endl;

	double startDepth;
	PmeStdSolidHoleCounterboredFeatureAPI::GetStartDepth(hFeature, startDepth);
	m_fout << "<upper_hole_depth>" << startDepth << "</upper_hole_depth>" << endl;

	double endRadius;
	PmeStdSolidHoleCounterboredFeatureAPI::GetEndRadius(hFeature, endRadius);
	m_fout << "<lower_hole_radius>" << endRadius << "</lower_hole_radius>" << endl;

	double endDepth;
	PmeStdSolidHoleCounterboredFeatureAPI::GetEndDepth(hFeature, endDepth);
	m_fout << "<lower_hole_depth>" << endDepth << "</lower_hole_depth>" << endl;

	double angle;
	PmeStdSolidHoleCounterboredFeatureAPI::GetAngle(hFeature, angle);
	m_fout << "<bottom_angle>" << angle << "</bottom_angle>" << endl;

	m_fout << "</SOLID_Create_Hole_Counterbored>" << endl;
}

void PmeXmlMacroWriter::WriteSolidHoleCountersunk(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hTargetFace;
	PmeStdSolidHoleCountersunkFeatureAPI::GetTargetFace(hFeature, hTargetFace);
	CString targetFaceName = WriteReference(hTargetFace);

	m_fout << "<SOLID_Create_Hole_Countersunk>" << endl;

	WriteResultObjectName(name);

	m_fout << "<target_face>" << targetFaceName << "</target_face>" << endl;
	
	double x, y, z;
	PmeStdSolidHoleCountersunkFeatureAPI::GetCenterX(hFeature, x);
	PmeStdSolidHoleCountersunkFeatureAPI::GetCenterY(hFeature, y);
	PmeStdSolidHoleCountersunkFeatureAPI::GetCenterZ(hFeature, z);
	
	m_fout << "<center_position>" << endl;
	WriteCoordinates(x, y, z);
	m_fout << "</center_position>" << endl;

	double radius;
	PmeStdSolidHoleCountersunkFeatureAPI::GetRadius(hFeature, radius);
	m_fout << "<radius>" << radius << "</radius>" << endl;

	double depth;
	PmeStdSolidHoleCountersunkFeatureAPI::GetDepth(hFeature, depth);
	m_fout << "<depth>" << depth << "</depth>" << endl;

	double countersinkRadius;
	PmeStdSolidHoleCountersunkFeatureAPI::GetSinkRadius(hFeature, countersinkRadius);
	m_fout << "<sink_radius>" << countersinkRadius << "</sink_radius>" << endl;

	double countersinkAngle;
	PmeStdSolidHoleCountersunkFeatureAPI::GetSinkAngle(hFeature, countersinkAngle);
	m_fout << "<sink_angle>" << countersinkAngle << "</sink_angle>" << endl;

	double bottomAngle;
	PmeStdSolidHoleCountersunkFeatureAPI::GetBottomAngle(hFeature, bottomAngle);
	m_fout << "<bottom_angle>" << bottomAngle << "</bottom_angle>" << endl;

	m_fout << "</SOLID_Create_Hole_Countersunk>" << endl;
}

void PmeXmlMacroWriter::WriteSolidHoleSimple(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReference hTargetFace;
	PmeStdSolidHoleSimpleFeatureAPI::GetTargetFace(hFeature, hTargetFace);
	CString targetFaceName = WriteReference(hTargetFace);

	m_fout << "<SOLID_Create_Hole_Simple>" << endl;

	WriteResultObjectName(name);

	m_fout << "<target_face>" << targetFaceName << "</target_face>" << endl;
	
	double x, y, z;
	PmeStdSolidHoleSimpleFeatureAPI::GetCenterX(hFeature, x);
	PmeStdSolidHoleSimpleFeatureAPI::GetCenterY(hFeature, y);
	PmeStdSolidHoleSimpleFeatureAPI::GetCenterZ(hFeature, z);

	m_fout << "<center_point>" << endl;
	WriteCoordinates(x, y, z);
	m_fout << "</center_point>" << endl;

	double Radius;
	PmeStdSolidHoleSimpleFeatureAPI::GetRadius(hFeature, Radius);
	m_fout << "<radius>" << Radius << "</radius>" << endl;

	double Depth;
	PmeStdSolidHoleSimpleFeatureAPI::GetDepth(hFeature, Depth);
	m_fout << "<depth>" << Depth << "</depth>" << endl;

	m_fout << "</SOLID_Create_Hole_Simple>" << endl;
}

void PmeXmlMacroWriter::WriteSolidLoftSections(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	PmeHReferences hSections;
	PmeStdSolidLoftSectionsFeatureAPI::GetLoftSections(hFeature, hSections);
	
	int numOfSections;
	PmeReferencesAPI::GetSize(hSections, numOfSections);
			
	for (int i = 0; i < numOfSections; ++i)
	{
		PmeHReference hSection;
		PmeReferencesAPI::GetItem(hSections,i,hSection);

		CString hSectionName = WriteReference(hSection);		
	}

	m_fout << "<SOLID_Create_Loft_Sections>" << endl;
		
		WriteResultObjectName(name);

		m_fout << "<number_of_sections>" << numOfSections << "</number_of_sections>" << endl;
		
		for (int i = 0; i < numOfSections; ++i)
		{
			PmeHReference hSection;
			PmeReferencesAPI::GetItem(hSections,i,hSection);
			
			CString hLoftSection;
			PmeReferenceAPI::GetName(hSection,hLoftSection);

			m_fout << "<loft_section>" << hLoftSection << "</loft_section>" << endl;
			
		}
		
		bool isCut;
		PmeStdSolidLoftSectionsFeatureAPI::IsCut(hFeature, isCut);

		m_fout << "<isCut>";
		WriteBoolean(isCut);
		m_fout << "</isCut>" << endl;

	m_fout << "</SOLID_Create_Loft_Sections>" << endl;
}

void PmeXmlMacroWriter::WriteSolidShell(PmeHFeature hFeature)
{
	PmeHReferences hTargetFaces;
	PmeStdSolidShellFeatureAPI::GetTargetFaces(hFeature, hTargetFaces);

	int size;
	PmeReferencesAPI::GetSize(hTargetFaces, size);

	vector<CString> faceNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hFace;
		PmeReferencesAPI::GetItem(hTargetFaces, i, hFace);

		CString faceName = WriteReference(hFace);
		faceNames.push_back(faceName);
	}

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Create_Shell>" << endl;
		WriteResultObjectName(name);

		vector<CString>::iterator it = faceNames.begin();
		while(it != faceNames.end())
		{
			m_fout << "<target_faces>" << (*it) << "</target_faces>" << endl;
			it ++;
		}

		double innerThickness, outerThickness;
		PmeStdSolidShellFeatureAPI::GetInnerThickness(hFeature, innerThickness);		
		PmeStdSolidShellFeatureAPI::GetOuterThickness(hFeature, outerThickness);

		m_fout << "<inner_thickness>" << innerThickness << "</inner_thickness>" << endl;
		m_fout << "<outer_thickness>" << outerThickness << "</outer_thickness>" << endl;

	m_fout << "</SOLID_Create_Shell>" << endl;
}

void PmeXmlMacroWriter::WriteSolidDraft(PmeHFeature hFeature)
{
	PmeHReferences hTargetFaces;
	PmeStdSolidDraftFeatureAPI::GetTargetFaces(hFeature, hTargetFaces);

	int size;
	PmeReferencesAPI::GetSize(hTargetFaces, size);

	vector<CString> faceNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hFace;
		PmeReferencesAPI::GetItem(hTargetFaces, i, hFace);

		CString faceName = WriteReference(hFace);
		faceNames.push_back(faceName);
	}

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);
	
	m_fout << "<SOLID_Create_Draft>" << endl;
		WriteResultObjectName(name);

		vector<CString>::iterator it = faceNames.begin();
		while(it != faceNames.end())
		{
			m_fout << "<target_faces>" << (*it) << "</target_faces>" << endl;
			it ++;
		}
		
		MrAxis1 pullingDirection;
		PmeStdSolidDraftFeatureAPI::GetPullingDirection(hFeature, pullingDirection);

		m_fout << "<pulling_origin>";
		WriteCoordinates(pullingDirection.Location().X(), pullingDirection.Location().Y(), pullingDirection.Location().Z());
		m_fout << "</pulling_origin>";

		m_fout << "<pulling_direction>";
		WriteCoordinates(pullingDirection.Direction().X(), pullingDirection.Direction().Y(), pullingDirection.Direction().Z());
		m_fout << "</pulling_direction>";


		double draftAngle;
		PmeStdSolidDraftFeatureAPI::GetDraftAngle(hFeature, draftAngle);		

		m_fout << "<draft_angle>" << draftAngle << "</draft_angle>" << endl;


	m_fout << "</SOLID_Create_Draft>" << endl;
}

void PmeXmlMacroWriter::WriteSolidOffset(PmeHFeature hFeature)
{
	PmeHReferences hTargetFaces;
	PmeStdSolidOffsetFeatureAPI::GetTargetFaces(hFeature, hTargetFaces);

	int size;
	PmeReferencesAPI::GetSize(hTargetFaces, size);

	vector<CString> faceNames;

	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hFace;
		PmeReferencesAPI::GetItem(hTargetFaces, i, hFace);

		CString faceName = WriteReference(hFace);
		faceNames.push_back(faceName);
	}

	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Create_Offset>" << endl;
		WriteResultObjectName(name);

		vector<CString>::iterator it = faceNames.begin();
		while(it != faceNames.end())
		{
			m_fout << "<target_faces>" << (*it) << "</target_faces>" << endl;
			it ++;
		}

		double offsetThickness;
		PmeStdSolidOffsetFeatureAPI::GetThickness(hFeature, offsetThickness);		

		m_fout << "<offset_thickness>" << offsetThickness << "</offset_thickness>" << endl;


	m_fout << "</SOLID_Create_Offset>" << endl;
}

void PmeXmlMacroWriter::WriteSolidImportedBrep(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	m_fout << "<SOLID_Import_Brep>" << endl;
		WriteResultObjectName(name);

		CString filePath;
		PmeStdSolidImportedBrepFeatureAPI::GetFilePath(hFeature, filePath);		

		m_fout << "<file_path>" << filePath << "</file_path>" << endl;

	m_fout << "</SOLID_Import_Brep>" << endl;
}

void PmeXmlMacroWriter::WriteDatumPlaneOffset(PmeHFeature hFeature)
{
	CString name;
	PmeFeatureAPI::GetName(hFeature, name);

	bool isFree;
	PmeStdDatumPlaneOffsetFeatureAPI::IsFree(hFeature, isFree);

	if(!isFree)
	{
		PmeHReference hSelectedPlane;
		PmeStdDatumPlaneOffsetFeatureAPI::GetSelectedPlane(hFeature, hSelectedPlane);

		CString selectedPlaneName = WriteReference(hSelectedPlane);

		m_fout << "<CONSTRAINTS_Create_3DReference_OffsetPlanes>" << endl;

		WriteResultObjectName(name);

		m_fout << "<selected_object>" << selectedPlaneName << "</selected_object>" << endl;

		double distance;
		PmeStdDatumPlaneOffsetFeatureAPI::GetDistance(hFeature, distance);

		m_fout << "<distance>" << distance << "</distance>" << endl;

		bool isFlip;
		PmeStdDatumPlaneOffsetFeatureAPI::IsFlip(hFeature, isFlip);

		m_fout << "<flip>";
		WriteBoolean(isFlip);
		m_fout << "</flip>" << endl;

		m_fout << "</CONSTRAINTS_Create_3DReference_OffsetPlanes>" << endl;
	}
	else
	{
		//새로 만든거 추가해야됨.
		m_fout << "<CONSTRAINTS_Create_3DReference_OffsetPlanes2>" << endl;

		WriteResultObjectName(name);

		MrPosition origin;
		MrDirection xdir, ydir;
		PmeStdDatumPlaneOffsetFeatureAPI::GetOrigin(hFeature, origin);
		PmeStdDatumPlaneOffsetFeatureAPI::GetXDirection(hFeature, xdir);
		PmeStdDatumPlaneOffsetFeatureAPI::GetYDirection(hFeature, ydir);
		
		m_fout << "<origin>" << endl;
		WriteCoordinates(origin.X(), origin.Y(), origin.Z());
		m_fout << "</origin>" << endl;
		
		m_fout << "<xdirection>" << endl;
		WriteCoordinates(xdir.X(), xdir.Y(), xdir.Z());
		m_fout << "</xdirection>" << endl;

		m_fout << "<ydirection>" << endl;
		WriteCoordinates(ydir.X(), ydir.Y(), ydir.Z());
		m_fout << "</ydirection>" << endl;

		bool isFlip;
		PmeStdDatumPlaneOffsetFeatureAPI::IsFlip(hFeature, isFlip);

		m_fout << "<flip>";
		WriteBoolean(isFlip);
		m_fout << "</flip>" << endl;

		m_fout << "</CONSTRAINTS_Create_3DReference_OffsetPlanes2>" << endl;
	}
}


void PmeXmlMacroWriter::WriteSketchConstraints(PmeHFeature hFeature)
{
	PmeHStdSketchConstraints hConstraints;
	PmeStdSketchFeatureAPI::GetConstraints(hFeature, hConstraints);

	int size;
	PmeStdSketchConstraintsAPI::GetSize(hConstraints, size);

	for(int i = 0; i < size; ++ i)
	{
		PmeHStdSketchConstraint hConstraint;
		PmeStdSketchConstraintsAPI::GetItem(hConstraints, i, hConstraint);

		PmeStdSketchConstraintType type;
		PmeStdSketchConstraintAPI::GetType(hConstraint, type);

		switch(type)
		{
		case PmeStdSketchConstraintType_CoincidentSamePoints:
			WriteStdSketchCoincidentSamePoints(hConstraint);
			break;
		case PmeStdSketchConstraintType_Perpendicular:
			WriteStdSketchPerpendicular(hConstraint);
			break;
		case PmeStdSketchConstraintType_Parallel:
			WriteStdSketchParallel(hConstraint);
			break;
		case PmeStdSketchConstraintType_Horizontal:
			WriteStdSketchHorizontal(hConstraint);
			break;
		case PmeStdSketchConstraintType_Vertical:
			WriteStdSketchVertical(hConstraint);
			break;
		}
	}
}

void PmeXmlMacroWriter::WriteStdSketchCoincidentSamePoints(PmeHStdSketchConstraint hConstraint)
{
	CString name;
	PmeStdSketchConstraintAPI::GetName(hConstraint, name);		

	PmeHReference hFirstGeometry;
	PmeStdSketchCoincidentAPI::GetFirstGeometry(hConstraint, hFirstGeometry);
	CString firstGeometryName = WriteReference(hFirstGeometry);

	PmeSamePointsType firstType;
	PmeStdSketchCoincidentAPI::GetFirstObjectType(hConstraint, firstType);

	PmeHReference hSecondGeometry;
	PmeStdSketchCoincidentAPI::GetSecondGeometry(hConstraint, hSecondGeometry);
	CString secondGeometryName = WriteReference(hSecondGeometry);

	PmeSamePointsType secondType;
	PmeStdSketchCoincidentAPI::GetSecondObjectType(hConstraint, secondType);

	m_fout << "<CONSTRAINTS_Create_Constraint_Coincident_SamePoints>" << endl;
	WriteResultObjectName(name);

	m_fout << "<first_object>" << firstGeometryName << "</first_object>" << endl;
	if(firstType == PmeSamePointsType_StartPoint)
		m_fout << "<first_type>" << "StartPoint" << "</first_type>" << endl;
	else if(firstType == PmeSamePointsType_EndPoint)
		m_fout << "<first_type>" << "EndPoint" << "</first_type>" << endl;
	else if(firstType == PmeSamePointsType_CenterPoint)
		m_fout << "<first_type>" << "CenterPoint" << "</first_type>" << endl;
	else if(firstType == PmeSamePointsType_Whole)
		m_fout << "<first_type>" << "Whole" << "</first_type>" << endl;

	m_fout << "<second_object>" << secondGeometryName << "</second_object>" << endl;
	if(secondType == PmeSamePointsType_StartPoint)
		m_fout << "<second_type>" << "StartPoint" << "</second_type>" << endl;
	else if(secondType == PmeSamePointsType_EndPoint)
		m_fout << "<second_type>" << "EndPoint" << "</second_type>" << endl;
	else if(secondType == PmeSamePointsType_CenterPoint)
		m_fout << "<second_type>" << "CenterPoint" << "</second_type>" << endl;
	else if(secondType == PmeSamePointsType_Whole)
		m_fout << "<second_type>" << "Whole" << "</second_type>" << endl;

	m_fout << "</CONSTRAINTS_Create_Constraint_Coincident_SamePoints>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchPerpendicular(PmeHStdSketchConstraint hConstraint)
{
	CString name;
	PmeStdSketchConstraintAPI::GetName(hConstraint, name);		

	PmeHReference hReferenceEdit;
	PmeStdSketchPerpendicularAPI::GetReferenceEdit(hConstraint, hReferenceEdit);
	CString referenceEditName = WriteReference(hReferenceEdit);

	PmeHReference hTarget;
	PmeStdSketchPerpendicularAPI::GetTarget(hConstraint, hTarget);
	CString targetName = WriteReference(hTarget);

	m_fout << "<CONSTRAINTS_Create_Constraint_Perpendicular>" << endl;
	WriteResultObjectName(name);

	m_fout << "<reference_edit>" << referenceEditName << "</reference_edit>" << endl;
	m_fout << "<target>" << targetName << "</target>" << endl;

	m_fout << "</CONSTRAINTS_Create_Constraint_Perpendicular>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchParallel(PmeHStdSketchConstraint hConstraint)
{
	CString name;
	PmeStdSketchConstraintAPI::GetName(hConstraint, name);		

	PmeHReference hReferenceEdit;
	PmeStdSketchParallelAPI::GetReferenceEdit(hConstraint, hReferenceEdit);
	CString referenceEditName = WriteReference(hReferenceEdit);

	PmeHReference hTarget;
	PmeStdSketchParallelAPI::GetTarget(hConstraint, hTarget);
	CString targetName = WriteReference(hTarget);

	m_fout << "<CONSTRAINTS_Create_Constraint_Parallel>" << endl;
	WriteResultObjectName(name);

	m_fout << "<reference_edit>" << referenceEditName << "</reference_edit>" << endl;
	m_fout << "<target>" << targetName << "</target>" << endl;

	m_fout << "</CONSTRAINTS_Create_Constraint_Parallel>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchHorizontal(PmeHStdSketchConstraint hConstraint)
{
	CString name;
	PmeStdSketchConstraintAPI::GetName(hConstraint, name);		

	PmeHReference hTarget;
	PmeStdSketchHorizontalAPI::GetTarget(hConstraint, hTarget);
	CString targetName = WriteReference(hTarget);

	m_fout << "<CONSTRAINTS_Create_Constraint_Horizontal>" << endl;
	WriteResultObjectName(name);

	m_fout << "<target>" << targetName << "</target>" << endl;

	m_fout << "</CONSTRAINTS_Create_Constraint_Horizontal>" << endl;
}

void PmeXmlMacroWriter::WriteStdSketchVertical(PmeHStdSketchConstraint hConstraint)
{
	CString name;
	PmeStdSketchConstraintAPI::GetName(hConstraint, name);		

	PmeHReference hTarget;
	PmeStdSketchVerticalAPI::GetTarget(hConstraint, hTarget);
	CString targetName = WriteReference(hTarget);

	m_fout << "<CONSTRAINTS_Create_Constraint_Vertical>" << endl;
	WriteResultObjectName(name);

	m_fout << "<target>" << targetName << "</target>" << endl;

	m_fout << "</CONSTRAINTS_Create_Constraint_Vertical>" << endl;
}

