#include "StdAfx.h"
#include ".\AssemViewPersistentNameOperator.h"
#include ".\AssemApplyConstraintDialog.h"
#include ".\AssemHSelectionSet.h"
#include ".\AssemViewManipulationOperator.h"

AssemViewPersistentNameOperator::AssemViewPersistentNameOperator( AssemApplyConstraintDialog * pDialog,
																  HBaseView * view,
																  int DoRepeat,
																  int DoCapture )
	: HOpCameraManipulate( view, DoRepeat, DoCapture )
	, m_pDialog( pDialog )
{
	m_pSelection = new HOpSelectAperture( view, DoRepeat, DoCapture );
}

AssemViewPersistentNameOperator::~AssemViewPersistentNameOperator( void )
{
	HBaseView * pHView = GetView();
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( pHView->GetSelection() );
	pSelection->DeSelectAll();

	delete m_pSelection;

	GetView()->SetOperator(new AssemViewManipulationOperator( pHView ));
}

int AssemViewPersistentNameOperator::OnLButtonDown( HEventInfo & event )
{
	m_pSelection->OnLButtonDown( event );
	
	return HOpCameraManipulate::OnLButtonDown( event );
}

int AssemViewPersistentNameOperator::OnLButtonUp( HEventInfo & event )
{
	HBaseView * pHView = GetView();
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( pHView->GetSelection() );

	ENTITY * pSelectedEntity = pSelection->GetSelectedEntity();

	if ( pSelectedEntity )
	{
		CString name;

		switch( pSelection->GetSelectionType() )
		{
		case AssemSelectionType_Face:
			PmePersistentNameAPI::FindFaceName( (FACE *)pSelectedEntity, name );
			break;
		case AssemSelectionType_Edge:
			PmePersistentNameAPI::FindEdgeName( (EDGE *)pSelectedEntity, name );
			break;
		case AssemSelectionType_Vertex:
			PmePersistentNameAPI::FindVertexName( (VERTEX *)pSelectedEntity, name );
			break;
		}

		if( !name.IsEmpty() )
		{
			m_pDialog->SetPersistentName( name );
		}
	}

	return ( HOP_OK );
}

void AssemViewPersistentNameOperator::OnFace( void )
{
	HBaseView * pHView = GetView();
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( pHView->GetSelection() );

	pSelection->DeSelectAll();
	pSelection->SetSelectionType( AssemSelectionType_Face );	

	HC_Open_Segment_By_Key( pHView->GetSceneKey() );		
		HC_Set_Selectability( "faces = on, lines = off, edges = off, markers = off" );
	HC_Close_Segment();

	pHView->Update();
}

void AssemViewPersistentNameOperator::OnEdge( void )
{
	HBaseView * pHView = GetView();
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( pHView->GetSelection() );

	pSelection->DeSelectAll();
	pSelection->SetSelectionType( AssemSelectionType_Edge );	

	HC_Open_Segment_By_Key( pHView->GetSceneKey() );
		HC_Set_Selectability ("faces = off, lines = on, edges = off, markers = off" );
	HC_Close_Segment();

	pHView->Update();
}

void AssemViewPersistentNameOperator::OnVertex( void )
{
	HBaseView * pHView = GetView();
	AssemHSelectionSet * pSelection = static_cast<AssemHSelectionSet *>( pHView->GetSelection() );

	pSelection->DeSelectAll();
	pSelection->SetSelectionType( AssemSelectionType_Vertex );

	HC_Open_Segment_By_Key( pHView->GetSceneKey() );
		HC_Set_Selectability( "faces = off, lines = off, edges = off, markers = on" );
	HC_Close_Segment();

	pHView->Update();
}