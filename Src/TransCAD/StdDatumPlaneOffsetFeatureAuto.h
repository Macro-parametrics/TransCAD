// StdDatumPlaneOffsetFeatureAuto.h : CStdDatumPlaneOffsetFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdDatumPlaneOffsetFeature, &IID_IStdDatumPlaneOffsetFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdDatumPlaneOffsetFeatureType;


// CStdDatumPlaneOffsetFeatureAuto

class ATL_NO_VTABLE CStdDatumPlaneOffsetFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdDatumPlaneOffsetFeatureType>
{
public:
	CStdDatumPlaneOffsetFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDDATUMPLANEOFFSETFEATURE)


BEGIN_COM_MAP(CStdDatumPlaneOffsetFeatureAuto)
	COM_INTERFACE_ENTRY(IStdDatumPlaneOffsetFeature)
	COM_INTERFACE_ENTRY(IFeature)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		ReleaseDispatchImplEx();
	}

public:
	STDMETHOD(get_SelectedPlane)(IReference** ppVal);
	STDMETHOD(put_SelectedPlane)(IReference* ppVal);
	STDMETHOD(get_IsFlip)(VARIANT_BOOL* pVal);
	STDMETHOD(put_IsFlip)(VARIANT_BOOL pVal);
	STDMETHOD(get_Distance)(double* pVal);
	STDMETHOD(put_Distance)(double pVal);
	STDMETHOD(get_IsFree)(VARIANT_BOOL* pVal);
	STDMETHOD(get_Origin)(double* ox, double* oy, double* oz);
	STDMETHOD(get_XDirection)(double* xx, double* xy, double* xz);
	STDMETHOD(get_YDirection)(double* yx, double* yy, double* yz);
	STDMETHOD(PutOrigin)(double ox, double oy, double oz);
	STDMETHOD(PutXDirection)(double xx, double xy, double xz);
	STDMETHOD(PutYDirection)(double yx, double yy, double yz);	
};

// OBJECT_ENTRY_AUTO(__uuidof(StdDatumPlaneOffsetFeature), CStdDatumPlaneOffsetFeatureAuto)
