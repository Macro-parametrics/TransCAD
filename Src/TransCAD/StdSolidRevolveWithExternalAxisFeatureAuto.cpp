// StdSolidRevolveWithExternalAxisFeatureAuto.cpp : CStdSolidRevolveWithExternalAxisFeatureAuto의 구현입니다.

#include "stdafx.h"
#include "StdSolidRevolveWithExternalAxisFeatureAuto.h"


// CStdSolidRevolveWithExternalAxisFeatureAuto


STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_ProfileSketch(IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetProfileSketch(m_hFeature, hReference);

	return CPartAuto::GetIReferenceFromHReference(hReference, ppVal);
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_StartAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetStartAngle(m_hFeature, startAngle);

	*pVal = startAngle;

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_StartCondition(StdRevolveEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdRevolveEndType startCondition;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetStartCondition(m_hFeature, startCondition);

	*pVal = (StdRevolveEndType)startCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_EndAngle(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetEndAngle(m_hFeature, endAngle);

	*pVal = endAngle;

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_EndCondition(StdRevolveEndType* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeStdRevolveEndType endCondition;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetStartCondition(m_hFeature, endCondition);

	*pVal = (StdRevolveEndType)endCondition;

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_RevolveAxis(double* orgX, double* orgY, double* orgZ, double* dirX, double* dirY, double* dirZ)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis1 revolveAxis;

	PmeStdSolidRevolveWithExternalAxisFeatureAPI::GetRevolveAxis(m_hFeature, revolveAxis);

	*orgX = revolveAxis.Location().X();
	*orgY = revolveAxis.Location().Y();
	*orgZ = revolveAxis.Location().Z();

	*dirX = revolveAxis.Direction().X();
	*dirY = revolveAxis.Direction().Y();
	*dirZ = revolveAxis.Direction().Z();

	return S_OK;
}


STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_IsCut(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isCut;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::IsCut(m_hFeature, isCut);

	*pVal = (isCut) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::get_IsFlip(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::IsFlip(m_hFeature, isFlip);

	*pVal = (isFlip) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}


STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::put_ProfileSketch(IReference* ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReference hReference = 0;
	CPartAuto::GetHReferenceFromIReference(ppVal, hReference);
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetProfileSketch(m_hFeature, hReference);
	
	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::put_IsFlip(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isFlip = pVal?true:false;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetFlip(m_hFeature, isFlip);

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::put_StartAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double startAngle = pVal;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetStartAngle(m_hFeature, startAngle);
	
	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::put_EndAngle(double pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	double endAngle = pVal;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetEndAngle(m_hFeature, endAngle);

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::put_IsCut(VARIANT_BOOL pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	bool isCut = pVal?true:false;
	PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetCut(m_hFeature, isCut);

	return S_OK;
}

STDMETHODIMP CStdSolidRevolveWithExternalAxisFeatureAuto::PutRevolveAxis(double orgX, double orgY, double orgZ, double dirX, double dirY, double dirZ)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis1 revolveAxis(MrPosition(orgX, orgY, orgZ), MrDirection(dirX, dirY, dirZ));

	PmeStdSolidRevolveWithExternalAxisFeatureAPI::SetRevolveAxis(m_hFeature, revolveAxis);

	return S_OK;
}