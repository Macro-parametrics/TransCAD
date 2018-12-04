#pragma once

#include ".\PmeObject.h"
#include ".\PmeDcmInterface.h"
#include ".\IPmeConstraintable.h"

class PmeStdSketchFeature;

class PmeStdSketchVDirection
	: public PmeObject
	, public IPmeConstraintable
	, public IPmeDcmLine
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchVDirection)
public:
	PmeStdSketchVDirection(PmeStdSketchFeature * pSketchFeature);
	virtual ~PmeStdSketchVDirection(void);

	CString GetName(void) const {return _T("VDirection");}
	PmeStdSketchFeature * GetSketchFeature(void) const {return m_pSketchFeature;}

	// IPmeDcmGeometry
	virtual DCM_g_type DcmGetIdentify();
	virtual void DcmTransform(double [3][3]);
	virtual void DcmSetStatus(g_node_status status);
	virtual void SetGNode(g_node * pGNode) {m_pGNode = pGNode;}
	virtual g_node * GetGNode(void) const {return m_pGNode;}
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// IPmeDcmLine
	virtual void DcmGetPosition(double pt[2]);
	virtual void DcmGetDirection(double dir[2]);

private:
	PmeStdSketchFeature * m_pSketchFeature;
	g_node * m_pGNode;
};
