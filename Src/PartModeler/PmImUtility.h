#pragma once

#include ".\PmMacro.h"

class PM_API PmImUtility
{
public:
	static void RegisterCallbacks();
    static void DatumPlaneCallback(HIC_Rendition * nr, HIC_Segment_Info * si);
	
private:
	static void ScaleIndependentSegment(HIC_Rendition * nr, HIC_Segment_Info * si, float scale);
};
