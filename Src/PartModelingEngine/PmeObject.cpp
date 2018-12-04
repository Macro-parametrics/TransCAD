#include "StdAfx.h"
#include ".\pmeobject.h"

const PmeRuntimeType PmeObject::s_runtimeTypePmeObject = PmeRuntimeType(_T("PmeObject"));

PmeRuntimeType const * PmeObject::GetRuntimeType(void) const
{
	return &s_runtimeTypePmeObject;
}

PmeObject::PmeObject(void)
{
}

PmeObject::~PmeObject(void)
{
}

bool PmeObject::IsInstanceOf(const PmeRuntimeType * pRuntimeType) const
{
	return GetRuntimeType()->IsSubclassOf(pRuntimeType);
}