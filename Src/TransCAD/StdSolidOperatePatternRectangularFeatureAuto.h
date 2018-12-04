// StdSolidOperatePatternRectangularFeatureAuto.h : CStdSolidOperatePatternRectangularFeatureAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"
#include ".\FeatureImpl.h"

typedef IDispatchImplEx<IStdSolidOperatePatternRectangularFeature, &IID_IStdSolidOperatePatternRectangularFeature, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0> IStdSolidOperatePatternRectangularFeatureType;


// CStdSolidOperatePatternRectangularFeatureAuto

class ATL_NO_VTABLE CStdSolidOperatePatternRectangularFeatureAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IFeatureImpl<IStdSolidOperatePatternRectangularFeatureType>
{
public:
	CStdSolidOperatePatternRectangularFeatureAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STDSOLIDOPERATEPATTERNRECTANGULARFEATURE)


BEGIN_COM_MAP(CStdSolidOperatePatternRectangularFeatureAuto)
	COM_INTERFACE_ENTRY(IStdSolidOperatePatternRectangularFeature)
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
	STDMETHOD(get_TargetFeatures)(IReferences** ppVal);
	STDMETHOD(get_ColumnSpacing)(double* pVal);
	STDMETHOD(get_ColumnDirection)(double* x, double* y, double* z);
	STDMETHOD(get_ColumnNumber)(int* pVal);
	STDMETHOD(get_RowSpacing)(double* pVal);
	STDMETHOD(get_RowDirection)(double* x, double* y, double* z);
	STDMETHOD(get_RowNumber)(int* pVal);

	STDMETHOD(put_TargetFeatures)(IReferences* ppVal);
	STDMETHOD(put_ColumnSpacing)(double pVal);
	STDMETHOD(PutColumnDirection)(double x, double y, double z);
	STDMETHOD(put_ColumnNumber)(int pVal);
	STDMETHOD(put_RowSpacing)(double pVal);
	STDMETHOD(put_RowNumber)(int pVal);
	STDMETHOD(PutRowDirection)(double x, double y, double z);
};

// OBJECT_ENTRY_AUTO(__uuidof(StdSolidOperatePatternRectangularFeature), CStdSolidOperatePatternRectangularFeatureAuto)
