// AssemApplyConstraintDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include ".\AssemApplyConstraintDialog.h"
#include ".\AssemDocument.h"
#include ".\AssemView.h"
#include ".\AssemHView.h"
#include ".\PmeAssembly.h"
#include ".\AssemHSelectionSet.h"

#include ".\AssemViewPersistentNameOperator.h"
#include ".\AssemViewManipulationOperator.h"
#include ".\AssemHView.h"

// AssemApplyConstraintDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC( AssemApplyConstraintDialog, CDialog )

AssemApplyConstraintDialog::AssemApplyConstraintDialog( AssemView * pView, CWnd* pParent /*=NULL*/ )
	: CDialog( AssemApplyConstraintDialog::IDD, pParent )
	, m_pView( pView )
{
	m_hAssembly = m_pView->GetDocument()->GetAssembly();
	m_pOperator = new AssemViewPersistentNameOperator( this, m_pView->GetHView() );
	m_pView->SetOperator( m_pOperator );
}

AssemApplyConstraintDialog::~AssemApplyConstraintDialog()
{
}

void AssemApplyConstraintDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AssemApplyConstraintDialog, CDialog)
	ON_BN_CLICKED(IDOK, &AssemApplyConstraintDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AssemApplyConstraintDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_SELECT_CONSTRAINED, &AssemApplyConstraintDialog::OnBnClickedSelectConstrained)
	ON_BN_CLICKED(IDC_SELECT_REFERENCE, &AssemApplyConstraintDialog::OnBnClickedSelectReference)
END_MESSAGE_MAP()





void AssemApplyConstraintDialog::DeSelectAll()
{
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( m_pView->GetHoopsView()->GetSelection() );
	pSelection->DeSelectAll();
}

/**
	@brief	Update view
*/
void AssemApplyConstraintDialog::UpdateAll( void )
{
	m_pView->GetDocument()->UpdateAll();
}

/**
	@brief	Initialize constraint name
*/
CString AssemApplyConstraintDialog::GetNewConstraintName( PmeStdAssemblyConstraintType type )
{
	CString name;

	if ( type == PmeStdAssemblyConstraintType_Coaxial )
		name = "Coaxial";
	else if ( type == PmeStdAssemblyConstraintType_Incidence )
		name = "Incidence";
	else if ( type == PmeStdAssemblyConstraintType_Parallel )
		name = "Parallel";
	else if ( type == PmeStdAssemblyConstraintType_Perpendicular )
		name = "Perpendicular";
	else if ( type == PmeStdAssemblyConstraintType_Distance )
		name = "Distance";
	else if ( type == PmeStdAssemblyConstraintType_Angle )
		name = "Angle";
	/*else if ( type == PmeStdAssemblyConstraintType_Fix )
		name = "Fix";*/

	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(m_hAssembly);

	int cnt = 1;

	//for ( int i = 1; i < pAssembly->GetConstraints()->GetSize(); ++i )
	for ( int i = 1; i < pAssembly->GetConstraintList().size(); ++i )
	{
		//if ( pAssembly->GetConstraints()->GetItem( i )->GetType() == type )
		if ( pAssembly->GetConstraint( i )->GetType() == type )
			cnt++;
	}

	name.AppendFormat( _T("%d"), cnt );

	return name;
}

void AssemApplyConstraintDialog::SetPersistentName( CString name )
{
	if ( m_partType == PmeStdAssemblyPartType_Constrained )
	{
		m_constrainedGeomName.SetWindowTextA( name );

		
		CString _componentName, _partName;
		AfxExtractSubString( _componentName, name, 0, ',' );
		AfxExtractSubString( _partName, name, 1, ',' );

		m_constrainedCompName.SetWindowTextA( _componentName );
		m_constrainedPartName.SetWindowTextA( _partName );
	}

	else if ( m_partType == PmeStdAssemblyPartType_Reference )
	{
		m_referenceGeomName.SetWindowTextA( name );

		CString _componentName, _partName;
		AfxExtractSubString( _componentName, name, 0, ',' );
		AfxExtractSubString( _partName, name, 1, ',' );

		m_referenceCompName.SetWindowTextA( _componentName );
		m_referencePartName.SetWindowTextA( _partName );
	}	
}

void AssemApplyConstraintDialog::OnBnClickedOk()
{
	if ( ApplyConstraint() )
	{
		OnBnClickedCancel();
	}

	UpdateAll();
}


void AssemApplyConstraintDialog::OnBnClickedCancel()
{
	DeSelectAll();
	DestroyWindow();
	m_pView->SetOperator(new AssemViewManipulationOperator(m_pView->GetHView()));
}


void AssemApplyConstraintDialog::OnBnClickedSelectConstrained()
{
	m_partType = PmeStdAssemblyPartType_Constrained;

	m_selectButton = (CButton *)GetDlgItem( IDC_SELECT_CONSTRAINED );
	m_selectButton->SetCheck( TRUE );

	m_constrainedGeomType.EnableWindow( TRUE );
	m_constrainedCompName.EnableWindow( TRUE );
	m_constrainedPartName.EnableWindow( TRUE );
	m_constrainedGeomName.EnableWindow( TRUE );

	m_referenceGeomType.EnableWindow( FALSE );
	m_referenceCompName.EnableWindow( FALSE );
	m_referencePartName.EnableWindow( FALSE );
	m_referenceGeomName.EnableWindow( FALSE );
	
	m_selectPart = 0;

	ApplySelectionFilter( m_selectPart );

}


void AssemApplyConstraintDialog::OnBnClickedSelectReference()
{
	m_partType = PmeStdAssemblyPartType_Reference;

	m_selectButton = (CButton *)GetDlgItem( IDC_SELECT_REFERENCE );
	m_selectButton->SetCheck( TRUE );

	m_constrainedGeomType.EnableWindow( FALSE );
	m_constrainedCompName.EnableWindow( FALSE );
	m_constrainedPartName.EnableWindow( FALSE );
	m_constrainedGeomName.EnableWindow( FALSE );

	m_referenceGeomType.EnableWindow( TRUE );
	m_referenceCompName.EnableWindow( TRUE );
	m_referencePartName.EnableWindow( TRUE );
	m_referenceGeomName.EnableWindow( TRUE );

	m_selectPart = 1;

	ApplySelectionFilter( m_selectPart );
}

/**
	@brief		Apply selection filter
	@param i	0 is constrained part and 1 is reference part
*/
void AssemApplyConstraintDialog::ApplySelectionFilter( int i )
{
	CString type;

	if ( i == 0 )
	{		
		m_constrainedGeomType.GetWindowTextA( type );
	}

	else if ( i == 1 )
	{
		m_referenceGeomType.GetWindowTextA( type );
	}

	/*****************************************************/
	
	if ( type.Find( "axis" ) == 0 || type == "planar face" )
	{
		m_pOperator->OnFace();

		UpdateData( FALSE );
	}
	else if ( type == "circular edge" || type == "linear edge" )
	{
		m_pOperator->OnEdge();

		UpdateData( FALSE );
	}

	else if ( type == "vertex" )
	{
		m_pOperator->OnVertex();

		UpdateData( FALSE );
	}
}