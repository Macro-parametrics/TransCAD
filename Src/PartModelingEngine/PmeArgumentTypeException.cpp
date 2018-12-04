#include "StdAfx.h"
#include ".\PmeArgumentTypeException.h"

PmeArgumentTypeException::PmeArgumentTypeException(void)
{
}

PmeArgumentTypeException::PmeArgumentTypeException(const CString & name)
: PmeArgumentException(name)
{
}

PmeArgumentTypeException::~PmeArgumentTypeException(void)
{
}
