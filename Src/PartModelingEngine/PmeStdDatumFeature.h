#pragma once
#include ".\pmestdfeature.h"

class PmeStdDatumFeature
	: public PmeStdFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdDatumFeature)
public:
	PmeStdDatumFeature(PmePart * pPart);
	PmeStdDatumFeature(PmePart * pPart, const CString & name);
	virtual ~PmeStdDatumFeature(void);
};
