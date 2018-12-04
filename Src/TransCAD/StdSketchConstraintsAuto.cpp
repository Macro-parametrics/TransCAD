// StdSketchConstraintsAuto.cpp : CStdSketchConstraintsAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchConstraintsAuto.h"


// CStdSketchConstraintsAuto

STDMETHODIMP CStdSketchConstraintsAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchConstraintsAuto::get_Item(long index, IStdSketchGeometry** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchConstraintsAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchConstraintsAuto::get_FindByName(IStdSketchGeometry** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

