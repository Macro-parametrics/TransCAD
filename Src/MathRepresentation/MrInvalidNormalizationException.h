#pragma once

#include ".\MrMacro.h"
#include ".\MrException.h"

class MrInvalidNormalizationException;

class MR_API MrInvalidNormalizationException
	: public MrException
{
public:
	MrInvalidNormalizationException(void);
	MrInvalidNormalizationException(const MrString & message);
};