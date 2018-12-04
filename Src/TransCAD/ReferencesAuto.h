// ReferencesAuto.h : CReferencesAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"

// CReferencesAuto

class ATL_NO_VTABLE CReferencesAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IReferences, &IID_IReferences, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CReferencesAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_REFERENCES)


BEGIN_COM_MAP(CReferencesAuto)
	COM_INTERFACE_ENTRY(IReferences)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
		PmeReferencesAPI::Delete(m_hReferences);
	}

	void Initialize(PmeHReferences hReferences) {m_hReferences = hReferences;}

	PmeHReferences GetHReferences(void) {return m_hReferences;}

private:
	PmeHReferences m_hReferences;

public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IReference** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
	STDMETHOD(Add)(IReference* pReference);
};

// OBJECT_ENTRY_AUTO(__uuidof(References), CReferencesAuto)
