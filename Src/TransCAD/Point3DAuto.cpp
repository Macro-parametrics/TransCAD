// Point3DAuto.cpp : CPoint3DAuto의 구현입니다.

#include "stdafx.h"
#include "Point3DAuto.h"


// CPoint3DAuto

STDMETHODIMP CPoint3DAuto::get_X(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*pVal = m_point3D.X();

	return S_OK;
}

STDMETHODIMP CPoint3DAuto::get_Y(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*pVal = m_point3D.Y();

	return S_OK;
}

STDMETHODIMP CPoint3DAuto::get_Z(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	*pVal = m_point3D.Z();

	return S_OK;
}

STDMETHODIMP CPoint3DAuto::put_X(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	m_point3D.SetX(pVal);

	return S_OK;
}

STDMETHODIMP CPoint3DAuto::put_Y(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	m_point3D.SetY(pVal);

	return S_OK;
}

STDMETHODIMP CPoint3DAuto::put_Z(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	m_point3D.SetZ(pVal);

	return S_OK;
}