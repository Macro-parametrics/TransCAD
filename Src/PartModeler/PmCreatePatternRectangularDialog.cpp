// PmCreateExtrudeDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreatePatternRectangularDialog.h"
#include "..\PartModelingEngine\PmeStdSolidOperatePatternRectangularFeature.h"
#include "PmView.h"

// PmCreateExtrudeDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreatePatternRectangularDialog, PmCreateFeatureDialog)

PmCreatePatternRectangularDialog::PmCreatePatternRectangularDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pView->SetOperator(new HOpCameraManipulate(m_pView->GetHView()));
}

PmCreatePatternRectangularDialog::~PmCreatePatternRectangularDialog()
{
}

void PmCreatePatternRectangularDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_TARGET_FEATURES, m_targetFeatures);
	DDX_Control(pDX, IDC_ROW_DIRECTION_X, m_rowDirX);
	DDX_Control(pDX, IDC_ROW_DIRECTION_Y, m_rowDirY);
	DDX_Control(pDX, IDC_ROW_DIRECTION_Z, m_rowDirZ);
	DDX_Control(pDX, IDC_COLUMN_DIRECTION_X, m_colDirX);
	DDX_Control(pDX, IDC_COLUMN_DIRECTION_Y, m_colDirY);
	DDX_Control(pDX, IDC_COLUMN_DIRECTION_Z, m_colDirZ);
	DDX_Control(pDX, IDC_ROW_INSTANCE_NUMBER, m_rowNumber);
	DDX_Control(pDX, IDC_ROW_INSTANCE_SPACING, m_rowSpacing);
	DDX_Control(pDX, IDC_COLUMN_INSTANCE_NUMBER, m_colNumber);
	DDX_Control(pDX, IDC_COLUMN_INSTANCE_SPACING, m_colSpacing);
}

BEGIN_MESSAGE_MAP(PmCreatePatternRectangularDialog, PmCreateFeatureDialog)
	ON_BN_CLICKED(IDC_SELECT_TARGET_FEATURES, OnBnClickedSelectTargetFeatures)
END_MESSAGE_MAP()


// PmCreateExtrudeDialog 메시지 처리기입니다.

BOOL PmCreatePatternRectangularDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidOperatePatternRectangularFeature));
	m_featureName.SetFocus();

	m_rowDirX.SetWindowText(_T("1.0"));
	m_rowDirY.SetWindowText(_T("0.0"));
	m_rowDirZ.SetWindowText(_T("0.0"));
	m_colDirX.SetWindowText(_T("0.0"));
	m_colDirY.SetWindowText(_T("1.0"));
	m_colDirZ.SetWindowText(_T("0.0"));
	m_rowNumber.SetWindowText(_T("2"));
	m_rowSpacing.SetWindowText(_T("20.0"));
	m_colNumber.SetWindowText(_T("1"));
	m_colSpacing.SetWindowText(_T("20.0"));
	
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);

	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreatePatternRectangularDialog::CreateFeature(void)
{
	DeSelectAll();
	
	CString _featureName;
	CString _targetFeatures;
	CString _rowDirX;
	CString _rowDirY;
	CString _rowDirZ;
	CString _colDirX;
	CString _colDirY;
	CString _colDirZ;
	CString _rowNumber;
	CString _rowSpacing;
	CString _colNumber;
	CString _colSpacing;

	m_featureName.GetWindowText(_featureName);
	m_targetFeatures.GetWindowText(_targetFeatures);
	m_rowDirX.GetWindowText(_rowDirX);
	m_rowDirY.GetWindowText(_rowDirY);
	m_rowDirZ.GetWindowText(_rowDirZ);
	m_colDirX.GetWindowText(_colDirX);
	m_colDirY.GetWindowText(_colDirY);
	m_colDirZ.GetWindowText(_colDirZ);
	m_rowNumber.GetWindowText(_rowNumber);
	m_rowSpacing.GetWindowText(_rowSpacing);
	m_colNumber.GetWindowText(_colNumber);
	m_colSpacing.GetWindowText(_colSpacing);

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

	double rowDirX = atof(_rowDirX);
	double rowDirY = atof(_rowDirY);
	double rowDirZ = atof(_rowDirZ);
	double colDirX = atof(_colDirX);
	double colDirY = atof(_colDirY);
	double colDirZ = atof(_colDirZ);
	int rowNumber = atoi(_rowNumber);
	double rowSpacing = atof(_rowSpacing);
	int colNumber = atoi(_colNumber);
	double colSpacing = atof(_colSpacing);

	MrDirection rowDir, colDir;
	rowDir.SetCoordinates(rowDirX, rowDirY, rowDirZ);
	colDir.SetCoordinates(colDirX, colDirY, colDirZ);
		
	if (rowNumber < 1.0 || colNumber < 1.0									// 인스턴스가 1개 이하일 때
		|| (rowNumber == 1.0 && colNumber == 1.0)							// 두 방향의 인스턴스가 모두 1개 일 때
		|| rowSpacing < 0.0 || colSpacing < 0.0								// Spacing이 0 이하일 때
		|| (rowSpacing == 0.0 && colSpacing == 0.0)							// 두 뱡항의 Spacing이 모두 0일 때
		|| (rowDirX == colDirX && rowDirY == colDirY && rowDirZ == colDirZ)	// 두 방향이 같을 때
		|| (rowDirX == 0 && rowDirY == 0 && rowDirZ == 0)					// Row 방향이 없을 때
		|| (colDirX == 0 && colDirY == 0 && colDirZ == 0))					// Column 방향이 없을 때
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
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetTargetFeatures(m_hFeature, hTargetFeatures);
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowDirection(m_hFeature, rowDir);
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowNumber(m_hFeature, rowNumber);
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetRowSpacing(m_hFeature, rowSpacing);
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnDirection(m_hFeature, colDir);
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnNumber(m_hFeature, colNumber);
		PmeStdSolidOperatePatternRectangularFeatureAPI::SetColumnSpacing(m_hFeature, colSpacing);

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
		
		PmeHFeature hPatternRectangularFeature = 0;
		PmeStdSolidOperatePatternRectangularFeatureAPI::Create(m_hPart, _featureName, hTargetFeatures, colSpacing, colDir, colNumber, rowSpacing, rowDir, rowNumber, hPatternRectangularFeature);	
		ASSERT(hPatternRectangularFeature);
	}

	return true;
}

void PmCreatePatternRectangularDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);
	
	PmeStdSolidOperatePatternRectangularFeature * pPatternRectangular = (PmeStdSolidOperatePatternRectangularFeature *)pFeature;

	m_featureName.SetWindowText(pPatternRectangular->GetName());
	m_featureName.EnableWindow(false);

	CString _targetFeatures;

	if (pPatternRectangular->GetTargetFeatures()->GetSize() == 1)
	{
		m_targetFeatureNames.push_back(pPatternRectangular->GetTargetFeatures()->GetItem(0)->GetReferenceeName());
		
		_targetFeatures.AppendFormat(m_targetFeatureNames[0]);
		m_targetFeatures.SetWindowText(_targetFeatures);
	}
	else
	{
		for (int i = 0; i < pPatternRectangular->GetTargetFeatures()->GetSize(); ++i)
			m_targetFeatureNames.push_back(pPatternRectangular->GetTargetFeatures()->GetItem(i)->GetReferenceeName());
		
		_targetFeatures.AppendFormat(_T("%d selected"), m_targetFeatureNames.size());
		m_targetFeatures.SetWindowText(_targetFeatures);
	}

	m_targetFeatures.EnableWindow(false);

	CString rowDirX, rowDirY, rowDirZ, colDirX, colDirY, colDirZ;
	CString rowNumber, rowSpacing, colNumber, colSpacing;

	rowDirX.AppendFormat(_T("%f"), pPatternRectangular->GetRowDirection().X());
	rowDirY.AppendFormat(_T("%f"), pPatternRectangular->GetRowDirection().Y());
	rowDirZ.AppendFormat(_T("%f"), pPatternRectangular->GetRowDirection().Z());
	colDirX.AppendFormat(_T("%f"), pPatternRectangular->GetColumnDirection().X());
	colDirY.AppendFormat(_T("%f"), pPatternRectangular->GetColumnDirection().Y());
	colDirZ.AppendFormat(_T("%f"), pPatternRectangular->GetColumnDirection().Z());
	
	rowNumber.AppendFormat(_T("%d"), pPatternRectangular->GetRowNumber());
	rowSpacing.AppendFormat(_T("%f"), pPatternRectangular->GetRowSpacing());
	colNumber.AppendFormat(_T("%d"), pPatternRectangular->GetColumnNumber());
	colSpacing.AppendFormat(_T("%f"), pPatternRectangular->GetColumnSpacing());
	
	m_rowDirX.SetWindowText(rowDirX);
	m_rowDirY.SetWindowText(rowDirY);
	m_rowDirZ.SetWindowText(rowDirZ);
	m_colDirX.SetWindowText(colDirX);
	m_colDirY.SetWindowText(colDirY);
	m_colDirZ.SetWindowText(colDirZ);
	m_rowNumber.SetWindowText(rowNumber);
	m_rowSpacing.SetWindowText(rowSpacing);
	m_colNumber.SetWindowText(colNumber);
	m_colSpacing.SetWindowText(colSpacing);

	m_rowNumber.SetFocus();
}

void PmCreatePatternRectangularDialog::OnBnClickedSelectTargetFeatures()
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