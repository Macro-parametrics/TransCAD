// TreeCtrlEx.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "AssemTreeCtrlEx.h"


// TreeCtrlEx
IMPLEMENT_DYNAMIC(CAssemTreeCtrlEx, CTreeCtrl)
CAssemTreeCtrlEx::CAssemTreeCtrlEx()
: m_hItemFirstSel(0)
, m_isRButtonPushed(false)
{
	
}

CAssemTreeCtrlEx::~CAssemTreeCtrlEx()
{
}


BEGIN_MESSAGE_MAP(CAssemTreeCtrlEx, CTreeCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CAssemTreeCtrlEx::OnTvnSelchanged)
END_MESSAGE_MAP()


// CAssemTreeCtrlEx 메시지 처리기입니다.

void CAssemTreeCtrlEx::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		
 	UINT flags;
 	HTREEITEM m_selectedItem = HitTest(point, &flags);
 
 
 	if((flags & TVHT_ONITEMRIGHT) || (flags & TVHT_ONITEMINDENT) || (flags & TVHT_ONITEM))
 	{
 		if(nFlags & MK_CONTROL)
 		{
 			// Control key is down
 			UINT flag;
 			HTREEITEM hItem = HitTest(point, &flag);
 			if(hItem)
 			{
 				// Initialize the reference item if this is the first shift selection
 				m_hItemFirstSel = hItem;
 
 				// Toggle selection state
 				UINT uNewSelState = GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED ? 0 : TVIS_SELECTED;
 				
 				// Get old selected (focus) item and state
 				HTREEITEM hItemOld = GetSelectedItem();
 				UINT uOldSelState  = hItemOld ? GetItemState(hItemOld, TVIS_SELECTED) : 0;
             
 				// Select new item
 				if(GetSelectedItem() == hItem)
 					SelectItem(NULL);		// to prevent edit
 	
 				// Set proper selection (highlight) state for new item
 				SetItemState(hItem, uNewSelState,  TVIS_SELECTED);
 
 				// Restore state of old selected item
 				if (hItemOld && hItemOld != hItem)
 					SetItemState(hItemOld, uOldSelState, TVIS_SELECTED);
 
 				// m_hItemFirstSel = NULL;
 
                 FireMultiSelChanged();
 
 				return;
 			}
 		} 
 		else if(nFlags & MK_SHIFT)
 		{
 			// Shift key is down
 			UINT flag;
 			HTREEITEM hItem = HitTest(point, &flag);
 
 			// Initialize the reference item if this is the first shift selection
 			if(!m_hItemFirstSel)
 				m_hItemFirstSel = GetSelectedItem();
 
 			// Select new item
 			if(GetSelectedItem() == hItem)
 				SelectItem(NULL);			// to prevent edit
 		
 			if(m_hItemFirstSel)
 			{
 				SelectItems(m_hItemFirstSel, hItem);
 				FireMultiSelChanged();
 				return;
 			}
 		}
 		else
 		{
 			// Normal - remove all selection and let default 
 			// handler do the rest
 			ClearSelection();
 			m_hItemFirstSel = NULL;
 
 			SelectItem(m_selectedItem);
 
 			SetItemState(m_selectedItem, 0, TVIS_SELECTED);
 			SetItemState(m_selectedItem, TVIS_SELECTED, TVIS_SELECTED);				
 			
 			HTREEITEM hitem;
 			hitem= GetSelectedItem();
 		
 			FireMultiSelChanged();
 		}
 	}
 	
 	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void CAssemTreeCtrlEx::ClearSelection()
{
	// This can be time consuming for very large trees 
	// and is called every time the user does a normal selection
	// If performance is an issue, it may be better to maintain 
	// a list of selected items
	for(HTREEITEM hItem = GetRootItem(); hItem != NULL; hItem = GetNextItem(hItem))
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			SetItemState(hItem, 0, TVIS_SELECTED);
}

// SelectItems	- Selects items from hItemFrom to hItemTo. Does not
//		- select child item if parent is collapsed. Removes
//		- selection from all other items
// hItemFrom	- item to start selecting from
// hItemTo	- item to end selection at.
BOOL CAssemTreeCtrlEx::SelectItems(HTREEITEM hItemFrom, HTREEITEM hItemTo)
{
	ClearSelection();

	// HTREEITEM hItem = GetParentItem(hItemFrom);

	HTREEITEM hItem = GetRootItem();
	
	// Clear selection upto the first item
	while(hItem && hItem != hItemFrom && hItem != hItemTo)
	{
		hItem = GetNextVisibleItem(hItem);
	}

	if(!hItem)
		return FALSE;	// Item is not visible

	SelectItem(hItemTo);	

	// Rearrange hItemFrom and hItemTo so that hItemFirst is at top
	if(hItem == hItemTo)
	{
		hItemTo = hItemFrom;
		hItemFrom = hItem;
	}

	while(hItem != hItemTo)
	{
		SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);		

		hItem = GetNextVisibleItem(hItem);
	}

	SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);	
	
	return TRUE;
}

void CAssemTreeCtrlEx::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_UP || nChar == VK_DOWN)
	{
		if(GetKeyState(VK_SHIFT) & 0x8000)
		{
			// Initialize the reference item if this is the first shift selection
			if(!m_hItemFirstSel)
			{
				m_hItemFirstSel = GetSelectedItem();
				ClearSelection();
			}

			// Find which item is currently selected
			HTREEITEM hItemPrevSel = GetSelectedItem();

			HTREEITEM hItemNext;
			if(nChar == VK_UP)
				hItemNext = GetPrevVisibleItem(hItemPrevSel);
			else
				hItemNext = GetNextVisibleItem(hItemPrevSel);

			if(hItemNext)
			{
				// Determine if we need to reselect previously selected item
				BOOL bReselect = !(GetItemState(hItemNext, TVIS_SELECTED) & TVIS_SELECTED);

				// Select the next item - this will also deselect the previous item
				SelectItem(hItemNext);

				// Reselect the previously selected item
				if(bReselect)
					SetItemState(hItemPrevSel, TVIS_SELECTED, TVIS_SELECTED);
			}
		
			FireMultiSelChanged();
			return;
		}
		else
		{
			ClearSelection();
			CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
			FireMultiSelChanged();
			return;
		}
	}
	else if(nChar == VK_SPACE)
	{
		m_hItemFirstSel = NULL;
		ClearSelection();
		FireMultiSelChanged();
	}

	CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

HTREEITEM CAssemTreeCtrlEx::GetFirstSelectedItem()
{
	for(HTREEITEM hItem = GetRootItem(); hItem!=NULL; hItem = GetNextItem(hItem))
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			return hItem;

	return NULL;
}

HTREEITEM CAssemTreeCtrlEx::GetNextSelectedItem(HTREEITEM hItem)
{
	for(hItem = GetNextItem(hItem); hItem != NULL; hItem = GetNextItem(hItem)) 
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			return hItem;

	return NULL;
}

HTREEITEM CAssemTreeCtrlEx::GetPrevSelectedItem(HTREEITEM hItem)
{
	for(hItem = GetPrevVisibleItem(hItem); hItem != NULL; hItem = GetPrevVisibleItem(hItem))
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			return hItem;

	return NULL;
}

void CAssemTreeCtrlEx::FireMultiSelChanged()
{
	::SendMessage(GetParent()->m_hWnd, TVN_MULTISELCHANGED, 0, 0);
}

void CAssemTreeCtrlEx::SelectAll()
{
	HTREEITEM oldItem = GetSelectedItem();

	for(HTREEITEM hItem = GetRootItem(); hItem != NULL; hItem = GetNextItem(hItem))
		SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);

	m_hItemFirstSel = NULL;

	SelectItem(oldItem);

	FireMultiSelChanged();
}

void CAssemTreeCtrlEx::DeselectAll()
{
	ClearSelection();
	FireMultiSelChanged();
}

void CAssemTreeCtrlEx::OnKillFocus(CWnd* pNewWnd)
{
	CTreeCtrl::OnKillFocus(pNewWnd);

	HTREEITEM hItem = GetFirstSelectedItem();

	RECT rect;
	while(hItem)
	{
		GetItemRect(hItem, &rect, TRUE);
		InvalidateRect(&rect);
		hItem = GetNextSelectedItem(hItem);
	}
}

void CAssemTreeCtrlEx::OnSetFocus(CWnd* pOldWnd)
{
	CTreeCtrl::OnSetFocus(pOldWnd);

	HTREEITEM hItem = GetFirstSelectedItem();

	RECT rect;
	while(hItem)
	{
		GetItemRect(hItem, &rect, TRUE);
		InvalidateRect(&rect);
		hItem = GetNextSelectedItem(hItem);
	}
}

void CAssemTreeCtrlEx::ShiftSelect(HTREEITEM hItem)
{
	SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);	
	// SelectItem(hItem);
}

void CAssemTreeCtrlEx::OnRButtonDown(UINT nFlags, CPoint point)
{
 	UINT flags;
 	HTREEITEM m_selectedItem = HitTest(point, &flags);
	
 	if((flags & TVHT_ONITEMRIGHT) || (flags & TVHT_ONITEMINDENT) || (flags & TVHT_ONITEM))
 	{
 		// Control key is down
 		UINT flag;
 		HTREEITEM hItem = HitTest(point, &flag);
 		if(hItem)
 		{
 			// 선택된 아이템 위에서 오른쪽 버튼을 눌렀으면
 			if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
 			{
 				// Get old selected (focus) item and state
 				HTREEITEM hItemOld = GetSelectedItem();
 				UINT uOldSelState  = hItemOld ? GetItemState(hItemOld, TVIS_SELECTED) : 0;
 				
 				SelectItem(m_selectedItem);
 				SetItemState(m_selectedItem, 0, TVIS_SELECTED);
 				SetItemState(m_selectedItem, TVIS_SELECTED, TVIS_SELECTED);
 
 				// Restore state of old selected item
 				if (hItemOld && hItemOld != hItem)
 					SetItemState(hItemOld, uOldSelState, TVIS_SELECTED);
 
 				m_isRButtonPushed = true;
 
 				SetFocus();
 
 				return;
 			}
 			else
 			{
 				// Normal - remove all selection and let default 
 				// handler do the rest
 				ClearSelection();
 				m_hItemFirstSel = NULL;
 
 				SelectItem(m_selectedItem);				
 
 				SetItemState(m_selectedItem, 0, TVIS_SELECTED);
 				SetItemState(m_selectedItem, TVIS_SELECTED, TVIS_SELECTED);
 
 				FireMultiSelChanged();
 
 				m_isRButtonPushed = true;
 
 				SetFocus();
 
 				return;
 			}
 		}
 	}

	CTreeCtrl::OnRButtonDown(nFlags, point);
}

void CAssemTreeCtrlEx::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_isRButtonPushed)
	{
		// Context menu
		m_isRButtonPushed = false;		

		// 이벤트를 위임한다.
		//::SendMessage(GetParent()->m_hWnd, TVN_CONTEXTMENU, 0, 0);
		::SendMessage(GetParent()->m_hWnd,WM_RBUTTONDOWN,0,MAKEWORD((int)point.x,(int)point.y));
	}

	//CTreeCtrl::OnRButtonUp(nFlags, point);
}


HTREEITEM CAssemTreeCtrlEx::GetNextItem(HTREEITEM hItem, UINT nCode)
{
	return CTreeCtrl::GetNextItem(hItem, nCode);
}

HTREEITEM CAssemTreeCtrlEx::GetNextItem(HTREEITEM hItem)
{
    HTREEITEM hti = NULL;

    if(ItemHasChildren(hItem))
        hti = GetChildItem(hItem);

    if(hti == NULL)
	{
        while((hti = GetNextSiblingItem(hItem)) == NULL)
		{
            if((hItem = GetParentItem(hItem)) == NULL)
                return NULL;
		}
	}

    return hti;
}

HTREEITEM CAssemTreeCtrlEx::GetPrevItem(HTREEITEM hItem)
{
	HTREEITEM hti;

    hti = GetPrevSiblingItem(hItem);

    if(hti == NULL)
        hti = GetParentItem(hItem);
    else
        hti = GetLastItem(hti);

    return hti;
}

HTREEITEM CAssemTreeCtrlEx::GetLastItem(HTREEITEM hItem)
{
    // Last child of the last child of the last child ...
    HTREEITEM htiNext;

    if(hItem == NULL)
	{
        // Get the last item at the top level
        htiNext = GetRootItem();
        while(htiNext)
		{
            hItem = htiNext;
            htiNext = GetNextSiblingItem(htiNext);
		}
	}

    while(ItemHasChildren(hItem))
	{
        htiNext = GetChildItem(hItem);
        while(htiNext)
		{
            hItem = htiNext;
            htiNext = GetNextSiblingItem(htiNext);
		}
	}

    return hItem;
}


void CAssemTreeCtrlEx::SetName(CString name)
{
	
}

void CAssemTreeCtrlEx::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	::SendMessage(GetParent()->m_hWnd,WM_LBUTTONDOWN,0,0);

	*pResult = 0;
}
