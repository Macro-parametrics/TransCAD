#define _USE_MATH_DEFINES

#include <cmath>
#include ".\MrDirection.h"
#include ".\MrVector.h"
#include ".\MrTolerance.h"
#include ".\MrExceptionTest.h"
#include ".\MrInvalidNormalizationException.h"
#include ".\MrArgumentOutOfRangeException.h"
#include ".\MrDebug.h"

MR_BEGIN_CHECK(MrDirection)
	double x = _this->X();
	double y = _this->Y();
	double z = _this->Z();
	double mag = std::sqrt(x * x + y * y + z * z);

	MR_CHECK_CONDITION(MrTolerance::IsZeroDistance(mag - 1.0));
MR_END_CHECK

const unsigned int MrDirection::s_dimension = 3;
const MrDirection MrDirection::s_OX = MrDirection(1.0, 0.0, 0.0);
const MrDirection MrDirection::s_OY = MrDirection(0.0, 1.0, 0.0);
const MrDirection MrDirection::s_OZ = MrDirection(0.0, 0.0, 1.0);

MrDirection::MrDirection(void)
: _x(0.0)
, _y(0.0)
, _z(1.0)
{
	MR_CHECK();
}

MrDirection::MrDirection(double x, double y, double z)
{
	SetCoordinates(x, y, z);
}

MrDirection::MrDirection(const MrVector & v)
{
	SetCoordinates(v.X(), v.Y(), v.Z());
}

void MrDirection::SetX(double x)
{
	SetCoordinates(x, _y, _z);
}

void MrDirection::SetY(double y)
{
	SetCoordinates(_x, y, _z);
}

void MrDirection::SetZ(double z)
{
	SetCoordinates(_x, _y, z);
}

void MrDirection::Coordinates(double & x, double & y, double & z) const
{
	x = _x;
	y = _y;
	z = _z;
}

void MrDirection::SetCoordinates(double x, double y, double z)
{
	double d = std::sqrt(x * x + y * y + z * z);

	MrThrowExceptionIf<MrInvalidNormalizationException>(MrTolerance::IsZeroDistance(d));
	
	_x = x / d;
	_y = y / d;
	_z = z / d;

	MR_CHECK();
}

double MrDirection::operator()(unsigned int index) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Dimension());

	return *(&_x + index);
}