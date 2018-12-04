// StdAssemConstraintDistanceAuto.cpp : CStdAssemConstraintDistanceAuto의 구현입니다.

#include "stdafx.h"
#include "StdAssemConstraintDistanceAuto.h"
#include ".\AssemAuto.h"
#include ".\PmeStdAssemblyDistanceAPI.h"

// CStdAssemConstraintDistanceAuto
STDMETHODIMP CStdAssemConstraintDistanceAuto::get_ConstrainedPart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyDistanceAPI::GetConstrainedPart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintDistanceAuto::get_ConstrainedGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyDistanceAPI::GetConstrainedGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}

STDMETHODIMP CStdAssemConstraintDistanceAuto::get_ReferencePart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyDistanceAPI::GetReferencePart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintDistanceAuto::get_ReferenceGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyDistanceAPI::GetReferenceGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}