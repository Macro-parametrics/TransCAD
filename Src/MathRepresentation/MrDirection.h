#pragma once

#include ".\MrMacro.h"

class MrVector;

class MR_API MrDirection
{
public:
	// Constructors
	MrDirection(void);
	MrDirection(double x, double y, double z);
	explicit MrDirection(const MrVector & v);

	// Properties
	double X(void) const {return _x;}
	double Y(void) const {return _y;}
	double Z(void) const {return _z;}

	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);

	void Coordinates(double & x, double & y, double & z) const;
	void SetCoordinates(double x, double y, double z);

	double operator()(unsigned int index) const;

	// Constants
	static unsigned int Dimension(void) {return s_dimension;}
	static const MrDirection & OX(void) {return s_OX;}
	static const MrDirection & OY(void) {return s_OY;}
	static const MrDirection & OZ(void) {return s_OZ;}

private:
	static const unsigned int s_dimension;
	static const MrDirection s_OX;
	static const MrDirection s_OY;
	static const MrDirection s_OZ;

	double _x;
	double _y;
	double _z;
};