// VertexAuto.cpp : CVertexAuto의 구현입니다.

#include "stdafx.h"
#include "VertexAuto.h"


// CVertexAuto

STDMETHODIMP CVertexAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;
	PmeVertexAPI::GetName(m_hVertex, name);

	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CVertexAuto::get_Coordinates(double* x, double* y, double* z)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition coordinates;
	PmeVertexAPI::GetCoordinates(m_hVertex, coordinates);

	*x = coordinates.X();
	*y = coordinates.Y();
	*z = coordinates.Z();

	return S_OK;
}

STDMETHODIMP CVertexAuto::get_X(double* x)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition coordinates;
	PmeVertexAPI::GetCoordinates(m_hVertex, coordinates);

	*x = coordinates.X();

	return S_OK;
}

STDMETHODIMP CVertexAuto::get_Y(double* y)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition coordinates;
	PmeVertexAPI::GetCoordinates(m_hVertex, coordinates);

	*y = coordinates.Y();

	return S_OK;
}

STDMETHODIMP CVertexAuto::get_Z(double* z)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition coordinates;
	PmeVertexAPI::GetCoordinates(m_hVertex, coordinates);

	*z = coordinates.Z();

	return S_OK;
}