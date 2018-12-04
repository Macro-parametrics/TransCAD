#include ".\MrInvalidNormalizationException.h"

MrInvalidNormalizationException::MrInvalidNormalizationException(void)
{
}

MrInvalidNormalizationException::MrInvalidNormalizationException(const MrString & message)
: MrException(message)
{
}