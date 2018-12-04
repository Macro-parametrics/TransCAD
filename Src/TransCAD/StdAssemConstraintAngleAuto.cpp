// StdAssemConstraintAngleAuto.cpp : CStdAssemConstraintAngleAuto의 구현입니다.

#include "stdafx.h"
#include "StdAssemConstraintAngleAuto.h"
#include ".\AssemAuto.h"
#include ".\PmeStdAssemblyAngleAPI.h"


// CStdAssemConstraintAngleAuto
STDMETHODIMP CStdAssemConstraintAngleAuto::get_ConstrainedPart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyAngleAPI::GetConstrainedPart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintAngleAuto::get_ConstrainedGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyAngleAPI::GetConstrainedGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}

STDMETHODIMP CStdAssemConstraintAngleAuto::get_ReferencePart( IPart** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );
	
	PmeHPart hPart;
	PmeStdAssemblyAngleAPI::GetReferencePart( m_hStdAssemConstraint, hPart );

	return CAssemAuto::GetIPartFromHPart( hPart, ppVal );
}

STDMETHODIMP CStdAssemConstraintAngleAuto::get_ReferenceGeometry( IReference** ppVal )
{
	AFX_MANAGE_STATE( AfxGetAppModuleState() );

	PmeHReference hReference;
	PmeStdAssemblyAngleAPI::GetReferenceGeometry( m_hStdAssemConstraint, hReference );

	return CAssemAuto::GetIReferenceFromHReference( hReference, ppVal );
}
