#pragma once
#include <vector>
using namespace std;

template<class T>
void ClearList(vector<T *> & t)
{
	vector<T *>::iterator i = t.begin();
	while ( i != t.end() )
	{
		delete *i;
		++i;
	}
	t.clear();
}