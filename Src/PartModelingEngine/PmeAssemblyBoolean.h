#pragma once

#include ".\PmePart.h"

class PmeAssembly;
class PmeComponent;
class PmePart;

class PmeAssemblyBoolean
	: public PmePart
{
	PME_DECLARE_RUNTIME_TYPE(PmeAssemblyBoolean)

public:
	PmeAssemblyBoolean(PmeAssembly * pAssem);
	PmeAssemblyBoolean(PmeAssembly * pAssem, PmePart * pTool, PmePart * pBlank);
	PmeAssemblyBoolean(PmeAssembly * pAssem, PmePart * pTool, VARIANT_BOOL type);
	virtual ~PmeAssemblyBoolean(void);

private:
	PmeAssembly * m_pAssem;
	PmePart * m_pTool;
	PmePart * m_pBlank;
};
