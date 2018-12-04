// DocumentsAuto.h : CDocumentsAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include <vector>


// CDocumentsAuto

class ATL_NO_VTABLE CDocumentsAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CDocumentsAuto, &CLSID_Documents>,
	public IDispatchImpl<IDocs, &IID_IDocs, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDocumentsAuto()
		: m_pApplication(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DOCUMENTSAUTO)


BEGIN_COM_MAP(CDocumentsAuto)
	COM_INTERFACE_ENTRY(IDocs)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
		m_pApplication->Release();
	}

	void Initialize(IApplication * pApplication);
	void GetDocumentsInfo();
	HRESULT GetIDocFromDocument(CDocument * pDoc, IDoc** ppRet);

private:
	IApplication * m_pApplication;
	std::vector<CDocument *> m_listDocuments;

public:
	STDMETHOD(get_Application)(IApplication** ppVal);
	STDMETHOD(get_Parent)(IDispatch** ppVal);
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IDoc** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
	STDMETHOD(AddPartDocument)(IPartDocument** ppVal);
	STDMETHOD(AddAssemDocument)(IAssemDocument** ppVal);
	STDMETHOD(Close)(void);
	STDMETHOD(Open)(BSTR filename, IPartDocument** ppVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(Documents), CDocumentsAuto)
