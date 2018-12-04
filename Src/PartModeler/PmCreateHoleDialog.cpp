// PmCreateHoleDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateHoleDialog.h"
#include ".\PmViewSelectionOperator.h"
#include "..\PartModelingEngine\PmeStdSolidHoleSimpleFeature.h"
#include "..\PartModelingEngine\PmeStdSolidHoleCounterboredFeature.h"
#include "..\PartModelingEngine\PmeStdSolidHoleCountersunkFeature.h"
#include "PmView.h"

// PmCreateHoleDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateHoleDialog, PmCreateFeatureDialog)

PmCreateHoleDialog::PmCreateHoleDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);

	m_pOperator->OnFace();
}

PmCreateHoleDialog::~PmCreateHoleDialog()
{
}

void PmCreateHoleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_HOLE_DEPTH, m_holeDepth);
	DDX_Control(pDX, IDC_HOLE_RADIUS, m_holeRadius);
	DDX_Control(pDX, IDC_HOLE_BOTTOM_ANGLE, m_holeBottomAngle);
	DDX_Control(pDX, IDC_HOLE_SINK_RADIUS, m_holeSinkRadius);
	DDX_Control(pDX, IDC_HOLE_SINK_ANGLE, m_holeSinkAngle);
	DDX_Control(pDX, IDC_HOLE_HEAD_DEPTH, m_holeHeadDepth);
	DDX_Control(pDX, IDC_HOLE_HEAD_RADIUS, m_holeHeadRadius);
	DDX_Control(pDX, IDC_HOLE_CENTER_X, m_holeCenterX);
	DDX_Control(pDX, IDC_HOLE_CENTER_Y, m_holeCenterY);
	DDX_Control(pDX, IDC_HOLE_CENTER_Z, m_holeCenterZ);
	DDX_Control(pDX, IDC_HOLE_TYPE, m_holeType);
}


BEGIN_MESSAGE_MAP(PmCreateHoleDialog, PmCreateFeatureDialog)
	ON_CBN_SELCHANGE(IDC_HOLE_TYPE, OnCbnSelchangeHoleType)
END_MESSAGE_MAP()


// PmCreateHoleDialog 메시지 처리기입니다.

BOOL PmCreateHoleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidHoleCounterboredFeature));
	m_featureName.SetFocus();
	
	m_holeType.Clear();
	
	m_holeType.AddString(_T("Counterbored"));
	m_holeType.AddString(_T("Countersunk"));
	m_holeType.AddString(_T("Simple"));
	m_holeType.SetCurSel(0);
	
	// 옵션 활성화 설정
	OnCbnSelchangeHoleType();

	m_holeDepth.SetWindowText(_T("10.0"));
	m_holeRadius.SetWindowText(_T("5.0"));
	m_holeBottomAngle.SetWindowText(_T("180.0"));
	m_holeSinkRadius.SetWindowText(_T("10.0"));
	m_holeSinkAngle.SetWindowText(_T("90.0"));
	m_holeHeadDepth.SetWindowText(_T("5.0"));
	m_holeHeadRadius.SetWindowText(_T("7.5"));
	m_holeCenterX.SetWindowText(_T("0.0"));
	m_holeCenterY.SetWindowText(_T("0.0"));
	m_holeCenterZ.SetWindowText(_T("0.0"));
	
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);
	
	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateHoleDialog::CreateFeature(void)
{	
	DeSelectAll();
	m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
		
	CString _featureName;
	CString _holeDepth;
	CString _holeRadius;
	CString _holeBottomAngle;
	CString _holeSinkRadius;
	CString _holeSinkAngle;
	CString _holeHeadDepth;
	CString _holeHeadRadius;
	CString _holeCenterX;
	CString _holeCenterY;
	CString _holeCenterZ;
	CString _holeType;

	m_featureName.GetWindowText(_featureName);
	m_holeDepth.GetWindowText(_holeDepth);
	m_holeRadius.GetWindowText(_holeRadius);
	m_holeBottomAngle.GetWindowText(_holeBottomAngle);
	m_holeSinkRadius.GetWindowText(_holeSinkRadius);
	m_holeSinkAngle.GetWindowText(_holeSinkAngle);
	m_holeHeadDepth.GetWindowText(_holeHeadDepth);
	m_holeHeadRadius.GetWindowText(_holeHeadRadius);
	m_holeCenterX.GetWindowText(_holeCenterX);
	m_holeCenterY.GetWindowText(_holeCenterY);
	m_holeCenterZ.GetWindowText(_holeCenterZ);
	m_holeType.GetWindowText(_holeType);
	
	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the fillet name."));
		return false;
	}

	if (m_selectedEntityNames.size() > 1)
	{
		AfxMessageBox(_T("Select one face."));
		return false;
	}

	double holeDepth = atof(_holeDepth);
	double holeRadius = atof(_holeRadius);
	double holeBottomAngle = atof(_holeBottomAngle);
	double holeSinkRadius = atof(_holeSinkRadius);
	double holeSinkAngle = atof(_holeSinkAngle);
	double holeHeadDepth = atof(_holeHeadDepth);
	double holeHeadRadius = atof(_holeHeadRadius);
	double holeCenterX = atof(_holeCenterX);
	double holeCenterY = atof(_holeCenterY);
	double holeCenterZ = atof(_holeCenterZ);

	if (holeRadius <= 0 || holeDepth <= 0 || holeBottomAngle <= 0 || holeBottomAngle > 180.0)
	{
		AfxMessageBox(_T("Invalid input parameters."));
		return false;
	}
	
	if (m_isModified)
	{
		if (_holeType == _T("Counterbored"))
		{
			if (holeHeadDepth > holeDepth || holeHeadRadius < holeRadius)
			{
				AfxMessageBox(_T("Invalid input parameters."));
				return false;
			}

			PmeStdSolidHoleCounterboredFeatureAPI::SetCenterX(m_hFeature, holeCenterX);
			PmeStdSolidHoleCounterboredFeatureAPI::SetCenterY(m_hFeature, holeCenterY);
			PmeStdSolidHoleCounterboredFeatureAPI::SetCenterZ(m_hFeature, holeCenterZ);
			PmeStdSolidHoleCounterboredFeatureAPI::SetStartRadius(m_hFeature, holeHeadRadius);
			PmeStdSolidHoleCounterboredFeatureAPI::SetStartDepth(m_hFeature, holeHeadDepth);
			PmeStdSolidHoleCounterboredFeatureAPI::SetEndRadius(m_hFeature, holeRadius);
			PmeStdSolidHoleCounterboredFeatureAPI::SetEndDepth(m_hFeature, holeDepth - holeHeadDepth);
			PmeStdSolidHoleCounterboredFeatureAPI::SetBottomAngle(m_hFeature, holeBottomAngle);
		}
		else if (_holeType == _T("Countersunk"))
		{
			if (holeSinkAngle > 180.0 || holeSinkAngle < 0.0 || holeSinkRadius < holeRadius)
			{
				AfxMessageBox(_T("Invalid input parameters."));
				return false;
			}
			
			PmeStdSolidHoleCountersunkFeatureAPI::SetCenterX(m_hFeature, holeCenterX);
			PmeStdSolidHoleCountersunkFeatureAPI::SetCenterY(m_hFeature, holeCenterY);
			PmeStdSolidHoleCountersunkFeatureAPI::SetCenterZ(m_hFeature, holeCenterZ);
			PmeStdSolidHoleCountersunkFeatureAPI::SetRadius(m_hFeature, holeRadius);
			PmeStdSolidHoleCountersunkFeatureAPI::SetDepth(m_hFeature, holeDepth);
			PmeStdSolidHoleCountersunkFeatureAPI::SetSinkRadius(m_hFeature, holeSinkRadius);
			PmeStdSolidHoleCountersunkFeatureAPI::SetSinkAngle(m_hFeature, holeSinkAngle);
			PmeStdSolidHoleCountersunkFeatureAPI::SetBottomAngle(m_hFeature, holeBottomAngle);
		}
		else if (_holeType == _T("Simple"))
		{
			PmeStdSolidHoleSimpleFeatureAPI::SetCenterX(m_hFeature, holeCenterX);
			PmeStdSolidHoleSimpleFeatureAPI::SetCenterY(m_hFeature, holeCenterY);
			PmeStdSolidHoleSimpleFeatureAPI::SetCenterZ(m_hFeature, holeCenterZ);
			PmeStdSolidHoleSimpleFeatureAPI::SetRadius(m_hFeature, holeRadius);
			PmeStdSolidHoleSimpleFeatureAPI::SetDepth(m_hFeature, holeDepth);
		}

		UpdateAll();
	}
	else
	{
		if (m_selectedEntityNames.size() == 0)
		{
			AfxMessageBox(_T("Select a target face first."));
			return false;
		}

		if (CheckFeatureExistence(_featureName))
		{
			AfxMessageBox(_T("Please enter another name."));
			return false;
		}
		
		PmeHReference hTargetFace = 0;
		PmePartAPI::SelectBrepByName(m_hPart, m_selectedEntityNames[0], hTargetFace);
		ASSERT(hTargetFace);

		PmeHFeature hHoleFeature = 0;

		if (_holeType == _T("Counterbored"))
		{
			if (holeHeadDepth > holeDepth || holeHeadRadius < holeRadius)
			{
				AfxMessageBox(_T("Invalid input parameters."));
				return false;
			}

			PmeStdSolidHoleCounterboredFeatureAPI::Create(m_hPart, _featureName, hTargetFace, holeCenterX, holeCenterY, holeCenterZ, holeHeadRadius, holeHeadDepth, holeRadius, holeDepth - holeHeadDepth, holeBottomAngle, hHoleFeature);
		}
		else if (_holeType == _T("Countersunk"))
		{
			if (holeSinkAngle > 180.0 || holeSinkAngle < 0.0 || holeSinkRadius < holeRadius)
			{
				AfxMessageBox(_T("Invalid input parameters."));
				return false;
			}

			PmeStdSolidHoleCountersunkFeatureAPI::Create(m_hPart, _featureName, hTargetFace, holeCenterX, holeCenterY, holeCenterZ, holeRadius, holeDepth, holeSinkRadius, holeSinkAngle, holeBottomAngle, hHoleFeature);
		}
		else if (_holeType == _T("Simple"))
			PmeStdSolidHoleSimpleFeatureAPI::Create(m_hPart, _featureName, hTargetFace, holeCenterX, holeCenterY, holeCenterZ, holeRadius, holeDepth, hHoleFeature);

		ASSERT(hHoleFeature);
	}
	
	return true;
}

void PmCreateHoleDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);
	
	m_holeType.EnableWindow(false);

	if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidHoleCounterboredFeature)
	{
		m_holeType.SetCurSel(0);
		
		PmeStdSolidHoleCounterboredFeature * pHole = (PmeStdSolidHoleCounterboredFeature *)pFeature;

		m_featureName.SetWindowText(pHole->GetName());
		m_featureName.EnableWindow(false);

		CString holeRadius, holeDepth, holeHeadRadius, holeHeadDepth;
		CString holeCenterX, holeCenterY, holeCenterZ;
		CString holeBottomAngle;

		holeRadius.AppendFormat(_T("%f"), pHole->GetEndRadius());
		holeDepth.AppendFormat(_T("%f"), pHole->GetEndDepth() + pHole->GetStartDepth());
		holeHeadRadius.AppendFormat(_T("%f"), pHole->GetStartRadius());
		holeHeadDepth.AppendFormat(_T("%f"), pHole->GetStartDepth());
		holeCenterX.AppendFormat(_T("%f"), pHole->GetCenterX());
		holeCenterY.AppendFormat(_T("%f"), pHole->GetCenterY());
		holeCenterZ.AppendFormat(_T("%f"), pHole->GetCenterZ());
		holeBottomAngle.AppendFormat(_T("%f"), pHole->GetAngle());

		m_holeRadius.SetWindowText(holeRadius);
		m_holeDepth.SetWindowText(holeDepth);
		m_holeHeadRadius.SetWindowText(holeHeadRadius);
		m_holeHeadDepth.SetWindowText(holeHeadDepth);
		m_holeCenterX.SetWindowText(holeCenterX);
		m_holeCenterY.SetWindowText(holeCenterY);
		m_holeCenterZ.SetWindowText(holeCenterZ);
		m_holeBottomAngle.SetWindowText(holeBottomAngle);

		m_holeSinkRadius.SetWindowText(_T("0.0"));
		m_holeSinkAngle.SetWindowText(_T("0.0"));
	}
	else if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidHoleCountersunkFeature)
	{
		m_holeType.SetCurSel(1);
		
		PmeStdSolidHoleCountersunkFeature * pHole = (PmeStdSolidHoleCountersunkFeature *)pFeature;

		m_featureName.SetWindowText(pHole->GetName());
		m_featureName.EnableWindow(false);

		CString holeRadius, holeDepth, holeSinkRadius, holeSinkAngle;
		CString holeCenterX, holeCenterY, holeCenterZ;
		CString holeBottomAngle;

		holeRadius.AppendFormat(_T("%f"), pHole->GetRadius());
		holeDepth.AppendFormat(_T("%f"), pHole->GetDepth());
		holeSinkRadius.AppendFormat(_T("%f"), pHole->GetSinkRadius());
		holeSinkAngle.AppendFormat(_T("%f"), pHole->GetSinkAngle());
		holeCenterX.AppendFormat(_T("%f"), pHole->GetCenterX());
		holeCenterY.AppendFormat(_T("%f"), pHole->GetCenterY());
		holeCenterZ.AppendFormat(_T("%f"), pHole->GetCenterZ());
		holeBottomAngle.AppendFormat(_T("%f"), pHole->GetBottomAngle());

		m_holeRadius.SetWindowText(holeRadius);
		m_holeDepth.SetWindowText(holeDepth);
		m_holeSinkRadius.SetWindowText(holeSinkRadius);
		m_holeSinkAngle.SetWindowText(holeSinkAngle);
		m_holeCenterX.SetWindowText(holeCenterX);
		m_holeCenterY.SetWindowText(holeCenterY);
		m_holeCenterZ.SetWindowText(holeCenterZ);
		m_holeBottomAngle.SetWindowText(holeBottomAngle);

		m_holeHeadRadius.SetWindowText(_T("0.0"));
		m_holeHeadDepth.SetWindowText(_T("0.0"));
	}
	else if (pFeature->GetFeatureType() == PmeFeatureType_StdSolidHoleSimpleFeature)
	{
		m_holeType.SetCurSel(2);
		
		PmeStdSolidHoleSimpleFeature * pHole = (PmeStdSolidHoleSimpleFeature *)pFeature;

		m_featureName.SetWindowText(pHole->GetName());
		m_featureName.EnableWindow(false);

		CString holeRadius, holeDepth;
		CString holeCenterX, holeCenterY, holeCenterZ;

		holeRadius.AppendFormat(_T("%f"), pHole->GetRadius());
		holeDepth.AppendFormat(_T("%f"), pHole->GetDepth());
		holeCenterX.AppendFormat(_T("%f"), pHole->GetCenterX());
		holeCenterY.AppendFormat(_T("%f"), pHole->GetCenterY());
		holeCenterZ.AppendFormat(_T("%f"), pHole->GetCenterZ());

		m_holeRadius.SetWindowText(holeRadius);
		m_holeDepth.SetWindowText(holeDepth);
		m_holeCenterX.SetWindowText(holeCenterX);
		m_holeCenterY.SetWindowText(holeCenterY);
		m_holeCenterZ.SetWindowText(holeCenterZ);

		m_holeBottomAngle.SetWindowText(_T("180.0"));
		m_holeSinkRadius.SetWindowText(_T("0.0"));
		m_holeSinkAngle.SetWindowText(_T("0.0"));
		m_holeHeadDepth.SetWindowText(_T("0.0"));
		m_holeHeadRadius.SetWindowText(_T("0.0"));
	}

	// 옵션 활성화 설정
	OnCbnSelchangeHoleType();
}

// 옵션 활성화 설정
void PmCreateHoleDialog::OnCbnSelchangeHoleType()
{
	if (m_holeType.GetCurSel() == 0)
	{
		if (m_featureName.IsWindowEnabled())
			m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidHoleCounterboredFeature));

		m_holeBottomAngle.EnableWindow(true);
		m_holeSinkRadius.EnableWindow(false);
		m_holeSinkAngle.EnableWindow(false);
		m_holeHeadDepth.EnableWindow(true);
		m_holeHeadRadius.EnableWindow(true);
	}
	else if (m_holeType.GetCurSel() == 1)
	{
		if (m_featureName.IsWindowEnabled())
			m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidHoleCountersunkFeature));
		
		m_holeBottomAngle.EnableWindow(true);
		m_holeSinkRadius.EnableWindow(true);
		m_holeSinkAngle.EnableWindow(true);
		m_holeHeadDepth.EnableWindow(false);
		m_holeHeadRadius.EnableWindow(false);
	}
	else if (m_holeType.GetCurSel() == 2)
	{
		if (m_featureName.IsWindowEnabled())
			m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidHoleSimpleFeature));
		
		m_holeBottomAngle.EnableWindow(false);
		m_holeSinkRadius.EnableWindow(false);
		m_holeSinkAngle.EnableWindow(false);
		m_holeHeadDepth.EnableWindow(false);
		m_holeHeadRadius.EnableWindow(false);
	}
}
