#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include "PmeEdgeType.h"

class PME_API PmeEdgeAPI
{
public:
	static void GetName(PmeHEdge hEdge, CString & name);
	static void GetType(PmeHEdge hEdge, PmeEdgeType & type);
	static void GetStartPoint(PmeHEdge hEdge, PmeHVertex & startPoint);
	static void GetEndPoint(PmeHEdge hEdge, PmeHVertex & endPoint);
};