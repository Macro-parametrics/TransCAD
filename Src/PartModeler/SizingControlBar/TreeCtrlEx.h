#pragma once

#define TVN_MULTISELCHANGED WM_USER + 1
#define TVN_CONTEXTMENU WM_USER + 2

// CTreeCtrlEx
class PmView;

class CTreeCtrlEx : public CTreeCtrl
{
	DECLARE_DYNAMIC(CTreeCtrlEx)

public:
	CTreeCtrlEx();
	virtual ~CTreeCtrlEx();

	void ShiftSelect(HTREEITEM hItem);

	void SelectAll();
	void DeselectAll();
	void ClearSelection();

	HTREEITEM GetFirstSelectedItem();
	HTREEITEM GetNextSelectedItem(HTREEITEM hItem);
	HTREEITEM GetPrevSelectedItem(HTREEITEM hItem);

	HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode);
	HTREEITEM GetNextItem(HTREEITEM hItem);
	HTREEITEM GetPrevItem(HTREEITEM hItem);
	HTREEITEM GetLastItem(HTREEITEM hItem);

	void ModifyFeature();
	void DeleteFeature();

protected:	
	BOOL SelectItems(HTREEITEM hItemFrom, HTREEITEM hItemTo);
	void FireMultiSelChanged();

protected:
	HTREEITEM m_hItemFirstSel;		// Init to NULL in constructor	
	bool m_isRButtonPushed;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};