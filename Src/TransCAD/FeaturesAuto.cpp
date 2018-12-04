// FeaturesAuto.cpp : CFeaturesAuto의 구현입니다.

#include "stdafx.h"
#include "FeaturesAuto.h"
#include ".\ReferenceAuto.h"
#include ".\ReferencesAuto.h"
#include ".\StdDefaultDatumPlaneFeatureAuto.h"
#include ".\StdSketchFeatureAuto.h"
#include ".\StdSolidProtrusionExtrudeFeatureAuto.h"
#include ".\StdSolidCutExtrudeFeatureAuto.h"
#include ".\StdSolidFilletConstantFeatureAuto.h"
#include ".\StdSolidChamferFeatureAuto.h"
#include ".\StdSolidProtrusionSweepFeatureAuto.h"
#include ".\StdSolidProtrusionRevolveFeatureAuto.h"
#include ".\StdSolidCutRevolveFeatureAuto.h"
#include ".\StdSolidOperatePatternRectangularFeatureAuto.h"
#include ".\StdSolidOperatePatternCircularFeatureAuto.h"
#include ".\StdSolidHoleCounterboredFeatureAuto.h"
#include ".\StdSolidHoleCountersunkFeatureAuto.h"
#include ".\StdDatumPlaneOffsetFeatureAuto.h"
#include ".\StdSolidLoftFacesFeatureAuto.h"
#include ".\StdSolidLoftSectionsFeatureAuto.h"
#include ".\StdSolidCutSweepFeatureAuto.h"
#include ".\StdSolidHoleSimpleFeatureAuto.h"
#include ".\StdSolidShellFeatureAuto.h"
#include ".\StdSolidRevolveWithExternalAxisFeatureAuto.h"
#include ".\StdSolidDraftFeatureAuto.h"
#include ".\StdSolidOffsetFeatureAuto.h"
#include ".\StdSolidImportedBrepFeatureAuto.h"

#define BEGIN_FEATURE_HFEATURE_MAP(hfeature) \
	PmeFeatureType type; \
	PmeFeatureAPI::GetType( hfeature , type); \
	HRESULT hr = E_FAIL; \
	PmeHFeature hInnerHFeature = hfeature; \
	switch(type) {

#define END_FEATURE_HFEATURE_MAP() }return hr;

#define FEATURE_HFEATURE_MAP(type, ifeature) \
	case PmeFeatureType_##type: { \
			CComObject<C##type##Auto> * pObj = NULL; \
			hr = CComObject<C##type##Auto>::CreateInstance(&pObj); \
			if(FAILED(hr)) return hr; \
			pObj->InitializeDispatchImplEx(m_pApplication, this); \
            pObj->Initialize(hInnerHFeature); \
			hr = pObj->QueryInterface(__uuidof(I##type), (void **) ifeature); \
		} break;

// CFeaturesAuto



void CFeaturesAuto::Initialize(PmeHPart hPart)
{
	m_hPart = hPart;
}

STDMETHODIMP CFeaturesAuto::get_Count(long* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	int size;
	PmeFeaturesAPI::GetSize(hFeatures, size);

	*pVal = (long)size;

	return S_OK;
}

STDMETHODIMP CFeaturesAuto::get_Item(long index, IFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	PmeHFeature hFeature;
	PmeFeaturesAPI::GetItem(hFeatures, (int)index - 1, hFeature);

	HRESULT hr = GetIFeatureFromHFeature(hFeature, ppVal);
    
	return hr;
}

STDMETHODIMP CFeaturesAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	int size;
	PmeFeaturesAPI::GetSize(hFeatures, size);

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHFeature hFeature;
		PmeFeaturesAPI::GetItem(hFeatures, i, hFeature);
		
		IFeature * pFeature = NULL;
		
		hr = GetIFeatureFromHFeature(hFeature, &pFeature);
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pFeature->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pFeature->Release();
		if(FAILED(hr))
			return hr;

		// create a variant and add it to the collection
		CComVariant & var = pVarVect[i];
		var.vt = VT_DISPATCH;
		var.pdispVal = pDispatch;
	}

	hr = pEnumObject->Init(&pVarVect[0], &pVarVect[size], NULL, AtlFlagCopy);
	if(FAILED(hr))
		return hr;

    hr = pEnumObject->QueryInterface(IID_IEnumVARIANT, (void **)ppUnk);
	
	delete [] pVarVect;

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSketchFeature(BSTR name, IReference* pSketchPlane, IStdSketchFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pSketchPlane);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSketchFeatureAPI::Create(m_hPart, strName, hReference, hFeature);	

	CComObject<CStdSketchFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSketchFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSketchFeature), (void **)ppVal);
    
	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidProtrusionExtrudeFeature(BSTR name, IReference* pProfileSketch, double startDepth, StdExtrudeEndType startCondition, double endDepth, StdExtrudeEndType endCondition, VARIANT_BOOL isFlip, IStdSolidProtrusionExtrudeFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;
	
	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidProtrusionExtrudeFeatureAPI::Create(m_hPart, strName, hReference, startDepth, /* 수정 필요 */ (PmeStdExtrudeEndType)startCondition, endDepth, (PmeStdExtrudeEndType)endCondition, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdSolidProtrusionExtrudeFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidProtrusionExtrudeFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidProtrusionExtrudeFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidProtrusionSweepFeature(BSTR name, IReference* pProfileSketch, IReference* pGuideCurve, IStdSolidProtrusionSweepFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;
	PmeHReference hReference = pReference->GetHReference();

	CReferenceAuto * pReference2 = static_cast<CReferenceAuto *>(pGuideCurve);
	if(!pReference2)
		return E_INVALIDARG;
	PmeHReference hReference2 = pReference2->GetHReference();

	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidProtrusionSweepFeatureAPI::Create(m_hPart, strName, hReference, hReference2, hFeature);

	CComObject<CStdSolidProtrusionSweepFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidProtrusionSweepFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidProtrusionSweepFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidProtrusionRevolveFeature(BSTR name, IReference* pProfileSketch, double startAngle, StdRevolveEndType startCondition, double endAngle, StdRevolveEndType endCondition, VARIANT_BOOL isFlip, IStdSolidProtrusionRevolveFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidProtrusionRevolveFeatureAPI::Create(m_hPart, strName, hReference, startAngle, /* 수정 필요 */ (PmeStdRevolveEndType)startCondition, endAngle, (PmeStdRevolveEndType)endCondition, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdSolidProtrusionRevolveFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidProtrusionRevolveFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidProtrusionRevolveFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidCutExtrudeFeature(BSTR name, IReference* pProfileSketch, double startDepth, StdExtrudeEndType startCondition, double endDepth, StdExtrudeEndType endCondition, VARIANT_BOOL isFlip, IStdSolidCutExtrudeFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidCutExtrudeFeatureAPI::Create(m_hPart, strName, hReference, startDepth, /* 수정 필요 */ (PmeStdExtrudeEndType)startCondition, endDepth, (PmeStdExtrudeEndType)endCondition, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdSolidCutExtrudeFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidCutExtrudeFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidCutExtrudeFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidCutSweepFeature(BSTR name, IReference* pProfileSketch, IReference* pGuideCurve, IStdSolidCutSweepFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;
	PmeHReference hReference = pReference->GetHReference();

	CReferenceAuto * pReference2 = static_cast<CReferenceAuto *>(pGuideCurve);
	if(!pReference2)
		return E_INVALIDARG;
	PmeHReference hReference2 = pReference2->GetHReference();

	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidCutSweepFeatureAPI::Create(m_hPart, strName, hReference, hReference2, hFeature);

	CComObject<CStdSolidCutSweepFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidCutSweepFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidCutSweepFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidCutRevolveFeature(BSTR name, IReference* pProfileSketch, double startAngle, StdRevolveEndType startCondition, double endAngle, StdRevolveEndType endCondition, VARIANT_BOOL isFlip, IStdSolidCutRevolveFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidCutRevolveFeatureAPI::Create(m_hPart, strName, hReference, startAngle, /* 수정 필요 */ (PmeStdRevolveEndType)startCondition, endAngle, (PmeStdRevolveEndType)endCondition, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdSolidCutRevolveFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidCutRevolveFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidCutRevolveFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidFilletConstantFeature(BSTR name, IReferences* pfilletEdges, double radius, PropagationType propagation, IStdSolidFilletConstantFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pReferences = static_cast<CReferencesAuto *>(pfilletEdges);
	if(!pReferences)
		return E_INVALIDARG;

	PmeHReferences hReferences = pReferences->GetHReferences();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidFilletConstantFeatureAPI::Create(m_hPart, strName, hReferences, radius, /* 수정 필요 */ (PmePropagationType)propagation, hFeature);

	CComObject<CStdSolidFilletConstantFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidFilletConstantFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidFilletConstantFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidChamferFeature(BSTR name, IReferences* pSelectedEdges, double length, IStdSolidChamferFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pReferences = static_cast<CReferencesAuto *>(pSelectedEdges);
	if(!pReferences)
		return E_INVALIDARG;

	PmeHReferences hReferences = pReferences->GetHReferences();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidChamferFeatureAPI::Create(m_hPart, strName, hReferences, length, hFeature);

	CComObject<CStdSolidChamferFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidChamferFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidChamferFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidOperatePatternRectangularFeature(BSTR name, IReferences* pTargetFeatures, double columnSpacing, double colDirX, double colDirY, double colDirZ, int columnNumber, double rowSpacing, double rowDirX, double rowDirY, double rowDirZ, int rowNumber, IStdSolidOperatePatternRectangularFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pReferences = static_cast<CReferencesAuto *>(pTargetFeatures);
	if(!pReferences)
		return E_INVALIDARG;

	PmeHReferences hReferences = pReferences->GetHReferences();
	CString strName(name);

	MrDirection columnDirection(colDirX, colDirY, colDirZ);
	MrDirection rowDirection(rowDirX, rowDirY, rowDirZ);

	PmeHFeature hFeature = 0;
	PmeStdSolidOperatePatternRectangularFeatureAPI::Create(m_hPart, strName, hReferences, columnSpacing, columnDirection, columnNumber, rowSpacing, rowDirection, rowNumber, hFeature);

	CComObject<CStdSolidOperatePatternRectangularFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidOperatePatternRectangularFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidOperatePatternRectangularFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidOperatePatternCircularFeature(BSTR name, IReferences* pTargetFeatures, double x1, double y1, double z1, double x2, double y2, double z2, int angleNumber, double angleIncrement, int radialNumber, double radialSpacing, VARIANT_BOOL radialAlignment, IStdSolidOperatePatternCircularFeature** ppVal)
{
 	AFX_MANAGE_STATE(AfxGetAppModuleState());
 
 	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pReferences = static_cast<CReferencesAuto *>(pTargetFeatures);
	if(!pReferences)
		return E_INVALIDARG;

	PmeHReferences hReferences = pReferences->GetHReferences();
	CString strName(name);

	MrAxis1 axis(MrPosition(x1, y1, z1), MrDirection(x2, y2, z2));

	PmeHFeature hFeature = 0;
	PmeStdSolidOperatePatternCircularFeatureAPI::Create(m_hPart, strName, hReferences, axis, angleNumber, angleIncrement, radialNumber, radialSpacing, radialAlignment == VARIANT_TRUE, hFeature);

	CComObject<CStdSolidOperatePatternCircularFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidOperatePatternCircularFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidOperatePatternCircularFeature), (void **)ppVal);

 	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidHoleSimpleFeature(BSTR name, IReference* pTargetFace, double cx, double cy, double cz, double Radius, double Depth, IStdSolidHoleSimpleFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pTargetFace);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidHoleSimpleFeatureAPI::Create(m_hPart, strName, hReference, cx, cy, cz, Radius, Depth, hFeature);

	CComObject<CStdSolidHoleSimpleFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidHoleSimpleFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidHoleSimpleFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidHoleCounterboredFeature(BSTR name, IReference* pTargetFace, double cx, double cy, double cz, double startRadius, double startDepth, double endRadius, double endDepth, double angle, IStdSolidHoleCounterboredFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pTargetFace);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidHoleCounterboredFeatureAPI::Create(m_hPart, strName, hReference, cx, cy, cz, startRadius, startDepth, endRadius, endDepth, angle, hFeature);

	CComObject<CStdSolidHoleCounterboredFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidHoleCounterboredFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidHoleCounterboredFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidHoleCountersunkFeature(BSTR name, IReference* pTargetFace, double cx, double cy, double cz, double radius, double depth, double sinkRadius, double sinkAngle, double bottomAngle, IStdSolidHoleCountersunkFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pTargetFace);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidHoleCountersunkFeatureAPI::Create(m_hPart, strName, hReference, cx, cy, cz, radius, depth, sinkRadius, sinkAngle, bottomAngle, hFeature);

	CComObject<CStdSolidHoleCountersunkFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidHoleCountersunkFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidHoleCountersunkFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewDatumPlaneOffsetFeature(BSTR name, IReference* pSelectedPlane, double distance, VARIANT_BOOL isFlip, IStdDatumPlaneOffsetFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pSelectedPlane);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create(m_hPart, strName, hReference, distance, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdDatumPlaneOffsetFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdDatumPlaneOffsetFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdDatumPlaneOffsetFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewDatumPlaneOffsetFeature2(BSTR name, double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz, VARIANT_BOOL isFlip, IStdDatumPlaneOffsetFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;
	
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdDatumPlaneOffsetFeatureAPI::Create2(m_hPart, strName, ox, oy, oz, xx, xy, xz, yx, yy, yz, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdDatumPlaneOffsetFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdDatumPlaneOffsetFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdDatumPlaneOffsetFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidLoftFacesFeature(BSTR name, IReference* pFace1, double param1, IReference* pFace2, double param2, IStdSolidLoftFacesFeature** ppVal )
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference1 = static_cast<CReferenceAuto *>(pFace1);
	if(!pReference1)
		return E_INVALIDARG;

	CReferenceAuto * pReference2 = static_cast<CReferenceAuto *>(pFace2);
	if(!pReference2)
		return E_INVALIDARG;

	PmeHReference hReference1 = pReference1->GetHReference();
	PmeHReference hReference2 = pReference2->GetHReference();
	CString strName(name);

	PmeHFeature hFeature = 0;
	PmeStdSolidLoftFacesFeatureAPI::Create(m_hPart, strName, hReference1, param1,hReference2, param2, hFeature);

	CComObject<CStdSolidLoftFacesFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidLoftFacesFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidLoftFacesFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidLoftSectionsFeature(BSTR name, IReferences* pLoftSections, VARIANT_BOOL isCut, IStdSolidLoftSectionsFeature** ppVal )
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pLoftSections1 = static_cast<CReferencesAuto *>(pLoftSections);
	if(!pLoftSections1)
		return E_INVALIDARG;

	CString strName(name);
	PmeHReferences hReferences1 = pLoftSections1->GetHReferences();
	//PmeHReference hReference2 = pReference2->GetHReference();
	

	PmeHFeature hFeature = 0;
	PmeStdSolidLoftSectionsFeatureAPI::Create(m_hPart, strName, hReferences1, isCut == VARIANT_TRUE, hFeature);


	CComObject<CStdSolidLoftSectionsFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidLoftSectionsFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidLoftSectionsFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidShellFeature(BSTR name, IReferences* pTargetFaces, double innerThickness, double outerThickness, IStdSolidShellFeature** ppVal )
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pTargetFaces1 = static_cast<CReferencesAuto *>(pTargetFaces);
	if(!pTargetFaces1)
		return E_INVALIDARG;

	CString strName(name);
	PmeHReferences hReferences1 = pTargetFaces1->GetHReferences();

	PmeHFeature hFeature = 0;
	PmeStdSolidShellFeatureAPI::Create(m_hPart, strName, hReferences1, innerThickness, outerThickness, hFeature);


	CComObject<CStdSolidShellFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidShellFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidShellFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidRevolveWithExternalAxisFeature(BSTR name, IReference* pProfileSketch, double startAngle, StdRevolveEndType startCondition, double endAngle, StdRevolveEndType endCondition, double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ, VARIANT_BOOL isCut, VARIANT_BOOL isFlip, IStdSolidRevolveWithExternalAxisFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferenceAuto * pReference = static_cast<CReferenceAuto *>(pProfileSketch);
	if(!pReference)
		return E_INVALIDARG;

	PmeHReference hReference = pReference->GetHReference();
	CString strName(name);

	MrAxis1 axis(MrPosition(orgX, orgY, orgZ), MrDirection(dirX, dirY, dirZ));

	PmeHFeature hFeature = 0;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::Create(m_hPart, strName, hReference, startAngle, (PmeStdRevolveEndType)startCondition, endAngle, (PmeStdRevolveEndType)endCondition, axis, isCut == VARIANT_TRUE, isFlip == VARIANT_TRUE, hFeature);

	CComObject<CStdSolidRevolveWithExternalAxisFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidRevolveWithExternalAxisFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidRevolveWithExternalAxisFeature), (void **)ppVal);

	return hr;
}
	
STDMETHODIMP CFeaturesAuto::AddNewSolidDraftFeature(BSTR name, IReferences* pTargetFaces, double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ, double draftAngle, IStdSolidDraftFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pTargetFaces1 = static_cast<CReferencesAuto *>(pTargetFaces);
	if(!pTargetFaces1)
		return E_INVALIDARG;

	CString strName(name);
	PmeHReferences hReferences1 = pTargetFaces1->GetHReferences();

	MrAxis1 axis(MrPosition(orgX, orgY, orgZ), MrDirection(dirX, dirY, dirZ));
	
	PmeHFeature hFeature = 0;
	PmeStdSolidDraftFeatureAPI::Create(m_hPart, strName, hReferences1, axis, draftAngle, hFeature);

	CComObject<CStdSolidDraftFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidDraftFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidDraftFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidOffsetFeature(BSTR name, IReferences* pTargetFaces, double offsetThickness, IStdSolidOffsetFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CReferencesAuto * pTargetFaces1 = static_cast<CReferencesAuto *>(pTargetFaces);
	if(!pTargetFaces1)
		return E_INVALIDARG;

	CString strName(name);
	PmeHReferences hReferences1 = pTargetFaces1->GetHReferences();

	PmeHFeature hFeature = 0;
	PmeStdSolidOffsetFeatureAPI::Create(m_hPart, strName, hReferences1, offsetThickness, hFeature);

	CComObject<CStdSolidOffsetFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidOffsetFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidOffsetFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::AddNewSolidImportedBrepFeature(BSTR name, BSTR filePath, IStdSolidImportedBrepFeature** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName(name);
	CString strFilePath(filePath);

	PmeHFeature hFeature = 0;
	PmeStdSolidImportedBrepFeatureAPI::Create(m_hPart, strName, strFilePath, hFeature);

	CComObject<CStdSolidImportedBrepFeatureAuto> * pObj = NULL;
	hr = CComObject<CStdSolidImportedBrepFeatureAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hFeature);

	hr = pObj->QueryInterface(__uuidof(IStdSolidImportedBrepFeature), (void **)ppVal);

	return hr;
}

STDMETHODIMP CFeaturesAuto::Delete(long index)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	HRESULT hr = S_OK;

	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);

	PmeFeaturesAPI::DeleteItem(hFeatures, (int)index);
    
	return hr;
}

STDMETHODIMP CFeaturesAuto::DeleteByName(BSTR name)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;

	PmeHFeatures hFeatures;
	PmePartAPI::GetFeatures(m_hPart, hFeatures);
	
	PmeHExplicitModel hExplicitModel;
	PmePartAPI::GetExplicitModel(m_hPart, hExplicitModel);

	CString strName(name);
	PmeFeaturesAPI::DeleteItemByName(hFeatures, strName);
    PmeExplicitModelAPI::DeleteItemByName(hExplicitModel, strName);

	return hr;
}

HRESULT CFeaturesAuto::GetIFeatureFromHFeature(PmeHFeature hFeature, IFeature **ppVal)
{
	BEGIN_FEATURE_HFEATURE_MAP(hFeature)
		FEATURE_HFEATURE_MAP(StdDefaultDatumPlaneFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSketchFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidProtrusionExtrudeFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidCutExtrudeFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidFilletConstantFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidChamferFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidProtrusionSweepFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidProtrusionRevolveFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidCutRevolveFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidOperatePatternRectangularFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidOperatePatternCircularFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidHoleCounterboredFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidHoleCountersunkFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdDatumPlaneOffsetFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidLoftFacesFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidLoftSectionsFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidCutSweepFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidHoleSimpleFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidShellFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidRevolveWithExternalAxisFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidDraftFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidOffsetFeature, ppVal)
		FEATURE_HFEATURE_MAP(StdSolidImportedBrepFeature, ppVal)
	END_FEATURE_HFEATURE_MAP()
}