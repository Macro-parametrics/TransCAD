// PmCreateShellDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateShellDialog.h"
#include ".\PmViewSelectionOperator.h"
#include "PmView.h"
#include "..\PartModelingEngine\PmeStdSolidShellFeature.h"

// PmCreateShellDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateShellDialog, PmCreateFeatureDialog)

PmCreateShellDialog::PmCreateShellDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);

	m_pOperator->OnFace();
}

PmCreateShellDialog::~PmCreateShellDialog()
{
}

void PmCreateShellDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_SHELL_INNER_THICKNESS, m_innerThickness);
	DDX_Control(pDX, IDC_SHELL_OUTER_THICKNESS, m_outerThickness);
}


BEGIN_MESSAGE_MAP(PmCreateShellDialog, PmCreateFeatureDialog)
END_MESSAGE_MAP()


// PmCreateShellDialog 메시지 처리기입니다.

BOOL PmCreateShellDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidShellFeature));
	m_featureName.SetFocus();
	
	m_innerThickness.SetWindowText(_T("1.0"));;
	m_outerThickness.SetWindowText(_T("0.0"));;
	
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);
	
	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateShellDialog::CreateFeature(void)
{
	DeSelectAll();
	m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
		
	CString _featureName;
	CString _innerThickness;
	CString _outerThickness;

	m_featureName.GetWindowText(_featureName);
	m_innerThickness.GetWindowText(_innerThickness);
	m_outerThickness.GetWindowText(_outerThickness);
	
	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the shell name."));
		return false;
	}

	double innerThickness = atof(_innerThickness);
	double outerThickness = atof(_outerThickness);

	if (innerThickness < 0 || outerThickness < 0)
	{
		AfxMessageBox(_T("Invalid input parameters."));
		return false;
	}

	PmeHReferences hReferenceFaces = 0;
	PmeReferencesAPI::Create(hReferenceFaces);

	for (int i = 0; i < (int)m_selectedEntityNames.size(); ++i)
	{
		PmeHReference hReferenceFace = 0;
		PmePartAPI::SelectBrepByName(m_hPart, m_selectedEntityNames[i], hReferenceFace);
		ASSERT(hReferenceFace);
		
		PmeReferencesAPI::AddItem(hReferenceFaces, hReferenceFace);
	}

	if (m_isModified)
	{
		PmeFeature * pFeature = PME_HANDLE2FEATURE(m_hFeature);
		PmeStdSolidShellFeature * pShell = (PmeStdSolidShellFeature *)pFeature;
		
		if (m_selectedEntityNames.size() == 0)
			hReferenceFaces = PME_REFERENCES2HANDLE(pShell->GetTargetFaces());
		
		PmeStdSolidShellFeatureAPI::SetTargetFaces(m_hFeature, hReferenceFaces);
		PmeStdSolidShellFeatureAPI::SetInnerThickness(m_hFeature, innerThickness);
		PmeStdSolidShellFeatureAPI::SetOuterThickness(m_hFeature, outerThickness);

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

		PmeHFeature hShellFeature = 0;
		PmeStdSolidShellFeatureAPI::Create(m_hPart, _featureName, hReferenceFaces, innerThickness, outerThickness, hShellFeature);
		ASSERT(hShellFeature);
	}
	
	return true;
}

void PmCreateShellDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeStdSolidShellFeature * pShell = (PmeStdSolidShellFeature *)pFeature;

	m_featureName.SetWindowText(pShell->GetName());
	m_featureName.EnableWindow(false);

	CString innerThickness, outerThickness;
	innerThickness.AppendFormat(_T("%f"), pShell->GetInnerThickness());
	outerThickness.AppendFormat(_T("%f"), pShell->GetOuterThickness());

	m_innerThickness.SetWindowText(innerThickness);
	m_outerThickness.SetWindowText(outerThickness);
	m_innerThickness.SetFocus();
}