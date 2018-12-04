#pragma once
#include "TransCADScript.h"

class StringToken
{
public:
	static string StringToken::GetString(char * buffer, const char * separater, char *& command);
};