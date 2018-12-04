// StdSketchControlPointAuto.cpp : CStdSketchControlPointAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchControlPointAuto.h"


// CStdSketchControlPointAuto

HRESULT CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(PmeHStdSketchGeometry hControlPoint, IStdSketchControlPoint** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hControlPoint == 0)
		return S_OK;

	CComObject<CStdSketchControlPointAuto> * pObj = NULL;
	hr = CComObject<CStdSketchControlPointAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hControlPoint);

	hr = pObj->QueryInterface(__uuidof(IStdSketchControlPoint), (void **)ppVal);

	return hr;
}

/*
STDMETHODIMP CStdSketchControlPointAuto::get_Type(StdSketchGeometryType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchControlPointAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchControlPointAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}
*/
STDMETHODIMP CStdSketchControlPointAuto::get_X(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double X, Y;
	PmeStdSketchControlPointAPI::GetPosition(m_hStdSketchGeometry, X, Y);

	*pVal = X;

	return S_OK;
}

STDMETHODIMP CStdSketchControlPointAuto::get_Y(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double X, Y;
	PmeStdSketchControlPointAPI::GetPosition(m_hStdSketchGeometry, X, Y);

	*pVal = Y;

	return S_OK;
}
