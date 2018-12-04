#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeExplicitModelObjectsAPI
{
public:
    static void Create(PmeHExplicitModelObjects & hExplicitModelObjects);
	static void Delete(PmeHExplicitModelObjects & hExplicitModelObjects);
	static void AddItem(PmeHExplicitModelObjects hExplicitModelObjects, PmeHExplicitModelObject hExplicitModelObject);
	static void GetSize(PmeHExplicitModelObjects hExplicitModelObjects, int & size);
	static void GetItem(PmeHExplicitModelObjects hExplicitModelObjects, int index, PmeHExplicitModelObject & hExplicitModelObject);
	static void FindByItem(PmeHExplicitModelObjects hExplicitModelObjects, PmeHExplicitModelObject hExplicitModelObject, int & index);
	static void DeleteItemByName(PmeHExplicitModelObjects hExplicitModelObjects, CString & name);
};