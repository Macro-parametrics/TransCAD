#pragma once
#include ".\PmeObject.h"

class PmeReference;

class PmeVertex
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeVertex)
public:
	PmeVertex(VERTEX * pVertex);
	virtual ~PmeVertex(void);
	
	MrPosition GetCoordinates(void) const {return m_pCoordinates;}
	
	CString GetName(void);

private:
	CString m_name;
	VERTEX * m_pVertex;

private:
	MrPosition m_pCoordinates;
};