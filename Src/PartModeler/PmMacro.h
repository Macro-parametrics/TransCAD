#pragma once

// 라이브러리 입출력 기호 정의
#ifdef PM_EXPORTS
#define PM_API __declspec(dllexport)
#else
#define PM_API __declspec(dllimport)
#endif