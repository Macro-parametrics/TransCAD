// EdgeAuto.cpp : CEdgeAuto의 구현입니다.

#include "stdafx.h"
#include "EdgeAuto.h"
#include "VertexAuto.h"
#include "SolidAuto.h"
// CEdgeAuto

STDMETHODIMP CEdgeAuto::get_Type(EdgeType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeEdgeType type;
	PmeEdgeAPI::GetType(m_hEdge, type);

	*pVal = ConvertPmeEdgeTypeToEdgeType(type);

	return S_OK;
}

STDMETHODIMP CEdgeAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;
	PmeEdgeAPI::GetName(m_hEdge, name);

	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CEdgeAuto::get_StartPoint(IVertex** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHVertex hVertex;
	PmeEdgeAPI::GetStartPoint(m_hEdge, hVertex);

	CSolidAuto::GetIVertexFromHVertex(hVertex, ppVal);

	return S_OK;
}

STDMETHODIMP CEdgeAuto::get_EndPoint(IVertex** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHVertex hVertex;
	PmeEdgeAPI::GetEndPoint(m_hEdge, hVertex);

	CSolidAuto::GetIVertexFromHVertex(hVertex, ppVal);

	return S_OK;
}


EdgeType CEdgeAuto::ConvertPmeEdgeTypeToEdgeType(PmeEdgeType type)
{
	return (EdgeType)type;
}