#include "stdAfx.h"
#include ".\attr_pme_facename.h"

#ifdef THIS
#undef THIS
#endif

#define THIS() ATTRIB_FACENAME
#define THIS_LIB NONE
#define PARENT() ATTRIB_PME
#define PARENT_LIB NONE

#define ATTRIB_FACENAME_NAME "facename"

ATTRIB_DEF("facename_attribute")

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
ATTRIB_FACENAME::ATTRIB_FACENAME(ENTITY * owner, const CString & faceName)
: ATTRIB_PME(owner)
, m_faceName(faceName)
{
}

// Virtual function called when an owner entity is being split.
void ATTRIB_FACENAME::split_owner(ENTITY* new_ent)
{
}

// Virtual function called when two entities are to be merged.
void ATTRIB_FACENAME::merge_owner(ENTITY * other_ent, logical delete_owner)
{
	backup();
}

void ATTRIB_FACENAME::SetFaceName(const CString & faceName)
{
	m_faceName = faceName;
}

#undef THIS