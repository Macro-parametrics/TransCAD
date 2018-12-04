#pragma once
#include "pmeexplicitmodelobject.h"

class PmeSketch :
	public PmeExplicitModelObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeSketch)
public:
	PmeSketch(void);
	virtual ~PmeSketch(void);

	virtual PmeExplicitModelObjectType GetType(void) const {return PmeExplicitModelObjectType_Sketch;}
};