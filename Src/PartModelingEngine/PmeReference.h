#pragma once
#include ".\PmeObject.h"
#include ".\PmeReferenceType.h"

class PmePart;

class PmeReference
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeReference)
public:
	PmeReference(PmePart * pPart);
	PmeReference(PmePart * pPart, const CString & name);
	virtual ~PmeReference(void);

	virtual PmeReferenceType GetReferenceType(void) const = 0;

	CString GetName(void) const {return m_name;}
	PmePart * GetPart(void) const {return m_pPart;}

	void SetName(const CString & name);
	void GiveDefaultName(void);

	void SetReferenceeName(const CString & name) {m_referenceeName = name;}
	CString GetReferenceeName(void) const {return m_referenceeName;}

	virtual void Update(void);

private:
	bool CheckName(const CString & name) const;

private:
	PmePart * m_pPart;
	CString m_name;
	CString m_referenceeName;
};