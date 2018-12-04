// StdSolidHoleCountersunkFeatureAuto.h : CStdSolidHoleCountersunkFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidHoleCountersunkFeature, &IID_IStdSolidHoleCountersunkFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidHoleCountersunkFeatureType;

// CStdSolidHoleCountersunkFeatureAuto

class ATL_NO_VTABLE CStdSolidHoleCountersunkFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidHoleCountersunkFeatureType>
{
public:
	CStdSolidHoleCountersunkFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDHOLECOUNTERSUNKFEATURE)


BEGIN_COM_MAP(CStdSolidHoleCountersunkFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidHoleCountersunkFeature)
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
	STDMETHOD(get_TargetFace)(IReference** ppVal);
	STDMETHOD(get_CenterPoint)(double* cx, double* cy, double* cz);
	STDMETHOD(get_Radius)(double* pVal);
	STDMETHOD(get_Depth)(double* pVal);
	STDMETHOD(get_SinkRadius)(double* pVal);
	STDMETHOD(get_SinkAngle)(double* pVal);
	STDMETHOD(get_BottomAngle)(double* pVal);

	STDMETHOD(put_TargetFace)(IReference* ppVal);
	STDMETHOD(PutCenterPoint)(double cx, double cy, double cz);
	STDMETHOD(put_Radius)(double pVal);
	STDMETHOD(put_Depth)(double pVal);
	STDMETHOD(put_SinkRadius)(double pVal);
	STDMETHOD(put_SinkAngle)(double pVal);
	STDMETHOD(put_BottomAngle)(double pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidHoleCountersunkFeature), CStdSolidHoleCountersunkFeatureAuto)
