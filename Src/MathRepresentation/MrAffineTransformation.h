#pragma once

#include ".\MrMacro.h"
#include ".\MrMatrix.h"
#include ".\MrVector.h"

class MrTransformation;
class MrAxis1;
class MrAxis2;
class MrPosition;

class MR_API MrAffineTransformation
{
public:
	MrAffineTransformation(void);
	MrAffineTransformation(const MrMatrix & rotation, const MrVector & translation);
	MrAffineTransformation(const MrTransformation & trsf);

	// Properties
	MrMatrix Rotation(void) const {return _rotation;}
	MrVector Translation(void) const {return _translation;}

	void SetRotation(const MrMatrix & rotation);
	void SetTranslation(const MrVector & translation);

	double operator()(unsigned int i, unsigned int j) const;

	// Operators
	void Transform(double x, double y, double z, double & nx, double & ny, double & nz) const;
	MrPosition Transform(const MrPosition & p) const;

	static MrAffineTransformation CreateTranslation(const MrVector & displacement);
	static MrAffineTransformation CreateScale(const MrPosition & fixedPoint, double xScaleFactor, double yScaleFactor, double zScaleFactor);
	static MrAffineTransformation CreateScale(double xScaleFactor, double yScaleFactor, double zScaleFactor);
	static MrAffineTransformation CreateRotation(const MrAxis1 & axis, double angle);
	static MrAffineTransformation CreateMirror(const MrPosition & center);
	static MrAffineTransformation CreateMirror(const MrAxis1 & axis);
	static MrAffineTransformation CreateMirror(const MrAxis2 & plane);
	static MrAffineTransformation CreateCoordinateSystemTransformation(const MrAxis2 & destination);
	static MrAffineTransformation CreateCoordinateSystemTransformation(const MrAxis2 & source, const MrAxis2 & destination);

	MrAffineTransformation & operator*=(const MrAffineTransformation & trsf);

	// Constants
	static unsigned int RowSize() {return s_rowSize;}
	static unsigned int ColumnSize() {return s_columnSize;}

private:
	static const unsigned int s_rowSize;
	static const unsigned int s_columnSize;

	MrMatrix _rotation;
	MrVector _translation;
};