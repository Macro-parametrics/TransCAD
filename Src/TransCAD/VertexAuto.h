// VertexAuto.h : CVertexAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"

// CVertexAuto

class ATL_NO_VTABLE CVertexAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IVertex, &IID_IVertex, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CVertexAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VERTEX)


BEGIN_COM_MAP(CVertexAuto)
	COM_INTERFACE_ENTRY(IVertex)
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

	void Initialize(PmeHVertex hVertex) {m_hVertex = hVertex;}

	PmeHVertex GetHVertex(void) {return m_hVertex;}

private:
	PmeHVertex m_hVertex;

public:
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Coordinates)(double* x, double* y, double* z);
	STDMETHOD(get_X)(double* x);
	STDMETHOD(get_Y)(double* y);
	STDMETHOD(get_Z)(double* z);
};

//OBJECT_ENTRY_AUTO(__uuidof(Vertex), CVertexAuto)
