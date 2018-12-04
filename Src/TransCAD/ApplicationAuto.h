// ApplicationAuto.h : CApplicationAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"


// CApplicationAuto

class ATL_NO_VTABLE CApplicationAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CApplicationAuto, &CLSID_Application>,
	public IDispatchImpl<IApplication, &IID_IApplication, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CApplicationAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_APPLICATIONAUTO)


BEGIN_COM_MAP(CApplicationAuto)
	COM_INTERFACE_ENTRY(IApplication)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	STDMETHOD(get_Visible)(VARIANT_BOOL* pVal);
	STDMETHOD(put_Visible)(VARIANT_BOOL newVal);
	STDMETHOD(get_Application)(IApplication** ppVal);
	STDMETHOD(get_Parent)(IDispatch** ppVal);
	STDMETHOD(get_ActiveDocument)(IDoc** ppVal);
	STDMETHOD(get_Documents)(IDocs** ppVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(Quit)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(Application), CApplicationAuto)
