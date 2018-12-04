// StdSolidOffsetFeatureAuto.cpp : CStdSolidOffsetFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidOffsetFeatureAuto.h"
#include ".\PartAuto.h"

// CStdSolidOffsetFeatureAuto

STDMETHODIMP CStdSolidOffsetFeatureAuto::get_TargetFaces(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hOffsetFaces;
	PmeStdSolidOffsetFeatureAPI::GetTargetFaces(m_hFeature, hOffsetFaces);

	return CPartAuto::GetIReferencesFromHReferences(hOffsetFaces, ppVal);
}

STDMETHODIMP CStdSolidOffsetFeatureAuto::put_TargetFaces(IReferences* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hOffsetFaces = 0;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hOffsetFaces);
	PmeStdSolidOffsetFeatureAPI::SetTargetFaces(m_hFeature, hOffsetFaces);

	return S_OK;
}

STDMETHODIMP CStdSolidOffsetFeatureAuto::get_OffsetThickness(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double offsetThickness;
	PmeStdSolidOffsetFeatureAPI::GetThickness(m_hFeature, offsetThickness);

	*pVal = offsetThickness;

	return S_OK;
}

STDMETHODIMP CStdSolidOffsetFeatureAuto::put_OffsetThickness(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double offsetThickness = pVal;
	PmeStdSolidOffsetFeatureAPI::SetThickness(m_hFeature, offsetThickness);

	return S_OK;
}