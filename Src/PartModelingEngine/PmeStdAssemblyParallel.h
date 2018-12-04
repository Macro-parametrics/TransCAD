/**
	@file	PmeStdAssemblyParallel.h
	@class	PmeStdAssemblyParallel
	@date	2017/03/23
	@author	Youngki Kim(kimyg5415@kaist.ac.kr)
*/
#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeReference.h"

class PmeAssembly;
class PmePart;
class PmeReference;

class PmeStdAssemblyParallel
	: public PmeStdAssemblyConstraint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyParallel)
public:
	
	PmeStdAssemblyParallel(PmeAssembly * pAssembly, PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);

	virtual ~PmeStdAssemblyParallel(void);

	PmePart * GetConstrainedPart(void) const {return m_pCoPart;}
	PmePart * GetReferencePart(void) const {return m_pRefPart;}

	PmeReference * GetConstrainedGeometry(void) const {return m_pCoGeometry;}
	PmeReference * GetReferenceGeometry(void) const {return m_pRefGeometry;}
	
	virtual PmeStdAssemblyConstraintType GetType(void) const { return PmeStdAssemblyConstraintType_Parallel; }

	void UpdateConstraint(void);

	void DoParallel( MrAxis2 coFaceLocalCSYS, MrAxis2 refFaceLocalCSYS );
	void DoParallel( EDGE * pCoEdge, EDGE * pRefEdge );
	void DoParallel( MrAxis2 faceLocalCSYS, EDGE * pEdge, int flag );

private:
	PmePart * m_pCoPart;
	PmePart * m_pRefPart;
	PmeReference * m_pCoGeometry;
	PmeReference * m_pRefGeometry;

	// These variables are only used internal functions
	MrVector m_coNormal, m_refNormal;
	MrTransformation m_coLocalToGlobal, m_refLocalToGlobal;
};
