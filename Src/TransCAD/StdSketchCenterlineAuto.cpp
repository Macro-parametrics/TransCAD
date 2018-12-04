// StdSketchCenterlineAuto.cpp : CStdSketchCenterlineAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchCenterlineAuto.h"
#include "StdSketchControlPointAuto.h"


// CStdSketchCenterlineAuto

STDMETHODIMP CStdSketchCenterlineAuto::get_StartPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hStartPoint;
	PmeStdSketchCenterlineAPI::GetStartPoint(m_hStdSketchGeometry, hStartPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hStartPoint, ppVal);
}

STDMETHODIMP CStdSketchCenterlineAuto::get_EndPoint(IStdSketchControlPoint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometry hEndPoint;
	PmeStdSketchCenterlineAPI::GetEndPoint(m_hStdSketchGeometry, hEndPoint);

	return CStdSketchControlPointAuto::GetIStdSketchControlPointFromHStdSketchGeometry(hEndPoint, ppVal);
}
