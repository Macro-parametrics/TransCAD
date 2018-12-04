#include <cmath>
#include ".\MrMatrix.h"
#include ".\MrVector.h"
#include ".\MrExceptionTest.h"
#include ".\MrArgumentOutOfRangeException.h"

const unsigned int MrMatrix::s_rowSize = 3;
const unsigned int MrMatrix::s_columnSize = 3;
const unsigned int MrMatrix::s_size = 9;

const MrMatrix MrMatrix::s_identity = MrMatrix(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
const MrMatrix MrMatrix::s_zero = MrMatrix(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

MrMatrix::MrMatrix(void)
: _m00(0.0), _m01(0.0), _m02(0.0)
, _m10(0.0), _m11(0.0), _m12(0.0)
, _m20(0.0), _m21(0.0), _m22(0.0)
{
}

MrMatrix::MrMatrix(double m00, double m01, double m02,
			   double m10, double m11, double m12,
			   double m20, double m21, double m22)
: _m00(m00), _m01(m01), _m02(m02)
, _m10(m10), _m11(m11), _m12(m12)
, _m20(m20), _m21(m21), _m22(m22)
{
}

void MrMatrix::Get(double & m00, double & m01, double & m02,
                 double & m10, double & m11, double & m12,
                 double & m20, double & m21, double & m22) const
{
	m00 = _m00; m01 = _m01; m02 = _m02;
	m10 = _m10; m11 = _m11; m12 = _m12;
	m20 = _m20; m21 = _m21; m22 = _m22;
}

void MrMatrix::Rows(MrVector & row1, MrVector & row2, MrVector & row3) const
{
	row1 = MrVector(_m00, _m01, _m02);
	row2 = MrVector(_m10, _m11, _m12);
	row3 = MrVector(_m20, _m21, _m22);
}

void MrMatrix::Columns(MrVector & column1, MrVector & column2, MrVector & column3) const
{
	column1 = MrVector(_m00, _m10, _m20);
	column2 = MrVector(_m01, _m11, _m21);
	column3 = MrVector(_m02, _m12, _m22);
}

void MrMatrix::Diagonal(double & d1, double & d2, double & d3) const
{
	d1 = _m00;
	d2 = _m11;
	d3 = _m22;
}

void MrMatrix::Set(double m00, double m01, double m02,
                 double m10, double m11, double m12,
                 double m20, double m21, double m22)
{
	_m00 = m00; _m01 = m01; _m02 = m02;
	_m10 = m10; _m11 = m11; _m12 = m12;
	_m20 = m20; _m21 = m21; _m22 = m22;
}

void MrMatrix::SetRows(const MrVector & row1, const MrVector & row2, const MrVector & row3)
{
	_m00 = row1.X(); _m01 = row1.Y(); _m02 = row1.Z();
	_m10 = row2.X(); _m11 = row2.Y(); _m12 = row2.Z();
	_m20 = row3.X(); _m21 = row3.Y(); _m22 = row3.Z();
}

void MrMatrix::SetColumns(const MrVector & column1, const MrVector & column2, const MrVector & column3)
{
	_m00 = column1.X(); _m01 = column2.X(); _m02 = column3.X();
	_m10 = column1.Y(); _m11 = column2.Y(); _m12 = column3.Y();
	_m20 = column1.Z(); _m21 = column2.Z(); _m22 = column3.Z();
}

void MrMatrix::SetDiagonal(double d1, double d2, double d3)
{
    _m00 = d1;
	_m11 = d2;
	_m22 = d3;
}

double & MrMatrix::operator()(unsigned int index)
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Size());

	return *(&_m00 + index);
}

double MrMatrix::operator()(unsigned int index) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(index >= Size());

	return *(&_m00 + index);
}

double & MrMatrix::operator()(unsigned int i, unsigned int j)
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(i >= RowSize() || j >= ColumnSize());

	return *(&_m00 + (i * ColumnSize() + j));
}

double MrMatrix::operator()(unsigned int i, unsigned int j) const
{
	MrThrowExceptionIf<MrArgumentOutOfRangeException>(i >= RowSize() || j >= ColumnSize());

	return *(&_m00 + (i * ColumnSize() + j));
}

MrMatrix & MrMatrix::operator+=(const MrMatrix & m)
{
	_m00 += m._m00;	_m01 += m._m01;	_m02 += m._m02;
	_m10 += m._m10;	_m11 += m._m11;	_m12 += m._m12;
	_m20 += m._m20;	_m21 += m._m21;	_m22 += m._m22;

	return *this;
}

MrMatrix & MrMatrix::operator-=(const MrMatrix & m)
{
	_m00 -= m._m00;	_m01 -= m._m01;	_m02 -= m._m02;
	_m10 -= m._m10;	_m11 -= m._m11;	_m12 -= m._m12;
	_m20 -= m._m20;	_m21 -= m._m21;	_m22 -= m._m22;

	return *this;
}

MrMatrix & MrMatrix::operator*=(const MrMatrix & m)
{
	MrMatrix src = *this;

	_m00 = src._m00 * m._m00 + src._m01 * m._m10 + src._m02 * m._m20;
	_m01 = src._m00 * m._m01 + src._m01 * m._m11 + src._m02 * m._m21;
	_m02 = src._m00 * m._m02 + src._m01 * m._m12 + src._m02 * m._m22;
	_m10 = src._m10 * m._m00 + src._m11 * m._m10 + src._m12 * m._m20;
	_m11 = src._m10 * m._m01 + src._m11 * m._m11 + src._m12 * m._m21;
	_m12 = src._m10 * m._m02 + src._m11 * m._m12 + src._m12 * m._m22;
	_m20 = src._m20 * m._m00 + src._m21 * m._m10 + src._m22 * m._m20;
	_m21 = src._m20 * m._m01 + src._m21 * m._m11 + src._m22 * m._m21;
	_m22 = src._m20 * m._m02 + src._m21 * m._m12 + src._m22 * m._m22;

	return *this;
}

MrMatrix & MrMatrix::operator*=(double d)
{
	_m00 *= d;	_m01 *= d;	_m02 *= d;
	_m10 *= d;	_m11 *= d;	_m12 *= d;
	_m20 *= d;	_m21 *= d;	_m22 *= d;

	return *this;
}