#pragma once
#include "TransCADScript.h"

class CMD
{
public:
	static void SetColor(int backcolor, int fontcolor);
	static void Clear(void);
	static void SetTitle(wstring title, int i);
};