// StdSolidCutRevolveFeatureAuto.h : CStdSolidCutRevolveFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidCutRevolveFeature, &IID_IStdSolidCutRevolveFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidCutRevolveFeatureType;


// CStdSolidCutRevolveFeatureAuto

class ATL_NO_VTABLE CStdSolidCutRevolveFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidCutRevolveFeatureType>
{
public:
	CStdSolidCutRevolveFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDCUTREVOLVEFEATURE)


BEGIN_COM_MAP(CStdSolidCutRevolveFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidCutRevolveFeature)
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
	STDMETHOD(get_StartCondition)(StdRevolveEndType* pVal);
	STDMETHOD(get_StartAngle)(double* pVal);
	STDMETHOD(get_EndCondition)(StdRevolveEndType* pVal);
	STDMETHOD(get_EndAngle)(double* pVal);

	STDMETHOD(put_ProfileSketch)(IReference* ppVal);
	STDMETHOD(put_IsFlip)(VARIANT_BOOL pVal);
	STDMETHOD(put_StartAngle)(double pVal);
	STDMETHOD(put_EndAngle)(double pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidCutRevolveFeature), CStdSolidCutRevolveFeatureAuto)
