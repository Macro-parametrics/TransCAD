// StdSketchHorizontalAuto.cpp : CStdSketchHorizontalAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchHorizontalAuto.h"


// CStdSketchHorizontalAuto

STDMETHODIMP CStdSketchHorizontalAuto::get_Target(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchHorizontalAPI::GetTarget(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}
