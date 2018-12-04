// StdSketchGeometryAuto.cpp : CStdSketchGeometryAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchGeometryAuto.h"


// CStdSketchGeometryAuto


STDMETHODIMP CStdSketchGeometryAuto::get_Type(StdSketchGeometryType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSketchGeometryType type;
	PmeStdSketchGeometryAPI_GetType(m_hGeometry, type);

	*pVal = ConvertPmeStdSketchGeometryTypeToStdSketchGeometryType(type);

	return S_OK;
}

STDMETHODIMP CStdSketchGeometryAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;
	PmeStdSketchGeometryAPI_GetName(m_hGeometry, name);

	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CStdSketchGeometryAuto::get_SketchFeature(IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}
