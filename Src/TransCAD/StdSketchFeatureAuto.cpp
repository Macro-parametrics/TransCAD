// StdSketchFeatureAuto.cpp : CStdSketchFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchFeatureAuto.h"
#include ".\SketchEditorAuto.h"
#include "StdSketchOriginAuto.h"
#include "StdSketchGeometriesAuto.h"


// CStdSketchFeatureAuto

STDMETHODIMP CStdSketchFeatureAuto::get_Origin(IStdSketchOrigin **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchOrigin hOrigin;
	PmeStdSketchFeatureAPI::GetOrigin(m_hFeature, hOrigin);

	return CStdSketchOriginAuto::GetIStdSketchOriginFromHStdSketchOrigin(hOrigin, ppVal);
}

STDMETHODIMP CStdSketchFeatureAuto::get_HDirection(IStdSketchHDirection **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::get_VDirection(IStdSketchVDirection **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::get_Geometries(IStdSketchGeometries **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CStdSketchGeometriesAuto> * pObj = NULL;
	hr = CComObject<CStdSketchGeometriesAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(m_hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSketchGeometries), (void **)ppVal);
	if(FAILED(hr))
		return hr;

	return hr;
}

STDMETHODIMP CStdSketchFeatureAuto::get_Constraints(IStdSketchConstraints **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::get_Sketch(ISketch **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::get_SketchPlane(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSketchFeatureAPI::GetSketchPlane(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSketchFeatureAuto::OpenEditor(ISketchEditor** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CSketchEditorAuto> * pSketchEditor = NULL;
	hr = CComObject<CSketchEditorAuto>::CreateInstance(&pSketchEditor);
	if(FAILED(hr))
		return hr;

	PmeHStdSketchEditor hEditor;
	PmeStdSketchFeatureAPI::OpenEditor(m_hFeature, hEditor);

	pSketchEditor->Initialize(hEditor);

	hr = pSketchEditor->QueryInterface(__uuidof(ISketchEditor), (void **)ppVal);
	if(FAILED(hr))
		return hr;

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::OpenEditorEx(VARIANT_BOOL activateDcm, ISketchEditor** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CSketchEditorAuto> * pSketchEditor = NULL;
	hr = CComObject<CSketchEditorAuto>::CreateInstance(&pSketchEditor);
	if(FAILED(hr))
		return hr;

	PmeHStdSketchEditor hEditor;
	PmeStdSketchFeatureAPI::OpenEditor(m_hFeature, (activateDcm == VARIANT_TRUE), hEditor);

	pSketchEditor->Initialize(hEditor);

	hr = pSketchEditor->QueryInterface(__uuidof(ISketchEditor), (void **)ppVal);
	if(FAILED(hr))
		return hr;

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::SetCoordinateSystem(double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition origin(ox, oy, oz);
	MrDirection xdir(xx, xy, xz);
	MrDirection ydir(yx, yy, yz);
	MrDirection zdir(xdir ^ ydir);

	PmeStdSketchFeatureAPI::SetCoordinateSystem(m_hFeature, MrAxis2(origin, zdir, xdir));

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::GetCoordinateSystem(double* ox, double* oy, double* oz, double* xx, double* xy, double* xz, double* yx, double* yy, double* yz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis2 coordinateSystem;

	PmeStdSketchFeatureAPI::GetCoordinateSystem(m_hFeature, coordinateSystem);

	MrPosition origin = coordinateSystem.Location();
	MrDirection xdir = coordinateSystem.XDirection();
	MrDirection ydir = coordinateSystem.YDirection();

	*ox = origin.X();
	*oy = origin.Y();
	*oz = origin.Z();
	*xx = xdir.X();
	*xy = xdir.Y();
	*xz = xdir.Z();
	*yx = ydir.X();
	*yy = ydir.Y();
	*yz = ydir.Z();

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::get_IsInversed(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isInversed;
	PmeStdSketchFeatureAPI::IsInversed(m_hFeature, isInversed);

	*pVal = (isInversed) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdSketchFeatureAuto::DeleteByName(BSTR name)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;

	CString strName(name);

	PmeStdSketchFeatureAPI::DeleteByName(m_hFeature, strName);

	return hr;
}