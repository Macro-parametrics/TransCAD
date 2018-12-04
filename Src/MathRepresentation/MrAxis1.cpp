#include ".\MrAxis1.h"

const MrAxis1 MrAxis1::s_OX = MrAxis1(MrPosition(0.0, 0.0, 0.0), MrDirection(1.0, 0.0, 0.0));
const MrAxis1 MrAxis1::s_OY = MrAxis1(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0));
const MrAxis1 MrAxis1::s_OZ = MrAxis1(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, 0.0, 1.0));

MrAxis1::MrAxis1(void)
: _location(0.0, 0.0, 0.0)
, _direction(0.0, 0.0, 1.0)
{
}

MrAxis1::MrAxis1(const MrPosition & location, const MrDirection & direction)
: _location(location)
, _direction(direction)
{
}

void MrAxis1::SetLocation(const MrPosition & location)
{
	_location = location;
}

void MrAxis1::SetDirection(const MrDirection & direction)
{
	_direction = direction;
}