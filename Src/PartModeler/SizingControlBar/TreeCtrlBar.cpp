// TreeCtrlBar.cpp: implementation of the CTreeCtrlBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TreeCtrlBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTreeCtrlBar::CTreeCtrlBar()
{

}

CTreeCtrlBar::~CTreeCtrlBar()
{

}

BEGIN_MESSAGE_MAP(CTreeCtrlBar, CSizingControlBarG)
	//{{AFX_MSG_MAP(CTreeCtrlBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlBar message handlers

int CTreeCtrlBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if(CSizingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetSCBStyle(GetSCBStyle() | SCBS_SHOWEDGES | SCBS_SIZECHILD);

	return 0;
}

BOOL CTreeCtrlBar::CreateTreeCtrl(DWORD dwStyle, UINT nID)
{
	if(!m_treeCtrl.Create(dwStyle, CRect(0, 0, 0, 0), this, nID))
		return -1;

	return 0;
}

CTreeCtrlEx & CTreeCtrlBar::GetTreeCtrl()
{
	return m_treeCtrl;
}