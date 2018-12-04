#include "StdAfx.h"
#include ".\pmviewzoomwindowoperator.h"
#include <HOpConstructRectangle.h>
#include <HBhvBehaviorManager.h>

PmViewZoomWindowOperator::PmViewZoomWindowOperator(HBaseView * view, int DoRepeat, int DoCapture)
 : HOpCameraZoomBox(view, DoRepeat, DoCapture)
{
	m_bIsPrevRenderMode = false;
}

PmViewZoomWindowOperator::~PmViewZoomWindowOperator(void)
{
}

int PmViewZoomWindowOperator::OnLButtonUp(HEventInfo & event)
{
	if(m_pView->GetModel()->GetBhvBehaviorManager()->IsPlaying() && 
       m_pView->GetModel()->GetBhvBehaviorManager()->GetCameraUpdated())
	{
		HOpConstructRectangle::OnLButtonUp(event);
		
		return (HOP_OK);
	}

	if(m_pView->GetRenderMode() == HRenderHiddenLine)
	{
		m_bIsPrevRenderMode = true;
		m_hPrevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode(HRenderHiddenLineFast);
	}

	HOpCameraZoomBox::OnLButtonUp(event);
	
	if(m_bIsPrevRenderMode)
	{
		m_bIsPrevRenderMode = false;
		m_pView->SetRenderMode(m_hPrevRenderMode);
		m_pView->Update();
	}

	return(HOP_READY);
}

int PmViewZoomWindowOperator::OnLButtonDblClk(HEventInfo & event)
{
    m_ptNew = event.GetMouseWindowPos();

    HC_Open_Segment_By_Key(m_pView->GetSceneKey());
		HC_Compute_Coordinates(".", "outer window", &m_ptNew, "world", &m_ptNew);
		HC_Set_Camera_Target  (m_ptNew.x, m_ptNew.y, m_ptNew.z);
	HC_Close_Segment();
	
    m_pView->Update();

    return HBaseOperator::OnLButtonDblClk(event);
}