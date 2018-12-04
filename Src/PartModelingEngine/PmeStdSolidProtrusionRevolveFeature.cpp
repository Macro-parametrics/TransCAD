#include "StdAfx.h"
#include ".\PmeStdSolidProtrusionRevolveFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketch.h"
#include ".\PmeSketchUtility.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature, PmeStdSolidRevolveFeature)

PmeStdSolidProtrusionRevolveFeature::PmeStdSolidProtrusionRevolveFeature(PmePart * pPart)
: PmeStdSolidRevolveFeature(pPart)
{
}

PmeStdSolidProtrusionRevolveFeature::PmeStdSolidProtrusionRevolveFeature(PmePart * pPart,
                                                                  PmeReference * pProfileSketch,
                                                                  double startAngle,
                                                                  PmeStdRevolveEndType startCondition,
                                                                  double endAngle,
                                                                  PmeStdRevolveEndType endCondition,
                                                                  bool isFlip)
: PmeStdSolidRevolveFeature(pPart, pProfileSketch, startAngle, startCondition, endAngle, endCondition, isFlip)
{
}

PmeStdSolidProtrusionRevolveFeature::~PmeStdSolidProtrusionRevolveFeature(void)
{
}

void PmeStdSolidProtrusionRevolveFeature::Update(void)
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
			result = api_boolean(pNewBody, pOldBody, UNION);
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

void PmeStdSolidProtrusionRevolveFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidProtrusionRevolveFeature::IsCut(void)
{
	return false;
}

void PmeStdSolidProtrusionRevolveFeature::CreateSolidBody(BODY *& pBody)
{
	BODY * pProfile = CreateShellFromSketch(GetProfileSketch());
	PmeThrowExceptionIf<PmeIlligalOperationException>(pProfile == 0);

	BODY * pStartBody = RevolveStartSolid(pProfile);
	BODY * pEndBody = RevolveEndSolid(pProfile);

	ENTITY_LIST old_face_list1, old_face_list2;
	get_faces((ENTITY*) pStartBody, old_face_list1);
	get_faces((ENTITY*) pEndBody, old_face_list2);

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

	SplitCheck(pBody, old_face_list1);
	SplitCheck(pBody, old_face_list2);
}