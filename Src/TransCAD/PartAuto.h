// PartAuto.h : CPartAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.
#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include "Point3DAuto.h"
#include "Axis1Auto.h"

// CPartAuto

class ATL_NO_VTABLE CPartAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImplEx<IPart, &IID_IPart, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPartAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PART)


BEGIN_COM_MAP(CPartAuto)
	COM_INTERFACE_ENTRY(IPart)
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

	void Initialize(PmeHPart hPart);

	static HRESULT GetIReferenceFromHReference(PmeHReference hReference, IReference** ppVal);
	static HRESULT GetIReferencesFromHReferences(PmeHReferences hReferences, IReferences** ppVal);

	static HRESULT GetHReferenceFromIReference(IReference* ppVal, PmeHReference & hReference);
	static HRESULT GetHReferencesFromIReferences(IReferences* ppVal, PmeHReferences & hReferences);

	PmeHPart GetHPart(void) {return m_hPart;}

private:
	PmeHPart m_hPart;
	HRESULT GetISolidFromHSolid(PmeHSolid hSolid, ISolid** ppVal);

public:
	STDMETHOD(set_Name)(BSTR pVal);
	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(set_ParentName)(BSTR pVal);
	STDMETHOD(get_ParentName)(BSTR* pVal);
	STDMETHOD(get_Features)(IFeatures** ppVal);
	STDMETHOD(get_Solid)(ISolid** ppVal);
	
	STDMETHOD(GetPlacement)(double* ox, double* oy, double* oz, double* xx, double* xy, double* xz, double* yx, double* yy, double* yz);

	STDMETHOD(CreateReferences)(IReferences** ppVal);
	STDMETHOD(SelectObjectByName)(BSTR name, IReference** ppVal);
	STDMETHOD(SelectBrepByName)(BSTR name, IReference** ppVal);
	STDMETHOD(SelectPlaneByAxis)(double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz, IReference** ppVal);
	STDMETHOD(SelectCurveBy3Points)(double startx, double starty, double startz, double endx, double endy, double endz, double curvex, double curvey, double curvez, IReference** ppVal);
	STDMETHOD(SelectCurveByPoint)(double curvex, double curvey, double curvez, IReference** ppVal);
	STDMETHOD(SelectFeatureByName)(BSTR name, IReference** ppVal);
	STDMETHOD(LoadFromFile)(BSTR name);

	STDMETHOD(IsBrepPart)(VARIANT_BOOL* pVal);

	STDMETHOD(SelectSketchSegmentByName)(BSTR name, IReference** ppVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(Part), CPartAuto)
