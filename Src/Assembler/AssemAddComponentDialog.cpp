// AssemAddComponentDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "AssemAddComponentDialog.h"

#include ".\AssemDocument.h"
#include ".\AssemView.h"
#include ".\AssemHView.h"
#include ".\PmeAssembly.h"

// AssemAddComponentDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC( AssemAddComponentDialog, CDialog )

AssemAddComponentDialog::AssemAddComponentDialog( AssemDocument * pDoc, CWnd* pParent /*=NULL*/ )
	: CDialog(AssemAddComponentDialog::IDD, pParent)
	, m_pDoc( pDoc )
{
	m_hAssembly = m_pDoc->GetAssembly();
}

AssemAddComponentDialog::~AssemAddComponentDialog()
{
}

void AssemAddComponentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control( pDX, IDC_COMPONENT_NAME, m_compName );
}


BEGIN_MESSAGE_MAP(AssemAddComponentDialog, CDialog)
	ON_BN_CLICKED(IDOK, &AssemAddComponentDialog::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL AssemAddComponentDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_compName.SetWindowTextA( m_pDoc->GetComponentName() );
	m_compName.SetFocus();

	// Dialog의 위치 지정
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
	
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return false;
}

void AssemAddComponentDialog::OnBnClickedOk()
{
	CDialog::OnOK();

	PmeHComponent hComp = 0;
	CString _compName;
	m_compName.GetWindowTextA( _compName );

	PmeComponentAPI::Create( hComp );
	PmeComponentAPI::SetName( hComp, _compName );

	PmeAssemblyAPI::AddComponent( m_hAssembly, hComp );	
}
