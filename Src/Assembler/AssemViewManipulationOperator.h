#pragma once

#include <HOpCameraManipulate.h>

class AssemViewManipulationOperator :
	public HOpCameraManipulate
{
public:
	AssemViewManipulationOperator( HBaseView* view, int DoRepeat = 0, int DoCapture = 1 );
	~AssemViewManipulationOperator( void );

	virtual int OnLButtonDownAndMove( HEventInfo & event );
    virtual int OnLButtonUp( HEventInfo & event );
	virtual int OnMButtonDownAndMove( HEventInfo & event );
    virtual int OnMButtonUp( HEventInfo & event );
	virtual int OnRButtonDownAndMove( HEventInfo & event );
    virtual int OnRButtonUp( HEventInfo & event );

	void OnFace( void );

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;
	HOpSelectAperture * m_pSelection;
};

