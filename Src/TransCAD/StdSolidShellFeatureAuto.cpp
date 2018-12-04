// StdSolidShellFeatureAuto.cpp : CStdSolidShellFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidShellFeatureAuto.h"
#include ".\PartAuto.h"

// CStdSolidShellFeatureAuto

STDMETHODIMP CStdSolidShellFeatureAuto::get_TargetFaces(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hShellFaces;
	PmeStdSolidShellFeatureAPI::GetTargetFaces(m_hFeature, hShellFaces);

	return CPartAuto::GetIReferencesFromHReferences(hShellFaces, ppVal);
}

STDMETHODIMP CStdSolidShellFeatureAuto::put_TargetFaces(IReferences* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hShellFaces = 0;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hShellFaces);

	PmeStdSolidShellFeatureAPI::SetTargetFaces(m_hFeature, hShellFaces);

	return S_OK;
}


STDMETHODIMP CStdSolidShellFeatureAuto::get_InnerThickness(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double innerThickness;
	PmeStdSolidShellFeatureAPI::GetInnerThickness(m_hFeature, innerThickness);

	*pVal = innerThickness;

	return S_OK;
}

STDMETHODIMP CStdSolidShellFeatureAuto::put_InnerThickness(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double innerThickness = pVal;
	PmeStdSolidShellFeatureAPI::SetInnerThickness(m_hFeature, innerThickness);

	return S_OK;
}


STDMETHODIMP CStdSolidShellFeatureAuto::get_OuterThickness(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double outerThickness;
	PmeStdSolidShellFeatureAPI::GetOuterThickness(m_hFeature, outerThickness);

	*pVal = outerThickness;

	return S_OK;
}

STDMETHODIMP CStdSolidShellFeatureAuto::put_OuterThickness(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double outerThickness = pVal;
	PmeStdSolidShellFeatureAPI::SetOuterThickness(m_hFeature, outerThickness);

	return S_OK;
}