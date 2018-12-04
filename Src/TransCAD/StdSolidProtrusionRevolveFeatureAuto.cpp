// StdSolidProtrusionRevolveFeatureAuto.cpp : CStdSolidProtrusionRevolveFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidProtrusionRevolveFeatureAuto.h"


// CStdSolidProtrusionRevolveFeatureAuto

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidProtrusionRevolveFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::get_IsFlip(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip;
	PmeStdSolidProtrusionRevolveFeatureAPI::IsFlip(m_hFeature, isFlip);

	*pVal = (isFlip) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::get_StartCondition(StdRevolveEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdRevolveEndType startCondition;
	PmeStdSolidProtrusionRevolveFeatureAPI::GetStartCondition(m_hFeature, startCondition);

	*pVal = (StdRevolveEndType)startCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::get_StartAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle;
	PmeStdSolidProtrusionRevolveFeatureAPI::GetStartAngle(m_hFeature, startAngle);

	*pVal = startAngle;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::get_EndCondition(StdRevolveEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdRevolveEndType endCondition;
	PmeStdSolidProtrusionRevolveFeatureAPI::GetStartCondition(m_hFeature, endCondition);

	*pVal = (StdRevolveEndType)endCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::get_EndAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle;
	PmeStdSolidProtrusionRevolveFeatureAPI::GetEndAngle(m_hFeature, endAngle);

	*pVal = endAngle;

	return S_OK;
}


STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidProtrusionRevolveFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::put_IsFlip(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip = pVal?true:false;
	PmeStdSolidProtrusionRevolveFeatureAPI::SetFlip(m_hFeature, isFlip);

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::put_StartAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle = pVal;
	PmeStdSolidProtrusionRevolveFeatureAPI::SetStartAngle(m_hFeature, startAngle);
	
	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionRevolveFeatureAuto::put_EndAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle = pVal;
	PmeStdSolidProtrusionRevolveFeatureAPI::SetEndAngle(m_hFeature, endAngle);

	return S_OK;
}