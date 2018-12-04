// StdSketchGeometriesAuto.h : CStdSketchGeometriesAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchGeometriesAuto

class ATL_NO_VTABLE CStdSketchGeometriesAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchGeometriesAuto, &CLSID_StdSketchGeometries>,
	public IDispatchImplEx<IStdSketchGeometries, &IID_IStdSketchGeometries, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchGeometriesAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHGEOMETRIES)


BEGIN_COM_MAP(CStdSketchGeometriesAuto)
	COM_INTERFACE_ENTRY(IStdSketchGeometries)
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

	void Initialize(PmeHFeature hFeature) {m_hFeature = hFeature;}

private:
	//PmeHStdSketchGeometries m_hGeometries;
	PmeHFeature m_hFeature;
	HRESULT GetIStdSketchGeometryFromHStdSketchGeometry(PmeHStdSketchGeometry hGeometry, IStdSketchGeometry** ppVal);

public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IStdSketchGeometry** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
	STDMETHOD(get_FindByName)(IStdSketchGeometry** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchGeometries), CStdSketchGeometriesAuto)
