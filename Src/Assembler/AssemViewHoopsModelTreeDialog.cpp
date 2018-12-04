// AssemViewHoopsModelTreeDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "AssemViewHoopsModelTreeDialog.h"
#include "Assemviewhoopsmodeltreedialog.h"
#include "AssemDocument.h"
#include "AssemHModel.h"


// AssemViewHoopsModelTreeDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(AssemViewHoopsModelTreeDialog, CDialog)

AssemViewHoopsModelTreeDialog::AssemViewHoopsModelTreeDialog(AssemDocument * pDocument, CWnd* pParent /*=NULL*/)
	: CDialog(AssemViewHoopsModelTreeDialog::IDD, pParent)
	, m_pDocument(pDocument)
{
}

AssemViewHoopsModelTreeDialog::~AssemViewHoopsModelTreeDialog()
{
}

void AssemViewHoopsModelTreeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIEW_HOOPS_MODEL_TREE_TREE, m_tree);
}


BEGIN_MESSAGE_MAP(AssemViewHoopsModelTreeDialog, CDialog)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// AssemViewHoopsModelTreeDialog 메시지 처리기입니다.

BOOL AssemViewHoopsModelTreeDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	HC_KEY hRootKey = m_pDocument->GetHModel()->GetModelKey();

	char segmentName[4096];

	HC_Show_Segment(hRootKey, segmentName);
	AddSegmentToTree(segmentName, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void AssemViewHoopsModelTreeDialog::AddSegmentToTree(char * segmentName, HTREEITEM hParent)
{
	char * pos = strrchr(segmentName, '/');
	char * name = (pos + 1);

	HTREEITEM hItem;

	if(hParent)
		hItem = m_tree.InsertItem(name, hParent);
	else
		hItem = m_tree.InsertItem(name);
	
	m_tree.Expand(hParent, TVE_EXPAND);

	char child[4096];

	HC_Open_Segment(segmentName);
		HC_Begin_Segment_Search("*");
		while(HC_Find_Segment(child))
		{
			AddSegmentToTree(child, hItem);				
		}
		HC_End_Segment_Search();
	HC_Close_Segment();	
}