#include "StdAfx.h"
#include ".\PmeStdDatumFeature.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdDatumFeature, PmeStdFeature)

PmeStdDatumFeature::PmeStdDatumFeature(PmePart * pPart)
: PmeStdFeature(pPart)
{
}

PmeStdDatumFeature::PmeStdDatumFeature(PmePart * pPart, const CString & name)
: PmeStdFeature(pPart, name)
{
}

PmeStdDatumFeature::~PmeStdDatumFeature(void)
{
}
