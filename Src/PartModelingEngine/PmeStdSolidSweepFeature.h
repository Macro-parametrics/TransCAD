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

	void AttachName(BODY *& pBody);
	void AttachVertexName_pointbased(BODY *& pBody);
	void AttachFaceName_pointbased(BODY *& pBody);

private:
	PmeReference * m_pProfileSketch;
	PmeReference * m_pGuideCurve;
};