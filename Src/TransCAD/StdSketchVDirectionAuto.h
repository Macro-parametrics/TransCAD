// StdSketchVDirectionAuto.h : CStdSketchVDirectionAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchVDirectionAuto

class ATL_NO_VTABLE CStdSketchVDirectionAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchVDirectionAuto, &CLSID_StdSketchVDirection>,
	public IDispatchImplEx<IStdSketchVDirection, &IID_IStdSketchVDirection, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchVDirectionAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHVDIRECTION)


BEGIN_COM_MAP(CStdSketchVDirectionAuto)
	COM_INTERFACE_ENTRY(IStdSketchVDirection)
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
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchVDirection), CStdSketchVDirectionAuto)
