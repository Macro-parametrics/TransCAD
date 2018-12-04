#include "stdafx.h"

#include <cmath>
#include "Math.h"
#include "Matrix.h"
#include "Vector.h"

#define M_SQRT1_2 0.707106781186547524401
#define M_PI 3.14159265359

Vector2D MrMath::Add(const Vector2D & v1, const Vector2D & v2)
{
	Vector2D ret = v1;
	return ret + v2;
}

Matrix2D MrMath::Add(const Matrix2D & m1, const Matrix2D & m2)
{
	Matrix2D ret = m1;
	return ret += m2;
}

Vector2D MrMath::Subtract(const Vector2D & v1, const Vector2D & v2)
{
	Vector2D ret = v1;
	return ret - v2;
}

Matrix2D MrMath::Subtract(const Matrix2D & m1, const Matrix2D & m2)
{
	Matrix2D ret = m1;
	return ret -= m2;
}

Vector2D MrMath::Reverse(const Vector2D & v)
{
	return Vector2D(-v.X(), -v.Y());
}

Matrix2D MrMath::Reverse(const Matrix2D & m)
{
	Matrix2D ret = m;
	return ret *= -1;
}

Vector2D MrMath::Multiply(const Matrix2D & m, const Vector2D & v)
{
	return Vector2D(
	m.M00() * v.X() + m.M01() * v.Y()
	, m.M10() * v.X() + m.M11() * v.Y()
	);
}

Matrix2D MrMath::Multiply(const Matrix2D & m1, const Matrix2D & m2)
{
	Matrix2D ret = m1;
	return ret *= m2;
}

Matrix2D MrMath::Multiply(const Matrix2D & m, double d)
{
	Matrix2D ret = m;
	return ret *= d;
}

double MrMath::Dot(const Vector2D & v1, const Vector2D & v2)
{
	return v1.X() * v2.X() + v1.Y() * v2.Y();
}

double MrMath::Norm(const Vector2D & v)
{
	return std::sqrt(v.X() * v.X() + v.Y() * v.Y());
}

Matrix2D MrMath::Transpose(const Matrix2D & m)
{
	return Matrix2D(m.M00(), m.M10(),
				  m.M01(), m.M11());
}

double MrMath::Det(const Matrix2D & m)
{
	return m.M00() * m.M11() -
		   m.M01() * m.M10();
}

double MrMath::Trace(const Matrix2D & m)
{
	return m.M00() + m.M11();
}

double MrMath::Angle(const Vector2D & v1, const Vector2D & v2)
{
	Direct2D dir1(v1);
	Direct2D dir2(v2);

	double cosine = Dot(dir1, dir2);

	if(cosine > -M_SQRT1_2 && cosine < M_SQRT1_2)
		return std::acos(cosine);

	double z = dir1.X() * dir2.Y() - dir1.Y() * dir2.X();

	double sine = std::sqrt(z * z);

	return (cosine < 0.0) ? M_PI - std::sin(sine) : std::sin(sine);
}

double MrMath::Round(double val)
{
	double rest;					// 나머지 부분
	double digit = pow(10.0, 9);	// 자릿 수
	
	val = val * digit;
		
	rest = val - floor(val);

	if(rest >= 0.5)	// 나머지가 0.5보다 크면 올림, 작으면 내림
		val = ceil(val);
	else
		val = floor(val);
		
	val /= digit;

	return val;
}