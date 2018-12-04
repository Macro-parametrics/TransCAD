#include "StdAfx.h"
#include "AssemViewManipulationOperator.h"
#include ".\AssemHSelectionSet.h"
#include ".\AssemView.h"


AssemViewManipulationOperator::AssemViewManipulationOperator( HBaseView* view, int DoRepeat, int DoCapture )
	: HOpCameraManipulate( view, DoRepeat, DoCapture )
{
	m_isPrevRenderMode = false;

	m_pSelection = new HOpSelectAperture( view, DoRepeat, DoCapture );
	OnFace();
}


AssemViewManipulationOperator::~AssemViewManipulationOperator(void)
{
	delete m_pSelection;
}

int AssemViewManipulationOperator::OnLButtonDownAndMove( HEventInfo & event )
{
	if ( m_pView->GetRenderMode() == HRenderHiddenLine )
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode( HRenderHiddenLineFast );
	}
	
	return HOpCameraManipulate::OnLButtonDownAndMove( event );
}

int AssemViewManipulationOperator::OnLButtonUp( HEventInfo & event )
{
	if( !m_bOpStarted )
		return HBaseOperator::OnLButtonDownAndMove( event );

	if( m_isPrevRenderMode )
	{
		m_isPrevRenderMode = false;
		m_pView->SetRenderMode( m_prevRenderMode );
	}

	m_pView->CameraPositionChanged( true, true );

 	m_pView->Update();
	m_bOpStarted = false;

    return( HOP_READY );
}

int AssemViewManipulationOperator::OnMButtonDownAndMove( HEventInfo & event )
{
	if (m_pView->GetRenderMode() == HRenderHiddenLine )
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode( HRenderHiddenLineFast );
	}
	
	return HOpCameraManipulate::OnMButtonDownAndMove( event );
}

int AssemViewManipulationOperator::OnMButtonUp( HEventInfo & event )
{
	if( !m_bOpStarted )
		return HBaseOperator::OnMButtonDownAndMove( event );

	if( m_isPrevRenderMode )
	{
		m_isPrevRenderMode = false;
		m_pView->SetRenderMode( m_prevRenderMode );
	}

	m_pView->CameraPositionChanged( true, true );

 	m_pView->Update();
	m_bOpStarted = false;

    return( HOP_READY );
}

int AssemViewManipulationOperator::OnRButtonDownAndMove( HEventInfo & event )
{
	if ( m_pView->GetRenderMode() == HRenderHiddenLine )
	{
		m_isPrevRenderMode = true;
		m_prevRenderMode = HRenderHiddenLine;
		m_pView->SetRenderMode( HRenderHiddenLineFast );
	}
	
	return HOpCameraManipulate::OnRButtonDownAndMove( event );
}

int AssemViewManipulationOperator::OnRButtonUp( HEventInfo & event )
{
	if( !m_bOpStarted )
		return HBaseOperator::OnRButtonDownAndMove( event );

	if( m_isPrevRenderMode )
	{
		m_isPrevRenderMode = false;
		m_pView->SetRenderMode( m_prevRenderMode );
	}

	m_pView->CameraPositionChanged( true, true );

 	m_pView->Update();
	m_bOpStarted = false;

    return( HOP_READY );
}

void AssemViewManipulationOperator::OnFace( void )
{
	HBaseView * pHView = GetView();
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( pHView->GetSelection() );

	pSelection->DeSelectAll();
	pSelection->SetSelectionType( AssemSelectionType_Face );

	HC_Open_Segment_By_Key( pHView->GetSceneKey() );
		HC_Set_Selectability("faces = on, lines = off, edges = off, markers = off");
	HC_Close_Segment();

	pHView->Update();
}