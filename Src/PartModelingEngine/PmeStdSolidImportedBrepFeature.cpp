#include "StdAfx.h"
#include ".\PmeStdSolidImportedBrepFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeInterOp.h"

#include ".\attr_pme_facename.h"
#include ".\attr_pme_vertexname.h"
#include ".\PmeQuery.h"
#include ".\pmepersistentname.h"
#include ".\PmePersistentNameAPI.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSolidImportedBrepFeature, PmeStdSolidFeature)

PmeStdSolidImportedBrepFeature::PmeStdSolidImportedBrepFeature(PmePart * pPart, const CString & filePath)
: PmeStdSolidFeature(pPart)
, m_filePath(filePath)
{
}

PmeStdSolidImportedBrepFeature::~PmeStdSolidImportedBrepFeature(void)
{
	//m_pBrepBody = NULL;
}

void PmeStdSolidImportedBrepFeature::Update(void)
{
	PmePart * pPart = GetPart();
	PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
	
	BODY * pOldBody = pSolid->GetSolid();
	BODY * pNewBody = 0;
	CreateSolidBody(pNewBody);

	//ENTITY_LIST old_face_list1, old_face_list2, old_face_list3;
	//get_faces((ENTITY*) pOldBody, old_face_list1);
	//get_faces((ENTITY*) pNewBody, old_face_list2);

	API_BEGIN
	
		if (pOldBody)
		{
			result = api_boolean(pNewBody, pOldBody, UNION);
			check_outcome(result);
		}
		else
			pOldBody = pNewBody;
		
		if (result.ok())
		{
			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
			pSolid->UpdateSolid(pOldBody);
			SetSolid(pSolid);
		}

	API_END

	//SplitCheck(pOldBody, old_face_list1);
	//SplitCheck(pOldBody, old_face_list2);
	//MergeCheck(pOldBody, old_face_list2, old_face_list3);
}

void PmeStdSolidImportedBrepFeature::Transform(const SPAtransf & transformation, BODY *& pBody)
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

bool PmeStdSolidImportedBrepFeature::IsCut(void)
{
	return false;
}

void PmeStdSolidImportedBrepFeature::CreateSolidBody(BODY *& pBody)
{
	ENTITY_LIST list;

	// Brep 모델 읽어오기
	if(m_filePath.Right(4) == L".sat")
	{
		FILE * fp = NULL;

		fopen_s(&fp, m_filePath,"r"); // "r" : ASCII mode, "rb" : binary mode
		
		if(fp)
		{
			api_restore_entity_list(fp,TRUE, list); // TRUE : ASCII mode, FALSE : binary mode
			fclose(fp);
		}
	}
	else if(m_filePath.Right(4) == L".stp" || m_filePath.Right(4) == L".igs")
	{
		API_BEGIN

			ENTITY_LIST* opAcisEntities = new ENTITY_LIST();
			SPAIDocument src(m_filePath);

			SPAIAcisDocument dst(opAcisEntities);
			SPAIConverter converter;
			converter.Convert(src, dst);
			dst.GetEntities(opAcisEntities); 

			api_copy_entity_list(*opAcisEntities, list);

			result = outcome( opAcisEntities == NULL ? API_FAILED : 0 );

			opAcisEntities->clear(); 
			ACIS_DELETE(opAcisEntities);

		API_END
	}
	else
	{
		ASSERT(0);
	}
	
	// 최종 바디
	BODY * pResultBody = 0;

	// 바디 병합
	for (int i = 0; i < list.count(); i++)
	{
		BODY * pNewBody = (BODY *)list[i];
		
		if (pResultBody)
		{
			outcome result = api_boolean(pNewBody, pResultBody, UNION);
			check_outcome(result);
		}
		else
			pResultBody = pNewBody;
	}
	
	//SetBrepBody(pResultBody);
	pBody = pResultBody;
	//api_copy_body(pResultBody, pBody);
	AttachName(pBody);
}

void PmeStdSolidImportedBrepFeature::AttachName(BODY *& pBody)
{
	AttachFeatureTag(pBody);

	ENTITY_LIST face_list;

	api_get_faces((ENTITY*)pBody, face_list);

	for (int i = 0; i < face_list.count(); ++i)
	{
		FACE * pFace = (FACE*)face_list[i];
		
		CString pFaceName;
		pFaceName.AppendFormat(_T("%s,0,Face%d,0,0,0,BrepFeature:0,0:0;0"), GetName(), i);
		
		new ATTRIB_FACENAME(pFace, pFaceName);
	}
}