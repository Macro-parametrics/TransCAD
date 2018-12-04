// 다음 ifdef 블록은 DLL에서 내보내기하는 작업을 쉽게 해 주는 매크로를 만드는 
// 표준 방식입니다. 이 DLL에 들어 있는 파일은 모두 명령줄에 정의된 _EXPORTS 기호로
// 컴파일되며, 동일한 DLL을 사용하는 다른 프로젝트에서는 이 기호를 정의할 수 없습니다.
// 이렇게 하면 소스 파일에 이 파일이 들어 있는 다른 모든 프로젝트에서는 
// DLLUGPOST_API 함수를 DLL에서 가져오는 것으로 보고, 이 DLL은
// 이 DLL은 해당 매크로로 정의된 기호가 내보내지는 것으로 봅니다.
#ifdef SCRIPTINTERFACE_EXPORTS
#define DLLSCRIPT_API extern "C" __declspec(dllexport)
#else
#define DLLSCRIPT_API extern "C" __declspec(dllimport)
#endif

#include <stdio.h>
#include <tchar.h>

#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>
#include <sstream>
#include <comutil.h>
#include <comdef.h>
#include <stdlib.h>
#include <typeinfo>
#include <assert.h>

#include "StringToken.h"
#include "StringCalc.h"
#include "CMD.h"
#include "Definition.h"
#include "ClearList.h"
#include "Vector.h"
#include "Math.h"
#include "Matrix.h"
#include "File.h"
#include "System.h"
#include "Information.h"

using namespace std;
using namespace CommandType;

extern TransCAD::IApplicationPtr m_spApplication;
extern CommandList Commands;
extern char seps_blank[];

#define VARIABLE_GET_AND_SET_FUNC_IMPL( type, fname, variable )	\
	type Get##fname() { return variable; }	\
	void Set##fname(type p##fname) { variable = p##fname; }

#define VARIABLE_IS_AND_SET_FUNC_IMPL( type, fname, variable )	\
	type Is##fname() { return variable; }	\
	void Set##fname(type p##fname) { variable = p##fname; }

#define LIST_GET_AND_SET_FUNC_IMPL( type, fname, variable )	\
	type Get##fname(int index) { return variable[index]; }	\
	int Get##fname##ListSize(void) { return variable.size(); }	\
	void Set##fname(type p##fname) { variable.push_back(p##fname); }	\
	void Erase##fname(int index) { variable.erase(variable.begin() + index); }

DLLSCRIPT_API int ScriptStartService(void);
DLLSCRIPT_API int ScriptRun(char * command);
DLLSCRIPT_API int ScriptTerminate(void);
