#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeFacesAPI
{
public:
    static void GetSize(PmeHFaces & hFaces, int & size);
    static void GetItem(PmeHFaces hFaces, int index, PmeHFace & hFace);
    static void FindByItem(PmeHFaces hFaces, PmeHFace hFace, int & index);
};
