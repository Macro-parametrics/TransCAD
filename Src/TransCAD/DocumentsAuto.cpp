// DocumentsAuto.cpp : CDocumentsAuto의 구현입니다.

#include "stdafx.h"
#include "DocumentsAuto.h"
#include ".\DocumentAuto.h"
#include ".\PartDocumentAuto.h"
#include "AssemDocumentAuto.h"

// CDocumentsAuto

void CDocumentsAuto::Initialize(IApplication * pApplication)
{
	m_pApplication = pApplication;
	m_pApplication->AddRef();

	GetDocumentsInfo();
}

void CDocumentsAuto::GetDocumentsInfo()
{
	CWinApp * pApp = static_cast<CWinApp *>(::AfxGetApp());
	if(pApp == NULL)
		return;

	m_listDocuments.clear();

	// 하나의 템플릿만 존재
	POSITION pos = pApp->GetFirstDocTemplatePosition();
	CDocTemplate * pDocTemplate = pApp->GetNextDocTemplate(pos);

	if(pDocTemplate == NULL)
		return;

	POSITION posDoc = pDocTemplate->GetFirstDocPosition();
	while(posDoc != NULL)
	{
		CDocument * pDoc = pDocTemplate->GetNextDoc(posDoc);
		m_listDocuments.push_back(pDoc);
	}
}

HRESULT CDocumentsAuto::GetIDocFromDocument(CDocument * pDoc, IDoc** pRet)
{
	HRESULT hr = S_OK;

	if(pDoc->IsKindOf(RUNTIME_CLASS(PmDocument)))
	{
		CComObject<CPartDocumentAuto> * pDocObject = NULL;
		hr = CComObject<CPartDocumentAuto>::CreateInstance(&pDocObject);
		if(FAILED(hr))
			return hr;

		pDocObject->InitializeDispatchImplEx(m_pApplication, this);
		pDocObject->Initialize(static_cast<PmDocument *>(pDoc));

		*pRet = NULL;
		hr = pDocObject->QueryInterface(__uuidof(IDoc), (void **)pRet);
	}
	else if(pDoc->IsKindOf(RUNTIME_CLASS(AssemDocument)))
	{
		CComObject<CAssemDocumentAuto> * pDocObject = NULL;
		hr = CComObject<CAssemDocumentAuto>::CreateInstance(&pDocObject);
		if(FAILED(hr))
			return hr;

		pDocObject->InitializeDispatchImplEx(m_pApplication, this);
		pDocObject->Initialize(static_cast<AssemDocument *>(pDoc));

		*pRet = NULL;
		hr = pDocObject->QueryInterface(__uuidof(IDoc), (void **)pRet);
	}
	else
	{
		CComObject<CDocumentAuto> * pDocObject = NULL;
		hr = CComObject<CDocumentAuto>::CreateInstance(&pDocObject);
		if(FAILED(hr))
			return hr;

		pDocObject->InitializeDispatchImplEx(m_pApplication, this);
		pDocObject->Initialize(pDoc);

		*pRet = NULL;
		hr = pDocObject->QueryInterface(__uuidof(IDoc), (void **)pRet);
	}

	return hr;
}

STDMETHODIMP CDocumentsAuto::get_Application(IApplication** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*ppVal = m_pApplication;
	m_pApplication->AddRef();

	return S_OK;
}

STDMETHODIMP CDocumentsAuto::get_Parent(IDispatch** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*ppVal = NULL;
	HRESULT hr = m_pApplication->QueryInterface(__uuidof(IDispatch), (void **)ppVal);
	if(FAILED(hr))
		return hr;

	return S_OK;
}

STDMETHODIMP CDocumentsAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*pVal = (long)m_listDocuments.size();
	
	return S_OK;
}

STDMETHODIMP CDocumentsAuto::get_Item(long index, IDoc** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	if((index < 1) || (index > (long)m_listDocuments.size()))
		return E_INVALIDARG;

	CDocument * pDoc = m_listDocuments[index - 1];
	HRESULT hr = GetIDocFromDocument(pDoc, ppVal);

	return hr;
}

STDMETHODIMP CDocumentsAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	int size = (int)m_listDocuments.size();

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		CDocument * pDoc = m_listDocuments[i];
		IDoc * pDocument = NULL;
		
		hr = GetIDocFromDocument(pDoc, &pDocument);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pDocument->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pDocument->Release();
		if(FAILED(hr))
			return hr;

		// create a variant and add it to the collection
		CComVariant & var = pVarVect[i];
		var.vt = VT_DISPATCH;
		var.pdispVal = pDispatch;
	}

	hr = pEnumObject->Init(&pVarVect[0], &pVarVect[size], NULL, AtlFlagCopy);
	if(FAILED(hr))
		return hr;

    hr = pEnumObject->QueryInterface(IID_IEnumVARIANT, (void **)ppUnk);
	
	delete [] pVarVect;

	return hr;
}

STDMETHODIMP CDocumentsAuto::AddPartDocument(IPartDocument** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	CWinApp * pApp = static_cast<CWinApp *>(::AfxGetApp());
	if(pApp == NULL)
		return E_FAIL;

	POSITION pos = pApp->GetFirstDocTemplatePosition();
	CDocTemplate * pDocTemplate = pApp->GetNextDocTemplate(pos);

	if(pDocTemplate == NULL)
		return E_FAIL;

	CDocument * pDoc = pDocTemplate->OpenDocumentFile(NULL);
	PmDocument * pPartDoc = static_cast<PmDocument *>(pDoc);
		
	m_listDocuments.push_back(pPartDoc);

	IDoc * pDocument;
	hr = GetIDocFromDocument(pPartDoc, &pDocument);
	if(FAILED(hr))
        return hr;
	
	hr = pDocument->QueryInterface(IID_IPartDocument, (void **)ppVal);
    pDocument->Release();

	return hr;
}


STDMETHODIMP CDocumentsAuto::AddAssemDocument(IAssemDocument** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	CWinApp * pApp = static_cast<CWinApp *>(::AfxGetApp());
	if(pApp == NULL)
		return E_FAIL;

	POSITION pos = pApp->GetFirstDocTemplatePosition();
	CDocTemplate * pDocTemplate = pApp->GetNextDocTemplate(pos);
	pDocTemplate = pApp->GetNextDocTemplate(pos);


	if(pDocTemplate == NULL)
		return E_FAIL;

	CDocument * pDoc = pDocTemplate->OpenDocumentFile(NULL);
	AssemDocument * pAssemDoc = static_cast<AssemDocument *>(pDoc);

	m_listDocuments.push_back(pAssemDoc);

	IDoc * pDocument;
	hr = GetIDocFromDocument(pAssemDoc, &pDocument);
	if(FAILED(hr))
		return hr;

	hr = pDocument->QueryInterface(IID_IAssemDocument, (void **)ppVal);
	pDocument->Release();

	return hr;
}

STDMETHODIMP CDocumentsAuto::Close(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	// TODO: 여기에 구현 코드를 추가합니다.

	return S_OK;
}

STDMETHODIMP CDocumentsAuto::Open(BSTR filename, IPartDocument** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	// TODO: 여기에 구현 코드를 추가합니다.

	HRESULT hr;

	CWinApp * pApp = static_cast<CWinApp *>(::AfxGetApp());
	if(pApp == NULL)
		return E_FAIL;

	POSITION pos = pApp->GetFirstDocTemplatePosition();
	CDocTemplate * pDocTemplate = pApp->GetNextDocTemplate(pos);

	if(pDocTemplate == NULL)
		return E_FAIL;


	CString strFilename(filename);
	//pPartDoc->OnOpenDocument((LPCTSTR)strFilename);

	CDocument * pDoc = pDocTemplate->OpenDocumentFile((LPCTSTR)strFilename);
	PmDocument * pPartDoc = static_cast<PmDocument *>(pDoc);
		
	m_listDocuments.push_back(pPartDoc);

	IDoc * pDocument;
	hr = GetIDocFromDocument(pPartDoc, &pDocument);
	if(FAILED(hr))
        return hr;
	
	hr = pDocument->QueryInterface(IID_IPartDocument, (void **)ppVal);
    pDocument->Release();

	return hr;
}