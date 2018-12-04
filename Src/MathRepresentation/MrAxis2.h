#pragma once
#include ".\MrMacro.h"
#include ".\MrPosition.h"
#include ".\MrDirection.h"
#include ".\MrAxis1.h"

class MR_API MrAxis2
{
public:
	// Constructors
	MrAxis2(void);
	MrAxis2(const MrPosition & location, const MrDirection & zDirection, const MrDirection & xDirection);
	MrAxis2(const MrPosition & location, const MrDirection & zDirection);

	// Properties
	MrPosition Location(void) const {return _location;}
	MrDirection XDirection(void) const {return _xDirection;}
	MrDirection YDirection(void) const {return _yDirection;}
	MrDirection ZDirection(void) const {return _zDirection;}
	MrAxis1 Axis(void) const {return MrAxis1(_location, _zDirection);}

	void SetLocation(const MrPosition & location);
	void SetXDirection(const MrDirection & xDirection);
	void SetYDirection(const MrDirection & yDirection);
	void SetZDirection(const MrDirection & zDirection);

	// Constants
	static const MrAxis2 & OXY(void) {return s_OXY;}
	static const MrAxis2 & OYZ(void) {return s_OYZ;}
	static const MrAxis2 & OZX(void) {return s_OZX;}

private:
	static const MrAxis2 s_OXY;
	static const MrAxis2 s_OYZ;
	static const MrAxis2 s_OZX;

	MrPosition _location;
	MrDirection _xDirection;
	MrDirection _yDirection;
	MrDirection _zDirection;
};