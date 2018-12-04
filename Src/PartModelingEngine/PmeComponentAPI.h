#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeAssemblyComponentType.h"

struct IPmeComponentEventListener
{
	virtual void OnPartUpdated( PmeHUpdateInfo hInfo ) = 0;
	virtual void OnComponentUpdated( PmeHUpdateInfo hInfo ) = 0;
};

class PME_API PmeComponentAPI
{
public:
	static void Create(PmeHComponent & hComp);
	static void Delete(PmeHComponent & hComp);
	static void UpdateAll(PmeHComponent & hComp);

	// Add functions
	static void AddComponent( PmeHComponent & hItem, PmeHComponent hComp );
	static void AddPart( PmeHComponent& hItem, PmeHPart hPart );

	// Get functions
	static void GetItem(PmeHComponent& hComp, int i, PmeHandle & hItem);
	static void GetComponent(PmeHComponent& hItem, int i, PmeHComponent & hComp);
	static void GetPart(PmeHComponent& hItem, int i, PmeHPart & hPart);
	
	
	static void GetSize(PmeHComponent hItem, int & nSize);
	static void GetCompSize(PmeHComponent hItem, int & nSize);
	static void GetPartSize(PmeHComponent hItem, int & nSize);
	
	static void GetName(PmeHComponent hItem, CString & name);
	static void GetParentName(PmeHComponent hItem, CString & name);

	static void GetParentComp(PmeHComponent hItem, PmeHComponent & hParent);
	static void GetCompType(PmeHComponent hItem, PmeAssemblyComponentType & CompType);

	static void GetPlacement( PmeHComponent hComponent, MrAxis2 & placement );
	static void GetModellingMatrix( PmeHComponent hComponent, float* transform );
	static void GetGlobalModellingMatrix( PmeHComponent hComponent, float* transform );
	
	// Set functions
	static void SetName(PmeHComponent hItem, CString name);
	static void SetParentName(PmeHComponent hItem, CString name);

	static void SetPlacement(PmeHComponent & hComponent, MrAxis2  placement);

	static void SetUpdated( PmeHComponent & hComp,BOOL result);	

	// Boolean type fucntions
	static void IsComponent( PmeHComponent & hComp, BOOL & result );
	static void IsComponent( PmeHComponent & hComp,int i, BOOL & result);
	static void IsPart( PmeHComponent & hComp,int i, BOOL & result);
	static void IsUpdated( PmeHComponent & hComp,BOOL & result);

	static void SaveAsMesh(PmeHComponent hComp, int i, CString filename);

	static void GetPart(PmeHComponent hItem, PmeHPart & hPart);
	static void SetPart(PmeHComponent hItem, PmeHPart & hPart);
	static void GetUniqueName(PmeHComponent hItem, CString & name);
};