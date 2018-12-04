#include ".\MrIlligalArgumentException.h"

MrIlligalArgumentException::MrIlligalArgumentException(void)
{
}

MrIlligalArgumentException::MrIlligalArgumentException(const MrString & message)
: MrException(message)
{
}

MrIlligalArgumentException::MrIlligalArgumentException(const MrString & message, const MrString & argument)
: MrException(message)
, _argument(argument)
{
}