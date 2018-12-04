#include "StdAfx.h"
#include ".\pmebrepreference.h"
#include ".\PmePersistentName.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentNullException.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeBrepReference, PmeReference)

PmeBrepReference::PmeBrepReference(PmePart * pPart, ENTITY * pEntity)
: PmeReference(pPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!pEntity);

	CString name = PmePersistentName::FindName(pEntity);

	SetReferenceeName(name);

	CString typeName = pEntity->type_name();

	if(typeName == _T("edge"))
		m_brepType = PmeBrepType_Edge;
	else if(typeName == _T("vertex"))
		m_brepType = PmeBrepType_Vertex;
	else if(typeName == _T("face"))
		m_brepType = PmeBrepType_Face;

}

PmeBrepReference::~PmeBrepReference(void)
{
}

PmeBrepType PmeBrepReference::GetBrepType(void) const
{
	return m_brepType;	
}