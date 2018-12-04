#include "stdafx.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeExplicitModelObject.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeReference.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeSketch.h"
#include ".\PmeStdSketchFeature.h"


//EDGE * CreateEdgeFromGeometry(PmeStdSketchGeometry * pGeometry);
//EDGE * CreateEdgeFromSketchLine(PmeStdSketchLine * pLine);
//EDGE * CreateEdgeFromSketchCircle(PmeStdSketchCircle * pCircle);
//EDGE * CreateEdgeFromSketchCircularArc(PmeStdSketchCircularArc * pArc);

PmeSketch * PmeSketchUtility::GetSketch(PmeReference * pReference)
{
	PmeExplicitModelObject * pObject = pReference->GetPart()->GetSelectionManager()->GetObjectFromReference(pReference);
	PmeThrowExceptionIf<PmeIlligalOperationException>(!pObject || pObject->GetType() != PmeExplicitModelObjectType_Sketch);

	PmeSketch * pSketch = static_cast<PmeSketch *>(pObject);

	return pSketch;
}

void PmeSketchUtility::CreateWire(PmeReference * pReference, BODY **& ppWires, int & nWire)
{
	PmeSketch * pSketch = GetSketch(pReference);

	PmeFeature * pFeature = pSketch->GetCreator();
	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);	

	PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();
	PmeStdSketchGeometries::SizeType size = pGeometries->GetSize();

	std::vector<EDGE *> edges;

	for(PmeStdSketchGeometries::SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(i);
		EDGE * pEdge = CreateEdgeFromGeometry(pGeometry);

		if(pEdge)
		{
			// Debug

			SPAposition start = pEdge->start_pos();
			SPAposition end = pEdge->end_pos();

			TRACE("%d edge: start (%.8f, %.8f, %.8f), end (%.8f, %.8f, %.8f) \n", i, start.x(), start.y(), start.z(), end.x(), end.y(), end.z());

            edges.push_back(pEdge);

			// 스케치에 엣지 저장해 둠. 향 후, 스케치 요소 이름이 소실 되었는지 체크하기 위함
			pSketchFeature->SaveEdgeGeometry(pEdge);
		}
	}

	API_BEGIN

		result = api_make_ewires((int)edges.size(), &edges[0], nWire, ppWires);
		check_outcome(result);

		if(!result.ok())
			nWire = 0;

	API_END

	edges.clear();
}

void PmeSketchUtility::CreateWire(PmeReference * pReference, BODY *& pWire)
{
	PmeSketch * pSketch = GetSketch(pReference);

	PmeFeature * pFeature = pSketch->GetCreator();
	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);	

	PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();
	PmeStdSketchGeometries::SizeType size = pGeometries->GetSize();

	ENTITY_LIST  elist;

	for(PmeStdSketchGeometries::SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(i);
		EDGE * pEdge = CreateEdgeFromGeometry(pGeometry);

		if(pEdge)
		{
			// Debug
			SPAposition start = pEdge->start_pos();
			SPAposition end = pEdge->end_pos();

			TRACE("%d edge: start (%.8f, %.8f, %.8f), end (%.8f, %.8f, %.8f) \n", i, start.x(), start.y(), start.z(), end.x(), end.y(), end.z());

            elist.add(pEdge);
		}
	} 

	API_BEGIN

		result = create_wire_from_edge_list(elist, pWire);
		check_outcome(result);		

	API_END
}

EDGE * PmeSketchUtility::CreateEdgeFromGeometry(PmeStdSketchGeometry * pGeometry)
{
	EDGE * pEdge = 0;

	switch(pGeometry->GetType())
	{
	case PmeStdSketchGeometryType_Line:
		pEdge = CreateEdgeFromSketchLine(static_cast<PmeStdSketchLine *>(pGeometry));
		break;
	case PmeStdSketchGeometryType_Circle:
		pEdge = CreateEdgeFromSketchCircle(static_cast<PmeStdSketchCircle *>(pGeometry));
		break;
	case PmeStdSketchGeometryType_CircularArc:
		pEdge = CreateEdgeFromSketchCircularArc(static_cast<PmeStdSketchCircularArc *>(pGeometry));
		break;
	}

	if(pEdge)
	{
		CString sketchName = pGeometry->GetSketchFeature()->GetName();
		CString name = pGeometry->GetName();

		new ATTRIB_GEN_STRING(pEdge, sketchName, name);
	}

	return pEdge;
}

EDGE * PmeSketchUtility::CreateEdgeFromSketchLine(PmeStdSketchLine * pLine)
{
	PmeStdSketchControlPoint * pStartPoint = pLine->GetStartPoint();
	PmeStdSketchControlPoint * pEndPoint = pLine->GetEndPoint();

	EDGE * pEdge = 0;

	API_BEGIN
		
        result = api_mk_ed_line(SPAposition(pStartPoint->GetX(), pStartPoint->GetY(), 0.0),
								SPAposition(pEndPoint->GetX(), pEndPoint->GetY(), 0.0),
								pEdge);
		check_outcome(result);
	
	API_END

	return pEdge;
}

EDGE * PmeSketchUtility::CreateEdgeFromSketchCircle(PmeStdSketchCircle * pCircle)
{
	PmeStdSketchControlPoint * pCenterPoint = pCircle->GetCenterPoint();
	double radius = pCircle->GetRadius();

	EDGE * pEdge = 0;

	API_BEGIN
		
        result = api_mk_ed_ellipse(SPAposition(pCenterPoint->GetX(), pCenterPoint->GetY(), 0.0),
								   SPAunit_vector(0.0, 0.0, 1.0),
								   SPAvector(1.0, 0.0, 0.0) * radius,
								   1.0, 0.0, 0.0,
								   pEdge);
		check_outcome(result);
	
	API_END

	return pEdge;
}

EDGE * PmeSketchUtility::CreateEdgeFromSketchCircularArc(PmeStdSketchCircularArc * pArc)
{
	PmeStdSketchControlPoint * pCenterPoint = pArc->GetCenterPoint();
	PmeStdSketchControlPoint * pStartPoint = pArc->GetStartPoint();
	PmeStdSketchControlPoint * pEndPoint = pArc->GetEndPoint();
	/*
	double radius = pArc->GetRadius();
	double startAngle = pArc->GetStartAngle();
	double endAngle = pArc->GetEndAngle();
	*/

	bounded_arc arc(SPAposition(pCenterPoint->GetX(), pCenterPoint->GetY(), 0.0),
				    SPAposition(pStartPoint->GetX(), pStartPoint->GetY(), 0.0),
					SPAposition(pEndPoint->GetX(), pEndPoint->GetY(), 0.0),
					SPAunit_vector(0.0, 0.0, 1.0));

	EDGE * pEdge = 0;

	API_BEGIN
	
		/*
        result = api_mk_ed_ellipse(SPAposition(pCenterPoint->GetX(), pCenterPoint->GetY(), 0.0),
								   SPAunit_vector(0.0, 0.0, 1.0),
								   SPAvector(1.0, 0.0, 0.0) * radius,
								   1.0,
								   startAngle, endAngle,
								   pEdge);
	    */
		pEdge = arc.make_edge();
		// check_outcome(result);
	
	API_END

	return pEdge;
}

MrAxis2 PmeSketchUtility::GetCoordinateSystem(PmeReference * pReference)
{
	PmeSketch * pSketch = GetSketch(pReference);

	PmeFeature * pFeature = pSketch->GetCreator();
	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);	

	return pSketchFeature->GetCoordinateSystem();
}

MrAxis1 PmeSketchUtility::GetRevolutionAxis(PmeReference * pReference)
{
	PmeSketch * pSketch = GetSketch(pReference);

	PmeFeature * pFeature = pSketch->GetCreator();
	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);	

	PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();
	PmeStdSketchGeometries::SizeType size = pGeometries->GetSize();

	ENTITY_LIST  elist;

	MrAxis1 axis(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0));

	for(PmeStdSketchGeometries::SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(i);
		if(pGeometry->GetType() == PmeStdSketchGeometryType_Centerline)
		{
			PmeStdSketchCenterline * pCenterline = static_cast<PmeStdSketchCenterline *>(pGeometry);
			PmeStdSketchControlPoint * pStartPoint = pCenterline->GetStartPoint();
			PmeStdSketchControlPoint * pEndPoint = pCenterline->GetEndPoint();

			MrPosition start(pStartPoint->GetX(), pStartPoint->GetY(), 0.0);
			MrPosition end(pEndPoint->GetX(), pEndPoint->GetY(), 0.0);

			axis = MrAxis1(start, MrDirection(MrVector(start, end)));
		}		
	}

	return axis;
}