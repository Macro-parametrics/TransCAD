#pragma once

#include ".\PmeRuntimeType.h"

class PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeObject)
public:
	PmeObject(void);
	virtual ~PmeObject(void);

public:
	bool IsInstanceOf(const PmeRuntimeType * pRuntimeType) const;
};