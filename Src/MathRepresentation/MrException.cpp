#include ".\MrException.h"

MrException::MrException(void)
{
}

MrException::MrException(const MrString & message)
: _message(message)
{
}