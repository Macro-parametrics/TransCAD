// PmCreateRevolveDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateRevolveDialog.h"
#include "..\PartModelingEngine\PmeStdSolidProtrusionRevolveFeature.h"
#include "..\PartModelingEngine\PmeStdSolidCutRevolveFeature.h"
#include "PmView.h"

// PmCreateRevolveDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateRevolveDialog, PmCreateFeatureDialog)

PmCreateRevolveDialog::PmCreateRevolveDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pView->SetOperator(new HOpCameraManipulate(m_pView->GetHView()));
}

PmCreateRevolveDialog::~PmCreateRevolveDialog()
{
}

void PmCreateRevolveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_PROFILE_SKETCH_NAME, m_sketchName);
	DDX_Control(pDX, IDC_REVOLVE_START_ANGLE, m_startAngle);
	DDX_Control(pDX, IDC_REVOLVE_END_ANGLE, m_endAngle);
	DDX_Control(pDX, IDC_REVOLVE_START_CONDITION, m_startCondition);
	DDX_Control(pDX, IDC_REVOLVE_END_CONDITION, m_endCondition);
	DDX_Control(pDX, IDC_IS_FLIP, m_isFlip);
	DDX_Control(pDX, IDC_BOOLEAN_TYPE, m_boolType);
}


BEGIN_MESSAGE_MAP(PmCreateRevolveDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_SELECT_PROFILE_SKETCH, OnBnClickedSelectProfileSketch)
	ON_CBN_SELCHANGE(IDC_BOOLEAN_TYPE, &PmCreateRevolveDialog::OnCbnSelchangeBooleanType)
END_MESSAGE_MAP()


// PmCreateRevolveDialog 메시지 처리기입니다.

BOOL PmCreateRevolveDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidProtrusionRevolveFeature));
	m_featureName.SetFocus();

	m_startAngle.SetWindowText(_T("360.0"));
	m_endAngle.SetWindowText(_T("0.0"));

	m_startCondition.AddString(_T("Blind"));
	m_startCondition.SetCurSel(0);
	
	m_endCondition.AddString(_T("Blind"));
	m_endCondition.SetCurSel(0);

	m_isFlip.AddString(_T("False"));
	m_isFlip.AddString(_T("True"));
	m_isFlip.SetCurSel(0);

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

bool PmCreateRevolveDialog::CreateFeature(void)
{
	DeSelectAll();
	
	CString _featureName;
	CString _sketchName;
	CString _startAngle;
	CString _endAngle;
	CString _startCondition;
	CString _endCondition;
	CString _boolType;
	CString _isFlip;

	m_featureName.GetWindowText(_featureName);
	m_sketchName.GetWindowText(_sketchName);
	m_startAngle.GetWindowText(_startAngle);
	m_endAngle.GetWindowText(_endAngle);
	m_startCondition.GetWindowText(_startCondition);
	m_endCondition.GetWindowText(_endCondition);
	m_boolType.GetWindowText(_boolType);
	m_isFlip.GetWindowText(_isFlip);

	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the extrude name."));
		return false;
	}

	if (_sketchName.IsEmpty())
	{
		AfxMessageBox(_T("Please select a profile sketch."));
		return false;
	}

	double startAngle = atof(_startAngle);
	double endAngle = atof(_endAngle);

	PmeStdRevolveEndType startCondition, endCondition;

	startCondition = PmeStdRevolveEndType_Blind;
	endCondition = PmeStdRevolveEndType_Blind;

	bool isFlip;

	if (_isFlip == _T("False"))
		isFlip = false;
	else if (_isFlip == _T("True"))
		isFlip = true;

	if (startAngle <= 0.0 && endAngle <= 0.0)
	{
		AfxMessageBox(_T("Invalid input parameters."));
		return false;
	}

	if (!CheckRevolveAxis(_sketchName))
	{
		AfxMessageBox(_T("The selected sketch does not have a centerline inside."));
		return false;
	}

	PmeHReference hSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _sketchName, hSketch);
	ASSERT(hSketch);

	CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
	CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
	PmFrame * pmFrame = (PmFrame *)pChild;

	if (m_isModified)
	{
		if (_boolType == _T("Protrusion"))
		{
			PmeStdSolidProtrusionRevolveFeatureAPI::SetProfileSketch(m_hFeature, hSketch);
			PmeStdSolidProtrusionRevolveFeatureAPI::SetStartAngle(m_hFeature, startAngle);
			PmeStdSolidProtrusionRevolveFeatureAPI::SetEndAngle(m_hFeature, endAngle);
			PmeStdSolidProtrusionRevolveFeatureAPI::SetFlip(m_hFeature, isFlip);
		}
		else if (_boolType == _T("Cut"))
		{
			PmeStdSolidCutRevolveFeatureAPI::SetProfileSketch(m_hFeature, hSketch);
			PmeStdSolidCutRevolveFeatureAPI::SetStartAngle(m_hFeature, startAngle);
			PmeStdSolidCutRevolveFeatureAPI::SetEndAngle(m_hFeature, endAngle);
			PmeStdSolidCutRevolveFeatureAPI::SetFlip(m_hFeature, isFlip);
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
		
		PmeHFeature hRevolveFeature = 0;

		if (_boolType == _T("Protrusion"))
			PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, _featureName, hSketch, startAngle, startCondition, endAngle, endCondition, isFlip, hRevolveFeature);
		else if (_boolType == _T("Cut"))
			PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, _featureName, hSketch, startAngle, startCondition, endAngle, endCondition, isFlip, hRevolveFeature);
		
		ASSERT(hRevolveFeature);
	}

	return true;
}

void PmCreateRevolveDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidProtrusionRevolveFeature)
	{
		PmeStdSolidProtrusionRevolveFeature * pProRevolve = (PmeStdSolidProtrusionRevolveFeature *)pFeature;
		
		m_boolType.SetCurSel(1);
		m_boolType.EnableWindow(false);

		m_featureName.SetWindowText(pProRevolve->GetName());
		m_featureName.EnableWindow(false);

		m_sketchName.SetWindowText(pProRevolve->GetProfileSketch()->GetReferenceeName());
		m_sketchName.EnableWindow(false);
		
		CString sA, eA;
		sA.AppendFormat(_T("%f"), pProRevolve->GetStartAngle());
		eA.AppendFormat(_T("%f"), pProRevolve->GetEndAngle());
		
		m_startAngle.SetWindowText(sA);
		m_endAngle.SetWindowText(eA);

		m_startCondition.SetCurSel(0);
		m_endCondition.SetCurSel(0);

		CString isFlip;

		if (!pProRevolve->IsFlip())
			m_isFlip.SetCurSel(0);
		else
			m_isFlip.SetCurSel(1);
	}
	else if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidCutRevolveFeature)
	{
		PmeStdSolidCutRevolveFeature * pCutRevolve = (PmeStdSolidCutRevolveFeature *)pFeature;
		
		m_boolType.SetCurSel(0);
		m_boolType.EnableWindow(false);

		m_featureName.SetWindowText(pCutRevolve->GetName());
		m_featureName.EnableWindow(false);

		m_sketchName.SetWindowText(pCutRevolve->GetProfileSketch()->GetReferenceeName());
		m_sketchName.EnableWindow(false);

		CString sA, eA;
		sA.AppendFormat(_T("%f"), pCutRevolve->GetStartAngle());
		eA.AppendFormat(_T("%f"), pCutRevolve->GetEndAngle());
		
		m_startAngle.SetWindowText(sA);
		m_endAngle.SetWindowText(eA);

		m_startCondition.SetCurSel(0);
		m_endCondition.SetCurSel(0);
		
		CString isFlip;

		if (!pCutRevolve->IsFlip())
			m_isFlip.SetCurSel(0);
		else
			m_isFlip.SetCurSel(1);
	}

	m_startAngle.SetFocus();
}

bool PmCreateRevolveDialog::CheckRevolveAxis(CString sketchName)
{
	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	PmeHFeature hFeature = 0;
	PmeFeaturesAPI::FindByName(hFeatures, sketchName, hFeature);

	bool hasCenterLine = false;
	PmeStdSketchFeatureAPI::HasCenterLine(hFeature, hasCenterLine);

	return hasCenterLine;
}

void PmCreateRevolveDialog::OnBnClickedSelectProfileSketch()
{
	if (m_sketchName.IsWindowEnabled())
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
					m_sketchName.SetWindowText(pFeature->GetName());
				else
					AfxMessageBox(_T("Please select a profile sketch."));
			}
		}
	}
}

void PmCreateRevolveDialog::OnCbnSelchangeBooleanType()
{
	if (m_boolType.GetCurSel() == 0)
		m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidCutRevolveFeature));
	else
		m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidProtrusionRevolveFeature));
}
