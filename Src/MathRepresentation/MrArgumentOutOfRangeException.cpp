#include ".\MrArgumentOutOfRangeException.h"

MrArgumentOutOfRangeException::MrArgumentOutOfRangeException(void)
{
}

MrArgumentOutOfRangeException::MrArgumentOutOfRangeException(const MrString & message)
: MrException(message)
{
}

MrArgumentOutOfRangeException::MrArgumentOutOfRangeException(const MrString & message, const MrString & argument)
: MrException(message)
, _argument(argument)
{
}