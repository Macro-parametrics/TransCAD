// StdAssemConstraintCoaxialAuto.cpp : CStdAssemConstraintCoaxialAuto의 구현입니다.

#include "stdafx.h"
#include "StdAssemConstraintCoaxialAuto.h"
#include ".\AssemAuto.h"
#include ".\PmeStdAssemblyCoaxialAPI.h"


// CStdAssemConstraintCoaxialAuto

STDMETHODIMP CStdAssemConstraintCoaxialAuto::get_ConstrainedPart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyCoaxialAPI::GetConstrainedPart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintCoaxialAuto::get_ConstrainedGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyCoaxialAPI::GetConstrainedGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}

STDMETHODIMP CStdAssemConstraintCoaxialAuto::get_ReferencePart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyCoaxialAPI::GetReferencePart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintCoaxialAuto::get_ReferenceGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyCoaxialAPI::GetReferenceGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}