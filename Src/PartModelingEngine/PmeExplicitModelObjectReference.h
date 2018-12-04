#pragma once

#include ".\PmeReference.h"

class PmeExplicitModelObject;

class PmeExplicitModelObjectReference
	: public PmeReference
{
	PME_DECLARE_RUNTIME_TYPE(PmeExplicitModelObjectReference)
public:
	PmeExplicitModelObjectReference(PmePart * pPart, PmeExplicitModelObject * pObject);
	~PmeExplicitModelObjectReference(void);

	// PmeReference
	virtual PmeReferenceType GetReferenceType(void) const { return PmeReferenceType_ExplicitModelObject; }
};
