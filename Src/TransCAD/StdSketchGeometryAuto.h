// StdSketchGeometryAuto.h : CStdSketchGeometryAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchGeometryAuto

class ATL_NO_VTABLE CStdSketchGeometryAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchGeometryAuto, &CLSID_StdSketchGeometry>,
	public IDispatchImplEx<IStdSketchGeometry, &IID_IStdSketchGeometry, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchGeometryAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHGEOMETRY)


BEGIN_COM_MAP(CStdSketchGeometryAuto)
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
		ReleaseDispatchImplEx();
	}

	void Initialize(PmeHStdSketchGeometry hGeometry) {m_hGeometry = hGeometry;}

private:
	PmeHStdSketchGeometry m_hGeometry;
	StdSketchGeometryType ConvertPmeStdSketchGeometryTypeToStdSketchGeometryType(PmeStdSketchGeometryType type)
	{
		return (StdSketchGeometryType)type;
	}

public:
	STDMETHOD(get_Type)(StdSketchGeometryType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchGeometry), CStdSketchGeometryAuto)
