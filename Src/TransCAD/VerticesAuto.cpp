// VerticesAuto.cpp : CVerticesAuto의 구현입니다.

#include "stdafx.h"
#include "VerticesAuto.h"
#include "VertexAuto.h"
#include "SolidAuto.h"
// CVerticesAuto

STDMETHODIMP CVerticesAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	int size;
	PmeVerticesAPI::GetSize(m_hVertices, size);

	*pVal = (long)size;
	
	return S_OK;
}

STDMETHODIMP CVerticesAuto::get_Item(long index, IVertex** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	PmeHVertex hVertex;
	PmeVerticesAPI::GetItem(m_hVertices, (int)index - 1, hVertex);

	HRESULT hr = CSolidAuto::GetIVertexFromHVertex(hVertex, ppVal);
	
	return hr;
}

STDMETHODIMP CVerticesAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	
	int size;
	PmeEdgesAPI::GetSize(m_hVertices, size);

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHVertex hVertex;
		PmeVerticesAPI::GetItem(m_hVertices, i, hVertex);
		
		IVertex * pVertex = NULL;
		
		hr = CSolidAuto::GetIVertexFromHVertex(hVertex, &pVertex);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pVertex->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pVertex->Release();
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