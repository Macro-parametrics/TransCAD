#include "StdAfx.h"
#include ".\PmeStdSolidOperatePatternRectangularFeature.h"
#include ".\PmeStdSolidOperatePatternCircularFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeReference.h"
#include ".\PmeReferences.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketchUtility.h"
#include ".\PmeSketch.h"
#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\IPmeTransformable.h"
#include ".\IPmePattern.h"

#include <algorithm>

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature, PmeStdSolidFeature)

PmeStdSolidOperatePatternRectangularFeature::PmeStdSolidOperatePatternRectangularFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidOperatePatternRectangularFeature::PmeStdSolidOperatePatternRectangularFeature(PmePart * pPart,
								 PmeReferences * pTargetFeatures,
								 double columnSpacing,
                                 const MrDirection & columnDirection,
                                 int columnNumber,
                                 double rowSpacing,
                                 const MrDirection & rowDirection,
                                 int rowNumber)
: PmeStdSolidFeature(pPart)
, m_pTargetFeatures(pTargetFeatures)
, m_columnSpacing(columnSpacing)
, m_columnDirection(columnDirection)
, m_columnNumber(columnNumber)
, m_rowSpacing(rowSpacing)
, m_rowDirection(rowDirection)
, m_rowNumber(rowNumber)
{
	m_pTargetFeatures = pTargetFeatures->Clone();
}

PmeStdSolidOperatePatternRectangularFeature::~PmeStdSolidOperatePatternRectangularFeature(void)
{
}

void PmeStdSolidOperatePatternRectangularFeature::Update(void)
{
	SetParentName(m_pTargetFeatures);
	ReorderTargetFeatures();
	CreateSolidBody();

	for (int i = 1; i < (int)m_bodyList.size(); ++i)
	{
		PmePart * pPart = GetPart();
		PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
	
		BODY * pOldBody = pSolid->GetSolid();
		BODY* pNewBody = m_bodyList[i];
		BOOL_TYPE type = m_boolTypeList[i];

		//
		ENTITY_LIST old_face_list1, old_face_list2;
		get_faces((ENTITY*) pOldBody, old_face_list1);
		get_faces((ENTITY*) pNewBody, old_face_list2);
		//

		API_BEGIN

			if(pOldBody)
			{
				result = api_boolean(pNewBody, pOldBody, type);
				check_outcome(result);
			}
			else
				pOldBody = pNewBody;

			if(result.ok())
			{
				PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
				pSolid->UpdateSolid(pOldBody);
				SetSolid(pSolid);
			}

		API_END

		// 
		SplitCheck(pOldBody, old_face_list1);
		SplitCheck(pOldBody, old_face_list2);
		//
	}
}

void PmeStdSolidOperatePatternRectangularFeature::ReorderTargetFeatures(void)
{
	m_featureList.clear();
	m_solidList.clear();

	// 입력 특징형상들을 모델링 순서에 맞게 재배열하여 저장
	// 감법 특징형상이 먼저 입력되는 경우를 방지하기 위함
	// 예를들어 육면체에 구멍을 뚫은 후 패턴시키려고 할 때, 사용자가 구멍을 먼저 입력할 경우를 대비
	for (int i = 0; i < m_pTargetFeatures->GetSize(); ++i)
	{
		PmeReference * m_targetFeature = m_pTargetFeatures->GetItem(i);
		
		if (m_targetFeature->GetReferenceType() == PmeReferenceType_Feature)
		{
			PmeFeature * pFeature = GetPart()->GetSelectionManager()->GetFeatureFromReference(m_targetFeature);
			
			m_featureList.push_back(pFeature);
		}
		else if (m_targetFeature->GetReferenceType() == PmeReferenceType_ExplicitModelObject)
		{
			if (GetPart()->GetExplicitModel()->FindByName(m_targetFeature->GetReferenceeName())->GetType() == PmeExplicitModelObjectType_Solid)
			{
				PmeExplicitModelObject * pExplicitModelObject = GetPart()->GetExplicitModel()->FindByName(m_targetFeature->GetReferenceeName());
				PmeSolid * pSolid = (PmeSolid *)pExplicitModelObject;
				
				m_solidList.push_back(pSolid);
			}
		}
	}

	// 모델링 순서에 따라 특징형상 재배열
	std::sort(m_featureList.begin(), m_featureList.end(),
		[](PmeFeature *& lhs, PmeFeature *& rhs){return lhs->GetOrder() < rhs->GetOrder();});
}


// 필렛, 챔퍼 등도 고려한 패턴 바디 생성 (미완성)
void PmeStdSolidOperatePatternRectangularFeature::CreateSolidBody(BODY *& pBody)
{
	BODY * temp = 0;
	
	for (int i = 0; i < (int)m_featureList.size(); ++i)
	{
		PmeFeature * pFeature = m_featureList[i];
		IPmePattern * pPattern = dynamic_cast<IPmePattern *>(pFeature);
		SPAtransf trsf;

		if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidShellFeature
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidDraftFeature
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidOffsetFeature	
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidFilletConstantFeature
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidChamferFeature)
		{
			pPattern->Transform(trsf, temp);
		}
		else
		{
			BODY * pFeatureBody = 0;
			pPattern->Transform(trsf, pFeatureBody);

			BOOL_TYPE pType = (pPattern->IsCut()) ? SUBTRACTION : UNION;
			
			//
			ENTITY_LIST old_face_list1, old_face_list2;
			get_faces((ENTITY*) temp, old_face_list1);
			get_faces((ENTITY*) pFeatureBody, old_face_list2);
			//

			API_BEGIN

				if(temp)
				{
					result = api_boolean(pFeatureBody, temp, pType);
					check_outcome(result);
				}
				else
					temp = pFeatureBody;

			API_END

			// 
			SplitCheck(temp, old_face_list1);
			SplitCheck(temp, old_face_list2);
			//
		}
	}

	CreatePatternBody(temp);

	pBody = temp;
}

// 16-11 권순조 추가
void PmeStdSolidOperatePatternRectangularFeature::CreateSolidBody(void)
{
	// 초기화
	m_bodyList.clear();
	m_boolTypeList.clear();

	// 입력된 모든 특징형상들에 대해 패턴 바디 생성
	// 이 때, 이미 생성된 패턴을 입력 받는 경우도 처리
	for (int i = 0; i < (int)m_featureList.size(); ++i)
	{
		// 입력 특징형상
		PmeFeature * pFeature = m_featureList[i];

		// 전이 특징형상 (필렛, 챔퍼 등)의 경우 건너뜀
		// 향 후, 고려 방안 강구
		if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidShellFeature
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidDraftFeature
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidOffsetFeature	
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidFilletConstantFeature
			|| pFeature->GetFeatureType() == PmeFeatureType_StdSolidChamferFeature)
			continue;
		
		// 원형 패턴일 때
		if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidOperatePatternCircularFeature)
		{
			PmeStdSolidOperatePatternCircularFeature * pCircPattern = dynamic_cast<PmeStdSolidOperatePatternCircularFeature *>(pFeature);
			pCircPattern->CreateSolidBody();
			
			for (int j = 0; j < pCircPattern->GetPatternBodySize(); ++j)
			{
				BODY * pTargetBody = pCircPattern->GetPatternBody(j);
				BOOL_TYPE pType = pCircPattern->GetPatternBodyType(j);
				m_bodyList.push_back(pTargetBody);
				m_boolTypeList.push_back(pType);
				
				CreatePatternBody(pTargetBody);
				
				m_bodyList.push_back(pTargetBody);
				m_boolTypeList.push_back(pType);
			}
		}
		// 사각 패턴일 때
		else if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidOperatePatternRectangularFeature)
		{
			PmeStdSolidOperatePatternRectangularFeature * pRectPattern = dynamic_cast<PmeStdSolidOperatePatternRectangularFeature *>(pFeature);
			pRectPattern->CreateSolidBody();
			
			for (int j = 0; j < pRectPattern->GetPatternBodySize(); ++j)
			{
				BODY * pTargetBody = pRectPattern->GetPatternBody(j);
				BOOL_TYPE pType = pRectPattern->GetPatternBodyType(j);
				m_bodyList.push_back(pTargetBody);
				m_boolTypeList.push_back(pType);
				
				CreatePatternBody(pTargetBody);
				
				m_bodyList.push_back(pTargetBody);
				m_boolTypeList.push_back(pType);
			}
		}
		// 패턴이 아닌 일반 특징형상의 경우
		else
		{
			IPmePattern * pPattern = dynamic_cast<IPmePattern *>(pFeature);
			BODY * pTargetBody = 0;
			BOOL_TYPE pType = (pPattern->IsCut()) ? SUBTRACTION : UNION;
			SPAtransf trsf;

			pPattern->Transform(trsf, pTargetBody);
			m_bodyList.push_back(pTargetBody);
			m_boolTypeList.push_back(pType);

			CreatePatternBody(pTargetBody);

			m_bodyList.push_back(pTargetBody);
			m_boolTypeList.push_back(pType);
		}
	}

	// PartBody가 입력 된 경우, 이에 대해 패턴 생성
	for (int i = 0; i < (int)m_solidList.size(); ++i)
	{
		BODY * pTargetBody = m_solidList[i]->GetSolid();
		m_bodyList.push_back(pTargetBody);
		m_boolTypeList.push_back(UNION);
		
		CreatePatternBody(pTargetBody);

		m_bodyList.push_back(pTargetBody);
		m_boolTypeList.push_back(UNION);
	}
}

// 16-11 권순조 추가
void PmeStdSolidOperatePatternRectangularFeature::CreatePatternBody(BODY *& pBody)
{
	// 입력된 바디에 대해서 패턴 바디를 생성
	BODY * pPatternBody = 0;
	
	MrVector translation;

	API_BEGIN

	for(int i = 0; i < m_columnNumber; ++ i)
	{
		for(int j = 0; j < m_rowNumber; ++ j)
		{
			if (i == 0 && j == 0)
				continue;
			
			// 패턴 대상 특징형상의 원본 바디 및 고유 명칭 복사
			BODY * pNewBody = 0;
			result = api_copy_body(pBody, pNewBody);
			CopyFaceNames(pBody, pNewBody);
			
			// 원본 특징형상 이동
			TranslateBody(pNewBody, i, j);
			
			// 이동한 바디에 이름을 붙임
			if(!(i == 0 && j == 0))
				AttachName(pNewBody, i, j);
			
			// 최종 패턴 바디에 합침
			if (pPatternBody)
				result = api_boolean(pNewBody, pPatternBody, UNION);
			else
			{
				// 첫 솔리드의 경우 최종 패턴 바디에 솔리드 및 고유 명칭 복사
				result = api_copy_body(pNewBody, pPatternBody);
				CopyFaceNames(pNewBody, pPatternBody);
			}

			ASSERT(result.ok());
		}
	}

	API_END
	
	// 최종 패턴 바디 리턴
	pBody = pPatternBody;
}

// 16-11 권순조 추가
void PmeStdSolidOperatePatternRectangularFeature::TranslateBody(BODY *& pBody, int colNum, int rowNum)
{
	MrVector translation;

	translation = colNum * m_columnSpacing * m_columnDirection + rowNum * m_rowSpacing * m_rowDirection;
	SPAtransf trsf = translate_transf(SPAvector(translation.X(), translation.Y(), translation.Z()));

	outcome result = api_apply_transf(pBody, trsf);

	ASSERT(pBody);
}

// 16-11 권순조 추가
void PmeStdSolidOperatePatternRectangularFeature::CopyFaceNames(BODY *& pOldBody, BODY *& pNewBody)
{
	// 바디를 카피한 이후, 이전 바디의 이름을 똑같이 복사 (단, 복사 된 바디여야 함)
	ENTITY_LIST old_face_list, new_face_list;
	api_get_faces((ENTITY*) pOldBody, old_face_list);
	api_get_faces((ENTITY*) pNewBody, new_face_list);

	for (int i = 0; i < old_face_list.count(); ++i)
	{
		FACE * pOldFace = (FACE*)old_face_list[i];
		ATTRIB_FACENAME * pAttrib = (ATTRIB_FACENAME*)find_attrib(pOldFace, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);

		if (pAttrib)
		{
			CString pOldfaceName = pAttrib->GetFaceName();

			FACE * pNewFace = (FACE*)new_face_list[i];
			new ATTRIB_FACENAME(pNewFace, pOldfaceName);
		}
	}
}

// 15-12 권순조 추가
void PmeStdSolidOperatePatternRectangularFeature::AttachName(BODY *& pBody, int colNum, int rowNum)
{
	AttachFeatureTag(pBody);
	
	ENTITY_LIST face_list;
	api_get_faces((ENTITY*) pBody, face_list);  

	for (int i = 0; i < face_list.count(); ++i) 
	{
		FACE * pFace = (FACE*)face_list[i];
		ATTRIB_FACENAME * pAttrib = (ATTRIB_FACENAME*)find_attrib(pFace, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);

		if (pAttrib)
		{
			CString pfaceName = pAttrib->GetFaceName();

			CString patternInfo;
			patternInfo.Format(_T(",%d,%d"), colNum, rowNum);
		
			pfaceName = GetName() + patternInfo + ",{" + pfaceName + "},PatternFeature:0,0:0;0";
			new ATTRIB_FACENAME(pFace, pfaceName);
		}
	}
}

/*
void PmeStdSolidOperatePatternRectangularFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidOperatePatternRectangularFeature::IsCut(void)
{
	return isCut;
}

// 15-12 권순조 수정
void PmeStdSolidOperatePatternRectangularFeature::CreateSolidBody(BODY *& pBody)
{
	PmeFeature * pFeature = m_pTargetFeature->GetPart()->GetSelectionManager()->GetFeatureFromReference(m_pTargetFeature);
	PmeThrowExceptionIf<PmeIlligalOperationException>(!pFeature);

	// 2010-05-03, 신수철
	IPmePattern * pPattern = dynamic_cast<IPmePattern *>(pFeature);
	PmeThrowExceptionIf<PmeIlligalOperationException>(!pPattern);

	IPmeTransformable * pTransformable = dynamic_cast<IPmeTransformable *>(pFeature);
	PmeThrowExceptionIf<PmeIlligalOperationException>(!pTransformable);

	BODY* pPatternBody = 0; // Pattern Body 저장을 위함
	MrVector translation;

	API_BEGIN

	for(int i = 0; i < m_columnNumber; ++ i)
	{
		for(int j = 0; j < m_rowNumber; ++ j)
		{

			translation = j * m_rowSpacing * m_rowDirection + i * m_columnSpacing * m_columnDirection;
			SPAtransf trsf = translate_transf(SPAvector(translation.X(), translation.Y(), translation.Z()));

			BODY * pNewBody = 0;
			pTransformable->Transform(trsf, pNewBody);
			
			ASSERT(pNewBody);
			
			//ENTITY_LIST faceList, edgeList, vertexList;
			//api_get_faces(pNewBody, faceList);
			//FACE * pFace = (FACE *)faceList[0];
			//api_get_edges(pFace, edgeList);
			//EDGE * pEdge = (EDGE *)edgeList[0];
			//
			//EDGE * pCopiedEdge;
			//api_copy_entity((ENTITY *)pEdge, (ENTITY *&)pCopiedEdge);
			//
			//result = api_apply_transf(pCopiedEdge, trsf);

			//api_get_vertices(pCopiedEdge, vertexList);
			//VERTEX * pVert = (VERTEX*)vertexList[0];

			if(!(i == 0 && j == 0))
				AttachName(pNewBody, i, j);

			// 2010-05-03, 신수철
			// circular pattern과 마찬가지로 pattern type (extrusion or cut) 추가
			BOOL_TYPE type = (pPattern->IsCut()) ? SUBTRACTION : UNION;

			if (pPatternBody)
				result = api_boolean(pNewBody, pPatternBody, UNION);
			else
				result = api_copy_body(pNewBody, pPatternBody);

			ASSERT(result.ok());
		}
	}

	pBody = pPatternBody;

	API_END
}
*/