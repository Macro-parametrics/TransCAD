#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeReference.h"

class PmeAssembly;
class PmePart;
class PmeReference;

class PmeStdAssemblyAngle
	: public PmeStdAssemblyConstraint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyAngle)
public:
	
	PmeStdAssemblyAngle(PmeAssembly * pAssembly, PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry, double angle);

	virtual ~PmeStdAssemblyAngle(void);

	PmePart * GetConstrainedPart(void) const {return m_pCoPart;}
	PmePart * GetReferencePart(void) const {return m_pRefPart;}

	PmeReference * GetConstrainedGeometry(void) const {return m_pCoGeometry;}
	PmeReference * GetReferenceGeometry(void) const {return m_pRefGeometry;}
	

	void UpdateConstraint(void);

	void SetAngle( MrAxis2 coFaceLocalCSYS, MrAxis2 refFaceLocalCSYS );
	void SetAngle( EDGE * coEdge, EDGE * refEdge );
	void SetAngle( MrAxis2 faceLocalCSYS, EDGE * pEdge, int flag );

	void DoAngle(void);

	virtual PmeStdAssemblyConstraintType GetType(void) const { return PmeStdAssemblyConstraintType_Angle; }

private:
	PmePart * m_pCoPart;
	PmePart * m_pRefPart;
	PmeReference * m_pCoGeometry;
	PmeReference * m_pRefGeometry;
	double m_Angle;

	// These variables are only used internal functions
	MrVector m_coNormal, m_refNormal;
	MrTransformation m_coLocalToGlobal, m_refLocalToGlobal;
};
