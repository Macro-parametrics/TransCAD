#pragma once

//#include ".\stdafx.h"
#include ".\AssemAuto.h"
#include ".\StdAssemConstraintsAuto.h"

template <class T>
class IStdAssemConstraintImpl : public T
{
public:
	IStdAssemConstraintImpl( void )
		: m_hStdAssemConstraint(0)
	{
	}

	void Initialize( PmeHStdAssemblyConstraint hStdAssemCosntraint ) { m_hStdAssemConstraint = hStdAssemCosntraint; }

	// IStdAssemConstraint
	STDMETHODIMP get_Type( StdAssemblyConstraintType* pVal )
	{
		AFX_MANAGE_STATE( AfxGetAppModuleState() );
		
		PmeStdAssemblyConstraintType type;
		PmeStdAssemblyConstraintAPI::GetType( m_hStdAssemConstraint, type );

		*pVal = ConvertPmeStdAssemConstraintTypeToStdAssemConstraintType( type );

		return S_OK;
	}

	STDMETHODIMP get_Name( BSTR* pVal )
	{
		AFX_MANAGE_STATE( AfxGetAppModuleState() );

		CString name;
		PmeStdAssemblyConstraintAPI::GetName( m_hStdAssemConstraint, name );

		name.SetSysString( pVal );

		return S_OK;
	}

	STDMETHODIMP SetName( BSTR pVal )
	{
		AFX_MANAGE_STATE( AfxGetAppModuleState() );

		CString name( pVal );
		PmeStdAssemblyConstraintAPI::SetName( m_hStdAssemConstraint, name );

		return S_OK;
	}

private:
	StdAssemblyConstraintType ConvertPmeStdAssemConstraintTypeToStdAssemConstraintType( PmeStdAssemblyConstraintType type )
	{
		return (StdAssemblyConstraintType)type;
	}

public:
	PmeHStdAssemblyConstraint m_hStdAssemConstraint;
};