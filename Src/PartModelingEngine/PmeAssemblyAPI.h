#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

struct IPmeAssemblyEventListener
{
	virtual void OnPartUpdated( PmeHUpdateInfo hInfo ) = 0;
	virtual void OnComponentUpdated( PmeHUpdateInfo hInfo ) = 0;
	virtual void OnConstraintUpdated( PmeHUpdateInfo hInfo ) = 0;
};

class PME_API PmeAssemblyAPI
{
public:
	static void Create(PmeHAssembly & hAssembly);
	static void Delete(PmeHAssembly & hAssembly);
	static void DeleteComponent (PmeHAssembly & hAssembly, PmeHComponent hComponent);
	static void UpdateAll(PmeHAssembly hAssembly);
	
	// Add functions
	static void AddAssembly(PmeHAssembly & hAssembly, PmeHAssembly hNewAssembly);
	static void AddComponent(PmeHAssembly & hAssembly, PmeHComponent hComponent);
	static void AddPart(PmeHAssembly & hAssembly, CString filename);
	static void AddPart(PmeHAssembly & hAssembly, PmeHPart hPart);
	static void AddBrepPart(PmeHAssembly & hAssembly, CString filename);

	// Get functions
	static void GetComponent(PmeHAssembly hAssembly, int i, PmeHComponent & hComponent);
	static void GetComponentByName(PmeHAssembly hAssembly, CString name, PmeHComponent & hComponent);
	static void GetPartByName(PmeHAssembly hAssembly, CString partName, PmeHPart & hPart);
	static void GetPartByName( PmeHAssembly hAssembly, CString compName, CString partName, PmeHPart & hPart );
	static void GetSize(PmeHAssembly hAssembly, int & size);

	static void GetConstraints( PmeHAssembly hAssembly, PmeHStdAssemblyConstraints & hConstraints );

	// Utilities
	static void RegisterEventListener(PmeHAssembly hAssembly, IPmeAssemblyEventListener * pListener);
	static void UnregisterEventListener(PmeHAssembly hAssembly, IPmeAssemblyEventListener * pListener);
	static void FireComponentsUpdatedEvent(PmeHAssembly hAssembly, PmeHUpdateInfo hInfo);
	static void FirePartsUpdatedEvent(PmeHAssembly hAssembly, PmeHUpdateInfo hInfo);
	static void FireConstraintsUpdatedEvent(PmeHAssembly hAssembly, PmeHUpdateInfo hInfo);
	
	static void LoadXmlMacro(CString filename, PmeHAssembly & hAssembly);
	static void SaveAsXmlMacro(PmeHAssembly hAssembly, CString filename);
	static void LoadBrepFile(CString filename, PmeHPart & hPart);

	static void SetName( PmeHAssembly hAssembly, CString name );
	static void GetName( PmeHAssembly hAssembly, CString & name );
};