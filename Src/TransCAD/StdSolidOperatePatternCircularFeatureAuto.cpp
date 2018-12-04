// StdSolidOperatePatternCircularFeatureAuto.cpp : CStdSolidOperatePatternCircularFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidOperatePatternCircularFeatureAuto.h"


// CStdSolidOperatePatternCircularFeatureAuto


STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_TargetFeatures(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hReferences;
	PmeStdSolidOperatePatternCircularFeatureAPI::GetTargetFeatures(m_hFeature, hReferences);

	return CPartAuto::GetIReferencesFromHReferences(hReferences, ppVal);
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_CenterAxis(double* x1, double* y1, double* z1, double* x2, double* y2, double* z2)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis1 centerAxis;

	PmeStdSolidOperatePatternCircularFeatureAPI::GetCenterAxis(m_hFeature, centerAxis);

	*x1 = centerAxis.Location().X();
	*y1 = centerAxis.Location().Y();
	*z1 = centerAxis.Location().Z();

	*x2 = centerAxis.Direction().X();
	*y2 = centerAxis.Direction().Y();
	*z2 = centerAxis.Direction().Z();

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_AngleNumber(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int number;
	PmeStdSolidOperatePatternCircularFeatureAPI::GetAngleNumber(m_hFeature, number);

	*pVal = number;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_AngleIncrement(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angleIncrement;
	PmeStdSolidOperatePatternCircularFeatureAPI::GetAngleIncrement(m_hFeature, angleIncrement);

	*pVal = angleIncrement;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_RadialNumber(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int radialNumber;
	PmeStdSolidOperatePatternCircularFeatureAPI::GetRadialNumber(m_hFeature, radialNumber);

	*pVal = radialNumber;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_RadialSpacing(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radialSpacing;
	PmeStdSolidOperatePatternCircularFeatureAPI::GetRadialSpacing(m_hFeature, radialSpacing);

	*pVal = radialSpacing;

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::get_IsRadialAnignment(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isRadialAlignment;
	PmeStdSolidOperatePatternCircularFeatureAPI::IsRadialAlignment(m_hFeature, isRadialAlignment);

	*pVal = (isRadialAlignment) ? VARIANT_TRUE : VARIANT_FALSE;
	
	return S_OK;
}



STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::put_TargetFeatures(IReferences* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hReferences = 0;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hReferences);
	PmeStdSolidOperatePatternCircularFeatureAPI::SetTargetFeatures(m_hFeature, hReferences);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::PutCenterAxis(double x1, double y1, double z1, double x2, double y2, double z2)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis1 centerAxis(MrPosition(x1, y1, z1), MrDirection(x2, y2, z2));

	PmeStdSolidOperatePatternCircularFeatureAPI::SetCenterAxis(m_hFeature, centerAxis);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::put_AngleNumber(int pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int number = pVal;
	PmeStdSolidOperatePatternCircularFeatureAPI::SetAngleNumber(m_hFeature, number);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::put_AngleIncrement(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angleIncrement = pVal;
	PmeStdSolidOperatePatternCircularFeatureAPI::SetAngleIncrement(m_hFeature, angleIncrement);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::put_RadialNumber(int pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int radialNumber = pVal;
	PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialNumber(m_hFeature, radialNumber);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::put_RadialSpacing(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radialSpacing = pVal;
	PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialSpacing(m_hFeature, radialSpacing);

	return S_OK;
}

STDMETHODIMP CStdSolidOperatePatternCircularFeatureAuto::put_IsRadialAnignment(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isRadialAlignment = pVal?true:false;
	PmeStdSolidOperatePatternCircularFeatureAPI::SetRadialAlignment(m_hFeature, isRadialAlignment);
	
	return S_OK;
}