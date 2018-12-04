#pragma once
#include "PmeArgumentException.h"

class PME_API PmeArgumentTypeException
	: public PmeArgumentException
{
public:
	PmeArgumentTypeException(void);
	PmeArgumentTypeException(const CString & name);
	virtual ~PmeArgumentTypeException(void);
};
