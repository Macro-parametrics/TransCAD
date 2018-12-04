#include "StdAfx.h"
#include ".\pmestdsolidholecountersunkfeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeDatumPlane.h"
#include ".\PmeDatumPlaneUtility.h"
#include ".\PmeQuery.h"
#include ".\PmeArgumentTypeException.h"
#include ".\attr_pme_facename.h"
#include ".\attr_pme_vertexname.h"
#include ".\pmepersistentname.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidHoleCountersunkFeature, PmeStdSolidFeature)

//double DegreeToRadian(double degree) {return M_PI / 180.0 * degree;}

PmeStdSolidHoleCountersunkFeature::PmeStdSolidHoleCountersunkFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}	

PmeStdSolidHoleCountersunkFeature::PmeStdSolidHoleCountersunkFeature(PmePart * pPart,
																	 PmeReference * pTargetFace,
																	 double centerX,
																	 double centerY,
																	 double centerZ,
																	 double radius,
																	 double depth,
																	 double sinkRadius,
																	 double sinkAngle,
																	 double bottomAngle)
: PmeStdSolidFeature(pPart)
, m_pTargetFace(pTargetFace)
, m_centerX(centerX)
, m_centerY(centerY)
, m_centerZ(centerZ)
, m_radius(radius)
, m_depth(depth)
, m_sinkRadius(sinkRadius)
, m_sinkAngle(sinkAngle)
, m_bottomAngle(bottomAngle)
{
}

PmeStdSolidHoleCountersunkFeature::~PmeStdSolidHoleCountersunkFeature(void)
{
}

void PmeStdSolidHoleCountersunkFeature::Update(void)
{
	SetParentName(m_pTargetFace);
	
	PmePart * pPart = GetPart();
	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();

	BODY * pOldBody = pSolid->GetSolid();

	BODY * pNewBody = 0;
	CreateSolidBody(pNewBody);
	
	ASSERT(pNewBody);

	API_BEGIN

		if(pOldBody)
		{
			result = api_boolean(pNewBody, pOldBody, SUBTRACTION);
			check_outcome(result);

			if(result.ok())
			{
				PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
				pSolid->UpdateSolid(pOldBody);
				SetSolid(pSolid);
			}
		}
	API_END	
}

EDGE * PmeStdSolidHoleCountersunkFeature::CreateCircleEdge(double centerX, double centerY, double radius)
{
	EDGE * pEdge = 0;

	API_BEGIN

		result = api_mk_ed_ellipse(SPAposition(centerX, centerY, 0.0),
									SPAunit_vector(0.0, 0.0, 1.0),
									SPAvector(1.0, 0.0, 0.0) * radius,
									1.0, 0.0, 0.0,
									pEdge);

//		result = api_curve_arc(SPAposition(centerX, centerY, 0.0), radius, 0, 0, pEdge);
		check_outcome(result);

	API_END

	return pEdge;
}

void PmeStdSolidHoleCountersunkFeature::CreateSolidBody(BODY *& pBody)
{
	api_set_int_option("annotations", TRUE);
	
	BODY * pMainHoleBody = 0;
	ResetHoleCenterPosition();
	CreateRevolvedHoleBody(pMainHoleBody, m_centerX, m_centerY, m_centerZ, m_radius, m_depth, m_sinkRadius, m_sinkAngle, m_bottomAngle);

	AttachName(pMainHoleBody);

	PmeThrowExceptionIf<PmeIlligalOperationException>(pMainHoleBody == 0);

	API_BEGIN

		if(pMainHoleBody)
			pBody = pMainHoleBody;
		else
			pBody = NULL;
	
	API_END

	api_clear_annotations();
}

void PmeStdSolidHoleCountersunkFeature::CreateSolidHoleBody(BODY *& pBody, double centerX, double centerY, double centerZ,  double radius, double depth)
{
	EDGE * circle = 0;
	circle = CreateCircleEdge(0, 0, radius);

	API_BEGIN

		BODY * pWire = 0;
		result = api_make_ewire(1, &circle, pWire);
		check_outcome(result);

		//PmeFeature * pFeature = m_pTargetFeature->GetPart()->GetSelectionManager()->GetFeatureFromReference(m_pTargetFeature);

		//m_pTargetFace->GetPart()->GetSelectionManager()->GetObjectFromReference()

		// MrAxis2 coordinateSystem = PmeSketchUtility::GetCoordinateSystem(m_pTargetFace);
		MrAxis2 coordinateSystem = GetReferenceCoordinateSystem(m_pTargetFace);
		MrPosition origin = coordinateSystem.Location();
		MrDirection xDir = coordinateSystem.XDirection();
		MrDirection yDir = coordinateSystem.YDirection();		

		SPAtransf spaTransf = coordinate_transf(SPAposition(centerX, centerY, centerZ),
												SPAunit_vector(xDir.X(), xDir.Y(), xDir.Z()),
												SPAunit_vector(yDir.X(), yDir.Y(), yDir.Z()));

		result = api_apply_transf(pWire, spaTransf);

		if(result.ok())
		{
			PmeThrowExceptionIf<PmeIlligalOperationException>(pWire == 0);

			// cut extrude
			MrDirection zDir = coordinateSystem.ZDirection();
			zDir = -zDir;

			if(depth > 0.0)
			{
				MrVector vector = zDir * depth;
//				vector = -vector;

				SPAvector spaVector(vector.X(), vector.Y(), vector.Z());
				sweep_options options;

				BODY * pNewBody = 0;
				BODY * pTemp = 0;

				result = api_copy_body(pWire, pNewBody);
				check_outcome(result);

				result = api_sweep_with_options(pNewBody, spaVector, &options, pTemp);
				check_outcome(result);

				pBody = pNewBody;
				//
				circle = 0;
				//api_remove_wire_edge(circle);
			}
		}
		else
			pBody = 0;

	API_END

}

void PmeStdSolidHoleCountersunkFeature::CreateSolidConicBody(BODY *& pBody, double centerX, double centerY,double centerZ,  double radius, double angle)
{
	API_BEGIN

	double height;
	height = radius/tan((M_PI / 180.0 * angle)/2.0);

	SPAposition spaBottomPos(0, 0, 0);
	SPAposition spaTopPos(0, 0, -height);

	BODY * pNewBody = 0;
	result = api_solid_cylinder_cone(spaBottomPos, spaTopPos, radius, radius, 0, NULL, pNewBody);
	check_outcome(result);


	//PmeFeature * pFeature = m_pTargetFeature->GetPart()->GetSelectionManager()->GetFeatureFromReference(m_pTargetFeature);

	//m_pTargetFace->GetPart()->GetSelectionManager()->GetObjectFromReference()

	// MrAxis2 coordinateSystem = PmeSketchUtility::GetCoordinateSystem(m_pTargetFace);
	MrAxis2 coordinateSystem = GetReferenceCoordinateSystem(m_pTargetFace);
	MrPosition origin = coordinateSystem.Location();
	MrDirection xDir = coordinateSystem.XDirection();
	MrDirection yDir = coordinateSystem.YDirection();		

	SPAtransf spaTransf = coordinate_transf(SPAposition(centerX, centerY, centerZ),
		SPAunit_vector(xDir.X(), xDir.Y(), xDir.Z()),
		SPAunit_vector(yDir.X(), yDir.Y(), yDir.Z()));

	result = api_apply_transf(pNewBody, spaTransf);

	if(result.ok())
	{
		PmeThrowExceptionIf<PmeIlligalOperationException>(pNewBody == 0);

		pBody = pNewBody;
	}
	else
		pBody = 0;

	API_END
}

MrAxis2 PmeStdSolidHoleCountersunkFeature::GetReferenceCoordinateSystem(PmeReference * pSketchPlane)
{
	MrAxis2 coordinateSystem;

	switch(pSketchPlane->GetReferenceType())
	{
	case PmeReferenceType_ExplicitModelObject:
		coordinateSystem = PmeDatumPlaneUtility::GetCoordinateSystem(pSketchPlane);
		break;
	case PmeReferenceType_Brep:
		{
			ENTITY * pEntity = GetPart()->GetSelectionManager()->GetBrepFromReference(pSketchPlane);
			PmeThrowExceptionIf<PmeArgumentTypeException>(strcmp(pEntity->type_name(), "face") != 0);

			coordinateSystem = PmeQueryFaceLocalCoordinate((FACE *)pEntity);
		}
		break;
	}

	return coordinateSystem;
}

// 16-02-19 권순조 (리볼브처럼 Hole 바디 생성)
void PmeStdSolidHoleCountersunkFeature::CreateRevolvedHoleBody(BODY *& pBody, double centerX, double centerY, double centerZ, double radius, double depth, double sinkRadius, double sinkAngle, double bottomAngle)
{
	std::vector<EDGE *> edges;
	 
	EDGE * pLine1 = 0;
	EDGE * pLine2 = 0;
	EDGE * pLine3 = 0;
	EDGE * pLine4 = 0;
	EDGE * pLine5 = 0;

	MrAxis2 coordinateSystem = GetReferenceCoordinateSystem(m_pTargetFace);
	MrPosition origin = coordinateSystem.Location();
	MrDirection XDir = coordinateSystem.XDirection();
	MrDirection YDir = coordinateSystem.YDirection();
	double X = XDir.Y()*YDir.Z()-XDir.Z()*YDir.Y();
	double Y = XDir.Z()*YDir.X()-XDir.X()*YDir.Z();
	double Z = XDir.X()*YDir.Y()-XDir.Y()*YDir.X();
	MrDirection ZDir(X,Y,Z);
	
	// Hole의 회전체 단면 점 생성
	SPAposition A(centerX, centerY, centerZ);
	SPAposition B(A.x() + sinkRadius*XDir.X(), A.y() + sinkRadius*XDir.Y(), A.z() + sinkRadius*XDir.Z());
	SPAposition C(B.x() - (sinkRadius-radius)*XDir.X() - ((sinkRadius-radius)/tan((M_PI/180*sinkAngle)/2))*ZDir.X(), 
					B.y() - (sinkRadius-radius)*XDir.Y() - ((sinkRadius-radius)/tan((M_PI/180*sinkAngle)/2))*ZDir.Y(),
					B.z() - (sinkRadius-radius)*XDir.Z() - ((sinkRadius-radius)/tan((M_PI/180*sinkAngle)/2))*ZDir.Z());
	SPAposition D(C.x() - (depth-((sinkRadius-radius)/tan((M_PI/180*sinkAngle)/2)))*ZDir.X(), 
					C.y() - (depth-((sinkRadius-radius)/tan((M_PI/180*sinkAngle)/2)))*ZDir.Y(), 
					C.z() - (depth-((sinkRadius-radius)/tan((M_PI/180*sinkAngle)/2)))*ZDir.Z());
	SPAposition E(D.x() - radius*XDir.X() - (radius/tan((M_PI/180*bottomAngle)/2))*ZDir.X(), 
					D.y() - radius*XDir.Y() - (radius/tan((M_PI/180*bottomAngle)/2))*ZDir.Y(), 
					D.z() - radius*XDir.Z() - (radius/tan((M_PI/180*bottomAngle)/2))*ZDir.Z());

	
	// Hole의 회전체 단면 선 생성 및 저장
	api_mk_ed_line(A, B, pLine1);
	api_mk_ed_line(B, C, pLine2);
	api_mk_ed_line(C, D, pLine3);
	api_mk_ed_line(D, E, pLine4);
	api_mk_ed_line(E, A, pLine5);

	edges.push_back(pLine1);
	edges.push_back(pLine2);
	edges.push_back(pLine3);
	edges.push_back(pLine4);
	edges.push_back(pLine5);

	// 선으로부터 폐곡선 Wire 생성
	BODY ** ppWires = NULL;
	int nWires = 5;
	
	//CreateWire(ppWires,nWires, edges);
	outcome result = api_make_ewires((int)edges.size(), &edges[0], nWires, ppWires);	
	
	ENTITY_LIST wlist;

	for(int i = 0; i < nWires; ++ i)
	{
		outcome isClosed = api_closed_wire(ppWires[i]);

		wlist.add(ppWires[i]);		
	}
	
	ACIS_DELETE [] STD_CAST ppWires;


	// 폐곡선 Wire로부터 Shell 생성
	BODY * pShell = 0;
	ENTITY_LIST outWires;	

	api_cover_planar_wires(wlist, pShell, outWires);
	
	SPAvector vec(ZDir.X(),ZDir.Y(),ZDir.Z());

	// Hole 바디 생성
	BODY * holeBody = RevolveHoleBody(pShell, SPAposition(centerX,centerY,centerZ), vec);
	pBody = holeBody;
}

// 16-02-19 권순조
BODY * PmeStdSolidHoleCountersunkFeature::RevolveHoleBody(BODY *& pProfile, const SPAposition & location, const SPAvector & direction)
{
	sweep_options options;

	BODY * pNewBody = 0;
	BODY * pTemp = 0;

	API_BEGIN
		result = api_copy_body(pProfile, pNewBody);
		check_outcome(result);

		options.set_sweep_angle(2*M_PI);

		result = api_sweep_with_options(pNewBody, location, direction, &options, pTemp);
	
		if(result.ok())
			return pNewBody;
	API_END

	return NULL;
}

void PmeStdSolidHoleCountersunkFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
{
	pBody = 0;

	BODY * pNewBody = 0;
	CreateSolidBody(pNewBody);

	ASSERT(pNewBody);

	API_BEGIN
        result = api_apply_transf(pNewBody, transformation);
		
		if(result.ok())
			pBody = pNewBody;
		
	API_END
}

bool PmeStdSolidHoleCountersunkFeature::IsCut(void)
{
	return true;
}

// 17-03-03 권순조
void PmeStdSolidHoleCountersunkFeature::ResetHoleCenterPosition(void)
{
	// 타겟 면
	FACE * pFace = (FACE *)GetPart()->GetSelectionManager()->GetBrepFromReference(m_pTargetFace);
	
	SPAposition center(m_centerX, m_centerY, m_centerZ); // 중심
	SPAposition foot; // 중심에서 타겟 면까지의 최단거리에 이르는 점
	
	pFace->geometry()->equation().point_perp(center, foot);

	// 두 점이 다르면 중심을 변경
	// 이는 타겟 면에 변동이 있을 때 반드시 필요
	if (center != foot)
	{
		m_centerX = foot.x();
		m_centerY = foot.y();
		m_centerZ = foot.z();
	}
}

// 16-02-19 권순조
void PmeStdSolidHoleCountersunkFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);
	
	ENTITY_LIST annotationListLateral;

	api_find_annotations(annotationListLateral, is_SWEEP_ANNO_EDGE_LAT);

	annotationListLateral.init();

	SWEEP_ANNO_EDGE_LAT * pAnnotationEdgeLat;
	
	int nFace = 0;

	while((pAnnotationEdgeLat = (SWEEP_ANNO_EDGE_LAT *)annotationListLateral.next()) != NULL)
	{
 		ENTITY_LIST annotationInputs;
		pAnnotationEdgeLat->inputs(annotationInputs);
		int count = annotationInputs.count();
		
		if(annotationInputs.count() == 1)
		{
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();
			//
			CString edgeName;
			edgeName.Format(_T("Line%d"), nFace);
			CString faceName = GetName() + ",0," + edgeName +",0,0,0,HoleFeature:0,0:0;0";

			new ATTRIB_FACENAME(pFace, faceName);
		}
		else if(annotationInputs.count() == 0)
		{
			int a = 0;
		}

		nFace++;
	}
}