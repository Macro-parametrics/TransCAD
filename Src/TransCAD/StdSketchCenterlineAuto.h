// StdSketchCenterlineAuto.h : CStdSketchCenterlineAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\StdSketchGeometryImpl.h"

typedef IDispatchImplEx<IStdSketchCenterline, &IID_IStdSketchCenterline, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSketchCenterlineType;


// CStdSketchCenterlineAuto

class ATL_NO_VTABLE CStdSketchCenterlineAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchCenterlineAuto, &CLSID_StdSketchCenterline>,
	// public IDispatchImpl<IStdSketchCenterline, &IID_IStdSketchCenterline, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
	public IStdSketchGeometryImpl<IStdSketchCenterlineType>
{
public:
	CStdSketchCenterlineAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHCENTERLINE)


BEGIN_COM_MAP(CStdSketchCenterlineAuto)
	COM_INTERFACE_ENTRY(IStdSketchCenterline)
	COM_INTERFACE_ENTRY(IStdSketchGeometry)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
		// ReleaseDispatchImplEx();
	}

public:
	// IStdSketchGeometry
	//STDMETHOD(get_Type)(StdSketchGeometryType* pVal);
	//STDMETHOD(get_Name)(BSTR* pVal);
	//STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);
	// IStdSketchCenterline
	STDMETHOD(get_StartPoint)(IStdSketchControlPoint** ppVal);
	STDMETHOD(get_EndPoint)(IStdSketchControlPoint** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchCenterline), CStdSketchCenterlineAuto)
