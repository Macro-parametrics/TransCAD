#include "StdAfx.h"
#include ".\PmeRuntimeType.h"

PmeRuntimeType::PmeRuntimeType(const CString & className, const PmeRuntimeType * pBaseClass)
: m_className(className)
, m_pBaseClass(pBaseClass)
{
}

PmeRuntimeType::~PmeRuntimeType(void)
{
}

bool PmeRuntimeType::IsSubclassOf(const PmeRuntimeType * pBaseClass) const
{
	if(!pBaseClass)
		return false;

	const PmeRuntimeType * pThisClass = this;

	while(pThisClass)
	{
		if(pThisClass == pBaseClass)
			return true;
		pThisClass = pThisClass->BaseClass();
	}

	return false;
}