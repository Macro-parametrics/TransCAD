// ApplicationAuto.cpp : CApplicationAuto의 구현입니다.

#include "stdafx.h"
#include "ApplicationAuto.h"
#include "MainFrame.h"
#include "DocumentsAuto.h"
#include "PartDocumentAuto.h"
#include "DocumentAuto.h"
#include "AssemDocumentAuto.h"

// CApplicationAuto

STDMETHODIMP CApplicationAuto::get_Visible(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MainFrame * pFrame = static_cast<MainFrame *>(::AfxGetMainWnd());
	if(pFrame == NULL)
		return E_FAIL;

	*pVal = (pFrame->IsWindowVisible() == TRUE) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CApplicationAuto::put_Visible(VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MainFrame * pFrame = static_cast<MainFrame *>(::AfxGetMainWnd());
	if(pFrame == NULL)
		return E_FAIL;

	if(newVal == VARIANT_TRUE)
	{
        pFrame->ShowWindow(SW_SHOW);
        pFrame->UpdateWindow();

		CFrameWnd * pActiveFrame = pFrame->GetActiveFrame();
		if(pActiveFrame != NULL)
		{
			pActiveFrame->ShowWindow(SW_SHOW);
			pActiveFrame->UpdateWindow();
		}
	}
	else
	{
		pFrame->ShowWindow(SW_HIDE);
	}

	return S_OK;
}

STDMETHODIMP CApplicationAuto::get_Application(IApplication** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*ppVal = NULL;
	HRESULT hr = QueryInterface(__uuidof(IApplication), (void **)ppVal);
	
	return hr;
}

STDMETHODIMP CApplicationAuto::get_Parent(IDispatch** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*ppVal = NULL;
	HRESULT hr = QueryInterface(__uuidof(IDispatch), (void **)ppVal);
	
	return hr;
}

STDMETHODIMP CApplicationAuto::get_ActiveDocument(IDoc** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*ppVal = NULL;

	MainFrame * pFrame = static_cast<MainFrame *>(::AfxGetMainWnd());
	if(pFrame == NULL)
		return E_FAIL;

	// 문서가 없는 경우 NULL을 리턴한다.
	CFrameWnd * pChild = pFrame->GetActiveFrame();
	if(pChild == NULL)
		return S_OK;

	CDocument * pDoc = pChild->GetActiveDocument();
	if(pDoc == NULL)
		return S_OK;

	HRESULT hr = E_FAIL;

	if(pDoc->IsKindOf(RUNTIME_CLASS(PmDocument)))
	{
		CComObject<CPartDocumentAuto> * pDocObject = NULL;
		hr = CComObject<CPartDocumentAuto>::CreateInstance(&pDocObject);
		if(FAILED(hr))
			return hr;

		IDocs * pDocuments = NULL;
		hr = get_Documents(&pDocuments);
		if(FAILED(hr))
			return hr;

		IDispatch * pDispatch = NULL;
		hr = pDocuments->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		if(FAILED(hr))
			return hr;

		pDocObject->InitializeDispatchImplEx(this, pDispatch);
		pDocObject->Initialize(static_cast<PmDocument *>(pDoc));
		hr = pDocObject->QueryInterface(__uuidof(IDoc), (void **)ppVal);

		pDispatch->Release();
		pDocuments->Release();
	}
	else if(pDoc->IsKindOf(RUNTIME_CLASS(AssemDocument)))
	{
		CComObject<CAssemDocumentAuto> * pDocObject = NULL;
		hr = CComObject<CAssemDocumentAuto>::CreateInstance(&pDocObject);
		if(FAILED(hr))
			return hr;

		IDocs * pDocuments = NULL;
		hr = get_Documents(&pDocuments);
		if(FAILED(hr))
			return hr;

		IDispatch * pDispatch = NULL;
		hr = pDocuments->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		if(FAILED(hr))
			return hr;

		pDocObject->InitializeDispatchImplEx(this, pDispatch);
		pDocObject->Initialize(static_cast<AssemDocument *>(pDoc));
		hr = pDocObject->QueryInterface(__uuidof(IDoc), (void **)ppVal);

		pDispatch->Release();
		pDocuments->Release();
	}
	else
	{
		CComObject<CDocumentAuto> * pDocObject = NULL;
		hr = CComObject<CDocumentAuto>::CreateInstance(&pDocObject);
		if(FAILED(hr))
			return hr;

		IDocs * pDocuments = NULL;
		hr = get_Documents(&pDocuments);
		if(FAILED(hr))
			return hr;

		IDispatch * pDispatch = NULL;
		hr = pDocuments->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		if(FAILED(hr))
			return hr;

		pDocObject->InitializeDispatchImplEx(this, pDispatch);
		pDocObject->Initialize(static_cast<AssemDocument *>(pDoc));
		hr = pDocObject->QueryInterface(__uuidof(IDoc), (void **)ppVal);

		pDispatch->Release();
		pDocuments->Release();
	}

	return hr;
}

STDMETHODIMP CApplicationAuto::get_Documents(IDocs** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CDocumentsAuto> * pDocuments = NULL;
	hr = CComObject<CDocumentsAuto>::CreateInstance(&pDocuments);
	if(FAILED(hr))
		return hr;

	pDocuments->Initialize(this);

	hr = pDocuments->QueryInterface(__uuidof(IDocs), (void **)ppVal);
	if(FAILED(hr))
		return hr;
	
	return S_OK;
}
STDMETHODIMP CApplicationAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name = ::AfxGetAppName();
	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CApplicationAuto::Quit(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MainFrame * pFrame = static_cast<MainFrame *>(::AfxGetMainWnd());
	if(pFrame == NULL)
		return E_FAIL;

	pFrame->SendMessage(WM_CLOSE);

	return S_OK;
}