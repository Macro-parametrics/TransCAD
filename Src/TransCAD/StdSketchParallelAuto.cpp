// StdSketchParallelAuto.cpp : CStdSketchParallelAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchParallelAuto.h"


// CStdSketchParallelAuto

STDMETHODIMP CStdSketchParallelAuto::get_ReferenceEdit(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchParallelAPI::GetReferenceEdit(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSketchParallelAuto::get_Target(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchParallelAPI::GetTarget(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}
