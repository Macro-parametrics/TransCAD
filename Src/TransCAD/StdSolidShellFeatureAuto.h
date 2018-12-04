// StdSolidShellFeatureAuto.h : CStdSolidShellFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.



#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"



typedef IDispatchImplEx<IStdSolidShellFeature, &IID_IStdSolidShellFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidShellFeatureType;



// CStdSolidShellFeatureAuto

class ATL_NO_VTABLE CStdSolidShellFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidShellFeatureType>
{
public:
	CStdSolidShellFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDSHELLFEATURE)


BEGIN_COM_MAP(CStdSolidShellFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidShellFeature)
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
	STDMETHOD(get_TargetFaces)(IReferences** ppVal);
	STDMETHOD(put_TargetFaces)(IReferences* ppVal);
	STDMETHOD(get_InnerThickness)(double* pVal);
	STDMETHOD(put_InnerThickness)(double pVal);
	STDMETHOD(get_OuterThickness)(double* pVal);
	STDMETHOD(put_OuterThickness)(double pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidShellFeature), CStdSolidShellFeatureAuto)
