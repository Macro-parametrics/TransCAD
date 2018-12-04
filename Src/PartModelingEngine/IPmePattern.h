#pragma once

#include "IPmeTransformable.h"

struct IPmePattern : public IPmeTransformable
{
	virtual bool IsCut(void) = 0;
};