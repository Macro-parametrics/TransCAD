#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeReference.h"

class PmeAssembly;
class PmePart;
class PmeReference;

class PmeStdAssemblyPerpendicular
	: public PmeStdAssemblyConstraint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyPerpendicular)
public:
	
	PmeStdAssemblyPerpendicular(PmeAssembly * pAssembly, PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);

	virtual ~PmeStdAssemblyPerpendicular(void);

	PmePart * GetConstrainedPart(void) const {return m_pCoPart;}
	PmePart * GetReferencePart(void) const {return m_pRefPart;}

	PmeReference * GetConstrainedGeometry(void) const {return m_pCoGeometry;}
	PmeReference * GetReferenceGeometry(void) const {return m_pRefGeometry;}
	
	virtual PmeStdAssemblyConstraintType GetType(void) const { return PmeStdAssemblyConstraintType_Perpendicular; }

	void UpdateConstraint(void);

	void SetPerpendicular( MrAxis2 coFaceLocalCSYS, MrAxis2 refFaceLocalCSYS );
	void SetPerpendicular( EDGE * coEdge, EDGE * refEdge );
	void SetPerpendicular( MrAxis2 faceLocalCSYS, EDGE * pEdge, int flag );
	
	void DoPerpendicular(void);
	

private:
	PmePart * m_pCoPart;
	PmePart * m_pRefPart;
	PmeReference * m_pCoGeometry;
	PmeReference * m_pRefGeometry;

	// These variables are only used internal functions
	MrVector m_coNormal, m_refNormal;
	MrTransformation m_coLocalToGlobal, m_refLocalToGlobal;
};
