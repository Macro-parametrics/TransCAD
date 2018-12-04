#include "stdafx.h"
#include ".\PmFeatureTree.h"
#include ".\PmeFeature.h"
#include ".\PmFrame.h"
#include ".\PmDocument.h"
#include ".\PmeHandleMacro.h"
#include ".\PmView.h"
#include ".\PmHSelectionSet.h"


IMPLEMENT_DYNAMIC(PmFeatureTree, CTreeCtrlBar)

PmFeatureTree::PmFeatureTree()
: _pFrame(0)
{
}

PmFeatureTree::~PmFeatureTree()
{
}


BEGIN_MESSAGE_MAP(PmFeatureTree, CTreeCtrlBar)
END_MESSAGE_MAP()

// PmFeatureTree 메시지 처리기입니다.

BOOL PmFeatureTree::Create(CString title, UINT barID, UINT treeID, CWnd * parent)
{
	if(!CSizingControlBar::Create(title, parent, barID))
        return FALSE;      // fail to create

	SetBarStyle(GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	CreateTreeCtrl(WS_CHILD | WS_VISIBLE | WS_BORDER | TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS, treeID);
	GetTreeCtrl().ModifyStyleEx(0, WS_EX_CLIENTEDGE);	
	
	return true;
}

void PmFeatureTree::Initialize()
{
	CTreeCtrl & tree = GetTreeCtrl();
	tree.DeleteAllItems();
	tree.InsertItem(TVIF_TEXT | TVIF_PARAM, _T("Part"), -1, -1, -1, -1, (LPARAM)GetDocument()->GetPart(), TVI_ROOT, TVI_LAST);
}

PmDocument * PmFeatureTree::GetDocument() const
{
	PmDocument * pDoc = static_cast<PmDocument *>(GetParentFrame()->GetActiveDocument());

	return pDoc;
}

void PmFeatureTree::OnFeaturesUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnFeaturesUpdated\n"));

	int size;
	PmeUpdateInfoAPI::GetSize(hInfo, size);

	for(int i = 0; i < size; ++ i)
	{
		PmeUpdateInfoItem item;
		PmeUpdateInfoAPI::GetItem(hInfo, i, item);

		switch(item.state)
		{
		case PmeUpdateState_Add:
			AddFeature(item);
			break;
		case PmeUpdateState_Update:
			UpdateFeature(item);
			break;
		case PmeUpdateState_Delete:
			break;
		}
	}
}

void PmFeatureTree::OnExplicitModelUpdated(PmeHUpdateInfo hInfo)
{
	TRACE(_T("OnExplicitModelUpdated\n"));
}

void PmFeatureTree::AddFeature(PmeUpdateInfoItem item)
{
	PmeHFeature hItem = item.hItem;
	
	PmeFeature * pFeature = PME_HANDLE2FEATURE(hItem);

	CString name;
	PmeFeatureAPI::GetName(hItem, name);

	CTreeCtrl & treeCtrl = GetTreeCtrl();

	HTREEITEM hNode = treeCtrl.InsertItem(TVIF_TEXT | TVIF_PARAM, name, -1, -1, -1, -1, (LPARAM)hItem, treeCtrl.GetRootItem(), TVI_LAST);
	treeCtrl.SetItemData(hNode, (DWORD_PTR)pFeature);
	treeCtrl.Expand(treeCtrl.GetRootItem(), TVE_EXPAND);
}

void PmFeatureTree::UpdateFeature(PmeUpdateInfoItem item)
{
	CTreeCtrl & treeCtrl = GetTreeCtrl();
	HTREEITEM hRootNode = treeCtrl.GetRootItem();

	PmeHFeature hItem = item.hItem;

	HTREEITEM hNode = FindTreeNode(hRootNode, hItem);
	
	if(hNode == NULL)
	{
		AddFeature(item);
		return;
	}

	// TODO

	treeCtrl.Expand(treeCtrl.GetRootItem(), TVE_EXPAND);
}

HTREEITEM PmFeatureTree::FindTreeNode(HTREEITEM hRootNode, PmeHFeature hItem)
{
	CTreeCtrl & treeCtrl = GetTreeCtrl();

	PmeHFeature hItemData = (PmeHFeature)treeCtrl.GetItemData(hRootNode);
	if(hItemData && hItemData == hItem)
		return hRootNode;

	if(treeCtrl.ItemHasChildren(hRootNode))
	{
		HTREEITEM hParent = hRootNode;
        HTREEITEM hChildNode = treeCtrl.GetChildItem(hRootNode);

        while(hChildNode != NULL)
		{            
			HTREEITEM hResult = FindTreeNode(hChildNode, hItem);
			if(hResult)
				return hResult;

			hChildNode = treeCtrl.GetNextItem(hChildNode, TVGN_NEXT);
		}
	}

	return NULL;
}
