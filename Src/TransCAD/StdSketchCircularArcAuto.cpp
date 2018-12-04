// StdSketchCircularArcAuto.cpp : CStdSketchCircularArcAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchCircularArcAuto.h"
#include "StdSketchControlPointAuto.h"


// CStdSketchCircularArcAuto

/*
STDMETHODIMP CStdSketchCircularArcAuto::get_Type(StdSketchGeometryType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchCircularArcAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchCircularArcAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}
*/

STDMETHODIMP CStdSketchCircularArcAuto::get_CenterPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hCenterPoint;
	PmeStdSketchCircularArcAPI::GetCenterPoint(m_hStdSketchGeometry, hCenterPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hCenterPoint, ppVal);
}

STDMETHODIMP CStdSketchCircularArcAuto::get_StartPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hStartPoint;
	PmeStdSketchCircularArcAPI::GetStartPoint(m_hStdSketchGeometry, hStartPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hStartPoint, ppVal);
}

STDMETHODIMP CStdSketchCircularArcAuto::get_EndPoint(IStdSketchControlPoint** ppVal){
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hEndPoint;
	PmeStdSketchCircularArcAPI::GetEndPoint(m_hStdSketchGeometry, hEndPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hEndPoint, ppVal);
}

STDMETHODIMP CStdSketchCircularArcAuto::get_Radius(double* pVal){
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSketchCircularArcAPI::GetRadius(m_hStdSketchGeometry, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSketchCircularArcAuto::get_StartAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle;
	PmeStdSketchCircularArcAPI::GetStartAngle(m_hStdSketchGeometry, startAngle);

	*pVal = startAngle;

	return S_OK;
}

STDMETHODIMP CStdSketchCircularArcAuto::get_EndAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle;
	PmeStdSketchCircularArcAPI::GetEndAngle(m_hStdSketchGeometry, endAngle);

	*pVal = endAngle;

	return S_OK;
}
