// StdSolidHoleCounterboredFeatureAuto.h : CStdSolidHoleCounterboredFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidHoleCounterboredFeature, &IID_IStdSolidHoleCounterboredFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidHoleCounterboredFeatureType;


// CStdSolidHoleCounterboredFeatureAuto

class ATL_NO_VTABLE CStdSolidHoleCounterboredFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidHoleCounterboredFeatureType>
{
public:
	CStdSolidHoleCounterboredFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDHOLECOUNTERBOREDFEATUREAUTO)


BEGIN_COM_MAP(CStdSolidHoleCounterboredFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidHoleCounterboredFeature)
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
	STDMETHOD(get_StartRadius)(double* pVal);
	STDMETHOD(get_StartDepth)(double* pVal);
	STDMETHOD(get_EndRadius)(double* pVal);
	STDMETHOD(get_EndDepth)(double* pVal);
	STDMETHOD(get_Angle)(double* pVal);

	STDMETHOD(put_TargetFace)(IReference* ppVal);
	STDMETHOD(PutCenterPoint)(double cx, double cy, double cz);
	STDMETHOD(put_StartRadius)(double pVal);
	STDMETHOD(put_StartDepth)(double pVal);
	STDMETHOD(put_EndRadius)(double pVal);
	STDMETHOD(put_EndDepth)(double pVal);
	STDMETHOD(put_Angle)(double pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidHoleCounterboredFeature), CStdSolidHoleCounterboredFeatureAuto)
