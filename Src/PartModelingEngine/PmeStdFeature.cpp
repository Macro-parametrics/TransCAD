#include "StdAfx.h"
#include ".\pmestdfeature.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdFeature, PmeFeature)

PmeStdFeature::PmeStdFeature(PmePart * pPart)
: PmeFeature(pPart)
{
}

PmeStdFeature::PmeStdFeature(PmePart * pPart, const CString & name)
: PmeFeature(pPart, name)
{
}

PmeStdFeature::~PmeStdFeature(void)
{
}
