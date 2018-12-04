#include "StdAfx.h"
#include ".\pmefilenotfoundexception.h"

PmeFileNotFoundException::PmeFileNotFoundException(void)
{
}

PmeFileNotFoundException::PmeFileNotFoundException(const CString & message)
: PmeException(message)
{
}

PmeFileNotFoundException::~PmeFileNotFoundException(void)
{
}
