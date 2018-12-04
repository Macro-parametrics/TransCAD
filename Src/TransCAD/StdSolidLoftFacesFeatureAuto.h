// StdSolidLoftFacesFeatureAuto.h : CStdSolidLoftFacesFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"


typedef IDispatchImplEx<IStdSolidLoftFacesFeature, &IID_IStdSolidLoftFacesFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidLoftFacesFeatureType;
// CStdSolidLoftFacesFeatureAuto

class ATL_NO_VTABLE CStdSolidLoftFacesFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidLoftFacesFeatureType>
{
public:
	CStdSolidLoftFacesFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDLOFTFACESFEATUREAUTO)


BEGIN_COM_MAP(CStdSolidLoftFacesFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidLoftFacesFeature)
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
	STDMETHOD(get_Face1)(IReference** ppVal);
	STDMETHOD(get_Param1)(double* pVal);
	STDMETHOD(get_Face2)(IReference** ppVal);
	STDMETHOD(get_Param2)(double* pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidLoftFacesFeature), CStdSolidLoftFacesFeatureAuto)
