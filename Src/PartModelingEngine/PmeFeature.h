#pragma once
#include "pmeobject.h"
#include "PmeFeatureType.h"
#include "PmeReference.h"
#include "PmeReferences.h"
#include "PmeFeatureTagMarker.h"
#include <vector>

class PmePart;

class PmeFeature
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeFeature)
public:
	PmeFeature(PmePart * pPart);
	PmeFeature(PmePart * pPart, const CString & name);
	virtual ~PmeFeature(void);

	virtual PmeFeatureType GetFeatureType(void) const = 0;

	CString GetName(void) const {return m_name;}
	void SetName(const CString & name);
	
	CString GetParentName(int index) const { return m_parentNames[index]; }
	void SetParentName(PmeReference * pReference);
	void SetParentName(PmeReferences * pReferences);
	int GetParentNameListSize(void) { return (int)m_parentNames.size(); }

	PmePart * GetPart(void) const {return m_pPart;}
	
	void GiveDefaultName(void);

	virtual void Update(void);

	int GetOrder(void);

	void AttachFeatureTag(BODY * pBody);
	void AttachFeatureTagToNewFaces(BODY * pBody);

private:
	bool CheckName(const CString & name) const;
	void GetTargetFeaturesFromBrepName(CString brepName);
	void GetTargetFeaturesFromFaceName(CString faceName);

private:
	PmePart * m_pPart;
	CString m_name;
	std::vector<CString> m_parentNames;
};
