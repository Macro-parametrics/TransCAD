#pragma once
#include "TransCADScript.h"
#include "TSIExceptionTest.h"
#include "TSIArgumentException.h"
#include "Part.h"
#include "Feature.h"

class Part;
class Feature;

class Manipulation
{
public:
	static void Modify(char * command, Part * pPart);
	static void UndoFeature(Part * pPart);
	static void RedoFeature(Part * pPart);
	static void RegenerateFeature(int start, int end, int mode, Part * pPart);
	static Feature * BacktraceFeature(Feature * pFeature, int start, int end, Part * pPart);
	static void Delete(char * command, Part * pPart);
	static void DeleteFeature(string name, Part * pPart);
	static void GetDescendants(string name, vector<string> & descendants, Part * pPart);
};