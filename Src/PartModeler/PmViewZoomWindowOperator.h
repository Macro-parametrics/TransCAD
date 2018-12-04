#pragma once

#include <HOpCameraZoomBox.h>

class PmViewZoomWindowOperator
	: public HOpCameraZoomBox
{
public:
	PmViewZoomWindowOperator(HBaseView * view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~PmViewZoomWindowOperator(void);

	virtual int OnLButtonUp(HEventInfo & event);
    virtual int OnLButtonDblClk(HEventInfo & event);

	virtual const char * GetName(void) {return "PmViewZoomWindowOperator";}

private:
	bool m_bIsPrevRenderMode;
	HRenderMode m_hPrevRenderMode;

};
