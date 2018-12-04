#pragma once
#include "pmereference.h"

class PmeFeature;

class PmeFeatureReference :
	public PmeReference
{
	PME_DECLARE_RUNTIME_TYPE(PmeFeatureReference)
public:
	PmeFeatureReference(PmePart * pPart, PmeFeature * pFeature);
	virtual ~PmeFeatureReference(void);

	// PmeReference
	virtual PmeReferenceType GetReferenceType(void) const { return PmeReferenceType_Feature; }
};
