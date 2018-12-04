#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeVerticesAPI
{
public:
    static void GetSize(PmeHVertices & hVertices, int & size);
    static void GetItem(PmeHVertices hVertices, int index, PmeHVertex & hVertex);
    static void FindByItem(PmeHVertices hVertices, PmeHVertex hVertex, int & index);
};
