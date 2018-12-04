// PmCreateExtrudeDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateExtrudeDialog.h"
#include "..\PartModelingEngine\PmeStdSolidProtrusionExtrudeFeature.h"
#include "..\PartModelingEngine\PmeStdSolidCutExtrudeFeature.h"
#include "PmView.h"

// PmCreateExtrudeDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateExtrudeDialog, PmCreateFeatureDialog)

PmCreateExtrudeDialog::PmCreateExtrudeDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pView->SetOperator(new HOpCameraManipulate(m_pView->GetHView()));
}

PmCreateExtrudeDialog::~PmCreateExtrudeDialog()
{
}

void PmCreateExtrudeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_PROFILE_SKETCH_NAME, m_sketchName);
	DDX_Control(pDX, IDC_EXTRUDE_START_DEPTH, m_startDepth);
	DDX_Control(pDX, IDC_EXTRUDE_END_DEPTH, m_endDepth);
	DDX_Control(pDX, IDC_EXTRUDE_START_CONDITION, m_startCondition);
	DDX_Control(pDX, IDC_EXTRUDE_END_CONDITION, m_endCondition);
	DDX_Control(pDX, IDC_IS_FLIP, m_isFlip);
	DDX_Control(pDX, IDC_BOOLEAN_TYPE, m_boolType);
}

BEGIN_MESSAGE_MAP(PmCreateExtrudeDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_SELECT_PROFILE_SKETCH, OnBnClickedSelectProfileSketch)
	ON_CBN_SELCHANGE(IDC_BOOLEAN_TYPE, &PmCreateExtrudeDialog::OnCbnSelchangeBooleanType)
END_MESSAGE_MAP()


// PmCreateExtrudeDialog 메시지 처리기입니다.

BOOL PmCreateExtrudeDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidProtrusionExtrudeFeature));
	m_featureName.SetFocus();

	m_startDepth.SetWindowText(_T("20.0"));
	m_endDepth.SetWindowText(_T("0.0"));

	m_startCondition.AddString(_T("Blind"));
	m_startCondition.AddString(_T("ThroughAll"));
	m_startCondition.SetCurSel(0);
	
	m_endCondition.AddString(_T("Blind"));
	m_endCondition.AddString(_T("ThroughAll"));
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

bool PmCreateExtrudeDialog::CreateFeature(void)
{
	DeSelectAll();
	
	CString _featureName;
	CString _sketchName;
	CString _startDepth;
	CString _endDepth;
	CString _startCondition;
	CString _endCondition;
	CString _boolType;
	CString _isFlip;

	m_featureName.GetWindowText(_featureName);
	m_sketchName.GetWindowText(_sketchName);
	m_startDepth.GetWindowText(_startDepth);
	m_endDepth.GetWindowText(_endDepth);
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

	double startDepth = atof(_startDepth);
	double endDepth = atof(_endDepth);

	PmeStdExtrudeEndType startCondition, endCondition;

	if (_startCondition == _T("Blind"))
		startCondition = PmeStdExtrudeEndType_Blind;
	else if (_startCondition == _T("ThroughAll"))
		startCondition = PmeStdExtrudeEndType_ThroughAll;
	
	if (_endCondition == _T("Blind"))
		endCondition = PmeStdExtrudeEndType_Blind;
	else if (_endCondition == _T("ThroughAll"))
		endCondition = PmeStdExtrudeEndType_ThroughAll;

	bool isFlip;

	if (_isFlip == _T("False"))
		isFlip = false;
	else if (_isFlip == _T("True"))
		isFlip = true;

	if (startDepth <= 0.0 && endDepth <= 0.0
		&& startCondition == PmeStdExtrudeEndType_Blind
		&& endCondition == PmeStdExtrudeEndType_Blind)
	{
		AfxMessageBox(_T("Invalid input parameters."));
		return false;
	}

	PmeHReference hSketch = 0;
	PmePartAPI::SelectObjectByName(m_hPart, _sketchName, hSketch);
	ASSERT(hSketch);

	if (m_isModified)
	{
		if (_boolType == _T("Protrusion"))
		{
			PmeStdSolidProtrusionExtrudeFeatureAPI::SetProfileSketch(m_hFeature, hSketch);
			PmeStdSolidProtrusionExtrudeFeatureAPI::SetStartDepth(m_hFeature, startDepth);
			PmeStdSolidProtrusionExtrudeFeatureAPI::SetStartCondition(m_hFeature, startCondition);
			PmeStdSolidProtrusionExtrudeFeatureAPI::SetEndDepth(m_hFeature, endDepth);
			PmeStdSolidProtrusionExtrudeFeatureAPI::SetEndCondition(m_hFeature, endCondition);
			PmeStdSolidProtrusionExtrudeFeatureAPI::SetFlip(m_hFeature, isFlip);
		}
		else if (_boolType == _T("Cut"))
		{
			PmeStdSolidCutExtrudeFeatureAPI::SetProfileSketch(m_hFeature, hSketch);
			PmeStdSolidCutExtrudeFeatureAPI::SetStartDepth(m_hFeature, startDepth);
			PmeStdSolidCutExtrudeFeatureAPI::SetStartCondition(m_hFeature, startCondition);
			PmeStdSolidCutExtrudeFeatureAPI::SetEndDepth(m_hFeature, endDepth);
			PmeStdSolidCutExtrudeFeatureAPI::SetEndCondition(m_hFeature, endCondition);
			PmeStdSolidCutExtrudeFeatureAPI::SetFlip(m_hFeature, isFlip);
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
		
		PmeHFeature hExtrudeFeature = 0;

		if (_boolType == _T("Protrusion"))
			PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, _featureName, hSketch, startDepth, startCondition, endDepth, endCondition, isFlip, hExtrudeFeature);
		else if (_boolType == _T("Cut"))
			PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, _featureName, hSketch, startDepth, startCondition, endDepth, endCondition, isFlip, hExtrudeFeature);
		
		ASSERT(hExtrudeFeature);
	}

	return true;
}

void PmCreateExtrudeDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidProtrusionExtrudeFeature)
	{
		PmeStdSolidProtrusionExtrudeFeature * pProExtrude = (PmeStdSolidProtrusionExtrudeFeature *)pFeature;
		
		m_boolType.SetCurSel(1);
		m_boolType.EnableWindow(false);

		m_featureName.SetWindowText(pProExtrude->GetName());
		m_featureName.EnableWindow(false);

		m_sketchName.SetWindowText(pProExtrude->GetProfileSketch()->GetReferenceeName());
		m_sketchName.EnableWindow(false);
		
		CString sD, eD;
		sD.AppendFormat(_T("%f"), pProExtrude->GetStartDepth());
		eD.AppendFormat(_T("%f"), pProExtrude->GetEndDepth());
		
		m_startDepth.SetWindowText(sD);
		m_endDepth.SetWindowText(eD);

		if (pProExtrude->GetStartCondition() == PmeStdExtrudeEndType_Blind)
			m_startCondition.SetCurSel(0);
		else
			m_startCondition.SetCurSel(1);

		if (pProExtrude->GetEndCondition() == PmeStdExtrudeEndType_Blind)
			m_endCondition.SetCurSel(0);
		else
			m_endCondition.SetCurSel(1);
		
		CString isFlip;

		if (!pProExtrude->IsFlip())
			m_isFlip.SetCurSel(0);
		else
			m_isFlip.SetCurSel(1);
	}
	else if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidCutExtrudeFeature)
	{
		PmeStdSolidCutExtrudeFeature * pCutExtrude = (PmeStdSolidCutExtrudeFeature *)pFeature;
		
		m_boolType.SetCurSel(0);
		m_boolType.EnableWindow(false);

		m_featureName.SetWindowText(pCutExtrude->GetName());
		m_featureName.EnableWindow(false);

		m_sketchName.SetWindowText(pCutExtrude->GetProfileSketch()->GetReferenceeName());
		m_sketchName.EnableWindow(false);

		CString sD, eD;
		sD.AppendFormat(_T("%f"), pCutExtrude->GetStartDepth());
		eD.AppendFormat(_T("%f"), pCutExtrude->GetEndDepth());
		
		m_startDepth.SetWindowText(sD);
		m_endDepth.SetWindowText(eD);

		if (pCutExtrude->GetStartCondition() == PmeStdExtrudeEndType_Blind)
			m_startCondition.SetCurSel(0);
		else
			m_startCondition.SetCurSel(1);

		if (pCutExtrude->GetEndCondition() == PmeStdExtrudeEndType_Blind)
			m_endCondition.SetCurSel(0);
		else
			m_endCondition.SetCurSel(1);
		
		CString isFlip;

		if (!pCutExtrude->IsFlip())
			m_isFlip.SetCurSel(0);
		else
			m_isFlip.SetCurSel(1);
	}

	m_startDepth.SetFocus();
}

void PmCreateExtrudeDialog::OnBnClickedSelectProfileSketch()
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


void PmCreateExtrudeDialog::OnCbnSelchangeBooleanType()
{
	if (m_boolType.GetCurSel() == 0)
		m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidCutExtrudeFeature));
	else
		m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidProtrusionExtrudeFeature));
}
