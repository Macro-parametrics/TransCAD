// ReferenceAuto.h : CReferenceAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"
#include ".\PmeReferenceType.h"


// CReferenceAuto

class ATL_NO_VTABLE CReferenceAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IReference, &IID_IReference, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CReferenceAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_REFERENCE)


BEGIN_COM_MAP(CReferenceAuto)
	COM_INTERFACE_ENTRY(IReference)
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

	void Initialize(PmeHReference hReference);

	PmeHReference GetHReference(void) {return m_hReference;}

private:
	PmeHReference m_hReference;

private:
	ReferenceType ConvertPmeReferenceTypeToReferenceType(PmeReferenceType type);

public:
	STDMETHOD(get_Type)(ReferenceType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_ReferenceeName)(BSTR* pVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(Reference), CReferenceAuto)
