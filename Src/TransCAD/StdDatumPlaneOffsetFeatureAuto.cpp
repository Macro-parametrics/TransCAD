// StdDatumPlaneOffsetFeatureAuto.cpp : CStdDatumPlaneOffsetFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdDatumPlaneOffsetFeatureAuto.h"


// CStdDatumPlaneOffsetFeatureAuto

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_SelectedPlane(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdDatumPlaneOffsetFeatureAPI::GetSelectedPlane(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_IsFlip(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip;
	PmeStdDatumPlaneOffsetFeatureAPI::IsFlip(m_hFeature, isFlip);

	*pVal = (isFlip) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_Distance(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double distance;
	PmeStdDatumPlaneOffsetFeatureAPI::GetDistance(m_hFeature, distance);

	*pVal = distance;

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_IsFree(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFree;
	PmeStdDatumPlaneOffsetFeatureAPI::IsFree(m_hFeature, isFree);

	*pVal = (isFree) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::put_SelectedPlane(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdDatumPlaneOffsetFeatureAPI::SetSelectedPlane(m_hFeature, hReference);

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::put_IsFlip(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip = pVal?true:false;
	
	PmeStdDatumPlaneOffsetFeatureAPI::SetFlip(m_hFeature, isFlip);

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::put_Distance(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double distance = pVal;
	PmeStdDatumPlaneOffsetFeatureAPI::SetDistance(m_hFeature, distance);

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_Origin(double* ox, double* oy, double* oz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition org;
	PmeStdDatumPlaneOffsetFeatureAPI::GetOrigin(m_hFeature, org);

	*ox = org.X();
	*oy = org.Y();
	*oz = org.Z();

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_XDirection(double* xx, double* xy, double* xz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection xDir;
	PmeStdDatumPlaneOffsetFeatureAPI::GetXDirection(m_hFeature, xDir);

	*xx = xDir.X();
	*xy = xDir.Y();
	*xz = xDir.Z();

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::get_YDirection(double* yx, double* yy, double* yz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection yDir;
	PmeStdDatumPlaneOffsetFeatureAPI::GetYDirection(m_hFeature, yDir);

	*yx = yDir.X();
	*yy = yDir.Y();
	*yz = yDir.Z();

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::PutOrigin(double ox, double oy, double oz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition org(ox, oy, oz);
	PmeStdDatumPlaneOffsetFeatureAPI::SetOrigin(m_hFeature, org);
	
	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::PutXDirection(double xx, double xy, double xz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection xDir(xx, xy, xz);
	PmeStdDatumPlaneOffsetFeatureAPI::SetXDirection(m_hFeature, xDir);

	return S_OK;
}

STDMETHODIMP CStdDatumPlaneOffsetFeatureAuto::PutYDirection(double yx, double yy, double yz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection yDir(yx, yy, yz);
	PmeStdDatumPlaneOffsetFeatureAPI::SetYDirection(m_hFeature, yDir);

	return S_OK;
}
