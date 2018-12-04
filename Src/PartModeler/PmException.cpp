#include "StdAfx.h"
#include ".\pmexception.h"

PmException::PmException(void)
{
}

PmException::PmException(const CString & message)
: m_message(message)
{
}

PmException::~PmException(void)
{
}
