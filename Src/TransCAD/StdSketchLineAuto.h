// StdSketchLineAuto.h : CStdSketchLineAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\StdSketchGeometryImpl.h"

typedef IDispatchImplEx<IStdSketchLine, &IID_IStdSketchLine, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSketchLineType;


// CStdSketchLineAuto

class ATL_NO_VTABLE CStdSketchLineAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchLineAuto, &CLSID_StdSketchLine>,
	// public IDispatchImplEx<IStdSketchLine, &IID_IStdSketchLine, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
	public IStdSketchGeometryImpl<IStdSketchLineType>
{
public:
	CStdSketchLineAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHLINE)


BEGIN_COM_MAP(CStdSketchLineAuto)
	COM_INTERFACE_ENTRY(IStdSketchLine)
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
	// IStdSketchLine
	STDMETHOD(get_StartPoint)(IStdSketchControlPoint** ppVal);
	STDMETHOD(get_EndPoint)(IStdSketchControlPoint** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchLine), CStdSketchLineAuto)
