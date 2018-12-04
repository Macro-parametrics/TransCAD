#pragma once

#include <HOpCameraPan.h>

class AssemViewPanningOperator
	: public HOpCameraPan
{
public:
	AssemViewPanningOperator(HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~AssemViewPanningOperator(void);

	virtual int OnLButtonDownAndMove(HEventInfo & event);
    virtual int OnLButtonUp(HEventInfo & event);

	virtual const char * GetName(void) {return "AssemViewPanningOperator";}

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;

};
