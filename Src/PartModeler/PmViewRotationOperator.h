#pragma once

#include <HOpCameraOrbit.h>

class PmViewRotationOperator
	: public HOpCameraOrbit
{
public:
	PmViewRotationOperator(HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~PmViewRotationOperator(void);

	virtual int OnLButtonUp(HEventInfo & event);
	virtual int OnLButtonDownAndMove(HEventInfo & event);
	virtual int OnLButtonDown(HEventInfo & event);

	virtual int OnMButtonDownAndMove(HEventInfo & event);
    virtual int OnMButtonUp(HEventInfo & event);

	virtual const char * GetName(void) {return "PmViewRotationOperator";}

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;
	bool m_singleClick;
};