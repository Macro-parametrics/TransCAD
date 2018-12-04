#include "StdAfx.h"
#include ".\PmeArgumentException.h"

PmeArgumentException::PmeArgumentException(void)
{
}

PmeArgumentException::PmeArgumentException(const CString & message)
: PmeException(message)
{
}

PmeArgumentException::~PmeArgumentException(void)
{
}
