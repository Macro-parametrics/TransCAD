#include <cmath>
#include <limits>
#include ".\MrTolerance.h"

double MrTolerance::s_distanceTolerance = 1.0e-7;
double MrTolerance::s_angleTolerance = 1.0e-10;
double MrTolerance::s_valueTolerance = std::numeric_limits<double>::epsilon() * 1.0e1;

bool MrTolerance::IsZeroDistance(double distance)
{
	return std::abs(distance) < std::abs(s_distanceTolerance);
}

bool MrTolerance::IsZeroAngle(double angle)
{
	return std::abs(angle) < std::abs(s_angleTolerance);
}

bool MrTolerance::IsZeroValue(double value)
{
	return std::abs(value) < std::abs(s_valueTolerance);
}