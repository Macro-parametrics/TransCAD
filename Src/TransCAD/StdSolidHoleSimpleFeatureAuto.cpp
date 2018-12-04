// StdSolidHoleSimpleFeatureAuto.cpp : CStdSolidHoleSimpleFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidHoleSimpleFeatureAuto.h"


// CStdSolidHoleSimpleFeatureAuto


STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::get_TargetFace(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidHoleSimpleFeatureAPI::GetTargetFace(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::get_CenterPoint(double* cx, double* cy, double* cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSolidHoleSimpleFeatureAPI::GetCenterX(m_hFeature, (*cx));
	PmeStdSolidHoleSimpleFeatureAPI::GetCenterY(m_hFeature, (*cy));
	PmeStdSolidHoleSimpleFeatureAPI::GetCenterZ(m_hFeature, (*cz));

	return S_OK;
}

STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::get_Radius(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSolidHoleSimpleFeatureAPI::GetRadius(m_hFeature, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::get_Depth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth;
	PmeStdSolidHoleSimpleFeatureAPI::GetDepth(m_hFeature, depth);

	*pVal = depth;

	return S_OK;
}


STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::put_TargetFace(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidHoleSimpleFeatureAPI::SetTargetFace(m_hFeature, hReference);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::PutCenterPoint(double cx, double cy, double cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSolidHoleSimpleFeatureAPI::SetCenterX(m_hFeature, cx);
	PmeStdSolidHoleSimpleFeatureAPI::SetCenterY(m_hFeature, cy);
	PmeStdSolidHoleSimpleFeatureAPI::SetCenterZ(m_hFeature, cz);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::put_Radius(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius = pVal;
	PmeStdSolidHoleSimpleFeatureAPI::SetRadius(m_hFeature, radius);

	return S_OK;
}

STDMETHODIMP CStdSolidHoleSimpleFeatureAuto::put_Depth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double depth = pVal;
	PmeStdSolidHoleSimpleFeatureAPI::SetDepth(m_hFeature, depth);

	return S_OK;
}