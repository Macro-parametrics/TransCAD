#pragma once
#include ".\PmeObject.h"
#include ".\PmeEdgeType.h"

class PmeVertex;

class PmeEdge
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeEdge)
public:
	PmeEdge(EDGE * pEdge);
	virtual ~PmeEdge(void);
	
	PmeVertex * GetStartPoint(void) const {return m_pStartPoint;}
	PmeVertex * GetEndPoint(void) const {return m_pEndPoint;}
	
	virtual PmeEdgeType GetEdgeType(void);
	
	CString GetName(void);

private:
	CString m_name;
	EDGE * m_pEdge;
	PmeEdgeType m_pEdgeType;

private:
	PmeVertex * m_pStartPoint;
	PmeVertex * m_pEndPoint;
};