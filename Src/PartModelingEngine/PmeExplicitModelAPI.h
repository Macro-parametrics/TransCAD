#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeExplicitModelAPI
{
public:
    static void GetSolid(PmeHExplicitModel hExplicitModel, PmeHExplicitModelObject & hObject);
	static void GetSolid2(PmeHExplicitModel hExplicitModel, PmeHSolid & hSolid);
	static void GetItem(PmeHExplicitModel hExplicitModel, PmeHExplicitModelObject & hObject, int index);
	static void GetSize(PmeHExplicitModel hExplicitModel, int & size);
	static void DeleteItem(PmeHExplicitModel hExplicitModel, int index);
	static void DeleteItemByName(PmeHExplicitModel hExplicitModel, CString & name);
};