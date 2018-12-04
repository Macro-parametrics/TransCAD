#pragma once

class Matrix2D;
class Vector2D;

class MrMath
{
public:
	// Add
	static Vector2D Add(const Vector2D & v1, const Vector2D & v2);
	static Matrix2D Add(const Matrix2D & m1, const Matrix2D & m2);

	// Subtract
	static Vector2D Subtract(const Vector2D & v1, const Vector2D & v2);
    static Matrix2D Subtract(const Matrix2D & m1, const Matrix2D & m2);

	// Reverse
	static Vector2D Reverse(const Vector2D & v);
	static Matrix2D Reverse(const Matrix2D & m);

	// Multiply
	static Vector2D Multiply(const Matrix2D & m, const Vector2D & v);
	static Matrix2D Multiply(const Matrix2D & m1, const Matrix2D & m2);
    static Matrix2D Multiply(const Matrix2D & m, double d);

	// Dot product
	static double Dot(const Vector2D & v1, const Vector2D & v2);
	
	// Norm
	static double Norm(const Vector2D & v);

	// Transpose
	static Matrix2D Transpose(const Matrix2D & m);

	// Determinant
	static double Det(const Matrix2D & m);

	// Trace
	static double Trace(const Matrix2D & m);

	// Inverse
	static Matrix2D Inverse(const Matrix2D & m);

	// Angle
	static double Angle(const Vector2D & v1, const Vector2D & v2);

	// IsEqual
	static bool IsEqual(const Vector2D & v1, const Vector2D & v2);

	// IsNormal
	static bool IsNormal(const Vector2D & v1, const Vector2D & v2);

	// IsOpposite
	static bool IsOpposite(const Vector2D & v1, const Vector2D & v2);

	// IsParallel
	static bool IsParallel(const Vector2D & v1, const Vector2D & v2);

	// Round up, down ÇÔ¼ö
	static double Round(double val);
};