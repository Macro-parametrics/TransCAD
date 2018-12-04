#pragma once
#include "pmeobject.h"
#include ".\PmeExplicitModelObjectType.h"

class PmeFeature;

class PmeExplicitModelObject
	: public PmeObject
{
	PME_DECLARE_RUNTIME_TYPE(PmeExplicitModelObject)
public:
	PmeExplicitModelObject(void);
	PmeExplicitModelObject(const CString & name);
	virtual ~PmeExplicitModelObject(void);

	virtual PmeExplicitModelObjectType GetType(void) const = 0;
	
	void SetCreator(PmeFeature * pCreator) {m_pCreator = pCreator;}
	PmeFeature * GetCreator(void) const {return m_pCreator;}
	

	CString GetName(void) const {return m_name;}
	void SetName(const CString & name) {m_name = name;}

private:
	CString m_name;
	PmeFeature * m_pCreator;
};
