#include "StdAfx.h"
#include ".\pmeargumentoutofrangeexception.h"

PmeArgumentOutOfRangeException::PmeArgumentOutOfRangeException(void)
{
}

PmeArgumentOutOfRangeException::PmeArgumentOutOfRangeException(const CString & message)
: PmeArgumentException(message)
{
}

PmeArgumentOutOfRangeException::~PmeArgumentOutOfRangeException(void)
{
}
