// StdSolidCutRevolveFeatureAuto.cpp : CStdSolidCutRevolveFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidCutRevolveFeatureAuto.h"


// CStdSolidCutRevolveFeatureAuto


STDMETHODIMP CStdSolidCutRevolveFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidCutRevolveFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::get_IsFlip(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip;
	PmeStdSolidCutRevolveFeatureAPI::IsFlip(m_hFeature, isFlip);

	*pVal = (isFlip) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::get_StartCondition(StdRevolveEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdRevolveEndType startCondition;
	PmeStdSolidCutRevolveFeatureAPI::GetStartCondition(m_hFeature, startCondition);

	*pVal = (StdRevolveEndType)startCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::get_StartAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle;
	PmeStdSolidCutRevolveFeatureAPI::GetStartAngle(m_hFeature, startAngle);

	*pVal = startAngle;

	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::get_EndCondition(StdRevolveEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdRevolveEndType endCondition;
	PmeStdSolidCutRevolveFeatureAPI::GetStartCondition(m_hFeature, endCondition);

	*pVal = (StdRevolveEndType)endCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::get_EndAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle;
	PmeStdSolidCutRevolveFeatureAPI::GetEndAngle(m_hFeature, endAngle);

	*pVal = endAngle;

	return S_OK;
}



STDMETHODIMP CStdSolidCutRevolveFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidCutRevolveFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::put_IsFlip(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip = pVal?true:false;
	PmeStdSolidCutRevolveFeatureAPI::SetFlip(m_hFeature, isFlip);

	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::put_StartAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle = pVal;
	PmeStdSolidCutRevolveFeatureAPI::SetStartAngle(m_hFeature, startAngle);
	
	return S_OK;
}

STDMETHODIMP CStdSolidCutRevolveFeatureAuto::put_EndAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle = pVal;
	PmeStdSolidCutRevolveFeatureAPI::SetEndAngle(m_hFeature, endAngle);

	return S_OK;
}