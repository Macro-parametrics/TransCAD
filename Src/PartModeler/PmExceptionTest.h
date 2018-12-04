#pragma once

template<class T>
void PmThrowExceptionIf(bool condition)
{
	if(condition)
		throw T();
}

template<class T, class P1>
void PmThrowExceptionIf(bool condition, P1 p1)
{
	if(condition)
		throw T(p1);
}

template<class T, class P1, class P2>
void PmThrowExceptionIf(bool condition, P1 p1, P2 p2)
{
	if(condition)
		throw T(p1, p2);
}