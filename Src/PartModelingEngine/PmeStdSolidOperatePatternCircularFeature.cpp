#include "StdAfx.h"
#include ".\PmeStdSolidOperatePatternCircularFeature.h"
#include ".\PmeStdSolidOperatePatternRectangularFeature.h"
#include ".\PmePart.h"
#include ".\PmeFeature.h"
#include ".\PmeFeatures.h"
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
#include ".\IPmePattern.h"

#include <algorithm>

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature, PmeStdSolidFeature)

double DegreeToRadian(double degree) {return M_PI / 180.0 * degree;}

PmeStdSolidOperatePatternCircularFeature::PmeStdSolidOperatePatternCircularFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}

PmeStdSolidOperatePatternCircularFeature::PmeStdSolidOperatePatternCircularFeature(PmePart * pPart,
								 PmeReferences * pTargetFeatures,
								 const MrAxis1 & centerAxis,
                                 int angleNumber,
                                 double angleIncrement,
								 int radialNumber,
                                 double radialSpacing,
                                 bool radialAlignment)
								 : PmeStdSolidFeature(pPart)
								 , m_pTargetFeatures(pTargetFeatures)
								 , m_centerAxis(centerAxis)
								 , m_angleNumber(angleNumber)
								 , m_angleIncrement(angleIncrement)
								 , m_radialNumber(radialNumber)
								 , m_radialSpacing(radialSpacing)
								 , m_radialAlignment(radialAlignment)
{
	m_pTargetFeatures = pTargetFeatures->Clone();
}

PmeStdSolidOperatePatternCircularFeature::~PmeStdSolidOperatePatternCircularFeature(void)
{
}


void PmeStdSolidOperatePatternCircularFeature::Update(void)
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

void PmeStdSolidOperatePatternCircularFeature::ReorderTargetFeatures(void)
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

// 16-11 권순조 추가
void PmeStdSolidOperatePatternCircularFeature::CreateSolidBody(void)
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
void PmeStdSolidOperatePatternCircularFeature::CreatePatternBody(BODY *& pBody)
{
	// 입력된 바디에 대해서 패턴 바디를 생성
	BODY * pPatternBody = 0;
	
	API_BEGIN

	for(int i = 0; i < m_angleNumber; ++i)
	{
		for(int j = 0; j < m_radialNumber; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			
			// 패턴 대상 특징형상의 원본 바디 및 고유 명칭 복사
			BODY * pNewBody = 0;
			result = api_copy_body(pBody, pNewBody);
			CopyFaceNames(pBody, pNewBody);
			
			// 원본 바디 회전
			RotateBody(pNewBody, i, j);

			// 회전된 바디에 이름을 붙임
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
void PmeStdSolidOperatePatternCircularFeature::RotateBody(BODY *& pBody, int angleNum, int radialNum)
{
	outcome result;
	MrDirection dir;
	MrVector trans;
	mass_props mp;
	mass_props_options mpo;		
	SPAtransf trsf;
	
	// 회전 각도
	double angle = angleNum*m_angleIncrement;

	/// 회전 중심을 원점으로 이동 (바디 이동)
	trsf = translate_transf(SPAvector(-m_centerAxis.Location().X(), -m_centerAxis.Location().Y(), -m_centerAxis.Location().Z()));
	result = api_apply_transf(pBody, trsf);

	// 원본 특징형상의 무게중심
	result = api_body_mass_props(pBody, mp, &mpo);
	SPAposition centroid_org = mp.get_centroid();
		
	// 특징형상 원본을 주어진 각도만큼 회전 이동
	trsf = rotate_transf(DegreeToRadian(angle), SPAvector(m_centerAxis.Direction().X(), m_centerAxis.Direction().Y(), m_centerAxis.Direction().Z()));
	result = api_apply_transf(pBody, trsf);
			
	// 회전된 특징형상의 무게중심
	result = api_body_mass_props(pBody, mp, &mpo);
	SPAposition centroid_trsf = mp.get_centroid();

	// RadialAlignment가 false일 때, 특징형상이 회전되지 않은 상태로 회전되어야 함.
	// 따라서 특징형상을 다시 제자리에 위치시킨 후 두 무게중심의 좌표 차이만큼 직선으로 transformation을 시킴
	if(!m_radialAlignment && angleNum != 0)
	{
		// 회전된 방향의 반대로 재회전. 이 때 특징형상은 원위치
		trsf = rotate_transf(-DegreeToRadian(angle), SPAvector(m_centerAxis.Direction().X(), m_centerAxis.Direction().Y(), m_centerAxis.Direction().Z()));
		result = api_apply_transf(pBody, trsf);
		
		// 두 무게중심의 차를 이용하여 이동 방향과 거리 계산
		dir.SetCoordinates(centroid_trsf.x()-centroid_org.x(), 
							centroid_trsf.y()-centroid_org.y(), 
							centroid_trsf.z()-centroid_org.z());
		trans = pow(pow(centroid_trsf.x()-centroid_org.x(),2)
					+pow(centroid_trsf.y()-centroid_org.y(),2)
					+pow(centroid_trsf.z()-centroid_org.z(),2),0.5) * dir;

		// 이동 방향으로 직선 이동
		trsf = translate_transf(SPAvector(trans.X(), trans.Y(), trans.Z()));
		result = api_apply_transf(pBody, trsf);
	}
	////

	// 회전 중심에서 Radial 방향으로 뻗어나가는 벡터(radialDir) 계산
	double axis[3], cog[3], radialDir[3];
	axis[0] = m_centerAxis.Direction().X();
	axis[1] = m_centerAxis.Direction().Y();
	axis[2]= m_centerAxis.Direction().Z();
						 
	cog[0]= centroid_trsf.x();
	cog[1] = centroid_trsf.y();
	cog[2] = centroid_trsf.z();

	for (int k = 0; k < 3; ++k)
		radialDir[k] = cog[k] - (axis[k]*(axis[0]*cog[0]+axis[1]*cog[1]+axis[2]*cog[2]))/(pow(axis[0],2)+pow(axis[1],2)+pow(axis[2],2));
	
	// Radial 방향으로  직선 이동
	if (!(radialDir[0] == 0 && radialDir[1] == 0 && radialDir[2] == 0))
	{
		dir.SetCoordinates(radialDir[0],radialDir[1],radialDir[2]);
		trans = radialNum * m_radialSpacing * dir;
			
		trsf = translate_transf(SPAvector(trans.X(), trans.Y(), trans.Z()));
		result = api_apply_transf(pBody, trsf);
	}

	// 회전 중심을 원래대로 이동 (바디 이동)
	trsf = translate_transf(SPAvector(m_centerAxis.Location().X(), m_centerAxis.Location().Y(), m_centerAxis.Location().Z()));
	result = api_apply_transf(pBody, trsf);

	ASSERT(pBody);
}

// 16-11 권순조 추가
void PmeStdSolidOperatePatternCircularFeature::CopyFaceNames(BODY *& pOldBody, BODY *& pNewBody)
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
void PmeStdSolidOperatePatternCircularFeature::AttachName(BODY *& pBody, int angleNum, int radialNum)
{
	AttachFeatureTag(pBody);
	
	ENTITY_LIST face_list;
	api_get_faces((ENTITY*) pBody, face_list);  

	for (int i = 0; i < face_list.count(); ++i) 
	{
		FACE * pFace = (FACE*)face_list[i];
		ATTRIB_FACENAME * pAttrib = (ATTRIB_FACENAME*)find_attrib(pFace, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);
		CString pfaceName = pAttrib->GetFaceName();
		
		CString patternInfo;
		patternInfo.Format(_T(",%d,%d"), angleNum, radialNum);
		
		pfaceName = GetName() + patternInfo + ",{" + pfaceName + "},PatternFeature:0,0:0;0";
		new ATTRIB_FACENAME(pFace, pfaceName);
	}
}

/*
// 15-12 권순조 수정
void PmeStdSolidOperatePatternCircularFeature::CreateSolidBody(BODY *& pBody)
{
	for (int k = 0; k < (int)m_featureList.size(); ++k)
	{
		BODY * pPatternBody = 0; // Pattern Body 저장을 위함
	
		PmeFeature * pFeature = m_featureList[k];
		PmeThrowExceptionIf<PmeIlligalOperationException>(!pFeature);

		IPmePattern * pPattern = dynamic_cast<IPmePattern *>(pFeature);
		PmeThrowExceptionIf<PmeIlligalOperationException>(!pPattern);
		
		BOOL_TYPE pType = (pPattern->IsCut()) ? SUBTRACTION : UNION;
		isCut = pPattern->IsCut();

		API_BEGIN

		for(int i = 0; i < m_angleNumber; ++ i)
		{
			double angle = i*m_angleIncrement;
		
			outcome result;
			MrDirection dir;
			MrVector trans;
			mass_props mp;
			mass_props_options mpo;
		
			for(int j = 0; j < m_radialNumber; ++ j)
			{
				SPAtransf trsf;
				
				// 패턴 대상 특징형상 원본 바디 생성
				BODY * pNewBody = pBody;
				
				if (pNewBody == 0)
					pPattern->Transform(trsf, pNewBody);
			

				/// 회전 중심을 원점으로 이동시키기 위해 회전 중심만큼 바디를 이동
				trsf = translate_transf(SPAvector(-m_centerAxis.Location().X(), -m_centerAxis.Location().Y(), -m_centerAxis.Location().Z()));
				result = api_apply_transf(pNewBody, trsf);

				// 특징형상 원본의 무게중심
				result = api_body_mass_props(pNewBody, mp, &mpo);
				SPAposition centroid_org = mp.get_centroid();
		
				// 특징형상 원본을 주어진 각도만큼 회전
				trsf = rotate_transf(DegreeToRadian(angle), SPAvector(m_centerAxis.Direction().X(), m_centerAxis.Direction().Y(), m_centerAxis.Direction().Z()));
				result = api_apply_transf(pNewBody, trsf);
			
				// 회전된 특징형상의 무게중심
				result = api_body_mass_props(pNewBody, mp, &mpo);
				SPAposition centroid = mp.get_centroid();

				// RadialAlignment가 false일 때, 특징형상이 회전되지 않은 상태로 패턴을 적용해야 함.
				// 따라서 특징형상을 다시 제자리에 위치시킨 후 두 무게중심의 좌표 차이만큼 직선으로 transformation을 시킴
				if(!m_radialAlignment && i != 0)
				{
					// 회전된 방향의 반대로 재회전. 이 때 특징형상은 제자리에 다시 위치하게 된다.
					trsf = rotate_transf(-DegreeToRadian(angle), SPAvector(m_centerAxis.Direction().X(), m_centerAxis.Direction().Y(), m_centerAxis.Direction().Z()));
					result = api_apply_transf(pNewBody, trsf);
				
					// 두 무게중심의 차를 이용하여 이동 방향과 거리 계산
					dir.SetCoordinates(centroid.x()-centroid_org.x(), centroid.y()-centroid_org.y(), centroid.z()-centroid_org.z());
					trans = pow(pow(centroid.x()-centroid_org.x(),2)
							+pow(centroid.y()-centroid_org.y(),2)
							+pow(centroid.z()-centroid_org.z(),2),0.5) * dir;

					// 이동 방향으로 직선 이동
					trsf = translate_transf(SPAvector(trans.X(), trans.Y(), trans.Z()));
					result = api_apply_transf(pNewBody, trsf);
				}
				////

				// 회전 중심에서 Radial 방향으로 뻗어나가는 벡터(radialDir) 계산
				// 이 때, cog는 회전된 특징형상의 무게중심
				double axis[3], cog[3], radialDir[3];
				axis[0] = m_centerAxis.Direction().X();
				axis[1] = m_centerAxis.Direction().Y();
				axis[2]= m_centerAxis.Direction().Z();
						 
				cog[0]= centroid.x();
				cog[1] = centroid.y();
				cog[2] = centroid.z();

				for (int k = 0; k < 3; ++k)
					radialDir[k] = cog[k] - (axis[k]*(axis[0]*cog[0]+axis[1]*cog[1]+axis[2]*cog[2]))/(pow(axis[0],2)+pow(axis[1],2)+pow(axis[2],2));
				////

				// Radial 방향으로  직선 이동
				dir.SetCoordinates(radialDir[0],radialDir[1],radialDir[2]);
				trans = j * m_radialSpacing * dir;
			
				trsf = translate_transf(SPAvector(trans.X(), trans.Y(), trans.Z()));
				result = api_apply_transf(pNewBody, trsf);
				
				trsf = translate_transf(SPAvector(m_centerAxis.Location().X(), m_centerAxis.Location().Y(), m_centerAxis.Location().Z()));
				result = api_apply_transf(pNewBody, trsf);

				ASSERT(pNewBody);

				if(!(i == 0 && j == 0))
					AttachName(pNewBody, i, j);

				if (pPatternBody)
					result = api_boolean(pNewBody, pPatternBody, UNION);
				else
					result = api_copy_body(pNewBody, pPatternBody);
			
				ASSERT(result.ok());
				////
			}		
		}
		
		API_END

	pBody = pPatternBody;
	}
}



void PmeStdSolidOperatePatternCircularFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidOperatePatternCircularFeature::IsCut(void)
{
	return isCut;
}
*/

