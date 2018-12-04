// SketchEditorAuto.cpp : CSketchEditorAuto의 구현입니다.

#include "stdafx.h"
#include "SketchEditorAuto.h"
#include ".\StdSketchLineAuto.h"
#include ".\StdSketchCircleAuto.h"
#include ".\StdSketchCircularArcAuto.h"
#include ".\ReferenceAuto.h"
#include ".\StdSketchCoincidentSamePointsAuto.h"
#include ".\StdSketchPerpendicularAuto.h"
#include ".\StdSketchParallelAuto.h"
#include ".\StdSketchHorizontalAuto.h"
#include ".\StdSketchVerticalAuto.h"

// CSketchEditorAuto

void CSketchEditorAuto::Initialize(PmeHStdSketchEditor hEditor)
{
	m_hEditor = hEditor;
}

STDMETHODIMP CSketchEditorAuto::Close(void)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdSketchEditorAPI::Close(m_hEditor);

	return S_OK;
}

STDMETHODIMP CSketchEditorAuto::Create2DLine2Points(BSTR name, double startX, double startY, double endX, double endY, IStdSketchLine** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmeHStdSketchGeometry hLine;
	PmeStdSketchEditorAPI::CreateLine(m_hEditor, strName, startX, startY, endX, endY, hLine);

	HRESULT hr;

	CComObject<CStdSketchLineAuto> * pObj = NULL;
	hr = CComObject<CStdSketchLineAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hLine);

	hr = pObj->QueryInterface(__uuidof(IStdSketchLine), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::Create2DCircleCenterPoint(BSTR name, double centerX, double centerY, double radius, IStdSketchCircle** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmeHStdSketchGeometry hCircle;
	PmeStdSketchEditorAPI::CreateCircle(m_hEditor, strName, centerX, centerY, radius, hCircle);

	HRESULT hr;

	CComObject<CStdSketchCircleAuto> * pObj = NULL;
	hr = CComObject<CStdSketchCircleAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this); // 수정 필요
	pObj->Initialize(hCircle);

	hr = pObj->QueryInterface(__uuidof(IStdSketchCircle), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::Create2DArc(BSTR name, double centerX, double centerY, double radius, double startAngle, double endAngle, IStdSketchCircularArc** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmeHStdSketchGeometry hArc;
	PmeStdSketchEditorAPI::CreateCircularArc(m_hEditor, strName, centerX, centerY, radius, startAngle, endAngle, hArc);

	HRESULT hr;

	CComObject<CStdSketchCircularArcAuto> * pObj = NULL;
	hr = CComObject<CStdSketchCircularArcAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this); // 수정 필요
	pObj->Initialize(hArc);

	hr = pObj->QueryInterface(__uuidof(IStdSketchCircularArc), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::Create2DArcCenterStartEnd(BSTR name, double centerX, double centerY, double startX, double startY, double endX, double endY, IStdSketchCircularArc** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmeHStdSketchGeometry hArc;
	PmeStdSketchEditorAPI::CreateCircularArcFromCenterStartEnd(m_hEditor, strName, centerX, centerY, startX, startY, endX, endY, hArc);

	HRESULT hr;

	CComObject<CStdSketchCircularArcAuto> * pObj = NULL;
	hr = CComObject<CStdSketchCircularArcAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this); // 수정 필요
	pObj->Initialize(hArc);

	hr = pObj->QueryInterface(__uuidof(IStdSketchCircularArc), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::Create2DArc3Points(BSTR name, double startX, double startY, double intermediateX, double intermediateY, double endX, double endY, IStdSketchCircularArc** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmeHStdSketchGeometry hArc;
	PmeStdSketchEditorAPI::CreateCircularArcFrom3Points(m_hEditor, strName, startX, startY, intermediateX, intermediateY, endX, endY, hArc);

	HRESULT hr;

	CComObject<CStdSketchCircularArcAuto> * pObj = NULL;
	hr = CComObject<CStdSketchCircularArcAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this); // 수정 필요
	pObj->Initialize(hArc);

	hr = pObj->QueryInterface(__uuidof(IStdSketchCircularArc), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::Create2DCenterline2Points(BSTR name, double startX, double startY, double endX, double endY, IStdSketchLine** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmeHStdSketchGeometry hLine;
	PmeStdSketchEditorAPI::CreateCenterline(m_hEditor, strName, startX, startY, endX, endY, hLine);

	HRESULT hr;

	CComObject<CStdSketchLineAuto> * pObj = NULL;
	hr = CComObject<CStdSketchLineAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hLine);

	hr = pObj->QueryInterface(__uuidof(IStdSketchLine), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::CreateCoincidentSamePoints(BSTR name, IReference* pFirstObject, StdCoincidentSamePointsType firstType, IReference* pSecondObject, StdCoincidentSamePointsType secondType, IStdSketchCoincidentSamePoints** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName(name);

	PmeHStdSketchConstraint hConstraint;

	CReferenceAuto * pReference1 = static_cast<CReferenceAuto *>(pFirstObject);
	if(!pReference1)
		return E_INVALIDARG;

	CReferenceAuto * pReference2 = static_cast<CReferenceAuto *>(pSecondObject);
	if(!pReference2)
		return E_INVALIDARG;

	PmeHReference hReference1 = pReference1->GetHReference();
	PmeHReference hReference2 = pReference2->GetHReference();

	PmeStdSketchEditorAPI::CreateCoincident(m_hEditor, strName, hReference1, (PmeSamePointsType)firstType, hReference2, (PmeSamePointsType)secondType, hConstraint);

	CComObject<CStdSketchCoincidentSamePointsAuto> * pObj = NULL;
	hr = CComObject<CStdSketchCoincidentSamePointsAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hConstraint);

	hr = pObj->QueryInterface(__uuidof(IStdSketchCoincidentSamePoints), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::CreatePerpendicular(BSTR name, IReference* pReferenceEdit, IReference* pTarget, IStdSketchPerpendicular** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName(name);

	PmeHStdSketchConstraint hConstraint;

	CReferenceAuto * pReference1 = static_cast<CReferenceAuto *>(pReferenceEdit);
	if(!pReference1)
		return E_INVALIDARG;

	CReferenceAuto * pReference2 = static_cast<CReferenceAuto *>(pTarget);
	if(!pReference2)
		return E_INVALIDARG;

	PmeHReference hReference1 = pReference1->GetHReference();
	PmeHReference hReference2 = pReference2->GetHReference();

	PmeStdSketchEditorAPI::CreatePerpendicular(m_hEditor, strName, hReference1, hReference2, hConstraint);

	CComObject<CStdSketchPerpendicularAuto> * pObj = NULL;
	hr = CComObject<CStdSketchPerpendicularAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hConstraint);

	hr = pObj->QueryInterface(__uuidof(IStdSketchPerpendicular), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::CreateParallel(BSTR name, IReference* pReferenceEdit, IReference* pTarget, IStdSketchParallel** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName(name);

	PmeHStdSketchConstraint hConstraint;

	CReferenceAuto * pReference1 = static_cast<CReferenceAuto *>(pReferenceEdit);
	if(!pReference1)
		return E_INVALIDARG;

	CReferenceAuto * pReference2 = static_cast<CReferenceAuto *>(pTarget);
	if(!pReference2)
		return E_INVALIDARG;

	PmeHReference hReference1 = pReference1->GetHReference();
	PmeHReference hReference2 = pReference2->GetHReference();

	PmeStdSketchEditorAPI::CreateParallel(m_hEditor, strName, hReference1, hReference2, hConstraint);

	CComObject<CStdSketchParallelAuto> * pObj = NULL;
	hr = CComObject<CStdSketchParallelAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hConstraint);

	hr = pObj->QueryInterface(__uuidof(IStdSketchParallel), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::CreateHorizontal(BSTR name, IReference* pTarget, IStdSketchHorizontal** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName(name);

	PmeHStdSketchConstraint hConstraint;

	CReferenceAuto * pReferenceTarget = static_cast<CReferenceAuto *>(pTarget);
	if(!pReferenceTarget)
		return E_INVALIDARG;

	PmeHReference hReferenceTarget = pReferenceTarget->GetHReference();

	PmeStdSketchEditorAPI::CreateHorizontal(m_hEditor, strName, hReferenceTarget, hConstraint);

	CComObject<CStdSketchHorizontalAuto> * pObj = NULL;
	hr = CComObject<CStdSketchHorizontalAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hConstraint);

	hr = pObj->QueryInterface(__uuidof(IStdSketchHorizontal), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::CreateVertical(BSTR name, IReference* pTarget, IStdSketchVertical** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName(name);

	PmeHStdSketchConstraint hConstraint;

	CReferenceAuto * pReferenceTarget = static_cast<CReferenceAuto *>(pTarget);
	if(!pReferenceTarget)
		return E_INVALIDARG;

	PmeHReference hReferenceTarget = pReferenceTarget->GetHReference();

	PmeStdSketchEditorAPI::CreateVertical(m_hEditor, strName, hReferenceTarget, hConstraint);

	CComObject<CStdSketchVerticalAuto> * pObj = NULL;
	hr = CComObject<CStdSketchVerticalAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	// pObj->InitializeDispatchImplEx(m_pApplication, this);
	pObj->Initialize(hConstraint);

	hr = pObj->QueryInterface(__uuidof(IStdSketchVertical), (void **)ppVal);

	return hr;
}

STDMETHODIMP CSketchEditorAuto::DeleteByName(BSTR name)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr = S_OK;
	//*ppVal = NULL;

	CString strName(name);

	PmeStdSketchEditorAPI::DeleteItemByName(m_hEditor, strName);

	return hr;
}