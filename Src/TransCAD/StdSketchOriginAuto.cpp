// StdSketchOriginAuto.cpp : CStdSketchOriginAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchOriginAuto.h"


// CStdSketchOriginAuto

HRESULT CStdSketchOriginAuto::GetIStdSketchOriginFromHStdSketchOrigin(PmeHStdSketchOrigin hOrigin, IStdSketchOrigin** ppVal)
{
	
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hOrigin == 0)
		return S_OK;

	CComObject<CStdSketchOriginAuto> * pObj = NULL;
	hr = CComObject<CStdSketchOriginAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hOrigin);

	hr = pObj->QueryInterface(__uuidof(IStdSketchOrigin), (void **)ppVal);

	return hr;
}

STDMETHODIMP CStdSketchOriginAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchOriginAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}
