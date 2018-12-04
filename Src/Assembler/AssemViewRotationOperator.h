#pragma once

#include <HOpCameraOrbit.h>

class AssemViewRotationOperator
	: public HOpCameraOrbit
{
public:
	AssemViewRotationOperator(HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~AssemViewRotationOperator(void);

	virtual int OnLButtonUp(HEventInfo & event);
	virtual int OnLButtonDownAndMove(HEventInfo & event);
	virtual int OnLButtonDown(HEventInfo & event);

	virtual const char * GetName(void) {return "AssemViewRotationOperator";}

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;
	bool m_singleClick;
};