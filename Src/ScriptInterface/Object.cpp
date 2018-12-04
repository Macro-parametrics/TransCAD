#include "stdafx.h"
#include "Object.h"

Object::Object(int type)
{
	SetType(type);
	SetModified(false);
	SetDeleted(false);
}

Object::~Object(void)
{
}

// 입력 변수가 잘못되었는지 판별
bool Object::CheckValid(string token)
{
	bool isValid = false;
	
	if (token != "FAIL")
		isValid = true;

	return isValid;
}