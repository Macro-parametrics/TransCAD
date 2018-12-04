// FaceAuto.h : CFaceAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include ".\PmeFaceType.h"
#include "TransCAD.h"

// CFaceAuto

class ATL_NO_VTABLE CFaceAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IFace, &IID_IFace, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFaceAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FACE)


BEGIN_COM_MAP(CFaceAuto)
	COM_INTERFACE_ENTRY(IFace)
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

	void Initialize(PmeHFace hFace) {m_hFace = hFace;}

	PmeHFace GetHFace(void) {return m_hFace;}

private:
	PmeHFace m_hFace;
	FaceType ConvertPmeFaceTypeToFaceType(PmeFaceType type);

public:
	STDMETHOD(get_Type)(FaceType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Edges)(IEdges** ppVal);
	STDMETHOD(get_Vertices)(IVertices** ppVal);
	STDMETHOD(get_Centroid)(double*cx, double* cy, double* cz);
	STDMETHOD(get_XDirection)(double* xx, double* xy, double* xz);
	STDMETHOD(get_YDirection)(double* yx, double* yy, double* yz);
	STDMETHOD(get_ZDirection)(double* zx, double* zy, double* zz);
	STDMETHOD(get_Area)(double* pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(Face), CFaceAuto)
