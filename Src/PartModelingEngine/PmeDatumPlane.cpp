#include "StdAfx.h"
#include ".\PmeDatumPlane.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeDatumPlane, PmeExplicitModelObject)

PmeDatumPlane::PmeDatumPlane(void)
: m_location(MrAxis2::OXY())
{
	isOffset = false;
}

PmeDatumPlane::PmeDatumPlane(const MrAxis2 & location)
: m_location(location)
{
	isOffset = false;
}

PmeDatumPlane::~PmeDatumPlane(void)
{
}
