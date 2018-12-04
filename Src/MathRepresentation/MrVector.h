#pragma once

#include ".\MrMacro.h"

class MrDirection;
class MrPosition;

class MR_API MrVector
{
public:
	// Constructors
	MrVector(void);
	MrVector(double x, double y, double z);
	MrVector(const MrDirection & dir, double length = 1.0);
	MrVector(const MrPosition & point);
	MrVector(const MrPosition & start, const MrPosition & end);

	// Properties
	double X(void) const {return _x;}
	double Y(void) const {return _y;}
	double Z(void) const {return _z;}

	void SetX(double x) {_x = x;}
	void SetY(double y) {_y = y;}
	void SetZ(double z) {_z = z;}

	void Coordinates(double & x, double & y, double & z) const;
	void SetCoordinates(double x, double y, double z);

	double & operator()(unsigned int index);
	double operator()(unsigned int index) const;

	// Constants
	static unsigned int Dimension(void) {return s_dimension;}
	static const MrVector & O(void) {return s_O;}
	static const MrVector & OX(void) {return s_OX;}
	static const MrVector & OY(void) {return s_OY;}
	static const MrVector & OZ(void) {return s_OZ;}

	// Operators
	MrVector & operator+=(const MrVector & v);
	MrVector & operator-=(const MrVector & v);
	MrVector & operator*=(double d);
	MrVector & operator^=(const MrVector & v); // cross product

private:
	static const unsigned int s_dimension;
	static const MrVector s_O;
	static const MrVector s_OX;
	static const MrVector s_OY;
	static const MrVector s_OZ;

	double _x;
	double _y;
	double _z;
};