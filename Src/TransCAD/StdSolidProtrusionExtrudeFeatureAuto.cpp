// StdSolidProtrusionExtrudeFeatureAuto.cpp : CStdSolidProtrusionExtrudeFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidProtrusionExtrudeFeatureAuto.h"
#include ".\PartAuto.h"


// CStdSolidProtrusionExtrudeFeatureAuto

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidProtrusionExtrudeFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::get_IsFlip(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip;
	PmeStdSolidProtrusionExtrudeFeatureAPI::IsFlip(m_hFeature, isFlip);

	*pVal = (isFlip) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::get_StartCondition(StdExtrudeEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType startCondition;
	PmeStdSolidProtrusionExtrudeFeatureAPI::GetStartCondition(m_hFeature, startCondition);

	*pVal = (StdExtrudeEndType)startCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::get_StartDepth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startDepth;
	PmeStdSolidProtrusionExtrudeFeatureAPI::GetStartDepth(m_hFeature, startDepth);

	*pVal = startDepth;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::get_EndCondition(StdExtrudeEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType endCondition;
	PmeStdSolidProtrusionExtrudeFeatureAPI::GetEndCondition(m_hFeature, endCondition);

	*pVal = (StdExtrudeEndType)endCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::get_EndDepth(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endDepth;
	PmeStdSolidProtrusionExtrudeFeatureAPI::GetEndDepth(m_hFeature, endDepth);

	*pVal = endDepth;

	return S_OK;
}


STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidProtrusionExtrudeFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::put_IsFlip(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip = pVal?true:false;
	PmeStdSolidProtrusionExtrudeFeatureAPI::SetFlip(m_hFeature, isFlip);

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::put_StartCondition(StdExtrudeEndType pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType startCondition = (PmeStdExtrudeEndType)pVal;
	PmeStdSolidProtrusionExtrudeFeatureAPI::SetStartCondition(m_hFeature, startCondition);

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::put_StartDepth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startDepth = pVal;
	PmeStdSolidProtrusionExtrudeFeatureAPI::SetStartDepth(m_hFeature, startDepth);
	
	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::put_EndCondition(StdExtrudeEndType pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdExtrudeEndType endCondition = (PmeStdExtrudeEndType)pVal;
	PmeStdSolidProtrusionExtrudeFeatureAPI::SetEndCondition(m_hFeature, endCondition);

	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionExtrudeFeatureAuto::put_EndDepth(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endDepth = pVal;
	PmeStdSolidProtrusionExtrudeFeatureAPI::SetEndDepth(m_hFeature, endDepth);

	return S_OK;
}