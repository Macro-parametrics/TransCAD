#pragma once
#include "pmeexception.h"

class PmeFileNotFoundException :
	public PmeException
{
public:
	PmeFileNotFoundException(void);
	PmeFileNotFoundException(const CString & message);
	~PmeFileNotFoundException(void);
};
