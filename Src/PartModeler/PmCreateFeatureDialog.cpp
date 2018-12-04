
#include "stdafx.h"
#include "PmCreateFeatureDialog.h"
#include "PmView.h"
#include "PmDocument.h"
#include "PmHSelectionSet.h"
#include "PmViewManipulationOperator.h"
// PmCreateFeatureDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(PmCreateFeatureDialog, CDialog)
PmCreateFeatureDialog::PmCreateFeatureDialog(PmView * pView, CWnd* pParent /*=NULL*/)
	: CDialog(PmCreateFeatureDialog::IDD, pParent)
	, m_pView(pView)
	, m_isModified(false)
{
	m_hPart = pView->GetDocument()->GetPart();
}

PmCreateFeatureDialog::~PmCreateFeatureDialog()
{
	OnBnClickedCancel();
}

BEGIN_MESSAGE_MAP(PmCreateFeatureDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOK)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


void PmCreateFeatureDialog::OnBnClickedOK()
{
	if (CreateFeature())
	{
		OnBnClickedCancel();
	}
}

void PmCreateFeatureDialog::OnBnClickedCancel()
{
	DeSelectAll();
	DestroyWindow();
	m_pView->SetOperator(new PmViewManipulationOperator(m_pView->GetHView()));
}

bool PmCreateFeatureDialog::CheckFeatureExistence(CString pName)
{
	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	int size = 0;
	PmeFeaturesAPI::GetSize(hFeatures, size);

	for (int i = 0; i < size; ++i)
	{
		PmeHFeature hFeature;
		PmeFeaturesAPI::GetItem(hFeatures, i, hFeature);
		
		CString name;
		PmeFeatureAPI::GetName(hFeature, name);

		if (pName == name)
			return true;
	}

	return false;
}

void PmCreateFeatureDialog::DeSelectAll(void)
{
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(m_pView->GetHoopsView()->GetSelection());
	pSelection->DeSelectAll();
}

void PmCreateFeatureDialog::UpdateAll(void)
{
	m_pView->GetDocument()->UpdateAll();
}

// 특징형상 새로 생성 시, 타입 별로 이름을 자동으로 생성
CString PmCreateFeatureDialog::GetNewFeatureName(PmeFeatureType type)
{
	CString name;

	if (type == PmeFeatureType_StdSolidProtrusionExtrudeFeature)
		name = "ProExtrude";
	else if (type == PmeFeatureType_StdSolidCutExtrudeFeature)
		name = "CutExtrude";
	else if (type == PmeFeatureType_StdSolidFilletConstantFeature)
		name = "Fillet";
	else if (type == PmeFeatureType_StdSolidChamferFeature)
		name = "Chamfer";
	else if (type == PmeFeatureType_StdSolidProtrusionSweepFeature)
		name = "ProSweep";
	else if (type == PmeFeatureType_StdSolidCutSweepFeature)
		name = "CutSweep";
	else if (type == PmeFeatureType_StdSolidProtrusionRevolveFeature)
		name = "ProRevolve";
	else if (type == PmeFeatureType_StdSolidCutRevolveFeature)
		name = "CutRevolve";
	else if (type == PmeFeatureType_StdSolidOperatePatternRectangularFeature)
		name = "RectPattern";
	else if (type == PmeFeatureType_StdSolidOperatePatternCircularFeature)
		name = "CircPattern";
	else if (type == PmeFeatureType_StdSolidHoleCounterboredFeature)
		name = "HoleCounterbored";
	else if (type == PmeFeatureType_StdSolidHoleCountersunkFeature)
		name = "HoleCountersunk";
	else if (type == PmeFeatureType_StdSolidHoleSimpleFeature)
		name = "HoleSimple";
	else if (type == PmeFeatureType_StdDatumPlaneOffsetFeature)
		name = "Plane";
	else if (type == PmeFeatureType_StdSolidShellFeature)
		name = "Shell";
	else if (type == PmeFeatureType_StdSolidDraftFeature)
		name = "Draft";
	else if (type == PmeFeatureType_StdSolidOffsetFeature)
		name = "Offset";

	PmePart * pPart = PME_HANDLE2PART(m_hPart);
	
	int count = 1;
	for (int i = 1; i < pPart->GetFeatures()->GetSize(); ++i)
	{
		if (pPart->GetFeatures()->GetItem(i)->GetFeatureType() == type)
			count++;
	}

	name.AppendFormat(_T("%d"), count);

	return name;
}