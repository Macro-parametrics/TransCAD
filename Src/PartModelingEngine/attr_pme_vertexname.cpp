#include "stdAfx.h"
#include ".\attr_pme_vertexname.h"

#ifdef THIS
#undef THIS
#endif

#define THIS() ATTRIB_VERTEXNAME
#define THIS_LIB NONE
#define PARENT() ATTRIB_PME
#define PARENT_LIB NONE

#define ATTRIB_VERTEXNAME_NAME "vertexname"

ATTRIB_DEF("vertexname_attribute")

SAVE_DEF    
    // Save specific data

RESTORE_DEF
    // (no specific pointer data)

COPY_DEF
    // (no specific pointer data)

SCAN_DEF
    // (no specific pointer data)

FIX_POINTER_DEF
    // (no specific pointer data)

TERMINATE_DEF

// make a color attribute
ATTRIB_VERTEXNAME::ATTRIB_VERTEXNAME(ENTITY * owner, const CString & vertexName)
: ATTRIB_PME(owner)
, m_vertexName(vertexName)
{
}

// Virtual function called when an owner entity is being split.
void ATTRIB_VERTEXNAME::split_owner(ENTITY* new_ent)
{
}

// Virtual function called when two entities are to be merged.
void ATTRIB_VERTEXNAME::merge_owner(ENTITY * other_ent, logical delete_owner)
{
}

void ATTRIB_VERTEXNAME::SetVertexName(const CString & vertexName)
{
	m_vertexName = vertexName;
}

#undef THIS