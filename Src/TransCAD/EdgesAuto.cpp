// EdgesAuto.cpp : CEdgesAuto의 구현입니다.

#include "stdafx.h"
#include "EdgesAuto.h"
#include "EdgeAuto.h"

// CEdgesAuto


STDMETHODIMP CEdgesAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	int size;
	PmeEdgesAPI::GetSize(m_hEdges, size);

	*pVal = (long)size;
	
	return S_OK;
}

STDMETHODIMP CEdgesAuto::get_Item(long index, IEdge** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	PmeHEdge hEdge;
	PmeEdgesAPI::GetItem(m_hEdges, (int)index - 1, hEdge);

	HRESULT hr = GetIEdgeFromHEdge(hEdge, ppVal);
	
	return hr;
}

STDMETHODIMP CEdgesAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	
	int size;
	PmeEdgesAPI::GetSize(m_hEdges, size);

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHEdge hEdge;
		PmeEdgesAPI::GetItem(m_hEdges, i, hEdge);
		
		IEdge * pEdge = NULL;
		
		hr = GetIEdgeFromHEdge(hEdge, &pEdge);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pEdge->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pEdge->Release();
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

HRESULT CEdgesAuto::GetIEdgeFromHEdge(PmeHEdge hEdge, IEdge** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hEdge == 0)
		return S_OK;

	CComObject<CEdgeAuto> * pObj = NULL;
	hr = CComObject<CEdgeAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hEdge);

	hr = pObj->QueryInterface(__uuidof(IEdge), (void **)ppVal);

	return hr;
}