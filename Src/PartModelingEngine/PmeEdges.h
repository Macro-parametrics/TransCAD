#pragma once
#include "pmeobject.h"
#include ".\PmeBaseList.h"

class PmeEdge;

class PmeEdges
	: public PmeObject
	, public PmeBaseList<PmeEdge *>
{
	typedef PmeBaseList<PmeEdge *> BaseList;
	PME_DECLARE_RUNTIME_TYPE(PmeEdges)
public:
	PmeEdges(void);
	virtual ~PmeEdges(void);
};