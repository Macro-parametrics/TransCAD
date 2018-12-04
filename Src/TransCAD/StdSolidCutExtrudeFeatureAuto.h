// StdSolidCutExtrudeFeatureAuto.h : CStdSolidCutExtrudeFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidCutExtrudeFeature, &IID_IStdSolidCutExtrudeFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidCutExtrudeFeatureType;

// CStdSolidCutExtrudeFeatureAuto

class ATL_NO_VTABLE CStdSolidCutExtrudeFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidCutExtrudeFeatureType>
{
public:
	CStdSolidCutExtrudeFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDCUTEXTRUDEFEATURE)


BEGIN_COM_MAP(CStdSolidCutExtrudeFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidCutExtrudeFeature)
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

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidCutExtrudeFeature), CStdSolidCutExtrudeFeatureAuto)
