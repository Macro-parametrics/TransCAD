// StdSketchGeometriesAuto.cpp : CStdSketchGeometriesAuto의 구현입니다.

#include "stdafx.h"
#include "StdSketchGeometriesAuto.h"
#include "StdSketchLineAuto.h"
#include "StdSketchCenterlineAuto.h"
#include "StdSketchCircleAuto.h"
#include "StdSketchCircularArcAuto.h"
#include "StdSketchControlPointAuto.h"

#define BEGIN_STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(hstdsketchgeometry) \
	PmeStdSketchGeometryType type; \
	PmeStdSketchGeometryAPI::GetType( hstdsketchgeometry , type); \
	HRESULT hr = E_FAIL; \
	PmeHStdSketchGeometry hInnerHStdSketchGeometry = hstdsketchgeometry; \
	switch(type) {

#define END_STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP() }return hr;

#define STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(type, istdsketchgeometry) \
	case PmeStdSketchGeometryType_##type: { \
			CComObject<CStdSketch##type##Auto> * pObj = NULL; \
			hr = CComObject<CStdSketch##type##Auto>::CreateInstance(&pObj); \
			if(FAILED(hr)) return hr; \
            pObj->Initialize(hInnerHStdSketchGeometry); \
			hr = pObj->QueryInterface(__uuidof(IStdSketch##type), (void **) istdsketchgeometry); \
		} break;

// CStdSketchGeometriesAuto

STDMETHODIMP CStdSketchGeometriesAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometries hGeometries;
	PmeStdSketchFeatureAPI::GetGeometries(m_hFeature, hGeometries);

	int size;
	PmeStdSketchGeometriesAPI::GetSize(hGeometries, size);

	*pVal = (long)size;

	return S_OK;
}

STDMETHODIMP CStdSketchGeometriesAuto::get_Item(long index, IStdSketchGeometry** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHStdSketchGeometries hGeometries;
	PmeStdSketchFeatureAPI::GetGeometries(m_hFeature, hGeometries);

	PmeHStdSketchGeometry hGeometry;
	PmeStdSketchGeometriesAPI::GetItem(hGeometries, (int)index - 1, hGeometry);

	HRESULT hr = GetIStdSketchGeometryFromHStdSketchGeometry(hGeometry, ppVal);
    
	return hr;
}

STDMETHODIMP CStdSketchGeometriesAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	PmeHStdSketchGeometries hGeometries;
	PmeStdSketchFeatureAPI::GetGeometries(m_hFeature, hGeometries);

	int size;
	PmeFeaturesAPI::GetSize(hGeometries, size);

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHStdSketchGeometry hGeometry;
		PmeStdSketchGeometriesAPI::GetItem(hGeometries, i, hGeometry);
		
		IStdSketchGeometry * pStdSketchGeometry = NULL;
		
		hr = GetIStdSketchGeometryFromHStdSketchGeometry(hGeometry, &pStdSketchGeometry);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pStdSketchGeometry->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pStdSketchGeometry->Release();
		if(FAILED(hr))
			return hr;

		// create a variant and add it to the collection
		CComVariant & var = pVarVect[i];
		var.vt = VT_DISPATCH;
		var.pdispVal = pDispatch;
	}

	hr = pEnumObject->Init(&pVarVect[0], &pVarVect[size], NULL, AtlFlagCopy);
	if(FAILED(hr))
		return hr;

    hr = pEnumObject->QueryInterface(IID_IEnumVARIANT, (void **)ppUnk);
	
	delete [] pVarVect;

	return hr;
}

STDMETHODIMP CStdSketchGeometriesAuto::get_FindByName(IStdSketchGeometry** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	return S_OK;
}

HRESULT CStdSketchGeometriesAuto::GetIStdSketchGeometryFromHStdSketchGeometry(PmeHStdSketchGeometry hGeometry, IStdSketchGeometry** ppVal)
{
	BEGIN_STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(hGeometry)
		STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(Line, ppVal)
		STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(Centerline, ppVal)
		STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(Circle, ppVal)
		STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(CircularArc, ppVal)
		STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP(ControlPoint, ppVal)
	END_STDSKETCHGEOMETRY_HSTDSKETCHGEOMETRY_MAP()
}