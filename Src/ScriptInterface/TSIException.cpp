#include "stdafx.h"
#include "TSIException.h"

TSIException::TSIException(void)
{
}

TSIException::TSIException(const char * message)
: m_message(message)
{
}

TSIException::~TSIException(void)
{
}