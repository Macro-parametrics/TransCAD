// StdSolidHoleCountersunkFeatureAuto.cpp : CStdSolidHoleCountersunkFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidHoleCountersunkFeatureAuto.h"


// CStdSolidHoleCountersunkFeatureAuto


STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_TargetFace(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidHoleCountersunkFeatureAPI::GetTargetFace(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_CenterPoint(double* cx, double* cy, double* cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSolidHoleCountersunkFeatureAPI::GetCenterX(m_hFeature, (*cx));
	PmeStdSolidHoleCountersunkFeatureAPI::GetCenterY(m_hFeature, (*cy));
	PmeStdSolidHoleCountersunkFeatureAPI::GetCenterZ(m_hFeature, (*cz));

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_Radius(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSolidHoleCountersunkFeatureAPI::GetRadius(m_hFeature, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_Depth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth;
	PmeStdSolidHoleCountersunkFeatureAPI::GetDepth(m_hFeature, depth);

	*pVal = depth;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_SinkRadius(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSolidHoleCountersunkFeatureAPI::GetSinkRadius(m_hFeature, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_SinkAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angle;
	PmeStdSolidHoleCountersunkFeatureAPI::GetSinkAngle(m_hFeature, angle);

	*pVal = angle;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::get_BottomAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angle;
	PmeStdSolidHoleCountersunkFeatureAPI::GetBottomAngle(m_hFeature, angle);

	*pVal = angle;

	return S_OK;
}


STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::put_TargetFace(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidHoleCountersunkFeatureAPI::SetTargetFace(m_hFeature, hReference);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::PutCenterPoint(double cx, double cy, double cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSolidHoleCountersunkFeatureAPI::SetCenterX(m_hFeature, cx);
	PmeStdSolidHoleCountersunkFeatureAPI::SetCenterY(m_hFeature, cy);
	PmeStdSolidHoleCountersunkFeatureAPI::SetCenterZ(m_hFeature, cz);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::put_Radius(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius = pVal;
	PmeStdSolidHoleCountersunkFeatureAPI::SetRadius(m_hFeature, radius);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::put_Depth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth = pVal;
	PmeStdSolidHoleCountersunkFeatureAPI::SetDepth(m_hFeature, depth);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::put_SinkRadius(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius = pVal;
	PmeStdSolidHoleCountersunkFeatureAPI::SetSinkRadius(m_hFeature, radius);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::put_SinkAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angle = pVal;
	PmeStdSolidHoleCountersunkFeatureAPI::SetSinkAngle(m_hFeature, angle);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCountersunkFeatureAuto::put_BottomAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angle = pVal;
	PmeStdSolidHoleCountersunkFeatureAPI::SetBottomAngle(m_hFeature, angle);

	return S_OK;
}