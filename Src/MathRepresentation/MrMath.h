#pragma once

#include ".\MrMacro.h"
#include ".\MrPosition.h"
#include ".\MrVector.h"
#include ".\MrDirection.h"
#include ".\MrTransformation.h"
#include ".\MrAffineTransformation.h"

class MrMatrix;
class MrAxis1;
class MrAxis2;
class MrTransformation;
class MrAffineTransformation;

class MR_API MrMath
{
public:
	// Add
	static MrPosition Add(const MrPosition & p, const MrVector & v);
	static MrVector Add(const MrVector & v1, const MrVector & v2);
	static MrMatrix Add(const MrMatrix & m1, const MrMatrix & m2);

	// Subtract
	static MrPosition Subtract(const MrPosition & p, const MrVector & v);
	static MrVector Subtract(const MrVector & v1, const MrVector & v2);
    static MrMatrix Subtract(const MrMatrix & m1, const MrMatrix & m2);

	// Reverse
	static MrPosition Reverse(const MrPosition & p);
	static MrVector Reverse(const MrVector & v);
	static MrDirection Reverse(const MrDirection & dir);
	static MrMatrix Reverse(const MrMatrix & m);
	static MrAxis1 Reverse(const MrAxis1 & ax);
	static MrAxis2 Reverse(const MrAxis2 & ax);

	// Multiply
	static MrPosition Multiply(const MrPosition & p, double d);
	static MrVector Multiply(const MrVector & v, double d);
	static MrVector Multiply(const MrMatrix & m, const MrVector & v);
	static MrMatrix Multiply(const MrMatrix & m1, const MrMatrix & m2);
    static MrMatrix Multiply(const MrMatrix & m, double d);
	static MrTransformation Multiply(const MrTransformation & trsf1, const MrTransformation & trsf2);
	static MrAffineTransformation Multiply(const MrAffineTransformation & trsf1, const MrAffineTransformation & trsf2);

	// Cross product
	static MrVector Cross(const MrVector & v1, const MrVector & v2);

	// Dot product
	static double Dot(const MrVector & v1, const MrVector & v2);
	static double Dot(const MrDirection & dir1, const MrDirection & dir2);

	// Distance
	static double Distance(const MrPosition & p1, const MrPosition & p2);

	// Norm
	static double Norm(const MrVector & v);
	static double Norm(const MrDirection & dir) {return 1.0;}
	static double Norm(const MrAxis2 & ax1, const MrAxis2 & ax2);

	// Normalize
	static MrVector Normalize(const MrVector & v);
	static MrDirection Normalize(const MrDirection & dir) {return dir;}

	// Transpose
	static MrMatrix Transpose(const MrMatrix & m);	

	// Determinant
	static double Det(const MrMatrix & m);

	// Trace
	static double Trace(const MrMatrix & m);

	// Inverse
	static MrMatrix Inverse(const MrMatrix & m);
	static MrTransformation Inverse(const MrTransformation & trsf);
	static MrAffineTransformation Inverse(const MrAffineTransformation & trsf);

	// Angle
	static double Angle(const MrVector & v1, const MrVector & v2);
	static double Angle(const MrVector & v1, const MrVector & v2, const MrVector & reference);
	static double Angle(const MrDirection & dir1, const MrDirection & dir2);
	static double Angle(const MrDirection & dir1, const MrDirection & dir2, const MrDirection & reference);
	static double Angle(const MrAxis1 & ax1, const MrAxis1 & ax2);
	static double Angle(const MrAxis2 & ax1, const MrAxis2 & ax2);

	// IsEqual
	static bool IsEqual(const MrPosition & p1, const MrPosition & p2);
	static bool IsEqual(const MrVector & v1, const MrVector & v2);
	static bool IsEqual(const MrDirection & dir1, const MrDirection & dir2);
	static bool IsEqual(const MrAxis1 & ax1, const MrAxis1 & ax2);
	static bool IsEqual(const MrAxis2 & ax1, const MrAxis2 & ax2);

	// IsNormal
	static bool IsNormal(const MrVector & v1, const MrVector & v2);
	static bool IsNormal(const MrDirection & dir1, const MrDirection & dir2);
	static bool IsNormal(const MrAxis1 & ax1, const MrAxis1 & ax2);

	// IsOpposite
	static bool IsOpposite(const MrVector & v1, const MrVector & v2);
	static bool IsOpposite(const MrDirection & dir1, const MrDirection & dir2);
	static bool IsOpposite(const MrAxis1 & ax1, const MrAxis1 & ax2);

	// IsParallel
	static bool IsParallel(const MrVector & v1, const MrVector & v2);
	static bool IsParallel(const MrDirection & dir1, const MrDirection & dir2);
	static bool IsParallel(const MrAxis1 & ax1, const MrAxis1 & ax2);
	static bool IsParallel(const MrAxis2 & ax1, const MrAxis2 & ax2);

	// IsCoaxial
	static bool IsCoaxial(const MrAxis1 & ax1, const MrAxis1 & ax2);

	// IsCoplanar
	static bool IsCoplanar(const MrAxis2 & ax1, const MrAxis2 & ax2);

	// Transform
	static MrPosition Transform(const MrPosition & p, const MrTransformation & trsf);
	static MrVector Transform(const MrVector & v, const MrTransformation & trsf);
	static MrDirection Transform(const MrDirection & dir, const MrTransformation & trsf);
	static MrAxis1 Transform(const MrAxis1 & ax, const MrTransformation & trsf);
	static MrAxis2 Transform(const MrAxis2 & ax, const MrTransformation & trsf);

	// Affine transform
	static MrPosition Transform(const MrPosition & p, const MrAffineTransformation & trsf);
	static MrVector Transform(const MrVector & v, const MrAffineTransformation & trsf);
	static MrDirection Transform(const MrDirection & dir, const MrAffineTransformation & trsf);
	static MrAxis1 Transform(const MrAxis1 & ax, const MrAffineTransformation & trsf);

	// Projection
	// 19-03-19 Added by YK
	static MrVector Project(const MrVector &v1, const MrVector &v2);
	static MrVector ProjectOnPlane(const MrVector &v1, const MrVector &planeNormal);
};

// Operator overloads
MR_API inline MrPosition operator+(const MrPosition & p, const MrVector & v) {return MrMath::Add(p, v);}
MR_API inline MrVector operator+(const MrVector & v1, const MrVector & v2) {return MrMath::Add(v1, v2);}
MR_API inline MrMatrix operator+(const MrMatrix & m1, const MrMatrix & m2) {return MrMath::Add(m1, m2);}

MR_API inline MrPosition operator-(const MrPosition & p, const MrVector & v) {return MrMath::Subtract(p, v);}
MR_API inline MrPosition operator-(const MrPosition & p) {return MrMath::Reverse(p);}
MR_API inline MrVector operator-(const MrVector & v1, const MrVector & v2) {return MrMath::Subtract(v1, v2);}
MR_API inline MrVector operator-(const MrPosition & p1, const MrPosition & p2) {return MrVector(p2, p1);}
MR_API inline MrVector operator-(const MrVector & v) {return MrMath::Reverse(v);}
MR_API inline MrMatrix operator-(const MrMatrix & m1, const MrMatrix & m2) {return MrMath::Subtract(m1, m2);}
MR_API inline MrMatrix operator-(const MrMatrix & m) {return MrMath::Reverse(m);}
MR_API inline MrDirection operator-(const MrDirection & dir) {return MrMath::Reverse(dir);}

MR_API inline MrPosition operator*(const MrPosition & p, double d) {return MrMath::Multiply(p, d);}
MR_API inline MrPosition operator*(double d, const MrPosition & p) {return p * d;}
MR_API inline MrVector operator*(const MrVector & v, double d) {return MrMath::Multiply(v, d);}
MR_API inline MrVector operator*(double d, const MrVector & v) {return v * d;}
MR_API inline MrVector operator*(const MrMatrix & m, const MrVector & v) {return MrMath::Multiply(m, v);}
MR_API inline MrMatrix operator*(const MrMatrix & m1, const MrMatrix & m2) {return MrMath::Multiply(m1, m2);}
MR_API inline MrMatrix operator*(const MrMatrix & m, double d) {return MrMath::Multiply(m, d);}
MR_API inline MrMatrix operator*(double d, const MrMatrix & m) {return m * d;}
MR_API inline MrTransformation operator*(const MrTransformation & trsf1, const MrTransformation & trsf2) {return MrMath::Multiply(trsf1, trsf2);}
MR_API inline MrAffineTransformation operator*(const MrAffineTransformation & trsf1, const MrAffineTransformation & trsf2) {return MrMath::Multiply(trsf1, trsf2);}

MR_API inline MrVector operator^(const MrVector & v1, const MrVector & v2) {return MrMath::Cross(v1, v2);}

MR_API inline double operator&(const MrDirection & dir1, const MrDirection & dir2) {return MrMath::Dot(dir1, dir2);}
MR_API inline double operator&(const MrVector & v1, const MrVector & v2) {return MrMath::Dot(v1, v2);}
