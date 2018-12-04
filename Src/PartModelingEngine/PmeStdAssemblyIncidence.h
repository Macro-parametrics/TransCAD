#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeReference.h"

class PmeAssembly;
class PmePart;
class PmeReference;

class PmeStdAssemblyIncidence
	: public PmeStdAssemblyConstraint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyIncidence)
public:
	/**
	 * Incidence condition is a orientation between faces
	 * true is a oppsite and false is a same
	**/
	PmeStdAssemblyIncidence(PmeAssembly * pAssembly,
							PmePart * pConstrainedPart,
							PmeReference * pConstrainedGeometry,
							PmePart * pReferencePart,
							PmeReference * pReferenceGeometry,
							PmeStdAssemblyIncidenceType incidenceType = PmeStdAssemblyIncidenceType_Opposite);

	virtual ~PmeStdAssemblyIncidence(void);

	PmePart * GetConstrainedPart(void) const {return m_pCoPart;}
	PmePart * GetReferencePart(void) const {return m_pRefPart;}

	PmeReference * GetConstrainedGeometry(void) const {return m_pCoGeometry;}
	PmeReference * GetReferenceGeometry(void) const {return m_pRefGeometry;}
	PmeStdAssemblyIncidenceType GetIncidenceType(void) const { return m_incidenceType; }

	virtual PmeStdAssemblyConstraintType GetType(void) const { return PmeStdAssemblyConstraintType_Incidence; }

	void UpdateConstraint(void);
	
	void DoIncidencePlanarFacesOpposite(void);
	void DoIncidencePlanarFacesSame(void);
	void DoIncidence( EDGE * pCoEdge, EDGE * pRefEdge );
	

private:
	PmePart * m_pCoPart;
	PmePart * m_pRefPart;
	PmeReference * m_pCoGeometry;
	PmeReference * m_pRefGeometry;
	PmeStdAssemblyIncidenceType m_incidenceType;

	// These variables are only used for internal functions
	ENTITY *	m_pCoEntity;
	ENTITY *	m_pRefEntity;
	MrAxis2		m_coFaceLCSYS, m_refFaceLCSYS;
	MrAxis2		m_coFaceGCSYS, m_refFaceGCSYS;
	MrAxis2		m_coPartCSYS, m_refPartCSYS;
	MrVector	m_coNormal, m_refNormal;
	MrTransformation m_coLocalToGlobal, m_refLocalToGlobal;

	// 좌표이동을 위한 벡터와 constrained part의 최종 좌표와 CSYS를 저장하는 변수
	MrVector	m_translationVector;
	MrAxis2		m_translationResult;
};
