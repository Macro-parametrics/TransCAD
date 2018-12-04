#pragma once
#include "assemexception.h"

class ASSEM_API AssemArgumentException
	: public AssemException
{
public:
	AssemArgumentException(void);
	AssemArgumentException(const CString & message);	
	virtual ~AssemArgumentException(void);
};