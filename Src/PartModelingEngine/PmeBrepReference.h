#pragma once

#include ".\PmeReference.h"
#include ".\PmeBrepType.h"

class PmeBrepReference
	: public PmeReference
{
	PME_DECLARE_RUNTIME_TYPE(PmeBrepReference)
public:
	PmeBrepReference(PmePart * pPart, ENTITY * pEntity);
	virtual ~PmeBrepReference(void);

	virtual PmeBrepType GetBrepType(void) const;

	// PmeReference
	virtual PmeReferenceType GetReferenceType(void) const { return PmeReferenceType_Brep; }

private:
	PmeBrepType m_brepType;
};
