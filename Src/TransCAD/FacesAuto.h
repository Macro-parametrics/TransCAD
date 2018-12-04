// FacesAuto.h : CFacesAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"


// CFacesAuto

class ATL_NO_VTABLE CFacesAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IFaces, &IID_IFaces, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFacesAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FACES)


BEGIN_COM_MAP(CFacesAuto)
	COM_INTERFACE_ENTRY(IFaces)
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

	void Initialize(PmeHFaces hFaces) {m_hFaces = hFaces;}

private:
	PmeHFaces m_hFaces;
	HRESULT GetIFaceFromHFace(PmeHFace hFace, IFace** ppVal);

public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IFace** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
};

//OBJECT_ENTRY_AUTO(__uuidof(Faces), CFacesAuto)
