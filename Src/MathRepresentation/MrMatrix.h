#pragma once

#include ".\MrMacro.h"

class MrVector;

class MR_API MrMatrix
{
public:
	// Constructors
	MrMatrix(void);
	MrMatrix(double m00, double m01, double m02,
		   double m10, double m11, double m12,
		   double m20, double m21, double m22);

	// Constants
	static unsigned int RowSize(void) {return s_rowSize;}
	static unsigned int ColumnSize(void) {return s_columnSize;}
	static unsigned int Size(void) {return s_size;}

	static const MrMatrix & Identity(void) {return s_identity;}
	static const MrMatrix & Zero(void) {return s_zero;}

	// Properties
	double M00(void) const {return _m00;}
	double M01(void) const {return _m01;}
	double M02(void) const {return _m02;}
	double M10(void) const {return _m10;}
	double M11(void) const {return _m11;}
	double M12(void) const {return _m12;}
	double M20(void) const {return _m20;}
	double M21(void) const {return _m21;}
	double M22(void) const {return _m22;}

	void Get(double & m00, double & m01, double & m02,
			 double & m10, double & m11, double & m12,
             double & m20, double & m21, double & m22) const;
	void Rows(MrVector & row1, MrVector & row2, MrVector & row3) const;
	void Columns(MrVector & column1, MrVector & column2, MrVector & column3) const;
	void Diagonal(double & d1, double & d2, double & d3) const;

	void SetM00(double d) {_m00 = d;}
	void SetM01(double d) {_m01 = d;}
	void SetM02(double d) {_m02 = d;}
	void SetM10(double d) {_m10 = d;}
	void SetM11(double d) {_m11 = d;}
	void SetM12(double d) {_m12 = d;}
	void SetM20(double d) {_m20 = d;}
	void SetM21(double d) {_m21 = d;}
	void SetM22(double d) {_m22 = d;}

	void Set(double m00, double m01, double m02,
			 double m10, double m11, double m12,
             double m20, double m21, double m22);
	void SetRows(const MrVector & row1, const MrVector & row2, const MrVector & row3);
	void SetColumns(const MrVector & column1, const MrVector & column2, const MrVector & column3);
	void SetDiagonal(double d1, double d2, double d3);

	double & operator()(unsigned int index);
	double operator()(unsigned int index) const;
	double & operator()(unsigned int i, unsigned int j);
	double operator()(unsigned int i, unsigned int j) const;

	// Operators
	MrMatrix & operator+=(const MrMatrix & m);
	MrMatrix & operator-=(const MrMatrix & m);
	MrMatrix & operator*=(const MrMatrix & m);
	MrMatrix & operator*=(double d);
		
private:
	static const unsigned int s_rowSize;
	static const unsigned int s_columnSize;
	static const unsigned int s_size;

	static const MrMatrix s_identity;
	static const MrMatrix s_zero;

	double _m00, _m01, _m02;
	double _m10, _m11, _m12;
	double _m20, _m21, _m22;
};