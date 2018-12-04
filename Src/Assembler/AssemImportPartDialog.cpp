// AssemImportPartDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "AssemImportPartDialog.h"

#include ".\AssemDocument.h"
#include ".\AssemView.h"
#include ".\AssemHView.h"
#include ".\PmeAssembly.h"

#include "PmeUtility.h"

// AssemImportPartDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(AssemImportPartDialog, CDialog)

AssemImportPartDialog::AssemImportPartDialog( AssemDocument * pDoc, CWnd* pParent /*=NULL*/)
	: CDialog(AssemImportPartDialog::IDD, pParent)
	, m_pDoc( pDoc )
{
	m_hAssembly = m_pDoc->GetAssembly();
}

AssemImportPartDialog::~AssemImportPartDialog()
{
}

void AssemImportPartDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control( pDX, IDC_COMP_LIST, m_compList );
	DDX_Control( pDX, IDC_FILE_PATH, m_filePath );
	DDX_Control( pDX, IDC_NEW_PART_NAME, m_partName );
	DDX_Control( pDX, IDC_ORIGIN_X, m_partOriginX );
	DDX_Control( pDX, IDC_ORIGIN_Y, m_partOriginY );
	DDX_Control( pDX, IDC_ORIGIN_Z, m_partOriginZ );
	DDX_Control( pDX, IDC_NORMAL_X, m_partNormalX );
	DDX_Control( pDX, IDC_NORMAL_Y, m_partNormalY );
	DDX_Control( pDX, IDC_NORMAL_Z, m_partNormalZ );
}


BEGIN_MESSAGE_MAP(AssemImportPartDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT_PART, &AssemImportPartDialog::OnBnClickedButtonImportPart)
	ON_BN_CLICKED(IDOK, &AssemImportPartDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AssemImportPartDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


BOOL AssemImportPartDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	int _compSize;

	PmeAssemblyAPI::GetSize( m_hAssembly, _compSize );

	for ( int i = 0; i < _compSize; ++i )
	{
		PmeHComponent hComp;
		PmeAssemblyAPI::GetComponent( m_hAssembly, i, hComp );
		
		CString compName;
		PmeComponentAPI::GetName( hComp, compName );

		m_compList.AddString( compName );
	}

	m_partOriginX.SetWindowTextA( "0.0" );
	m_partOriginY.SetWindowTextA( "0.0" );
	m_partOriginZ.SetWindowTextA( "0.0" );

	m_partNormalX.SetWindowTextA( "0.0" );
	m_partNormalY.SetWindowTextA( "0.0" );
	m_partNormalZ.SetWindowTextA( "1.0" );

	// Dialog의 위치 지정
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
	
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return false;
}


void AssemImportPartDialog::OnBnClickedButtonImportPart()
{
	CString filters = _T("Part files(*.xml)|*.xml|");
	CFileDialog dlg( TRUE, _T("*.xml"), NULL, OFN_FILEMUSTEXIST, filters );

	if ( dlg.DoModal() )
	{
		m_filePath.SetWindowTextA( dlg.GetPathName() );
		m_partName.SetWindowTextA( dlg.GetFileTitle() );
	}	
}


void AssemImportPartDialog::OnBnClickedOk()
{
	if ( ImportPart() )
	{
		OnBnClickedCancel();
	}
}

void AssemImportPartDialog::OnBnClickedCancel()
{
	DestroyWindow();
}

bool AssemImportPartDialog::ImportPart()
{
	// 선택된 component 이름 받아오기
	CString _compName;
	int listIndex;

	listIndex = m_compList.GetCurSel();

	if ( listIndex == -1 )
	{
		AfxMessageBox( _T("Select the component in the list") );
		return false;
	}

	m_compList.GetText( listIndex, _compName );

	PmeHComponent hComp;
	PmeAssemblyAPI::GetComponentByName( m_hAssembly, _compName, hComp );
	
	// import part
	CString _partName, _filePath;
	m_partName.GetWindowTextA( _partName );
	m_filePath.GetWindowTextA( _filePath );

	if ( _filePath.IsEmpty() )
	{
		AfxMessageBox( _T("Select a file you want to import") );
		return false;
	}

	if ( _partName.IsEmpty() )
	{
		AfxMessageBox( _T("Enter the part name") );
		return false;
	}

	PmeHPart importedPart;
	PmePartAPI::Create( importedPart );
	PmePartAPI::SetName( importedPart, _partName );

	PmePartAPI::LoadXmlMacro( _filePath, importedPart );

	// part placement
	CString x, y, z, nx, ny, nz;
	m_partOriginX.GetWindowTextA( x );
	m_partOriginY.GetWindowTextA( y );
	m_partOriginZ.GetWindowTextA( z );

	m_partNormalX.GetWindowTextA( nx );
	m_partNormalY.GetWindowTextA( ny );
	m_partNormalZ.GetWindowTextA( nz );

	double _x, _y, _z, _nx, _ny, _nz;
	_x = atof( x );
	_y = atof( y );
	_z = atof( z );

	_nx = atof( nx );
	_ny = atof( ny );
	_nz = atof( nz );

	MrAxis2 t = MrAxis2( MrPosition( _x, _y, _z ),
						 MrDirection( _nx, _ny, _nz ),
						 MrDirection( 1.0, 0.0, 0.0 ) );

	PmePartAPI::SetPlacement( importedPart, t );

	// add part to component
	PmeComponentAPI::AddPart( hComp, importedPart );
	
	PmeAssemblyAPI::UpdateAll( m_hAssembly );

	MrAxis2 placement;
	PmePartAPI::GetPlacement( importedPart, placement);

	return true;
}