// FaceAuto.cpp : CFaceAuto의 구현입니다.

#include "stdafx.h"
#include "FaceAuto.h"
#include "SolidAuto.h"
#include "PartAuto.h"
// CFaceAuto

STDMETHODIMP CFaceAuto::get_Type(FaceType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeFaceType type;
	PmeFaceAPI::GetType(m_hFace, type);

	*pVal = ConvertPmeFaceTypeToFaceType(type);

	return S_OK;
}

STDMETHODIMP CFaceAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;
	PmeFaceAPI::GetName(m_hFace, name);

	name.SetSysString(pVal);

	return S_OK;
}

STDMETHODIMP CFaceAuto::get_Edges(IEdges** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHEdges hEdges;
	PmeFaceAPI::GetEdges(m_hFace, hEdges);

	return CSolidAuto::GetIEdgesFromHEdges(hEdges, ppVal);
}

STDMETHODIMP CFaceAuto::get_Vertices(IVertices** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHVertices hVertices;
	PmeFaceAPI::GetVertices(m_hFace, hVertices);

	return CSolidAuto::GetIVerticesFromHVertices(hVertices, ppVal);
}

STDMETHODIMP CFaceAuto::get_Centroid(double*cx, double* cy, double* cz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrPosition centroid;
	PmeFaceAPI::GetCentroid(m_hFace, centroid);

	*cx = centroid.X();
	*cy = centroid.Y();
	*cz = centroid.Z();

	return S_OK;
}

STDMETHODIMP CFaceAuto::get_XDirection(double* xx, double* xy, double* xz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection xDir;
	PmeFaceAPI::GetXDirection(m_hFace, xDir);

	*xx = xDir.X();
	*xy = xDir.Y();
	*xz = xDir.Z();

	return S_OK;
}

STDMETHODIMP CFaceAuto::get_YDirection(double* yx, double* yy, double* yz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection yDir;
	PmeFaceAPI::GetYDirection(m_hFace, yDir);

	*yx = yDir.X();
	*yy = yDir.Y();
	*yz = yDir.Z();

	return S_OK;
}

STDMETHODIMP CFaceAuto::get_ZDirection(double* zx, double* zy, double* zz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrDirection zDir;
	PmeFaceAPI::GetZDirection(m_hFace, zDir);

	*zx = zDir.X();
	*zy = zDir.Y();
	*zz = zDir.Z();

	return S_OK;
}

STDMETHODIMP CFaceAuto::get_Area(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double area = 0;
	PmeFaceAPI::GetArea(m_hFace, area);

	*pVal = area;

	return S_OK;
}


FaceType CFaceAuto::ConvertPmeFaceTypeToFaceType(PmeFaceType type)
{
	return (FaceType)type;
}
