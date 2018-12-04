#include "stdafx.h"
#include "System.h"
#include "Feature.h"
#include "Manipulation.h"

// TransCAD 활성화 (COM 시작)
void System::InitTransCAD(Part * pPart)
{
	HRESULT hr = ::CoInitialize(NULL);
	hr = m_spApplication.CreateInstance(__uuidof(TransCAD::Application));
	m_spApplication->Visible = VARIANT_TRUE;

	pPart->SetDocsPtr(m_spApplication->GetDocuments());
	pPart->SetPartDocumentPtr(pPart->GetDocsPtr()->AddPartDocument());
	pPart->SetPartPtr(pPart->GetPartDocumentPtr()->GetPart());
	pPart->SetFeaturesPtr(pPart->GetPartPtr()->GetFeatures());
	
	pPart->SetCurrentState(0);
}

// TransCAD 비활성화 (COM 종료)
void System::UninitTransCAD(Part * pPart)
{
	// Clear TransCAD
	m_spApplication = NULL;
	pPart->SetDocsPtr(NULL);
	pPart->SetPartDocumentPtr(NULL);
	pPart->SetPartPtr(NULL);
	pPart->SetFeaturesPtr(NULL);
	
	// COM Automation API Uninitialization
	::CoUninitialize();
}

// TransCAD 종료
void System::TerminateTransCAD(Part * pPart)
{
	UninitTransCAD(pPart);
	
	DWORD dwSize = 250;
	HANDLE hSnapShot;
	PROCESSENTRY32 pEntry;
	BOOL bCrrent = FALSE;

	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL,NULL);
	pEntry.dwSize = sizeof(pEntry);

	// 실행중인 프로세스들의 첫번재 정보를 가져온다.
	Process32First (hSnapShot,&pEntry);

	// Tool이 실행중인지 확인
	while(1)
	{
		// 다음번 프로세스의 정보를 가져온다.
		BOOL hRes = Process32Next(hSnapShot, &pEntry);
		char file[256];

		WideCharToMultiByte(CP_ACP, 0, pEntry.szExeFile, -1, file, 256, NULL, NULL);

		if (hRes == FALSE)
			break;
		
		if (!strncmp(file, "TransCAD.exe",15))
		{
			bCrrent = TRUE;
		}
		
		if (bCrrent)
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pEntry.th32ProcessID);
			if (hProcess)
			{
				if (TerminateProcess(hProcess, 0))
				{
					unsigned long nCode; //프로세스 종료 상태
					GetExitCodeProcess(hProcess, &nCode);
				}
				CloseHandle(hProcess);
			}
			break;
		}
	}
}

// 종료되기 이전 세션 특징형상들을 복구하는 함수
void System::RestoreSession(Part * pPart)
{
	TransCAD::IDoc * _result = 0;
	HRESULT _hr = m_spApplication->get_ActiveDocument(&_result);
				
	// TransCAD가 꺼졌을 경우에만 실행
	if (SUCCEEDED(_hr) && pPart->GetPartDocumentPtr() != NULL)
		return;

	InitTransCAD(pPart);

	pPart->SetCurrentState(pPart->GetHistoryFeatureListSize() - pPart->GetUndoCount() + pPart->GetRedoCount());

	pPart->Clear();

	for (int i = 0; i < pPart->GetCurrentState(); ++i)
	{
		CMD::SetTitle(TEXT("Restoring features"), i);
		
		Feature * pFeature = 0;

		// 생성 된 경우
		if (!pPart->GetHistoryFeature(i)->IsModified() && !pPart->GetHistoryFeature(i)->IsDeleted())
		{
			pFeature = Manipulation::BacktraceFeature(pPart->GetHistoryFeature(i), 0, pPart->GetCurrentState() - 1, pPart);

			if (pFeature)
			{
				pFeature->Restore();
				pFeature->Create();
				pFeature->SetDeleted(false);
				pFeature->SetModified(false);
				pPart->SetFeature(pFeature);
			}
		}
	}

	pPart->SetRestored(true);
}

// 설정을 초기화하고 새로운 모델 정보를 불러오는 함수
void System::Reset(Part * pPart)
{
	pPart->SetUpdateCount(0);
	pPart->SetUndoCount(0);
	pPart->SetRedoCount(0);
	pPart->SetInitialState(0);
	pPart->SetCurrentState(0);
	pPart->SetRestored(false);
		
	pPart->AddInfo();
}

// 매 명령어마다 정보를 갱신하는 함수
void System::Renew(Part * pPart)
{
	TransCAD::IDoc * _result = 0;
	HRESULT hr = m_spApplication->get_ActiveDocument(&_result);
	
	if (FAILED(hr)) // 활성 문서가 없는 경우
	{
		TSIThrowExceptionIf<TSIArgumentException>(FAILED(hr), "Run TransCAD first!");
	}
	else			// 활성 문서가 있는 경우
	{
		pPart->SetPartDocumentPtr(m_spApplication->GetActiveDocument());

		// TransCAD가 백그라운드에만 실행되어 있는 경우. 즉, 종료 된 경우
		if (pPart->GetPartDocumentPtr() == NULL)
			return;
		else
		{
			pPart->SetPartPtr(pPart->GetPartDocumentPtr()->GetPart());	// Set TransCAD Part Ptr
			pPart->SetFeaturesPtr(pPart->GetPartPtr()->GetFeatures());	// Set TransCAD Features Ptr
			
			string m_currenttitle = _bstr_t(pPart->GetPartDocumentPtr()->GetTitle());

			if (pPart->GetRestored()) // 복구 된 경우
			{
				// 현재 문서의 타이틀을 초기 타이틀로 설정
				pPart->SetInitialTitle(m_currenttitle);
			}
			else
			{
				// Part 문서가 새로 생성 되었을 때 모델 정보 리셋
				// Part 문서의 제목이 변경되었는지 체크
				if (pPart->GetInitialTitle() != m_currenttitle)
				{
					Reset(pPart);
					pPart->SetInitialTitle(m_currenttitle);
				}
			}

			// 순서 리셋
			for (int i = 0; i < pPart->GetFeatureListSize(); ++i)
				pPart->GetFeature(i)->SetOrder(i);
			
			// 모델이 로딩이 되어있지 않은 경우
			if (pPart->GetCurrentState() == 0 && pPart->GetUpdateCount() == 0)
				Reset(pPart);

			pPart->SetRestored(false);
		}
	}
}