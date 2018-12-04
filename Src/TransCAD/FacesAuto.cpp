// FacesAuto.cpp : CFacesAuto의 구현입니다.

#include "stdafx.h"
#include "FacesAuto.h"
#include "FaceAuto.h"

// CFacesAuto

STDMETHODIMP CFacesAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	int size;
	PmeFacesAPI::GetSize(m_hFaces, size);

	*pVal = (long)size;
	
	return S_OK;
}

STDMETHODIMP CFacesAuto::get_Item(long index, IFace** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	PmeHFace hFace;
	PmeFacesAPI::GetItem(m_hFaces, (int)index - 1, hFace);

	HRESULT hr = GetIFaceFromHFace(hFace, ppVal);
	
	return hr;
}

STDMETHODIMP CFacesAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	
	int size;
	PmeFacesAPI::GetSize(m_hFaces, size);

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHFace hFace;
		PmeFacesAPI::GetItem(m_hFaces, i, hFace);
		
		IFace * pFace= NULL;
		
		hr = GetIFaceFromHFace(hFace, &pFace);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pFace->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pFace->Release();
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

HRESULT CFacesAuto::GetIFaceFromHFace(PmeHFace hFace, IFace** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hFace == 0)
		return S_OK;

	CComObject<CFaceAuto> * pObj = NULL;
	hr = CComObject<CFaceAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hFace);

	hr = pObj->QueryInterface(__uuidof(IFace), (void **)ppVal);

	return hr;
}