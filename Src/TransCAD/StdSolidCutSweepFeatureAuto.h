// StdSolidCutSweepFeatureAuto.h : CStdSolidCutSweepFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.



#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidCutSweepFeature, &IID_IStdSolidCutSweepFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidCutSweepFeatureType;



// CStdSolidCutSweepFeatureAuto

class ATL_NO_VTABLE CStdSolidCutSweepFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidCutSweepFeatureType>
{
public:
	CStdSolidCutSweepFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDCUTSWEEPFEATURE)


BEGIN_COM_MAP(CStdSolidCutSweepFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidCutSweepFeature)
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

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidCutSweepFeature), CStdSolidCutSweepFeatureAuto)
