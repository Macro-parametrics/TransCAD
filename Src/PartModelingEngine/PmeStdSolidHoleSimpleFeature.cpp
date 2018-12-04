#include "StdAfx.h"
#include ".\pmestdsolidholesimplefeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
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

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidHoleSimpleFeature, PmeStdSolidFeature)

//double DegreeToRadian(double degree) {return M_PI / 180.0 * degree;}

PmeStdSolidHoleSimpleFeature::PmeStdSolidHoleSimpleFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}	

PmeStdSolidHoleSimpleFeature::PmeStdSolidHoleSimpleFeature(PmePart * pPart,
																	 PmeReference * pTargetFace,
																	 double centerX,
																	 double centerY,
																	 double centerZ,
																	 double radius,
																	 double depth)
: PmeStdSolidFeature(pPart)
, m_pTargetFace(pTargetFace)
, m_centerX(centerX)
, m_centerY(centerY)
, m_centerZ(centerZ)
, m_radius(radius)
, m_depth(depth)
{
}

PmeStdSolidHoleSimpleFeature::~PmeStdSolidHoleSimpleFeature(void)
{
}

void PmeStdSolidHoleSimpleFeature::Update(void)
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

EDGE * PmeStdSolidHoleSimpleFeature::CreateCircleEdge(double centerX, double centerY, double radius)
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

void PmeStdSolidHoleSimpleFeature::CreateSolidBody(BODY *& pBody)
{
	api_set_int_option("annotations", TRUE);
	
	BODY * pMainHoleBody = 0;
	ResetHoleCenterPosition();
	CreateSolidHoleBody(pMainHoleBody, m_centerX, m_centerY, m_centerZ, m_radius, m_depth);

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

void PmeStdSolidHoleSimpleFeature::CreateSolidHoleBody(BODY *& pBody, double centerX, double centerY, double centerZ,  double radius, double depth)
{
	EDGE * circle = 0;
	circle = CreateCircleEdge(0, 0, radius);

	API_BEGIN

		BODY * pWire = 0;
		result = api_make_ewire(1, &circle, pWire);
		check_outcome(result);

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

			MrDirection zDir = coordinateSystem.ZDirection();
			zDir = -zDir;

			if(depth > 0.0)
			{
				MrVector vector = zDir * depth;

				SPAvector spaVector(vector.X(), vector.Y(), vector.Z());
				sweep_options options;

				BODY * pNewBody = 0;
				BODY * pTemp = 0;

				result = api_copy_body(pWire, pNewBody);
				check_outcome(result);

				result = api_sweep_with_options(pNewBody, spaVector, &options, pTemp);
				check_outcome(result);

				pBody = pNewBody;
				
				circle = 0;

			}
		}
		else
			pBody = 0;

	API_END

}

MrAxis2 PmeStdSolidHoleSimpleFeature::GetReferenceCoordinateSystem(PmeReference * pSketchPlane)
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

void PmeStdSolidHoleSimpleFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidHoleSimpleFeature::IsCut(void)
{
	return true;
}

// 17-03-03 권순조
void PmeStdSolidHoleSimpleFeature::ResetHoleCenterPosition(void)
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

void PmeStdSolidHoleSimpleFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);
	
	ENTITY_LIST annotationListLateral;

	api_find_annotations(annotationListLateral, is_SWEEP_ANNO_EDGE_LAT);

	annotationListLateral.init();

	SWEEP_ANNO_EDGE_LAT * pAnnotationEdgeLat;


	while((pAnnotationEdgeLat = (SWEEP_ANNO_EDGE_LAT *)annotationListLateral.next()) != NULL)
	{
        ENTITY_LIST annotationInputs;
		pAnnotationEdgeLat->inputs(annotationInputs);
		int count = annotationInputs.count();
		
		ASSERT(annotationInputs.count() == 1);

		FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();

		CString faceName = GetName() + ",0,Side,0,0,0,HoleFeature:0,0:0;0";

		new ATTRIB_FACENAME(pFace, faceName);
		
	}

	ENTITY_LIST annotationListEnd;
	api_find_annotations(annotationListEnd, is_SWEEP_ANNO_END_CAPS);



	SWEEP_ANNO_END_CAPS	* pAnnotationEndCaps;
	
	annotationListEnd.init();

	while((pAnnotationEndCaps = (SWEEP_ANNO_END_CAPS *)annotationListEnd.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;

		FACE * pEndFace = pAnnotationEndCaps->end_face();

		CString endFaceName = GetName() + ",0,Bottom,0,0,0,HoleFeature:0,0:0;0";

		new ATTRIB_FACENAME(pEndFace, endFaceName);        

	}
}