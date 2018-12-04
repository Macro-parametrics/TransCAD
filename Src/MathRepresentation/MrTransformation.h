#pragma once

#include ".\MrMacro.h"
#include ".\MrMatrix.h"
#include ".\MrVector.h"

class MrPosition;
class MrAxis1;
class MrAxis2;

class MR_API MrTransformation
{
public:
	// Constructros
	MrTransformation(void);
	MrTransformation(double scaleFactor, const MrMatrix & rotation, const MrVector & translation);

	// Properties
	double ScaleFactor(void) const {return _scaleFactor;}
	MrMatrix Rotation(void) const {return _rotation;}
	MrVector Translation(void) const {return _translation;}

	void SetScaleFactor(double scaleFactor);
	void SetRotation(const MrMatrix & rotation);
	void SetTranslation(const MrVector & translation);

	double operator()(unsigned int i, unsigned int j) const;

	// Operators
	void Transform(double x, double y, double z, double & nx, double & ny, double & nz) const;
	MrPosition Transform(const MrPosition & p) const;

	static MrTransformation CreateTranslation(const MrVector & displacement);
	static MrTransformation CreateScale(const MrPosition & fixedPoint, double scaleFactor);
	static MrTransformation CreateScale(double scaleFactor);
	static MrTransformation CreateRotation(const MrAxis1 & axis, double angle);
	static MrTransformation CreateMirror(const MrPosition & center);
	static MrTransformation CreateMirror(const MrAxis1 & axis);
	static MrTransformation CreateMirror(const MrAxis2 & plane);
	static MrTransformation CreateCoordinateSystemTransformation(const MrAxis2 & destination);
	static MrTransformation CreateCoordinateSystemTransformation(const MrAxis2 & source, const MrAxis2 & destination);

	MrTransformation & operator*=(const MrTransformation & trsf);

	// Constants
	static unsigned int RowSize() {return _rowSize;}
	static unsigned int ColumnSize() {return _columnSize;}

private:
	static const unsigned int _rowSize;
	static const unsigned int _columnSize;

	double _scaleFactor;
	MrMatrix _rotation;
	MrVector _translation;
};