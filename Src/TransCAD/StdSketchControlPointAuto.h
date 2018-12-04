// StdSketchControlPointAuto.h : CStdSketchControlPointAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\StdSketchGeometryImpl.h"

typedef IDispatchImplEx<IStdSketchControlPoint, &IID_IStdSketchControlPoint, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSketchControlPointType;


// CStdSketchControlPointAuto

class ATL_NO_VTABLE CStdSketchControlPointAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	//public CComCoClass<CStdSketchControlPointAuto, &CLSID_StdSketchControlPoint>,
	//public IDispatchImplEx<IStdSketchControlPoint, &IID_IStdSketchControlPoint, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
	public IStdSketchGeometryImpl<IStdSketchControlPointType>
{
public:
	CStdSketchControlPointAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHCONTROLPOINT)


BEGIN_COM_MAP(CStdSketchControlPointAuto)
	COM_INTERFACE_ENTRY(IStdSketchControlPoint)
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

	static HRESULT GetIStdSketchControlPointFromHStdSketchGeometry(PmeHStdSketchGeometry hControlPoint, IStdSketchControlPoint** ppVal);


public:
	// IStdSketchGeometry
	//STDMETHOD(get_Type)(StdSketchGeometryType* pVal);
	//STDMETHOD(get_Name)(BSTR* pVal);
	//STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);
	// IStdSketchControlPoint
	STDMETHOD(get_X)(double* pVal);
	STDMETHOD(get_Y)(double* pVal);

};

//OBJECT_ENTRY_AUTO(__uuidof(StdSketchControlPoint), CStdSketchControlPointAuto)
