#include "StdAfx.h"
#include ".\PmViewPersistentNameOperator.h"
#include ".\PmViewPersistentNameDialog.h"
#include ".\PmHSelectionSet.h"
#include "PmViewManipulationOperator.h"


PmViewPersistentNameOperator::PmViewPersistentNameOperator(PmViewPersistentNameDialog * pDialog, HBaseView* view, int DoRepeat, int DoCapture)
	: HOpCameraManipulate(view, DoRepeat, DoCapture)
	, m_pDialog(pDialog)
{
	m_pSelection = new HOpSelectAperture(view, DoRepeat, DoCapture);
}

PmViewPersistentNameOperator::~PmViewPersistentNameOperator(void)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());
	pSelection->DeSelectAll();

	delete m_pSelection;

	GetView()->SetOperator(new PmViewManipulationOperator(pHView));
}

int PmViewPersistentNameOperator::OnLButtonDown(HEventInfo & event)
{
	m_pSelection->OnLButtonDown(event);
	
	return HOpCameraManipulate::OnLButtonDown(event);
}

int PmViewPersistentNameOperator::OnLButtonUp(HEventInfo & event)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());

	ENTITY * pSelectedEntity = pSelection->GetSelectedEntity();

	if (pSelectedEntity)
	{
		CString name;

		switch(pSelection->GetSelectionType())
		{
		case PmSelectionType_Face:
			PmePersistentNameAPI::FindFaceName((FACE *)pSelectedEntity, name);
			break;
		case PmSelectionType_Edge:
			PmePersistentNameAPI::FindEdgeName((EDGE *)pSelectedEntity, name);
			break;
		case PmSelectionType_Vertex:
			PmePersistentNameAPI::FindVertexName((VERTEX *)pSelectedEntity, name);
			break;
		}

		if(!name.IsEmpty())
		{
			m_pDialog->SetPersistentName(name);
		}
	}

	return (HOP_OK);
}

void PmViewPersistentNameOperator::OnFace(void)
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

void PmViewPersistentNameOperator::OnEdge(void)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());

	pSelection->DeSelectAll();
	pSelection->SetSelectionType(PmSelectionType_Edge);	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());		
		HC_Set_Selectability("faces = off, lines = on, edges = off, markers = off");
	HC_Close_Segment();

	pHView->Update();
}

void PmViewPersistentNameOperator::OnVertex(void)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());

	pSelection->DeSelectAll();
	pSelection->SetSelectionType(PmSelectionType_Vertex);	

	HC_Open_Segment_By_Key(pHView->GetSceneKey());
		HC_Set_Selectability("faces = off, lines = off, edges = off, markers = on");
	HC_Close_Segment();

	pHView->Update();
}