#pragma once
#include "PmeStdSolidSweepFeature.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidProtrusionSweepFeature :
	public PmeStdSolidSweepFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidProtrusionSweepFeature)
public:
	PmeStdSolidProtrusionSweepFeature(PmePart * pPart);
	PmeStdSolidProtrusionSweepFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 PmeReference * pGuideCurve);
	virtual ~PmeStdSolidProtrusionSweepFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidProtrusionSweepFeature;}
	virtual void Update(void);

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

private:
	void CreateSolidBody(BODY *& pBody);
};
