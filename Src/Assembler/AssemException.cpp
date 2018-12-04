#include "stdafx.h"
#include "assemexception.h"

AssemException::AssemException(void)
{
}

AssemException::AssemException(const CString & message)
: m_message(message)
{
}

AssemException::~AssemException(void)
{
}
