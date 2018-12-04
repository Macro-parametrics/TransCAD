#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeSolidAPI
{
public:
	static void GetSolid(PmeHExplicitModelObject hObject, BODY *& pBody);
	static void GetFaces(PmeHSolid hSolid, PmeHFaces & hFaces);
	static void GetEdges(PmeHSolid hSolid, PmeHEdges & hEdges);
	static void GetVertices(PmeHSolid hSolid, PmeHVertices & hVertices);
};