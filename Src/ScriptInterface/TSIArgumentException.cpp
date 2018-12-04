#include "stdafx.h"
#include "TSIArgumentException.h"

TSIArgumentException::TSIArgumentException(void)
{
}

TSIArgumentException::TSIArgumentException(const char * message)
: TSIException(message)
{
}

TSIArgumentException::~TSIArgumentException(void)
{
}