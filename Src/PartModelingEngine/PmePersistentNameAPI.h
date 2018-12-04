#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmePersistentNameAPI
{
public:
    static void FindFaceName(FACE * pFace, CString & faceName);
	static void FindEdgeName(EDGE * pEdge, CString & edgeName);
	static void FindVertexName(VERTEX * pVertex, CString & vertexName);
	static void SelectNamingMethod(bool bMethod);// true: Topology, false: Geometry
	static void GetNamingMethod(bool & bMethod);
};