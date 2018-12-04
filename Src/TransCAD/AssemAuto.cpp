// AssemAuto.cpp : CAssemAuto의 구현입니다.

#include "stdafx.h"
#include "AssemAuto.h"
#include "PartAuto.h"
#include "ComponentAuto.h"
#include ".\ReferenceAuto.h"
#include "StdAssemConstraintsAuto.h"

// CAssemAuto

void CAssemAuto::Initialize(PmeHAssembly hAssem)
{
	m_hAssem = hAssem;
}

STDMETHODIMP CAssemAuto::get_Name(BSTR* pVal)
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	CString name;

	PmeAssemblyAPI::GetName( m_hAssem, name );

	*pVal = name.AllocSysString();

	return S_OK;
}

STDMETHODIMP CAssemAuto::get_Constraints( IStdAssemConstraints** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CStdAssemConstraintsAuto> * pConstraints = NULL;
	hr = CComObject<CStdAssemConstraintsAuto>::CreateInstance( &pConstraints );
	if( FAILED( hr ) )
		return hr;

	pConstraints->InitializeDispatchImplEx( m_pApplication, this );
	pConstraints->Initialize( m_hAssem );

	hr = pConstraints->QueryInterface( __uuidof( IStdAssemConstraints ), (void **)ppVal );
	if( FAILED( hr ) )
		return hr;

	return hr;
}

STDMETHODIMP CAssemAuto::CreatePart(IPart** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHPart hPart =0;

	PmePartAPI::Create(hPart);

	HRESULT hr;
	*ppVal = NULL;

	CComObject<CPartAuto> * pPart = NULL;
	
	hr = CComObject<CPartAuto>::CreateInstance(&pPart);
	
	if(FAILED(hr))
		return hr;

	pPart->InitializeDispatchImplEx(m_pApplication,this); 

	pPart->Initialize(hPart);
	
	hr = pPart->QueryInterface(__uuidof(IPart), (void **)ppVal);
	
	return hr;
}

STDMETHODIMP CAssemAuto::CreateComponent(IComp** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

 	PmeHComponent hComp =0;
 	PmeComponentAPI::Create(hComp);

 	HRESULT hr;
 	*ppVal = NULL;
 
 	CComObject<CComponentAuto> * pComp = NULL;

	hr = CComObject<CComponentAuto>::CreateInstance(&pComp);
 
 	if(FAILED(hr))
 		return hr;
 
	pComp->InitializeDispatchImplEx(m_pApplication,this); 
 
 	pComp->Initialize(hComp);
 
 	hr = pComp->QueryInterface(__uuidof(IComp), (void **)ppVal);
 
 	return hr;
}

//STDMETHODIMP CAssemAuto::AddBooleanPart(BSTR pVal, IPart* pTool,IPart* pBlank)
//{
//	AFX_MANAGE_STATE(AfxGetAppModuleState());
//
//	CPartAuto * pToolAuto = static_cast<CPartAuto *>(pTool);
//	if(!pToolAuto)
//		return E_INVALIDARG;
//
//	CPartAuto * pBlankAuto = static_cast<CPartAuto *>(pBlank);
//	if(!pToolAuto)
//		return E_INVALIDARG;
//
//
//	PmeHPart hTool = pToolAuto->GetHPart();
//	PmeHPart hBlank = pBlankAuto->GetHPart();
//
//	PmeAssemblyBooleanAPI::Create(m_hAssem, (CString)pVal, hTool, hBlank);	
//
//	return S_OK;
//}
//
//STDMETHODIMP CAssemAuto::AddBooleanPart2(BSTR pVal, IPart* pTool, VARIANT_BOOL type)
//{
//	AFX_MANAGE_STATE(AfxGetAppModuleState());
//
//	CPartAuto * pToolAuto = static_cast<CPartAuto *>(pTool);
//	if(!pToolAuto)
//		return E_INVALIDARG;
//
//
//	PmeHPart hTool = pToolAuto->GetHPart();
//
//	PmeAssemblyBooleanAPI::Create(m_hAssem, (CString)pVal, hTool, type);	
//
//	return S_OK;
//}

STDMETHODIMP CAssemAuto::AddComponent(/*PmeHComponent& hItem,*/ IComp* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CComponentAuto * pCompAuto = static_cast<CComponentAuto *>(pVal);
	if(!pCompAuto)
		return E_INVALIDARG;

	PmeHComponent hComp = pCompAuto->GetHComponent();
	
	PmeAssemblyAPI::AddComponent(m_hAssem, hComp);

	return S_OK;
}

STDMETHODIMP CAssemAuto::GetComponent(int index, IComp** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	PmeHComponent hComp;

	PmeAssemblyAPI::GetComponent(m_hAssem,index,hComp);
	//HRESULT hr = GetICompFromHComp(hComp, ppVal);

	HRESULT hr = S_OK;

	if(hComp == 0)
		return S_OK;

	CComObject<CComponentAuto> * pComp = NULL;
	hr = CComObject<CComponentAuto>::CreateInstance(&pComp);
	if(FAILED(hr))
		return hr;

	pComp->InitializeDispatchImplEx(m_pApplication, this);
	pComp->Initialize(hComp);

	hr = pComp->QueryInterface(__uuidof(IComp), (void **)ppVal);
	
	return hr;
}



// Component의 갯수를 받아오는 함수
STDMETHODIMP CAssemAuto::GetSize(/*PmeHComponent hItem,*/ int* pVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	int nSize;

	PmeAssemblyAPI::GetSize(m_hAssem,nSize);

	*pVal=nSize;

	return S_OK;
}

HRESULT CAssemAuto::GetIPartFromHPart(PmeHPart hPart, IPart** ppVal)
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

HRESULT CAssemAuto::GetICompFromHComp( PmeHComponent hComp, IComp** ppVal )
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

HRESULT CAssemAuto::GetIReferenceFromHReference( PmeHReference hReference, IReference** ppVal )
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

HRESULT CAssemAuto::GetIStdAssemConstraintsFromHStdAssemConstraints( PmeHStdAssemblyConstraints hStdAssemConstraints, IStdAssemConstraints** ppVal )
{
	*ppVal = NULL;
	HRESULT hr = S_OK;

	if(hStdAssemConstraints == 0)
		return S_OK;
	
	CComObject<CStdAssemConstraintsAuto> * pStdAssemConstraints = NULL;
	hr = CComObject<CStdAssemConstraintsAuto>::CreateInstance(&pStdAssemConstraints);
	if(FAILED(hr))
		return hr;

	pStdAssemConstraints->Initialize( hStdAssemConstraints );

	hr = pStdAssemConstraints->QueryInterface(__uuidof(IStdAssemConstraints), (void **)ppVal);

	return hr;
}