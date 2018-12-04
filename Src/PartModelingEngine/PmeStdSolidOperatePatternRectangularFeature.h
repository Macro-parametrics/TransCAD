#pragma once
#include "PmeStdSolidFeature.h"
#include "IPmePattern.h"

class PmePart;
class PmeFeature;
//class PmeReference;
class PmeReferences;

class PmeStdSolidOperatePatternRectangularFeature :
	public PmeStdSolidFeature
	//,public IPmePattern
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidOperatePatternRectangularFeature)
public:
	PmeStdSolidOperatePatternRectangularFeature(PmePart * pPart);
	PmeStdSolidOperatePatternRectangularFeature(PmePart * pPart,
								 PmeReferences * pTargetFeatures,
								 double columnSpacing,
                                 const MrDirection & columnDirection,
                                 int columnNumber,
                                 double rowSpacing,
                                 const MrDirection & rowDirection,
                                 int rowNumber);

	virtual ~PmeStdSolidOperatePatternRectangularFeature(void);

	PmeReferences * GetTargetFeatures(void) const {return m_pTargetFeatures;}
	double GetColumnSpacing(void) const {return m_columnSpacing;}
	MrDirection GetColumnDirection(void) const {return m_columnDirection;}
	int GetColumnNumber(void) const {return m_columnNumber;}
	double GetRowSpacing(void) const {return m_rowSpacing;}
	MrDirection GetRowDirection(void) const {return m_rowDirection;}
	int GetRowNumber(void) const {return m_rowNumber;}

	void SetTargetFeatures(PmeReferences * pTargetFeatures) { m_pTargetFeatures = pTargetFeatures->Clone(); }
	void SetColumnSpacing(double colSpacing) { m_columnSpacing = colSpacing; }
	void SetColumnDirection(MrDirection colDirection) { m_columnDirection; }
	void SetColumnNumber(int columnNumber) { m_columnNumber = columnNumber; }
	void SetRowSpacing(double rowSpacing) { m_rowSpacing = rowSpacing; }
	void SetRowDirection(MrDirection rowDirection) { m_rowDirection = rowDirection; }
	void SetRowNumber(int rowNumber) { m_rowNumber = rowNumber; }

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidOperatePatternRectangularFeature;}
	virtual void Update(void);
	
	// IPmePattern
	//virtual void Transform(const SPAtransf & transformation, BODY *& pBody);
	//virtual bool IsCut(void);
	//BODY * GetPatternBody() { return pPatternBody; }

	int GetPatternBodySize(void) { return (int)m_bodyList.size(); }
	BODY * GetPatternBody(int index) { return m_bodyList[index]; }
	BOOL_TYPE GetPatternBodyType(int index) { return m_boolTypeList[index]; }
	
	void CreateSolidBody(void);
	void CreateSolidBody(BODY *& pBody);

private:
	void CreatePatternBody(BODY *& pBody);
	void TranslateBody(BODY *& pBody, int colNum, int rowNum);
	void ReorderTargetFeatures(void);

protected:
	void AttachName(BODY *& pBody, int colNum, int rowNum);
	void CopyFaceNames(BODY *& pOldBody, BODY *& pNewBody);

private:
	PmeReferences * m_pTargetFeatures;
	std::vector<PmeFeature *> m_featureList;
	std::vector<PmeSolid *> m_solidList;
	std::vector<BODY *> m_bodyList;
	std::vector<BOOL_TYPE> m_boolTypeList;
	double m_columnSpacing;
    MrDirection m_columnDirection;
    int m_columnNumber;
    double m_rowSpacing;
    MrDirection m_rowDirection;
    int m_rowNumber;
	bool isCut;
};