// PmViewHoopsModelTreeDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmViewHoopsModelTreeDialog.h"
#include ".\pmviewhoopsmodeltreedialog.h"
#include ".\PmDocument.h"
#include ".\PmHModel.h"


// PmViewHoopsModelTreeDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmViewHoopsModelTreeDialog, CDialog)

PmViewHoopsModelTreeDialog::PmViewHoopsModelTreeDialog(PmDocument * pDocument, CWnd* pParent /*=NULL*/)
	: CDialog(PmViewHoopsModelTreeDialog::IDD, pParent)
	, m_pDocument(pDocument)
{
}

PmViewHoopsModelTreeDialog::~PmViewHoopsModelTreeDialog()
{
}

void PmViewHoopsModelTreeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIEW_HOOPS_MODEL_TREE_TREE, m_tree);
}


BEGIN_MESSAGE_MAP(PmViewHoopsModelTreeDialog, CDialog)
END_MESSAGE_MAP()


// PmViewHoopsModelTreeDialog 메시지 처리기입니다.

BOOL PmViewHoopsModelTreeDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	HC_KEY hRootKey = m_pDocument->GetHModel()->GetModelKey();

	char segmentName[4096];

	HC_Show_Segment(hRootKey, segmentName);
	AddSegmentToTree(segmentName, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void PmViewHoopsModelTreeDialog::AddSegmentToTree(char * segmentName, HTREEITEM hParent)
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