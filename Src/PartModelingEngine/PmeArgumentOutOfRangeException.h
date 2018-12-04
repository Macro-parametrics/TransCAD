#pragma once
#include "pmeargumentexception.h"

class PME_API PmeArgumentOutOfRangeException :
	public PmeArgumentException
{
public:
	PmeArgumentOutOfRangeException(void);
	PmeArgumentOutOfRangeException(const CString & message);
	virtual ~PmeArgumentOutOfRangeException(void);
};
