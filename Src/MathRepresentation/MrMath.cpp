#define _USE_MATH_DEFINES

#include <cmath>
#include ".\MrMath.h"
#include ".\MrMatrix.h"
#include ".\MrDirection.h"
#include ".\MrAxis1.h"
#include ".\MrAxis2.h"
#include ".\MrTransformation.h"

#include ".\MrTolerance.h"
#include ".\MrExceptionTest.h"
#include ".\MrSingularMatrixException.h"
#include ".\MrInvalidNormalizationException.h"

MrPosition MrMath::Add(const MrPosition & p, const MrVector & v)
{
	MrPosition ret = p;
	return ret += v;
}

MrVector MrMath::Add(const MrVector & v1, const MrVector & v2)
{
	MrVector ret = v1;
	return ret += v2;
}

MrMatrix MrMath::Add(const MrMatrix & m1, const MrMatrix & m2)
{
	MrMatrix ret = m1;
	return ret += m2;
}

MrPosition MrMath::Subtract(const MrPosition & p, const MrVector & v)
{
	MrPosition ret = p;
	return ret -= v;
}

MrVector MrMath::Subtract(const MrVector & v1, const MrVector & v2)
{
	MrVector ret = v1;
	return ret -= v2;
}

MrMatrix MrMath::Subtract(const MrMatrix & m1, const MrMatrix & m2)
{
	MrMatrix ret = m1;
	return ret -= m2;
}

MrPosition MrMath::Reverse(const MrPosition & p)
{
	return MrPosition(-p.X(), -p.Y(), -p.Z());
}

MrVector MrMath::Reverse(const MrVector & v)
{
	return MrVector(-v.X(), -v.Y(), -v.Z());
}

MrDirection MrMath::Reverse(const MrDirection & dir)
{
	return MrDirection(-dir.X(), -dir.Y(), -dir.Z());
}

MrMatrix MrMath::Reverse(const MrMatrix & m)
{
	MrMatrix ret = m;
	return ret *= -1;
}

MrAxis1 MrMath::Reverse(const MrAxis1 & ax)
{
	return MrAxis1(ax.Location(), -ax.Direction());
}

MrAxis2 MrMath::Reverse(const MrAxis2 & ax)
{
	return MrAxis2(ax.Location(), -ax.ZDirection(), ax.XDirection());
}

MrPosition MrMath::Multiply(const MrPosition & p, double d)
{
	MrPosition ret = p;
	return ret *= d;
}

MrVector MrMath::Multiply(const MrVector & v, double d)
{
	MrVector ret = v;
	return ret *= d;
}

MrVector MrMath::Multiply(const MrMatrix & m, const MrVector & v)
{
	return MrVector(
	m.M00() * v.X() + m.M01() * v.Y() + m.M02() * v.Z()
	, m.M10() * v.X() + m.M11() * v.Y() + m.M12() * v.Z()
	, m.M20() * v.X() + m.M21() * v.Y() + m.M22() * v.Z()
	);
}

MrMatrix MrMath::Multiply(const MrMatrix & m1, const MrMatrix & m2)
{
	MrMatrix ret = m1;
	return ret *= m2;
}

MrMatrix MrMath::Multiply(const MrMatrix & m, double d)
{
	MrMatrix ret = m;
	return ret *= d;
}

MrTransformation MrMath::Multiply(const MrTransformation & trsf1, const MrTransformation & trsf2)
{
	MrTransformation ret = trsf1;
	return ret *= trsf2;
}

MrAffineTransformation MrMath::Multiply(const MrAffineTransformation & trsf1, const MrAffineTransformation & trsf2)
{
	MrAffineTransformation ret = trsf1;
	return ret *= trsf2;
}

MrVector MrMath::Cross(const MrVector & v1, const MrVector & v2)
{
	MrVector ret = v1;
	return ret ^= v2;
}

double MrMath::Dot(const MrVector & v1, const MrVector & v2)
{
	return v1.X() * v2.X() + v1.Y() * v2.Y() + v1.Z() * v2.Z();
}

double MrMath::Dot(const MrDirection & dir1, const MrDirection & dir2)
{
	return dir1.X() * dir2.X() + dir1.Y() * dir2.Y() + dir1.Z() * dir2.Z();
}

double MrMath::Distance(const MrPosition & p1, const MrPosition & p2)
{
	double d = (p1.X() - p2.X()) * (p1.X() - p2.X())
			 + (p1.Y() - p2.Y()) * (p1.Y() - p2.Y())
			 + (p1.Z() - p2.Z()) * (p1.Z() - p2.Z());
	return std::sqrt(d);
}

double MrMath::Norm(const MrVector & v)
{
	return std::sqrt(v.X() * v.X() + v.Y() * v.Y() + v.Z() * v.Z());
}

double MrMath::Norm(const MrAxis2 & ax1, const MrAxis2 & ax2)
{
	double d = Distance(ax1.Location(), ax2.Location());
	double angle = Norm(Cross(ax1.Axis().Direction(), ax2.Axis().Direction()));

	return d * fabs(angle);
}

MrVector MrMath::Normalize(const MrVector & v)
{
	double d = Norm(v);

	MrThrowExceptionIf<MrInvalidNormalizationException>(MrTolerance::IsZeroDistance(d));

	return MrVector(v.X() / d, v.Y() / d, v.Z() / d);
}

MrMatrix MrMath::Transpose(const MrMatrix & m)
{
	return MrMatrix(m.M00(), m.M10(), m.M20(),
				  m.M01(), m.M11(), m.M21(),
				  m.M02(), m.M12(), m.M22());
}

double MrMath::Det(const MrMatrix & m)
{
	return m.M00() * m.M11() * m.M22() +
		   m.M01() * m.M12() * m.M20() +
		   m.M02() * m.M10() * m.M21() -
		   m.M02() * m.M11() * m.M20() -
		   m.M01() * m.M10() * m.M22() -
		   m.M00() * m.M12() * m.M21();
}

double MrMath::Trace(const MrMatrix & m)
{
	return m.M00() + m.M11() + m.M22();
}

MrMatrix MrMath::Inverse(const MrMatrix & m)
{
	double det = Det(m);

	MrThrowExceptionIf<MrSingularMatrixException>(MrTolerance::IsZeroValue(det));

	return MrMatrix(
          (m.M11() * m.M22() - m.M12() * m.M21()) / det
		, (m.M02() * m.M21() - m.M01() * m.M22()) / det
		, (m.M01() * m.M12() - m.M02() * m.M11()) / det
		, (m.M12() * m.M20() - m.M10() * m.M22()) / det
		, (m.M00() * m.M22() - m.M02() * m.M20()) / det
		, (m.M02() * m.M10() - m.M00() * m.M12()) / det
		, (m.M10() * m.M21() - m.M11() * m.M20()) / det
		, (m.M01() * m.M20() - m.M00() * m.M21()) / det
		, (m.M00() * m.M11() - m.M01() * m.M10()) / det
		);
}

MrTransformation MrMath::Inverse(const MrTransformation & trsf)
{
	double scaleFactor = 1.0 / trsf.ScaleFactor();
	MrMatrix rotation = Transpose(trsf.Rotation());
	MrVector translation = rotation * trsf.Translation();
	translation *= -scaleFactor;

	return MrTransformation(scaleFactor, rotation, translation);
}

MrAffineTransformation MrMath::Inverse(const MrAffineTransformation & trsf)
{
	MrMatrix rotation = Inverse(trsf.Rotation());
	MrVector translation = rotation * trsf.Translation();

	return MrAffineTransformation(rotation, -translation);
}

double MrMath::Angle(const MrVector & v1, const MrVector & v2)
{
	MrDirection dir1(v1);
	MrDirection dir2(v2);

	return MrMath::Angle(dir1, dir2);
}

double MrMath::Angle(const MrVector & v1, const MrVector & v2, const MrVector & reference)
{
	double angle = MrMath::Angle(v1, v2);

    MrVector cross = Cross(v1, v2);

	return (MrMath::Dot(cross, reference) >= 0.0) ? angle : -angle;
}

double MrMath::Angle(const MrDirection & dir1, const MrDirection & dir2)
{
	double cosine = Dot(dir1, dir2);

	if(cosine > -M_SQRT1_2 && cosine < M_SQRT1_2)
		return std::acos(cosine);

	double x = dir1.Y() * dir2.Z() - dir1.Z() * dir2.Y();
	double y = dir1.Z() * dir2.X() - dir1.X() * dir2.Z();
	double z = dir1.X() * dir2.Y() - dir1.Y() * dir2.X();

	double sine = std::sqrt(x * x + y * y + z * z);

	return (cosine < 0.0) ? M_PI - std::sin(sine) : std::sin(sine);
}

double MrMath::Angle(const MrDirection & dir1, const MrDirection & dir2, const MrDirection & reference)
{
	double angle = Angle(dir1, dir2);
	double dot = (dir1.Y() * dir2.Z() - dir1.Z() * dir2.Y()) * reference.X()
				+ (dir1.Z() * dir2.X() - dir1.X() * dir2.Z()) * reference.Y()
				+ (dir1.X() * dir2.Y() - dir1.Y() * dir2.X()) * reference.Z();

	return (dot >= 0.0) ? angle : -angle;
}

double MrMath::Angle(const MrAxis1 & ax1, const MrAxis1 & ax2)
{
	MrDirection dir1 = ax1.Direction();
	MrDirection dir2 = ax2.Direction();

	return MrMath::Angle(dir1, dir2);
}

double MrMath::Angle(const MrAxis2 & ax1, const MrAxis2 & ax2)
{
	MrDirection dir1 = ax1.ZDirection();
	MrDirection dir2 = ax2.ZDirection();

	return MrMath::Angle(dir1, dir2);
}

bool MrMath::IsEqual(const MrPosition & p1, const MrPosition & p2)
{
	return MrTolerance::IsZeroDistance(Distance(p1, p2));
}

bool MrMath::IsEqual(const MrVector & v1, const MrVector & v2)
{
	double mag1 = Norm(v1);
	double mag2 = Norm(v2);
	MrVector v = v1;
	v -= v2;

	if(MrTolerance::IsZeroDistance(mag1) || MrTolerance::IsZeroDistance(mag2))
		return MrTolerance::IsZeroDistance(Norm(v));
	else
        return MrTolerance::IsZeroDistance(Norm(v)) && MrTolerance::IsZeroAngle(Angle(v1, v2));
}

bool MrMath::IsEqual(const MrDirection & dir1, const MrDirection & dir2)
{
	double angle = Angle(dir1, dir2);

    return MrTolerance::IsZeroAngle(angle);
}

bool MrMath::IsEqual(const MrAxis1 & ax1, const MrAxis1 & ax2)
{
	return IsEqual(ax1.Location(), ax2.Location())
		&& IsEqual(ax1.Direction(), ax2.Direction());
}

bool MrMath::IsEqual(const MrAxis2 & ax1, const MrAxis2 & ax2)
{
	return IsEqual(ax1.Location(), ax2.Location())
		&& IsEqual(ax1.ZDirection(), ax2.ZDirection())
		&& IsEqual(ax1.XDirection(), ax2.XDirection())
		&& IsEqual(ax1.YDirection(), ax2.YDirection());
}

bool MrMath::IsNormal(const MrVector & v1, const MrVector & v2)
{
	if(MrTolerance::IsZeroDistance(Norm(v1)) || MrTolerance::IsZeroDistance(Norm(v2)))
		return false;

    MrDirection dir1(v1);
	MrDirection dir2(v2);

	return MrMath::IsNormal(dir1, dir2);
}

bool MrMath::IsNormal(const MrDirection & dir1, const MrDirection & dir2)
{
	double dot = Dot(dir1, dir2);

	return MrTolerance::IsZeroAngle(std::abs(dot));
}

bool MrMath::IsNormal(const MrAxis1 & ax1, const MrAxis1 & ax2)
{
	MrDirection dir1 = ax1.Direction();
	MrDirection dir2 = ax2.Direction();

	return MrMath::IsNormal(dir1, dir2);
}

bool MrMath::IsOpposite(const MrVector & v1, const MrVector & v2)
{
	if(MrTolerance::IsZeroDistance(Norm(v1)) || MrTolerance::IsZeroDistance(Norm(v2)))
		return false;
	
	MrDirection dir1(v1);
	MrDirection dir2(v2);

	return MrMath::IsOpposite(dir1, dir2);
}

bool MrMath::IsOpposite(const MrDirection & dir1, const MrDirection & dir2)
{
	double angle = Angle(dir1, dir2);

	return MrTolerance::IsZeroAngle(std::abs(angle - M_PI));
}

bool MrMath::IsOpposite(const MrAxis1 & ax1, const MrAxis1 & ax2)
{
	MrDirection dir1 = ax1.Direction();
	MrDirection dir2 = ax2.Direction();

	return MrMath::IsOpposite(dir1, dir2);
}

bool MrMath::IsParallel(const MrVector & v1, const MrVector & v2)
{
	if(MrTolerance::IsZeroDistance(Norm(v1)) || MrTolerance::IsZeroDistance(Norm(v2)))
		return false;

	MrDirection dir1(v1);
	MrDirection dir2(v2);

	return MrMath::IsParallel(dir1, dir2);
}

bool MrMath::IsParallel(const MrDirection & dir1, const MrDirection & dir2)
{
	double angle = Angle(dir1, dir2);
	
	return MrTolerance::IsZeroAngle(angle) || MrTolerance::IsZeroAngle(std::abs(angle - M_PI));
}

bool MrMath::IsParallel(const MrAxis1 & ax1, const MrAxis1 & ax2)
{
	MrDirection dir1 = ax1.Direction();
	MrDirection dir2 = ax2.Direction();

	return MrMath::IsParallel(dir1, dir2);
}

bool MrMath::IsParallel(const MrAxis2 & ax1, const MrAxis2 & ax2)
{
	MrDirection dir1 = ax1.ZDirection();
	MrDirection dir2 = ax2.ZDirection();

	return MrMath::IsParallel(dir1, dir2);
}

bool MrMath::IsCoaxial(const MrAxis1 & ax1, const MrAxis1 & ax2)
{
	MrDirection dir1 = ax1.Direction();
	MrDirection dir2 = ax2.Direction();

	if(!MrMath::IsParallel(dir1, dir2))
		return false;

	MrVector vec(ax1.Location(), ax2.Location());

	if(MrTolerance::IsZeroDistance(MrMath::Norm(vec)))
		return true;

	MrDirection dir(vec);

	return MrMath::IsParallel(dir1, dir)
		&& MrMath::IsParallel(dir2, dir);
}

bool MrMath::IsCoplanar(const MrAxis2 & ax1, const MrAxis2 & ax2)
{
	MrDirection dir1 = ax1.ZDirection();
	MrDirection dir2 = ax2.ZDirection();

	if(!MrMath::IsParallel(dir1, dir2))
		return false;

	MrVector vec(ax1.Location(), ax2.Location());

	if(MrTolerance::IsZeroDistance(MrMath::Norm(vec)))
		return true;
	
	MrDirection dir(vec);

	return MrMath::IsNormal(dir1, dir) && MrMath::IsNormal(dir2, dir);
}

MrPosition MrMath::Transform(const MrPosition & p, const MrTransformation & trsf)
{
	return trsf.Transform(p);
}

MrVector MrMath::Transform(const MrVector & v, const MrTransformation & trsf)
{
	double ox, oy, oz;
	trsf.Transform(0.0, 0.0, 0.0, ox, oy, oz);

	double px, py, pz;
	trsf.Transform(v.X(), v.Y(), v.Z(), px, py, pz);

	return MrVector(px - ox, py - oy, pz - oz);
}

MrDirection MrMath::Transform(const MrDirection & dir, const MrTransformation & trsf)
{
	double ox, oy, oz;
	trsf.Transform(0.0, 0.0, 0.0, ox, oy, oz);

	double px, py, pz;
	trsf.Transform(dir.X(), dir.Y(), dir.Z(), px, py, pz);

	return MrDirection(px - ox, py - oy, pz - oz);
}

MrAxis1 MrMath::Transform(const MrAxis1 & ax, const MrTransformation & trsf)
{
	MrPosition newLocation = Transform(ax.Location(), trsf);
	MrDirection newMainDirection = Transform(ax.Direction(), trsf);

	return MrAxis1(newLocation, newMainDirection);
}

MrPosition MrMath::Transform(const MrPosition & p, const MrAffineTransformation & trsf)
{
	return trsf.Transform(p);
}

MrVector MrMath::Transform(const MrVector & v, const MrAffineTransformation & trsf)
{
	double ox, oy, oz;
	trsf.Transform(0.0, 0.0, 0.0, ox, oy, oz);

	double px, py, pz;
	trsf.Transform(v.X(), v.Y(), v.Z(), px, py, pz);

	return MrVector(px - ox, py - oy, pz - oz);
}

MrDirection MrMath::Transform(const MrDirection & dir, const MrAffineTransformation & trsf)
{
	double ox, oy, oz;
	trsf.Transform(0.0, 0.0, 0.0, ox, oy, oz);

	double px, py, pz;
	trsf.Transform(dir.X(), dir.Y(), dir.Z(), px, py, pz);

	return MrDirection(px - ox, py - oy, pz - oz);
}

MrAxis2 MrMath::Transform(const MrAxis2 & ax, const MrTransformation & trsf)
{
	MrPosition newLocation = Transform(ax.Location(), trsf);
	MrDirection newMainDirection = Transform(ax.ZDirection(), trsf);
	MrDirection newXDirection = Transform(ax.XDirection(), trsf);

	return MrAxis2(newLocation, newMainDirection, newXDirection);
}

MrAxis1 MrMath::Transform(const MrAxis1 & ax, const MrAffineTransformation & trsf)
{
	MrPosition newLocation = Transform(ax.Location(), trsf);
	MrDirection newMainDirection = Transform(ax.Direction(), trsf);

	return MrAxis1(newLocation, newMainDirection);
}

/**
 * 17-03-19 Added by YK
 * The vector projection a vector(v1) onto another vector(v2)
 * @param v1
 * projected vector
 * @param v2
 * destination vector
 */
MrVector MrMath::Project(const MrVector & v1, const MrVector & v2)
{
	MrVector proj, u, v;

	u.SetCoordinates(v1.X(), v1.Y(), v1.Z());
	v.SetCoordinates(v2.X(), v2.Y(), v2.Z());

	double value = MrMath::Dot( u, v ) / MrMath::Norm( v );
	
	proj.SetCoordinates( v.X() * value, v.Y() * value, v.Z() * value );

	return proj;	
}

/**
 * 17-03-20 Added by YK
 * The vector projection a vector(v1) onto a plane 
 * defined by a normal orthogonal to the plane
 * @param v1
 * projected vector
 * @param planeNormal
 * normal vector on the plane
 */
MrVector MrMath::ProjectOnPlane(const MrVector & v1, const MrVector & planeNormal )
{
	MrVector proj, v, n;
	
	v = v1;
	n = planeNormal;

	double distance = MrMath::Dot(v, n);
	MrVector transVector = n.operator*=(distance);

	proj = v.operator-=(transVector);

	return proj;
}