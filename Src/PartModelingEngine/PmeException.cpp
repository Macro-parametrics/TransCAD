#include "StdAfx.h"
#include ".\pmeexception.h"

PmeException::PmeException(void)
{
}

PmeException::PmeException(const CString & message)
: m_message(message)
{
}

PmeException::~PmeException(void)
{
}
