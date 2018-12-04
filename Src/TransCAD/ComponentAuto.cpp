// ComponentAuto.cpp : CComponentAuto의 구현입니다.

#include "stdafx.h"
#include "ComponentAuto.h"
#include "PartAuto.h"

// CComponentAuto


void CComponentAuto::Initialize( PmeHComponent hComponent )
{
	m_hComponent = hComponent;
}

STDMETHODIMP CComponentAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	CString name;
	PmeComponentAPI::GetName(m_hComponent,name);
	*pVal = name.AllocSysString();

	return S_OK;
}

STDMETHODIMP CComponentAuto::set_Name(BSTR pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	PmeComponentAPI::SetName(m_hComponent,(CString)pVal);
	return S_OK;
}

STDMETHODIMP CComponentAuto::get_ParentName(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	CString name;
	PmeComponentAPI::GetParentName(m_hComponent,name);
	*pVal = name.AllocSysString();
	return S_OK;
}

STDMETHODIMP CComponentAuto::set_ParentName(BSTR pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	PmeComponentAPI::SetParentName(m_hComponent,(CString)pVal);
	return S_OK;
}

STDMETHODIMP CComponentAuto::GetPart(/*PmeHComponent& hComp,*/ int i, IPart** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	HRESULT hr;

	PmeHPart hPart;

	PmeComponentAPI::GetItem(m_hComponent, i, hPart);
	//hr = GetIPartFromHPart(hPart, ppVal);
		
	*ppVal = NULL;

	CComObject<CPartAuto> * pPart = NULL;
	hr = CComObject<CPartAuto>::CreateInstance(&pPart);
	if(FAILED(hr))
		return hr;

	pPart->InitializeDispatchImplEx(m_pApplication, this);
	pPart->Initialize(hPart);

	hr = pPart->QueryInterface(__uuidof(IPart), (void **)ppVal);
	
	return hr;
}

STDMETHODIMP CComponentAuto::GetComponent(/*PmeHComponent& hComp,*/ int i, IComp** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHComponent hComp;

	PmeComponentAPI::GetItem(m_hComponent,i,hComp);

	HRESULT hr = GetICompFromHComp(hComp, ppVal);

	return hr;
}

STDMETHODIMP CComponentAuto::IsPart( /*PmeHComponent& hComp,*/ int i,  VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	BOOL result;
	PmeComponentAPI::IsPart(m_hComponent,i,result);
	*pVal = (result) ? VARIANT_TRUE : VARIANT_FALSE;	
	return S_OK;
}

STDMETHODIMP CComponentAuto::IsComponent(/* PmeHComponent& hComp,*/ int i,  VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	

	BOOL result;
	PmeComponentAPI::IsComponent(m_hComponent,i,result);

	*pVal = (result) ? VARIANT_TRUE : VARIANT_FALSE;


	return S_OK;
}

STDMETHODIMP CComponentAuto::GetPlacement(/*PmeHComponent hComponent,*/ double* ox, double* oy, double* oz, double* xx, double* xy, double* xz, double* yx, double* yy, double* yz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	MrAxis2 placement;

	PmeComponentAPI::GetPlacement(m_hComponent,placement);

	*ox = placement.Location().X();
	*oy = placement.Location().Y();
	*oz = placement.Location().Z();

	*xx = placement.XDirection().X();
	*xy = placement.XDirection().Y();
	*xz = placement.XDirection().Z();

	*yx = placement.YDirection().X();
	*yy = placement.YDirection().Y();
	*yz = placement.YDirection().Z();

	return S_OK;
}

STDMETHODIMP CComponentAuto::SetPlacement(/*PmeHComponent hComponent,*/ double ox, double oy, double oz, double zx, double zy, double zz, double xx, double xy, double xz)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	MrAxis2 placement(MrPosition(ox,oy,oz),MrDirection(zx,zy,zz),MrDirection(xx,xy,xz));

	

	PmeComponentAPI::SetPlacement(m_hComponent,placement);

	return S_OK;
}

STDMETHODIMP CComponentAuto::AddPart(/*PmeHComponent& hItem,*/ IPart* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());
	

	CPartAuto * pPartAuto = static_cast<CPartAuto *>(pVal);
	if(!pPartAuto)
		return E_INVALIDARG;

	PmeHPart hPart = pPartAuto->GetHPart();

	PmeComponentAPI::AddPart(m_hComponent,hPart);

	return S_OK;
}

STDMETHODIMP CComponentAuto::AddComponent(/*PmeHComponent& hItem,*/ IComp* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CComponentAuto * pCompAuto = static_cast<CComponentAuto *>(pVal);
	if(!pCompAuto)
		return E_INVALIDARG;

	PmeHComponent hComp = pCompAuto->GetHComponent();


	PmeComponentAPI::AddComponent(m_hComponent,hComp);

	return S_OK;
}

STDMETHODIMP CComponentAuto::GetSize(/*PmeHComponent hItem,*/ int* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int nSize;

	PmeComponentAPI::GetSize(m_hComponent,nSize);

	*pVal=nSize;

	return S_OK;
}

HRESULT CComponentAuto::GetICompFromHComp( PmeHComponent hComp, IComp** ppVal )
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hComp == 0)
		return S_OK;

	CComObject<CComponentAuto> * pComp = NULL;
	hr = CComObject<CComponentAuto>::CreateInstance(&pComp);
	if(FAILED(hr))
		return hr;

	pComp->Initialize(hComp);

	hr = pComp->QueryInterface(__uuidof(IComp), (void **)ppVal);

	return hr;
}

HRESULT CComponentAuto::GetIPartFromHPart(PmeHPart hPart, IPart** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CPartAuto> * pPart = NULL;
	hr = CComObject<CPartAuto>::CreateInstance(&pPart);
	if(FAILED(hr))
		return hr;

	pPart->Initialize(hPart);

	hr = pPart->QueryInterface(__uuidof(IPart), (void **)ppVal);

	return hr;
}

STDMETHODIMP CComponentAuto::SaveAsMesh(int i, BSTR name)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);
	
	PmeComponentAPI::SaveAsMesh(m_hComponent,i,strName);

	return S_OK;
}

STDMETHODIMP CComponentAuto::CreatePart( BSTR name, IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHPart hPart;
	CString strName( name );

	PmePartAPI::Create( hPart );
	PmePartAPI::SetName( hPart, strName );

	HRESULT hr = GetIPartFromHPart( hPart, ppVal );

	return hr;
}

STDMETHODIMP CComponentAuto::ImportPartFromXML( BSTR path, IPart* pVal, IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	CString strPath( path );

	CPartAuto * pPartAuto = static_cast<CPartAuto *>(pVal);
	if(!pPartAuto)
		return E_INVALIDARG;

	PmeHPart hPart = pPartAuto->GetHPart();
	
	PmePartAPI::LoadXmlMacro( strPath, hPart );

	HRESULT hr = GetIPartFromHPart( hPart, ppVal );

	return hr;
}

STDMETHODIMP CComponentAuto::SetPartPlacement( IPart* pVal, double ox, double oy, double oz, double zx, double zy, double zz, double xx, double xy, double xz )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	MrAxis2 placement( MrPosition( ox, oy, oz), MrDirection( zx, zy, zz), MrDirection(xx,xy,xz) );

	CPartAuto * pPartAuto = static_cast<CPartAuto *>(pVal);
	if(!pPartAuto)
		return E_INVALIDARG;

	PmeHPart hPart = pPartAuto->GetHPart();

	PmePartAPI::SetPlacement( hPart, placement );

	return S_OK;
}