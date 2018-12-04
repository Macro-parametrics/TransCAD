#include "stdafx.h"

#include <cmath>
#include "Matrix.h"
#include "Vector.h"
#include "TSIExceptionTest.h"
#include "TSIArgumentException.h"

const unsigned int Matrix2D::s_rowSize = 2;
const unsigned int Matrix2D::s_columnSize = 2;
const unsigned int Matrix2D::s_size = 4;

const Matrix2D Matrix2D::s_identity = Matrix2D(1.0, 0.0, 0.0, 1.0);
const Matrix2D Matrix2D::s_zero = Matrix2D(0.0, 0.0, 0.0, 0.0);

Matrix2D::Matrix2D(void)
: _m00(0.0), _m01(0.0)
, _m10(0.0), _m11(0.0)
{
}

Matrix2D::Matrix2D(double m00, double m01,
			   double m10, double m11)
: _m00(m00), _m01(m01)
, _m10(m10), _m11(m11)
{
}

void Matrix2D::Get(double & m00, double & m01,
                 double & m10, double & m11) const
{
	m00 = _m00; m01 = _m01;
	m10 = _m10; m11 = _m11;
}

void Matrix2D::Rows(Vector2D & row1, Vector2D & row2) const
{
	row1 = Vector2D(_m00, _m01);
	row2 = Vector2D(_m10, _m11);
}

void Matrix2D::Columns(Vector2D & column1, Vector2D & column2) const
{
	column1 = Vector2D(_m00, _m10);
	column2 = Vector2D(_m01, _m11);
}

void Matrix2D::Diagonal(double & d1, double & d2) const
{
	d1 = _m00;
	d2 = _m11;
}

void Matrix2D::Set(double m00, double m01,
                 double m10, double m11)
{
	_m00 = m00; _m01 = m01;
	_m10 = m10; _m11 = m11;
}

void Matrix2D::SetRows(const Vector2D & row1, const Vector2D & row2)
{
	_m00 = row1.X(); _m01 = row1.Y();
	_m10 = row2.X(); _m11 = row2.Y();
}

void Matrix2D::SetColumns(const Vector2D & column1, const Vector2D & column2)
{
	_m00 = column1.X(); _m01 = column2.X();
	_m10 = column1.Y(); _m11 = column2.Y();
}

void Matrix2D::SetDiagonal(double d1, double d2)
{
    _m00 = d1;
	_m11 = d2;
}

double & Matrix2D::operator()(unsigned int index)
{
	TSIThrowExceptionIf<TSIArgumentException>(index >= Size(), "Index should be smaller than matrix size!");

	return *(&_m00 + index);
}

double Matrix2D::operator()(unsigned int index) const
{
	TSIThrowExceptionIf<TSIArgumentException>(index >= Size(), "Index should be smaller than matrix size!");

	return *(&_m00 + index);
}

double & Matrix2D::operator()(unsigned int i, unsigned int j)
{
	TSIThrowExceptionIf<TSIArgumentException>(i >= RowSize() || j >= ColumnSize(), "Index should be smaller than matrix size!");

	return *(&_m00 + (i * ColumnSize() + j));
}

double Matrix2D::operator()(unsigned int i, unsigned int j) const
{
	TSIThrowExceptionIf<TSIArgumentException>(i >= RowSize() || j >= ColumnSize(), "Index should be smaller than matrix size!");

	return *(&_m00 + (i * ColumnSize() + j));
}

Matrix2D & Matrix2D::operator+=(const Matrix2D & m)
{
	_m00 += m._m00;	_m01 += m._m01;
	_m10 += m._m10;	_m11 += m._m11;

	return *this;
}

Matrix2D & Matrix2D::operator-=(const Matrix2D & m)
{
	_m00 -= m._m00;	_m01 -= m._m01;
	_m10 -= m._m10;	_m11 -= m._m11;

	return *this;
}

Matrix2D & Matrix2D::operator*=(const Matrix2D & m)
{
	Matrix2D src = *this;

	_m00 = src._m00 * m._m00 + src._m01 * m._m10;
	_m01 = src._m00 * m._m01 + src._m01 * m._m11;
	_m10 = src._m10 * m._m00 + src._m11 * m._m10;
	_m11 = src._m10 * m._m01 + src._m11 * m._m11;

	return *this;
}

Matrix2D & Matrix2D::operator*=(double d)
{
	_m00 *= d;	_m01 *= d;
	_m10 *= d;	_m11 *= d;

	return *this;
}