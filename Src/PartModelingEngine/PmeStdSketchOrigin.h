#pragma once

#include ".\PmeObject.h"
#include ".\PmeDcmInterface.h"
#include ".\IPmeConstraintable.h"

class PmeStdSketchFeature;

class PmeStdSketchOrigin
	: public PmeObject
	, public IPmeConstraintable
	, public IPmeDcmPoint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchOrigin)
public:
	PmeStdSketchOrigin(PmeStdSketchFeature * pSketchFeature);
	virtual ~PmeStdSketchOrigin(void);

	CString GetName(void) const {return _T("Origin");}
	PmeStdSketchFeature * GetSketchFeature(void) const {return m_pSketchFeature;}

	// IPmeDcmGeometry
	virtual DCM_g_type DcmGetIdentify();
	virtual void DcmTransform(double [3][3]);
	virtual void DcmSetStatus(g_node_status status);
	virtual void SetGNode(g_node * pGNode) {m_pGNode = pGNode;}
	virtual g_node * GetGNode(void) const {return m_pGNode;}
	virtual void UpdateDcmInfo(PmeStdSketchEditor * pEditor);
	virtual void CleanDcmInfo(PmeStdSketchEditor * pEditor);

	// IPmeDcmPoint
	virtual void DcmGetPosition(double pt[2]);

private:
	PmeStdSketchFeature * m_pSketchFeature;
	g_node * m_pGNode;
};
