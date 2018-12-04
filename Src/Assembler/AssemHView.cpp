#include "stdafx.h"
#include "AssemHView.h"
#include "AssemHModel.h"
#include "AssemHSelectionSet.h"
#include "AssemView.h"

AssemHView::AssemHView(
                               AssemHModel * pHModel
							   , const char * alias
							   , const char * driver_type
                               , const char * instance_name
                               , void * window_handle
                               , void * colormap
							   )
: HBaseView(pHModel, alias, driver_type, instance_name, window_handle, colormap)
, m_hMeshLinkKey(0)
{
	m_pSnapGrid = 0;
	m_bSnap = false;

}

AssemHView::~AssemHView(void)
{
	H_SAFE_DELETE(m_pSnapGrid);
}

void AssemHView::Init(void)
{
	// call base's init function first to get the default HOOPS hierarchy for the view
	HBaseView::Init();
// 	HC_Open_Segment_By_Key(GetOverwriteKey());
// 	m_hMeshLinkKey = HC_KCreate_Segment("MeshIncluder");
// 	HC_Open_Segment_By_Key(m_hMeshLinkKey);
// 	HC_KInclude_Segment_By_Key(GetModel()->GetMeshKey());
// 	HC_Close_Segment();
// 	HC_Close_Segment();

	// create our app-specific Selection object and initialize
	
	///SwitchToModelView();

	m_pSelection = new AssemHSelectionSet(this);
	m_pSelection->Init();

	// create our app-specific Selection object and initialize
	
}

HBaseModel * AssemHView::GetModel(void)
{
	return static_cast<AssemHModel *>(HBaseView::GetModel());
}

AssemHSelectionSet * AssemHView::GetSelection(void)
{
	return static_cast<AssemHSelectionSet *>(m_pSelection);
}

void AssemHView::FitWorld(HPoint * center_out)
{
	HC_Open_Segment_By_Key(GetModelKey());
		HC_Open_Segment("DatumSegment/FitIgnoringSegment");
			HC_Set_Visibility("everything = off");
			HC_Set_Rendering_Options("attribute lock = visibility");
		HC_Close_Segment();
	HC_Close_Segment();

	HBaseView::FitWorld(center_out);

	HC_Open_Segment_By_Key(GetModelKey());
		HC_Open_Segment("DatumSegment/FitIgnoringSegment");
			HC_UnSet_Visibility();
			HC_UnSet_Rendering_Options();
		HC_Close_Segment();
	HC_Close_Segment();
}

void AssemHView::ShowGrid(ViewMode viewmode)
{
	HPoint origin, ref1, ref2;
	bool success;
	origin.Set(0.0, 0.0, 0.0);
	ref1.Set(0.0, 0.0, 0.0);
	ref2.Set(0.0, 0.0, 0.0);
	switch(viewmode)
	{
		case HViewXY:
			origin.Set(0.0, 0.0, 0.0);
			ref1.Set(10.0, 0.0, 0.0);
			ref2.Set(0.0, 10.0, 0.0);
			break;
		
		case HViewYZ:
			origin.Set(0.0, 0.0, 0.0);
			ref1.Set(0.0, 10.0, 0.0);
			ref2.Set(0.0, 0.0, 10.0);
			break;
		
		case HViewZX:
			origin.Set(0.0, 0.0, 0.0);
			ref1.Set(0.0, 0.0, 10.0);
			ref2.Set(10.0, 0.0, 0.0);
			break;
	}
	
	m_pSnapGrid = new HSnapGrid(this);
	success = m_pSnapGrid->Create(&origin, &ref1, &ref2);
	
	if (success)
	{
		HC_Open_Segment_By_Key(m_pSnapGrid->GetGridSegment());
			//HC_Set_Visibility("geometry=off");	
			HC_Set_Color_By_Value("geometry","RGB", 0.6, 0.7, 0.8);
			HC_Set_Rendering_Options("depth range=(0.0, 0.0)");
		HC_Close_Segment();
	}

}

void AssemHView::HideGrid(void)
{
	H_SAFE_DELETE(m_pSnapGrid);
}

void AssemHView::SwitchToModelView(void)
{
	SetModelViewVisibility(true);
	SetMeshViewVisibility(false);
}

void AssemHView::SwitchToMeshView(void)
{
	SetModelViewVisibility(false);
	SetMeshViewVisibility(true);
}

void AssemHView::SetModelViewVisibility(bool on)
{
	HC_Open_Segment_By_Key(GetOverwriteKey());
	HC_Open_Segment("SelectionConditionIncluder");
	if(on)
	{
		HC_UnSet_Visibility();
		HC_UnSet_Rendering_Options();
	}				
	else
	{
		HC_Set_Visibility("everything = off");
		HC_Set_Rendering_Options("attribute lock = visibility");
	}
	HC_Close_Segment();
	HC_Close_Segment();
}

void AssemHView::SetMeshViewVisibility(bool on)
{
	HC_Open_Segment_By_Key(m_hMeshLinkKey);

	if(on)
	{
		HC_UnSet_Visibility();
		HC_UnSet_Rendering_Options();
	}				
	else
	{
		HC_Set_Visibility("everything = off");
		HC_Set_Rendering_Options("attribute lock = visibility");
	}

	HC_Close_Segment();
}