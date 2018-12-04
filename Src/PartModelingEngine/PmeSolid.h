#pragma once
#include "pmeexplicitmodelobject.h"

class PmeFaces;
class PmeEdges;
class PmeVertices;

class PmeSolid :
	public PmeExplicitModelObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeSolid)
public:
	PmeSolid(void);
	virtual ~PmeSolid(void);

	virtual PmeExplicitModelObjectType GetType(void) const {return PmeExplicitModelObjectType_Solid;}

	BODY * GetSolid(void) const {return m_pBody;}
	void UpdateSolid(BODY * pBody);

	PmeFaces * GetFaces(void);
	PmeEdges * GetEdges(void);
	PmeVertices * GetVertices(void);

private:
	BODY * m_pBody;
	PmeFaces * m_pFaces;
	PmeEdges * m_pEdges;
	PmeVertices * m_pVertices;
};
