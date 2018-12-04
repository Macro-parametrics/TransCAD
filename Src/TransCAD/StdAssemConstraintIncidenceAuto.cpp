// StdAssemConstraintIncidenceAuto.cpp : CStdAssemConstraintIncidenceAuto의 구현입니다.

#include "stdafx.h"
#include "StdAssemConstraintIncidenceAuto.h"
#include ".\AssemAuto.h"
#include ".\PmeStdAssemblyIncidenceAPI.h"

// CStdAssemConstraintIncidenceAuto

STDMETHODIMP CStdAssemConstraintIncidenceAuto::get_ConstrainedPart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyIncidenceAPI::GetConstrainedPart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintIncidenceAuto::get_ConstrainedGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyIncidenceAPI::GetConstrainedGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}

STDMETHODIMP CStdAssemConstraintIncidenceAuto::get_ReferencePart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyIncidenceAPI::GetReferencePart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintIncidenceAuto::get_ReferenceGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyIncidenceAPI::GetReferenceGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}