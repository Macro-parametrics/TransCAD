// StdSolidRevolveWithExternalAxisFeatureAuto.h : CStdSolidRevolveWithExternalAxisFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidRevolveWithExternalAxisFeature, &IID_IStdSolidRevolveWithExternalAxisFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidRevolveWithExternalAxisFeatureType;


// CStdSolidRevolveWithExternalAxisFeatureAuto

class ATL_NO_VTABLE CStdSolidRevolveWithExternalAxisFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidRevolveWithExternalAxisFeatureType>
{
public:
	CStdSolidRevolveWithExternalAxisFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDREVOLVEWITHEXTERNALAXISFEATURE)


BEGIN_COM_MAP(CStdSolidRevolveWithExternalAxisFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidRevolveWithExternalAxisFeature)
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
	STDMETHOD(get_StartAngle)(double* pVal);
	STDMETHOD(get_StartCondition)(StdRevolveEndType* pVal);
	STDMETHOD(get_EndAngle)(double* pVal);
	STDMETHOD(get_EndCondition)(StdRevolveEndType* pVal);
	STDMETHOD(get_IsFlip)(VARIANT_BOOL* pVal);
	STDMETHOD(get_IsCut)(VARIANT_BOOL* pVal);
	STDMETHOD(get_RevolveAxis)(double* orgX, double* orgY, double* orgZ, double* dirX, double* dirY, double* dirZ);
	
	STDMETHOD(put_ProfileSketch)(IReference* ppVal);
	STDMETHOD(put_IsFlip)(VARIANT_BOOL pVal);
	STDMETHOD(put_StartAngle)(double pVal);
	STDMETHOD(put_EndAngle)(double pVal);
	STDMETHOD(put_IsCut)(VARIANT_BOOL pVal);
	STDMETHOD(PutRevolveAxis)(double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ);
};