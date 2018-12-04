#pragma once
#include "pmestdsolidfeature.h"
#include "PmeStdExtrudeEndType.h"

class PmeReference;

class PmeStdSolidExtrudeFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidExtrudeFeature)
public:
	PmeStdSolidExtrudeFeature(PmePart * pPart);
	PmeStdSolidExtrudeFeature(PmePart * pPart,
								 PmeReference * pProfileSketch,
                                 double startDepth,
                                 PmeStdExtrudeEndType startCondition,
                                 double endDepth,
                                 PmeStdExtrudeEndType endCondition,
                                 bool isFlip = false);
	virtual ~PmeStdSolidExtrudeFeature(void);

	PmeReference * GetProfileSketch(void) const {return m_pProfileSketch;}
	bool IsFlip(void) const {return m_isFlip;}
	PmeStdExtrudeEndType GetStartCondition(void) const {return m_startCondition;}
	double GetStartDepth(void) const {return m_startDepth;}
	PmeStdExtrudeEndType GetEndCondition(void) const {return m_endCondition;}
	double GetEndDepth(void) const {return m_endDepth;}

	void SetProfileSketch(PmeReference * pProfileSketch) {m_pProfileSketch = pProfileSketch;}
	void SetFlip(bool isFlip) {m_isFlip = isFlip;}
	void SetStartCondition(PmeStdExtrudeEndType endType) {m_startCondition = endType;}
	void SetStartDepth(double depth) {m_startDepth = depth;}
	void SetEndCondition(PmeStdExtrudeEndType endType) {m_endCondition = endType;}
	void SetEndDepth(double depth) {m_endDepth = depth;}

protected:
	PmeStdExtrudeEndType GetInternalStartCondition(void) const {return (IsFlip()) ? m_endCondition : m_startCondition;}
	double GetInternalStartDepth(void) const {return (IsFlip()) ? m_endDepth : m_startDepth;}
	PmeStdExtrudeEndType GetInternalEndCondition(void) const {return (IsFlip()) ? m_startCondition : m_endCondition;}
	double GetInternalEndDepth(void) const {return (IsFlip()) ? m_startDepth : m_endDepth;}

	MrDirection GetInternalDirection(bool isCut);

	BODY * ExtrudeStartSolid(BODY *& pProfile, bool isCut = false);
	BODY * ExtrudeEndSolid(BODY *& pProfile, bool isCut = false);

	BODY * ExtrudeWithBlind(BODY *& pProfile, const MrVector & vector);
	BODY * ExtrudeWithThroughAll(BODY *& pProfile, const MrDirection & direction);

	void AttachName(BODY *& pBody);
	void AttachName_pointbased_1(BODY *& pBody);
	void AttachName_pointbased_2(BODY *& pBody);
	
	//void SplitCheck(BODY *& pBody, ENTITY_LIST & old_face_list);

private:
	PmeReference * m_pProfileSketch;
	bool m_isFlip;
	PmeStdExtrudeEndType m_startCondition;
	double m_startDepth;
	PmeStdExtrudeEndType m_endCondition;
	double m_endDepth;
};
