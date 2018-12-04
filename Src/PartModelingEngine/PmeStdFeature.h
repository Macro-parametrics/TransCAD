#pragma once
#include "pmefeature.h"

class PmeStdFeature
	: public PmeFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdFeature)
public:
	PmeStdFeature(PmePart * pPart);
	PmeStdFeature(PmePart * pPart, const CString & name);
	virtual ~PmeStdFeature(void);
};
