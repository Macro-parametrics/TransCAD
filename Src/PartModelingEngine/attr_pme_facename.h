#pragma once

#include ".\attr_pme.h"

extern int ATTRIB_FACENAME_TYPE;
#define ATTRIB_FACENAME_LEVEL (ATTRIB_PME_LEVEL + 1)

class ATTRIB_FACENAME: public ATTRIB_PME
{
private:
	CString m_faceName;

public:
	ATTRIB_FACENAME(ENTITY * owner = NULL, const CString & faceName = _T(""));

	CString GetFaceName(void) const {return m_faceName;}
	void SetFaceName(const CString & faceName);

	virtual void split_owner(ENTITY * new_ent);
	virtual void merge_owner(ENTITY * other_ent, logical delete_owner);
	ATTRIB_FUNCTIONS(ATTRIB_FACENAME, NONE)
};