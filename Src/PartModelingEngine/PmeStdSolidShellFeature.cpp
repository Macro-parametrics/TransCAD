#include "StdAfx.h"
#include ".\pmestdsolidshellfeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeReferences.h"
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
#include ".\PmePersistentNameAPI.h"


PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidShellFeature, PmeStdSolidFeature)

//double DegreeToRadian(double degree) {return M_PI / 180.0 * degree;}

PmeStdSolidShellFeature::PmeStdSolidShellFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}	

PmeStdSolidShellFeature::PmeStdSolidShellFeature(PmePart * pPart,
												PmeReferences * pTargetFaces,
												double innerThickness,
												double outerThickness)
: PmeStdSolidFeature(pPart)
, m_pTargetFaces(pTargetFaces)
, m_innerThickness(innerThickness)
, m_outerThickness(outerThickness)
{
	m_pTargetFaces = pTargetFaces->Clone();
}

PmeStdSolidShellFeature::~PmeStdSolidShellFeature(void)
{
}

// 16-02-22 권순조
void PmeStdSolidShellFeature::Update(void)
{
	SetParentName(m_pTargetFaces);
	PmeThrowExceptionIf<PmeIlligalOperationException>(m_pTargetFaces == 0);
	PmeThrowExceptionIf<PmeIlligalOperationException>(m_innerThickness < 0);
	PmeThrowExceptionIf<PmeIlligalOperationException>(m_outerThickness < 0);

	api_set_int_option("annotations", TRUE);

	PmePart * pPart = GetPart();
	BODY* pOldBody = pPart->GetExplicitModel()->GetSolid()->GetSolid();
	
	// Shell 적용 전의 Face 목록을 저장. SplitCheck를 위함
	ENTITY_LIST old_face_list1;
	get_faces((ENTITY *) pOldBody, old_face_list1);

	bool result = CreateShellBody(pOldBody);

	if(result)
	{
		PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
		pSolid->UpdateSolid(pOldBody);
		SetSolid(pSolid);
	}
	
	SplitCheck(pOldBody, old_face_list1);
	AttachName(pOldBody);
	
	api_clear_annotations();
}

bool PmeStdSolidShellFeature::CreateShellBody(BODY *& pBody)
{
	// Shell의 타겟 면
	ENTITY_LIST targetFaces = m_pTargetFaces->CreateEntityList();
	
	std::vector<FACE*> pOpenFaces;					// faces being omitted.
	for (int i = 0; i < targetFaces.count(); ++i)
	{
		pOpenFaces.push_back((FACE *)targetFaces[i]);
	}
	
	const int nOpen = targetFaces.count();			// number of faces being omitted.
	double innerDeafualt = (-1)*m_innerThickness;	// default inner offset (usually -).
	double outerDeafualt = m_outerThickness;		// default outer offset (usually +).
	lop_options* options = 0;						// local operations options. NULL argument will set the default values.

	// 기존 솔리드의 Bounding box를 가져온다.
	SPAposition minPoint;
	SPAposition maxPoint;
	WCS * pWCS = NULL;
	SPAboxing_options boxingOptions(pWCS, SPAboxing_tight);

	api_get_entity_box(pBody, minPoint, maxPoint, &boxingOptions);
	
	// Bounding box의 최솟값/최댓값을 1만큼 감소/증가시킨다.
	// Shell Operation의 작업범위 설정을 위함
	for (int i = 0; i < 3; ++i)
	{
		minPoint.set_coordinate(i, minPoint.coordinate(i) - 100);
		maxPoint.set_coordinate(i, maxPoint.coordinate(i) + 100);
	}

	API_BEGIN

		result = api_hollow_body_specific(pBody, nOpen, &pOpenFaces[0], innerDeafualt, outerDeafualt, 0, 0, 0, 0, 0, 0, minPoint, maxPoint, options);
		check_outcome(result);

		if(!result.ok())
			return false;

	API_END

	return true;
}

// 16-03-02 권순조
void PmeStdSolidShellFeature::AttachName(BODY *& pBody)
{
	ENTITY_LIST faceList;
	api_get_faces(pBody, faceList);

	// Shell 특징형상을 통해 생성 된 면의 네이밍은 두께 방향의 맞은 편 면의 이름을 따름.
	// 최단거리가 Shell의 두께와 일치하는 경우, 해당 면의 이름을 따르게 한다.
	for (int i = 0; i < faceList.count(); ++i)
	{
		FACE * pFace = (FACE *)faceList[i];

		CString faceName;
        PmePersistentNameAPI::FindFaceName(pFace, faceName);

		// 새로 생성된 면인 경우 진입
		if(faceName == "")
		{
            for (int j = 0; j < faceList.count(); ++j)
			{
				FACE * pFace1 = (FACE *)faceList[j];
				
				CString faceName1;
				PmePersistentNameAPI::FindFaceName(pFace1, faceName1);

				const char * faceType1 = get_entity_type_string((ENTITY*)pFace);
				const char * faceType2 = get_entity_type_string((ENTITY*)pFace1);

				if 	((i != j)							// 자기 자신이 아닌 경우.
					&& (faceName1 != "")				// 기존 면인 경우.
					&& (faceType1 == faceType2))		// face의 타입이 같은 경우.
				{
					// api_planar_face_pr 속성 목록
					double req_rel_accy = 0;		// relative precision desired
					double area;					// area returned
					SPAposition centre, centre1;	// centroid return
					double moment_a;				// first principal moment
					double moment_b;				// second principal moment
					SPAunit_vector axis_a, axis_a1;	// first principal axis
					SPAunit_vector axis_b, axis_b1;	// second principal axis
					double est_rel_accy_achieved;	// estimate of relative accuracy achieved
					AcisOptions* ao = NULL;
				
					// Shell 면의 속성 취득. 중심점 (centre) 및 주축(axis_a, axis_b)을 구하기 위함.
					api_planar_face_pr(pFace, req_rel_accy, area, centre, moment_a, moment_b, axis_a, axis_b, est_rel_accy_achieved, ao);
					// 기존 면의 속성 취득
					api_planar_face_pr(pFace1, req_rel_accy, area, centre1, moment_a, moment_b, axis_a1, axis_b1, est_rel_accy_achieved, ao);
					
					// Shell면과 기존 면의 Normal 벡터 취득
					SPAunit_vector axis_c, axis_c1;
					
					axis_c.set_x(axis_a.y()*axis_b.z()-axis_a.z()*axis_b.y());
					axis_c.set_y(axis_a.z()*axis_b.x()-axis_a.x()*axis_b.z());
					axis_c.set_z(axis_a.x()*axis_b.y()-axis_a.y()*axis_b.x());
					
					axis_c1.set_x(axis_a1.y()*axis_b1.z()-axis_a1.z()*axis_b1.y());
					axis_c1.set_y(axis_a1.z()*axis_b1.x()-axis_a1.x()*axis_b1.z());
					axis_c1.set_z(axis_a1.x()*axis_b1.y()-axis_a1.y()*axis_b1.x());
					
					// api_entity_entity_distance 속성 목록
					double      distance;
					SPAposition pos1, pos2;
					param_info  ent_info1, ent_info2;

					// 두 면의 최단 거리(distance)를 구함
					api_entity_entity_distance((ENTITY*)pFace, (ENTITY*)pFace1, pos1, pos2, distance, ent_info1, ent_info2, ao);

					// 두 면의 최단 거리가 Shell의 두께와 같은 경우에 진입. distance1, distance2 모두 비교
					// Cylindrical face의 경우 10e-14정도의 오차가 발생
					if ((abs(m_innerThickness + m_outerThickness - distance) < 0.0000000001))
					{
						const char * planar = "planar face";
						const char * cylindrical = "cylindrical face";

						if(((*faceType1 == *planar) && (axis_c == (-1)*axis_c1))			// Planar의 경우, 법선 방향 반대
							|| ((*faceType1 == *cylindrical) && (axis_c == axis_c1)))	// Cylindrical의 경우, 법선 방향 동일
						{
							// 이름 부여
							CString faceName = GetName() + ",{" + faceName1 + "},ShellFeature:0,0:0;0";
							new ATTRIB_FACENAME(pFace, faceName);
							
							PmeFeatureTagMarker::Detach(pFace);
							PmeFeatureTagMarker::Attach(pFace, this);

							break;
						}
					}		
				}
			}
		}
	}

	//AttachFeatureTagToNewFaces(pBody);
}

// 16-08-09 권순조
void PmeStdSolidShellFeature::GetElementsfromFaceName(CString faceName, CString & tempElementsName)
{
	int prev, next;
	int count = 3;
	CString s1;

	prev = 0;
	next = faceName.Find(_T(','), prev);

	if (faceName.Find("SweepFeature") != -1)
		count = 5;

	for (int i = 0; i < count; ++i)
	{
		s1 = faceName.Mid(prev, next - prev);
		tempElementsName = tempElementsName + s1 + ",";

		prev = next + 1;
		next = faceName.Find(_T(','), prev);
	}
}