#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include ".\PmeExplicitModelObjectType.h"

class PME_API PmeExplicitModelObjectAPI
{
public:
    static void GetName(PmeHExplicitModelObject hObject, CString & name);
	static void GetType(PmeHExplicitModelObject hObject, PmeExplicitModelObjectType & type);
	static void GetCreator(PmeHExplicitModelObject hObject, PmeHFeature & hFeature);
};