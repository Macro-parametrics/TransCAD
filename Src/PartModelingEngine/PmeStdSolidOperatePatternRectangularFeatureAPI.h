#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidOperatePatternRectangularFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReferences hTargetFeatures,
		double columnSpacing,
		const MrDirection & columnDirection,
		int columnNumber,
		double rowSpacing,
		const MrDirection & rowDirection,
		int rowNumber,
		PmeHFeature & hFeature
	);

	static void GetTargetFeatures(PmeHFeature hFeature, PmeHReferences & hTargetFeatures);
	static void GetColumnSpacing(PmeHFeature hFeature, double & columnSpacing);
	static void GetColumnDirection(PmeHFeature hFeature, MrDirection & columnDirection);
	static void GetColumnNumber(PmeHFeature hFeature, int & columnNumber);
	static void GetRowSpacing(PmeHFeature hFeature, double & rowSpacing);
	static void GetRowDirection(PmeHFeature hFeature, MrDirection & rowDirection);
	static void GetRowNumber(PmeHFeature hFeature, int & rowNumber);

	static void SetTargetFeatures(PmeHFeature hFeature, PmeHReferences hTargetFeatures);
	static void SetColumnSpacing(PmeHFeature hFeature, double columnSpacing);
	static void SetColumnDirection(PmeHFeature hFeature, MrDirection columnDirection);
	static void SetColumnNumber(PmeHFeature hFeature, int columnNumber);
	static void SetRowSpacing(PmeHFeature hFeature, double rowSpacing);
	static void SetRowDirection(PmeHFeature hFeature, MrDirection rowDirection);
	static void SetRowNumber(PmeHFeature hFeature, int rowNumber);
};