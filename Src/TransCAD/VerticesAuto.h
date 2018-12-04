// VerticesAuto.h : CVerticesAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"


// CVerticesAuto

class ATL_NO_VTABLE CVerticesAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IVertices, &IID_IVertices, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CVerticesAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VERTICES)


BEGIN_COM_MAP(CVerticesAuto)
	COM_INTERFACE_ENTRY(IVertices)
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
	
	void Initialize(PmeHVertices hVertices) {m_hVertices = hVertices;}

private:
	PmeHVertices m_hVertices;

public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IVertex** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
};

//OBJECT_ENTRY_AUTO(__uuidof(Vertices), CVerticesAuto)
