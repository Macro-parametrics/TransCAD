#include <cmath>
#include ".\MrAxis2.h"
#include ".\MrVector.h"
#include ".\MrMath.h"
#include ".\MrExceptionTest.h"
#include ".\MrIlligalArgumentException.h"
#include ".\MrDebug.h"

MR_BEGIN_CHECK(MrAxis2)
	MrDirection xdir = _this->XDirection();
	MrDirection ydir = _this->YDirection();
	MrDirection zdir = _this->ZDirection();

	MR_CHECK_CONDITION(MrMath::IsNormal(xdir, ydir));
	MR_CHECK_CONDITION(MrMath::IsNormal(ydir, zdir));
	MR_CHECK_CONDITION(MrMath::IsNormal(zdir, xdir));
MR_END_CHECK

const MrAxis2 MrAxis2::s_OXY = MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, 0.0, 1.0), MrDirection(1.0, 0.0, 0.0));
const MrAxis2 MrAxis2::s_OYZ = MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(1.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0));
const MrAxis2 MrAxis2::s_OZX = MrAxis2(MrPosition(0.0, 0.0, 0.0), MrDirection(0.0, 1.0, 0.0), MrDirection(0.0, 0.0, 1.0));

MrAxis2::MrAxis2(void)
	: _location(0.0, 0.0, 0.0)
	, _xDirection(1.0, 0.0, 0.0)
	, _yDirection(0.0, 1.0, 0.0)
	, _zDirection(0.0, 0.0, 1.0)
{
	MR_CHECK();
}

MrAxis2::MrAxis2(const MrPosition & location, const MrDirection & zDirection, const MrDirection & xDirection)
: _location(location)
, _zDirection(zDirection)
{
	MrThrowExceptionIf<MrIlligalArgumentException>(MrMath::IsParallel(zDirection, xDirection));

	MrVector projX(zDirection, MrMath::Dot(xDirection, zDirection));
	MrVector vecX = xDirection - projX;
	_xDirection = MrDirection(vecX);
	_yDirection = MrDirection(_zDirection ^ _xDirection);

	MR_CHECK();
}

MrAxis2::MrAxis2(const MrPosition & location, const MrDirection & zDirection)
: _location(location)
, _zDirection(zDirection)
{
	double A = std::abs(zDirection.X());
	double B = std::abs(zDirection.Y());
	double C = std::abs(zDirection.Z());
	MrDirection dx;

	if(A >= C && B >= C)
	{
		if(A > B)
            dx.SetCoordinates(-B, A, 0.0);
		else
			dx.SetCoordinates(B, -A, 0.0);
	}
	else if(A >= B && C >= B)
	{
		if(A > C)
            dx.SetCoordinates(-C, 0.0, A);
		else
			dx.SetCoordinates(C, 0.0, -A);
	}
	else
	{
		if(B > C)
            dx.SetCoordinates(0.0, -C, B);
		else
			dx.SetCoordinates(0.0, C, -B);
	}

	SetXDirection(dx);

	MR_CHECK();
}

void MrAxis2::SetLocation(const MrPosition & location)
{
	_location = location;
}

void MrAxis2::SetXDirection(const MrDirection & xDirection)
{
	MrThrowExceptionIf<MrIlligalArgumentException>(MrMath::IsParallel(_zDirection, xDirection));

	MrVector projX(_zDirection, MrMath::Dot(xDirection, _zDirection));
	MrVector vecX = xDirection - projX;
	_xDirection = MrDirection(vecX);
	_yDirection = MrDirection(_zDirection ^ _xDirection);

	MR_CHECK();
}

void MrAxis2::SetYDirection(const MrDirection & yDirection)
{
	MrThrowExceptionIf<MrIlligalArgumentException>(MrMath::IsParallel(_zDirection, yDirection));

	MrVector projY(_zDirection, MrMath::Dot(yDirection, _zDirection));
	MrVector vecY = yDirection - projY;
	_yDirection = MrDirection(vecY);
	_xDirection = MrDirection(_yDirection ^ _zDirection);

	MR_CHECK();
}

void MrAxis2::SetZDirection(const MrDirection & zDirection)
{
	if(MrMath::IsEqual(zDirection, _xDirection))
	{
		_xDirection = _yDirection;
		_yDirection = _zDirection;
		_zDirection = zDirection;
	}
	else if(MrMath::IsOpposite(zDirection, _xDirection))
	{
		_xDirection = _zDirection;
		_zDirection = zDirection;
	}
	else
	{
		MrVector projX(zDirection, MrMath::Dot(_xDirection, zDirection));
		MrVector vecX = _xDirection - projX;
		_xDirection = MrDirection(vecX);
		_yDirection = MrDirection(zDirection ^ _xDirection);
		_zDirection = zDirection;
	}

	MR_CHECK();
}