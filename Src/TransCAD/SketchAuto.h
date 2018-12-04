// SketchAuto.h : CSketchAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"


// CSketchAuto

class ATL_NO_VTABLE CSketchAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CSketchAuto, &CLSID_Sketch>,
	public IDispatchImpl<ISketch, &IID_ISketch, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSketchAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SKETCH)


BEGIN_COM_MAP(CSketchAuto)
	COM_INTERFACE_ENTRY(ISketch)
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

public:

};

// OBJECT_ENTRY_AUTO(__uuidof(Sketch), CSketchAuto)
