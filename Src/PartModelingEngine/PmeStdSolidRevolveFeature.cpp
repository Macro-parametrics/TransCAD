#include "StdAfx.h"
#include <algorithm>
#include ".\PmeStdSolidRevolveFeature.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\PmePersistentNameAPI.h"
#include <vector>
#include <string>

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidRevolveFeature, PmeStdSolidFeature)

PmeStdSolidRevolveFeature::PmeStdSolidRevolveFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidRevolveFeature::PmeStdSolidRevolveFeature(PmePart * pPart,
                                                           PmeReference * pProfileSketch,
                                                           double startAngle,
                                                           PmeStdRevolveEndType startCondition,
                                                           double endAngle,
                                                           PmeStdRevolveEndType endCondition,
														   bool isFlip) 
: PmeStdSolidFeature(pPart)
, m_pProfileSketch(pProfileSketch)
, m_startAngle(startAngle)
, m_startCondition(startCondition)
, m_endAngle(endAngle)
, m_endCondition(endCondition)
, m_isFlip(isFlip)
{
}

PmeStdSolidRevolveFeature::~PmeStdSolidRevolveFeature(void)
{
}

MrAxis1 PmeStdSolidRevolveFeature::GetInternalAxis(bool isCut)
{
	MrAxis1 axis = PmeSketchUtility::GetRevolutionAxis(GetProfileSketch());
	if(isCut)
		axis = MrMath::Reverse(axis);

	MrAxis2 coordinateSystem = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch());
	MrAffineTransformation trsf = MrAffineTransformation::CreateCoordinateSystemTransformation(coordinateSystem, MrAxis2::OXY());

	return MrMath::Transform(axis, trsf);
}

BODY * PmeStdSolidRevolveFeature::RevolveStartSolid(BODY *& pProfile, bool isCut)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	MrAxis1 axis = GetInternalAxis(isCut);
	
	switch(GetInternalStartCondition())
	{
	case PmeStdRevolveEndType_Blind:
		{
			double angle = GetInternalStartAngle();
			if(angle == 0)
				break;
			pResult = RevolveWithBlind(pProfile, axis, angle);
		}
		break;
	}

	if(pResult)
        AttachName(pResult);
	
	api_clear_annotations();

	return pResult;
}

BODY * PmeStdSolidRevolveFeature::RevolveEndSolid(BODY *& pProfile, bool isCut)
{
	BODY * pResult = 0;

	api_set_int_option("annotations", TRUE);

	MrAxis1 axis = GetInternalAxis(isCut);

	switch(GetInternalEndCondition())
	{
	case PmeStdRevolveEndType_Blind:
		{
			double angle = GetInternalEndAngle();
			if(angle == 0)
				break;
			pResult = RevolveWithBlind(pProfile, MrMath::Reverse(axis), angle);
		}
		break;
	}

	if(pResult)
	{
		if(g_bNamingType)
			AttachName(pResult);
		else
			AttachName_pointbased(pResult);
	}
	api_clear_annotations();

	return pResult;
}

BODY * PmeStdSolidRevolveFeature::RevolveWithBlind(BODY *& pProfile, const MrAxis1 & axis, double angle)
{
	SPAposition spaRoot(axis.Location().X(), axis.Location().Y(), axis.Location().Z());
	SPAvector spaAxis(axis.Direction().X(), axis.Direction().Y(), axis.Direction().Z());
	sweep_options options;

	BODY * pNewBody = 0;
	BODY * pTemp = 0;

	API_BEGIN

		result = api_copy_body(pProfile, pNewBody);
		check_outcome(result);

		options.set_sweep_angle(DegreeToRadian(angle));

		result = api_sweep_with_options(pNewBody, spaRoot, spaAxis, &options, pTemp);
		check_outcome(result);

		if(result.ok())
			return pNewBody;

	API_END

	return 0;
}

void PmeStdSolidRevolveFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);
	
	ENTITY_LIST annotationListLateral;

	api_find_annotations(annotationListLateral, is_SWEEP_ANNO_EDGE_LAT);

	annotationListLateral.init();

	SWEEP_ANNO_EDGE_LAT * pAnnotationEdgeLat;
	
	CString sketchName = PmeSketchUtility::GetSketch(GetProfileSketch())->GetName();

	while((pAnnotationEdgeLat = (SWEEP_ANNO_EDGE_LAT *)annotationListLateral.next()) != NULL)
	{
        ENTITY_LIST annotationInputs;
		pAnnotationEdgeLat->inputs(annotationInputs);
		int count = annotationInputs.count();
		
		if(annotationInputs.count() == 1)
		{
			EDGE * pEdge = pAnnotationEdgeLat->profile_edge();
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();
			
			CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
			CString faceName = GetName() + "," + sketchName +"," + edgeName +",0,0,0,RevolveFeature:0,0:0;0";

			new ATTRIB_FACENAME(pFace, faceName);
		}
		else if(annotationInputs.count() == 0)
		{
			EDGE * pEdge = pAnnotationEdgeLat->profile_edge();
			FACE * pFace = (FACE *)pAnnotationEdgeLat->lateral_face();

			CString edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, sketchName))->value();
			CString faceName = GetName() + "," + sketchName +"," + edgeName +",0,0,0,RevolveFeature:0,0:0;0";

			new ATTRIB_FACENAME(pFace, faceName);
		}
	}

	ENTITY_LIST annotationListEnd;
	api_find_annotations(annotationListEnd, is_SWEEP_ANNO_END_CAPS);

	MrDirection sketchNormal = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).ZDirection();
	MrPosition sketchOrigin = PmeSketchUtility::GetCoordinateSystem(GetProfileSketch()).Location();

	SWEEP_ANNO_END_CAPS	* pAnnotationEndCaps;
	
	annotationListEnd.init();

	while((pAnnotationEndCaps = (SWEEP_ANNO_END_CAPS *)annotationListEnd.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;

		//pAnnotationEdgeLat->inputs(annotationInputs);		

		FACE * pStartFace = pAnnotationEndCaps->start_face();
		FACE * pEndFace = pAnnotationEndCaps->end_face();

		MrDirection startNormal = PmeQueryFaceNormal(pStartFace, sketchOrigin);
		MrDirection endNormal = PmeQueryFaceNormal(pEndFace, sketchOrigin);

		bool isEndSolid = false;
		
		// StartSolid (반시계방향 회전): 스케치 평면의 Normal과 StartFace의 Normal이 동일
		// EndSolid (시계방향 회전): 스케치 평면의 Normal과 StartFace의 Normal이 반대
		if(!MrMath::IsEqual(startNormal, sketchNormal)) // EndSolid의 경우 진입
		{
			std::swap(pStartFace, pEndFace);
			isEndSolid = true;
		}

		CString startFaceName = GetName() + ",0,-1,0,0,0,RevolveFeature:0,0:0;0";
		CString endFaceName = GetName() + ",0,-2,0,0,0,RevolveFeature:0,0:0;0";
		

		/** 1. 일반적인 경우 **/
		// StartFace : 스케치 평면의 Normal과 동일 방향으로 회전하여 생기는 면 (시계방향) 
		// EndFace : 스케치 평면의 Normal과 반대 방향으로 회전하여 생기는 면 (반시계방향)
		if (!m_isFlip) // Flip이 아닌 경우
		{
			new ATTRIB_FACENAME(pStartFace, startFaceName);
			new ATTRIB_FACENAME(pEndFace, endFaceName);
		}
		else // Flip인 경우
		{
			new ATTRIB_FACENAME(pStartFace, endFaceName);
			new ATTRIB_FACENAME(pEndFace, startFaceName);
		}    

		/** 2. 시작면과 끝면이 엣지를 공유하며 전체 각도가 180도 인 경우 **/
		// 이 때, 두 면의 Merge가 발생할 수 있으므로 아래와 같이 처리
		if (IsSharingEdge(pStartFace, pEndFace))
		{	
			// StartAngle + EndEngle의 합이 180일 때 (단, 둘 중 하나가 0인 경우 포함)
			// 이 경우 무조건 StartFaceName을 가지도록 처리 (CATIA의 사례를 따름)
			if(GetInternalStartAngle() + GetInternalEndAngle() == 180.0)
			{
				new ATTRIB_FACENAME(pStartFace, startFaceName);
				new ATTRIB_FACENAME(pEndFace, startFaceName);
			}
			// StartAngle, EndAngle 둘 중 하나만 180일 때 (단, 둘 다 0보다 큰 경우)
			// 이 경우 StartSolid의 EndFace가 EndFace로, EndSolid의 EndFace가 StartFace로 남도록 처리 (단, Flip의 경우 반대)
			else if (pStartFace == pEndFace)
			{	
				if (!isEndSolid)	// StartSolid만 180도 일 때
				{
					if(!m_isFlip)	// Flip이 아닐 때
						new ATTRIB_FACENAME(pEndFace, endFaceName);
					else			// Flip일 때
						new ATTRIB_FACENAME(pEndFace, startFaceName);
				}
				else if (isEndSolid)// EndSolid만 180도 일 때
				{
					if(!m_isFlip)	// Flip이 아닐 때
						new ATTRIB_FACENAME(pEndFace, startFaceName);
					else			// Filp일 때
						new ATTRIB_FACENAME(pEndFace, endFaceName);
				}	
			}
		}

	}

}

bool PmeStdSolidRevolveFeature::IsSharingEdge(FACE * pFace1, FACE * pFace2)
{
	ENTITY_LIST vertex_list1, vertex_list2;
	get_vertices(pFace1, vertex_list1);
	get_vertices(pFace2, vertex_list2);
	
	SPAposition p1,p2;

	int count = 0;

	for (int i = 0; i < vertex_list1.count(); ++i)
	{
		VERTEX* pVert1 = (VERTEX*)vertex_list1[i];
		p1 = pVert1->geometry()->coords();

		for (int j = 0; j < vertex_list2.count(); ++j)
		{
			VERTEX* pVert2 = (VERTEX*)vertex_list2[j];
			p2 = pVert2->geometry()->coords();

			if((p1.x() == p2.x()) && (p1.y() == p2.y()) && (p1.z() == p2.z()))
				count ++;
			else
				continue;
		}
	}

	if (count >= 2)
		return true;
	else
		return false;


}

void PmeStdSolidRevolveFeature::AttachName_pointbased(BODY *& pBody)
{	
	ENTITY_LIST face_list;
	get_faces(pBody, face_list);

	int a = face_list.count();

	if (a >1)
	{
		for (int i = 0 ; i < a; i++)
		{
			FACE *f = (FACE *) face_list[i]; 
			
			EDGE * ce;
			ce =  f->loop()->start()->edge();

			SPAposition onePoint;
			onePoint = ce->start_pos();
			
			ELLIPSE* el = (ELLIPSE*)ce->geometry();

			SPAposition centerPoint;
			centerPoint = el->centre();

			double radius;
			radius = sqrt( (centerPoint.x() - onePoint.x()) * (centerPoint.x() - onePoint.x()) + (centerPoint.y() - onePoint.y()) * (centerPoint.y() - onePoint.y()) + (centerPoint.z() - onePoint.z()) * (centerPoint.z() - onePoint.z()));
				
			double vertexcoord[3];
			CString vertexNum[3];

			vertexcoord[0] = centerPoint.x();
			vertexcoord[1] = centerPoint.y();
			vertexcoord[2] = centerPoint.z();

			vertexNum[0].Format(_T("%3.2f"), vertexcoord[0]);
			vertexNum[1].Format(_T("%3.2f"), vertexcoord[1]);
			vertexNum[2].Format(_T("%3.2f"), vertexcoord[2]);
						
			CString radiusname;
			radiusname.Format(_T("%3.2f"), radius);

			CString faceName;

			faceName = "Face, 0, Rev1,(" + vertexNum[0] + ","+ vertexNum[1] +","+ vertexNum[2] +  "),"+ radiusname ;
			new ATTRIB_FACENAME(f, faceName);
		}	
	}
}

