// TreeCtrlBar.cpp: implementation of the CAssemTreeCtrlBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AssemTreeCtrlBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAssemTreeCtrlBar::CAssemTreeCtrlBar()
{

}

CAssemTreeCtrlBar::~CAssemTreeCtrlBar()
{

}

BEGIN_MESSAGE_MAP(CAssemTreeCtrlBar, CAssemSizingControlBarG)
	//{{AFX_MSG_MAP(CAssemTreeCtrlBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssemTreeCtrlBar message handlers

int CAssemTreeCtrlBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if(CAssemSizingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetSCBStyle(GetSCBStyle() | SCBS_SHOWEDGES | SCBS_SIZECHILD);

	return 0;
}

BOOL CAssemTreeCtrlBar::CreateTreeCtrl(DWORD dwStyle, UINT nID)
{
	if(!m_treeCtrl.Create(dwStyle, CRect(0, 0, 0, 0), this, nID))
		return -1;

	return 0;
}

CAssemTreeCtrlEx & CAssemTreeCtrlBar::GetTreeCtrl()
{
	return m_treeCtrl;
}
