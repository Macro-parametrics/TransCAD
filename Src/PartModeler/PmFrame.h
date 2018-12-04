// PmFrame.h : PmFrame 클래스의 인터페이스
//


#pragma once

#include ".\PmMacro.h"
#include ".\PmFeatureTree.h"

class PmDocument;
class PmView;

class PM_API PmFrame
	: public CMDIChildWnd
{
	DECLARE_DYNCREATE(PmFrame)
public:
	PmFrame();

// 특성
public:
	PmDocument * GetDocument(void);
	PmView * GetView(void);
	PmFeatureTree * GetFeatureTree(void) {return & _featureTree;}

private:
	CSplitterWnd m_wndSplitter;
	PmFeatureTree _featureTree;
	bool _initialUpdate;
	int _updateCount;

// 작업

public:
// 재정의
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현
public:
	virtual ~PmFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()

	CToolBar    m_wndToolBar;

public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd);
	virtual void ActivateFrame(int nCmdShow = -1);
};
