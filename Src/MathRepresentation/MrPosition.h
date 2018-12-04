#pragma once

#include ".\MrMacro.h"

class MrPosition;
class MrVector;

class MR_API MrPosition
{
public:
	// Constructors
	MrPosition(void);
	MrPosition(double x, double y, double z);

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

	static const MrPosition & O(void) {return s_O;}

	// Operators
	MrPosition & operator+=(const MrVector & v);
	MrPosition & operator-=(const MrVector & v);
	MrPosition & operator*=(double d);

private:
	static const unsigned int s_dimension;
	static const MrPosition s_O;

	double _x;
	double _y;
	double _z;
};