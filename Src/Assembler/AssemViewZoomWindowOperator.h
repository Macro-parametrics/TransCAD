#pragma once

#include <HOpCameraZoomBox.h>

class AssemViewZoomWindowOperator
	: public HOpCameraZoomBox
{
public:
	AssemViewZoomWindowOperator(HBaseView * view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~AssemViewZoomWindowOperator(void);

	virtual int OnLButtonUp(HEventInfo & event);
    virtual int OnLButtonDblClk(HEventInfo & event);

	virtual const char * GetName(void) {return "AssemViewZoomWindowOperator";}

private:
	bool m_bIsPrevRenderMode;
	HRenderMode m_hPrevRenderMode;

};
