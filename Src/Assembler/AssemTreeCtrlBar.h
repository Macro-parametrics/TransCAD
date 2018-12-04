// TreeCtrlBar.h: interface for the CAssemTreeCtrlBar class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "AssemSizingControlBarG.h"
#include "AssemTreeCtrlEx.h"

class CAssemTreeCtrlBar : public CAssemSizingControlBarG
{
public:
	CAssemTreeCtrlBar();
	virtual ~CAssemTreeCtrlBar();

	BOOL CreateTreeCtrl(DWORD dwStyle, UINT nID);
	CAssemTreeCtrlEx & GetTreeCtrl();

protected:
	CAssemTreeCtrlEx m_treeCtrl;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};