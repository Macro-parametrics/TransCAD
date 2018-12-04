// Point3DAuto.h : CPoint3DAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"


// CPoint3DAuto

class ATL_NO_VTABLE CPoint3DAuto :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IPoint3D, &IID_IPoint3D, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPoint3DAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_POINT3D)


BEGIN_COM_MAP(CPoint3DAuto)
	COM_INTERFACE_ENTRY(IPoint3D)
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
	
	void Initialize(MrPosition point3D) {m_point3D = point3D;}

	MrPosition GetPoint() {return m_point3D;}

private:
	MrPosition m_point3D;

public:
	STDMETHOD(get_X)(double* pVal);
	STDMETHOD(get_Y)(double* pVal);
	STDMETHOD(get_Z)(double* pVal);
	STDMETHOD(put_X)(double pVal);
	STDMETHOD(put_Y)(double pVal);
	STDMETHOD(put_Z)(double pVal);
};

//OBJECT_ENTRY_AUTO(__uuidof(Point3D), CPoint3DAuto)
