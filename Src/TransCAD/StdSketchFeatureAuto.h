// StdSketchFeatureAuto.h : CStdSketchFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSketchFeature, &IID_IStdSketchFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSketchFeatureType;

// CStdSketchFeatureAuto

class ATL_NO_VTABLE CStdSketchFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSketchFeatureType>
{
public:
	CStdSketchFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSKETCHFEATURE)


BEGIN_COM_MAP(CStdSketchFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSketchFeature)
	COM_INTERFACE_ENTRY(IFeature)
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

public:	
	// IStdSketchFeature
	STDMETHOD(get_Origin)(IStdSketchOrigin **ppVal);
	STDMETHOD(get_HDirection)(IStdSketchHDirection **ppVal);
	STDMETHOD(get_VDirection)(IStdSketchVDirection **ppVal);
	STDMETHOD(get_Geometries)(IStdSketchGeometries **ppVal);
	STDMETHOD(get_Constraints)(IStdSketchConstraints **ppVal);
	STDMETHOD(get_Sketch)(ISketch **ppVal);
	STDMETHOD(get_SketchPlane)(IReference** ppVal);
	STDMETHOD(get_IsInversed)(VARIANT_BOOL* pVal);

	STDMETHOD(OpenEditor)(ISketchEditor** ppVal);
	STDMETHOD(OpenEditorEx)(VARIANT_BOOL activateDcm, ISketchEditor** ppVal);
	STDMETHOD(SetCoordinateSystem)(double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz);
	STDMETHOD(GetCoordinateSystem)(double* ox, double* oy, double* oz, double* xx, double* xy, double* xz, double* yx, double* yy, double* yz);
	STDMETHOD(DeleteByName)(BSTR name);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSketchFeature), CStdSketchFeatureAuto)
