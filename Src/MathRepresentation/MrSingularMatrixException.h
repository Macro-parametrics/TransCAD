#pragma once

#include ".\MrMacro.h"
#include ".\MrException.h"

class MrSingularMatrixException;

class MR_API MrSingularMatrixException
	: public MrException
{
public:
	MrSingularMatrixException(void);
	MrSingularMatrixException(const MrString & message);
};