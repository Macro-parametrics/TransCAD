// StdSketchOriginAuto.h : CStdSketchOriginAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchOriginAuto

class ATL_NO_VTABLE CStdSketchOriginAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchOriginAuto, &CLSID_StdSketchOrigin>,
	public IDispatchImplEx<IStdSketchOrigin, &IID_IStdSketchOrigin, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchOriginAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHORIGIN)


BEGIN_COM_MAP(CStdSketchOriginAuto)
	COM_INTERFACE_ENTRY(IStdSketchOrigin)
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

	static HRESULT GetIStdSketchOriginFromHStdSketchOrigin(PmeHStdSketchOrigin hOrigin, IStdSketchOrigin** ppVal);
	void Initialize(PmeHStdSketchOrigin hOrigin) {m_hOrigin = hOrigin;}

private:
	PmeHStdSketchOrigin m_hOrigin;

public:
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchOrigin), CStdSketchOriginAuto)
