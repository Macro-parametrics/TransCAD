// StdSketchCircleAuto.cpp : CStdSketchCircleAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchCircleAuto.h"
#include "StdSketchControlPointAuto.h"


// CStdSketchCircleAuto

/*
STDMETHODIMP CStdSketchCircleAuto::get_Type(StdSketchGeometryType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchCircleAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchCircleAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}
*/

STDMETHODIMP CStdSketchCircleAuto::get_CenterPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hCenterPoint;
	PmeStdSketchCircleAPI::GetCenterPoint(m_hStdSketchGeometry, hCenterPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hCenterPoint, ppVal);
}

STDMETHODIMP CStdSketchCircleAuto::get_Radius(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSketchCircleAPI::GetRadius(m_hStdSketchGeometry, radius);

	*pVal = radius;

	return S_OK;
}
