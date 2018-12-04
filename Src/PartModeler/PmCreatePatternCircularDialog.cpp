// PmCreateExtrudeDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreatePatternCircularDialog.h"
#include "..\PartModelingEngine\PmeStdSolidOperatePatternCircularFeature.h"
#include "PmView.h"

// PmCreateExtrudeDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreatePatternCircularDialog, PmCreateFeatureDialog)

PmCreatePatternCircularDialog::PmCreatePatternCircularDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pView->SetOperator(new HOpCameraManipulate(m_pView->GetHView()));
}

PmCreatePatternCircularDialog::~PmCreatePatternCircularDialog()
{
}

void PmCreatePatternCircularDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_TARGET_FEATURES, m_targetFeatures);
	DDX_Control(pDX, IDC_AXIS_ORIGIN_X, m_axisOrgX);
	DDX_Control(pDX, IDC_AXIS_ORIGIN_Y, m_axisOrgY);
	DDX_Control(pDX, IDC_AXIS_ORIGIN_Z, m_axisOrgZ);
	DDX_Control(pDX, IDC_AXIS_DIRECTION_X, m_axisDirX);
	DDX_Control(pDX, IDC_AXIS_DIRECTION_Y, m_axisDirY);
	DDX_Control(pDX, IDC_AXIS_DIRECTION_Z, m_axisDirZ);
	DDX_Control(pDX, IDC_ANGULAR_NUMBER, m_angNumber);
	DDX_Control(pDX, IDC_ANGULAR_INCREMENT, m_angIncrement);
	DDX_Control(pDX, IDC_RADIAL_NUMBER, m_radNumber);
	DDX_Control(pDX, IDC_RADIAL_SPACING, m_radSpacing);
	DDX_Control(pDX, IDC_IS_RADIALLY_ALIGNED, m_isRadiallyAligned);
}

BEGIN_MESSAGE_MAP(PmCreatePatternCircularDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_SELECT_TARGET_FEATURES, OnBnClickedSelectTargetFeatures)
END_MESSAGE_MAP()


// PmCreateExtrudeDialog 메시지 처리기입니다.

BOOL PmCreatePatternCircularDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidOperatePatternCircularFeature));
	m_featureName.SetFocus();

	m_axisOrgX.SetWindowText(_T("0.0"));
	m_axisOrgY.SetWindowText(_T("0.0"));
	m_axisOrgZ.SetWindowText(_T("0.0"));
	m_axisDirX.SetWindowText(_T("0.0"));
	m_axisDirY.SetWindowText(_T("0.0"));
	m_axisDirZ.SetWindowText(_T("1.0"));
	m_angNumber.SetWindowText(_T("2"));
	m_angIncrement.SetWindowText(_T("45.0"));
	m_radNumber.SetWindowText(_T("1"));
	m_radSpacing.SetWindowText(_T("20.0"));
	
	m_isRadiallyAligned.AddString(_T("False"));
	m_isRadiallyAligned.AddString(_T("True"));
	m_isRadiallyAligned.SetCurSel(1);

	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreatePatternCircularDialog::CreateFeature(void)
{
	DeSelectAll();
	
	CString _featureName;
	CString _targetFeatures;
	CString _axisOrgX;
	CString _axisOrgY;
	CString _axisOrgZ;
	CString _axisDirX;
	CString _axisDirY;
	CString _axisDirZ;
	CString _angNumber;
	CString _angIncrement;
	CString _radNumber;
	CString _radSpacing;
	CString _isRadiallyAligned;

	m_featureName.GetWindowText(_featureName);
	m_targetFeatures.GetWindowText(_targetFeatures);
	m_axisOrgX.GetWindowText(_axisOrgX);
	m_axisOrgY.GetWindowText(_axisOrgY);
	m_axisOrgZ.GetWindowText(_axisOrgZ);
	m_axisDirX.GetWindowText(_axisDirX);
	m_axisDirY.GetWindowText(_axisDirY);
	m_axisDirZ.GetWindowText(_axisDirZ);
	m_angNumber.GetWindowText(_angNumber);
	m_angIncrement.GetWindowText(_angIncrement);
	m_radNumber.GetWindowText(_radNumber);
	m_radSpacing.GetWindowText(_radSpacing);
	m_isRadiallyAligned.GetWindowText(_isRadiallyAligned);
	
	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the rectangular pattern name."));
		return false;
	}

	if (_targetFeatures.IsEmpty())
	{
		AfxMessageBox(_T("Select target features."));
		return false;
	}
	else if (_targetFeatures == _featureName)
	{
		AfxMessageBox(_T("Please select another target features."));
		return false;
	}

	double axisOrgX = atof(_axisOrgX);
	double axisOrgY = atof(_axisOrgY);
	double axisOrgZ = atof(_axisOrgZ);
	double axisDirX = atof(_axisDirX);
	double axisDirY = atof(_axisDirY);
	double axisDirZ = atof(_axisDirZ);
	int angNumber = atoi(_angNumber);
	double angIncrement = atof(_angIncrement);
	int radNumber = atoi(_radNumber);
	double radSpacing = atof(_radSpacing);

	bool isRadiallyAligned;

	if (_isRadiallyAligned == _T("False"))
		isRadiallyAligned = false;
	else if (_isRadiallyAligned == _T("True"))
		isRadiallyAligned = true;

	MrAxis1 axis;
	axis.SetLocation(MrPosition(axisOrgX, axisOrgY, axisOrgZ));
	axis.SetDirection(MrDirection(axisDirX, axisDirY, axisDirZ));
	
	if (angNumber < 1.0 || radNumber < 1.0											// 인스턴스가 1개 이하일 때
		|| (angNumber == 1.0 && radNumber == 1.0)									// 두 방향의 인스턴스가 모두 1개 일 때
		|| angIncrement < 0.0 || radSpacing < 0.0									// Spacing이 0 이하일 때
		|| (angIncrement == 0.0 && radSpacing == 0.0)								// 두 뱡항의 Spacing이 모두 0일 때
		|| (axisOrgX == axisDirX && axisOrgY == axisDirY && axisOrgZ == axisDirZ)	// 원점과 방향이 같을 때
		|| (axisDirX == 0 && axisDirY == 0 && axisDirZ == 0))						// 방향이 없을 때
	{
		AfxMessageBox(_T("Invalid input parameters."));
		return false;
	}

	PmeHReferences hTargetFeatures = 0;
	PmeReferencesAPI::Create(hTargetFeatures);

	for (int i = 0; i < (int)m_targetFeatureNames.size(); ++i)
	{
		PmeHReference hTargetFeature = 0;

		if (m_targetFeatureNames[i] == _T("PartBody"))
			PmePartAPI::SelectObjectByName(m_hPart, m_targetFeatureNames[i], hTargetFeature);
		else
			PmePartAPI::SelectFeatureByName(m_hPart, m_targetFeatureNames[i], hTargetFeature);
		
		ASSERT(hTargetFeature);
	
		PmeReferencesAPI::AddItem(hTargetFeatures, hTargetFeature);
	}

	if (m_isModified)
	{
		PmeStdSolidOperatePatternCircularFeatureAPI::SetTargetFeatures(m_hFeature, hTargetFeatures);
		PmeStdSolidOperatePatternCircularFeatureAPI::SetCenterAxis(m_hFeature, axis);
		PmeStdSolidOperatePatternCircularFeatureAPI::SetAngleNumber(m_hFeature, angNumber);
		PmeStdSolidOperatePatternCircularFeatureAPI::SetAngleIncrement(m_hFeature, angIncrement);
		PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialNumber(m_hFeature, radNumber);
		PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialSpacing(m_hFeature, radSpacing);
		PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialAlignment(m_hFeature, isRadiallyAligned);

		UpdateAll();
	}
	else
	{
		if (m_targetFeatureNames.size() == 0)
		{
			AfxMessageBox(_T("Select more than one feature first."));
			return false;
		}

		if (CheckFeatureExistence(_featureName))
		{
			AfxMessageBox(_T("Please enter another name."));
			return false;
		}
		
		PmeHFeature hPatternCircularFeature = 0;
		PmeStdSolidOperatePatternCircularFeatureAPI::Create(m_hPart, _featureName, hTargetFeatures, axis, angNumber, angIncrement, radNumber, radSpacing, isRadiallyAligned, hPatternCircularFeature);	
		ASSERT(hPatternCircularFeature);
	}

	return true;
}

void PmCreatePatternCircularDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);
	
	PmeStdSolidOperatePatternCircularFeature * pPatternCircular = (PmeStdSolidOperatePatternCircularFeature *)pFeature;

	m_featureName.SetWindowText(pPatternCircular->GetName());
	m_featureName.EnableWindow(false);

	CString _targetFeatures;

	if (pPatternCircular->GetTargetFeatures()->GetSize() == 1)
	{
		m_targetFeatureNames.push_back(pPatternCircular->GetTargetFeatures()->GetItem(0)->GetReferenceeName());
		
		_targetFeatures.AppendFormat(m_targetFeatureNames[0]);
		m_targetFeatures.SetWindowText(_targetFeatures);
	}
	else
	{
		for (int i = 0; i < pPatternCircular->GetTargetFeatures()->GetSize(); ++i)
			m_targetFeatureNames.push_back(pPatternCircular->GetTargetFeatures()->GetItem(i)->GetReferenceeName());
		
		_targetFeatures.AppendFormat(_T("%d selected"), m_targetFeatureNames.size());
		m_targetFeatures.SetWindowText(_targetFeatures);
	}

	m_targetFeatures.EnableWindow(false);

	CString axisOrgX, axisOrgY, axisOrgZ, axisDirX, axisDirY, axisDirZ;
	CString angNumber, angIncrement, radNumber, radSpacing;

	axisOrgX.AppendFormat(_T("%f"), pPatternCircular->GetCenterAxis().Location().X());
	axisOrgY.AppendFormat(_T("%f"), pPatternCircular->GetCenterAxis().Location().Y());
	axisOrgZ.AppendFormat(_T("%f"), pPatternCircular->GetCenterAxis().Location().Z());
	axisDirX.AppendFormat(_T("%f"), pPatternCircular->GetCenterAxis().Direction().X());
	axisDirY.AppendFormat(_T("%f"), pPatternCircular->GetCenterAxis().Direction().Y());
	axisDirZ.AppendFormat(_T("%f"), pPatternCircular->GetCenterAxis().Direction().Z());
	
	angNumber.AppendFormat(_T("%d"), pPatternCircular->GetAngleNumber());
	angIncrement.AppendFormat(_T("%f"), pPatternCircular->GetAngleIncrement());
	radNumber.AppendFormat(_T("%d"), pPatternCircular->GetRadialNumber());
	radSpacing.AppendFormat(_T("%f"), pPatternCircular->GetRadialSpacing());


	m_axisOrgX.SetWindowText(axisOrgX);
	m_axisOrgY.SetWindowText(axisOrgY);
	m_axisOrgZ.SetWindowText(axisOrgZ);
	m_axisDirX.SetWindowText(axisDirX);
	m_axisDirY.SetWindowText(axisDirY);
	m_axisDirZ.SetWindowText(axisDirZ);
	m_angNumber.SetWindowText(angNumber);
	m_angIncrement.SetWindowText(angIncrement);
	m_radNumber.SetWindowText(radNumber);
	m_radSpacing.SetWindowText(radSpacing);
		
	CString isRadiallyAligned;

	if (!pPatternCircular->IsRadialAnignment())
		m_isRadiallyAligned.SetCurSel(0);
	else
		m_isRadiallyAligned.SetCurSel(1);

	m_isRadiallyAligned.SetFocus();
}

void PmCreatePatternCircularDialog::OnBnClickedSelectTargetFeatures()
{
	if (m_targetFeatures.IsWindowEnabled())
	{
		CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
		CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
		PmFrame * pmFrame = (PmFrame *)pChild;

		HTREEITEM item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetSelectedItem();

		m_targetFeatureNames.clear();

		while (item)
		{
			if (pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemText(item) == _T("Part"))
				m_targetFeatureNames.push_back(_T("PartBody"));
			else
			{
				PmeFeature * pFeature = reinterpret_cast<PmeFeature *>(pmFrame->GetFeatureTree()->GetTreeCtrl().GetItemData(item));

				if (pFeature)
				{
					if (pFeature->GetFeatureType() == PmeFeatureType_StdSketchFeature
						|| pFeature->GetFeatureType() == PmeFeatureType_StdDefaultDatumPlaneFeature
						|| pFeature->GetFeatureType() == PmeFeatureType_StdDatumPlaneOffsetFeature)
					{
						AfxMessageBox(_T("You cannot select a sketch or a plane."));
						m_targetFeatureNames.clear();
						break;
					}
					else
					{
						m_targetFeatureNames.push_back(pFeature->GetName());
					}
				}
			}

			item = pmFrame->GetFeatureTree()->GetTreeCtrl().GetNextSelectedItem(item);
		}

		CString _targetFeatures;

		if (m_targetFeatureNames.size() == 1)
		{
			_targetFeatures.AppendFormat(m_targetFeatureNames[0]);
			m_targetFeatures.SetWindowText(_targetFeatures);
		}
		else
		{
			_targetFeatures.AppendFormat(_T("%d selected"), m_targetFeatureNames.size());
			m_targetFeatures.SetWindowText(_targetFeatures);
		}
	}
}