#pragma once

#include <HOpCameraManipulate.h>

class PmViewPersistentNameDialog;

class PmViewPersistentNameOperator
	: /*public HBaseOperator, */public HOpCameraManipulate
{
public:
	PmViewPersistentNameOperator(PmViewPersistentNameDialog * pDialog, HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~PmViewPersistentNameOperator(void);

	virtual int OnLButtonDown(HEventInfo & event);
	virtual int OnLButtonUp(HEventInfo & event);

	virtual const char * GetName(void) {return "PmViewPersistentNameOperator";}

	void OnFace(void);
	void OnEdge(void);
	void OnVertex(void);

private:
	HOpSelectAperture * m_pSelection;
	PmViewPersistentNameDialog * m_pDialog;
};