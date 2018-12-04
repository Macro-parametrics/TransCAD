//#include "TreeCtrlEx.h"
// TreeCtrlEx.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TreeCtrlEx.h"
#include "..\PmView.h"
#include "..\PmDocument.h"
#include "..\PmHSelectionSet.h"
#include "..\..\PartModelingEngine\PmeFeature.h"
#include "..\PmFrame.h"
#include "..\PmCreateChamferDialog.h"
#include "..\PmCreateEdgeFilletDialog.h"
#include "..\PmCreateShellDialog.h"
#include "..\PmCreateOffsetDialog.h"
#include "..\PmCreateDraftDialog.h"
#include "..\PmCreateExtrudeDialog.h"
#include "..\PmCreateRevolveDialog.h"
#include "..\PmCreateSweepDialog.h"
#include "..\PmCreateHoleDialog.h"
#include "..\PmCreatePatternRectangularDialog.h"
#include "..\PmCreatePatternCircularDialog.h"
#include "..\PmCreateDatumPlaneOffsetDialog.h"

// TreeCtrlEx

IMPLEMENT_DYNAMIC(CTreeCtrlEx, CTreeCtrl)
CTreeCtrlEx::CTreeCtrlEx()
: m_hItemFirstSel(0)
, m_isRButtonPushed(false)
{
}

CTreeCtrlEx::~CTreeCtrlEx()
{
}


BEGIN_MESSAGE_MAP(CTreeCtrlEx, CTreeCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CTreeCtrlEx::OnTvnSelchanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CTreeCtrlEx::OnNMDblclk)
	ON_BN_CLICKED(ID_MODIFY_FEATURE, ModifyFeature)
	ON_BN_CLICKED(ID_DELETE_FEATURE, DeleteFeature)
END_MESSAGE_MAP()


// CTreeCtrlEx 메시지 처리기입니다.

void CTreeCtrlEx::OnLButtonDown(UINT nFlags, CPoint point)
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

			FireMultiSelChanged();
		}
	}
	
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void CTreeCtrlEx::ClearSelection()
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
BOOL CTreeCtrlEx::SelectItems(HTREEITEM hItemFrom, HTREEITEM hItemTo)
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

void CTreeCtrlEx::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
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

HTREEITEM CTreeCtrlEx::GetFirstSelectedItem()
{
	for(HTREEITEM hItem = GetRootItem(); hItem!=NULL; hItem = GetNextItem(hItem))
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			return hItem;

	return NULL;
}

HTREEITEM CTreeCtrlEx::GetNextSelectedItem(HTREEITEM hItem)
{
	for(hItem = GetNextItem(hItem); hItem != NULL; hItem = GetNextItem(hItem)) 
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			return hItem;

	return NULL;
}

HTREEITEM CTreeCtrlEx::GetPrevSelectedItem(HTREEITEM hItem)
{
	for(hItem = GetPrevVisibleItem(hItem); hItem != NULL; hItem = GetPrevVisibleItem(hItem))
		if(GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
			return hItem;

	return NULL;
}

void CTreeCtrlEx::FireMultiSelChanged()
{
	::SendMessage(GetParent()->m_hWnd, TVN_MULTISELCHANGED, 0, 0);
}

void CTreeCtrlEx::SelectAll()
{
	HTREEITEM oldItem = GetSelectedItem();

	for(HTREEITEM hItem = GetRootItem(); hItem != NULL; hItem = GetNextItem(hItem))
		SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);

	m_hItemFirstSel = NULL;

	SelectItem(oldItem);

	FireMultiSelChanged();
}

void CTreeCtrlEx::DeselectAll()
{
	ClearSelection();
	FireMultiSelChanged();
}

void CTreeCtrlEx::OnKillFocus(CWnd* pNewWnd)
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

void CTreeCtrlEx::OnSetFocus(CWnd* pOldWnd)
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

void CTreeCtrlEx::ShiftSelect(HTREEITEM hItem)
{
	SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);	
	// SelectItem(hItem);
}

void CTreeCtrlEx::OnRButtonDown(UINT nFlags, CPoint point)
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

void CTreeCtrlEx::OnRButtonUp(UINT nFlags, CPoint point)
{
	// 컨텍스트 메뉴 생성
	CMenu m_ContextMenu;

	m_ContextMenu.CreatePopupMenu();
	m_ContextMenu.AppendMenu(MF_STRING, ID_MODIFY_FEATURE, (LPCTSTR)_T("수정"));
	m_ContextMenu.AppendMenu(MF_STRING, ID_DELETE_FEATURE, (LPCTSTR)_T("제거"));
	CPoint pos;
	GetCursorPos(&pos);
 
	// 마우스 위치에 팝업메뉴를 출력한다.
	m_ContextMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pos.x, pos.y, this);
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_isRButtonPushed)
	{
		// Context menu
		m_isRButtonPushed = false;		

		// 이벤트를 위임한다.
		::SendMessage(GetParent()->m_hWnd, TVN_CONTEXTMENU, 0, 0);
	}

	CTreeCtrl::OnRButtonUp(nFlags, point);
}

HTREEITEM CTreeCtrlEx::GetNextItem(HTREEITEM hItem, UINT nCode)
{
	return CTreeCtrl::GetNextItem(hItem, nCode);
}

HTREEITEM CTreeCtrlEx::GetNextItem(HTREEITEM hItem)
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

HTREEITEM CTreeCtrlEx::GetPrevItem(HTREEITEM hItem)
{
	HTREEITEM hti;

    hti = GetPrevSiblingItem(hItem);

    if(hti == NULL)
        hti = GetParentItem(hItem);
    else
        hti = GetLastItem(hti);

    return hti;
}

HTREEITEM CTreeCtrlEx::GetLastItem(HTREEITEM hItem)
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


// 특징형상 하이라이트
void CTreeCtrlEx::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
	CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
	PmView * pView = static_cast<PmView *>(pChild->GetActiveView());

	if(pView)
	{
		PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pView->GetHoopsView()->GetSelection());

  		TVITEM newItem = pNMTreeView->itemNew;
  		TVITEM oldItem = pNMTreeView->itemOld;

		// 파트인 경우 건너 뜀
		if (GetItemText(newItem.hItem) == _T("Part"))
		{
			pSelection->DeSelectAll();
			pView->GetHoopsView()->Update();
			return;
		}

		PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(newItem.lParam);
		PmeFeature * pOldFeature = reinterpret_cast<PmeFeature *>(oldItem.lParam);

		if(!pFeature)
		{
			pSelection->DeSelectAll();
			pView->GetHoopsView()->Update();
			return;
		}
		
 		pSelection->DeSelectAll();
		pView->SelectFeature(pFeature);

		pView->GetHoopsView()->Update();
	}

	*pResult = 0;
}

// 특징형상 수정 (더블 클릭)
void CTreeCtrlEx::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 더블 클릭 시 수정 창 띄우기
	ModifyFeature();

	*pResult = 0;
}

// 특징형상 수정 (우 클릭 메뉴)
void CTreeCtrlEx::ModifyFeature()
{
	CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
	CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
	PmView * pView = static_cast<PmView *>(pChild->GetActiveView());
	PmFrame * pmFrame = (PmFrame *)pChild;
	
	HTREEITEM item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetSelectedItem();
	
	if (item && GetItemText(item) != _T("Part"))
	{
		PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemData(item));
		
		// 특징형상 다이얼로그 띄우기
		pView->CreateFeatureDialog(pFeature->GetFeatureType());
		
		// 파라메터 설정
		if (pView->GetFeatureDialog())
			pView->GetFeatureDialog()->SetParameters(pFeature);

		// 특징형상 하이라이트
		pView->SelectFeature(pFeature);
	}
}

// 특징형상 제거 (우 클릭 메뉴)
void CTreeCtrlEx::DeleteFeature()
{
	CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
	CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
	PmView * pView = static_cast<PmView *>(pChild->GetActiveView());
	PmFrame * pmFrame = (PmFrame *)pChild;

	HTREEITEM item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetSelectedItem();
	
	if (item && GetItemText(item) != _T("Part"))
	{
		PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemData(item));
		
		if (pFeature)
		{
			// 좌표평면은 건너 뜀
			if (pFeature->GetFeatureType() == PmeFeatureType_StdDefaultDatumPlaneFeature)
				return;
			
			/// 자식 특징형상이 있는 경우 삭제할 수 없음
			int count = 0;

			for (int i = 0; i < (int)pFeature->GetPart()->GetFeatures()->GetSize(); ++i)
			{
				for (int j = 0; j < pFeature->GetPart()->GetFeatures()->GetItem(i)->GetParentNameListSize(); ++j)
				{
					if (pFeature->GetPart()->GetFeatures()->GetItem(i)->GetParentName(j) == pFeature->GetName())
						count++;
				}
			}

			if (count > 0)
			{
				AfxMessageBox(_T("This feature cannot be deleted."));
				return;
			}
			///

			// 특징형상 삭제
			for (int i = 0; i < (int)pFeature->GetPart()->GetFeatures()->GetSize(); ++i)
			{
				if (pFeature->GetPart()->GetFeatures()->GetItem(i)->GetName() == pFeature->GetName())
					pFeature->GetPart()->GetFeatures()->Delete(i);
			}

			pView->GetDocument()->UpdateAll();
		}
	}
}
