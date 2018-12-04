#include "stdafx.h"
#include "Reference.h"

Reference::Reference(Feature * pFeature, int referenceType)
	:Object(referenceType)
{
	SetFeature(pFeature);
}

Reference::~Reference(void)
{
}

void Reference::SetDepth(void)
{
	if (GetTargetFeature(0) == "XYPlane"
		|| GetTargetFeature(0) == "YZPlane"
		|| GetTargetFeature(0) == "ZXPlane"
		|| GetTargetFeature(0) == "PartBody")
		GetFeature()->SetDepth(1);
	else
	{
		int parentDepth = GetFeature()->GetPart()->GetFeatureByName(GetTargetFeature(0))->GetDepth();
		GetFeature()->SetDepth(parentDepth + 1);
	}
}