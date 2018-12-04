#pragma once

// 라이브러리 입출력 기호 정의
#ifdef MR_EXPORTS
#define MR_API __declspec(dllexport)
#else
#define MR_API __declspec(dllimport)
#endif