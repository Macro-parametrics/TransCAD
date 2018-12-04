#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSketchGeometriesAPI
{
public:
	static void GetSize(PmeHStdSketchGeometries & hGeometries, int & size);
	static void GetItem(PmeHStdSketchGeometries & hGeometries, int index, PmeHStdSketchGeometry & hGeometry);
	static void FindByItem(PmeHStdSketchGeometries & hGeometries, PmeHStdSketchGeometry hGeometry, int & index);
};