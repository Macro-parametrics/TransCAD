// StdSketchLineAuto.cpp : CStdSketchLineAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchLineAuto.h"
#include "StdSketchControlPointAuto.h"


// CStdSketchLineAuto

/*
STDMETHODIMP CStdSketchLineAuto::get_Type(StdSketchGeometryType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchLineAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchLineAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}
*/

STDMETHODIMP CStdSketchLineAuto::get_StartPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hStartPoint;
	PmeStdSketchLineAPI::GetStartPoint(m_hStdSketchGeometry, hStartPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hStartPoint, ppVal);
}

STDMETHODIMP CStdSketchLineAuto::get_EndPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hEndPoint;
	PmeStdSketchLineAPI::GetEndPoint(m_hStdSketchGeometry, hEndPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hEndPoint, ppVal);
}
