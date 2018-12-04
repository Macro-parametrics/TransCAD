#include "StdAfx.h"
#include ".\pmeexplicitmodelobjectreference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeExplicitModelObject.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeExplicitModelObjectReference, PmeReference)

PmeExplicitModelObjectReference::PmeExplicitModelObjectReference(PmePart * pPart, PmeExplicitModelObject * pObject)
: PmeReference(pPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!pObject);

	SetReferenceeName(pObject->GetName());
}

PmeExplicitModelObjectReference::~PmeExplicitModelObjectReference(void)
{
}
