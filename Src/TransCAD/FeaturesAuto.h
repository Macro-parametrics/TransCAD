// FeaturesAuto.h : CFeaturesAuto의 선언입니다.

#pragma once
#include "resource.h"       // 주 기호입니다.

#include "TransCAD.h"
#include ".\DispatchImplEx.h"

// CFeaturesAuto

class ATL_NO_VTABLE CFeaturesAuto : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImplEx<IFeatures, &IID_IFeatures, &LIBID_TransCAD, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFeaturesAuto()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FEATURES)


BEGIN_COM_MAP(CFeaturesAuto)
	COM_INTERFACE_ENTRY(IFeatures)
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

	void Initialize(PmeHPart hPart);

private:
	PmeHPart m_hPart;

private:
	HRESULT GetIFeatureFromHFeature(PmeHFeature hFeature, IFeature **ppVal);

public:
	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, IFeature** ppVal);
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
	STDMETHOD(Delete)(long index);
	STDMETHOD(DeleteByName)(BSTR name);
	STDMETHOD(AddNewSketchFeature)(BSTR name, IReference* pSketchPlane, IStdSketchFeature** ppVal);
	STDMETHOD(AddNewSolidProtrusionExtrudeFeature)(BSTR name, IReference* pProfileSketch, double startDepth, StdExtrudeEndType startCondition, double endDepth, StdExtrudeEndType endCondition, VARIANT_BOOL isFlip, IStdSolidProtrusionExtrudeFeature** ppVal);
	STDMETHOD(AddNewSolidCutExtrudeFeature)(BSTR name, IReference* pProfileSketch, double startDepth, StdExtrudeEndType startCondition, double endDepth, StdExtrudeEndType endCondition, VARIANT_BOOL isFlip, IStdSolidCutExtrudeFeature** ppVal);
	STDMETHOD(AddNewSolidFilletConstantFeature)(BSTR name, IReferences* pfilletEdges, double radius, PropagationType propagation, IStdSolidFilletConstantFeature** ppVal);
	STDMETHOD(AddNewSolidChamferFeature)(BSTR name, IReferences* pSelectedEdges, double length, IStdSolidChamferFeature** ppVal);
	STDMETHOD(AddNewSolidProtrusionSweepFeature)(BSTR name, IReference* pProfileSketch, IReference* pGuideCurve, IStdSolidProtrusionSweepFeature** ppVal);
	STDMETHOD(AddNewSolidProtrusionRevolveFeature)(BSTR name, IReference* pProfileSketch, double startAngle, StdRevolveEndType startCondition, double endAngle, StdRevolveEndType endCondition, VARIANT_BOOL isFlip, IStdSolidProtrusionRevolveFeature** ppVal);
	STDMETHOD(AddNewSolidCutRevolveFeature)(BSTR name, IReference* pProfileSketch, double startAngle, StdRevolveEndType startCondition, double endAngle, StdRevolveEndType endCondition, VARIANT_BOOL isFlip, IStdSolidCutRevolveFeature** ppVal);
	STDMETHOD(AddNewSolidOperatePatternRectangularFeature)(BSTR name, IReferences* pTargetFeatures, double columnSpacing, double colDirX, double colDirY, double colDirZ, int columnNumber, double rowSpacing, double rowDirX, double rowDirY, double rowDirZ, int rowNumber, IStdSolidOperatePatternRectangularFeature** ppVal);
	STDMETHOD(AddNewSolidOperatePatternCircularFeature)(BSTR name, IReferences* pTargetFeatures, double x1, double y1, double z1, double x2, double y2, double z2, int angleNumber, double angleIncrement, int radialNumber, double radialSpacing, VARIANT_BOOL radialAlignment, IStdSolidOperatePatternCircularFeature** ppVal);
	STDMETHOD(AddNewSolidHoleCounterboredFeature)(BSTR name, IReference* pTargetFace, double cx, double cy, double cz, double startRadius, double startDepth, double endRadius, double endDepth, double angle, IStdSolidHoleCounterboredFeature** ppVal);
	STDMETHOD(AddNewSolidHoleCountersunkFeature)(BSTR name, IReference* pTargetFace, double cx, double cy, double cz, double radius, double depth, double sinkRadius, double sinkAngle, double bottomAngle, IStdSolidHoleCountersunkFeature** ppVal);
	STDMETHOD(AddNewDatumPlaneOffsetFeature)(BSTR name, IReference* pSelectedPlane, double distance, VARIANT_BOOL isFlip, IStdDatumPlaneOffsetFeature** ppVal);
	STDMETHOD(AddNewDatumPlaneOffsetFeature2)(BSTR name, double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz, VARIANT_BOOL isFlip, IStdDatumPlaneOffsetFeature** ppVal);
	STDMETHOD(AddNewSolidLoftFacesFeature)(BSTR name, IReference* pFace1, double param1, IReference* pFace2, double param2, IStdSolidLoftFacesFeature** ppVal );
	STDMETHOD(AddNewSolidLoftSectionsFeature)(BSTR name, IReferences* pLoftSections, VARIANT_BOOL isCut, IStdSolidLoftSectionsFeature** ppVal );
	STDMETHOD(AddNewSolidCutSweepFeature)(BSTR name, IReference* pProfileSketch, IReference* pGuideCurve, IStdSolidCutSweepFeature** ppVal);
	STDMETHOD(AddNewSolidHoleSimpleFeature)(BSTR name, IReference* pTargetFace, double cx, double cy, double cz, double Radius, double Depth, IStdSolidHoleSimpleFeature** ppVal);
	STDMETHOD(AddNewSolidShellFeature)(BSTR name, IReferences* pTargetFaces, double innerThickness, double outerThickness, IStdSolidShellFeature** ppVal);
	STDMETHOD(AddNewSolidRevolveWithExternalAxisFeature)(BSTR name, IReference* pProfileSketch, double startAngle, StdRevolveEndType startCondition, double endAngle, StdRevolveEndType endCondition, double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ, VARIANT_BOOL isCut, VARIANT_BOOL isFlip, IStdSolidRevolveWithExternalAxisFeature** ppVal);
	STDMETHOD(AddNewSolidDraftFeature)(BSTR name, IReferences* pTargetFaces, double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ, double draftAngle, IStdSolidDraftFeature** ppVal);
	STDMETHOD(AddNewSolidOffsetFeature)(BSTR name, IReferences* pTargetFaces, double offsetThickness, IStdSolidOffsetFeature** ppVal);
	STDMETHOD(AddNewSolidImportedBrepFeature)(BSTR name, BSTR filePath, IStdSolidImportedBrepFeature** ppVal);
};

// OBJECT_ENTRY_AUTO(__uuidof(Features), CFeaturesAuto)
