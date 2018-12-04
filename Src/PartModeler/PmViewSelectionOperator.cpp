#include "stdAfx.h"
#include ".\PmViewSelectionOperator.h"
#include ".\PmHSelectionSet.h"
#include "PmViewManipulationOperator.h"


PmViewSelectionOperator::PmViewSelectionOperator(HBaseView* view, int DoRepeat, int DoCapture)
	: HOpCameraManipulate(view, DoRepeat, DoCapture)
{
	m_pSelection = new HOpSelectAperture(view, DoRepeat, DoCapture);
	m_pSelectedEntityNames.clear();
}

PmViewSelectionOperator::~PmViewSelectionOperator(void)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());
	pSelection->DeSelectAll();

	delete m_pSelection;

	GetView()->SetOperator(new PmViewManipulationOperator(pHView));
}

int PmViewSelectionOperator::OnLButtonDown(HEventInfo & event)
{
	m_pSelection->OnLButtonDown(event);

	return HOpCameraManipulate::OnLButtonDown(event);
}

int PmViewSelectionOperator::OnLButtonUp(HEventInfo & event)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());

	int count = pSelection->GetSelectedListSize();
	
	if (count > 0)
	{
		m_pSelectedEntityNames.clear();
		
		for (int i = 0; i < count; ++i)
		{
			CString name;
			ENTITY * pSelectedEntity = pSelection->GetSelectedEntityAt(i);

			switch(pSelection->GetSelectionType())
			{
			case PmSelectionType_Face:
				PmePersistentNameAPI::FindFaceName((FACE *)pSelectedEntity, name);
				break;
			case PmSelectionType_Edge:
				PmePersistentNameAPI::FindEdgeName((EDGE *)pSelectedEntity, name);
				break;
			}

			if(!name.IsEmpty())
			{
				m_pSelectedEntityNames.push_back(name);
			}
		}
	}

	return (HOP_OK);
}

void PmViewSelectionOperator::OnFace(void)
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

void PmViewSelectionOperator::OnEdge(void)
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

void PmViewSelectionOperator::DeselectAll(void)
{
	HBaseView * pHView = GetView();
	PmHSelectionSet * pSelection = static_cast<PmHSelectionSet *>(pHView->GetSelection());
	
	pSelection->DeSelectAll();
	m_pSelectedEntityNames.clear();
}