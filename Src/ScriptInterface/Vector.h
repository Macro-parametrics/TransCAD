#pragma once

#include <math.h>

typedef class Vector2D Point2D;
typedef class Vector2D Direct2D;

typedef class Vector3D Point3D;
typedef class Vector3D Direct3D;

class Vector2D 
{
public:

	Vector2D(void) : _x(0.0), _y(0.0) {}
	Vector2D(double x, double y) : _x(x), _y(y) {}
	Vector2D(double coord[]) : _x(coord[0]), _y(coord[1]) {}

	double X(void) const {return _x;}
	double Y(void) const {return _y;}

	void X(double x) { _x = x; }
	void Y(double y) { _y = y; }

	void SetXY(double x, double y) { _x = x;_y = y; }
	void SetXY(double rhs[2]) { _x = rhs[0]; _y = rhs[1]; }
	void SetXY(Vector2D & d) { _x = d._x; _y = d._y; }

	double & operator[](int i) { return *(&_x + i); }

	Vector2D operator+(const Vector2D & rhs){
		return Vector2D(_x + rhs._x, _y + rhs._y);
	}
	Vector2D operator-(const Vector2D & rhs){
		return Vector2D(_x - rhs._x, _y - rhs._y);
	}
	Vector2D operator*(double d){
		return Vector2D(_x * d, _y * d);
	}
	Vector2D operator/(double d){
		return Vector2D(_x / d, _y / d);
	}
	// Distance
	double GetDistance(Vector2D & d){
		return sqrt(pow(_x - d._x, 2) + pow(_y - d._y, 2));
	}
	// Dot product
	double operator*(Vector2D & d){
		return (_x*d._x+_y*d._y);
	}
	// Cross Product
	double operator^(Vector2D & d) {
		return _x * d._y - _y * d._x;
	}
	bool operator==(const Vector2D & rhs)
	{
		return _x == rhs._x && _y == rhs._y;
	}
	bool operator!=(const Vector2D & rhs)
	{
		return _x != rhs._x || _y != rhs._y;
	}
	void operator=(const Vector2D & rhs)
	{
		_x = rhs._x; _y = rhs._y;
	}

	double Size() const { return sqrt(_x*_x + _y*_y); }
	Vector2D Norm(void) { return Vector2D(_x,_y) / Size(); }

private:
	double _x, _y;
};

class Vector3D 
{
public:

	Vector3D(void) : _x(0.0), _y(0.0), _z(0.0) {}
	Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
	Vector3D(double coord[]) : _x(coord[0]), _y(coord[1]), _z(coord[2]) {}

	double X(void) const {return _x;}
	double Y(void) const {return _y;}
	double Z(void) const {return _z;}

	void X(double x) { _x = x; }
	void Y(double y) { _y = y; }
	void Z(double z) { _z = z; }

	void SetXYZ(double x, double y, double z) { _x = x;_y = y;_z = z;}
	void SetXYZ(double rhs[3]) {_x = rhs[0];_y = rhs[1];_z = rhs[2];}

	double & operator[](int i) {return *(&_x + i);}

	Vector3D operator+(const Vector3D & rhs){
		return Vector3D(_x + rhs._x, _y + rhs._y, _z + rhs._z);
	}
	Vector3D operator-(const Vector3D & rhs){
		return Vector3D(_x - rhs._x, _y - rhs._y, _z - rhs._z);
	}
	Vector3D operator*(double d){
		return Vector3D(_x * d, _y * d, _z * d);
	}
	Vector3D operator/(double d){
		return Vector3D(_x / d, _y / d, _z / d);
	}
	// Dot product
	double operator*(Vector3D & d){
		return (_x*d._x+_y*d._y+_z*d._z);
	}
	// Cross Product
	Vector3D operator^(Vector3D & d) {
		double i = _y * d._z - _z * d._y;
		double j = _z * d._x - _x * d._z;
		double k = _x * d._y - _y * d._x;
		return Vector3D(i,j,k);
	}
	bool operator==(const Vector3D & rhs)
	{
		return _x == rhs._x && _y == rhs._y && _z == rhs._z;
	}
	void operator=(const Vector3D & rhs)
	{
		_x = rhs._x; _y = rhs._y; _z = rhs._z;
	}

	bool IsBetween(Vector3D & d1, Vector3D & d2)
	{
		if(((d1._x <= _x && _x <= d2._x) || (d2._x <= _x && _x <= d1._x))
		&& ((d1._y <= _y && _y <= d2._y) || (d2._y <= _y && _y <= d1._y))
		&& ((d1._z <= _z && _z <= d2._z) || (d2._z <= _z && _z <= d1._z)))
			return true;

		return false;
	}

	double Size() const { return sqrt(_x*_x + _y*_y + _z*_z); }
	Vector3D Norm(void) { return Vector3D(_x,_y,_z) / Size(); }

private:
	double _x, _y, _z;
};