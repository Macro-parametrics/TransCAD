#include "StdAfx.h"
#include ".\PmHView.h"
#include ".\PmHModel.h"
#include ".\PmHSelectionSet.h"

PmHView::PmHView(
                               PmHModel * pHModel
							   , const char * alias
							   , const char * driver_type
                               , const char * instance_name
                               , void * window_handle
                               , void * colormap
							   )
: HBaseView(pHModel, alias, driver_type, instance_name, window_handle, colormap)
{
}

PmHView::~PmHView(void)
{
}

void PmHView::Init(void)
{
	// call base's init function first to get the default HOOPS hierarchy for the view
	HBaseView::Init();

	// create our app-specific Selection object and initialize
	m_pSelection = new PmHSelectionSet(this);
    m_pSelection->Init();
}

HBaseModel * PmHView::GetModel(void)
{
	return static_cast<PmHModel *>(HBaseView::GetModel());
}

PmHSelectionSet * PmHView::GetSelection(void)
{
	return static_cast<PmHSelectionSet *>(m_pSelection);
}

void PmHView::FitWorld(HPoint * center_out)
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