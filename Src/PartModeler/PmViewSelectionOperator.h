#pragma once

#include <vector>
#include <HOpCameraManipulate.h>

class PmViewSelectionOperator
	: /*public HBaseOperator, */public HOpCameraManipulate
{
public:
	PmViewSelectionOperator(HBaseView* view, int DoRepeat = 0, int DoCapture = 1);
	virtual ~PmViewSelectionOperator(void);

	virtual int OnLButtonDown(HEventInfo & event);
	virtual int OnLButtonUp(HEventInfo & event);

	virtual const char * GetName(void) {return "PmViewSelectionOperator";}

	void OnFace(void);
	void OnEdge(void);

	void DeselectAll(void);

	std::vector<CString> GetSelectedEntityNames(void) {return m_pSelectedEntityNames;}

private:
	bool m_isPrevRenderMode;
	HRenderMode m_prevRenderMode;
	HOpSelectAperture * m_pSelection;
	std::vector<CString> m_pSelectedEntityNames;
};