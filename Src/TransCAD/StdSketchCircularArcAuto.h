// StdSketchCircularArcAuto.h : CStdSketchCircularArcAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\StdSketchGeometryImpl.h"

typedef IDispatchImplEx<IStdSketchCircularArc, &IID_IStdSketchCircularArc, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSketchCircularArcType;

// CStdSketchCircularArcAuto

class ATL_NO_VTABLE CStdSketchCircularArcAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchCircularArcAuto, &CLSID_StdSketchCircularArc>,
	// public IDispatchImplEx<IStdSketchCircularArc, &IID_IStdSketchCircularArc, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
	public IStdSketchGeometryImpl<IStdSketchCircularArcType>
{
public:
	CStdSketchCircularArcAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHCIRCULARARC)


BEGIN_COM_MAP(CStdSketchCircularArcAuto)
	COM_INTERFACE_ENTRY(IStdSketchCircularArc)
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
	}

public:
	// IStdSketchGeometry
	//STDMETHOD(get_Type)(StdSketchGeometryType* pVal);
	//STDMETHOD(get_Name)(BSTR* pVal);
	//STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);
	// IStdSketchCircularArc
	STDMETHOD(get_CenterPoint)(IStdSketchControlPoint** ppVal);
	STDMETHOD(get_StartPoint)(IStdSketchControlPoint** ppVal);
	STDMETHOD(get_EndPoint)(IStdSketchControlPoint** ppVal);
	STDMETHOD(get_Radius)(double* pVal);
	STDMETHOD(get_StartAngle)(double* pVal);
	STDMETHOD(get_EndAngle)(double* pVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchCircularArc), CStdSketchCircularArcAuto)
