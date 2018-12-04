#pragma once
#include "pmestdsolidfeature.h"


class PmePart;
class PmeReferences;

class PmeStdSolidDraftFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidDraftFeature)
public:
	PmeStdSolidDraftFeature(PmePart * pPart);
	PmeStdSolidDraftFeature(PmePart * pPart,
							PmeReferences * pTargetFaces,
							const MrAxis1 & pullingDirection,
							double draftAngle);

	virtual ~PmeStdSolidDraftFeature(void);

	PmeReferences * GetTargetFaces(void) const {return m_pTargetFaces;}
	MrAxis1 GetPullingDirection(void) const {return m_pullingDirection;}
	double GetDraftAngle(void) const {return m_draftAngle;}
	
	void SetTargetFaces(PmeReferences * pTargetFaces) {m_pTargetFaces = pTargetFaces->Clone();}
	void SetPullingDirection(MrAxis1 pullingDirection) {m_pullingDirection = pullingDirection;}
	void SetDraftAngle(double draftAngle) {m_draftAngle = draftAngle;}
	
	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidDraftFeature;}
	virtual void Update(void);
	
	double DegreeToRadian(double degree) {return M_PI / 180.0 * degree;}

protected:
	void AttachName(BODY *& pBody);
	void GetElementsfromFaceName(CString faceName, CString & tempElementsName);

private:
	PmeReferences * m_pTargetFaces;
	MrAxis1 m_pullingDirection;
	double m_draftAngle;
};
