// StdSolidOffsetFeatureAuto.h : CStdSolidOffsetFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.



#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"



typedef IDispatchImplEx<IStdSolidOffsetFeature, &IID_IStdSolidOffsetFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidOffsetFeatureType;


// CStdSolidOffsetFeatureAuto

class ATL_NO_VTABLE CStdSolidOffsetFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidOffsetFeatureType>
{
public:
	CStdSolidOffsetFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDOFFSETFEATURE)


BEGIN_COM_MAP(CStdSolidOffsetFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidOffsetFeature)
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
	STDMETHOD(get_OffsetThickness)(double* pVal);
	STDMETHOD(put_OffsetThickness)(double pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidOffsetFeature), CStdSolidOffsetFeatureAuto)
