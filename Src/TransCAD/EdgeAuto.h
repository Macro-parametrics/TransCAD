// EdgeAuto.h : CEdgeAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include ".\PmeEdgeType.h"
#include "TransCAD.h"


// CEdgeAuto

class ATL_NO_VTABLE CEdgeAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IEdge, &IID_IEdge, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEdgeAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EDGE)


BEGIN_COM_MAP(CEdgeAuto)
	COM_INTERFACE_ENTRY(IEdge)
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

	void Initialize(PmeHEdge hEdge) {m_hEdge = hEdge;}

	PmeHEdge GetHEdge(void) {return m_hEdge;}

private:
	PmeHEdge m_hEdge;
	EdgeType ConvertPmeEdgeTypeToEdgeType(PmeEdgeType type);

public:
	STDMETHOD(get_Type)(EdgeType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_StartPoint)(IVertex** ppVal);
	STDMETHOD(get_EndPoint)(IVertex** ppVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(Edge), CEdgeAuto)
