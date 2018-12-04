#pragma once

#include ".\MrMacro.h"

class MrString;

template<class T>
void MrThrowExceptionIf(bool condition)
{
	if(condition)
		throw T();
}

template<class T, class P1>
void MrThrowExceptionIf(bool condition, P1 p1)
{
	if(condition)
		throw T(p1);
}

template<class T, class P1, class P2>
void MrThrowExceptionIf(bool condition, P1 p1, P2 p2)
{
	if(condition)
		throw T(p1, p2);
}