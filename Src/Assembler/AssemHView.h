#pragma once

#include "AssemMacro.h"
#include "HSnapGrid.h"

class AssemHModel;
class AssemHSelectionSet;

class ASSEM_API AssemHView
	: public HBaseView
{
public:
	AssemHView(
		AssemHModel * pHModel
		, const char * alias = 0
		, const char * driver_type = 0
		, const char * instance_name = 0
		, void * window_handle = 0
		, void * colormap = 0
		);
	virtual ~AssemHView(void);

//Grid
	HSnapGrid * GetSnapGrid() {return (m_pSnapGrid);}
	bool GetSnap() {return (m_bSnap);}
	void	SetSnap(bool snap) {m_bSnap = snap;}
	void	ShowGrid(ViewMode viewmode);
//Grid

	void Init(void);

    //AssemHModel * GetModel();
	HBaseModel * GetModel();

	void SwitchToModelView(void);
	void SwitchToMeshView(void);

	HC_KEY GetMeshLinkKey(void) const {return m_hMeshLinkKey;}

	void SetModelViewVisibility(bool on = true);
	void SetMeshViewVisibility(bool on = true);

	virtual void FitWorld(HPoint * center_out = 0);
	AssemHSelectionSet * GetSelection(void);

//Grid
protected:

	HSnapGrid * m_pSnapGrid;
	bool        m_bSnap;
//Grid

public:
	void HideGrid(void);

private:
	HC_KEY m_hMeshLinkKey;
};
