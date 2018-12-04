#pragma once

#include <HOpCameraManipulate.h>

class AssemApplyConstraintDialog;

class AssemViewPersistentNameOperator
	: public HOpCameraManipulate
{
public:
	AssemViewPersistentNameOperator( AssemApplyConstraintDialog * pDialog,
									 HBaseView * view,
									 int DoRepeat = 0,
									 int DoCapture = 1 );
	virtual ~AssemViewPersistentNameOperator( void );

	virtual int OnLButtonDown( HEventInfo & event );
	virtual int OnLButtonUp( HEventInfo & event );

	void OnFace(void);
	void OnEdge(void);
	void OnVertex(void);

private:
	HOpSelectAperture * m_pSelection;
	AssemApplyConstraintDialog * m_pDialog;
};