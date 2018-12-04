#pragma once
#include "TransCADScript.h"
#include "Part.h"

class Part;

class System
{
public:
	static void InitTransCAD(Part * pPart);
	static void UninitTransCAD(Part * pPart);
	static void TerminateTransCAD(Part * pPart);
	static void RestoreSession(Part * pPart);
	static void Reset(Part * pPart);
	static void Renew(Part * pPart);
};