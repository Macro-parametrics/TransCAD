#pragma once
#include "PmeStdSolidExtrudeFeature.h"
#include "PmeStdExtrudeEndType.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidCutExtrudeFeature :
	public PmeStdSolidExtrudeFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidCutExtrudeFeature)
public:
	PmeStdSolidCutExtrudeFeature(PmePart * pPart);
	PmeStdSolidCutExtrudeFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 double startDepth,
								 PmeStdExtrudeEndType startCondition,
								 double endDepth,
								 PmeStdExtrudeEndType endCondition,
								 bool isFlip = false);
	virtual ~PmeStdSolidCutExtrudeFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidCutExtrudeFeature;}
	virtual void Update(void);

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);

private:
	void CreateSolidBody(BODY *& pBody);
	
	void AttachVertexName_pointbased(BODY *& pBody);
	void AttachFaceName_pointbased(BODY *& pBody);
};
