#include "stdafx.h"
#include "AssemArgumentException.h"

AssemArgumentException::AssemArgumentException(void)
{
}

AssemArgumentException::AssemArgumentException(const CString & message)
: AssemException(message)
{
}

AssemArgumentException::~AssemArgumentException(void)
{
}