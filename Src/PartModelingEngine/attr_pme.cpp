#include "stdafx.h"
#include <cstdio>
#include ".\attr_pme.h"

#ifdef THIS
#undef THIS
#endif

#define THIS() ATTRIB_PME
#define THIS_LIB NONE
#define PARENT() ATTRIB
#define PARENT_LIB KERN 
#define ATTRIB_PME_NAME "Pme"

MASTER_ATTRIB_DEFN( "Pme_attribute" );

#undef THIS