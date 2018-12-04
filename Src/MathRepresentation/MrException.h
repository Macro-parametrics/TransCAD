#pragma once

#include ".\MrMacro.h"
#include ".\MrString.h"

class MrException;

class MR_API MrException
{
public:
	MrException(void);
	MrException(const MrString & message);

	virtual ~MrException(void) {}

	MrString Message(void) const {return _message;}
private:
	MrString _message;
};