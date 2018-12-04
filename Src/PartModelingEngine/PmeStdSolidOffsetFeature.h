#pragma once
#include "pmestdsolidfeature.h"


class PmePart;
class PmeReferences;

class PmeStdSolidOffsetFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidOffsetFeature)
public:
	PmeStdSolidOffsetFeature(PmePart * pPart);
	PmeStdSolidOffsetFeature(PmePart * pPart,
							PmeReferences * pTargetFaces,
							double thickness);

	virtual ~PmeStdSolidOffsetFeature(void);

	PmeReferences * GetTargetFaces(void) const {return m_pTargetFaces;}
	double GetThickness(void) const {return m_thickness;}

	void SetTargetFaces(PmeReferences * pTargetFaces) {m_pTargetFaces = pTargetFaces->Clone();}
	void SetThickness(double thickness) {m_thickness = thickness;}

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidOffsetFeature;}
	virtual void Update(void);

protected:
	void AttachName(BODY *& pBody);
	void GetElementsfromFaceName(CString faceName, CString & tempElementsName);

private:
	PmeReferences * m_pTargetFaces;
	double m_thickness;
};
