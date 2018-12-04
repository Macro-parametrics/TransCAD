#include "StdAfx.h"
#include ".\PmeStdDatumPlaneFeature.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdDatumPlaneFeature, PmeStdDatumFeature)

PmeStdDatumPlaneFeature::PmeStdDatumPlaneFeature(PmePart * pPart)
: PmeStdDatumFeature(pPart)
{
}

PmeStdDatumPlaneFeature::PmeStdDatumPlaneFeature(PmePart * pPart, const CString & name)
: PmeStdDatumFeature(pPart, name)
{
}

PmeStdDatumPlaneFeature::~PmeStdDatumPlaneFeature(void)
{
}
