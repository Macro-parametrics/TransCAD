// TransCADScript.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "TransCADScript.h"
#include "Part.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

Part * pPart = NULL;
TransCAD::IApplicationPtr m_spApplication;
CommandList Commands;
char seps_blank[] = " "; // 띄어쓰기 구분자

DLLSCRIPT_API int ScriptStartService(void)
{
	HRESULT hr = ::CoInitialize(NULL);		
	if(FAILED(hr))
		return 1;

	hr = m_spApplication.CreateInstance(__uuidof(TransCAD::Application));
	if(FAILED(hr))
		return 1;

	// TransCAD 가시화. WebTransCAD 모듈에서는 이 부분 주석처리 필요
	m_spApplication->Visible = VARIANT_TRUE;

	pPart = new Part();

	return 0;
}

DLLSCRIPT_API int ScriptRun(char * command)
{
	if(pPart)
	{
		if (pPart->GetCurrentSketch())				// 스케치 생성 중인 경우
			pPart->OnCreatingSketch(command);
		else if (pPart->GetCurrentReference())		// 다 수의 레퍼런스 선택 중인 경우
			pPart->OnSelectingReferences(command);
		else if (pPart->GetCurrentFeature())			// 다 수의 특징형상 선택 중인 경우
			pPart->OnSelectingFeatures(command);
		else										// 일반적인 경우
			pPart->RunCommands(command);
	}

	return 0;
}

DLLSCRIPT_API int ScriptTerminate(void)
{
	delete pPart;

	::CoUninitialize();

	return 0;
}