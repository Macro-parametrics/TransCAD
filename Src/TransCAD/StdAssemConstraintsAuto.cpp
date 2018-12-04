// StdAssemConstraintsAuto.cpp : CStdAssemConstraintsAuto의 구현입니다.

#include "stdafx.h"
#include "StdAssemConstraintsAuto.h"
#include ".\PartAuto.h"
#include ".\ReferenceAuto.h"

#include ".\StdAssemConstraintCoaxialAuto.h"
#include ".\PmeStdAssemblyCoaxialAPI.h"
#include ".\StdAssemConstraintIncidenceAuto.h"
#include ".\PmeStdAssemblyIncidenceAPI.h"
#include ".\StdAssemConstraintDistanceAuto.h"
#include ".\PmeStdAssemblyDistanceAPI.h"
#include ".\StdAssemConstraintAngleAuto.h"
#include ".\PmeStdAssemblyAngleAPI.h"

#define BEGIN_CONSTRAINT_HCONSTRAINT_MAP( hconstraint ) \
	PmeStdAssemblyConstraintType type; \
	PmeStdAssemblyConstraintAPI::GetType( hconstraint, type );\
	HRESULT hr = E_FAIL; \
	PmeHStdAssemblyConstraint hInnerHStdAssemConstraint = hconstraint; \
	switch(type) {

#define END_CONSTRAINT_HCONSTRAINT_MAP() }return hr;

#define CONSTRAINT_HCONSTRAINT_MAP( type, iconstraint ) \
	case PmeStdAssemblyConstraintType_##type: { \
			CComObject<CStdAssemConstraint##type##Auto> * pObj = NULL; \
			hr = CComObject<CStdAssemConstraint##type##Auto>::CreateInstance(&pObj); \
			if(FAILED(hr)) return hr; \
			pObj->InitializeDispatchImplEx(m_pApplication, this); \
            pObj->Initialize( hInnerHStdAssemConstraint ); \
			hr = pObj->QueryInterface(__uuidof(IStdAssemConstraint##type), (void **) iconstraint); \
		} break;

// CStdAssemConstraintsAuto

void CStdAssemConstraintsAuto::Initialize( PmeHAssembly hAssembly )
{
	m_hAssembly = hAssembly;
}

STDMETHODIMP CStdAssemConstraintsAuto::get_Count( long* pVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHStdAssemblyConstraints hStdAssmblyConstraints;
	PmeAssemblyAPI::GetConstraints( m_hAssembly, hStdAssmblyConstraints );

	int size;
	PmeStdAssemblyConstraintsAPI::GetSize( hStdAssmblyConstraints, size );

	*pVal = (long)size;

	return S_OK;
}

STDMETHODIMP CStdAssemConstraintsAuto::get_Constraint( long index, IStdAssemConstraint** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHStdAssemblyConstraints hStdAssemblyConstraints;
	PmeAssemblyAPI::GetConstraints( m_hAssembly, hStdAssemblyConstraints );

	PmeHStdAssemblyConstraint hStdAssemblyConstraint;
	PmeStdAssemblyConstraintsAPI::GetItem( hStdAssemblyConstraints, (int)index - 1, hStdAssemblyConstraint );

	HRESULT hr = GetIStdAssemConstraintFromHStdAssemConstraint( hStdAssemblyConstraint, ppVal );

	return hr;
}

STDMETHODIMP CStdAssemConstraintsAuto::SelectConstraintByName(BSTR name, IStdAssemConstraint** ppVal)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	CString strName(name);
	PmeHStdAssemblyConstraints hStdAssemblyConstraints;
	PmeAssemblyAPI::GetConstraints(m_hAssembly, hStdAssemblyConstraints);

	PmeHStdAssemblyConstraint hStdAssemblyConstraint;

	PmeStdAssemblyConstraintsAPI::FindByName(hStdAssemblyConstraints, strName, hStdAssemblyConstraint);
	
	HRESULT hr = GetIStdAssemConstraintFromHStdAssemConstraint(hStdAssemblyConstraint, ppVal);

	return hr;
}

STDMETHODIMP CStdAssemConstraintsAuto::get__NewEnum(IUnknown** ppUnk)
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	HRESULT hr;

	PmeHStdAssemblyConstraints hStdAssemblyConstraints;
	PmeAssemblyAPI::GetConstraints( m_hAssembly, hStdAssemblyConstraints );

	int size;
	PmeStdAssemblyConstraintsAPI::GetSize( hStdAssemblyConstraints, size );

	*ppUnk = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > EnumVar;
	EnumVar * pEnumObject = NULL;
	hr = EnumVar::CreateInstance(&pEnumObject);
	if(FAILED(hr))
		return hr;

	CComVariant * pVarVect = new CComVariant[size];
	
	for(int i = 0; i < size; ++ i)
	{
		PmeHStdAssemblyConstraint hStdAssemblyConstraint;
		PmeStdAssemblyConstraintsAPI::GetItem( hStdAssemblyConstraints, i, hStdAssemblyConstraint );

		IStdAssemConstraint * pConstraint = NULL;
		
		hr = GetIStdAssemConstraintFromHStdAssemConstraint( hStdAssemblyConstraint, &pConstraint );
		if(FAILED(hr))
			return hr;

		// get IDispatch pointer
		IDispatch * pDispatch = NULL;
		hr = pConstraint->QueryInterface(IID_IDispatch, (void **)&pDispatch);
		pConstraint->Release();
		if(FAILED(hr))
			return hr;

		// create a variant and add it to the collection
		CComVariant & var = pVarVect[i];
		var.vt = VT_DISPATCH;
		var.pdispVal = pDispatch;
	}

	hr = pEnumObject->Init(&pVarVect[0], &pVarVect[size], NULL, AtlFlagCopy);
	if(FAILED(hr))
		return hr;

    hr = pEnumObject->QueryInterface(IID_IEnumVARIANT, (void **)ppUnk);
	
	delete [] pVarVect;

	return hr;
}

// Add a new constraint for pre-processor
STDMETHODIMP CStdAssemConstraintsAuto::AddNewAssemblyCoaxialConstraint( BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, IStdAssemConstraintCoaxial** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName( name );

	CPartAuto * pConstPart = static_cast<CPartAuto *>(pConstrainedPart);
	if( !pConstPart )
		return E_INVALIDARG;

	PmeHPart hConstPart = pConstPart->GetHPart();

	CReferenceAuto * pConstGeometry = static_cast<CReferenceAuto *>(pConstrainedGeometry);
	if( !pConstGeometry )
		return E_INVALIDARG;

	PmeHReference hConstGeometry = pConstGeometry->GetHReference();

	////////////////////////////////////////////////////////////////////////////////////////

	CPartAuto * pReferPart = static_cast<CPartAuto *>(pReferencePart);
	if( !pReferPart )
		return E_INVALIDARG;

	PmeHPart hReferPart = pReferPart->GetHPart();

	CReferenceAuto * pReferGeometry = static_cast<CReferenceAuto *>(pReferenceGeometry);
	if( !pReferGeometry )
		return E_INVALIDARG;

	PmeHReference hReferGeometry = pReferGeometry->GetHReference();

	PmeHStdAssemblyConstraint hConstraint = 0;
	PmeStdAssemblyCoaxialAPI::ApplyCoaxial( m_hAssembly, strName, hConstPart, hConstGeometry, hReferPart, hReferGeometry, hConstraint );
	

	CComObject<CStdAssemConstraintCoaxialAuto> * pObj = NULL;
	hr = CComObject<CStdAssemConstraintCoaxialAuto>::CreateInstance( &pObj );
	if( FAILED( hr ) )
		return hr;

	pObj->InitializeDispatchImplEx( m_pApplication, this );
	pObj->Initialize( hConstraint );

	hr = pObj->QueryInterface( __uuidof( IStdAssemConstraintCoaxial ), (void **)ppVal );

	return hr;
}

STDMETHODIMP CStdAssemConstraintsAuto::AddNewAssemblyIncidenceConstraint( BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, StdAssemblyIncidenceType incidenceType, IStdAssemConstraintIncidence** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName( name );

	CPartAuto * pConstPart = static_cast<CPartAuto *>(pConstrainedPart);
	if( !pConstPart )
		return E_INVALIDARG;

	PmeHPart hConstPart = pConstPart->GetHPart();

	CReferenceAuto * pConstGeometry = static_cast<CReferenceAuto *>(pConstrainedGeometry);
	if( !pConstGeometry )
		return E_INVALIDARG;

	PmeHReference hConstGeometry = pConstGeometry->GetHReference();

	////////////////////////////////////////////////////////////////////////////////////////

	CPartAuto * pReferPart = static_cast<CPartAuto *>(pReferencePart);
	if( !pReferPart )
		return E_INVALIDARG;

	PmeHPart hReferPart = pReferPart->GetHPart();

	CReferenceAuto * pReferGeometry = static_cast<CReferenceAuto *>(pReferenceGeometry);
	if( !pReferGeometry )
		return E_INVALIDARG;

	PmeHReference hReferGeometry = pReferGeometry->GetHReference();

	PmeHStdAssemblyConstraint hConstraint = 0;
	PmeStdAssemblyIncidenceAPI::ApplyIncidence( m_hAssembly, strName, hConstPart, hConstGeometry, hReferPart, hReferGeometry, (PmeStdAssemblyIncidenceType)incidenceType, hConstraint );
	

	CComObject<CStdAssemConstraintIncidenceAuto> * pObj = NULL;
	hr = CComObject<CStdAssemConstraintIncidenceAuto>::CreateInstance( &pObj );
	if( FAILED( hr ) )
		return hr;

	pObj->InitializeDispatchImplEx( m_pApplication, this );
	pObj->Initialize( hConstraint );

	hr = pObj->QueryInterface( __uuidof( IStdAssemConstraintIncidence ), (void **)ppVal );

	return hr;
}

STDMETHODIMP CStdAssemConstraintsAuto::AddNewAssemblyDistance( BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, double distance, StdAssemblyIncidenceType incidenceType, IStdAssemConstraintDistance** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName( name );

	CPartAuto * pConstPart = static_cast<CPartAuto *>(pConstrainedPart);
	if( !pConstPart )
		return E_INVALIDARG;

	PmeHPart hConstPart = pConstPart->GetHPart();

	CReferenceAuto * pConstGeometry = static_cast<CReferenceAuto *>(pConstrainedGeometry);
	if( !pConstGeometry )
		return E_INVALIDARG;

	PmeHReference hConstGeometry = pConstGeometry->GetHReference();

	////////////////////////////////////////////////////////////////////////////////////////

	CPartAuto * pReferPart = static_cast<CPartAuto *>(pReferencePart);
	if( !pReferPart )
		return E_INVALIDARG;

	PmeHPart hReferPart = pReferPart->GetHPart();

	CReferenceAuto * pReferGeometry = static_cast<CReferenceAuto *>(pReferenceGeometry);
	if( !pReferGeometry )
		return E_INVALIDARG;

	PmeHReference hReferGeometry = pReferGeometry->GetHReference();

	PmeHStdAssemblyConstraint hConstraint = 0;
	PmeStdAssemblyDistanceAPI::ApplyDistance( m_hAssembly, strName, hConstPart, hConstGeometry, hReferPart, hReferGeometry, distance, (PmeStdAssemblyIncidenceType)incidenceType, hConstraint );

	/*CComObject<CStdAssemConstraintIncidenceAuto> * pObj = NULL;
	hr = CComObject<CStdAssemConstraintIncidenceAuto>::CreateInstance( &pObj );*/
	CComObject<CStdAssemConstraintDistanceAuto> * pObj = NULL;
	hr = CComObject<CStdAssemConstraintDistanceAuto>::CreateInstance( &pObj );
	if( FAILED( hr ) )
	return hr;

	pObj->InitializeDispatchImplEx( m_pApplication, this );
	pObj->Initialize( hConstraint );

	hr = pObj->QueryInterface( __uuidof( IStdAssemConstraintDistance ), (void **)ppVal );

	return hr;
}

STDMETHODIMP CStdAssemConstraintsAuto::AddNewAssemblyAngle( BSTR name, IPart* pConstrainedPart, IReference* pConstrainedGeometry, IPart* pReferencePart, IReference* pReferenceGeometry, double angle, IStdAssemConstraintAngle** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	HRESULT hr = S_OK;
	*ppVal = NULL;

	CString strName( name );

	CPartAuto * pConstPart = static_cast<CPartAuto *>(pConstrainedPart);
	if( !pConstPart )
		return E_INVALIDARG;

	PmeHPart hConstPart = pConstPart->GetHPart();

	CReferenceAuto * pConstGeometry = static_cast<CReferenceAuto *>(pConstrainedGeometry);
	if( !pConstGeometry )
		return E_INVALIDARG;

	PmeHReference hConstGeometry = pConstGeometry->GetHReference();

	////////////////////////////////////////////////////////////////////////////////////////

	CPartAuto * pReferPart = static_cast<CPartAuto *>(pReferencePart);
	if( !pReferPart )
		return E_INVALIDARG;

	PmeHPart hReferPart = pReferPart->GetHPart();

	CReferenceAuto * pReferGeometry = static_cast<CReferenceAuto *>(pReferenceGeometry);
	if( !pReferGeometry )
		return E_INVALIDARG;

	PmeHReference hReferGeometry = pReferGeometry->GetHReference();

	PmeHStdAssemblyConstraint hConstraint = 0;
	PmeStdAssemblyAngleAPI::ApplyAngle( m_hAssembly, strName, hConstPart, hConstGeometry, hReferPart, hReferGeometry, angle, hConstraint );

	/*CComObject<CStdAssemConstraintIncidenceAuto> * pObj = NULL;
	hr = CComObject<CStdAssemConstraintIncidenceAuto>::CreateInstance( &pObj );*/
	CComObject<CStdAssemConstraintAngleAuto> * pObj = NULL;
	hr = CComObject<CStdAssemConstraintAngleAuto>::CreateInstance( &pObj );
	if( FAILED( hr ) )
	return hr;

	pObj->InitializeDispatchImplEx( m_pApplication, this );
	pObj->Initialize( hConstraint );

	hr = pObj->QueryInterface( __uuidof( IStdAssemConstraintDistance ), (void **)ppVal );

	return hr;
}

HRESULT CStdAssemConstraintsAuto::GetIStdAssemConstraintFromHStdAssemConstraint( PmeHStdAssemblyConstraint hconstraint, IStdAssemConstraint **ppVal )
{
	BEGIN_CONSTRAINT_HCONSTRAINT_MAP( hconstraint )
		CONSTRAINT_HCONSTRAINT_MAP( Coaxial, ppVal )
		CONSTRAINT_HCONSTRAINT_MAP( Incidence, ppVal )
		CONSTRAINT_HCONSTRAINT_MAP( Distance, ppVal )
		CONSTRAINT_HCONSTRAINT_MAP( Angle, ppVal )
	END_CONSTRAINT_HCONSTRAINT_MAP()
}