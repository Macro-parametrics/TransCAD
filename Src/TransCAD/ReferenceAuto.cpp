// ReferenceAuto.cpp : CReferenceAuto의 구현입니다.

#include "stdafx.h"
#include "ReferenceAuto.h"

// CReferenceAuto

void CReferenceAuto::Initialize(PmeHReference hReference)
{
	m_hReference = hReference;
}

STDMETHODIMP CReferenceAuto::get_Type(ReferenceType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeReferenceType type;
	PmeReferenceAPI::GetType(m_hReference, type);

	*pVal = ConvertPmeReferenceTypeToReferenceType(type);

	return S_OK;
}

STDMETHODIMP CReferenceAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;
	PmeReferenceAPI::GetName(m_hReference, name);

	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CReferenceAuto::get_ReferenceeName(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;
	PmeReferenceAPI::GetReferenceeName(m_hReference, name);

	name.SetSysString(pVal);

	return S_OK;
}

ReferenceType CReferenceAuto::ConvertPmeReferenceTypeToReferenceType(PmeReferenceType type)
{
	return (ReferenceType)type;
}