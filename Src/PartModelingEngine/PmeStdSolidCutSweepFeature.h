#pragma once
#include "PmeStdSolidSweepFeature.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidCutSweepFeature :
	public PmeStdSolidSweepFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidCutSweepFeature)
public:
	PmeStdSolidCutSweepFeature(PmePart * pPart);
	PmeStdSolidCutSweepFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 PmeReference * pGuideCurve);
	virtual ~PmeStdSolidCutSweepFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidCutSweepFeature;}
	virtual void Update(void);

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

private:
	void CreateSolidBody(BODY *& pBody);
};
