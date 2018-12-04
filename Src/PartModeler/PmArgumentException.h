#pragma once
#include "pmexception.h"

class PM_API PmArgumentException
	: public PmException
{
public:
	PmArgumentException(void);
	PmArgumentException(const CString & message);	
	virtual ~PmArgumentException(void);
};