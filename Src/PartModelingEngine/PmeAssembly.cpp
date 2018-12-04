#include "StdAfx.h"
#include <algorithm>
#include "PmeAssembly.h"
#include "PmePart.h"
#include "PmeComponent.h"
#include "PmeAssemblyComponentType.h"
#include "PmeStdAssemblyConstraints.h"

PME_IMPLEMENT_RUNTIME_TYPE( PmeAssembly, PmeObject )

PmeAssembly::PmeAssembly(void)
{
	PmePart * pPart = new PmePart();

	pPart->SetName( "Default Datum planes" );

	PmeComponent * pComp = new PmeComponent();

	pComp->SetName( "Default SubAssembly") ;

	pComp->AddPart( pPart );

	pComp->SetCompType( PmeAssemblyComponentType_Component );

	AddComponent( pComp );

	//m_pConstraints = new PmeStdAssemblyConstraints();

	SetName(_T("Assembly"));
}

void ReleaseComponent( PmeComponent * pComponent )
{
	if( pComponent )
	{
		delete pComponent;
		pComponent = 0;
	}
}

PmeAssembly::~PmeAssembly(void)
{
	// Components는 BaseList으로 정의 됨
	// vector타입인 BaseList의 clear() 함수를 이용하여 정리
	m_components.clear();

	// m_pConstraints는 class로 정의, 생성자에서 new로 정의 됨
	// 따라서, delete를 이용하여 정리
	ASSERT(m_pConstraints);
	delete m_pConstraints;
}


void PmeAssembly::AddComponent( PmeComponent * pComponent )
{
	m_components.push_back( pComponent );
}

void PmeAssembly::AddConstraint( PmeStdAssemblyConstraint * pConstraint )
{
	m_constraints.push_back( pConstraint );
}

void PmeAssembly::UpdateAll(void)
{
	for each( PmeComponent * pComp in m_components )
	{
		
		pComp->UpdateAll();
	}
}