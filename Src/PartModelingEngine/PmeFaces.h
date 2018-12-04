#pragma once
#include "pmeobject.h"
#include ".\PmeBaseList.h"

class PmeFace;

class PmeFaces
	: public PmeObject
	, public PmeBaseList<PmeFace *>
{
	typedef PmeBaseList<PmeFace *> BaseList;
	PME_DECLARE_RUNTIME_TYPE(PmeFaces)

public:
	PmeFaces(void);
	virtual ~PmeFaces(void);
};