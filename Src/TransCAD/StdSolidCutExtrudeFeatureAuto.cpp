// StdSolidCutExtrudeFeatureAuto.cpp : CStdSolidCutExtrudeFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidCutExtrudeFeatureAuto.h"
#include ".\PartAuto.h"


// CStdSolidCutExtrudeFeatureAuto
STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidCutExtrudeFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::get_IsFlip(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip;
	PmeStdSolidCutExtrudeFeatureAPI::IsFlip(m_hFeature, isFlip);

	*pVal = (isFlip) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::get_StartCondition(StdExtrudeEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType startCondition;
	PmeStdSolidCutExtrudeFeatureAPI::GetStartCondition(m_hFeature, startCondition);

	*pVal = (StdExtrudeEndType)startCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::get_StartDepth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startDepth;
	PmeStdSolidCutExtrudeFeatureAPI::GetStartDepth(m_hFeature, startDepth);

	*pVal = startDepth;

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::get_EndCondition(StdExtrudeEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType endCondition;
	PmeStdSolidCutExtrudeFeatureAPI::GetEndCondition(m_hFeature, endCondition);

	*pVal = (StdExtrudeEndType)endCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::get_EndDepth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endDepth;
	PmeStdSolidCutExtrudeFeatureAPI::GetEndDepth(m_hFeature, endDepth);

	*pVal = endDepth;

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidCutExtrudeFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::put_IsFlip(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip = pVal?true:false;
	PmeStdSolidCutExtrudeFeatureAPI::SetFlip(m_hFeature, isFlip);

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::put_StartCondition(StdExtrudeEndType pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType startCondition = (PmeStdExtrudeEndType)pVal;
	PmeStdSolidCutExtrudeFeatureAPI::SetStartCondition(m_hFeature, startCondition);

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::put_StartDepth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startDepth = pVal;
	PmeStdSolidCutExtrudeFeatureAPI::SetStartDepth(m_hFeature, startDepth);
	
	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::put_EndCondition(StdExtrudeEndType pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType endCondition = (PmeStdExtrudeEndType)pVal;
	PmeStdSolidCutExtrudeFeatureAPI::SetEndCondition(m_hFeature, endCondition);

	return S_OK;
}

STDMETHODIMP CStdSolidCutExtrudeFeatureAuto::put_EndDepth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endDepth = pVal;
	PmeStdSolidCutExtrudeFeatureAPI::SetEndDepth(m_hFeature, endDepth);

	return S_OK;
}