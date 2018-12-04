// ExplicitModelObjectAuto.h : CExplicitModelObjectAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"
#include ".\DispatchImplEx.h"

// CExplicitModelObjectAuto

class ATL_NO_VTABLE CExplicitModelObjectAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImplEx<IExplicitModelObject, &IID_IExplicitModelObject, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CExplicitModelObjectAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EXPLICITMODELOBJECT)


BEGIN_COM_MAP(CExplicitModelObjectAuto)
	COM_INTERFACE_ENTRY(IExplicitModelObject)
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
	STDMETHOD(get_Type)(ExplicitModelObjectType* pVal);
	STDMETHOD(get_Creator)(IFeature* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(ExplicitModelObject), CExplicitModelObjectAuto)
