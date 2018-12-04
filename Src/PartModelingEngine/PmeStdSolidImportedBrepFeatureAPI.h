#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeStdSolidImportedBrepFeatureAPI
{
public:
	static void Create
	(
		PmeHPart hPart
		, const CString & name
		, const CString & filePath
		, PmeHFeature & hFeature
	);

	static void GetFilePath(PmeHFeature hFeature, CString & filePath);
};