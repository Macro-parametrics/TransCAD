// StdSketchPerpendicularAuto.cpp : CStdSketchPerpendicularAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchPerpendicularAuto.h"


// CStdSketchPerpendicularAuto

STDMETHODIMP CStdSketchPerpendicularAuto::get_ReferenceEdit(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchPerpendicularAPI::GetReferenceEdit(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSketchPerpendicularAuto::get_Target(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchPerpendicularAPI::GetTarget(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

