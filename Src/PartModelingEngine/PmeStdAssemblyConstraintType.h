#pragma once

enum PmeStdAssemblyConstraintType
{
	PmeStdAssemblyConstraintType_Coaxial,
	PmeStdAssemblyConstraintType_Incidence,
	PmeStdAssemblyConstraintType_Perpendicular,
	PmeStdAssemblyConstraintType_Parallel,
	PmeStdAssemblyConstraintType_Distance,
	PmeStdAssemblyConstraintType_Angle
};

enum PmeStdAssemblyIncidenceType
{
	PmeStdAssemblyIncidenceType_Opposite,	// In NX, Oppsite is touch
	PmeStdAssemblyIncidenceType_Same		// In NX, Same is align
};

enum PmeStdAssemblyPartType
{
	PmeStdAssemblyPartType_Constrained,
	PmeStdAssemblyPartType_Reference
};