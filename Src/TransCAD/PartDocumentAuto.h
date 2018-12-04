// PartDocumentAuto.h : CPartDocumentAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"

// CPartDocumentAuto

class ATL_NO_VTABLE CPartDocumentAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CPartDocumentAuto, &CLSID_PartDocument>,
	public IDispatchImplEx<IPartDocument, &IID_IPartDocument, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPartDocumentAuto()
		: m_pDocument(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PARTDOCUMENTAUTO)


BEGIN_COM_MAP(CPartDocumentAuto)	
	COM_INTERFACE_ENTRY(IPartDocument)
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

	void Initialize(PmDocument * pDocument);

private:
	PmDocument * m_pDocument;

public:
	// IDoc
	STDMETHOD(get_FullName)(BSTR* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Path)(BSTR* pVal);
	STDMETHOD(get_Saved)(VARIANT_BOOL* pVal);
	STDMETHOD(Activate)(void);
	STDMETHOD(Close)(VARIANT_BOOL saveChanges, BSTR filename);
	STDMETHOD(Save)(void);
	STDMETHOD(SaveAs)(BSTR filename);
	// IPartDocument
    STDMETHOD(get_Part)(IPart** pVal);
	STDMETHOD(Update)(void);
	STDMETHOD(get_Title)(BSTR* pVal);

	STDMETHOD(DoMeshGeneration)(double normalTolerance,double surfaceTolerance);
	STDMETHOD(GetBBDiagonal)(void);
	
	STDMETHOD(ImportFromCATIA)(BSTR path);
	STDMETHOD(ExportToCATIA)(BSTR path);
	STDMETHOD(ImportFromUG)(BSTR path);
	STDMETHOD(ExportToUG)(BSTR path);
	STDMETHOD(ExportToMesh)(BSTR path);

	STDMETHOD(ExportToBrep)(BSTR path);
	STDMETHOD(ExportToXML)(BSTR path);
	STDMETHOD(ImportFromXML)(BSTR path);
	STDMETHOD(ImportFromBrep)(BSTR path);
	STDMETHOD(ConvertMesh)(BSTR source, BSTR target);

	STDMETHOD(RunScriptInterface)(BSTR command);
};

// OBJECT_ENTRY_AUTO(__uuidof(PartDocument), CPartDocumentAuto)
