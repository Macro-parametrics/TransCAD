// StdSketchConstraintAuto.h : CStdSketchConstraintAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"


// CStdSketchConstraintAuto

class ATL_NO_VTABLE CStdSketchConstraintAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	// public CComCoClass<CStdSketchConstraintAuto, &CLSID_StdSketchConstraint>,
	public IDispatchImplEx<IStdSketchConstraint, &IID_IStdSketchConstraint, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStdSketchConstraintAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHCONSTRAINT)


BEGIN_COM_MAP(CStdSketchConstraintAuto)
	COM_INTERFACE_ENTRY(IStdSketchConstraint)
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
	STDMETHOD(get_Type)(StdSketchGeometryType* pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_SketchFeature)(IStdSketchFeature** ppVal);

};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchConstraint), CStdSketchConstraintAuto)
