#pragma once
#include "TSIException.h"

class TSIArgumentException
	: public TSIException
{
public:
	TSIArgumentException(void);
	TSIArgumentException(const char * message);
	virtual ~TSIArgumentException(void);
};