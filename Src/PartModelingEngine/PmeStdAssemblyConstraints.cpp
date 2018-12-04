#include "StdAfx.h"
#include ".\pmestdassemblyconstraints.h"
#include ".\PmeStdAssemblyConstraint.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdAssemblyConstraints, PmeObject)

PmeStdAssemblyConstraints::PmeStdAssemblyConstraints(void)
{
}

PmeStdAssemblyConstraints::~PmeStdAssemblyConstraints(void)
{
}

void PmeStdAssemblyConstraints::Add( PmeStdAssemblyConstraint * pConstraint )
{
	SizeType index = Find( pConstraint );

	// BaseList에 매개변수로 들어온 constraint가 없으면 -1 리턴
	if ( index == -1 )	
	{
		BaseList::Add( pConstraint );
	}

}

PmeStdAssemblyConstraint * PmeStdAssemblyConstraints::FindByName( const CString & name ) const
{
	SizeType size = GetSize();	// SizeType = int

	for( SizeType i = 0; i < size; ++ i )
	{
		PmeStdAssemblyConstraint * pConstraint = GetItem( i );
		if( pConstraint->GetName() == name )
			return pConstraint;
	}

	return 0;
}
