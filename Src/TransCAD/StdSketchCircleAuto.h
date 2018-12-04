// StdSketchCircleAuto.h : CStdSketchCircleAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\StdSketchGeometryImpl.h"

typedef IDispatchImplEx<IStdSketchCircle, &IID_IStdSketchCircle, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSketchCircleType;


// CStdSketchCircleAuto

class ATL_NO_VTABLE CStdSketchCircleAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchCircleAuto, &CLSID_StdSketchCircle>,
	// public IDispatchImplEx<IStdSketchCircle, &IID_IStdSketchCircle, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
	public IStdSketchGeometryImpl<IStdSketchCircleType>
{
public:
	CStdSketchCircleAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHCIRCLE)


BEGIN_COM_MAP(CStdSketchCircleAuto)
	COM_INTERFACE_ENTRY(IStdSketchCircle)
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

private:
	PmeHStdSketchGeometry m_hCircle;

public:
	// IStdSketchGeometry
	//STDMETHOD(get_Type)(StdSketchGeometryType* pVal);
	//STDMETHOD(get_Name)(BSTR* pVal);
	//STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);
	// IStdSketchCircle
	STDMETHOD(get_CenterPoint)(IStdSketchControlPoint** ppVal);
	STDMETHOD(get_Radius)(double* pVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchCircle), CStdSketchCircleAuto)
