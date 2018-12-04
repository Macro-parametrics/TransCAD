// ReferencesAuto.cpp : CReferencesAuto의 구현입니다.

#include "stdafx.h"
#include "ReferencesAuto.h"
#include ".\ReferenceAuto.h"
#include ".\PartAuto.h"

// CReferencesAuto

STDMETHODIMP CReferencesAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int size;
	PmeReferencesAPI::GetSize(m_hReferences, size);

	*pVal = (long)size;

	return S_OK;
}

STDMETHODIMP CReferencesAuto::get_Item(long index, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeReferencesAPI::GetItem(m_hReferences, (int)index - 1, hReference);

	HRESULT hr = CPartAuto::GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CReferencesAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	int size;
	PmeReferencesAPI::GetSize(m_hReferences, size);

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHReference hReference;
		PmeReferencesAPI::GetItem(m_hReferences, i, hReference);
		
		IReference * pReference = NULL;
		
		hr = CPartAuto::GetIReferenceFromHReference(hReference, &pReference);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pReference->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pReference->Release();
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

STDMETHODIMP CReferencesAuto::Add(IReference* pReference)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CReferenceAuto * pRef = static_cast<CReferenceAuto *>(pReference);
	if(!pRef)
		return E_INVALIDARG;

	PmeHReference hReference = pRef->GetHReference();

	PmeReferencesAPI::AddItem(m_hReferences, hReference);	

	return S_OK;
}