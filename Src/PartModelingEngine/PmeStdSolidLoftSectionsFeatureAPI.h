#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidLoftSectionsFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart,
		const CString & name,
		PmeHReferences hSections,
		bool isCut,
		PmeHFeature & hFeature
	);

	static void GetLoftSections(PmeHFeature hFeature, PmeHReferences & hLoftSections);
	static void IsCut(PmeHFeature hFeature, bool & isCut);
};
