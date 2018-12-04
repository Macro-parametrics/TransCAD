#pragma once

#include <HOpCameraManipulate.h>

class PmViewManipulationOperator
	: public HOpCameraManipulate
{
public:
	PmViewManipulationOperator(HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~PmViewManipulationOperator(void);

	virtual int OnLButtonDownAndMove(HEventInfo & event);
    virtual int OnLButtonUp(HEventInfo & event);
	virtual int OnMButtonDownAndMove(HEventInfo & event);
    virtual int OnMButtonUp(HEventInfo & event);
	virtual int OnRButtonDownAndMove(HEventInfo & event);
    virtual int OnRButtonUp(HEventInfo & event);
	virtual int OnLButtonDblClk(HEventInfo & event);

	virtual const char * GetName(void) {return "PmViewManipulationOperator";}
	void OnFace(void);

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;
	HOpSelectAperture * m_pSelection;
};
