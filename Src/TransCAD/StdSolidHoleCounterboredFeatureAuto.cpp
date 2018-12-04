// StdSolidHoleCounterboredFeatureAuto.cpp : CStdSolidHoleCounterboredFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidHoleCounterboredFeatureAuto.h"


// CStdSolidHoleCounterboredFeatureAuto


STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_TargetFace(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidHoleCounterboredFeatureAPI::GetTargetFace(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_CenterPoint(double* cx, double* cy, double* cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSolidHoleCounterboredFeatureAPI::GetCenterX(m_hFeature, (*cx));
	PmeStdSolidHoleCounterboredFeatureAPI::GetCenterY(m_hFeature, (*cy));
	PmeStdSolidHoleCounterboredFeatureAPI::GetCenterZ(m_hFeature, (*cz));

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_StartRadius(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSolidHoleCounterboredFeatureAPI::GetStartRadius(m_hFeature, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_StartDepth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth;
	PmeStdSolidHoleCounterboredFeatureAPI::GetStartDepth(m_hFeature, depth);

	*pVal = depth;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_EndRadius(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSolidHoleCounterboredFeatureAPI::GetEndRadius(m_hFeature, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_EndDepth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth;
	PmeStdSolidHoleCounterboredFeatureAPI::GetEndDepth(m_hFeature, depth);

	*pVal = depth;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::get_Angle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angle;
	PmeStdSolidHoleCounterboredFeatureAPI::GetAngle(m_hFeature, angle);

	*pVal = angle;

	return S_OK;
}


STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::put_TargetFace(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidHoleCounterboredFeatureAPI::SetTargetFace(m_hFeature, hReference);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::PutCenterPoint(double cx, double cy, double cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSolidHoleCounterboredFeatureAPI::SetCenterX(m_hFeature, cx);
	PmeStdSolidHoleCounterboredFeatureAPI::SetCenterY(m_hFeature, cy);
	PmeStdSolidHoleCounterboredFeatureAPI::SetCenterZ(m_hFeature, cz);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::put_StartRadius(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius = pVal;
	PmeStdSolidHoleCounterboredFeatureAPI::SetStartRadius(m_hFeature, radius);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::put_StartDepth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth = pVal;
	PmeStdSolidHoleCounterboredFeatureAPI::SetStartDepth(m_hFeature, depth);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::put_EndRadius(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius = pVal;
	PmeStdSolidHoleCounterboredFeatureAPI::SetEndRadius(m_hFeature, radius);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::put_EndDepth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth = pVal;
	PmeStdSolidHoleCounterboredFeatureAPI::SetEndDepth(m_hFeature, depth);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleCounterboredFeatureAuto::put_Angle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double angle = pVal;
	PmeStdSolidHoleCounterboredFeatureAPI::SetBottomAngle(m_hFeature, angle);

	return S_OK;
}