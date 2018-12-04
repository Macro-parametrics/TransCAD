#include <cmath>
#include ".\MrVector.h"
#include ".\MrDirection.h"
#include ".\MrMath.h"
#include ".\MrExceptionTest.h"
#include ".\MrArgumentOutOfRangeException.h"

const unsigned int MrVector::s_dimension = 3;
const MrVector MrVector::s_O = MrVector(0.0, 0.0, 0.0);
const MrVector MrVector::s_OX = MrVector(1.0, 0.0, 0.0);
const MrVector MrVector::s_OY = MrVector(0.0, 1.0, 0.0);
const MrVector MrVector::s_OZ = MrVector(0.0, 0.0, 1.0);

MrVector::MrVector(void)
: _x(0.0)
, _y(0.0)
, _z(0.0)
{
}

MrVector::MrVector(double x, double y, double z)
: _x(x)
, _y(y)
, _z(z)
{
}

MrVector::MrVector(const MrDirection & dir, double length)
: _x(dir.X() * length)
, _y(dir.Y() * length)
, _z(dir.Z() * length)
{
}

MrVector::MrVector(const MrPosition & point)
: _x(point.X())
, _y(point.Y())
, _z(point.Z())
{
}

MrVector::MrVector(const MrPosition & start, const MrPosition & end)
: _x(end.X() - start.X())
, _y(end.Y() - start.Y())
, _z(end.Z() - start.Z())
{
}

void MrVector::Coordinates(double & x, double & y, double & z) const
{
	x = _x;
	y = _y;
	z = _z;
}

void MrVector::SetCoordinates(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

double & MrVector::operator()(unsigned int index)
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Dimension());

	return *(&_x + index);
}

double MrVector::operator()(unsigned int index) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Dimension());

	return *(&_x + index);
}

MrVector & MrVector::operator+=(const MrVector & v)
{
	_x += v._x;
	_y += v._y;
	_z += v._z;

	return *this;
}

MrVector & MrVector::operator-=(const MrVector & v)
{
	_x -= v._x;
	_y -= v._y;
	_z -= v._z;

	return *this;
}

MrVector & MrVector::operator*=(double d)
{
	_x *= d;
	_y *= d;
	_z *= d;

	return *this;
}

MrVector & MrVector::operator^=(const MrVector & v)
{
	double x = _y * v._z - _z * v._y;
	double y = _z * v._x - _x * v._z;
	double z = _x * v._y - _y * v._x;

	_x = x;
	_y = y;
	_z = z;

	return *this;
}