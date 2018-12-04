// TreeCtrlBar.h: interface for the CTreeCtrlBar class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include ".\SizingControlBarG.h"
#include "TreeCtrlEx.h"

class CTreeCtrlBar : public CSizingControlBarG
{
public:
	CTreeCtrlBar();
	virtual ~CTreeCtrlBar();

	BOOL CreateTreeCtrl(DWORD dwStyle, UINT nID);
	CTreeCtrlEx & GetTreeCtrl();

protected:
	CTreeCtrlEx m_treeCtrl;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};