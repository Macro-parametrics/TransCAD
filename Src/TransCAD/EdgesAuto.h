// EdgesAuto.h : CEdgesAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"

// CEdgesAuto

class ATL_NO_VTABLE CEdgesAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IEdges, &IID_IEdges, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEdgesAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EDGES)


BEGIN_COM_MAP(CEdgesAuto)
	COM_INTERFACE_ENTRY(IEdges)
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
	
	void Initialize(PmeHEdges hEdges) {m_hEdges = hEdges;}

private:
	PmeHEdges m_hEdges;
	HRESULT GetIEdgeFromHEdge(PmeHEdge hEdge, IEdge** ppVal);

public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IEdge** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
};

//OBJECT_ENTRY_AUTO(__uuidof(Edges), CEdgesAuto)
