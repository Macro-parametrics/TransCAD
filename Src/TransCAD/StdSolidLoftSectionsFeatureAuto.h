// StdSolidLoftSectionsFeatureAuto.h : CStdSolidLoftSectionsFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidLoftSectionsFeature, &IID_IStdSolidLoftSectionsFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidLoftSectionsFeatureType;

// CStdSolidLoftSectionsFeatureAuto

class ATL_NO_VTABLE CStdSolidLoftSectionsFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidLoftSectionsFeatureType>
{
public:
	CStdSolidLoftSectionsFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDLOFTSECTIONSFEATURE)


BEGIN_COM_MAP(CStdSolidLoftSectionsFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidLoftSectionsFeature)
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
	STDMETHOD(get_References)(IReferences** ppVal);
	STDMETHOD(get_IsCut)(VARIANT_BOOL* pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidLoftSectionsFeature), CStdSolidLoftSectionsFeatureAuto)
