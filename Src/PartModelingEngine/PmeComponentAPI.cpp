#include "StdAfx.h"
#include <map>
#include <vector>
#include <algorithm>
#include ".\PmePartAPI.h"
#include ".\PmePart.h"
#include ".\PmeFeatures.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeHandleMacro.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeReference.h"
#include ".\PmeComponent.h"
#include ".\PmeComponentAPI.h"
#include ".\PmeTransformAPI.h"

#include ".\PmeXmlMacroWriter.h"
#include ".\PmeXmlMacroReader.h"
#include ".\PmeMeshFileWriter.h"

typedef std::vector<IPmeComponentEventListener *> ComponentListenerList;
typedef std::map<PmeHComponent, ComponentListenerList *> ComponentListenerMap;
ComponentListenerMap g_ComponentListeners;


void PmeComponentAPI::Create( PmeHComponent & hComp )
{
	PmeComponent * pComp = new PmeComponent();
	hComp = PME_COMPONENT2HANDLE( pComp );

	/*g_ComponentListeners[ hComp ] = new ComponentListenerList();

	pComp->UpdateAll();*/
}

void PmeComponentAPI::Delete( PmeHComponent & hComp )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hComp );

	ComponentListenerList * pCompListenerList = g_ComponentListeners[ hComp ];

	if( pCompListenerList )
		delete pCompListenerList;

	pCompListenerList = 0;

	PmeComponent * pComp = PME_HANDLE2COMPONENT( hComp );	
	pComp->Clear();

	if( pComp )
		delete pComp;

	pComp = 0;
}

void PmeComponentAPI::UpdateAll( PmeHComponent & hComp )
{
 	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
 	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComp);
 
 	int nPartSize = pComponent->GetPartsSize();
 
 	for(int i = 0; i < nPartSize; ++ i)
 	{
 
 		PmeHUpdateInfo hUpdatedComponents = 0;
 		PmeUpdateInfoAPI::Create(hUpdatedComponents);
 		PmeUpdateInfoItem infoItem;
 
 		infoItem.hItem = PME_COMPONENT2HANDLE(pComponent->GetPart(i));
 		infoItem.state = PmeUpdateState_Add;
 
 		PmeUpdateInfoAPI::AddItem(hUpdatedComponents, infoItem);
 		//PmeAssemblyAPI::FirePartsUpdatedEvent(hAssembly, hUpdatedComponents);
 		PmeUpdateInfoAPI::Delete(hUpdatedComponents);
 
 	}
}

// Add functions
/**
 * @brief AddComponent Add a component(= sub component) to the current component
 * @param hItem Current component
 * @param hComp Component to be added
*/
void PmeComponentAPI::AddComponent( PmeHComponent & hItem, PmeHComponent hComp )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	PmeComponent * pComp = PME_HANDLE2COMPONENT( hComp );
	pComponent->AddComponent( pComp );
}

/**
 * @brief AddComponent Add a part to the current component
 * @param hItem Current component
 * @param hPart Part to be added
*/
void PmeComponentAPI::AddPart( PmeHComponent& hItem, PmeHPart hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	PmePart * pPart = PME_HANDLE2PART( hPart );

	pComponent->AddPart(pPart);
}

// Get functinos
/**
 * @brief GetItem Find a component or part in the target component
 * @param hComp [in] Target component
 * @param i		index
 * @param hItem [out] result component or part by searching through target component
 */
void PmeComponentAPI::GetItem( PmeHComponent& hComp, int i, PmeHandle & hItem )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hComp );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hComp );
	if( pComponent->GetItem( i )->IsInstanceOf( PME_RUNTIME_TYPE( PmePart ) ) )
	{
		PmePart * pPart = static_cast<PmePart *> ( pComponent->GetItem( i ) );
		hItem = PME_PART2HANDLE( pPart );
	}
	else if( pComponent->GetItem( i )->IsInstanceOf( PME_RUNTIME_TYPE( PmeComponent ) ) )
	{
		PmeComponent * pComp = static_cast<PmeComponent *> ( pComponent->GetItem( i ) );
		hItem = PME_COMPONENT2HANDLE( pComp );
	}
}

/**
 * @brief GetComponent
 * @param hItem [in] Target component
 * @param i		index
 * @param hComp [out] result component by searching through target component
 */
void PmeComponentAPI::GetComponent( PmeHComponent& hItem, int i, PmeHComponent & hComp )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );
	PmeComponent * pComp = pComponent->GetComponent( i );

	hComp = PME_COMPONENT2HANDLE(pComp);
}

/**
 * @brief GetPart 
 * @param hItem [in] Target component
 * @param i		index
 * @param hPart [out] result part by searching through target component
 */
void PmeComponentAPI::GetPart( PmeHComponent& hItem, int i, PmeHPart & hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	PmePart * pPart = pComponent->GetPart( i );
	hPart = PME_PART2HANDLE( pPart );
}

/**
 * @brief GetSize Get the number of components including components and parts
				  in the target component
 * @param hItem Target component
 * @param nSize The number of components
 */
void PmeComponentAPI::GetSize( PmeHComponent hItem, int & nSize )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	nSize = pComponent->GetSize();
}

/**
 * @brief GetCompSize Get the number of components in the target component
 * @param hItem Target component
 * @param nSize The number of components
 */
void PmeComponentAPI::GetCompSize( PmeHComponent hItem, int & nSize )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	nSize = pComponent->GetComponentsSize();
}

/**
 * @brief GetPartSize Get the number of parts in the target component
 * @param hItem Target component
 * @param nSize The number of components
 */
void PmeComponentAPI::GetPartSize( PmeHComponent hItem, int & nSize )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hItem);

	nSize = pComponent->GetPartsSize();
}

/**
 * @brief GetName Get name of component( parameter 1)
 * @param hItem [in] Component want to know name
 * @param name	[out] name of component
 */
void PmeComponentAPI::GetName( PmeHComponent hItem, CString & name )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComp = PME_HANDLE2COMPONENT(hItem);

	name = pComp->GetName();
}

/**
 * @brief GetName Get parent name of component( parameter 1)
 * @param hItem [in] Component want to know parent name
 * @param name	[out] parent name of component or null if component does not have parent
 */
void PmeComponentAPI::GetParentName( PmeHComponent hItem, CString & name )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComp = PME_HANDLE2COMPONENT( hItem );

	name = pComp->GetParentName();
}

/**
 * @brief GetName Get parent component of input component(= parameter 1)
 * @param hItem		[in] Component want to know parent
 * @param hParent	[out] parent of component or null if component does not have parent
 */
void PmeComponentAPI::GetParentComp( PmeHComponent hItem, PmeHComponent & hParent )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	hParent = (PmeComponent *)pComponent->GetParent();
}

void PmeComponentAPI::GetCompType( PmeHComponent hItem, PmeAssemblyComponentType & CompType )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	CompType = pComponent->GetCompType();
}

void PmeComponentAPI::GetPlacement(PmeHComponent hComponent, MrAxis2 & placement)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComponent);

	placement = pComponent->GetPlacement();
}

void PmeComponentAPI::GetModellingMatrix(PmeHComponent hComponent, float* transform)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComponent);
		
	MrTransformation mrTrsf = MrTransformation::CreateCoordinateSystemTransformation(pComponent->GetPlacement(), MrAxis2::OXY());

	transform[0] = (float)mrTrsf(0, 0); transform[1] = (float)mrTrsf(1, 0); transform[2] = (float)mrTrsf(2, 0); transform[3] = 0.0f;
	transform[4] = (float)mrTrsf(0, 1); transform[5] = (float)mrTrsf(1, 1); transform[6] = (float)mrTrsf(2, 1); transform[7] = 0.0f;
	transform[8] = (float)mrTrsf(0, 2); transform[9] = (float)mrTrsf(1, 2); transform[10] = (float)mrTrsf(2, 2); transform[11] = 0.0f;
	transform[12] = (float)mrTrsf(0, 3); transform[13] = (float)mrTrsf(1, 3); transform[14] = (float)mrTrsf(2, 3); transform[15] = 1.0f;	
}

void PmeComponentAPI::GetGlobalModellingMatrix(PmeHComponent hComponent, float* transform)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComponent);

	MrTransformation mrTrsf = PmeTransformAPI::CalcModelingMatrix(hComponent);

	transform[0] = (float)mrTrsf(0, 0); transform[1] = (float)mrTrsf(1, 0); transform[2] = (float)mrTrsf(2, 0); transform[3] = 0.0f;
	transform[4] = (float)mrTrsf(0, 1); transform[5] = (float)mrTrsf(1, 1); transform[6] = (float)mrTrsf(2, 1); transform[7] = 0.0f;
	transform[8] = (float)mrTrsf(0, 2); transform[9] = (float)mrTrsf(1, 2); transform[10] = (float)mrTrsf(2, 2); transform[11] = 0.0f;
	transform[12] = (float)mrTrsf(0, 3); transform[13] = (float)mrTrsf(1, 3); transform[14] = (float)mrTrsf(2, 3); transform[15] = 1.0f;	
}


// Set functions
void PmeComponentAPI::SetName( PmeHComponent hItem, CString name )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComp = PME_HANDLE2COMPONENT( hItem );

	pComp->SetName(name);
}

void PmeComponentAPI::SetParentName(PmeHComponent hItem, CString name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComp = PME_HANDLE2COMPONENT(hItem);

	pComp->SetParentName(name);
}


void PmeComponentAPI::SetPlacement( PmeHComponent & hComponent, MrAxis2 placement )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComponent);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComponent);

	pComponent->SetPlacement(placement);
}

void PmeComponentAPI::SetUpdated( PmeHComponent & hComp, BOOL result )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComp);

	pComponent->IsUpdated(result);
}


// Boolean type fucntions
void PmeComponentAPI::IsComponent( PmeHComponent & hComp, BOOL & result )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComp);

	if(pComponent->IsInstanceOf(PME_RUNTIME_TYPE(PmeComponent)))
	{
		result = TRUE;
	}
	else 
		result = FALSE;
}

void PmeComponentAPI::IsComponent( PmeHComponent & hComp, int i, BOOL & result )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComp);

	if(pComponent->GetItem(i)->IsInstanceOf(PME_RUNTIME_TYPE(PmeComponent)))
	{
		result = TRUE;
	}
	else 
		result = FALSE;
}

void PmeComponentAPI::IsPart( PmeHComponent & hComp, int i, BOOL & result )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComp);

	if(pComponent->GetItem(i)->IsInstanceOf(PME_RUNTIME_TYPE(PmePart)))
	{
		result = TRUE;
	}
	else 
		result = FALSE;
}

void PmeComponentAPI::IsUpdated( PmeHComponent & hComp, BOOL & result )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComp);

	result = pComponent->IsUpdated();	
}

// Etc
void PmeComponentAPI::SaveAsMesh(PmeHComponent hComp, int i, CString filename )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hComp);
	//PmeComponent * pComp = PME_HANDLE2COMPONENT(hComp);

	PmeMeshFileWriter writer(hComp, i, filename);
	writer.Save();
}


/*
void PmePartAPI::RegisterEventListener(PmeHPart hPart, IPmePartEventListener * pListener)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	if(find(pPartListenerList->begin(), pPartListenerList->end(), pListener) == pPartListenerList->end())
	{
		pPartListenerList->push_back(pListener);
	}
}

void PmePartAPI::UnregisterEventListener(PmeHPart hPart, IPmePartEventListener * pListener)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;

	PartListenerList::iterator i2 = find(pPartListenerList->begin(), pPartListenerList->end(), pListener);
	if(i2 == pPartListenerList->end())
		return;

	pPartListenerList->erase(i2);
}

void PmePartAPI::FireFeaturesUpdatedEvent(PmeHPart hPart, PmeHUpdateInfo hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	PartListenerList::iterator i2 = pPartListenerList->begin();

	while(i2 != pPartListenerList->end())
	{
		(*i2)->OnFeaturesUpdated(hInfo);
		i2 ++;
	}	
}

void PmePartAPI::FireExplicitModelUpdatedEvent(PmeHPart hPart, PmeHUpdateInfo hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hPart);

	PartListenerMap::iterator i = g_partListeners.find(hPart);
	if(i == g_partListeners.end())
		return;

	PartListenerList * pPartListenerList = i->second;
	PartListenerList::iterator i2 = pPartListenerList->begin();

	while(i2 != pPartListenerList->end())
	{
		(*i2)->OnExplicitModelUpdated(hInfo);
		i2 ++;
	}	
}

*/ 


// 이 함수는 왜 있는 건지...?
void PmeComponentAPI::GetPart( PmeHComponent hItem, PmeHPart & hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hItem );

	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	PmePart * pPart = pComponent->GetPart();
	hPart = PME_PART2HANDLE( pPart );
}
void PmeComponentAPI::SetPart( PmeHComponent hItem, PmeHPart & hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComponent = PME_HANDLE2COMPONENT( hItem );

	PmePart * pPart = PME_HANDLE2PART( hPart );
	pComponent->SetPart( pPart );
	//hPart = PME_PART2HANDLE(pPart);
}
void PmeComponentAPI::GetUniqueName(PmeHComponent hItem, CString & name)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hItem);
	PmeComponent * pComp = PME_HANDLE2COMPONENT(hItem);

	CString memAddr;

	memAddr.Format("%ld",hItem);

	name = pComp->GetName() + memAddr;
}