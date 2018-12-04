// DocumentAuto.h : CDocumentAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include "DispatchImplEx.h"

// CDocumentAuto

class ATL_NO_VTABLE CDocumentAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CDocumentAuto, &CLSID_Document>,
	public IDispatchImplEx<IDoc, &IID_IDoc, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDocumentAuto()
		: m_pDocument(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DOCUMENTAUTO)


BEGIN_COM_MAP(CDocumentAuto)
	COM_INTERFACE_ENTRY(IDoc)
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

	void Initialize(CDocument * pDocument);

private:
	CDocument * m_pDocument;

public:
	STDMETHOD(get_FullName)(BSTR* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Path)(BSTR* pVal);
	STDMETHOD(get_Saved)(VARIANT_BOOL* pVal);
	STDMETHOD(Activate)(void);
	STDMETHOD(Close)(VARIANT_BOOL saveChanges, BSTR filename);
	STDMETHOD(Save)(void);
	STDMETHOD(SaveAs)(BSTR filename);
};

// OBJECT_ENTRY_AUTO(__uuidof(Document), CDocumentAuto)
