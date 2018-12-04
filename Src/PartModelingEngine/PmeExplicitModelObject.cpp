#include "StdAfx.h"
#include ".\pmeexplicitmodelobject.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeExplicitModelObject, PmeObject)

PmeExplicitModelObject::PmeExplicitModelObject(void)
: m_name(_T(""))
, m_pCreator(0)
{	
}

PmeExplicitModelObject::PmeExplicitModelObject(const CString & name)
: m_name(name)
{
}

PmeExplicitModelObject::~PmeExplicitModelObject(void)
{
}