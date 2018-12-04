#pragma once
#include "pmeargumentexception.h"

class PME_API PmeArgumentNullException
	: public PmeArgumentException
{
public:
	PmeArgumentNullException(void);
	PmeArgumentNullException(const CString & message);
	virtual ~PmeArgumentNullException(void);
};
