#include <cmath>
#include ".\MrAffineTransformation.h"
#include ".\MrVector.h"
#include ".\MrPosition.h"
#include ".\MrDirection.h"
#include ".\MrAxis1.h"
#include ".\MrAxis2.h"
#include ".\MrMath.h"
#include ".\MrTransformation.h"
#include ".\MrTolerance.h"
#include ".\MrExceptionTest.h"
#include ".\MrIlligalArgumentException.h"
#include ".\MrArgumentOutOfRangeException.h"

#include ".\MrDebug.h"

MR_BEGIN_CHECK(MrAffineTransformation)
	double det = std::abs(MrMath::Det(_this->Rotation()));

	MR_CHECK_CONDITION(!MrTolerance::IsZeroValue(det));
MR_END_CHECK

const unsigned int MrAffineTransformation::s_rowSize = 3;
const unsigned int MrAffineTransformation::s_columnSize = 4;

MrAffineTransformation::MrAffineTransformation(void)
: _rotation(MrMatrix::Identity())
, _translation(0.0, 0.0, 0.0)
{
	MR_CHECK();
}

MrAffineTransformation::MrAffineTransformation(const MrMatrix & rotation, const MrVector & translation)
:
#if _DEBUG
 _rotation(MrMatrix::Identity())
,
#endif
_translation(translation)
{
	SetRotation(rotation);

	MR_CHECK();
}

MrAffineTransformation::MrAffineTransformation(const MrTransformation & trsf)
: _rotation(trsf.ScaleFactor() * trsf.Rotation())
, _translation(trsf.Translation())
{
}

void MrAffineTransformation::SetRotation(const MrMatrix & rotation)
{
	double adet = std::abs(MrMath::Det(rotation));
	MrThrowExceptionIf<MrIlligalArgumentException>(
		MrTolerance::IsZeroValue(adet)
		, L"Illigal rotation matrix"
		);

	_rotation = rotation;

	MR_CHECK();
}

void MrAffineTransformation::SetTranslation(const MrVector & translation)
{
	_translation = translation;
}

double MrAffineTransformation::operator()(unsigned int i, unsigned int j) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(i >= RowSize() || j >= ColumnSize());

	if(j == ColumnSize() - 1)
		return _translation(i);
	else
		return _rotation(i, j);
}

void MrAffineTransformation::Transform(double x, double y, double z, double & nx, double & ny, double & nz) const
{
	nx = _rotation.M00() * x + _rotation.M01() * y + _rotation.M02() * z;
	ny = _rotation.M10() * x + _rotation.M11() * y + _rotation.M12() * z;
	nz = _rotation.M20() * x + _rotation.M21() * y + _rotation.M22() * z;

	nx += _translation.X();
	ny += _translation.Y();
	nz += _translation.Z();
}

MrPosition MrAffineTransformation::Transform(const MrPosition & p) const
{
	double nx, ny, nz;
	Transform(p.X(), p.Y(), p.Z(), nx, ny, nz);

	return MrPosition(nx, ny, nz);
}

MrAffineTransformation & MrAffineTransformation::operator*=(const MrAffineTransformation & trsf)
{
	// The sequence is important.
	MrVector temp = _rotation * trsf._translation;
	_translation += temp;
	_rotation *= trsf._rotation;

	MR_CHECK();

	return *this;
}

MrAffineTransformation MrAffineTransformation::CreateTranslation(const MrVector & displacement)
{
	return MrAffineTransformation(MrMatrix::Identity(), displacement);
}

MrAffineTransformation MrAffineTransformation::CreateScale(double xScaleFactor, double yScaleFactor, double zScaleFactor)
{
	MrThrowExceptionIf<MrIlligalArgumentException>(
		MrTolerance::IsZeroValue(xScaleFactor) || MrTolerance::IsZeroValue(yScaleFactor) || MrTolerance::IsZeroValue(zScaleFactor)
		, L"Illigal scaling factors"
		);

	MrMatrix rotation(xScaleFactor, 0.0, 0.0, 0.0, yScaleFactor, 0.0, 0.0, 0.0, zScaleFactor);

	return MrAffineTransformation(rotation, MrVector(0.0, 0.0, 0.0));
}

MrAffineTransformation MrAffineTransformation::CreateScale(const MrPosition & fixedPoint, double xScaleFactor, double yScaleFactor, double zScaleFactor)
{
	MrThrowExceptionIf<MrIlligalArgumentException>(
		MrTolerance::IsZeroValue(xScaleFactor) || MrTolerance::IsZeroValue(yScaleFactor) || MrTolerance::IsZeroValue(zScaleFactor)
		, L"Illigal scaling factors"
		);

	MrMatrix rotation(xScaleFactor, 0.0, 0.0, 0.0, yScaleFactor, 0.0, 0.0, 0.0, zScaleFactor);

	MrVector translation(
		fixedPoint.X() * (1.0 - xScaleFactor)
		, fixedPoint.Y() * (1.0 - yScaleFactor)
		, fixedPoint.Z() * (1.0 - zScaleFactor)
		);

	return MrAffineTransformation(rotation, translation);
}

MrAffineTransformation MrAffineTransformation::CreateRotation(const MrAxis1 & axis, double angle)
{
	double cosine = std::cos(angle);
	double sine = std::sin(angle);
	double oneCosine = 1.0 - cosine;
	MrDirection n = axis.Direction();
	double nx = n.X(), ny = n.Y(), nz = n.Z();

	MrMatrix rot(
		cosine + oneCosine * nx * nx, oneCosine * nx * ny - nz * sine, oneCosine * nx * nz + ny *sine,
		oneCosine * ny * nx + nz *sine, cosine + oneCosine * ny * ny, oneCosine * ny * nz - nx *sine,
		oneCosine * nz * nx - ny *sine, oneCosine * nz * ny + nx *sine, cosine + oneCosine * nz * nz
		);

	MrPosition p0 = axis.Location();
	MrVector v0 = rot * (-p0);
	v0 += p0;

	return MrAffineTransformation(rot, v0);
}

MrAffineTransformation MrAffineTransformation::CreateMirror(const MrPosition & center)
{
	return MrAffineTransformation(-MrMatrix::Identity(), 2 * center);
}

MrAffineTransformation MrAffineTransformation::CreateMirror(const MrAxis1 & axis)
{
	MrDirection n = axis.Direction();
	double nx = n.X(), ny = n.Y(), nz = n.Z();
	double nxny = 2.0 * nx * ny;
	double nxnz = 2.0 * nx * nz;
	double nynz = 2.0 * ny * nz;

	MrMatrix mirror(
		2.0 * nx * nx - 1.0, nxny, nxnz,
		nxny, 2.0 * ny * ny - 1.0, nynz,
		nxnz, nynz, 2.0 * nz * nz - 1.0
		);

	MrPosition p0 = axis.Location();
	MrVector v0 = mirror * (-p0);
	v0 += p0;

	return MrAffineTransformation(mirror, v0);
}

MrAffineTransformation MrAffineTransformation::CreateMirror(const MrAxis2 & plane)
{
	MrDirection n = plane.ZDirection();
	double nx = n.X(), ny = n.Y(), nz = n.Z();
	double nxny = 2.0 * nx * ny;
	double nxnz = 2.0 * nx * nz;
	double nynz = 2.0 * ny * nz;

	MrMatrix mirror(
		2.0 * nx * nx, nxny, nxnz,
		nxny, 2.0 * ny * ny, nynz,
		nxnz, nynz, 2.0 * nz * nz
		);

	MrPosition p0 = plane.Location();
	MrVector v0 = mirror * p0;

	return MrAffineTransformation(MrMatrix::Identity() - mirror, v0);
}

MrAffineTransformation MrAffineTransformation::CreateCoordinateSystemTransformation(const MrAxis2 & destination)
{
	MrDirection xDir = destination.XDirection();
	MrDirection yDir = destination.YDirection();
	MrDirection zDir = destination.ZDirection();

	MrMatrix rB(
		xDir.X(), xDir.Y(), xDir.Z()
		, yDir.X(), yDir.Y(), yDir.Z()
		, zDir.X(), zDir.Y(), zDir.Z()
		);

	MrVector oB = -destination.Location();
	MrVector o = rB * oB;

	return MrTransformation(1.0, rB, o);
}

MrAffineTransformation MrAffineTransformation::CreateCoordinateSystemTransformation(const MrAxis2 & source, const MrAxis2 & destination)
{
	MrDirection sxDir = source.XDirection();
	MrDirection syDir = source.YDirection();
	MrDirection szDir = source.ZDirection();

	MrMatrix rA(
		sxDir.X(), syDir.X(), szDir.X()
		, sxDir.Y(), syDir.Y(), szDir.Y()
		, sxDir.Z(), syDir.Z(), szDir.Z()
		);

	MrDirection dxDir = destination.XDirection();
	MrDirection dyDir = destination.YDirection();
	MrDirection dzDir = destination.ZDirection();

	MrMatrix rB(
		dxDir.X(), dxDir.Y(), dxDir.Z()
		, dyDir.X(), dyDir.Y(), dyDir.Z()
		, dzDir.X(), dzDir.Y(), dzDir.Z()
		);

	MrMatrix r = rB * rA;

	MrVector oA = source.Location();
	MrVector oB = destination.Location();
	oA -= oB;
	MrVector o = rB * oA;

	return MrTransformation(1.0, r, o);
}