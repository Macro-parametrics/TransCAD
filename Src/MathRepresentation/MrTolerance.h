#pragma once
#include ".\MrMacro.h"

class MR_API MrTolerance
{
public:
	// Properties
	static double DistanceTolerance() {return s_distanceTolerance;}
	static double AngleTolerance() {return s_angleTolerance;}
	static double ValueTolerance() {return s_valueTolerance;}

	static void SetDistanceTolerance(double tolerance) {s_distanceTolerance = tolerance;}
	static void SetAngleTolerance(double tolerance) {s_angleTolerance = tolerance;}
	static void SetValueTolerance(double tolerance) {s_valueTolerance = tolerance;}

	// Operators
	static bool IsZeroDistance(double distance);
	static bool IsZeroAngle(double angle);
	static bool IsZeroValue(double value);

private:
	static double s_distanceTolerance;
	static double s_angleTolerance;
	static double s_valueTolerance;
};