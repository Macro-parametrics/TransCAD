// PmCreateSweepDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateSweepDialog.h"
#include "..\PartModelingEngine\PmeStdSolidProtrusionSweepFeature.h"
#include "..\PartModelingEngine\PmeStdSolidCutSweepFeature.h"
#include "PmView.h"

// PmCreateSweepDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateSweepDialog, PmCreateFeatureDialog)

PmCreateSweepDialog::PmCreateSweepDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pView->SetOperator(new HOpCameraManipulate(m_pView->GetHView()));
}

PmCreateSweepDialog::~PmCreateSweepDialog()
{
}

void PmCreateSweepDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_PROFILE_SKETCH_NAME, m_profileSketchName);
	DDX_Control(pDX, IDC_GUIDE_SKETCH_NAME, m_guideSketchName);
	DDX_Control(pDX, IDC_BOOLEAN_TYPE, m_boolType);
}


BEGIN_MESSAGE_MAP(PmCreateSweepDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_SELECT_PROFILE_SKETCH, OnBnClickedSelectProfileSketch)
	ON_BN_CLICKED(IDC_SELECT_GUIDE_SKETCH, OnBnClickedSelectGuideSketch)
	ON_CBN_SELCHANGE(IDC_BOOLEAN_TYPE, &PmCreateSweepDialog::OnCbnSelchangeBooleanType)
END_MESSAGE_MAP()


// PmCreateSweepDialog 메시지 처리기입니다.

BOOL PmCreateSweepDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidProtrusionSweepFeature));
	m_featureName.SetFocus();

	m_boolType.AddString(_T("Protrusion"));
	m_boolType.AddString(_T("Cut"));
	m_boolType.SetCurSel(1);
	
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
	
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateSweepDialog::CreateFeature(void)
{
	DeSelectAll();
	
	CString _featureName;
	CString _profileSketchName;
	CString _guideSketchName;
	CString _boolType;

	m_featureName.GetWindowText(_featureName);
	m_profileSketchName.GetWindowText(_profileSketchName);
	m_guideSketchName.GetWindowText(_guideSketchName);
	m_boolType.GetWindowText(_boolType);

	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the extrude name."));
		return false;
	}

	if (_profileSketchName.IsEmpty())
	{
		AfxMessageBox(_T("Please select a profile sketch."));
		return false;
	}

	if (_guideSketchName.IsEmpty())
	{
		AfxMessageBox(_T("Please select a guide sketch."));
		return false;
	}

	PmeHReference hProfileSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _profileSketchName, hProfileSketch);
	ASSERT(hProfileSketch);

	PmeHReference hGuideCurve = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _guideSketchName, hGuideCurve);
	ASSERT(hGuideCurve);

	if (m_isModified)
	{
		if (_boolType == _T("Protrusion"))
		{
			PmeStdSolidProtrusionSweepFeatureAPI::SetProfileSketch(m_hFeature, hProfileSketch);
			PmeStdSolidProtrusionSweepFeatureAPI::SetGuideCurve(m_hFeature, hGuideCurve);

		}
		else if (_boolType == _T("Cut"))
		{
			PmeStdSolidCutSweepFeatureAPI::SetProfileSketch(m_hFeature, hProfileSketch);
			PmeStdSolidCutSweepFeatureAPI::SetGuideCurve(m_hFeature, hGuideCurve);
		}

		UpdateAll();
	}
	else
	{
		if (CheckFeatureExistence(_featureName))
		{
			AfxMessageBox(_T("Please enter another name."));
			return false;
		}
		
		PmeHFeature hSweepFeature = 0;

		if (_boolType == _T("Protrusion"))
			PmeStdSolidProtrusionSweepFeatureAPI::Create(m_hPart, _featureName, hProfileSketch, hGuideCurve, hSweepFeature);
		else if (_boolType == _T("Cut"))
			PmeStdSolidCutSweepFeatureAPI::Create(m_hPart, _featureName, hProfileSketch, hGuideCurve, hSweepFeature);
		
		ASSERT(hSweepFeature);
	}

	return true;
}

void PmCreateSweepDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidProtrusionSweepFeature)
	{
		PmeStdSolidProtrusionSweepFeature * pProSweep = (PmeStdSolidProtrusionSweepFeature *)pFeature;
		
		m_boolType.SetCurSel(1);
		m_boolType.EnableWindow(false);

		m_featureName.SetWindowText(pProSweep->GetName());
		m_featureName.EnableWindow(false);

		m_profileSketchName.SetWindowText(pProSweep->GetProfileSketch()->GetReferenceeName());
		m_profileSketchName.EnableWindow(false);

		m_guideSketchName.SetWindowText(pProSweep->GetGuideCurve()->GetReferenceeName());
		m_guideSketchName.EnableWindow(false);
	}
	else if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidCutSweepFeature)
	{
		PmeStdSolidCutSweepFeature * pCutSweep = (PmeStdSolidCutSweepFeature *)pFeature;
		
		m_boolType.SetCurSel(0);
		m_boolType.EnableWindow(false);

		m_featureName.SetWindowText(pCutSweep->GetName());
		m_featureName.EnableWindow(false);

		m_profileSketchName.SetWindowText(pCutSweep->GetProfileSketch()->GetReferenceeName());
		m_profileSketchName.EnableWindow(false);

		m_guideSketchName.SetWindowText(pCutSweep->GetGuideCurve()->GetReferenceeName());
		m_guideSketchName.EnableWindow(false);
	}

	m_featureName.SetFocus();
}

void PmCreateSweepDialog::OnBnClickedSelectProfileSketch()
{
	if (m_profileSketchName.IsWindowEnabled())
	{
		CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
		CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
		PmFrame * pmFrame = (PmFrame *)pChild;
		
		HTREEITEM item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetSelectedItem();

		if (item)
		{
			PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemData(item));

			if (pFeature)
			{
				if (pFeature->GetFeatureType() == PmeFeatureType_StdSketchFeature)
					m_profileSketchName.SetWindowText(pFeature->GetName());
				else
					AfxMessageBox(_T("Please select a profile sketch."));
			}
		}
	}
}

void PmCreateSweepDialog::OnBnClickedSelectGuideSketch()
{
	if (m_guideSketchName.IsWindowEnabled())
	{
		CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
		CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
		PmFrame * pmFrame = (PmFrame *)pChild;
		
		HTREEITEM item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetSelectedItem();

		if (item)
		{
			PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemData(item));

			if (pFeature)
			{
				if (pFeature->GetFeatureType() == PmeFeatureType_StdSketchFeature)
					m_guideSketchName.SetWindowText(pFeature->GetName());
				else
					AfxMessageBox(_T("Please select a profile sketch."));
			}
		}
	}
}

void PmCreateSweepDialog::OnCbnSelchangeBooleanType()
{
	if (m_boolType.GetCurSel() == 0)
		m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidCutSweepFeature));
	else
		m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidProtrusionSweepFeature));
}
