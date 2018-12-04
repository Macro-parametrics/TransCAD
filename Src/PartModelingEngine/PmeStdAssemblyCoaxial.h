#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeReference.h"

class PmeAssembly;
class PmePart;
class PmeReference;

class PmeStdAssemblyCoaxial
	: public PmeStdAssemblyConstraint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyCoaxial)
public:
	PmeStdAssemblyCoaxial(PmeAssembly * pAssembly, PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry);
	virtual ~PmeStdAssemblyCoaxial(void);

	PmePart * GetConstrainedPart(void) const { return m_pCoPart; }
	PmePart * GetReferencePart(void) const { return m_pRefPart; }

	PmeReference * GetConstrainedGeometry(void) const { return m_pCoGeometry; }
	PmeReference * GetReferenceGeometry(void) const { return m_pRefGeometry; }

	void UpdateConstraint(void);
	//void CleanConstraint(void);

	virtual PmeStdAssemblyConstraintType GetType(void) const { return PmeStdAssemblyConstraintType_Coaxial; }
	
	void DoCoaxial( MrAxis2 costrainedLocalCSYS, MrAxis2 referenceLocalCSYS );

private:
	PmeReference * m_pCoGeometry;
	PmeReference * m_pRefGeometry;
	PmePart * m_pCoPart;
	PmePart * m_pRefPart;
	
	MrVector m_translationVector;
	MrAxis2 m_translationResult;
};
