// StdSketchHDirectionAuto.h : CStdSketchHDirectionAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchHDirectionAuto

class ATL_NO_VTABLE CStdSketchHDirectionAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchHDirectionAuto, &CLSID_StdSketchHDirection>,
	public IDispatchImplEx<IStdSketchHDirection, &IID_IStdSketchHDirection, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchHDirectionAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHHDIRECTION)


BEGIN_COM_MAP(CStdSketchHDirectionAuto)
	COM_INTERFACE_ENTRY(IStdSketchHDirection)
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

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchHDirection), CStdSketchHDirectionAuto)
