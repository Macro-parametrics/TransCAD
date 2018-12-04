#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeEdgesAPI
{
public:
    static void GetSize(PmeHEdges & hEdges, int & size);
    static void GetItem(PmeHEdges hEdges, int index, PmeHEdge & hEdge);
    static void FindByItem(PmeHEdges hEdges, PmeHEdge hEdge, int & index);
};
