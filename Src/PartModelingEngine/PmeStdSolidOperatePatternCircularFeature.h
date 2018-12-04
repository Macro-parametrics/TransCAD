#pragma once
#include "PmeStdSolidFeature.h"
#include "IPmePattern.h"

class PmePart;
class PmeFeature;
class PmeReference;
class PmeReferences;

class PmeStdSolidOperatePatternCircularFeature :
	public PmeStdSolidFeature
	//,public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidOperatePatternCircularFeature)
public:
	PmeStdSolidOperatePatternCircularFeature(PmePart * pPart);
	PmeStdSolidOperatePatternCircularFeature(PmePart * pPart,
								 PmeReferences * pTargetFeatures,
								 const MrAxis1 & centerAxis,
                                 int angleNumber,
                                 double angleIncrement,
								 int radialNumber,
                                 double radialSpacing,
                                 bool radialAlignment);

	virtual ~PmeStdSolidOperatePatternCircularFeature(void);

	PmeReferences * GetTargetFeatures(void) const {return m_pTargetFeatures;}
	MrAxis1 GetCenterAxis(void) const {return m_centerAxis;}
	int GetAngleNumber(void) const {return m_angleNumber;}
	double GetAngleIncrement(void) const {return m_angleIncrement;}
	int GetRadialNumber(void) const {return m_radialNumber;}
	double GetRadialSpacing(void) const {return m_radialSpacing;}
	bool IsRadialAnignment(void) const {return m_radialAlignment;}
	
	void SetTargetFeatures(PmeReferences * pTargetFeatures) { m_pTargetFeatures = pTargetFeatures->Clone();}
	void SetCenterAxis(MrAxis1 centerAxis) { m_centerAxis = centerAxis;}
	void SetAngleNumber(int angleNumber) { m_angleNumber = angleNumber;}
	void SetAngleIncrement(double angleIncrement) { m_angleIncrement = angleIncrement;}
	void SetRadialNumber(int radialNumber) { m_radialNumber = radialNumber;}
	void SetRadialSpacing(double radialSpacing) { m_radialSpacing = radialSpacing;}
	void SetRadialAlignment(bool radialAlignment) { m_radialAlignment = radialAlignment;}
	
	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidOperatePatternCircularFeature;}
	virtual void Update(void);

	// IPmePattern
	//virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	//virtual bool IsCut(void);
	//BODY * GetPatternBody() { return pPatternBody; }

	int GetPatternBodySize(void) { return (int)m_bodyList.size(); }
	BODY * GetPatternBody(int index) { return m_bodyList[index]; }
	BOOL_TYPE GetPatternBodyType(int index) { return m_boolTypeList[index]; }
	
	void CreateSolidBody(void);

private:
	void CreatePatternBody(BODY *& pBody);
	void RotateBody(BODY *& pBody, int angleNum, int radialNum);
	void ReorderTargetFeatures(void);

protected:
	void AttachName(BODY *& pBody, int angleNum, int radialNum);
	void CopyFaceNames(BODY *& pOldBody, BODY *& pNewBody);

private:
	PmeReferences * m_pTargetFeatures;
	std::vector<PmeFeature *> m_featureList;
	std::vector<PmeSolid *> m_solidList;
	std::vector<BODY *> m_bodyList;
	std::vector<BOOL_TYPE> m_boolTypeList;
	MrAxis1 m_centerAxis;
    int m_angleNumber;
    double m_angleIncrement;
	int m_radialNumber;
    double m_radialSpacing;
	bool m_radialAlignment;
	bool isCut;	
};