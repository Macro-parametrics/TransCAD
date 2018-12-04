// PartFrame.cpp : PartFrame 클래스의 구현
//
#include "stdafx.h"
#include "TransCAD.h"

#include "PartFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// PartFrame

IMPLEMENT_DYNCREATE(PartFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(PartFrame, CMDIChildWnd)
END_MESSAGE_MAP()


// PartFrame 생성/소멸

PartFrame::PartFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

PartFrame::~PartFrame()
{
}


BOOL PartFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서 Window 클래스 또는 스타일을 수정합니다.
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// PartFrame 진단

#ifdef _DEBUG
void PartFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void PartFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// PartFrame 메시지 처리기
