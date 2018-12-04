// StdSolidCutSweepFeatureAuto.cpp : CStdSolidCutSweepFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidCutSweepFeatureAuto.h"
#include ".\PartAuto.h"

// CStdSolidCutSweepFeatureAuto

STDMETHODIMP CStdSolidCutSweepFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidCutSweepFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidCutSweepFeatureAuto::get_GuideCurve(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidCutSweepFeatureAPI::GetGuideCurve(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidCutSweepFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidCutSweepFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidCutSweepFeatureAuto::put_GuideCurve(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidCutSweepFeatureAPI::SetGuideCurve(m_hFeature, hReference);
	
	return S_OK;
}