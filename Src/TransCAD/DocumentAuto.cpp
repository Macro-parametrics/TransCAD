// DocumentAuto.cpp : CDocumentAuto의 구현입니다.

#include "stdafx.h"
#include "DocumentAuto.h"


// CDocumentAuto

void CDocumentAuto::Initialize(CDocument * pDocument)
{
	m_pDocument = pDocument;
}

STDMETHODIMP CDocumentAuto::get_FullName(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString fullname = m_pDocument->GetPathName();
	fullname.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CDocumentAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name = m_pDocument->GetPathName();
	name = name.Right(name.GetLength() - name.ReverseFind('\\') - 1);
	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CDocumentAuto::get_Path(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString path = m_pDocument->GetPathName();
	path = path.Left(path.ReverseFind('\\'));
	path.SetSysString(pVal);

	return S_OK;
}


STDMETHODIMP CDocumentAuto::get_Saved(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CDocumentAuto::Activate(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CDocumentAuto::Close(VARIANT_BOOL saveChanges, BSTR filename)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CDocumentAuto::Save(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CDocumentAuto::SaveAs(BSTR filename)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

