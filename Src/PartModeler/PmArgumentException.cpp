#include "StdAfx.h"
#include ".\PmArgumentException.h"

PmArgumentException::PmArgumentException(void)
{
}

PmArgumentException::PmArgumentException(const CString & message)
: PmException(message)
{
}

PmArgumentException::~PmArgumentException(void)
{
}
