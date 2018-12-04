#pragma once

#include ".\MrMacro.h"
#include ".\MrException.h"

class MrArgumentOutOfRangeException;

class MR_API MrArgumentOutOfRangeException
	: public MrException
{
public:
	MrArgumentOutOfRangeException(void);
	MrArgumentOutOfRangeException(const MrString & message);
	MrArgumentOutOfRangeException(const MrString & message, const MrString & argument);

	MrString Argument() const {return _argument;}

private:
	MrString _argument;
};