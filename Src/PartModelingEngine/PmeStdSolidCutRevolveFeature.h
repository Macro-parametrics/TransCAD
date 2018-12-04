#pragma once
#include "PmeStdSolidRevolveFeature.h"
#include "PmeStdRevolveEndType.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidCutRevolveFeature :
	public PmeStdSolidRevolveFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidCutRevolveFeature)
public:
	PmeStdSolidCutRevolveFeature(PmePart * pPart);
	PmeStdSolidCutRevolveFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 double startAngle,
								 PmeStdRevolveEndType startCondition,
								 double endAngle,
								 PmeStdRevolveEndType endCondition,
								 bool isFlip = false);
	virtual ~PmeStdSolidCutRevolveFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidCutRevolveFeature;}
	virtual void Update(void);

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

private:
	void CreateSolidBody(BODY *& pBody);
};
