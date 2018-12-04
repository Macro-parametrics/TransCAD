#include "StdAfx.h"
#include ".\pmeargumentnullexception.h"

PmeArgumentNullException::PmeArgumentNullException(void)
{
}

PmeArgumentNullException::PmeArgumentNullException(const CString & message)
: PmeArgumentException(message)
{
}

PmeArgumentNullException::~PmeArgumentNullException(void)
{
}
