// PmViewPersistentNameDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmViewPersistentNameDialog.h"
#include ".\PmViewPersistentNameOperator.h"
#include "PmViewManipulationOperator.h"
#include "PmHSelectionSet.h"
#include "PmView.h"

// PmViewPersistentNameDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmViewPersistentNameDialog, CDialog)
PmViewPersistentNameDialog::PmViewPersistentNameDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: CDialog(PmViewPersistentNameDialog::IDD, pParent)
	, m_pView(pView)
	, m_isFace(TRUE)
	, m_isEdge(FALSE)
	, m_isVertex(FALSE)
{
	m_pOperator = new PmViewPersistentNameOperator(this, m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);
}

PmViewPersistentNameDialog::~PmViewPersistentNameDialog()
{
	OnCancel();
}

void PmViewPersistentNameDialog::OnCancel()
{
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(m_pView->GetHoopsView()->GetSelection());
	pSelection->DeSelectAll();

	DestroyWindow();
	m_pView->SetOperator(new PmViewManipulationOperator(m_pView->GetHView()));
}

void PmViewPersistentNameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIEW_PERSISTENT_NAME_NAME, m_persistentName);
	DDX_Check(pDX, IDC_VIEW_PERSISTENT_NAME_FACE, m_isFace);
	DDX_Check(pDX, IDC_VIEW_PERSISTENT_NAME_EDGE, m_isEdge);
	DDX_Check(pDX, IDC_VIEW_PERSISTENT_NAME_VERTEX, m_isVertex);
}


BEGIN_MESSAGE_MAP(PmViewPersistentNameDialog, CDialog)
	ON_BN_CLICKED(IDC_VIEW_PERSISTENT_NAME_FACE, OnBnClickedViewPersistentNameFace)
	ON_BN_CLICKED(IDC_VIEW_PERSISTENT_NAME_EDGE, OnBnClickedViewPersistentNameEdge)
	ON_BN_CLICKED(IDC_VIEW_PERSISTENT_NAME_VERTEX, OnBnClickedViewPersistentNameVertex)
END_MESSAGE_MAP()


// PmViewPersistentNameDialog 메시지 처리기입니다.

void PmViewPersistentNameDialog::OnBnClickedViewPersistentNameFace()
{
	m_isFace = TRUE;
	m_isEdge = FALSE;
	m_isVertex = FALSE;

	m_pOperator->OnFace();

	UpdateData(FALSE);
}

void PmViewPersistentNameDialog::OnBnClickedViewPersistentNameEdge()
{
	m_isFace = FALSE;
	m_isEdge = TRUE;
	m_isVertex = FALSE;

	m_pOperator->OnEdge();

	UpdateData(FALSE);
}

void PmViewPersistentNameDialog::OnBnClickedViewPersistentNameVertex()
{
	m_isFace = FALSE;
	m_isEdge = FALSE;
	m_isVertex = TRUE;

	m_pOperator->OnVertex();

	UpdateData(FALSE);
}

BOOL PmViewPersistentNameDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	OnBnClickedViewPersistentNameFace();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}