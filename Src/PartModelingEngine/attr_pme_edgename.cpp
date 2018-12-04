#include "stdAfx.h"
#include ".\attr_pme_edgename.h"

#ifdef THIS
#undef THIS
#endif

#define THIS() ATTRIB_EDGENAME
#define THIS_LIB NONE
#define PARENT() ATTRIB_PME
#define PARENT_LIB NONE

#define ATTRIB_EDGENAME_NAME "edgename"

ATTRIB_DEF("edgename_attribute")

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
ATTRIB_EDGENAME::ATTRIB_EDGENAME(ENTITY * owner, const CString & edgeName)
: ATTRIB_PME(owner)
, m_edgeName(edgeName)
{
}

// Virtual function called when an owner entity is being split.
void ATTRIB_EDGENAME::split_owner(ENTITY* new_ent)
{
}

// Virtual function called when two entities are to be merged.
void ATTRIB_EDGENAME::merge_owner(ENTITY * other_ent, logical delete_owner)
{
}

void ATTRIB_EDGENAME::SetEdgeName(const CString & edgeName)
{
	m_edgeName = edgeName;
}

#undef THIS