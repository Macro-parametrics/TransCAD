#pragma once
#include "TransCADScript.h"
#include "TSIExceptionTest.h"
#include "TSIArgumentException.h"
#include "Part.h"

class Part;

class File
{
public:
	static void Import(char * command, Part * pPart);
	static void Export(char * command, Part * pPart);
	static void ConvertMesh(char * command, Part * pPart);
};