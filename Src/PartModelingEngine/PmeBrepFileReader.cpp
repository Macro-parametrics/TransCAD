#include "StdAfx.h"
#include "PmeHandleMacro.h"
#include "PmeBrepFileReader.h"
#include "PmePart.h"
#include ".\PmeFeatures.h"
#include ".\PmeStdSolidImportedBrepFeature.h"
#include "PmeExplicitModel.h"
#include "PmeExplicitModelObject.h"
#include "PmeSolid.h"
#include "PmeInterOp.h"
#include "PmeUtility.h"

#include ".\PmePartAPI.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeReference.h"

PmeBrepFileReader::PmeBrepFileReader(void)
{
}

PmeBrepFileReader::PmeBrepFileReader( PmeHPart hPart, CString filename )
	: m_hPart(hPart)
	, m_filename(filename)
{

}

PmeBrepFileReader::~PmeBrepFileReader(void)
{
}

void PmeBrepFileReader::Read()
{
	ENTITY_LIST list;

	if(m_filename.Right(4) == L".sat")
	{
		FILE * fp = NULL;

		fopen_s(&fp, m_filename,"r"); // "r" : ASCII mode, "rb" : binary mode
		
		if(fp)
		{
			api_restore_entity_list(fp,TRUE,list); // TRUE : ASCII mode, FALSE : binary mode
			fclose(fp);
		}
	}
	else if(m_filename.Right(4) == L".stp" || m_filename.Right(4) == L".step" || m_filename.Right(4) == L".iges" || m_filename.Right(4) == L".igs")
	{
		API_BEGIN

			ENTITY_LIST* opAcisEntities = new ENTITY_LIST();
			SPAIDocument src(m_filename);

			SPAIAcisDocument dst(opAcisEntities);
			SPAIConverter converter;
			converter.Convert(src, dst);
			dst.GetEntities(opAcisEntities); 

			api_copy_entity_list(*opAcisEntities,list);

			result = outcome( opAcisEntities == NULL ? API_FAILED : 0 );

			opAcisEntities->clear(); 
			ACIS_DELETE(opAcisEntities);

		API_END
	}
	else
	{
		ASSERT(0);
	}
		
	PmePart * pPart = PME_HANDLE2PART(m_hPart);
	pPart->isBrepPart(TRUE);

	PmeFeatures * pFeatures = pPart->GetFeatures();
	PmeSolid * pSolid = new PmeSolid;
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

	pSolid->UpdateSolid(pResultBody);
	CString _brepName = _T("Manifold_Solid_Brep");

	/*
	PmeStdSolidImportedBrepFeature * pFeature = new PmeStdSolidImportedBrepFeature(pPart, m_filename);
	pFeature->SetName(_brepName);
	pFeature->SetSolid(pSolid);
	pFeature->SetBrepBody(pSolid->GetSolid());
		
	pFeatures->Add(pFeature);
	pPart->UpdateLast();

	PmeHFeature hFeature = PME_FEATURE2HANDLE(pFeature);

	if(hFeature)
	{
		PME_UPDATE_FEATURE(m_hPart, hFeature, PmeUpdateState_Add);
	}

	PmeHExplicitModelObject hSolid = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetSolid());
	
	if(hSolid)
	{
		PME_UPDATE_EXPLICITMODELOBJECT(m_hPart, hSolid, PmeUpdateState_Update);
	}
	*/
}
