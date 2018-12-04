#pragma once

#ifdef _DEBUG

#include <crtdbg.h>
#define MR_CHECK_CONDITION(expr) \
		do { if (!(expr) && \
			(1 == _CrtDbgReport(_CRT_ASSERT, _filename, _line, NULL, #expr))) \
             _CrtDbgBreak(); } while (0)

#else

#define MR_CHECK_CONDITION(expr)

#endif

#ifdef _DEBUG

#define MR_BEGIN_CHECK(type) static void _MrDebugCheck(type * _this, const char * _filename, unsigned int _line) {
#define MR_END_CHECK }

#define MR_CHECK() _MrDebugCheck(this, __FILE__, __LINE__);

#else

#define MR_BEGIN_CHECK(type) template<class T> void _MrDebugCheck(type * _this, const char * filename, unsigned int line) {
#define MR_END_CHECK }

#define MR_CHECK()

#endif