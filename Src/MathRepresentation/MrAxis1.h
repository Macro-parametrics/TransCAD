#pragma once
#include ".\MrMacro.h"
#include ".\MrPosition.h"
#include ".\MrDirection.h"

class MR_API MrAxis1
{
public:
	// Constructors
	MrAxis1(void);
	MrAxis1(const MrPosition & location, const MrDirection & direction);

	// Properties
	MrPosition Location(void) const {return _location;}
	MrDirection Direction(void) const {return _direction;}

	void SetLocation(const MrPosition & location);
	void SetDirection(const MrDirection & direction);

	// Constants
	static const MrAxis1 & OX(void) {return s_OX;}
	static const MrAxis1 & OY(void) {return s_OY;}
	static const MrAxis1 & OZ(void) {return s_OZ;}

private:
	static const MrAxis1 s_OX;
	static const MrAxis1 s_OY;
	static const MrAxis1 s_OZ;

	MrPosition _location;
	MrDirection _direction;
};