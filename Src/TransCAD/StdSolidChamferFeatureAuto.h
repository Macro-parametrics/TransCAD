// StdSolidChamferFeatureAuto.h : CStdSolidChamferFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidChamferFeature, &IID_IStdSolidChamferFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidChamferFeatureType;

// CStdSolidChamferFeatureAuto

class ATL_NO_VTABLE CStdSolidChamferFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidChamferFeatureType>
{
public:
	CStdSolidChamferFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDCHAMFERFEATURE)


BEGIN_COM_MAP(CStdSolidChamferFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidChamferFeature)
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
	STDMETHOD(get_SelectedEdges)(IReferences **ppVal);
	STDMETHOD(put_SelectedEdges)(IReferences *ppVal);
	STDMETHOD(get_Length)(double *pVal);
	STDMETHOD(put_Length)(double pVal);

	STDMETHOD(get_SelectedFace)(IReference **ppVal);
	STDMETHOD(get_Value)(double *pVal);
	STDMETHOD(get_ChamferType)(ChamferType *pVal);
	
	STDMETHOD(get_StartPosX)(double *pVal);
	STDMETHOD(get_StartPosY)(double *pVal);
	STDMETHOD(get_StartPosZ)(double *pVal);
	STDMETHOD(get_EndPosX)(double *pVal);
	STDMETHOD(get_EndPosY)(double *pVal);
	STDMETHOD(get_EndPosZ)(double *pVal);

	STDMETHOD(get_StartPosXAt)(int index, double *pVal);
	STDMETHOD(get_StartPosYAt)(int index, double *pVal);
	STDMETHOD(get_StartPosZAt)(int index, double *pVal);
	STDMETHOD(get_EndPosXAt)(int index, double *pVal);
	STDMETHOD(get_EndPosYAt)(int index, double *pVal);
	STDMETHOD(get_EndPosZAt)(int index, double *pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidChamferFeature), CStdSolidChamferFeatureAuto)
