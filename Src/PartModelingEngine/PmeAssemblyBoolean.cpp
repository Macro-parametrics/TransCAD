#include "StdAfx.h"
#include "PmeAssemblyBoolean.h"
#include "PmeExplicitModel.h"
#include "PmeAssembly.h"
#include "PmeComponent.h"
#include "PmePartAPI.h"
#include "PmeHandleMacro.h"
#include "PmeSolid.h"


PME_IMPLEMENT_RUNTIME_TYPE(PmeAssemblyBoolean, PmeComponent)

PmeAssemblyBoolean::PmeAssemblyBoolean(PmeAssembly * pAssem)
	: m_pAssem(pAssem)
{

}
PmeAssemblyBoolean::PmeAssemblyBoolean(PmeAssembly * pAssem,PmePart * pTool, PmePart * pBlank)
	: m_pAssem(pAssem)
	, m_pTool(pTool)
	, m_pBlank (pBlank)
{

 	
 	PmeSolid * pSolidTool = pTool->GetExplicitModel()->GetSolid();
 	BODY * pBodyTool = pSolidTool->GetSolid();

	PmeSolid * pSolidBlank = pBlank->GetExplicitModel()->GetSolid();
	BODY * pBodyBlank = pSolidBlank->GetSolid();

 	BODY * pNewBody = new BODY;
 	 
	
 	ASSERT(pNewBody);

 	API_BEGIN
// 
// 		/*
// 		if(pStartBody && pEndBody)
// 		{
 		result = api_boolean(pBodyTool, pBodyBlank, UNION, NDBOOL_KEEP_BOTH, pNewBody );

		PmeSolid* pSolidNew = new PmeSolid();

		pSolidNew->UpdateSolid(pNewBody);

		PmeExplicitModel * pExplnew = new PmeExplicitModel();

		pExplnew->SetSolid(pSolidNew);

		SetExplicitModel(pExplnew);

	
// 		}
// 		else if(pEndBody)
// 			pStartBody = pEndBody;
// 		*/
// 
// 		if(pOldBody)
// 		{
// 			result = api_boolean(pNewBody, pOldBody, UNION);
// 			check_outcome(result);
// 		}
// 		else
// 			pOldBody = pNewBody;
// 
// 		if(result.ok())
// 		{
// 			PmeSolid * pSolid = pPart->GetExplicitModel()->GetSolid();
// 			pSolid->UpdateSolid(pOldBody);
// 			SetSolid(pSolid);
// 		}
 	API_END	



}

PmeAssemblyBoolean::PmeAssemblyBoolean(PmeAssembly * pAssem,PmePart * pTool, VARIANT_BOOL type)
	: m_pAssem(pAssem)
	, m_pTool(pTool)
{

 	
 	PmeSolid * pSolidTool = pTool->GetExplicitModel()->GetSolid();
 	BODY * pBodyTool = pSolidTool->GetSolid();

	int nCompSize = pAssem->GetComponentList().size();


	PmeSolid * pSolidBlank = pAssem->GetComponent(nCompSize-1)->GetPart()->GetExplicitModel()->GetSolid();
		
	BODY * pBodyBlank = pSolidBlank->GetSolid();

 	BODY * pNewBody = new BODY;
 	 
	
 	ASSERT(pSolidBlank);

 	API_BEGIN

		if(type == VARIANT_TRUE)
		{
			result = api_boolean(pBodyTool, pBodyBlank, UNION, NDBOOL_KEEP_NEITHER, pNewBody );
		}
		else
			result = api_boolean(pBodyTool, pBodyBlank, SUBTRACTION, NDBOOL_KEEP_NEITHER, pNewBody );
			
		PmeSolid* pSolidNew = new PmeSolid();
			
		pSolidBlank->UpdateSolid(0);
			
		pSolidNew->UpdateSolid(pNewBody);

		PmeExplicitModel * pExplnew = new PmeExplicitModel();

		pExplnew->SetSolid(pSolidNew);

		SetExplicitModel(pExplnew);

 	API_END	

}

PmeAssemblyBoolean::~PmeAssemblyBoolean(void)
{
// 	if(m_pPart)
// 	{
// 		//delete m_pPart;
// 		PmeHPart hPart = PME_PART2HANDLE(m_pPart); 
// 		PmePartAPI::Delete(hPart);
// 		m_pPart = 0;
// 	}
}
