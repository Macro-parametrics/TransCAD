// StdSketchVDirectionAuto.cpp : CStdSketchVDirectionAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchVDirectionAuto.h"


// CStdSketchVDirectionAuto

STDMETHODIMP CStdSketchVDirectionAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchVDirectionAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

