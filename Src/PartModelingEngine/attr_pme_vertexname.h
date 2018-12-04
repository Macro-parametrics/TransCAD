#pragma once

#include ".\attr_pme.h"

extern int ATTRIB_VERTEXNAME_TYPE;
#define ATTRIB_VERTEXNAME_LEVEL (ATTRIB_PME_LEVEL + 1)

class ATTRIB_VERTEXNAME: public ATTRIB_PME
{
private:
	CString m_vertexName;

public:
	ATTRIB_VERTEXNAME(ENTITY * owner = NULL, const CString & vertexName = _T(""));

	CString GetVertexName(void) const {return m_vertexName;}
	void SetVertexName(const CString & vertexName);

	virtual void split_owner(ENTITY * new_ent);
	virtual void merge_owner(ENTITY * other_ent, logical delete_owner);
	ATTRIB_FUNCTIONS(ATTRIB_VERTEXNAME, NONE)
};