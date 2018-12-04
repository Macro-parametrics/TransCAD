// PmCreateEdgeFilletDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateEdgeFilletDialog.h"
#include ".\PmViewSelectionOperator.h"
#include "PmView.h"
#include "..\PartModelingEngine\PmeStdSolidFilletConstantFeature.h"

// PmCreateEdgeFilletDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateEdgeFilletDialog, PmCreateFeatureDialog)

PmCreateEdgeFilletDialog::PmCreateEdgeFilletDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
	, m_isFace(TRUE)
	, m_isEdge(FALSE)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);
}

PmCreateEdgeFilletDialog::~PmCreateEdgeFilletDialog()
{
}

void PmCreateEdgeFilletDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_FILLET_RADIUS, m_filletRadius);
	DDX_Control(pDX, IDC_FILLET_PROPAGATION_TYPE, m_propagation);
	DDX_Check(pDX, IDC_VIEW_SELECT_FACE, m_isFace);
	DDX_Check(pDX, IDC_VIEW_SELECT_EDGE, m_isEdge);
}

BEGIN_MESSAGE_MAP(PmCreateEdgeFilletDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_VIEW_SELECT_FACE, OnBnClickedSelectFace)
	ON_BN_CLICKED(IDC_VIEW_SELECT_EDGE, OnBnClickedSelectEdge)
END_MESSAGE_MAP()


// PmCreateEdgeFilletDialog 메시지 처리기입니다.

void PmCreateEdgeFilletDialog::OnBnClickedSelectFace()
{
	m_isFace = TRUE;
	m_isEdge = FALSE;

	m_pOperator->OnFace();
	
	UpdateData(FALSE);
}

void PmCreateEdgeFilletDialog::OnBnClickedSelectEdge()
{
	m_isFace = FALSE;
	m_isEdge = TRUE;

	m_pOperator->OnEdge();

	UpdateData(FALSE);
}

BOOL PmCreateEdgeFilletDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	OnBnClickedSelectEdge();

	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidFilletConstantFeature));
	m_featureName.SetFocus();
	m_filletRadius.SetWindowText(_T("5.0"));

	m_propagation.AddString(_T("Minimal"));
	m_propagation.AddString(_T("Tangency"));
	m_propagation.SetCurSel(0);

	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateEdgeFilletDialog::CreateFeature(void)
{
	DeSelectAll();
	m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
	
	CString _featureName;
	CString _filletRadius;
	CString _propagation;

	m_featureName.GetWindowText(_featureName);
	m_filletRadius.GetWindowText(_filletRadius);
	m_propagation.GetWindowText(_propagation);
	
	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the fillet name."));
		return false;
	}

	double radius = atof(_filletRadius);

	if (radius <= 0)
	{
		AfxMessageBox(_T("The radius should be greater than zero."));
		return false;
	}

	PmePropagationType propagation;
	
	if (_propagation == _T("Minimal"))
		propagation = PmePropagationType_Minimal;
	else if (_propagation == _T("Tangency"))
		propagation = PmePropagationType_Tangency;

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
		PmeStdSolidFilletConstantFeature * pFillet = (PmeStdSolidFilletConstantFeature *)pFeature;
		
		if (m_selectedEntityNames.size() == 0)
			hReferenceEdges = PME_REFERENCES2HANDLE(pFillet->GetFilletEdges());
		
		PmeStdSolidFilletConstantFeatureAPI::SetFilletEdges(m_hFeature, hReferenceEdges);
		PmeStdSolidFilletConstantFeatureAPI::SetRadius(m_hFeature, radius);
		PmeStdSolidFilletConstantFeatureAPI::SetPropagationType(m_hFeature, propagation);

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

		PmeHFeature hFilletFeature = 0;
		PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, _featureName, hReferenceEdges, radius, propagation, hFilletFeature);
		ASSERT(hFilletFeature);
	}

	return true;
}

void PmCreateEdgeFilletDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeStdSolidFilletConstantFeature * pFillet = (PmeStdSolidFilletConstantFeature *)pFeature;

	m_featureName.SetWindowText(pFillet->GetName());
	m_featureName.EnableWindow(false);

	CString radius;
	radius.AppendFormat(_T("%f"), pFillet->GetRadius());
	m_filletRadius.SetWindowText(radius);
	m_filletRadius.SetFocus();
	
	if (pFillet->GetPropagation() == PmePropagationType_Minimal)
		m_propagation.SetCurSel(0);
	else
		m_propagation.SetCurSel(1);
}