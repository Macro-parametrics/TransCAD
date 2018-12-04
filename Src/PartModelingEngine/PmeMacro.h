#pragma once

// 라이브러리 입출력 기호 정의
#ifdef PME_EXPORTS
#define PME_API __declspec(dllexport)
#else
#define PME_API __declspec(dllimport)
#endif