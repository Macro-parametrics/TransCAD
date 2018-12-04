#include "stdafx.h"
#include "Assemviewrotationoperator.h"

AssemViewRotationOperator::AssemViewRotationOperator(HBaseView* view, int DoRepeat, int DoCapture)
: HOpCameraOrbit(view, DoRepeat, DoCapture)
{
	m_singleClick = false;
	m_isPrevRenderMode = false;
}

AssemViewRotationOperator::~AssemViewRotationOperator(void)
{
}

int AssemViewRotationOperator::OnLButtonDown(HEventInfo & event)
{
	m_singleClick = true;

	return HOpCameraOrbit::OnLButtonDown(event);
}

int AssemViewRotationOperator::OnLButtonDownAndMove(HEventInfo & event)
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
 
int AssemViewRotationOperator::OnLButtonUp(HEventInfo & event)
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