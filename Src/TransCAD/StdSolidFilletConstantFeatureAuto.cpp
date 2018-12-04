// StdSolidFilletConstantFeatureAuto.cpp : CStdSolidFilletConstantFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidFilletConstantFeatureAuto.h"
#include ".\PartAuto.h"

// CStdSolidFilletConstantFeatureAuto

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_FilletEdges(IReferences **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hFilletEdges;
	PmeStdSolidFilletConstantFeatureAPI::GetFilletEdges(m_hFeature, hFilletEdges);

	return CPartAuto::GetIReferencesFromHReferences(hFilletEdges, ppVal);
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::put_FilletEdges(IReferences *ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	HRESULT hr = S_OK;

	PmeHReferences hFilletEdges = 0;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hFilletEdges);

	PmeStdSolidFilletConstantFeatureAPI::SetFilletEdges(m_hFeature, hFilletEdges);

	return hr;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_Radius(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius;
	PmeStdSolidFilletConstantFeatureAPI::GetRadius(m_hFeature, radius);

	*pVal = radius;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::put_Radius(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double radius = pVal;
	PmeStdSolidFilletConstantFeatureAPI::SetRadius(m_hFeature, radius);

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_Propagation(PropagationType *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmePropagationType propagation;
	PmeStdSolidFilletConstantFeatureAPI::GetPropagationType(m_hFeature, propagation);

	*pVal = (PropagationType)propagation;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::put_Propagation(PropagationType pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmePropagationType propagation = (PmePropagationType)pVal;
	PmeStdSolidFilletConstantFeatureAPI::SetPropagationType(m_hFeature, propagation);

	return S_OK;
}


STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_StartPosX(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;
	
	PmeStdSolidFilletConstantFeatureAPI::GetStartPoint(m_hFeature, pos);
	
	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_StartPosY(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetStartPoint(m_hFeature, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_StartPosZ(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetStartPoint(m_hFeature, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_EndPosX(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetEndPoint(m_hFeature, pos);

	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_EndPosY(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetEndPoint(m_hFeature, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_EndPosZ(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetEndPoint(m_hFeature, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}



STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_StartPosXAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;
	
	PmeStdSolidFilletConstantFeatureAPI::GetStartPointAt(m_hFeature, index, pos);
	
	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_StartPosYAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetStartPointAt(m_hFeature, index, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_StartPosZAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetStartPointAt(m_hFeature, index, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_EndPosXAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetEndPointAt(m_hFeature, index, pos);

	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_EndPosYAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetEndPointAt(m_hFeature, index, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidFilletConstantFeatureAuto::get_EndPosZAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidFilletConstantFeatureAPI::GetEndPointAt(m_hFeature, index, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}
