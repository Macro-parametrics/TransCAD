#include "StdAfx.h"
#include ".\pmeilligaloperationexception.h"

PmeIlligalOperationException::PmeIlligalOperationException(void)
{
}

PmeIlligalOperationException::PmeIlligalOperationException(const CString & message)
: PmeException(message)
{
}

PmeIlligalOperationException::~PmeIlligalOperationException(void)
{
}
