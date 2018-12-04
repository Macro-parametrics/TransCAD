// StdSolidProtrusionSweepFeatureAuto.h : CStdSolidProtrusionSweepFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidProtrusionSweepFeature, &IID_IStdSolidProtrusionSweepFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidProtrusionSweepFeatureType;


// CStdSolidProtrusionSweepFeatureAuto

class ATL_NO_VTABLE CStdSolidProtrusionSweepFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidProtrusionSweepFeatureType>
{
public:
	CStdSolidProtrusionSweepFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDPROTRUSIONSWEEPFEATURE)


BEGIN_COM_MAP(CStdSolidProtrusionSweepFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidProtrusionSweepFeature)
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
	STDMETHOD(get_GuideCurve)(IReference** ppVal);
	STDMETHOD(put_ProfileSketch)(IReference* ppVal);
	STDMETHOD(put_GuideCurve)(IReference* ppVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidProtrusionSweepFeature), CStdSolidProtrusionSweepFeatureAuto)
