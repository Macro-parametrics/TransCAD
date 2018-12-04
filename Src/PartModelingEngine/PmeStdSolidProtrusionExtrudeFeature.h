#pragma once
#include "PmeStdSolidExtrudeFeature.h"
#include "PmeStdExtrudeEndType.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidProtrusionExtrudeFeature :
	public PmeStdSolidExtrudeFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidProtrusionExtrudeFeature)
public:
	PmeStdSolidProtrusionExtrudeFeature(PmePart * pPart);
	PmeStdSolidProtrusionExtrudeFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 double startDepth,
								 PmeStdExtrudeEndType startCondition,
								 double endDepth,
								 PmeStdExtrudeEndType endCondition,
								 bool isFlip = false);
	virtual ~PmeStdSolidProtrusionExtrudeFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidProtrusionExtrudeFeature;}
	virtual void Update(void);	

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

private:
	void CreateSolidBody(BODY *& pBody);
};
