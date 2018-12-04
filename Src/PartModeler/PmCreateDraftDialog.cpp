// PmCreateDraftDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PmCreateDraftDialog.h"
#include ".\PmViewSelectionOperator.h"
#include "PmView.h"
#include "..\PartModelingEngine\PmeStdSolidDraftFeature.h"

// PmCreateDraftDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateDraftDialog, PmCreateFeatureDialog)

PmCreateDraftDialog::PmCreateDraftDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: PmCreateFeatureDialog(pView)
{
	m_pOperator = new PmViewSelectionOperator(m_pView->GetHView());
	m_pView->SetOperator(m_pOperator);

	m_pOperator->OnFace();
}

PmCreateDraftDialog::~PmCreateDraftDialog()
{
}

void PmCreateDraftDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURE_NAME, m_featureName);
	DDX_Control(pDX, IDC_DRAFT_ANGLE, m_draftAngle);
	DDX_Control(pDX, IDC_PULLING_ORIGIN_X, m_pullingOrgX);
	DDX_Control(pDX, IDC_PULLING_ORIGIN_Y, m_pullingOrgY);
	DDX_Control(pDX, IDC_PULLING_ORIGIN_Z, m_pullingOrgZ);
	DDX_Control(pDX, IDC_PULLING_DIRECTION_X, m_pullingDirX);
	DDX_Control(pDX, IDC_PULLING_DIRECTION_Y, m_pullingDirY);
	DDX_Control(pDX, IDC_PULLING_DIRECTION_Z, m_pullingDirZ);
}


BEGIN_MESSAGE_MAP(PmCreateDraftDialog, PmCreateFeatureDialog)
END_MESSAGE_MAP()


// PmCreateDraftDialog 메시지 처리기입니다.

BOOL PmCreateDraftDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_featureName.SetWindowText(GetNewFeatureName(PmeFeatureType_StdSolidDraftFeature));
	m_featureName.SetFocus();
	m_draftAngle.SetWindowText(_T("5.0"));
	m_pullingOrgX.SetWindowText(_T("0.0"));
	m_pullingOrgY.SetWindowText(_T("0.0"));
	m_pullingOrgZ.SetWindowText(_T("0.0"));
	m_pullingDirX.SetWindowText(_T("0.0"));
	m_pullingDirY.SetWindowText(_T("0.0"));
	m_pullingDirZ.SetWindowText(_T("1.0"));
	
	RECT  rectParent;
	CPoint pos;
	(::AfxGetMainWnd())->GetWindowRect(&rectParent);
 
	pos.x = rectParent.left + 210;
	pos.y = rectParent.top + 80;
	SetWindowPos(NULL, pos.x ,pos.y, 0, 0, SWP_NOSIZE);
	
	return FALSE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

bool PmCreateDraftDialog::CreateFeature(void)
{
	DeSelectAll();
	m_selectedEntityNames = m_pOperator->GetSelectedEntityNames();
		
	CString _featureName;
	CString _draftAngle;
	CString _orgX;
	CString _orgY;
	CString _orgZ;
	CString _dirX;
	CString _dirY;
	CString _dirZ;

	m_featureName.GetWindowText(_featureName);
	m_draftAngle.GetWindowText(_draftAngle);
	m_pullingOrgX.GetWindowText(_orgX);
	m_pullingOrgY.GetWindowText(_orgY);
	m_pullingOrgZ.GetWindowText(_orgZ);
	m_pullingDirX.GetWindowText(_dirX);
	m_pullingDirY.GetWindowText(_dirY);
	m_pullingDirZ.GetWindowText(_dirZ);
	
	if (_featureName.IsEmpty())
	{
		AfxMessageBox(_T("Enter the fillet name."));
		return false;
	}

	double draftAngle = atof(_draftAngle);
	double orgX = atof(_orgX);
	double orgY = atof(_orgY);
	double orgZ = atof(_orgZ);
	double dirX = atof(_dirX);
	double dirY = atof(_dirY);
	double dirZ = atof(_dirZ);

	MrAxis1 pullingDirection(MrPosition(orgX, orgY, orgZ), MrDirection(dirX, dirY, dirZ));

	if (draftAngle < 0)
	{
		AfxMessageBox(_T("The angle should be greater than zero."));
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
		PmeStdSolidDraftFeature * pDraft = (PmeStdSolidDraftFeature *)pFeature;
		
		if (m_selectedEntityNames.size() == 0)
			hReferenceFaces = PME_REFERENCES2HANDLE(pDraft->GetTargetFaces());
		
		PmeStdSolidDraftFeatureAPI::GetTargetFaces(m_hFeature, hReferenceFaces);
		PmeStdSolidDraftFeatureAPI::SetDraftAngle(m_hFeature, draftAngle);
		PmeStdSolidDraftFeatureAPI::SetPullingDirection(m_hFeature, pullingDirection);

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

		PmeHFeature hDraftFeature = 0;
		PmeStdSolidDraftFeatureAPI::Create(m_hPart, _featureName, hReferenceFaces, pullingDirection, draftAngle, hDraftFeature);
		ASSERT(hDraftFeature);
	}
	
	return true;
}

void PmCreateDraftDialog::SetParameters(PmeFeature * pFeature)
{
	m_isModified = true;
	m_hFeature = PME_FEATURE2HANDLE(pFeature);

	PmeStdSolidDraftFeature * pDraft = (PmeStdSolidDraftFeature *)pFeature;

	m_featureName.SetWindowText(pDraft->GetName());
	m_featureName.EnableWindow(false);

	CString draftAngle;
	CString orgX, orgY, orgZ, dirX, dirY, dirZ;

	draftAngle.AppendFormat(_T("%f"), pDraft->GetDraftAngle());
	orgX.AppendFormat(_T("%f"), pDraft->GetPullingDirection().Location().X());
	orgY.AppendFormat(_T("%f"), pDraft->GetPullingDirection().Location().Y());
	orgZ.AppendFormat(_T("%f"), pDraft->GetPullingDirection().Location().Z());
	dirX.AppendFormat(_T("%f"), pDraft->GetPullingDirection().Direction().X());
	dirY.AppendFormat(_T("%f"), pDraft->GetPullingDirection().Direction().Y());
	dirZ.AppendFormat(_T("%f"), pDraft->GetPullingDirection().Direction().Z());
	
	m_draftAngle.SetWindowText(draftAngle);
	m_pullingOrgX.SetWindowText(orgX);
	m_pullingOrgY.SetWindowText(orgY);
	m_pullingOrgZ.SetWindowText(orgZ);
	m_pullingDirX.SetWindowText(dirX);
	m_pullingDirY.SetWindowText(dirY);
	m_pullingDirZ.SetWindowText(dirZ);

	m_draftAngle.SetFocus();
}