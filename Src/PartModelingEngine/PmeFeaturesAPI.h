#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeFeaturesAPI
{
public:
    static void GetSize(PmeHFeatures hFeatures, int & size);
    static void GetItem(PmeHFeatures hFeatures, int index, PmeHFeature & hFeature);
    static void FindByItem(PmeHFeatures hFeatures, PmeHFeature hFeature, int & index);
	static void FindByName(PmeHFeatures hFeatures, CString name, PmeHFeature & hFeature);
	static void DeleteItem(PmeHFeatures hFeatures, int index);
	static void DeleteItemByName(PmeHFeatures hFeatures, CString & name);
};
