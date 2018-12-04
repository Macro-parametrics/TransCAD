#include "StdAfx.h"
#include <map>
#include <algorithm>
#include ".\PmeHandleMacro.h"
#include "PmeAssemblyAPI.h"
#include "PmeAssembly.h"
#include ".\PmeUpdateInfoAPI.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include "PmePartAPI.h"
#include "PmePart.h"
#include "PmeAssemblyAPI.h"
#include "PmeComponent.h"
#include "PmeComponentapi.h"
#include "PmeXmlMacroReader.h"
#include "PmeXmlMacroWriter.h"

#include "PmeUtility.h"


typedef std::vector<IPmeAssemblyEventListener *> AssemblyListenerList;
typedef std::map<PmeHAssembly, AssemblyListenerList *> AssemblyListenerMap;
AssemblyListenerMap g_assemblyListeners;

/**
 * @brief Create AssemDocument에서 Initialize할 때, 한번만 사용되어야 한다.
 */
void PmeAssemblyAPI::Create(PmeHAssembly & hAssembly)
{
	PmeAssembly * pAssembly = new PmeAssembly();
	hAssembly = PME_ASSEMBLY2HANDLE(pAssembly);

	g_assemblyListeners[hAssembly] = new AssemblyListenerList();

	pAssembly->UpdateAll();
}

void PmeAssemblyAPI::Delete(PmeHAssembly & hAssembly)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	AssemblyListenerList * pAssemblyListenerList = g_assemblyListeners[hAssembly];
	if(pAssemblyListenerList)
		delete pAssemblyListenerList;
	pAssemblyListenerList = 0;

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);	

	if(pAssembly)
		delete pAssembly;
	hAssembly = 0;
}

/**
 * @brief DeleteComponent Assembly에 들어있는 component 중 특정 component 삭제
 */
void PmeAssemblyAPI::DeleteComponent( PmeHAssembly & hAssembly, PmeHComponent hComponent )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	
	PME_UPDATE_COMPONENT( hAssembly, hComponent, PmeUpdateState_Delete );
}

void PmeAssemblyAPI::UpdateAll( PmeHAssembly hAssembly )
{	
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);		
	
	// pAssembly에 있는 모든 part들의 정보를 업데이트
	pAssembly->UpdateAll();

	// Update components
	int nCompSize = pAssembly->GetComponentList().size();
	
	PmeHUpdateInfo hUpdatedComponents = 0;
	PmeUpdateInfoAPI::Create( hUpdatedComponents );

	for( int i = 0; i < nCompSize; ++ i )
	{
		PmeUpdateInfoItem infoItem;

		infoItem.hItem = PME_COMPONENT2HANDLE( pAssembly->GetComponent( i ) );
		infoItem.state = PmeUpdateState_Update; //PmeUpdateState_Add

		PmeUpdateInfoAPI::AddItem( hUpdatedComponents, infoItem );	
	}

	PmeAssemblyAPI::FireComponentsUpdatedEvent(hAssembly, hUpdatedComponents);
	PmeUpdateInfoAPI::Delete(hUpdatedComponents);

	// Update constraints
	int nConstraintSize = pAssembly->GetConstraintList().size();

	PmeHUpdateInfo hUpdatedConstraints = 0;
	PmeUpdateInfoAPI::Create(hUpdatedConstraints);

	for ( int i = 0; i < nConstraintSize; ++i )
	{
		PmeUpdateInfoItem infoItem;

		infoItem.hItem = PME_STDASSEMBLYCONSTRAINT2HANDLE( pAssembly->GetConstraint( i ) );
		infoItem.state = PmeUpdateState_Update;

		PmeUpdateInfoAPI::AddItem( hUpdatedConstraints, infoItem );
	}

	PmeAssemblyAPI::FireConstraintsUpdatedEvent(hAssembly, hUpdatedConstraints);
	PmeUpdateInfoAPI::Delete(hUpdatedConstraints);

}

// Add functions
/**
 * @brief AddAssembly Add a new assembly in a current assembly
 * @param hNewAssembly A new assembly to be added
 */
void PmeAssemblyAPI::AddAssembly( PmeHAssembly & hAssembly, PmeHAssembly hNewAssembly )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);
	PmeThrowExceptionIf<PmeArgumentNullException>(!hNewAssembly);

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmeAssembly * pNewAssembly = PME_HANDLE2ASSEMBLY(hNewAssembly);

	if(hNewAssembly)
	{
		PME_UPDATE_ASSEMBLY(hAssembly, hNewAssembly, PmeUpdateState_Add);
	}
}

/**
 * @brief AddComponent Add a new component in current assembly
 */
void PmeAssemblyAPI::AddComponent( PmeHAssembly & hAssembly, PmeHComponent hComponent )
{
 	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);
 
 	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
 	 
 	PmeComponent * pComponent = PME_HANDLE2COMPONENT(hComponent);
	 	
	pAssembly->AddComponent(pComponent);
 	
	PmeHComponent hComp = PME_COMPONENT2HANDLE(pComponent);
	 	
	PME_UPDATE_COMPONENT(hAssembly, hComp, PmeUpdateState_Add);
}

/**
 * @brief AddPart Add a new part by using xml file that specified MPA
				  in the default component of a current assembly
 * @param hAssembly Current assembly
 * @param filename	xml file ( absolute or relative path from TransCAD.exe )
 */
void PmeAssemblyAPI::AddPart( PmeHAssembly & hAssembly, CString filename )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );
	PmeHPart hPart = 0;

	PmePartAPI::Create( hPart );
	PmePartAPI::LoadXmlMacro( filename, hPart );	
	PmePartAPI::SetName( hPart, filename );
	
	PmeHComponent hComponent;
	GetComponentByName( hAssembly, _T ("Default SubAssembly" ), hComponent );
	PmeComponentAPI::AddPart( hComponent, hPart );

	if( hPart )
	{
		PME_UPDATE_PART( hAssembly, hComponent, PmeUpdateState_Add );
	}
}

/**
 * @breif AddPart Add a new part in the default component of a current assembly
 * @param hAssembly Current assembly
 * @param hPart part to be added
 */
void PmeAssemblyAPI::AddPart( PmeHAssembly & hAssembly, PmeHPart hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	PmeHComponent hComponent;
	GetComponentByName( hAssembly, _T ("Default SubAssembly" ), hComponent );
	PmeComponentAPI::AddPart( hComponent, hPart );

	if( hPart )
	{
		PME_UPDATE_PART( hAssembly, hComponent, PmeUpdateState_Add );
	}
}

/**
 * @brief AddBrepPart Add a new brep part such as sat, stp, and iges
					  in the default component of a current assembly
 * @param hAssembly Current assembly
 * @param filename	( absolute or relative path from TransCAD.exe )
 * Note: Currently this function dose not work
 */
void PmeAssemblyAPI::AddBrepPart( PmeHAssembly & hAssembly, CString filename )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmeHPart hPart = 0;

	PmePartAPI::Create(hPart);
	
	PmePartAPI::LoadBrepFile(filename, hPart);	
	
	PmePart * pPart = PME_HANDLE2PART(hPart);

	pPart->SetName(filename);

	PmeHComponent hComponent;
	GetComponentByName( hAssembly, _T ("Default SubAssembly" ), hComponent );
	PmeComponentAPI::AddPart( hComponent, hPart );
}

// Get functions
/**
 * @brief GetComponent	Get component among components in the assembly by using an index
 * @param hAssembly		Current assembly
 * @param i				Component index you want to find
 * @param hComponent	[out] PmeHComponent
 */
void PmeAssemblyAPI::GetComponent( PmeHAssembly hAssembly, int i, PmeHComponent & hComponent )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );
	PmeComponent * pComponent = pAssembly->GetComponent( i );

	hComponent = PME_COMPONENT2HANDLE( pComponent );
}

/**
 * @brief GetComponentByName Get component among components in the assembly by using a component name
 * @param hAssembly		Current assembly
 * @param name			Component name
 * @param hComponent	[out] PmeHComponent
 */
void PmeAssemblyAPI::GetComponentByName( PmeHAssembly hAssembly, CString name, PmeHComponent & hComponent )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	int _size;

	GetSize( hAssembly, _size );

	for( int i =0; i < _size; i++ )
	{
		GetComponent( hAssembly, i, hComponent );

		CString componentName;
		PmeComponentAPI::GetName( hComponent, componentName );

		if( componentName == name )
			return;
	}
}

/**
 * @brief GetPartByName	Get part in the assembly by using a part name
						This function search all items in the assembly
 * @param hAssembly	Cureent assembly
 * @param name		Part name
 * @param hPart		[out] PmeHPart
*/
void PmeAssemblyAPI::GetPartByName( PmeHAssembly hAssembly, CString name, PmeHPart & hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	int _size;	// the number of component in assembly

	GetSize( hAssembly, _size );	

	for ( int i = 0; i < _size; i++ )
	{
		PmeHComponent hComponent;

		GetComponent( hAssembly, i, hComponent );

		int _partSize;	// the number of part in component
		PmeComponentAPI::GetPartSize( hComponent, _partSize );

		for ( int j = 0; j < _partSize; ++j )
		{
			PmeComponentAPI::GetPart( hComponent, j, hPart );

			CString partName;
			PmePartAPI::GetName( hPart, partName );

			if( partName == name )
				return;
		}		
	}
}

/**
 * @brief GetPartByName	Get part in the assembly by using a part name
						This function find component specified component name firstly
						and then search part in the component
 * @param hAssembly	Cureent assembly
 * @param compName	
 * @param partName	Part name
 * @param hPart		[out] PmeHPart
*/
void PmeAssemblyAPI::GetPartByName( PmeHAssembly hAssembly, CString compName, CString partName, PmeHPart & hPart )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);

	int _size;	// Assembly에 있는 component의 수

	GetSize(hAssembly, _size);	

	for ( int i = 0; i < _size; i++ )
	{
		PmeHComponent hComponent;

		GetComponent( hAssembly, i, hComponent );

		CString thisCompName;
		PmeComponentAPI::GetName( hComponent, thisCompName );

		if ( thisCompName == compName )
		{
			int _partSize;	// Component에 있는 part의 수

			PmeComponentAPI::GetPartSize( hComponent, _partSize );

			for ( int j = 0; j < _partSize; ++j )
			{
				PmeComponentAPI::GetPart( hComponent, j, hPart );

				CString thisPartName;

				PmePartAPI::GetName( hPart, thisPartName );

				if( thisPartName == partName )
					return;
			}
		}			
	}
}

/**
 * @brief Getsize Get component size in the assembly
 * @param hAssembly Current assembly
 * @param size		[out] size of component
 */
void PmeAssemblyAPI::GetSize(PmeHAssembly hAssembly, int & size)
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly =PME_HANDLE2ASSEMBLY(hAssembly);

	size = pAssembly->GetComponentList().size();
}

/**
 * @brief GetConstraints Get constraints in the assembly
 * @param hAssembly		Current assembly
 * @param hConstraints	[out] PmeStdAssemblyConstraints
 */
void PmeAssemblyAPI::GetConstraints( PmeHAssembly hAssembly, PmeHStdAssemblyConstraints & hConstraints )
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	hConstraints = pAssembly->GetConstraints();
}

// Utilities
// when assemdocument initialized,
void PmeAssemblyAPI::RegisterEventListener(PmeHAssembly hAssembly, IPmeAssemblyEventListener * pListener)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	AssemblyListenerMap::iterator i = g_assemblyListeners.find(hAssembly);
	if(i == g_assemblyListeners.end())
		return;

	AssemblyListenerList * pAssemblyListenerList = i->second;
	if(find(pAssemblyListenerList->begin(), pAssemblyListenerList->end(), pListener) == pAssemblyListenerList->end())
	{
		pAssemblyListenerList->push_back(pListener);
	}
}

// when assemdocument uninitialized,
void PmeAssemblyAPI::UnregisterEventListener(PmeHAssembly hAssembly, IPmeAssemblyEventListener * pListener)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	AssemblyListenerMap::iterator i = g_assemblyListeners.find(hAssembly);
	if(i == g_assemblyListeners.end())
		return;

	AssemblyListenerList * pAssemblyListenerList = i->second;

	AssemblyListenerList::iterator i2 = find(pAssemblyListenerList->begin(), pAssemblyListenerList->end(), pListener);
	if(i2 == pAssemblyListenerList->end())
		return;

	pAssemblyListenerList->erase(i2);
}

void PmeAssemblyAPI::FireComponentsUpdatedEvent( PmeHAssembly hAssembly, PmeHUpdateInfo hInfo )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	AssemblyListenerMap::iterator i = g_assemblyListeners.find( hAssembly );
	if( i == g_assemblyListeners.end() )
		return;

	AssemblyListenerList * pAssemblyListenerList = i->second;
	AssemblyListenerList::iterator i2 = pAssemblyListenerList->begin();

	while( i2 != pAssemblyListenerList->end() )
	{
		// FeatureTree로 이동하는 단계
		(*i2)->OnComponentUpdated( hInfo );
		i2 ++;
	}	
}

void PmeAssemblyAPI::FirePartsUpdatedEvent(PmeHAssembly hAssembly, PmeHUpdateInfo hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	AssemblyListenerMap::iterator i = g_assemblyListeners.find(hAssembly);
	if(i == g_assemblyListeners.end())
		return;

	AssemblyListenerList * pAssemblyListenerList = i->second;
	AssemblyListenerList::iterator i2 = pAssemblyListenerList->begin();

	while(i2 != pAssemblyListenerList->end())
	{
		(*i2)->OnPartUpdated(hInfo);
		i2 ++;
	}	
}

void PmeAssemblyAPI::FireConstraintsUpdatedEvent(PmeHAssembly hAssembly, PmeHUpdateInfo hInfo)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	AssemblyListenerMap::iterator i = g_assemblyListeners.find( hAssembly );
	if( i == g_assemblyListeners.end() )
		return;

	AssemblyListenerList * pAssemblyListenerList = i->second;
	AssemblyListenerList::iterator i2 = pAssemblyListenerList->begin();

	while( i2 != pAssemblyListenerList->end() )
	{
		// FeatureTree로 이동
		(*i2)->OnConstraintUpdated( hInfo );
		i2++;
	}
}


void PmeAssemblyAPI::SaveAsXmlMacro(PmeHAssembly hAssembly, CString filename)
{
	PmeThrowExceptionIf<PmeArgumentNullException>( !hAssembly );
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);

	PmeXmlMacroWriter writer( filename );

	int _compSize;	// the number of components

	GetSize( hAssembly, _compSize );
	writer.WriteHeader();

	for( int i =0; i < _compSize; i++ )
	{
		PmeHComponent hComponent;

		GetComponent( hAssembly, i, hComponent );
		
		int _partSize;
		PmeComponentAPI::GetPartSize( hComponent, _partSize );

		for ( int j = 0; j < _partSize; ++j )
		{
			PmeHPart hPart;
			PmeComponentAPI::GetPart( hComponent, j, hPart );

			writer.SetPart( hPart );
			writer.WriteParts();
		}		
	}
	writer.WriteFooter();
}

void PmeAssemblyAPI::LoadXmlMacro( CString filename, PmeHAssembly & hAssembly )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);

	PmeXmlMacroReader reader(pAssembly,filename);

	reader.ReadAssembly();

}

void PmeAssemblyAPI::SetName( PmeHAssembly hAssembly, CString name )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	pAssembly->SetName( name );
}

void PmeAssemblyAPI::GetName( PmeHAssembly hAssembly, CString & name )
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!hAssembly);
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY( hAssembly );

	name = pAssembly->GetName();
}