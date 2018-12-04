// StdSolidLoftFacesFeatureAuto.cpp : CStdSolidLoftFacesFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidLoftFacesFeatureAuto.h"


// CStdSolidLoftFacesFeatureAuto


STDMETHODIMP CStdSolidLoftFacesFeatureAuto::get_Face1(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidLoftFacesFeatureAPI::GetFace2(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidLoftFacesFeatureAuto::get_Param1(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double param1;
	PmeStdSolidLoftFacesFeatureAPI::GetParam1(m_hFeature, param1);

	*pVal = param1;

	return S_OK;
}

STDMETHODIMP CStdSolidLoftFacesFeatureAuto::get_Face2(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidLoftFacesFeatureAPI::GetFace2(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidLoftFacesFeatureAuto::get_Param2(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double param2;
	PmeStdSolidLoftFacesFeatureAPI::GetParam2(m_hFeature, param2);

	*pVal = param2;

	return S_OK;
}
