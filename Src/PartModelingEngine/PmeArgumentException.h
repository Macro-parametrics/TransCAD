#pragma once
#include "pmeexception.h"

class PME_API PmeArgumentException
	: public PmeException
{
public:
	PmeArgumentException(void);
	PmeArgumentException(const CString & message);	
	virtual ~PmeArgumentException(void);
};