#pragma once
#include "PmeStdSolidRevolveFeature.h"
#include "PmeStdRevolveEndType.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidProtrusionRevolveFeature :
	public PmeStdSolidRevolveFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidProtrusionRevolveFeature)
public:
	PmeStdSolidProtrusionRevolveFeature(PmePart * pPart);
	PmeStdSolidProtrusionRevolveFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 double startAngle,
								 PmeStdRevolveEndType startCondition,
								 double endAngle,
								 PmeStdRevolveEndType endCondition,
								 bool isFlip = false);
	virtual ~PmeStdSolidProtrusionRevolveFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidProtrusionRevolveFeature;}
	virtual void Update(void);	

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

private:
	void CreateSolidBody(BODY *& pBody);
};
