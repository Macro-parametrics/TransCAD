// TransCAD.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "TransCAD.h"
#include "MainFrame.h"
#include "afxwinappex.h"
#include "afxdialogex.h"

#include "PartFrame.h"
#include "PartDocument.h"
#include "PartView.h"
#include ".\transcad.h"
#include <initguid.h>
#include "TransCAD_i.c"

#include "TCVersion.h"
#include <sdkddkver.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WIN_MAJOR_MAX	    10    // Windows 10
#define WIN_MAJOR_MIN	    5    // Windows 2000 or XP

// TransCADApp


class CTransCADModule :
	public CAtlMfcModule
{
public:
	DECLARE_LIBID(LIBID_TransCAD);
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TRANSCAD, "{102B11C0-2B4A-472D-B4FF-C7035FFAD8FD}");};

CTransCADModule _AtlModule;

BEGIN_MESSAGE_MAP(TransCADApp, CHoopsApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// 표준 파일을 기초로 하는 문서 명령입니다.
	ON_COMMAND(ID_FILE_NEW, CHoopsApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CHoopsApp::OnFileOpen)
	// 표준 인쇄 설정 명령입니다.
	ON_COMMAND(ID_FILE_PRINT_SETUP, CHoopsApp::OnFilePrintSetup)
	ON_COMMAND(ID_SCRIPT_INTERFACE, OnScriptInterface)
END_MESSAGE_MAP()


// TransCADApp 생성

TransCADApp::TransCADApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bHiColorIcons = TRUE;

	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 TransCADApp 개체입니다.

TransCADApp theApp;

// TransCADApp 초기화

BOOL TransCADApp::InitInstance()
{
	if(!InitializeHoops())
		return FALSE;

	if(!InitializeAcis())
		return FALSE;

	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControls()가 필요합니다. 
	// InitCommonControls()를 사용하지 않으면 창을 만들 수 없습니다.
	InitCommonControls();

	CHoopsApp::InitInstance();

	// OLE 라이브러리를 초기화합니다.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));
	LoadStdProfileSettings(4);  // MRU를 포함하여 표준 INI 파일 옵션을 로드합니다.
	// 응용 프로그램의 문서 템플릿을 등록합니다. 문서 템플릿은
	// 문서, 프레임 창 및 뷰 사이의 연결 역할을 합니다.
		
	AddPartModeler();

	AddAssembler();


	// 주 MDI 프레임 창을 만듭니다.
	MainFrame* pMainFrame = new MainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
	// 접미사가 있을 경우에만 DragAcceptFiles를 호출합니다.
	// MDI 응용 프로그램에서는 m_pMainWnd를 설정한 후 바로 이러한 호출이 발생해야 합니다.
	// 표준 셸 명령, DDE, 파일 열기에 대한 명령줄을 구문 분석합니다.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// Register class factories via CoRegisterClassObject().
	if (FAILED(_AtlModule.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE)))
		return FALSE;
	// App was launched with /Embedding or /Automation switch.
	// Run app as automation server.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Don't show the main window
		return TRUE;
	}
	// App was launched with /Unregserver or /Unregister switch.
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		_AtlModule.UpdateRegistryAppId(FALSE);
		_AtlModule.UnregisterServer(TRUE);
		return FALSE;
	}
	// App was launched with /Register or /Regserver switch.
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
	{
		_AtlModule.UpdateRegistryAppId(TRUE);
		_AtlModule.RegisterServer(TRUE);
		return FALSE;
	}
	// 명령줄에 지정된 명령을 디스패치합니다. 응용 프로그램이 /RegServer, /Register, /Unregserver 또는 /Unregister로 시작된 경우 FALSE를 반환합니다.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 주 창이 초기화되었으므로 이를 표시하고 업데이트합니다.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	
	return TRUE;
}



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원

// 구현
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString versionTC;
	CString versionRevision;
	CString releaseDate;
	CString versionWindows;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
	, versionTC(_T(""))
	, versionRevision(_T(""))
	, releaseDate(_T(""))
	//, versionWindows(_T(""))	
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, VersionBuild, versionRevision);
	DDX_Text(pDX, ReleaseDate, releaseDate);
	//DDX_Text(pDX, VersionWindows, versionWindows);
	DDX_Text(pDX, IDC_VERSION, versionTC);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void TransCADApp::OnAppAbout()
{
	CAboutDlg aboutDlg;

	
	// TransCAD version
	aboutDlg.versionTC			= CString(TCMajor) + '.' + CString(TCMinor);
	aboutDlg.versionRevision	= TCRevision;
	aboutDlg.releaseDate		= TCReleaseDate;
	
	aboutDlg.DoModal();
}

void TransCADApp::OnScriptInterface()
{
	STARTUPINFO si;
    PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

	// Start the child process. 
	CreateProcess(NULL,"TransCADScriptInterface.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}



// TransCADApp 메시지 처리기

bool TransCADApp::InitializeHoops(void)
{
#ifdef _DEBUG
	HC_Define_System_Options("no info, no message limit");
#else
	HC_Define_System_Options("no warnings, no info, no errors, no fatal errors, no message limit");
#endif

	// HDB와 CTDriver를 초기화 한다.
	m_pHoopsDB = new HDB;
	m_pHoopsDB->Init();
	//m_pCTDriver must be started after m_pHoopsDB is created
	m_pCTDriver = new CTDriver( 10 );
	m_pCTDriver->StartTimer();

	return true;
}

bool TransCADApp::ReleaseHoops(void)
{
	//m_pCTDriver must be deleted before m_pHoopsDB
	if(m_pCTDriver)
	{
		delete m_pCTDriver;
		m_pCTDriver = 0;
	}

	if(m_pHoopsDB)
	{
		delete m_pHoopsDB;
		m_pHoopsDB = 0;
	}

	return true;
}

bool TransCADApp::InitializeAcis(void)
{
	// ACIS initializer
	if(api_start_modeller(0).ok() == FALSE)
	{
		TRACE(_T("Failed to initialize ACIS.\n"));
		return false;
	}

	if(api_initialize_kernel().ok() == FALSE)
	{
		TRACE(_T("Failed to initialize ACIS Kernel.\n"));
		return false;
	}

	if(api_initialize_hoops_acis_bridge().ok() == FALSE)
	{
		TRACE(_T("Failed to initialize HOOPS_ACIS_Bridge.\n"));
		return false;
	}

	return true;
}

bool TransCADApp::ReleaseAcis(void)
{
	// ACIS uninitializer
	if(api_terminate_hoops_acis_bridge().ok() == FALSE)
	{
		TRACE(_T("Failed to uninitialize HOOPS_ACIS_Bridge.\n"));
		return false;
	}

	if(api_terminate_kernel().ok() == FALSE)
	{
		TRACE(_T("Failed to uninitialize ACIS Kernel.\n"));
		return false;
	}

	if(api_stop_modeller().ok() == FALSE)
	{
		TRACE(_T("Failed to uninitialize ACIS.\n"));
		return false;
	}

	return true;
}

int TransCADApp::ExitInstance()
{
	_AtlModule.RevokeClassObjects();
	if(!ReleaseAcis())
		return FALSE;

	if(!ReleaseHoops())
		return FALSE;

	return CHoopsApp::ExitInstance();
}

