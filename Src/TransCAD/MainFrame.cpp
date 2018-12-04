// MainFrame.cpp : MainFrame 클래스의 구현
//

#include "stdafx.h"
#include "TransCAD.h"

#include "MainFrame.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <Tlhelp32.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MainFrame

IMPLEMENT_DYNAMIC(MainFrame, CHoopsFrame)

BEGIN_MESSAGE_MAP(MainFrame, CHoopsFrame)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// MainFrame 생성/소멸

MainFrame::MainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

MainFrame::~MainFrame()
{
	// TransCAD를 작업관리자에서 찾아서 종료하는 부분

	DWORD dwSize = 250;
	HANDLE hSnapShot;
	PROCESSENTRY32 pEntry;
	BOOL bCrrent=FALSE;
	
	hSnapShot=CreateToolhelp32Snapshot(TH32CS_SNAPALL,NULL);

	pEntry.dwSize =sizeof(pEntry);
	// 실행중인 프로세스들의 첫번재 정보를 가져온다.
	Process32First (hSnapShot,&pEntry);

	// Tool이 실행중인지 확인
	while(1)
	{
		// 다음번 프로세스의 정보를 가져온다.
		BOOL hRes=Process32Next (hSnapShot,&pEntry);

		if(hRes == FALSE)
			break;        
		if(!strncmp(pEntry.szExeFile,"TransCAD.exe",15))
		{
			bCrrent = TRUE;
		}
		if(bCrrent)
		{
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pEntry.th32ProcessID);
			if(hProcess)
			{
				if(TerminateProcess(hProcess, 0))
				{
					unsigned long nCode; //프로세스 종료 상태
					GetExitCodeProcess(hProcess, &nCode);
				}
				CloseHandle(hProcess);
			}
			break;
		} 
	}
	//
}


int MainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CHoopsFrame::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL MainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CHoopsFrame::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}


// MainFrame 진단

#ifdef _DEBUG
void MainFrame::AssertValid() const
{
	CHoopsFrame::AssertValid();
}

void MainFrame::Dump(CDumpContext& dc) const
{
	CHoopsFrame::Dump(dc);
}

#endif //_DEBUG


// MainFrame 메시지 처리기

