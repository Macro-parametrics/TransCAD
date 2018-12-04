// StdSolidImportedBrepFeatureAuto.h : CStdSolidImportedBrepFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidImportedBrepFeature, &IID_IStdSolidImportedBrepFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidImportedBrepFeatureType;

// CStdSolidImportedBrepFeatureAuto

class ATL_NO_VTABLE CStdSolidImportedBrepFeatureAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidImportedBrepFeatureType>
{
public:
	CStdSolidImportedBrepFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDIMPORTEDBREPFEATURE)


BEGIN_COM_MAP(CStdSolidImportedBrepFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidImportedBrepFeature)
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
	STDMETHOD(get_FilePath)(BSTR* pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(StdSolidImportedBrepFeature), CStdSolidImportedBrepFeatureAuto)
