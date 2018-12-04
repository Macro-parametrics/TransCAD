#pragma once

#include ".\PmeObject.h"
#include ".\PmeStdSketchGeometryType.h"
#include ".\PmeDcmInterface.h"
#include ".\IPmeConstraintable.h"

class PmeStdSketchFeature;

class PmeStdSketchGeometry
	: public PmeObject
	, public IPmeConstraintable
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSketchGeometry)
public:
	PmeStdSketchGeometry(PmeStdSketchFeature * pSketchFeature);
	PmeStdSketchGeometry(PmeStdSketchFeature * pSketchFeature, const CString & name);
	virtual ~PmeStdSketchGeometry(void);

	virtual PmeStdSketchGeometryType GetType(void) const = 0;

	CString GetName(void) const {return m_name;}
	PmeStdSketchFeature * GetSketchFeature(void) const {return m_pSketchFeature;}

	void SetName(const CString & name);
	void GiveDefaultName(void);

	// IPmeConstraintable
	virtual void SetGNode(g_node * pGNode) {m_pGNode = pGNode;}
	virtual g_node * GetGNode(void) const {return m_pGNode;}

private:
	bool CheckName(const CString & name) const;

private:
	CString m_name;
	PmeStdSketchFeature * m_pSketchFeature;
	g_node * m_pGNode;
};
