#include "StdAfx.h"
#include "PmeStdSolidLoftSectionsFeature.h"
#include <algorithm>

#include "PmePart.h"
#include "PmeSelectionManager.h"
#include "PmeSolid.h"
#include "PmeExplicitModel.h"

#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\PmeDatumPlane.h"
#include ".\PmeDatumPlaneUtility.h"
#include ".\pmepersistentname.h"
#include ".\attr_pme_vertexname.h"
#include ".\PmePersistentNameAPI.h"
#include ".\PmeArgumentTypeException.h"

#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchCenterline.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchCircularArc.h"
#include ".\MrTolerance.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidLoftSectionsFeature, PmeStdSolidFeature)

PmeStdSolidLoftSectionsFeature::PmeStdSolidLoftSectionsFeature(PmePart * pPart)
	: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidLoftSectionsFeature::PmeStdSolidLoftSectionsFeature(PmePart * pPart,
	PmeReferences * pSections,
	bool isCut)
	: PmeStdSolidFeature(pPart)
	, m_pSections(pSections)
	, m_isCut(isCut)
{
	m_pStartSketch = m_pSections->GetItem(0);
	m_pEndSketch = m_pSections->GetItem(m_pSections->GetSize() - 1);
}

PmeStdSolidLoftSectionsFeature::~PmeStdSolidLoftSectionsFeature(void)
{

}

void PmeStdSolidLoftSectionsFeature::Update(void)
{
 	SetParentName(m_pSections);
	
	PmePart * pPart = GetPart();
 	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
 
 	BODY * pOldBody = pSolid->GetSolid();

	// 로프트 바디 생성
	BODY * pNewBody = 0;
 	CreateSolidBody(pNewBody);
	
	//
	ENTITY_LIST old_face_list1, old_face_list2, old_face_list3;
	get_faces((ENTITY*) pOldBody, old_face_list1);
	get_faces((ENTITY*) pNewBody, old_face_list2);

	CopyFaces(old_face_list2, old_face_list3);
	//

 	API_BEGIN
		if(pOldBody)
		{
			if (!IsCut())
				result = api_boolean(pNewBody, pOldBody, UNION);
			else
				result = api_boolean(pNewBody, pOldBody, SUBTRACTION);
			
			check_outcome(result);
		}
		else
		{
			if (!IsCut())
				pOldBody = pNewBody;
		}

		if(result.ok())
		{
			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
			pSolid->UpdateSolid(pOldBody);
			SetSolid(pSolid);
		}
		else
		{
			TRACE("\nextension err: %s\n",result.get_error_info()->error_message()); 
		}
		check_outcome(result);
 	API_END	

	//
	SplitCheck(pOldBody, old_face_list1);
	SplitCheck(pOldBody, old_face_list2);
	MergeCheck(pOldBody, old_face_list2, old_face_list3);
	//

}

// 로프트 바디 생성
void PmeStdSolidLoftSectionsFeature::CreateSolidBody(BODY *& pBody)
{
	api_set_int_option("annotations", TRUE);

	skin_options options;
	options.set_solid(1);

	ENTITY_LIST pSectionList;

	for (int i = 0; i < GetLoftSections()->GetSize(); i++)
	{
		PmeReference * pReference = GetLoftSections()->GetItem(i);
		
		// Face인 경우
		if (pReference->GetReferenceType() == PmeReferenceType_Brep)
		{
			ENTITY * pFace = pReference->GetPart()->GetSelectionManager()->GetBrepFromReference(pReference);
			pSectionList.add(pFace);
		}
		// Sketch인 경우
		else if (pReference->GetReferenceType() == PmeReferenceType_ExplicitModelObject)
		{
			BODY * pSketch = CreateWireFromSketch(pReference);
			pSectionList.add(pSketch);
		}
	}
	
	API_BEGIN
		// Loft 생성하는 API
		result = api_skin_wires(pSectionList.count(), pSectionList, pBody, &options);
		
		if(!result.ok())
			TRACE("\nextension err: %s\n",result.get_error_info()->error_message()); 

		check_outcome(result);
		
	API_END

	AttachName(pBody);

	api_clear_annotations();
}

void PmeStdSolidLoftSectionsFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidLoftSectionsFeature::IsCut(void)
{
	if(m_isCut)
		return true;
	else
		return false;
}



// 16-02-22 권순조
void PmeStdSolidLoftSectionsFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);
	
	// 시작 면 네이밍
	ENTITY_LIST annotationListStart;
	api_find_annotations(annotationListStart, is_SKIN_ANNO_START_FACE);

	SKIN_ANNO_START_FACE	* pAnnotationStartCaps;
	
	annotationListStart.init();

	while((pAnnotationStartCaps = (SKIN_ANNO_START_FACE *)annotationListStart.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;
		pAnnotationStartCaps->inputs(annotationInputs);		

		FACE * pStartFace = pAnnotationStartCaps->face();

		CString startFaceName = GetName() + ",0,-1,0,0,0,LoftFeature:0,0:0;0";

		new ATTRIB_FACENAME(pStartFace, startFaceName);
	}

	// 끝 면 네이밍
	ENTITY_LIST annotationListEnd;
	api_find_annotations(annotationListEnd, is_SKIN_ANNO_END_FACE);

	SKIN_ANNO_END_FACE	* pAnnotationEndCaps;
	
	annotationListEnd.init();
	
	while((pAnnotationEndCaps = (SKIN_ANNO_END_FACE *)annotationListEnd.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;
		pAnnotationEndCaps->inputs(annotationInputs);		

		FACE * pEndFace = pAnnotationEndCaps->face();

		CString endFaceName = GetName() + ",0,-2,0,0,0,LoftFeature:0,0:0;0";

		new ATTRIB_FACENAME(pEndFace, endFaceName);

	}
	
	// 옆 면 네이밍
	ENTITY_LIST annotationListLateral;
	api_find_annotations(annotationListLateral, is_SKIN_ANNO_LAT_FACE);

	annotationListLateral.init();

	SKIN_ANNO_LAT_FACE * pAnnotationEdgeLat;

	CString startSketchName = PmeSketchUtility::GetSketch(GetStartSketch())->GetName();
	CString endSketchName = PmeSketchUtility::GetSketch(GetEndSketch())->GetName();

	while((pAnnotationEdgeLat = (SKIN_ANNO_LAT_FACE *)annotationListLateral.next()) != NULL)
	{
		ENTITY_LIST annotationInputs;
		pAnnotationEdgeLat->inputs(annotationInputs);
		
		FACE * pFace = (FACE *)pAnnotationEdgeLat->face();

		CString startEdgeName, endEdgeName;

		// Loft로 생성된 면과 시작 스케치(Start Sketch) 및 끝 스케치(End Sketch)를 비교하여, 
		// 해당 면 생성에 사용된 지오메트리의 이름을 가져온다.
		GetEdgeNameFromSketchReference(pFace, m_pStartSketch, startEdgeName);	// 시작 스케치와 비교
		GetEdgeNameFromSketchReference(pFace, m_pEndSketch, endEdgeName);		// 끝 스케치와 비교

		CString faceName = GetName() + "," + startSketchName + "," + startEdgeName + "," + endSketchName + "," + endEdgeName + ",0,LoftFeature:0,0:0;0";

		new ATTRIB_FACENAME(pFace, faceName);
	}
}

// 16-02-22 권순조 (16-07-29 권순조 수정)
void PmeStdSolidLoftSectionsFeature::GetEdgeNameFromSketchReference(FACE *& pSourceFace, PmeReference *& pSketchReference, CString & edgeName)
{
	// 엣지 정보 리스트에 저장	
	ENTITY_LIST elist;
	api_get_edges(pSourceFace, elist);

	// 스케치 피쳐 (윗면 혹은 아랫면) 불러오기
	PmeFeature * pFeature = PmeSketchUtility::GetSketch(pSketchReference)->GetCreator();
	PmeStdSketchFeature * pSketchFeature = static_cast<PmeStdSketchFeature *>(pFeature);	
	
	// 스케치 지오메트리 정보
	PmeStdSketchGeometries * pGeometries = pSketchFeature->GetGeometries();
	PmeStdSketchGeometries::SizeType size = pGeometries->GetSize();

	// 스케치 좌표계
	MrAxis2 coordinateSystem = pSketchFeature->GetCoordinateSystem();


	// 스케치 지오메트리들과의 좌표 비교
	// 동일한 지오메트리 요소의 스케치 이름을 매칭
	for(int i = 0; i < elist.count(); ++i)
	{
		EDGE* pEdge = (EDGE*)elist[i];
		
		/** 1차 비교 **/
		// Edge 정보가 이미 저장되어 있는 스케치 지오메트리 중 하나와 매칭이 되는 경우
		if (find_named_attrib(pEdge, pSketchFeature->GetName()))
		{
			edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge, pSketchFeature->GetName()))->value();
			return;
		}
		else
		{
			/** 2차 비교 **/
			// Edge 정보와 스케치 지오메트리 전부와 좌표 비교.
			// 이 때, Edge를 스케치 좌표계(위 coordinateSystem)로 이동시켜준다.
			for(PmeStdSketchGeometries::SizeType j = 0; j < size; ++ j)
			{
				PmeStdSketchGeometry * pGeometry = pGeometries->GetItem(j);

				// 일반적인 Loft에서 스케치에 원(Circle)이 존재하는 경우는, 스케치 내부에 다른 요소가 없다.
				// 이 경우, 바로 Circle의 이름을 매칭
				if (pGeometry->GetType() == PmeStdSketchGeometryType_Circle)
				{
					edgeName = pGeometry->GetName();
					return;
				}
				else // Line 또는 Arc 인 경우
				{
					EDGE * pEdge1 = PmeSketchUtility::CreateEdgeFromGeometry(pGeometry);
					EDGE * pEdge2 = CreateTransformedEdge(pEdge, coordinateSystem);

					// pEdge1, pEdge2가 모두 생성되고, pEdge1과 pEdge2의 좌표가 동일한 경우 진입
					if(pEdge1 && pEdge2 && IsEdgesSame(pEdge1, pEdge2))
					{
						edgeName = ((ATTRIB_GEN_STRING *)find_named_attrib(pEdge1, pSketchFeature->GetName()))->value();
						return;				
					}
				}
			}
		}
	}

}

// 두 엣지의 좌표 비교. 일치하면 True, 아니면 False 리턴 (16-07-29 권순조 수정)
bool PmeStdSolidLoftSectionsFeature::IsEdgesSame(EDGE * pEdge1, EDGE * pEdge2)
{
	// 시작점-시작점, 끝점-끝점의 좌표가 같을 때
	if(MrTolerance::IsZeroDistance(pEdge1->start_pos().x() - pEdge2->start_pos().x())
		&& MrTolerance::IsZeroDistance(pEdge1->start_pos().y() - pEdge2->start_pos().y())
		&& MrTolerance::IsZeroDistance(pEdge1->start_pos().z() - pEdge2->start_pos().z())
		&& MrTolerance::IsZeroDistance(pEdge1->end_pos().x() - pEdge2->end_pos().x())
		&& MrTolerance::IsZeroDistance(pEdge1->end_pos().y() - pEdge2->end_pos().y())
		&& MrTolerance::IsZeroDistance(pEdge1->end_pos().z() - pEdge2->end_pos().z()))
	{
		return true;
	}
	// 시작점-끝점, 끝점-시작점의 좌표가 같을 때
	else if(MrTolerance::IsZeroDistance(pEdge1->start_pos().x() - pEdge2->end_pos().x())
		&& MrTolerance::IsZeroDistance(pEdge1->start_pos().y() - pEdge2->end_pos().y())
		&& MrTolerance::IsZeroDistance(pEdge1->start_pos().z() - pEdge2->end_pos().z())
		&& MrTolerance::IsZeroDistance(pEdge1->end_pos().x() - pEdge2->start_pos().x())
		&& MrTolerance::IsZeroDistance(pEdge1->end_pos().y() - pEdge2->start_pos().y())
		&& MrTolerance::IsZeroDistance(pEdge1->end_pos().z() - pEdge2->start_pos().z()))
	{
		return true;
	}
	else if (IsEdgesIncluded(pEdge1, pEdge2))
	{
		return true;
	}

	return false;
}

// 두 엣지의 포함 관계 계산 (16-07-29 권순조)
bool PmeStdSolidLoftSectionsFeature::IsEdgesIncluded(EDGE * pEdge1, EDGE * pEdge2)
{
	// 한 직선이 나머지 한 직선에 완전히 포함된 경우를 계산. 점과 직선의 거리를 통해 계산
	// 스케치의 Arc와, 로프트 생성 후 Arc의 일부분으로 구성된 Edge가 같음을 찾기 위해 활용
	// 시작점과 끝점이 같은 직선과 호의 경우에도 true 값이 나올 것이므로 로프트 네이밍에서만 활용

	double dist_E1s_E2 = 0;
	double dist_E1e_E2 = 0;
	double dist_E2s_E1 = 0;
	double dist_E2e_E1 = 0;

	outcome result;
	SPAposition in_point;
	SPAposition closest_pos;
	param_info  ent_info;
	AcisOptions *ao = NULL;

	in_point = pEdge1->start_pos();
	result = api_entity_point_distance((ENTITY*)pEdge2, in_point, closest_pos, dist_E1s_E2, ent_info, ao);

	in_point = pEdge1->end_pos();
	result = api_entity_point_distance((ENTITY*)pEdge2, in_point, closest_pos, dist_E1e_E2, ent_info, ao);

	in_point = pEdge2->start_pos();
	result = api_entity_point_distance((ENTITY*)pEdge1, in_point, closest_pos, dist_E2s_E1, ent_info, ao);

	in_point = pEdge2->end_pos();
	result = api_entity_point_distance((ENTITY*)pEdge1, in_point, closest_pos, dist_E2e_E1, ent_info, ao);
		
	if ((MrTolerance::IsZeroDistance(dist_E1s_E2) && MrTolerance::IsZeroDistance(dist_E1e_E2)) 
		|| (MrTolerance::IsZeroDistance(dist_E2s_E1) && MrTolerance::IsZeroDistance(dist_E2e_E1)))
		return true;

	return false;
}