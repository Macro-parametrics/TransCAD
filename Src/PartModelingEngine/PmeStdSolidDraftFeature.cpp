#include "StdAfx.h"
#include ".\pmestdsoliddraftfeature.h"
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


PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidDraftFeature, PmeStdSolidFeature)



PmeStdSolidDraftFeature::PmeStdSolidDraftFeature(PmePart * pPart)
: PmeStdSolidFeature(pPart)
{
}	

PmeStdSolidDraftFeature::PmeStdSolidDraftFeature(PmePart * pPart,
												PmeReferences * pTargetFaces,
												const MrAxis1 & pullingDirection,
												double draftAngle)
: PmeStdSolidFeature(pPart)
, m_pTargetFaces(pTargetFaces)
, m_pullingDirection(pullingDirection)
, m_draftAngle(draftAngle)
{
	m_pTargetFaces = pTargetFaces->Clone();
}

PmeStdSolidDraftFeature::~PmeStdSolidDraftFeature(void)
{
}

// 16-03-01 권순조
void PmeStdSolidDraftFeature::Update(void)
{
	SetParentName(m_pTargetFaces);
	PmeThrowExceptionIf<PmeIlligalOperationException>(m_pTargetFaces == 0);
	PmeThrowExceptionIf<PmeIlligalOperationException>(m_draftAngle < 0);
	
	api_set_int_option("annotations", TRUE);

	PmePart * pPart = GetPart();
	BODY* pOldBody = pPart->GetExplicitModel()->GetSolid()->GetSolid();
	
	
	// Shell의 타겟 면
	ENTITY_LIST targetFaces = m_pTargetFaces->CreateEntityList();
	
	std::vector<FACE*> pDraftFaces;					// faces being omitted.
	for (int i = 0; i < targetFaces.count(); ++i)
	{
		pDraftFaces.push_back((FACE*)targetFaces[i]);
	}
	
	const int nDraft = targetFaces.count();				// number of faces being drafted.
	double draftAngle = DegreeToRadian(m_draftAngle);	// default draft angle.
	
	const SPAposition point(m_pullingDirection.Location().X(),	m_pullingDirection.Location().Y(),	m_pullingDirection.Location().Z());
	const SPAunit_vector normal(m_pullingDirection.Direction().X(),m_pullingDirection.Direction().Y(),m_pullingDirection.Direction().Z());
	
	lop_options* options = 0;						// local operations options. NULL argument will set the default values.


	// 기존 솔리드의 Bounding box를 가져온다.
	SPAposition minPoint;
	SPAposition maxPoint;
	WCS * pWCS = NULL;
	SPAboxing_options boxingOptions(pWCS, SPAboxing_tight);

	api_get_entity_box(pOldBody, minPoint, maxPoint, &boxingOptions);
	
	// Bounding box의 최솟값/최댓값을 1만큼 감소/증가시킨다.
	// Shell Operation의 작업범위 설정을 위함
	for (int i = 0; i < 3; ++i)
	{
		minPoint.set_coordinate(i, minPoint.coordinate(i) - 100);
		maxPoint.set_coordinate(i, maxPoint.coordinate(i) + 100);
	}

	API_BEGIN

		result = api_taper_faces(nDraft, &pDraftFaces[0], point, normal, draftAngle, minPoint, maxPoint, options);
		check_outcome(result);

		if(result.ok())
		{
			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
			pSolid->UpdateSolid(pOldBody);
			SetSolid(pSolid);
		}

	API_END
	AttachName(pOldBody);

	api_clear_annotations();
}

// 16-03-01 권순조
void PmeStdSolidDraftFeature::AttachName(BODY *& pBody)
{
	// Draft의 타겟 면
	ENTITY_LIST targetFaces = m_pTargetFaces->CreateEntityList();
	
	for (int i = 0; i < targetFaces.count(); ++i)
	{
		FACE * pFace = (FACE*)targetFaces[i];
		ATTRIB_FACENAME * pAttrib = (ATTRIB_FACENAME*)find_attrib(pFace, ATTRIB_PME_TYPE, ATTRIB_FACENAME_TYPE);
		CString pfaceName = pAttrib->GetFaceName();
		
		pfaceName = GetName() + ",{" + pfaceName + "},DraftFeature:0,0:0;0";
		new ATTRIB_FACENAME(pFace, pfaceName);

		PmeFeatureTagMarker::Detach(pFace);
		PmeFeatureTagMarker::Attach(pFace, this);
	}
}

// 16-08-09 권순조
void PmeStdSolidDraftFeature::GetElementsfromFaceName(CString faceName, CString & tempElementsName)
{
	int prev = 0;
	int next = 0;
	next = faceName.Find(_T(','), prev);

	CString s1 = faceName.Mid(prev, next - prev);

	prev = next+1;
	next = faceName.Find(_T(','), prev);
	prev = next+1;
	next = faceName.Find(_T(','), prev);
	CString s2 = faceName.Mid(prev, next - prev);

	tempElementsName = s1 + "," + s2;
}