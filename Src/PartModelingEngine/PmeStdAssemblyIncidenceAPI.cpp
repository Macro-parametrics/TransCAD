#include "stdafx.h"
#include ".\PmeStdAssemblyIncidenceAPI.h"
#include ".\PmeStdAssemblyIncidence.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeArgumentNullException.h"
#include ".\PmeHandleMacro.h"
#include "PmeAssembly.h"
#include "PmeComponent.h"
#include "PmePart.h"
#include ".\PmeUpdateInfoAPI.h"
#include "PmeUtility.h"
#include "PmeAssemblyAPI.h"
#include ".\PmeQuery.h"
#include ".\PmeSelectionManager.h"
#include "MrTransformation.h"
#include ".\PmeStdAssemblyConstraints.h"

void PmeStdAssemblyIncidenceAPI::ApplyIncidence
	(
		PmeHAssembly hAssembly,
		const CString & name,
		PmeHPart & hConstrainedPart,
		PmeHReference & hConstrainedGeometry,
		PmeHPart & hReferencePart,
		PmeHReference & hReferenceGeometry,
		PmeStdAssemblyIncidenceType hIncidenceType,
		PmeHStdAssemblyConstraint & hConstraint)
{
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmePart * pConstrainedPart = PME_HANDLE2PART(hConstrainedPart);
	PmeReference * pConstrainedGeometry = PME_HANDLE2REFERENCE(hConstrainedGeometry);
	PmePart * pReferencePart = PME_HANDLE2PART(hReferencePart);
	PmeReference * pReferenceGeometry = PME_HANDLE2REFERENCE(hReferenceGeometry);
	
	//PmeStdAssemblyConstraints * pConstraints = pAssembly->GetConstraints();

	if ( isSupportGeometry( pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry ) )
	{
		PmeStdAssemblyIncidence * pIncidence = new PmeStdAssemblyIncidence( pAssembly, pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry, hIncidenceType );
	
		pIncidence->UpdateConstraint();
		pIncidence->SetName(name);

		//pConstraints->Add( pIncidence );
		pAssembly->AddConstraint( pIncidence );

		hConstraint = PME_STDASSEMBLYCONSTRAINT2HANDLE( pIncidence );
		if ( hConstraint )
		{
			//PME_UPDATE_CONSTRAINT( hAssembly, hConstraint, PmeUpdateState_Update );
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}


		/*hConstrainedPart = PME_PART2HANDLE(pConstrainedPart);

		if(hConstrainedPart)
		{
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}

		return true;*/
	}

	//else return false;
	
}

bool PmeStdAssemblyIncidenceAPI::isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry)
{
	ENTITY * pCoEntity = pConstrainedPart->GetSelectionManager()->GetBrepFromReference(pConstrainedGeometry);
	ENTITY * pRefEntity = pReferencePart->GetSelectionManager()->GetBrepFromReference(pReferenceGeometry);
	
	const char * edgetype = "edge";

	// Check constrained and reference geometry
	// Angle constraint support face(planar, cylinderical) and "linear" edge
	if ( *pCoEntity->type_name() == *edgetype && *pRefEntity->type_name() == *edgetype )
	{
		if ( !isLinearEdge((EDGE *)pCoEntity) && !isLinearEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Constrained and reference geometry error : \nTransCAD distance constraint does not support a circular edge"));

			return false;
		}
		
		else if ( !isLinearEdge((EDGE *)pCoEntity) )
		{
			AfxMessageBox(TEXT("Constrained geometry error : \nTransCAD distance constraint does not support a circular edge"));

			return false;
		}

		else if ( !isLinearEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Reference geometry error : \nTransCAD distance constraint does not support a circular edge"));

			return false;
		}
	}

	else if ( *pCoEntity->type_name() == *edgetype )
	{
		if ( !isLinearEdge((EDGE *)pCoEntity) )
		{
			AfxMessageBox(TEXT("Constrained geometry error : \nTransCAD distance constraint does not support a circular edge"));

			return false;
		}
	}

	else if ( *pRefEntity->type_name() == *edgetype )
	{
		if ( !isLinearEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Reference geometry error : \nTransCAD distance constraint does not support a circular edge"));

			return false;
		}
	}


	else return true;
}

bool PmeStdAssemblyIncidenceAPI::isLinearEdge(EDGE * pEdge)
{
	CURVE * pCurve = pEdge->geometry();
	const curve & curveEquation = pCurve->equation();
	
	// linear is 0 and circular is 1
	int periodic = curveEquation.periodic();
	
	return ( periodic == 0 ) ? true : false;
}

void PmeStdAssemblyIncidenceAPI::GetConstrainedPart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hConstrainedPart )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyIncidence )));
	PmeStdAssemblyIncidence * pIncidence = static_cast<PmeStdAssemblyIncidence *>( pConstraint );

	PmePart * pPart = pIncidence->GetConstrainedPart();
	hConstrainedPart = PME_PART2HANDLE( pPart );
}

void PmeStdAssemblyIncidenceAPI::GetReferencePart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hReferencePart )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyIncidence )));
	PmeStdAssemblyIncidence * pIncidence = static_cast<PmeStdAssemblyIncidence *>( pConstraint );

	PmePart * pPart = pIncidence->GetReferencePart();
	hReferencePart = PME_PART2HANDLE( pPart );
}

void PmeStdAssemblyIncidenceAPI::GetConstrainedGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hConstrainedGeometry )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyIncidence )));
	PmeStdAssemblyIncidence * pIncidence = static_cast<PmeStdAssemblyIncidence *>( pConstraint );

	PmeReference * pReference = pIncidence->GetConstrainedGeometry();
	hConstrainedGeometry = PME_REFERENCE2HANDLE( pReference );
}

void PmeStdAssemblyIncidenceAPI::GetReferenceGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hReferenceGeometry )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyIncidence )));
	PmeStdAssemblyIncidence * pIncidence = static_cast<PmeStdAssemblyIncidence *>( pConstraint );

	PmeReference * pReference = pIncidence->GetReferenceGeometry();
	hReferenceGeometry = PME_REFERENCE2HANDLE( pReference );
}