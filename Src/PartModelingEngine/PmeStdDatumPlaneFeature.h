#pragma once
#include ".\PmeStdDatumFeature.h"

class PmeStdDatumPlaneFeature
	: public PmeStdDatumFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdDatumPlaneFeature)
public:
	PmeStdDatumPlaneFeature(PmePart * pPart);
	PmeStdDatumPlaneFeature(PmePart * pPart, const CString & name);
	virtual ~PmeStdDatumPlaneFeature(void);
};
