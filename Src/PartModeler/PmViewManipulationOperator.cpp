#include "StdAfx.h"
#include "PmViewManipulationOperator.h"
#include "PmHSelectionSet.h"
#include "PmView.h"
#include "PmeFeatureTagMarker.h"

#include "PmCreateChamferDialog.h"
#include "PmCreateEdgeFilletDialog.h"
#include "PmCreateShellDialog.h"
#include "PmCreateOffsetDialog.h"
#include "PmCreateDraftDialog.h"
#include "PmCreateExtrudeDialog.h"
#include "PmCreateRevolveDialog.h"
#include "PmCreateSweepDialog.h"
#include "PmCreateHoleDialog.h"
#include "PmCreatePatternRectangularDialog.h"
#include "PmCreatePatternCircularDialog.h"
#include "PmCreateDatumPlaneOffsetDialog.h"

PmViewManipulationOperator::PmViewManipulationOperator(HBaseView* view, int DoRepeat, int DoCapture)
	: HOpCameraManipulate(view, DoRepeat, DoCapture)
{
	m_isPrevRenderMode = false;

	m_pSelection = new HOpSelectAperture(view, DoRepeat, DoCapture);
	OnFace();
}

PmViewManipulationOperator::~PmViewManipulationOperator(void)
{
	delete m_pSelection;
}

int PmViewManipulationOperator::OnLButtonDownAndMove(HEventInfo & event)
{
	if (m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}
	
	return HOpCameraManipulate::OnLButtonDownAndMove(event);
}

int PmViewManipulationOperator::OnLButtonUp(HEventInfo & event)
{
	if(!m_bOpStarted)
		return HBaseOperator::OnLButtonDownAndMove(event);

	if(m_isPrevRenderMode )
	{
		m_isPrevRenderMode = false;
		m_pView->SetRenderMode(m_prevRenderMode);
	}

	m_pView->CameraPositionChanged(true, true);

 	m_pView->Update();
	m_bOpStarted = false;

    return(HOP_READY);
}

int PmViewManipulationOperator::OnMButtonDownAndMove(HEventInfo & event)
{
	if (m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}
	
	return HOpCameraManipulate::OnMButtonDownAndMove(event);
}

int PmViewManipulationOperator::OnMButtonUp(HEventInfo & event)
{
	if(!m_bOpStarted)
		return HBaseOperator::OnMButtonDownAndMove(event);

	if(m_isPrevRenderMode )
	{
		m_isPrevRenderMode = false;
		m_pView->SetRenderMode(m_prevRenderMode);
	}

	m_pView->CameraPositionChanged(true, true);

 	m_pView->Update();
	m_bOpStarted = false;

    return(HOP_READY);
}

int PmViewManipulationOperator::OnRButtonDownAndMove(HEventInfo & event)
{
	if (m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}
	
	return HOpCameraManipulate::OnRButtonDownAndMove(event);
}

int PmViewManipulationOperator::OnRButtonUp(HEventInfo & event)
{
	if(!m_bOpStarted)
		return HBaseOperator::OnRButtonDownAndMove(event);

	if(m_isPrevRenderMode )
	{
		m_isPrevRenderMode = false;
		m_pView->SetRenderMode(m_prevRenderMode);
	}

	m_pView->CameraPositionChanged(true, true);

 	m_pView->Update();
	m_bOpStarted = false;

    return(HOP_READY);
}

// 마우스 더블 클릭 시, 특징형상 수정 창 띄우기 (17-03-07 권순조)
int PmViewManipulationOperator::OnLButtonDblClk(HEventInfo & event)
{
	m_pSelection->OnLButtonDown(event);
	
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());
	
	if (pSelection->GetSelectedListSize() > 0)
	{
		ENTITY * pSelectedEntity = pSelection->GetSelectedEntityAt(0);

		PmeFeature * pFeature = PmeFeatureTagMarker::FindFeature(pSelectedEntity);
			
		CMDIFrameWnd * pFrame = static_cast<CMDIFrameWnd *>(::AfxGetMainWnd());
		CMDIChildWnd * pChild = static_cast<CMDIChildWnd *>(pFrame->GetActiveFrame());
		PmView * pView = static_cast<PmView *>(pChild->GetActiveView());

		// 특징형상 다이얼로그 띄우기
		pView->CreateFeatureDialog(pFeature->GetFeatureType());
		
		// 파라메터 설정
		if (pView->GetFeatureDialog())
			pView->GetFeatureDialog()->SetParameters(pFeature);

		// 특징형상 하이라이트
		pView->SelectFeature(pFeature);
	}

	return HOpCameraManipulate::OnLButtonDblClk(event);
}

void PmViewManipulationOperator::OnFace(void)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());

	pSelection->DeSelectAll();
	pSelection->SetSelectionType(PmSelectionType_Face);	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());		
		HC_Set_Selectability("faces = on, lines = off, edges = off, markers = off");
	HC_Close_Segment();

	pHView->Update();
}