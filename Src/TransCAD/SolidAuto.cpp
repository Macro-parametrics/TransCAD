// SolidAuto.cpp : CSolidAuto의 구현입니다.

#include "stdafx.h"
#include "SolidAuto.h"
#include "FacesAuto.h"
#include "EdgesAuto.h"
#include "VerticesAuto.h"
#include "VertexAuto.h"
#include ".\PartAuto.h"

// CSolidAuto

STDMETHODIMP CSolidAuto::get_Faces(IFaces** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHFaces hFaces;
	PmeSolidAPI::GetFaces(m_hSolid, hFaces);
	
	return GetIFacesFromHFaces(hFaces, ppVal);
}

STDMETHODIMP CSolidAuto::get_Edges(IEdges** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHEdges hEdges;
	PmeSolidAPI::GetEdges(m_hSolid, hEdges);

	return GetIEdgesFromHEdges(hEdges, ppVal);
}

STDMETHODIMP CSolidAuto::get_Vertices(IVertices** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHVertices hVertices;
	PmeSolidAPI::GetVertices(m_hSolid, hVertices);

	return GetIVerticesFromHVertices(hVertices, ppVal);
}

HRESULT CSolidAuto::GetIFacesFromHFaces(PmeHFaces hFaces, IFaces** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hFaces == 0)
		return S_OK;

	CComObject<CFacesAuto> * pObj = NULL;
	hr = CComObject<CFacesAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hFaces);

	hr = pObj->QueryInterface(__uuidof(IFaces), (void **)ppVal);

	return hr;
}

HRESULT CSolidAuto::GetIEdgesFromHEdges(PmeHEdges hEdges, IEdges** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hEdges == 0)
		return S_OK;

	CComObject<CEdgesAuto> * pObj = NULL;
	hr = CComObject<CEdgesAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hEdges);

	hr = pObj->QueryInterface(__uuidof(IEdges), (void **)ppVal);

	return hr;
}

HRESULT CSolidAuto::GetIVerticesFromHVertices(PmeHVertices hVertices, IVertices** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hVertices == 0)
		return S_OK;

	CComObject<CVerticesAuto> * pObj = NULL;
	hr = CComObject<CVerticesAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hVertices);

	hr = pObj->QueryInterface(__uuidof(IVertices), (void **)ppVal);

	return hr;
}

HRESULT CSolidAuto::GetIVertexFromHVertex(PmeHVertex hVertex, IVertex** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hVertex == 0)
		return S_OK;

	CComObject<CVertexAuto> * pObj = NULL;
	hr = CComObject<CVertexAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hVertex);

	hr = pObj->QueryInterface(__uuidof(IVertex), (void **)ppVal);

	return hr;
}