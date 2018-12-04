// Axis1Auto.h : CAxis1Auto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"


// CAxis1Auto

class ATL_NO_VTABLE CAxis1Auto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IAxis1, &IID_IAxis1, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAxis1Auto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AXIS1)


BEGIN_COM_MAP(CAxis1Auto)
	COM_INTERFACE_ENTRY(IAxis1)
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
	
	void Initialize(MrAxis1 axis) {m_axis = axis;}

	MrAxis1 GetAxis() {return m_axis;}

private:
	MrAxis1 m_axis;

public:
	STDMETHOD(get_Location)(IPoint3D** pVal);
	STDMETHOD(put_Location)(IPoint3D* pVal);
	STDMETHOD(get_Direction)(IPoint3D** pVal);
	STDMETHOD(put_Direction)(IPoint3D* pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(Axis1), CAxis1Auto)
