// StdSolidProtrusionSweepFeatureAuto.cpp : CStdSolidProtrusionSweepFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidProtrusionSweepFeatureAuto.h"
#include ".\PartAuto.h"


// CStdSolidProtrusionSweepFeatureAuto

STDMETHODIMP CStdSolidProtrusionSweepFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidProtrusionSweepFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidProtrusionSweepFeatureAuto::get_GuideCurve(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidProtrusionSweepFeatureAPI::GetGuideCurve(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidProtrusionSweepFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidProtrusionSweepFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidProtrusionSweepFeatureAuto::put_GuideCurve(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidProtrusionSweepFeatureAPI::SetGuideCurve(m_hFeature, hReference);
	
	return S_OK;
}

