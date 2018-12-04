// AssemFrame.h : AssemFrame 클래스의 인터페이스
//


#pragma once

#include "AssemMacro.h"
#include "AssemFeatureTree.h"

class AssemDocument;
class AssemView;

class ASSEM_API AssemFrame
	: public CMDIChildWnd
{
	DECLARE_DYNCREATE(AssemFrame)
public:
	AssemFrame();

// 특성
public:
	AssemDocument * GetDocument(void);
	AssemView * GetView(void);
	AssemFeatureTree * GetFeatureTree(void) {return &_featureTree;}
private:
	CSplitterWnd m_wndSplitter;
	AssemFeatureTree _featureTree;
	bool _initialUpdate;

// 작업
public:

// 재정의
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현
public:
	virtual ~AssemFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 메시지 맵 함수를 생성했습니다.
protected:
	DECLARE_MESSAGE_MAP()	
public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd);
	virtual void ActivateFrame(int nCmdShow = -1);
};
