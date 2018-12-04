#include "StdAfx.h"
#include ".\PmeStdSolidProtrusionSweepFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSketch.h"
#include ".\PmeSketchUtility.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidProtrusionSweepFeature, PmeStdSolidSweepFeature)

PmeStdSolidProtrusionSweepFeature::PmeStdSolidProtrusionSweepFeature(PmePart * pPart)
: PmeStdSolidSweepFeature(pPart)
{
}

PmeStdSolidProtrusionSweepFeature::PmeStdSolidProtrusionSweepFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 PmeReference * pGuideCurve)
: PmeStdSolidSweepFeature(pPart, pProfileSketch, pGuideCurve)
{
}

PmeStdSolidProtrusionSweepFeature::~PmeStdSolidProtrusionSweepFeature(void)
{
}

void PmeStdSolidProtrusionSweepFeature::Update(void)
{
	PmeReferences * pReferences = new PmeReferences();
	pReferences->Add(GetProfileSketch());
	pReferences->Add(GetGuideCurve());
	SetParentName(pReferences);
	
	BODY * pBody = 0;
	CreateSolidBody(pBody);

	PmePart * pPart = GetPart();
	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
	
	BODY * pOldBody = pSolid->GetSolid();

	//
	ENTITY_LIST old_face_list1, old_face_list2, old_face_list3;
	get_faces((ENTITY*) pOldBody, old_face_list1);
	get_faces((ENTITY*) pBody, old_face_list2);

	CopyFaces(old_face_list2, old_face_list3);
	//


	API_BEGIN

		//result = api_boolean(pBody, pOldBody, UNION);
		//check_outcome(result);

		if(pOldBody)
		{
			result = api_boolean(pBody, pOldBody, UNION);
			check_outcome(result);
		}
		else
			pOldBody = pBody;

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

void PmeStdSolidProtrusionSweepFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidProtrusionSweepFeature::IsCut(void)
{
	return false;
}

void PmeStdSolidProtrusionSweepFeature::CreateSolidBody(BODY *& pBody)
{
	BODY * pProfile = CreateShellFromSketch(GetProfileSketch());
	BODY * pGuideCurve = CreateWireFromSketch(GetGuideCurve());
	PmeThrowExceptionIf<PmeIlligalOperationException>(pProfile == 0 || pGuideCurve == 0);

	pBody = SweepSolid(pProfile, pGuideCurve);
	PmeThrowExceptionIf<PmeIlligalOperationException>(pBody == 0);
}