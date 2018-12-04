#pragma once
#include "pmeobject.h"
#include ".\PmeBaseList.h"

class PmeVertex;

class PmeVertices
	: public PmeObject
	, public PmeBaseList<PmeVertex *>
{
	typedef PmeBaseList<PmeVertex *> BaseList;
	PME_DECLARE_RUNTIME_TYPE(PmeVertices)
public:
	PmeVertices(void);
	virtual ~PmeVertices(void);
};