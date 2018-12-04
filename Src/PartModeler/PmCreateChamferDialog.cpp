// PmCreateEdgeFilletDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateChamferDialog.h"
#include ".\PmViewSelectionOperator.h"
#include "PmView.h"
#include "..\PartModelingEngine\PmeStdSolidChamferFeature.h"

// PmCreateEdgeFilletDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateChamferDialog, PmCreateFeatureDialog)

PmCreateChamferDialog::PmCreateChamferDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
	, m_isFace(TRUE)
	, m_isEdge(FALSE)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);
}

PmCreateChamferDialog::~PmCreateChamferDialog()
{
}

void PmCreateChamferDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_CHAMFER_LENGTH, m_chamferLength);
	DDX_Check(pDX, IDC_VIEW_SELECT_FACE, m_isFace);
	DDX_Check(pDX, IDC_VIEW_SELECT_EDGE, m_isEdge);
}

BEGIN_MESSAGE_MAP(PmCreateChamferDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_VIEW_SELECT_FACE, OnBnClickedSelectFace)
	ON_BN_CLICKED(IDC_VIEW_SELECT_EDGE, OnBnClickedSelectEdge)
END_MESSAGE_MAP()


// PmCreateEdgeFilletDialog 메시지 처리기입니다.

void PmCreateChamferDialog::OnBnClickedSelectFace()
{
	m_isFace = TRUE;
	m_isEdge = FALSE;

	m_pOperator->OnFace();
	
	UpdateData(FALSE);
}

void PmCreateChamferDialog::OnBnClickedSelectEdge()
{
	m_isFace = FALSE;
	m_isEdge = TRUE;

	m_pOperator->OnEdge();

	UpdateData(FALSE);
}

BOOL PmCreateChamferDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	OnBnClickedSelectEdge();

	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidChamferFeature));
	m_featureName.SetFocus();
	m_chamferLength.SetWindowText(_T("1.0"));
		
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateChamferDialog::CreateFeature(void)
{
	DeSelectAll();
	m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
	
	CString _featureName;
	CString _chamferLength;

	m_featureName.GetWindowText(_featureName);
	m_chamferLength.GetWindowText(_chamferLength);

	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the chamfer name."));
		return false;
	}

	double length = atof(_chamferLength);

	if (length <= 0)
	{
		AfxMessageBox(_T("The length should be greater than zero."));
		return false;
	}

	PmeHReferences hReferenceEdges = 0;
	PmeReferencesAPI::Create(hReferenceEdges);

	for (int i = 0; i < (int)m_selectedEntityNames.size(); ++i)
	{
		PmeHReference hReferenceEdge = 0;
		PmePartAPI::SelectBrepByName(m_hPart, m_selectedEntityNames[i], hReferenceEdge);
		ASSERT(hReferenceEdge);
	
		PmeReferencesAPI::AddItem(hReferenceEdges, hReferenceEdge);
	}

	if (m_isModified)
	{
		PmeFeature * pFeature = PME_HANDLE2FEATURE(m_hFeature);
		PmeStdSolidChamferFeature * pChamfer = (PmeStdSolidChamferFeature *)pFeature;
		
		if (m_selectedEntityNames.size() == 0)
			hReferenceEdges = PME_REFERENCES2HANDLE(pChamfer->GetSelectedEdges());
		
		PmeStdSolidChamferFeatureAPI::SetSelectedEdges(m_hFeature, hReferenceEdges);
		PmeStdSolidChamferFeatureAPI::SetLength(m_hFeature, length);
	
		UpdateAll();
	}
	else
	{
		if (m_selectedEntityNames.size() == 0)
		{
			AfxMessageBox(_T("Select more than one edge or face first."));
			return false;
		}

		if (CheckFeatureExistence(_featureName))
		{
			AfxMessageBox(_T("Please enter another name."));
			return false;
		}

		PmeHFeature hChamferFeature = 0;
		PmeStdSolidChamferFeatureAPI::Create(m_hPart, _featureName, hReferenceEdges, length, hChamferFeature);
		ASSERT(hChamferFeature);
	}

	return true;
}

void PmCreateChamferDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeStdSolidChamferFeature * pChamfer = (PmeStdSolidChamferFeature *)pFeature;
	
	m_featureName.SetWindowText(pChamfer->GetName());
	m_featureName.EnableWindow(false);

	CString length;
	length.AppendFormat(_T("%f"), pChamfer->GetLength());
	m_chamferLength.SetWindowText(length);
	m_chamferLength.SetFocus();
}