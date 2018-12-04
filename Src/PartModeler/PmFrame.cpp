// PmFrame.cpp : PmFrame 클래스의 구현
//
#include "stdafx.h"
#include ".\Resource.h"
#include ".\PmFrame.h"
#include ".\PmView.h"
#include ".\PmDocument.h"
//#include ".\PmFeatureTree.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// PmFrame

IMPLEMENT_DYNCREATE(PmFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(PmFrame, CMDIChildWnd)
	ON_WM_CREATE()
	ON_WM_MDIACTIVATE()
END_MESSAGE_MAP()

// PmFrame 생성/소멸

PmFrame::PmFrame()
: _initialUpdate(false)
{
	_updateCount = 0;
}

PmFrame::~PmFrame()
{
	
}


BOOL PmFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서 Window 클래스 또는 스타일을 수정합니다.
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// PmFrame 진단

#ifdef _DEBUG
void PmFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void PmFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// PmFrame 메시지 처리기

BOOL PmFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	CPushRoutingFrame push(this);

	// pump through current view FIRST
	CView * pActiveView = GetActiveView();
	if (pActiveView != NULL && pActiveView->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	CDocument * pDoc = GetActiveDocument();
	if(pDoc)
	{
		POSITION pos = pDoc->GetFirstViewPosition();
		while(pos != NULL)
		{
			CView * pView = pDoc->GetNextView(pos);
			if(pView != NULL && pView != pActiveView && pView->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
				return TRUE;
		}
	}

	// then pump through frame
	if (CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// last but not least, pump through app
	CWinApp* pApp = AfxGetApp();
	if (pApp != NULL && pApp->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	return FALSE;
	// return CMDIChildWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

int PmFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 트리를 만든다.
	CString featureTreeTitle;
	featureTreeTitle.LoadString(IDS_PM_FEATURE_TREE_TITLE);

	if(!_featureTree.Create(featureTreeTitle, IDC_FEATURE_TREE_BAR, IDC_FEATURE_TREE_CTRL, this))
	{
		TRACE0("피쳐 트리를 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	_featureTree.SetParentFrame(this);

	EnableDocking(CBRS_ALIGN_ANY);

	_featureTree.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&_featureTree, AFX_IDW_DOCKBAR_LEFT);
	
	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
	//	| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(IDR_MANIPULATION_TOOLBAR))
	//{
	//	TRACE0("도구 모음을 만들지 못했습니다.\n");
	//	return -1;      // 만들지 못했습니다.
	//}

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	return 0;
}

void PmFrame::OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd)
{
	CMDIChildWnd::OnMDIActivate(bActivate, pActivateWnd, pDeactivateWnd);
}

PmDocument * PmFrame::GetDocument(void)
{
	PmDocument * pDoc = static_cast<PmDocument *>(GetActiveDocument());

	return pDoc;
}

PmView * PmFrame::GetView(void)
{
	PmView * pView = static_cast<PmView *>(GetActiveView());

	return pView;
}

void PmFrame::ActivateFrame(int nCmdShow)
{
	
	if(!_initialUpdate )
	{
		_initialUpdate = true;
		
		PmeHPart hPart = GetDocument()->GetPart();

		PmePartAPI::RegisterEventListener(hPart, &_featureTree);

// 		CString strName;
// 		PmePartAPI::GetName(hPart,strName);
		_featureTree.Initialize();
		
		//GetDocument()->DeleteContents();
		GetDocument()->UpdateAll();
		//_updateCount++;
	}

	CMDIChildWnd::ActivateFrame(SW_SHOWMAXIMIZED);
}
