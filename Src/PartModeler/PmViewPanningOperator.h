#pragma once

#include <HOpCameraPan.h>

class PmViewPanningOperator
	: public HOpCameraPan
{
public:
	PmViewPanningOperator(HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~PmViewPanningOperator(void);

	virtual int OnLButtonDownAndMove(HEventInfo & event);
    virtual int OnLButtonUp(HEventInfo & event);

	virtual const char * GetName(void) {return "PmViewPanningOperator";}

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;

};
