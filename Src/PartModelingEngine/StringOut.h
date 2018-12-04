#pragma once

#include <ostream>

std::ostream & operator<<(std::ostream & os, CString str)
{
	os << str.GetBuffer();

	return os;
}