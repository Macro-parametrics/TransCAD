#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeReferencesAPI
{
public:
	static void Create(PmeHReferences & hReferences);
    static void Delete(PmeHReferences & hReferences);
    static void AddItem(PmeHReferences hReferences, PmeHReference hReference);
    static void GetSize(PmeHReferences & hReferences, int & size);
    static void GetItem(PmeHReferences hReferences, int index, PmeHReference & hReference);
    static void FindByItem(PmeHReferences hReferences, PmeHReference hReference, int & index);
    static void Copy(PmeHReferences hSource, PmeHReferences & hNew);
};
