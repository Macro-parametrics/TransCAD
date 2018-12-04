// AssemApplyParallelDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "AssemApplyParallelDialog.h"
#include "..\PartModelingEngine\PmeStdAssemblyParallelAPI.h"

#include ".\AssemView.h"

#include ".\AssemHSelectionSet.h"
#include ".\AssemViewPersistentNameOperator.h"


// AssemApplyParallelDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC( AssemApplyParallelDialog, AssemApplyConstraintDialog )

AssemApplyParallelDialog::AssemApplyParallelDialog( AssemView * pView, CWnd* pParent /*=NULL*/ )
	: AssemApplyConstraintDialog( pView )
{
	m_selectPart = 0;
}

AssemApplyParallelDialog::~AssemApplyParallelDialog()
{
}

void AssemApplyParallelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control( pDX, IDC_CONSTRAINT_NAME, m_constraintName );
	DDX_Control( pDX, IDC_CONSTRAINED_COMP_NAME, m_constrainedCompName );
	DDX_Control( pDX, IDC_CONSTRAINED_PART_NAME, m_constrainedPartName );
	DDX_Control( pDX, IDC_CONSTRAINED_GEOM_NAME, m_constrainedGeomName );
	DDX_Control( pDX, IDC_CONSTRAINED_GEOM_TYPE, m_constrainedGeomType );
	DDX_Control( pDX, IDC_REFERENCE_COMP_NAME, m_referenceCompName );
	DDX_Control( pDX, IDC_REFERENCE_PART_NAME, m_referencePartName );
	DDX_Control( pDX, IDC_REFERENCE_GEOM_NAME, m_referenceGeomName );
	DDX_Control( pDX, IDC_REFERENCE_GEOM_TYPE, m_referenceGeomType );
}


BEGIN_MESSAGE_MAP(AssemApplyParallelDialog, AssemApplyConstraintDialog)
	ON_CBN_SELCHANGE(IDC_CONSTRAINED_GEOM_TYPE, &AssemApplyParallelDialog::OnCbnSelchangeConstrainedGeomType)
	ON_CBN_SELCHANGE(IDC_REFERENCE_GEOM_TYPE, &AssemApplyParallelDialog::OnCbnSelchangeReferenceGeomType)
END_MESSAGE_MAP()


BOOL AssemApplyParallelDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_constraintName.SetWindowText( GetNewConstraintName( PmeStdAssemblyConstraintType_Parallel ) );
	m_constraintName.SetFocus();

	m_constrainedGeomType.AddString( _T("axis(cylinderical face)") );
	m_constrainedGeomType.AddString( _T("linear edge") );
	m_constrainedGeomType.AddString( _T("planar face") );	
	m_constrainedGeomType.SetCurSel(0);

	m_referenceGeomType.AddString( _T("axis(cylinderical face)") );
	m_referenceGeomType.AddString( _T("linear edge") );
	m_referenceGeomType.AddString( _T("planar face") );
	m_referenceGeomType.SetCurSel(0);

	// 기본적으로 constrained의 정보를 먼저 입력하도록 설정
	// constrained정보의 radio 버튼을 활성화하면 reference정보입력을 방지
	if ( m_selectPart == 0 )
	{
		m_partType = PmeStdAssemblyPartType_Constrained;

		m_selectButton = (CButton *)GetDlgItem( IDC_SELECT_CONSTRAINED );
		m_selectButton->SetCheck( TRUE );

		m_referenceGeomType.EnableWindow( FALSE );
		m_referenceCompName.EnableWindow( FALSE );
		m_referencePartName.EnableWindow( FALSE );
		m_referenceGeomName.EnableWindow( FALSE );
	}

	// m_constrainedGeomType의 기본 값을 "axis(= cylinderical face)"로 선택했으므로,
	// 선택 필터를 Face로 설정
	m_pOperator->OnFace();

	UpdateData( FALSE );

	// Dialog의 위치 지정
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
	
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;

}


void AssemApplyParallelDialog::OnCbnSelchangeConstrainedGeomType()
{
	m_selectPart = 0;

	ApplySelectionFilter( m_selectPart );
}


void AssemApplyParallelDialog::OnCbnSelchangeReferenceGeomType()
{
	m_selectPart = 1;

	ApplySelectionFilter( m_selectPart );
}

bool AssemApplyParallelDialog::ApplyConstraint()
{
	CString _constraintName;

	CString _constrainedCompName;
	CString _constrainedPartName;
	CString _constrainedGeomName;
	CString _constrainedGeomType;

	CString _referenceCompName;
	CString _referencePartName;
	CString _referenceGeomName;
	CString _referenceGeomType;

/******************** GUI에 입력된 값을 받아오기 시작 ********************/
	m_constraintName.GetWindowText( _constraintName );

	m_constrainedCompName.GetWindowText( _constrainedCompName );
	m_constrainedPartName.GetWindowText( _constrainedPartName );
	m_constrainedGeomName.GetWindowText( _constrainedGeomName );
	m_constrainedGeomType.GetWindowText( _constrainedGeomType );
	
	m_referenceCompName.GetWindowText( _referenceCompName );
	m_referencePartName.GetWindowText( _referencePartName );
	m_referenceGeomName.GetWindowText( _referenceGeomName );
	m_referenceGeomType.GetWindowText( _referenceGeomType );
/******************** GUI에 입력된 값을 받아오기 종료 ********************/


/******************** 입력 값의 유효성 판단 시작 ********************/
	if ( _constraintName.IsEmpty() )
	{
		AfxMessageBox( _T("Enter the constraint name") );
		return false;
	}

	if ( _constrainedCompName.IsEmpty() )
	{
		AfxMessageBox( _T("Select the constrained component") );
		return false;
	}

	if ( _constrainedPartName.IsEmpty() )
	{
		AfxMessageBox( _T("Select the constrained part") );
		return false;
	}

	if ( _constrainedGeomName.IsEmpty() )
	{
		AfxMessageBox( _T("Select the constrained geometry") );
		return false;
	}

	if ( _referenceCompName.IsEmpty() )
	{
		AfxMessageBox( _T("Select the reference component") );
		return false;
	}

	if ( _referencePartName.IsEmpty() )
	{
		AfxMessageBox( _T("Select the reference part") );
		return false;
	}

	if ( _referenceGeomName.IsEmpty() )
	{
		AfxMessageBox( _T("Select the reference geometry") );
		return false;
	}
/******************** 입력 값의 유효성 판단 종료 ********************/


	PmeHPart _hConstrainedPart, _hReferencePart;

	PmeAssemblyAPI::GetPartByName( m_hAssembly, _constrainedCompName, _constrainedPartName, _hConstrainedPart );
	PmeAssemblyAPI::GetPartByName( m_hAssembly, _referenceCompName, _referencePartName, _hReferencePart );


	PmeHReference _hConstrainedGeometry, _hReferenceGeometry;

	PmePartAPI::SelectBrepByName( _hConstrainedPart, _constrainedGeomName, _hConstrainedGeometry );
	PmePartAPI::SelectBrepByName( _hReferencePart, _referenceGeomName, _hReferenceGeometry );

	bool result = PmeStdAssemblyParallelAPI::ApplyParallel( m_hAssembly,
															_constraintName,
															_hConstrainedPart,
															_hConstrainedGeometry,
															_hReferencePart,
															_hReferenceGeometry );
	

	if ( result ) return true;
	else return false;
}