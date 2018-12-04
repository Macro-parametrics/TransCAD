#pragma once
#include "TransCADScript.h"
#include "TSIExceptionTest.h"
#include "TSIArgumentException.h"
#include "Part.h"

class Part;

class Information
{
public:
	static void Ask(char * command, Part * pPart);
	static void Parent(char * command, Part * pPart);
	static void Children(char * command, Part * pPart);
	static void GetChildren(string parentName, int parentDepth, Part * pPart);
	static void Highlight(char * command, Part * pPart);
};