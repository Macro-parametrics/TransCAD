// PmTreeView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmTreeView.h"
#include ".\pmtreeview.h"


// PmTreeView

IMPLEMENT_DYNCREATE(PmTreeView, CTreeView)

PmTreeView::PmTreeView()
{
}

PmTreeView::~PmTreeView()
{
}

BEGIN_MESSAGE_MAP(PmTreeView, CTreeView)
END_MESSAGE_MAP()


// PmTreeView 진단입니다.

#ifdef _DEBUG
void PmTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void PmTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG


// PmTreeView 메시지 처리기입니다.