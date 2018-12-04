#pragma once

#include <math.h>

class Vector2D;

class Matrix2D
{
public:
	// Constructors
	Matrix2D(void);
	Matrix2D(double m00, double m01,
		     double m10, double m11);

	// Constants
	static unsigned int RowSize(void) {return s_rowSize;}
	static unsigned int ColumnSize(void) {return s_columnSize;}
	static unsigned int Size(void) {return s_size;}

	static const Matrix2D & Identity(void) {return s_identity;}
	static const Matrix2D & Zero(void) {return s_zero;}

	// Properties
	double M00(void) const {return _m00;}
	double M01(void) const {return _m01;}
	double M10(void) const {return _m10;}
	double M11(void) const {return _m11;}

	void Get(double & m00, double & m01,
			 double & m10, double & m11) const;
	
	void Rows(Vector2D & row1, Vector2D & row2) const;
	void Columns(Vector2D & column1, Vector2D & column2) const;
	void Diagonal(double & d1, double & d2) const;

	void SetM00(double d) {_m00 = d;}
	void SetM01(double d) {_m01 = d;}
	void SetM10(double d) {_m10 = d;}
	void SetM11(double d) {_m11 = d;}

	void Set(double m00, double m01,
			 double m10, double m11);

	void SetRows(const Vector2D & row1, const Vector2D & row2);
	void SetColumns(const Vector2D & column1, const Vector2D & column2);
	void SetDiagonal(double d1, double d2);

	double & operator()(unsigned int index);
	double operator()(unsigned int index) const;
	double & operator()(unsigned int i, unsigned int j);
	double operator()(unsigned int i, unsigned int j) const;

	// Operators
	Matrix2D & operator+=(const Matrix2D & m);
	Matrix2D & operator-=(const Matrix2D & m);
	Matrix2D & operator*=(const Matrix2D & m);
	Matrix2D & operator*=(double d);
		
private:
	static const unsigned int s_rowSize;
	static const unsigned int s_columnSize;
	static const unsigned int s_size;

	static const Matrix2D s_identity;
	static const Matrix2D s_zero;

	double _m00, _m01;
	double _m10, _m11;
};