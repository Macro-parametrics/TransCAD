// AssemDocumentAuto.cpp : CAssemDocumentAuto의 구현입니다.

#include "stdafx.h"
#include "AssemDocumentAuto.h"
#include "AssemAuto.h"



// CAssemDocumentAuto
void CAssemDocumentAuto::Initialize(AssemDocument * pDocument)
{
	m_pDocument = pDocument;
}
STDMETHODIMP CAssemDocumentAuto::get_FullName(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString fullname = m_pDocument->GetPathName();
	fullname.SetSysString(pVal);
	
	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name = m_pDocument->GetPathName();
	name = name.Right(name.GetLength() - name.ReverseFind('\\') - 1);
	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::get_Path(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString path = m_pDocument->GetPathName();
	path = path.Left(path.ReverseFind('\\'));
	path.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::get_Saved(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::Activate(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::Close(VARIANT_BOOL saveChanges, BSTR filename)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::Save(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return (m_pDocument->DoFileSave() == TRUE) ? S_OK : E_FAIL;
}

STDMETHODIMP CAssemDocumentAuto::SaveAs(BSTR filename)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strFilename(filename);

	return S_OK ;
}

STDMETHODIMP CAssemDocumentAuto::get_Assem(IAssem** pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());	

	HRESULT hr;
	CComObject<CAssemAuto> * pAssemObject = NULL;
	hr = CComObject<CAssemAuto>::CreateInstance(&pAssemObject);
	if(FAILED(hr))
		return hr;

	pAssemObject->InitializeDispatchImplEx(m_pApplication, this);
	pAssemObject->Initialize(m_pDocument->GetAssembly());

	hr = pAssemObject->QueryInterface(__uuidof(IAssem), (void **)pVal);

	return S_OK;
}

STDMETHODIMP CAssemDocumentAuto::Update(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	m_pDocument->UpdateAll();

	return S_OK;
}


STDMETHODIMP CAssemDocumentAuto::test(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	//m_pDocument->OnContacttypeContact();

	return S_OK;
}
