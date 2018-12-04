// PmCreateDatumPlaneOffsetDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateDatumPlaneOffsetDialog.h"
#include "PmView.h"
#include "PmFrame.h"
#include ".\PmViewSelectionOperator.h"
#include "..\PartModelingEngine\PmeStdDatumPlaneOffsetFeature.h"


// PmCreateDatumPlaneOffsetDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateDatumPlaneOffsetDialog, PmCreateFeatureDialog)

PmCreateDatumPlaneOffsetDialog::PmCreateDatumPlaneOffsetDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);

	m_pOperator->OnFace();
}

PmCreateDatumPlaneOffsetDialog::~PmCreateDatumPlaneOffsetDialog()
{
}

void PmCreateDatumPlaneOffsetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_REFERENCE_PLANE_NAME, m_referenceName);
	DDX_Control(pDX, IDC_DATUMPLANE_DISTANCE, m_distance);
	DDX_Control(pDX, IDC_IS_FLIP, m_isFlip);
	DDX_Control(pDX, IDC_IS_FREE, m_isFree);
	DDX_Control(pDX, IDC_DATUM_ORIGIN_X, m_orgX);
	DDX_Control(pDX, IDC_DATUM_ORIGIN_Y, m_orgY);
	DDX_Control(pDX, IDC_DATUM_ORIGIN_Z, m_orgZ);
	DDX_Control(pDX, IDC_DATUM_XDIRECTION_X, m_xdirX);
	DDX_Control(pDX, IDC_DATUM_XDIRECTION_Y, m_xdirY);
	DDX_Control(pDX, IDC_DATUM_XDIRECTION_Z, m_xdirZ);
	DDX_Control(pDX, IDC_DATUM_YDIRECTION_X, m_ydirX);
	DDX_Control(pDX, IDC_DATUM_YDIRECTION_Y, m_ydirY);
	DDX_Control(pDX, IDC_DATUM_YDIRECTION_Z, m_ydirZ);
}


BEGIN_MESSAGE_MAP(PmCreateDatumPlaneOffsetDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_SELECT_REFERENCE_PLANE, OnBnClickedSelectReferencePlane)
	ON_CBN_SELCHANGE(IDC_IS_FREE, &PmCreateDatumPlaneOffsetDialog::OnCbnSelchangeIsFree)
END_MESSAGE_MAP()


// PmCreateDatumPlaneOffsetDialog 메시지 처리기입니다.

BOOL PmCreateDatumPlaneOffsetDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdDatumPlaneOffsetFeature));
	m_featureName.SetFocus();
	
	m_isFree.AddString(_T("False"));
	m_isFree.AddString(_T("True"));
	m_isFree.SetCurSel(0);
	
	OnCbnSelchangeIsFree();

	m_distance.SetWindowText(_T("20.0"));

	m_isFlip.AddString(_T("False"));
	m_isFlip.AddString(_T("True"));
	m_isFlip.SetCurSel(0);

	m_orgX.SetWindowText(_T("0.0"));
	m_orgY.SetWindowText(_T("0.0"));
	m_orgZ.SetWindowText(_T("0.0"));
	m_xdirX.SetWindowText(_T("1.0"));
	m_xdirY.SetWindowText(_T("0.0"));
	m_xdirZ.SetWindowText(_T("0.0"));
	m_ydirX.SetWindowText(_T("0.0"));
	m_ydirY.SetWindowText(_T("1.0"));
	m_ydirZ.SetWindowText(_T("0.0"));

	m_ToolTip.Create(this);
    m_ToolTip.AddTool(GetDlgItem(IDC_IS_FREE), "평면 타입입니다. (False: 레퍼런스 평면 선택, True: 원점, X축, Y축 입력)");
    m_ToolTip.SetTipBkColor(RGB(0, 0, 0));
    m_ToolTip.SetTipTextColor(RGB(255, 255, 255));
	
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
	
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateDatumPlaneOffsetDialog::CreateFeature(void)
{
	DeSelectAll();
	
	CString _featureName;
	CString _referenceName;
	CString _distance;
	CString _isFlip;
	CString _isFree;
	CString _orgX, _orgY, _orgZ;
	CString _xdirX, _xdirY, _xdirZ;
	CString _ydirX, _ydirY, _ydirZ;

	m_featureName.GetWindowText(_featureName);
	m_referenceName.GetWindowText(_referenceName);
	m_distance.GetWindowText(_distance);
	m_isFlip.GetWindowText(_isFlip);
	m_isFree.GetWindowText(_isFree);

	m_orgX.GetWindowText(_orgX);
	m_orgY.GetWindowText(_orgY);
	m_orgZ.GetWindowText(_orgZ);
	m_xdirX.GetWindowText(_xdirX);
	m_xdirY.GetWindowText(_xdirY);
	m_xdirZ.GetWindowText(_xdirZ);
	m_ydirX.GetWindowText(_ydirX);
	m_ydirY.GetWindowText(_ydirY);
	m_ydirZ.GetWindowText(_ydirZ);

	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the plane name."));
		return false;
	}

	double distance = atof(_distance);
	double orgX = atof(_orgX);
	double orgY = atof(_orgY);
	double orgZ = atof(_orgZ);
	double xdirX = atof(_xdirX);
	double xdirY = atof(_xdirY);
	double xdirZ = atof(_xdirZ);
	double ydirX = atof(_ydirX);
	double ydirY = atof(_ydirY);
	double ydirZ = atof(_ydirZ);

	bool isFlip, isFree;

	if (_isFlip == _T("False"))
		isFlip = false;
	else if (_isFlip == _T("True"))
		isFlip = true;

	if (_isFree == _T("False"))
		isFree = false;
	else if (_isFree == _T("True"))
		isFree = true;

	PmeHReference hReferencePlane = 0;

	if (!isFree)
	{
		if (distance < 0.0)
		{
			AfxMessageBox(_T("Invalid input parameters."));
			return false;
		}
		
		if (_referenceName.IsEmpty())
		{
			AfxMessageBox(_T("Please select a reference plane."));
			return false;
		}
		
		if (_referenceName == _T("1 face selected"))
			PmePartAPI::SelectBrepByName(m_hPart, m_tempReferenceName, hReferencePlane);
		else
			PmePartAPI::SelectObjectByName(m_hPart, _referenceName, hReferencePlane);
	
		ASSERT(hReferencePlane);
	}

	if (m_isModified)
	{
		if (!isFree)
		{
			PmeStdDatumPlaneOffsetFeatureAPI::SetSelectedPlane(m_hFeature, hReferencePlane);
			PmeStdDatumPlaneOffsetFeatureAPI::SetDistance(m_hFeature, distance);
			PmeStdDatumPlaneOffsetFeatureAPI::SetFlip(m_hFeature, isFlip);
		}
		else
		{
			MrPosition org(orgX, orgY, orgZ);
			MrDirection xdir(xdirX, xdirY, xdirZ);
			MrDirection ydir(ydirX, ydirY, ydirZ);

			PmeStdDatumPlaneOffsetFeatureAPI::SetOrigin(m_hFeature, org);
			PmeStdDatumPlaneOffsetFeatureAPI::SetXDirection(m_hFeature, xdir);
			PmeStdDatumPlaneOffsetFeatureAPI::SetYDirection(m_hFeature, ydir);
			PmeStdDatumPlaneOffsetFeatureAPI::SetFlip(m_hFeature, isFlip);
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
		
		PmeHFeature hDatumPlane = 0;
		
		if (!isFree)
			PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, _featureName, hReferencePlane, distance, isFlip, hDatumPlane);
		else
			PmeStdDatumPlaneOffsetFeatureAPI::Create2(m_hPart, _featureName, orgX, orgY, orgZ, xdirX, xdirY, xdirZ, ydirX, ydirY, ydirZ, isFlip, hDatumPlane);

		ASSERT(hDatumPlane);
	}

	return true;
}

void PmCreateDatumPlaneOffsetDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeStdDatumPlaneOffsetFeature * pDatumPlane = (PmeStdDatumPlaneOffsetFeature *)pFeature;

	m_featureName.SetWindowText(pDatumPlane->GetName());
	m_featureName.EnableWindow(false);

	CString isFree;
	m_isFree.EnableWindow(false);

	if (!pDatumPlane->IsFree())
		m_isFree.SetCurSel(0);
	else
		m_isFree.SetCurSel(1);

	if (!pDatumPlane->IsFree())
	{
		if (pDatumPlane->GetSelectedPlane()->GetReferenceType() == PmeReferenceType_ExplicitModelObject)
			m_referenceName.SetWindowText(pDatumPlane->GetSelectedPlane()->GetReferenceeName());
		else if (pDatumPlane->GetSelectedPlane()->GetReferenceType() == PmeReferenceType_Brep)
		{
			m_tempReferenceName = pDatumPlane->GetSelectedPlane()->GetReferenceeName();
			m_referenceName.SetWindowText(_T("1 face selected"));
		}

		m_referenceName.EnableWindow(false);
	
		CString distance;
		distance.AppendFormat(_T("%f"), pDatumPlane->GetDistance());
		
		m_distance.SetWindowText(distance);
	}
	else
	{
		CString orgX, orgY, orgZ;
		CString xdirX, xdirY, xdirZ;
		CString ydirX, ydirY, ydirZ;

		orgX.AppendFormat(_T("%f"), pDatumPlane->GetOrigin().X());
		orgY.AppendFormat(_T("%f"), pDatumPlane->GetOrigin().Y());
		orgZ.AppendFormat(_T("%f"), pDatumPlane->GetOrigin().Z());
		xdirX.AppendFormat(_T("%f"), pDatumPlane->GetXDirection().X());
		xdirY.AppendFormat(_T("%f"), pDatumPlane->GetXDirection().Y());
		xdirZ.AppendFormat(_T("%f"), pDatumPlane->GetXDirection().Z());
		ydirX.AppendFormat(_T("%f"), pDatumPlane->GetYDirection().X());
		ydirY.AppendFormat(_T("%f"), pDatumPlane->GetYDirection().Y());
		ydirZ.AppendFormat(_T("%f"), pDatumPlane->GetYDirection().Z());

		m_orgX.SetWindowText(orgX);
		m_orgY.SetWindowText(orgY);
		m_orgZ.SetWindowText(orgZ);
		m_xdirX.SetWindowText(xdirX);
		m_xdirY.SetWindowText(xdirY);
		m_xdirZ.SetWindowText(xdirZ);
		m_ydirX.SetWindowText(ydirX);
		m_ydirY.SetWindowText(ydirY);
		m_ydirZ.SetWindowText(ydirZ);

		m_referenceName.SetWindowText(_T("N/A"));
	}

	CString isFlip;

	if (!pDatumPlane->IsFlip())
		m_isFlip.SetCurSel(0);
	else
		m_isFlip.SetCurSel(1);

	m_distance.SetFocus();

	OnCbnSelchangeIsFree();
}

void PmCreateDatumPlaneOffsetDialog::OnBnClickedSelectReferencePlane()
{
	if (m_referenceName.IsWindowEnabled())
	{
		m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
		
		if (m_selectedEntityNames.size() > 0)
		{
			if (m_selectedEntityNames.size() == 1)
			{
				m_referenceName.SetWindowText(_T("1 face selected"));
				m_tempReferenceName = m_selectedEntityNames[0];
			}
			else
			{
				AfxMessageBox(_T("Please select one face"));
				m_referenceName.SetWindowText(_T(""));
				m_tempReferenceName.Empty();
			}
		}
		else
		{
			CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
			CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
			PmFrame * pmFrame = (PmFrame *)pChild;
		
			HTREEITEM item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetSelectedItem();

			if (item && pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemText(item) != _T("Part"))
			{
				PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemData(item));
				
				if (pFeature->GetFeatureType() == PmeFeatureType_StdDefaultDatumPlaneFeature
					|| pFeature->GetFeatureType() == PmeFeatureType_StdDatumPlaneOffsetFeature)
					m_referenceName.SetWindowText(pFeature->GetName());
				else
					AfxMessageBox(_T("Please select a plane"));
			}	
		}

		m_pOperator->DeselectAll();
	}
}

void PmCreateDatumPlaneOffsetDialog::OnCbnSelchangeIsFree()
{
	if (m_isFree.GetCurSel() == 0)
	{
		m_orgX.EnableWindow(false);
		m_orgY.EnableWindow(false);
		m_orgZ.EnableWindow(false);
		m_xdirX.EnableWindow(false);
		m_xdirY.EnableWindow(false);
		m_xdirZ.EnableWindow(false);
		m_ydirX.EnableWindow(false);
		m_ydirY.EnableWindow(false);
		m_ydirZ.EnableWindow(false);
		m_referenceName.EnableWindow(true);
		m_distance.EnableWindow(true);
	}
	else if (m_isFree.GetCurSel() == 1)
	{
		m_orgX.EnableWindow(true);
		m_orgY.EnableWindow(true);
		m_orgZ.EnableWindow(true);
		m_xdirX.EnableWindow(true);
		m_xdirY.EnableWindow(true);
		m_xdirZ.EnableWindow(true);
		m_ydirX.EnableWindow(true);
		m_ydirY.EnableWindow(true);
		m_ydirZ.EnableWindow(true);
		m_referenceName.EnableWindow(false);
		m_distance.EnableWindow(false);
	}
}

BOOL PmCreateDatumPlaneOffsetDialog::PreTranslateMessage(MSG* pMsg)
{
	m_ToolTip.RelayEvent(pMsg);
    return CDialog::PreTranslateMessage(pMsg);
}