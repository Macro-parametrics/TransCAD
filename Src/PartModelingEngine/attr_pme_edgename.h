#pragma once

#include ".\attr_pme.h"

extern int ATTRIB_EDGENAME_TYPE;
#define ATTRIB_EDGENAME_LEVEL (ATTRIB_PME_LEVEL + 1)

class ATTRIB_EDGENAME: public ATTRIB_PME
{
private:
	CString m_edgeName;

public:
	ATTRIB_EDGENAME(ENTITY * owner = NULL, const CString & edgeName = _T(""));

	CString GetEdgeName(void) const {return m_edgeName;}
	void SetEdgeName(const CString & edgeName);

	virtual void split_owner(ENTITY * new_ent);
	virtual void merge_owner(ENTITY * other_ent, logical delete_owner);
	ATTRIB_FUNCTIONS(ATTRIB_EDGENAME, NONE)
};