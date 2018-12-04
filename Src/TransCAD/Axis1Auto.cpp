// Axis1Auto.cpp : CAxis1Auto의 구현입니다.

#include "stdafx.h"
#include "Axis1Auto.h"
#include "PartAuto.h"

// CAxis1Auto

STDMETHODIMP CAxis1Auto::get_Location(IPoint3D** pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CComObject<CPoint3DAuto> * pPoint = NULL;
	HRESULT hr = CComObject<CPoint3DAuto>::CreateInstance(&pPoint);

	pPoint->Initialize(m_axis.Location());

	hr = pPoint->QueryInterface(__uuidof(IPoint3D), (void **)pVal);

	return S_OK;
}

STDMETHODIMP CAxis1Auto::get_Direction(IPoint3D** pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	CComObject<CPoint3DAuto> * pPoint = NULL;
	HRESULT hr = CComObject<CPoint3DAuto>::CreateInstance(&pPoint);

	pPoint->Initialize(MrPosition(m_axis.Direction().X(), m_axis.Direction().Y(), m_axis.Direction().Z()));

	hr = pPoint->QueryInterface(__uuidof(IPoint3D), (void **)pVal);

	return S_OK;
}

STDMETHODIMP CAxis1Auto::put_Location(IPoint3D* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CPoint3DAuto * location = (CPoint3DAuto *)pVal;
	m_axis.SetLocation(location->GetPoint());

	return S_OK;
}

STDMETHODIMP CAxis1Auto::put_Direction(IPoint3D* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CPoint3DAuto * direction = (CPoint3DAuto *)pVal;
	m_axis.SetDirection(MrDirection(direction->GetPoint()));

	return S_OK;
}