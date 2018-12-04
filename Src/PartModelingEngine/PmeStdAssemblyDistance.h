/**
	@file	PmeStdAssemblyDistance.h
	@class	PmeStdAssemblyDistance
	@date	2017/03/23
	@author	Youngki Kim(kimyg5415@kaist.ac.kr)
*/
#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeReference.h"

class PmeAssembly;
class PmePart;
class PmeReference;


class PmeStdAssemblyDistance
	: public PmeStdAssemblyConstraint
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdAssemblyDistance)
public:
	
	PmeStdAssemblyDistance(PmeAssembly * pAssembly,
						   PmePart * pConstrainedPart,
						   PmeReference * pConstrainedGeometry,
						   PmePart * pReferencePart,
						   PmeReference * pReferenceGeometry,
						   double distance,
						   PmeStdAssemblyIncidenceType incidenceType = PmeStdAssemblyIncidenceType_Opposite);

	virtual ~PmeStdAssemblyDistance(void);

	PmePart * GetConstrainedPart(void) const {return m_pCoPart;}
	PmePart * GetReferencePart(void) const {return m_pRefPart;}

	PmeReference * GetConstrainedGeometry(void) const {return m_pCoGeometry;}
	PmeReference * GetReferenceGeometry(void) const {return m_pRefGeometry;}
	
	double GetDistance(void) const { return m_Distance; }

	virtual PmeStdAssemblyConstraintType GetType(void) const { return PmeStdAssemblyConstraintType_Angle; }
	
	PmeStdAssemblyIncidenceType GetDistanceOption(void) const { return m_DistanceType; }

	void UpdateConstraint(void);

	void DoDistancePlanarFacesOpposite(void);
	void DoDistancePlanarFacesSame(void);
	
private:
	// Expose to external variables
	PmePart * m_pCoPart;
	PmePart * m_pRefPart;
	PmeReference * m_pCoGeometry;
	PmeReference * m_pRefGeometry;
	double m_Distance;
	PmeStdAssemblyIncidenceType m_DistanceType;
	
	// These variables are only used for internal functions
	ENTITY *	m_pCoEntity;
	ENTITY *	m_pRefEntity;
	MrAxis2		m_coFaceLCSYS, m_refFaceLCSYS;
	MrAxis2		m_coFaceGCSYS, m_refFaceGCSYS;
	MrAxis2		m_coPartCSYS, m_refPartCSYS;
	MrVector	m_coNormal, m_refNormal;

	// 좌표이동을 위한 벡터와 constrained part의 최종 좌표와 CSYS를 저장하는 변수
	MrVector	m_translationVector;
	MrAxis2		m_translationResult;
};
