#pragma once

#include ".\PmeMacro.h"
#include ".\PmeHandle.h"

class PME_API PmeAssemblyBooleanAPI
{
public:

	static void Create(
		PmeHAssembly hAssem,
		const CString & name,
		PmeHPart hTool,
		PmeHPart hBlank
		);

	static void Create(
		PmeHAssembly hAssem,
		const CString & name,
		PmeHPart hTool,
		VARIANT_BOOL type
		);

};
