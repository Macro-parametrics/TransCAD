#include "StdAfx.h"
#include ".\PmeStdSolidRevolveWithExternalAxisFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketch.h"
#include ".\PmeSketchUtility.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature, PmeStdSolidRevolveFeature)

PmeStdSolidRevolveWithExternalAxisFeature::PmeStdSolidRevolveWithExternalAxisFeature(PmePart * pPart)
: PmeStdSolidRevolveFeature(pPart)
{
}

PmeStdSolidRevolveWithExternalAxisFeature::PmeStdSolidRevolveWithExternalAxisFeature(PmePart * pPart,
                                                                  PmeReference * pProfileSketch,
                                                                  double startAngle,
                                                                  PmeStdRevolveEndType startCondition,
                                                                  double endAngle,
                                                                  PmeStdRevolveEndType endCondition,
																  const MrAxis1 & revolveAxis,
																  bool isCut,
                                                                  bool isFlip)
: PmeStdSolidRevolveFeature(pPart, pProfileSketch, startAngle, startCondition, endAngle, endCondition, isFlip)
, m_revolveAxis(revolveAxis)
, m_isCut(isCut)
, m_startAngle(startAngle)
, m_endAngle(endAngle)
{
}

PmeStdSolidRevolveWithExternalAxisFeature::~PmeStdSolidRevolveWithExternalAxisFeature(void)
{
}

void PmeStdSolidRevolveWithExternalAxisFeature::Update(void)
{
	SetParentName(GetProfileSketch());

	PmePart * pPart = GetPart();
	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
	
	BODY * pOldBody = pSolid->GetSolid();

	BODY * pNewBody = 0;
	CreateSolidBody(pNewBody);

	ASSERT(pNewBody);

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
	MergeCheck(pOldBody, old_face_list2, old_face_list3);
	//
}

void PmeStdSolidRevolveWithExternalAxisFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidRevolveWithExternalAxisFeature::IsCut(void)
{
	return m_isCut;
}

void PmeStdSolidRevolveWithExternalAxisFeature::CreateSolidBody(BODY *& pBody)
{
	BODY * pProfile = CreateShellFromSketch(GetProfileSketch());
	PmeThrowExceptionIf<PmeIlligalOperationException>(pProfile == 0);
	
	BODY * pStartBody = 0;
	BODY * pEndBody = 0;
	
	api_set_int_option("annotations", TRUE);

	// StartBody 생성
	if (m_startAngle != 0)
	{	
		if (!IsFlip())
			pStartBody = RevolveWithBlind(pProfile, m_revolveAxis, m_startAngle);
		else
			pStartBody = RevolveWithBlind(pProfile, MrMath::Reverse(m_revolveAxis), m_startAngle);
		
		AttachName(pStartBody); // StartBody에 대해서 Naming. 각각 따로 해주어야 함
	}
	// EndBody 생성
	if (m_endAngle != 0)
	{
		if (!IsFlip())
			pEndBody = RevolveWithBlind(pProfile, MrMath::Reverse(m_revolveAxis), m_endAngle);
		else
			pEndBody = RevolveWithBlind(pProfile, m_revolveAxis, m_endAngle);
		
		AttachName(pEndBody);  // EndBody에 대해서 Naming
	}

	api_clear_annotations();

	PmeThrowExceptionIf<PmeIlligalOperationException>(pStartBody == 0 && pEndBody == 0);
	
	API_BEGIN

		if(pStartBody && pEndBody)
		{
			result = api_boolean(pEndBody, pStartBody, UNION);
		}
		else if(pEndBody)
			pStartBody = pEndBody;
		
		pBody = pStartBody;

	API_END
}