#pragma once
#include "PmeStdSolidRevolveFeature.h"
#include "PmeStdRevolveEndType.h"
#include "IPmePattern.h"

class PmePart;

class PmeStdSolidRevolveWithExternalAxisFeature :
	public PmeStdSolidRevolveFeature,
	public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidRevolveWithExternalAxisFeature)
public:
	PmeStdSolidRevolveWithExternalAxisFeature(PmePart * pPart);
	PmeStdSolidRevolveWithExternalAxisFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
								 double startAngle,
								 PmeStdRevolveEndType startCondition,
								 double endAngle,
								 PmeStdRevolveEndType endCondition,
								 const MrAxis1 & revolveAxis,
								 bool isCut,
								 bool isFlip = false);
	virtual ~PmeStdSolidRevolveWithExternalAxisFeature(void);

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidRevolveWithExternalAxisFeature;}
	virtual void Update(void);	

	// IPmePattern
	virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	virtual bool IsCut(void);
		
	MrAxis1 GetRevolveAxis(void) { return m_revolveAxis; }
	
	void SetRevolveAxis(MrAxis1 axis) {m_revolveAxis = axis;}
	void SetCut(bool isCut) {m_isCut = isCut;}

private:
	void CreateSolidBody(BODY *& pBody);

private:
	MrAxis1 m_revolveAxis;
	bool m_isCut;
	double m_startAngle;
	double m_endAngle;
	bool m_isFlip;
};