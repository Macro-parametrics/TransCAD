#include "StdAfx.h"
#include "PmeAssembly.h"
#include "PmeAssemblyAPI.h"
#include "PmeAssemblyBoolean.h"
#include "PmeAssemblyBooleanAPI.h"
#include "PmeComponent.h"
#include "PmePartAPI.h"
#include ".\PmeHandleMacro.h"
#include ".\PmePart.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeUtility.h"


void PmeAssemblyBooleanAPI::Create(
	PmeHAssembly hAssem,
	const CString & name,
	PmeHPart hTool,
	PmeHPart hBlank
	)
{

	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssem);
	PmeAssembly * pAssem = PME_HANDLE2ASSEMBLY(hAssem);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTool);
	PmePart * pTool = PME_HANDLE2PART(hTool);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hBlank);
	PmePart * pBlank = PME_HANDLE2PART(hBlank);
	
 	PmePart * pNewPart = new PmeAssemblyBoolean (pAssem, pTool, pBlank);

	pNewPart->SetName(name);

	PmeComponent * pComponent = new PmeComponent(pNewPart);
	pAssem->AddComponent(pComponent);
	PmeHComponent hComponent = PME_COMPONENT2HANDLE(pComponent);

	if(hTool&&hBlank)
	{
		PME_UPDATE_PART(hAssem, hComponent, PmeUpdateState_Add);
	}



//	pAssem->AddComponent(pComp);
	
// 	
// 	 if(name.IsEmpty())
// 		pFeature->GiveDefaultName();
// 	else
// 		pFeature->SetName(name);
// 
// 	pFeatures->Add(pFeature);
// 	pPart->UpdateLast();
// 
// 	hFeature = PME_FEATURE2HANDLE(pFeature);
// 	if(hFeature)
// 	{
// 		PME_UPDATE_FEATURE(hPart, hFeature, PmeUpdateState_Add);
// 	}
// 
// 	PmeHExplicitModelObject hSolid = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetSolid());
// 	if(hSolid)
// 	{
// 		PME_UPDATE_EXPLICITMODELOBJECT(hPart, hSolid, PmeUpdateState_Update);
// 	}
}


void PmeAssemblyBooleanAPI::Create(
	PmeHAssembly hAssem,
	const CString & name,
	PmeHPart hTool,
	VARIANT_BOOL type
	)
{

	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssem);
	PmeAssembly * pAssem = PME_HANDLE2ASSEMBLY(hAssem);

	PmeThrowExceptionIf<PmeArgumentNullException>(!hTool);
	PmePart * pTool = PME_HANDLE2PART(hTool);

	ASSERT(hTool);
	
	if(pAssem->GetComponentList().size() == 1)
	{
		PmePart * pNewPart = pTool;
		pNewPart->SetName(name);
		
		CString strParent;
		PmePartAPI::GetParentName(hTool,strParent);

		pNewPart->SetParentName(strParent);

		PmeComponent * pComponent = new PmeComponent(pNewPart);
		pAssem->AddComponent(pComponent);
		PmeHComponent hComponent = PME_COMPONENT2HANDLE(pComponent);
		
		if(hTool)
		{
			PME_UPDATE_PART(hAssem, hComponent, PmeUpdateState_Add);
		}
	}
	else
	{
		int nComp = pAssem->GetComponentList().size();
		PmePart * pNewPart = new PmeAssemblyBoolean (pAssem, pTool, type);
		pNewPart->SetName(name);

		CString strParent;
		PmePartAPI::GetParentName(hTool,strParent);

		pNewPart->SetParentName(strParent);

		PmeComponent * pComponent = new PmeComponent(pNewPart);
		pAssem->AddComponent(pComponent);
		PmeHComponent hComponent = PME_COMPONENT2HANDLE(pComponent);
		
		if(hTool)
		{
			PmeComponent* pOldComponent = pAssem->GetComponent(nComp-1);
			PmeHComponent hOldComponent = PME_COMPONENT2HANDLE(pOldComponent);

			PME_UPDATE_PART(hAssem, pOldComponent, PmeUpdateState_Update);
			PME_UPDATE_PART(hAssem, hComponent, PmeUpdateState_Add);
		}
	}
	
	



	//	pAssem->AddComponent(pComp);

	// 	
	// 	 if(name.IsEmpty())
	// 		pFeature->GiveDefaultName();
	// 	else
	// 		pFeature->SetName(name);
	// 
	// 	pFeatures->Add(pFeature);
	// 	pPart->UpdateLast();
	// 
	// 	hFeature = PME_FEATURE2HANDLE(pFeature);
	// 	if(hFeature)
	// 	{
	// 		PME_UPDATE_FEATURE(hPart, hFeature, PmeUpdateState_Add);
	// 	}
	// 
	// 	PmeHExplicitModelObject hSolid = PME_EXPLICITMODELOBJECT2HANDLE(pFeature->GetSolid());
	// 	if(hSolid)
	// 	{
	// 		PME_UPDATE_EXPLICITMODELOBJECT(hPart, hSolid, PmeUpdateState_Update);
	// 	}
}