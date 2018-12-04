// StdSolidHoleSimpleFeatureAuto.h : CStdSolidHoleSimpleFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidHoleSimpleFeature, &IID_IStdSolidHoleSimpleFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidHoleSimpleFeatureType;


// CStdSolidHoleSimpleFeatureAuto

class ATL_NO_VTABLE CStdSolidHoleSimpleFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidHoleSimpleFeatureType>
{
public:
	CStdSolidHoleSimpleFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDHOLESIMPLEFEATURE)


BEGIN_COM_MAP(CStdSolidHoleSimpleFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidHoleSimpleFeature)
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
	STDMETHOD(get_Radius)(double* pVal);
	STDMETHOD(get_Depth)(double* pVal);

	STDMETHOD(put_TargetFace)(IReference* ppVal);
	STDMETHOD(PutCenterPoint)(double cx, double cy, double cz);
	STDMETHOD(put_Radius)(double pVal);
	STDMETHOD(put_Depth)(double pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidHoleSimpleFeature), CStdSolidHoleSimpleFeatureAuto)
