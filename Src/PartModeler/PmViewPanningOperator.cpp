#include "StdAfx.h"
#include ".\Pmviewpanningoperator.h"

PmViewPanningOperator::PmViewPanningOperator(HBaseView* view, int DoRepeat, int DoCapture)
: HOpCameraPan(view, DoRepeat, DoCapture)
{
	m_isPrevRenderMode = false;
}

PmViewPanningOperator::~PmViewPanningOperator(void)
{
}

int PmViewPanningOperator::OnLButtonDownAndMove(HEventInfo & event)
{
	if (m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}
	
	return HOpCameraPan::OnLButtonDownAndMove(event);
}

int PmViewPanningOperator::OnLButtonUp(HEventInfo & event)
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
