// PmCreateOffsetDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateOffsetDialog.h"
#include ".\PmViewSelectionOperator.h"
#include "PmView.h"
#include "..\PartModelingEngine\PmeStdSolidOffsetFeature.h"

// PmCreateOffsetDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateOffsetDialog, PmCreateFeatureDialog)

PmCreateOffsetDialog::PmCreateOffsetDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);

	m_pOperator->OnFace();
}

PmCreateOffsetDialog::~PmCreateOffsetDialog()
{
}

void PmCreateOffsetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_OFFSET_THICKNESS, m_thickness);
}


BEGIN_MESSAGE_MAP(PmCreateOffsetDialog, PmCreateFeatureDialog)
END_MESSAGE_MAP()


// PmCreateOffsetDialog 메시지 처리기입니다.

BOOL PmCreateOffsetDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidOffsetFeature));
	m_featureName.SetFocus();
	m_thickness.SetWindowText(_T("1.0"));;

	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);
	
	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateOffsetDialog::CreateFeature(void)
{
	DeSelectAll();
	m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
		
	CString _featureName;
	CString _thickness;

	m_featureName.GetWindowText(_featureName);
	m_thickness.GetWindowText(_thickness);
	
	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the fillet name."));
		return false;
	}

	double thickess = atof(_thickness);

	if (thickess < 0)
	{
		AfxMessageBox(_T("The thickness should be greater than zero."));
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
		PmeStdSolidOffsetFeature * pOffset = (PmeStdSolidOffsetFeature *)pFeature;
		
		if (m_selectedEntityNames.size() == 0)
			hReferenceFaces = PME_REFERENCES2HANDLE(pOffset->GetTargetFaces());
		
		PmeStdSolidOffsetFeatureAPI::SetTargetFaces(m_hFeature, hReferenceFaces);
		PmeStdSolidOffsetFeatureAPI::SetThickness(m_hFeature, thickess);

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

		PmeHFeature hOffsetFeature = 0;
		PmeStdSolidOffsetFeatureAPI::Create(m_hPart, _featureName, hReferenceFaces, thickess, hOffsetFeature);
		ASSERT(hOffsetFeature);
	}
	
	return true;
}

void PmCreateOffsetDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeStdSolidOffsetFeature * pOffset = (PmeStdSolidOffsetFeature *)pFeature;

	m_featureName.SetWindowText(pOffset->GetName());
	m_featureName.EnableWindow(false);

	CString thickness;
	thickness.AppendFormat(_T("%f"), pOffset->GetThickness());
	m_thickness.SetWindowText(thickness);
	m_thickness.SetFocus();
}