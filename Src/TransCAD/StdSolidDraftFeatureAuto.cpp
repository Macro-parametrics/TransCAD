// StdSolidDraftFeatureAuto.cpp : CStdSolidDraftFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidDraftFeatureAuto.h"
#include ".\PartAuto.h"

// CStdSolidDraftFeatureAuto

STDMETHODIMP CStdSolidDraftFeatureAuto::get_TargetFaces(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hDraftFaces;
	PmeStdSolidDraftFeatureAPI::GetTargetFaces(m_hFeature, hDraftFaces);

	return CPartAuto::GetIReferencesFromHReferences(hDraftFaces, ppVal);
}

STDMETHODIMP CStdSolidDraftFeatureAuto::put_TargetFaces(IReferences* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hDraftFaces;
	CPartAuto::GetHReferencesFromIReferences(ppVal, hDraftFaces);

	PmeStdSolidDraftFeatureAPI::SetTargetFaces(m_hFeature, hDraftFaces);

	return S_OK;
}

STDMETHODIMP CStdSolidDraftFeatureAuto::get_PullingDirection(double* orgX, double* orgY, double* orgZ, double* dirX, double* dirY, double* dirZ)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis1 pullingDirection;

	PmeStdSolidDraftFeatureAPI::GetPullingDirection(m_hFeature, pullingDirection);

	*orgX = pullingDirection.Location().X();
	*orgY = pullingDirection.Location().Y();
	*orgZ = pullingDirection.Location().Z();

	*dirX = pullingDirection.Direction().X();
	*dirY = pullingDirection.Direction().Y();
	*dirZ = pullingDirection.Direction().Z();

	return S_OK;
}

STDMETHODIMP CStdSolidDraftFeatureAuto::PutPullingDirection(double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis1 pullingDirection(MrPosition(orgX, orgY, orgZ), MrDirection(dirX, dirY, dirZ));

	PmeStdSolidDraftFeatureAPI::SetPullingDirection(m_hFeature, pullingDirection);

	return S_OK;
}

STDMETHODIMP CStdSolidDraftFeatureAuto::get_DraftAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double draftAngle;
	PmeStdSolidDraftFeatureAPI::GetDraftAngle(m_hFeature, draftAngle);

	*pVal = draftAngle;

	return S_OK;
}

STDMETHODIMP CStdSolidDraftFeatureAuto::put_DraftAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double draftAngle = pVal;
	PmeStdSolidDraftFeatureAPI::SetDraftAngle(m_hFeature, draftAngle);

	return S_OK;
}