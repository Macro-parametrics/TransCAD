#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"
#include "PmeFaceType.h"

class PME_API PmeFaceAPI
{
public:
	static void GetName(PmeHFace hFace, CString & name);
	static void GetType(PmeHFace hFace, PmeFaceType & type);
	static void GetEdges(PmeHFace hFace, PmeHEdges & hEdges);
	static void GetVertices(PmeHFace hFace, PmeHVertices & hVertices);

	static void GetCentroid(PmeHFace hFace, MrPosition & centroid);
	static void GetXDirection(PmeHFace hFace, MrDirection & xDirection);
	static void GetYDirection(PmeHFace hFace, MrDirection & yDirection);
	static void GetZDirection(PmeHFace hFace, MrDirection & zDirection);
	static void GetArea(PmeHFace hFace, double & area);
};