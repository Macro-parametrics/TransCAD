#include "StdAfx.h"
#include ".\pmefeaturereference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeFeature.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeFeatureReference, PmeReference)

PmeFeatureReference::PmeFeatureReference(PmePart * pPart, PmeFeature * pFeature)
: PmeReference(pPart)
{
	PmeThrowExceptionIf<PmeArgumentNullException>(!pFeature);

	SetReferenceeName(pFeature->GetName());
}

PmeFeatureReference::~PmeFeatureReference(void)
{
}