#pragma once
#include "pmestdsolidfeature.h"


class PmePart;
class PmeReferences;

class PmeStdSolidShellFeature :
	public PmeStdSolidFeature
{
	PME_DECLARE_RUNTIME_TYPE(PmeStdSolidShellFeature)
public:
	PmeStdSolidShellFeature(PmePart * pPart);
	PmeStdSolidShellFeature(PmePart * pPart,
							PmeReferences * pTargetFaces,
							double innerThickness,
							double outerThickness);

	virtual ~PmeStdSolidShellFeature(void);

	PmeReferences * GetTargetFaces(void) const {return m_pTargetFaces;}
	double GetInnerThickness(void) const {return m_innerThickness;}
	double GetOuterThickness(void) const {return m_outerThickness;}

	void SetTargetFaces(PmeReferences * pTargetFaces) {m_pTargetFaces = pTargetFaces->Clone();}
	void SetInnerThickness(double innerThickness) {m_innerThickness = innerThickness;}
	void SetOuterThickness(double outerThickness) {m_outerThickness = outerThickness;}

	// PmeFeature
	virtual PmeFeatureType GetFeatureType(void) const { return PmeFeatureType_StdSolidShellFeature;}
	virtual void Update(void);

	bool CreateShellBody(BODY *& pBody);

protected:
	void AttachName(BODY *& pBody);
	void GetElementsfromFaceName(CString faceName, CString & tempElementsName);

private:
	PmeReferences * m_pTargetFaces;
	double m_innerThickness;
	double m_outerThickness;
};
