// SolidAuto.h : CSolidAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"

// CSolidAuto

class ATL_NO_VTABLE CSolidAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ISolid, &IID_ISolid, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSolidAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SOLID)


BEGIN_COM_MAP(CSolidAuto)
	COM_INTERFACE_ENTRY(ISolid)
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

	void Initialize(PmeHSolid hSolid) {m_hSolid = hSolid;}

	static HRESULT GetIFacesFromHFaces(PmeHFaces hFaces, IFaces** ppVal);
	static HRESULT GetIEdgesFromHEdges(PmeHEdges hEdges, IEdges** ppVal);
	static HRESULT GetIVerticesFromHVertices(PmeHVertices hVertices, IVertices** ppVal);
	static HRESULT GetIVertexFromHVertex(PmeHVertex hVertex, IVertex** ppVal);

private:
	PmeHSolid m_hSolid;

public:
	STDMETHOD(get_Faces)(IFaces** ppVal);
	STDMETHOD(get_Edges)(IEdges** ppVal);
	STDMETHOD(get_Vertices)(IVertices** ppVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(Solid), CSolidAuto)
