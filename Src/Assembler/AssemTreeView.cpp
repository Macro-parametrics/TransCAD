// AssemTreeView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "AssemTreeView.h"
#include ".\Assemtreeview.h"


// AssemTreeView

IMPLEMENT_DYNCREATE(AssemTreeView, CTreeView)

AssemTreeView::AssemTreeView()
{
}

AssemTreeView::~AssemTreeView()
{
}

BEGIN_MESSAGE_MAP(AssemTreeView, CTreeView)
END_MESSAGE_MAP()


// AssemTreeView 진단입니다.

#ifdef _DEBUG
void AssemTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void AssemTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG