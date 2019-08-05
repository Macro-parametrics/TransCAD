#pragma once
#include "pmestdsolidfeature.h"

class PmeReference;

class PmeStdSolidSweepFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidSweepFeature)
public:
	PmeStdSolidSweepFeature(PmePart * pPart);
	PmeStdSolidSweepFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 PmeReference * pGuideCurve);
	virtual ~PmeStdSolidSweepFeature(void);

	PmeReference * GetProfileSketch(void) const {return m_pProfileSketch;}
	PmeReference * GetGuideCurve(void) const {return m_pGuideCurve;}

	void SetProfileSketch(PmeReference * pProfileSketch) {m_pProfileSketch = pProfileSketch;}
	void SetGuideCurve(PmeReference * pGuideCurve) {m_pGuideCurve = pGuideCurve;}

protected:
	BODY * SweepSolid(BODY *& pProfile, BODY *& pGuideCurve);

	BODY * NameNewVertices_ADD_BOL(BODY *& pBody, bool isCut = false); //For Name Matching
	BODY * NameNewVertices_SUB_BOL(BODY *& pBody, bool isCut = true); //For Name Matching

	//[Topology-Based Names]
	void AttachName(BODY *& pBody);

	//[Point-Based Names]
	void AttachVertexName_pointbased(BODY *& pBody); //initial 
	void AttachFaceName_pointbased(BODY *& pBody); //initial 
	void Attach_NewVertexNames_pointbased(BODY *& pBody); //Name Matching
	void AttachRemainingVertexNames_pointbased(BODY *& pBody); //Final Check

private:
	PmeReference * m_pProfileSketch;
	PmeReference * m_pGuideCurve;
};
