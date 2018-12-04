// StdSolidChamferFeatureAuto.cpp : CStdSolidChamferFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidChamferFeatureAuto.h"


// CStdSolidChamferFeatureAuto

STDMETHODIMP CStdSolidChamferFeatureAuto::get_ChamferType(ChamferType *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeChamferType chamferType;
	PmeStdSolidChamferFeatureAPI::GetChamferType(m_hFeature, chamferType);

	*pVal = (ChamferType)chamferType;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_SelectedEdges(IReferences **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hSelectedEdges;
	PmeStdSolidChamferFeatureAPI::GetSelectedEdges(m_hFeature, hSelectedEdges);

	return CPartAuto::GetIReferencesFromHReferences(hSelectedEdges, ppVal);
}

STDMETHODIMP CStdSolidChamferFeatureAuto::put_SelectedEdges(IReferences *ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hSelectedEdges;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hSelectedEdges);
	
	PmeStdSolidChamferFeatureAPI::SetSelectedEdges(m_hFeature, hSelectedEdges);

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_SelectedFace(IReference **ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hSelectedFace;
	PmeStdSolidChamferFeatureAPI::GetSelectedFace(m_hFeature, hSelectedFace);

	return CPartAuto::GetIReferenceFromHReference(hSelectedFace, ppVal);
	//return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_Length(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double length;
	PmeStdSolidChamferFeatureAPI::GetLength(m_hFeature, length);

	*pVal = length;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::put_Length(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double length = pVal;
	PmeStdSolidChamferFeatureAPI::SetLength(m_hFeature, length);

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_Value(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double value;
	PmeStdSolidChamferFeatureAPI::GetValue(m_hFeature, value);

	*pVal = value;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_StartPosX(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetStartPoint(m_hFeature, pos);

	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_StartPosY(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetStartPoint(m_hFeature, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_StartPosZ(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetStartPoint(m_hFeature, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_EndPosX(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetEndPoint(m_hFeature, pos);

	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_EndPosY(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetEndPoint(m_hFeature, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_EndPosZ(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetEndPoint(m_hFeature, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}


STDMETHODIMP CStdSolidChamferFeatureAuto::get_StartPosXAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;
	
	PmeStdSolidChamferFeatureAPI::GetStartPointAt(m_hFeature, index, pos);
	
	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_StartPosYAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetStartPointAt(m_hFeature, index, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_StartPosZAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetStartPointAt(m_hFeature, index, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_EndPosXAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetEndPointAt(m_hFeature, index, pos);

	coord = pos.x();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_EndPosYAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetEndPointAt(m_hFeature, index, pos);

	coord = pos.y();

	*pVal = coord;

	return S_OK;
}

STDMETHODIMP CStdSolidChamferFeatureAuto::get_EndPosZAt(int index, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	SPAposition pos;
	double coord;

	PmeStdSolidChamferFeatureAPI::GetEndPointAt(m_hFeature, index, pos);

	coord = pos.z();

	*pVal = coord;

	return S_OK;
}