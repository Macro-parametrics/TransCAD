#pragma once
#include ".\PmeObject.h"
#include ".\PmeFaceType.h"

class PmeEdges;
class PmeVertices;

class PmeFace
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeFace)
public:
	PmeFace(FACE * pFace);
	virtual ~PmeFace(void);

	virtual PmeFaceType GetFaceType(void);

	CString GetName(void);

	PmeEdges * GetEdges(void);
	PmeVertices * GetVertices(void);
	
	MrPosition GetCentroid(void) {return m_pCentroid;}
	MrDirection GetXDirection(void) {return m_pXDirection;}
	MrDirection GetYDirection(void) {return m_pYDirection;}
	MrDirection GetZDirection(void) {return m_pZDirection;}
	double GetArea(void) {return m_pArea;}

private:
	void GetProperties(void);

private:
	CString m_name;
	FACE * m_pFace;
	PmeFaceType m_pFaceType;
	PmeEdges * m_pEdges;
	PmeVertices * m_pVertices;
	MrPosition m_pCentroid;
	MrDirection m_pXDirection, m_pYDirection, m_pZDirection;
	double m_pArea;
};