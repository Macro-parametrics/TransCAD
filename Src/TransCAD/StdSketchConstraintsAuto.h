// StdSketchConstraintsAuto.h : CStdSketchConstraintsAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchConstraintsAuto

class ATL_NO_VTABLE CStdSketchConstraintsAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchConstraintsAuto, &CLSID_StdSketchConstraints>,
	public IDispatchImplEx<IStdSketchConstraints, &IID_IStdSketchConstraints, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchConstraintsAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHCONSTRAINTS)


BEGIN_COM_MAP(CStdSketchConstraintsAuto)
	COM_INTERFACE_ENTRY(IStdSketchConstraints)
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
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IStdSketchGeometry** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
	STDMETHOD(get_FindByName)(IStdSketchGeometry** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchConstraints), CStdSketchConstraintsAuto)
