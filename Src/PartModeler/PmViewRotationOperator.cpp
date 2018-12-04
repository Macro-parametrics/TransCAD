#include "StdAfx.h"
#include ".\pmviewrotationoperator.h"

PmViewRotationOperator::PmViewRotationOperator(HBaseView* view, int DoRepeat, int DoCapture)
: HOpCameraOrbit(view, DoRepeat, DoCapture)
{
	m_singleClick = false;
	m_isPrevRenderMode = false;
}

PmViewRotationOperator::~PmViewRotationOperator(void)
{
}

int PmViewRotationOperator::OnLButtonDown(HEventInfo & event)
{
	m_singleClick = true;

	return HOpCameraOrbit::OnLButtonDown(event);
}

int PmViewRotationOperator::OnLButtonDownAndMove(HEventInfo & event)
{
	m_singleClick = false;

	if(m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}

	HOpCameraOrbit::OnLButtonDownAndMove(event);
	return (HOP_OK);
}
 
int PmViewRotationOperator::OnLButtonUp(HEventInfo & event)
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

	return (HOP_OK);
}


int PmViewRotationOperator::OnMButtonDownAndMove(HEventInfo & event)
{
	if (m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}
	
	return HOpCameraOrbit::OnMButtonDownAndMove(event);
}

int PmViewRotationOperator::OnMButtonUp(HEventInfo & event)
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
