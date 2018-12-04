#pragma once
#include "pmestdsolidfeature.h"
#include "PmeStdRevolveEndType.h"

class PmeReference;

class PmeStdSolidRevolveFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidRevolveFeature)
public:
	PmeStdSolidRevolveFeature(PmePart * pPart);
	PmeStdSolidRevolveFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
                                 double startAngle,
                                 PmeStdRevolveEndType startCondition,
                                 double endAngle,
                                 PmeStdRevolveEndType endCondition,
                                 bool isFlip = false);
	virtual ~PmeStdSolidRevolveFeature(void);

	PmeReference * GetProfileSketch(void) const {return m_pProfileSketch;}
	bool IsFlip(void) const {return m_isFlip;}
	PmeStdRevolveEndType GetStartCondition(void) const {return m_startCondition;}
	double GetStartAngle(void) const {return m_startAngle;}
	PmeStdRevolveEndType GetEndCondition(void) const {return m_endCondition;}
	double GetEndAngle(void) const {return m_endAngle;}

	void SetProfileSketch(PmeReference * pProfileSketch) {m_pProfileSketch = pProfileSketch;}
	void SetFlip(bool isFlip) {m_isFlip = isFlip;}
	void SetStartCondition(PmeStdRevolveEndType endType) {m_startCondition = endType;}
	void SetStartAngle(double angle) {m_startAngle = angle;}
	void SetEndCondition(PmeStdRevolveEndType endType) {m_endCondition = endType;}
	void SetEndAngle(double angle) {m_endAngle = angle;}

protected:
	PmeStdRevolveEndType GetInternalStartCondition(void) const {return (IsFlip()) ? m_endCondition : m_startCondition;}
	double GetInternalStartAngle(void) const {return (IsFlip()) ? m_endAngle : m_startAngle;}
	PmeStdRevolveEndType GetInternalEndCondition(void) const {return (IsFlip()) ? m_startCondition : m_endCondition;}
	double GetInternalEndAngle(void) const {return (IsFlip()) ? m_startAngle : m_endAngle;}

	MrAxis1 GetInternalAxis(bool isCut);

	BODY * RevolveStartSolid(BODY *& pProfile, bool isCut = false);
	BODY * RevolveEndSolid(BODY *& pProfile, bool isCut = false);

	BODY * RevolveWithBlind(BODY *& pProfile, const MrAxis1 & axis, double angle);

	void AttachName(BODY *& pBody);
	void AttachName_pointbased(BODY *& pBody);

	bool IsSharingEdge(FACE * pFace1, FACE * pFace2);

	double DegreeToRadian(double degree) {return M_PI / 180.0 * degree;}

private:
	PmeReference * m_pProfileSketch;
	bool m_isFlip;
	PmeStdRevolveEndType m_startCondition;
	double m_startAngle;
	PmeStdRevolveEndType m_endCondition;
	double m_endAngle;
};