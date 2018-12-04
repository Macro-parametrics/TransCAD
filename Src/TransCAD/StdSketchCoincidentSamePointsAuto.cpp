// StdSketchCoincidentSamePointsAuto.cpp : CStdSketchCoincidentSamePointsAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchCoincidentSamePointsAuto.h"


// CStdSketchCoincidentSamePointsAuto


STDMETHODIMP CStdSketchCoincidentSamePointsAuto::get_FirstObject(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchCoincidentAPI::GetFirstGeometry(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSketchCoincidentSamePointsAuto::get_FirstType(StdCoincidentSamePointsType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeSamePointsType type;
	PmeStdSketchCoincidentAPI::GetFirstObjectType(m_hStdSketchConstraint, type);

	*pVal = (StdCoincidentSamePointsType)type;

	return S_OK;
}

STDMETHODIMP CStdSketchCoincidentSamePointsAuto::get_SecondObject(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchCoincidentAPI::GetSecondGeometry(m_hStdSketchConstraint, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSketchCoincidentSamePointsAuto::get_SecondType(StdCoincidentSamePointsType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeSamePointsType type;
	PmeStdSketchCoincidentAPI::GetSecondObjectType(m_hStdSketchConstraint, type);

	*pVal = (StdCoincidentSamePointsType)type;

	return S_OK;
}
