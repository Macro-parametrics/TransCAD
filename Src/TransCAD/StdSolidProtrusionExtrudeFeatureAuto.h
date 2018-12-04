// StdSolidProtrusionExtrudeFeatureAuto.h : CStdSolidProtrusionExtrudeFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidProtrusionExtrudeFeature, &IID_IStdSolidProtrusionExtrudeFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidProtrusionExtrudeFeatureType;


// CStdSolidProtrusionExtrudeFeatureAuto

class ATL_NO_VTABLE CStdSolidProtrusionExtrudeFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidProtrusionExtrudeFeatureType>
{
public:
	CStdSolidProtrusionExtrudeFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDPROTRUSIONEXTRUDEFEATURE)


BEGIN_COM_MAP(CStdSolidProtrusionExtrudeFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidProtrusionExtrudeFeature)
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
	STDMETHOD(get_ProfileSketch)(IReference** ppVal);
	STDMETHOD(get_IsFlip)(VARIANT_BOOL* pVal);
	STDMETHOD(get_StartCondition)(StdExtrudeEndType* pVal);
	STDMETHOD(get_StartDepth)(double* pVal);
	STDMETHOD(get_EndCondition)(StdExtrudeEndType* pVal);
	STDMETHOD(get_EndDepth)(double* pVal);

	STDMETHOD(put_ProfileSketch)(IReference* ppVal);
	STDMETHOD(put_IsFlip)(VARIANT_BOOL pVal);
	STDMETHOD(put_StartCondition)(StdExtrudeEndType pVal);
	STDMETHOD(put_StartDepth)(double pVal);
	STDMETHOD(put_EndCondition)(StdExtrudeEndType pVal);
	STDMETHOD(put_EndDepth)(double pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidProtrusionExtrudeFeature), CStdSolidProtrusionExtrudeFeatureAuto)
