// PartAuto.cpp : CPartAuto의 구현입니다.

#include "stdafx.h"
#include "PartAuto.h"
#include ".\FeaturesAuto.h"
#include ".\ReferenceAuto.h"
#include ".\ReferencesAuto.h"
#include ".\SolidAuto.h"
// CPartAuto

void CPartAuto::Initialize(PmeHPart hPart)
{
	m_hPart = hPart;
}

HRESULT CPartAuto::GetIReferenceFromHReference(PmeHReference hReference, IReference** ppVal)
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hReference == 0)
		return S_OK;

	CComObject<CReferenceAuto> * pObj = NULL;
	hr = CComObject<CReferenceAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;
	
	pObj->Initialize(hReference);
	
	hr = pObj->QueryInterface(__uuidof(IReference), (void **)ppVal);

	return hr;
}

HRESULT CPartAuto::GetIReferencesFromHReferences(PmeHReferences hReferences, IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	PmeHReferences hNewReferences;
	PmeReferencesAPI::Copy(hReferences, hNewReferences);

	CComObject<CReferencesAuto> * pReferences = NULL;
	hr = CComObject<CReferencesAuto>::CreateInstance(&pReferences);
	if(FAILED(hr))
		return hr;

	pReferences->Initialize(hNewReferences);

	hr = pReferences->QueryInterface(__uuidof(IReferences), (void **)ppVal);
	
	return hr;
}

HRESULT CPartAuto::GetHReferenceFromIReference(IReference* ppVal, PmeHReference & hReference)
{
	CReferenceAuto * pRef = static_cast<CReferenceAuto *>(ppVal);
	
	if(!pRef)
		return E_INVALIDARG;

	hReference = pRef->GetHReference();

	return S_OK;
}

HRESULT CPartAuto::GetHReferencesFromIReferences(IReferences* ppVal, PmeHReferences & hReferences)
{
	CReferencesAuto * pRefs = static_cast<CReferencesAuto *>(ppVal);
	
	if(!pRefs)
		return E_INVALIDARG;

	hReferences = pRefs->GetHReferences();

	return S_OK;
}

HRESULT CPartAuto::GetISolidFromHSolid(PmeHSolid hSolid, ISolid** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	HRESULT hr;
	*ppVal = NULL;
	
	if(hSolid == 0)
		return S_OK;

	CComObject<CSolidAuto> * pObj = NULL;
	hr = CComObject<CSolidAuto>::CreateInstance(&pObj);
	if(FAILED(hr))
		return hr;

	pObj->Initialize(hSolid);

	hr = pObj->QueryInterface(__uuidof(ISolid), (void **)ppVal);
	if(FAILED(hr))
		return hr;

	return hr;
}

STDMETHODIMP CPartAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	CString name;

	PmePartAPI::GetName(m_hPart,name);

	*pVal = name.AllocSysString();

	return S_OK;
}

STDMETHODIMP CPartAuto::set_Name(BSTR pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	PmePartAPI::SetName(m_hPart,(CString)pVal);
	return S_OK;
}

STDMETHODIMP CPartAuto::get_ParentName(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString name;

	PmePartAPI::GetParentName(m_hPart,name);

	*pVal = name.AllocSysString();

	return S_OK;
}

STDMETHODIMP CPartAuto::set_ParentName(BSTR pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	PmePartAPI::SetParentName(m_hPart,(CString)pVal);
	return S_OK;
}

STDMETHODIMP CPartAuto::get_Features(IFeatures** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CFeaturesAuto> * pFeatures = NULL;
	hr = CComObject<CFeaturesAuto>::CreateInstance(&pFeatures);
	if(FAILED(hr))
		return hr;

	pFeatures->InitializeDispatchImplEx(m_pApplication, this);
	pFeatures->Initialize(m_hPart);

	hr = pFeatures->QueryInterface(__uuidof(IFeatures), (void **)ppVal);
	if(FAILED(hr))
		return hr;

	return hr;
}

STDMETHODIMP CPartAuto::get_Solid(ISolid** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHExplicitModel hExplicitModel;
	PmePartAPI::GetExplicitModel(m_hPart, hExplicitModel);
	
	PmeHSolid hSolid;
	PmeExplicitModelAPI::GetSolid2(hExplicitModel, hSolid);

	return GetISolidFromHSolid(hSolid, ppVal);
}

STDMETHODIMP CPartAuto::GetPlacement( double* ox, double* oy, double* oz, double* xx, double* xy, double* xz, double* yx, double* yy, double* yz )
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis2 placement;

	PmePartAPI::GetPlacement( m_hPart, placement );

	MrPosition origin = placement.Location();
	MrDirection xDirection = placement.XDirection();
	MrDirection yDirection = placement.YDirection();

	*ox = origin.X();
	*oy = origin.Y();
	*oz = origin.Z();
	*xx = xDirection.X();
	*xy = xDirection.Y();
	*xz = xDirection.Z();
	*yx = yDirection.X();
	*yy = yDirection.Y();
	*yz = yDirection.Z();

	return S_OK;
}

STDMETHODIMP CPartAuto::CreateReferences(IReferences** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHReferences hReferences;

	PmeReferencesAPI::Create(hReferences);

	*ppVal = NULL;
	HRESULT hr = GetIReferencesFromHReferences(hReferences, ppVal);
	
	return hr;
}

STDMETHODIMP CPartAuto::SelectObjectByName(BSTR name, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	
	HRESULT hr;
	CString strName(name);
	PmeHReference hReference = 0;

	PmePartAPI::SelectObjectByName(m_hPart, strName, hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CPartAuto::SelectBrepByName(BSTR name, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	CString strName(name);
	PmeHReference hReference = 0;

	PmePartAPI::SelectBrepByName(m_hPart, strName, hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CPartAuto::SelectPlaneByAxis(double ox, double oy, double oz, double xx, double xy, double xz, double yx, double yy, double yz, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	MrPosition origin(ox, oy, oz);
	MrDirection xdir(xx, xy, xz);
	MrDirection ydir(yx, yy, yz);
	MrDirection zdir(xdir ^ ydir);

	PmeHReference hReference = 0;

	PmePartAPI::SelectPlaneByAxis(m_hPart, MrAxis2(origin, zdir, xdir), hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CPartAuto::SelectCurveBy3Points(double startx, double starty, double startz, double endx, double endy, double endz, double curvex, double curvey, double curvez, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	MrPosition start(startx, starty, startz);
	MrPosition end(endx, endy, endz);
	MrPosition pointOnCurve(curvex, curvey, curvez);

	PmeHReference hReference = 0;

	PmePartAPI::SelectCurveBy3Points(m_hPart, start, end, pointOnCurve, hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CPartAuto::SelectCurveByPoint(double curvex, double curvey, double curvez, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;

	MrPosition pointOnCurve(curvex, curvey, curvez);

	PmeHReference hReference = 0;

	PmePartAPI::SelectCurveByPoint(m_hPart, pointOnCurve, hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CPartAuto::SelectFeatureByName(BSTR name, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	CString strName(name);
	PmeHReference hReference = 0;

	PmePartAPI::SelectFeatureByName(m_hPart, strName, hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

STDMETHODIMP CPartAuto::LoadFromFile(BSTR name)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);

	PmePartAPI::LoadBrepFile(strName,m_hPart);

	return S_OK;
}

STDMETHODIMP CPartAuto::IsBrepPart(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	BOOL result;
	PmePartAPI::IsBrepPart(m_hPart,result);

	*pVal = (result) ? VARIANT_TRUE : VARIANT_FALSE;


	return S_OK;
}

STDMETHODIMP CPartAuto::SelectSketchSegmentByName(BSTR name, IReference** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	CString strName(name);
	PmeHReference hReference = 0;

	PmePartAPI::SelectSketchGeometryByName(m_hPart, strName, hReference);	

	hr = GetIReferenceFromHReference(hReference, ppVal);

	return hr;
}

