#pragma once
#include "pmeexception.h"

class PmeIlligalOperationException
	: public PmeException
{
public:
	PmeIlligalOperationException(void);
	PmeIlligalOperationException(const CString & message);	
	virtual ~PmeIlligalOperationException(void);
};
