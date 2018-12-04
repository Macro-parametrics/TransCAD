#include <cmath>
#include ".\MrPosition.h"
#include ".\MrVector.h"
#include ".\MrExceptionTest.h"
#include ".\MrArgumentOutOfRangeException.h"

const unsigned int MrPosition::s_dimension = 3;
const MrPosition MrPosition::s_O = MrPosition(0.0, 0.0, 0.0);

MrPosition::MrPosition(void)
: _x(0.0)
, _y(0.0)
, _z(0.0)
{
}

MrPosition::MrPosition(double x, double y, double z)
: _x(x)
, _y(y)
, _z(z)
{
}

void MrPosition::Coordinates(double & x, double & y, double & z) const
{
	x = _x;
	y = _y;
	z = _z;
}

void MrPosition::SetCoordinates(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

double & MrPosition::operator()(unsigned int index)
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Dimension());

	return *(&_x + index);
}

double MrPosition::operator()(unsigned int index) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Dimension());

	return *(&_x + index);
}

MrPosition & MrPosition::operator+=(const MrVector & v)
{
	_x += v.X();
	_y += v.Y();
	_z += v.Z();

	return *this;
}

MrPosition & MrPosition::operator-=(const MrVector & v)
{
	_x -= v.X();
	_y -= v.Y();
	_z -= v.Z();

	return *this;
}

MrPosition & MrPosition::operator*=(double d)
{
	_x *= d;
	_y *= d;
	_z *= d;

	return *this;
}