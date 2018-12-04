#include "StdAfx.h"
#include ".\PmeStdSolidProtrusionExtrudeFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketch.h"
#include ".\PmeSketchUtility.h"

#include ".\attr_pme_facename.h"
#include ".\PmeQuery.h"
#include ".\attr_pme_vertexname.h"
#include ".\pmepersistentname.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature, PmeStdSolidExtrudeFeature)

PmeStdSolidProtrusionExtrudeFeature::PmeStdSolidProtrusionExtrudeFeature(PmePart * pPart)
: PmeStdSolidExtrudeFeature(pPart)
{
}

PmeStdSolidProtrusionExtrudeFeature::PmeStdSolidProtrusionExtrudeFeature(PmePart * pPart,
                                                                  PmeReference * pProfileSketch,
                                                                  double startDepth,
                                                                  PmeStdExtrudeEndType startCondition,
                                                                  double endDepth,
                                                                  PmeStdExtrudeEndType endCondition,
                                                                  bool isFlip)
: PmeStdSolidExtrudeFeature(pPart, pProfileSketch, startDepth, startCondition, endDepth, endCondition, isFlip)
{
}

PmeStdSolidProtrusionExtrudeFeature::~PmeStdSolidProtrusionExtrudeFeature(void)
{
}

void PmeStdSolidProtrusionExtrudeFeature::Update(void)
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
	//MergeCheckAfterOperation(pOldBody, old_face_list2);
	MergeCheck(pOldBody, old_face_list2, old_face_list3);
	//
}

void PmeStdSolidProtrusionExtrudeFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidProtrusionExtrudeFeature::IsCut(void)
{
	return false;
}

void PmeStdSolidProtrusionExtrudeFeature::CreateSolidBody(BODY *& pBody)
{
	BODY * pProfile = CreateShellFromSketch(GetProfileSketch());
	PmeThrowExceptionIf<PmeIlligalOperationException>(pProfile == 0);
	
	BODY * pStartBody = ExtrudeStartSolid(pProfile);
	BODY * pEndBody = ExtrudeEndSolid(pProfile);

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