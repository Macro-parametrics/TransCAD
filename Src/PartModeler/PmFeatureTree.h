#pragma once

#include ".\PmMacro.h"
#include ".\SizingControlBar\\TreeCtrlBar.h"

class PmDocument;
class PmFrame;
class PmView;
// PmFeatureTree
struct IPmePartEventListener;

class PM_API PmFeatureTree
	: public CTreeCtrlBar
	, public IPmePartEventListener
{
	DECLARE_DYNAMIC(PmFeatureTree)

public:
	PmFeatureTree();
	virtual ~PmFeatureTree();

	BOOL Create(CString title, UINT barID, UINT treeID, CWnd * parent);

	void Initialize(void);

	PmDocument * GetDocument() const;

	void SetParentFrame(PmFrame * pFrame) {_pFrame = pFrame;}
	PmFrame * GetParentFrame() const {return _pFrame;}

private:
	void AddFeature(PmeUpdateInfoItem item);
	void UpdateFeature(PmeUpdateInfoItem item);

	HTREEITEM FindTreeNode(HTREEITEM hRootNode, PmeHFeature hItem);

public:
	// IPmePartEventListener
	virtual void OnFeaturesUpdated(PmeHUpdateInfo hInfo);
	virtual void OnExplicitModelUpdated(PmeHUpdateInfo hInfo);

private:
	PmFrame * _pFrame;

protected:
	DECLARE_MESSAGE_MAP()
};