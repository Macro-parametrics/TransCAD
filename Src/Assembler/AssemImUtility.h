#pragma once

#include "AssemMacro.h"

class ASSEM_API AssemImUtility
{
public:
	static void RegisterCallbacks();
    static void DatumPlaneCallback(HIC_Rendition * nr, HIC_Segment_Info * si);

private:
	static void ScaleIndependentSegment(HIC_Rendition * nr, HIC_Segment_Info * si, float scale);
};
