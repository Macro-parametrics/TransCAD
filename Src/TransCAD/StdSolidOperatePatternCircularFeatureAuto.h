// StdSolidOperatePatternCircularFeatureAuto.h : CStdSolidOperatePatternCircularFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"


typedef IDispatchImplEx<IStdSolidOperatePatternCircularFeature, &IID_IStdSolidOperatePatternCircularFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidOperatePatternCircularFeatureType;


// CStdSolidOperatePatternCircularFeatureAuto

class ATL_NO_VTABLE CStdSolidOperatePatternCircularFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidOperatePatternCircularFeatureType>
{
public:
	CStdSolidOperatePatternCircularFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDOPERATEPATTERNCIRCULARFEATURE)


BEGIN_COM_MAP(CStdSolidOperatePatternCircularFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidOperatePatternCircularFeature)
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
	STDMETHOD(get_TargetFeatures)(IReferences** ppVal);
	STDMETHOD(get_CenterAxis)(double* x1, double* y1, double* z1, double* x2, double* y2, double* z2);
	STDMETHOD(get_AngleNumber)(int* pVal);
	STDMETHOD(get_AngleIncrement)(double* pVal);
	STDMETHOD(get_RadialNumber)(int* pVal);
	STDMETHOD(get_RadialSpacing)(double* pVal);
	STDMETHOD(get_IsRadialAnignment)(VARIANT_BOOL* pVal);

	STDMETHOD(put_TargetFeatures)(IReferences* ppVal);
	STDMETHOD(PutCenterAxis)(double x1, double y1, double z1, double x2, double y2, double z2);
	STDMETHOD(put_AngleNumber)(int pVal);
	STDMETHOD(put_AngleIncrement)(double pVal);
	STDMETHOD(put_RadialNumber)(int pVal);
	STDMETHOD(put_RadialSpacing)(double pVal);
	STDMETHOD(put_IsRadialAnignment)(VARIANT_BOOL pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidOperatePatternCircularFeature), CStdSolidOperatePatternCircularFeatureAuto)
