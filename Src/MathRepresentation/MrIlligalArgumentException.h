#pragma once

#include ".\MrMacro.h"
#include ".\MrException.h"
#include ".\MrString.h"

class MrIlligalArgumentException
	: public MrException
{
public:
	MrIlligalArgumentException(void);
	MrIlligalArgumentException(const MrString & message);
	MrIlligalArgumentException(const MrString & message, const MrString & argument);

	MrString Argument() const {return _argument;}

private:
	MrString _argument;
};