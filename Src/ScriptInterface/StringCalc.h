#pragma once
#include "TransCADScript.h"

const string simbols = "(+-*/) ";

class StringCalc
{
public:
	static string GetPostFix(const string infixExpression);
	static double Calculate(const string postfixExpression);
};