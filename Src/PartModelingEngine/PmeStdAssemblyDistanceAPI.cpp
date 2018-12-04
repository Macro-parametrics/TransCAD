#include "stdafx.h"
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

#include ".\PmeStdAssemblyDistanceAPI.h"
#include ".\PmeStdAssemblyDistance.h"

bool PmeStdAssemblyDistanceAPI::ApplyDistance(PmeHAssembly hAssembly, 
												const CString & name,					
												PmeHPart & hConstrainedPart, 
												PmeHReference & hConstrainedGeometry, 
												PmeHPart & hReferencePart, 
												PmeHReference & hReferenceGeometry,
												double distance,
												PmeStdAssemblyIncidenceType incidenceType,
												PmeHStdAssemblyConstraint & hConstraint)
{
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmePart * pConstrainedPart = PME_HANDLE2PART(hConstrainedPart);
	PmeReference * pConstrainedGeometry = PME_HANDLE2REFERENCE(hConstrainedGeometry);
	PmePart * pReferencePart = PME_HANDLE2PART(hReferencePart);
	PmeReference * pReferenceGeometry = PME_HANDLE2REFERENCE(hReferenceGeometry);
	
	if ( isSupportGeometry(pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry) )
	{
		PmeStdAssemblyDistance * pDistance = new PmeStdAssemblyDistance(pAssembly, pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry, distance, incidenceType);
	
		pDistance->UpdateConstraint();
		pDistance->SetName(name);

		pAssembly->AddConstraint( pDistance );

		hConstraint = PME_STDASSEMBLYCONSTRAINT2HANDLE( pDistance );
		if ( hConstraint )
		{
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}

		/*hConstrainedPart = PME_PART2HANDLE(pConstrainedPart);

		if(hConstrainedPart)
		{
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}

		return true;*/
	}

	else return false;
}

/**
 * 17-03-22 Added by YK
 * Check geometries prior to do distance constraint
 * if selected geometry(ies) is(are) circular edge, return false
 * @param pConstrainedPart
 * 
 * @param pConstrainedGeometry
 *
 * @param pReferencePart
 *
 * @param pReferenceGeometry
 *
**/
bool PmeStdAssemblyDistanceAPI::isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry)
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

bool PmeStdAssemblyDistanceAPI::isLinearEdge(EDGE * pEdge)
{
	CURVE * pCurve = pEdge->geometry();
	const curve & curveEquation = pCurve->equation();
	
	// linear is 0 and circular is 1
	int periodic = curveEquation.periodic();
	
	return ( periodic == 0 ) ? true : false;
}

void PmeStdAssemblyDistanceAPI::GetConstrainedPart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hConstrainedPart )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyDistance )));
	PmeStdAssemblyDistance * pDistance = static_cast<PmeStdAssemblyDistance *>( pConstraint );

	PmePart * pPart = pDistance->GetConstrainedPart();
	hConstrainedPart = PME_PART2HANDLE( pPart );
}

void PmeStdAssemblyDistanceAPI::GetReferencePart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hReferencePart )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyDistance )));
	PmeStdAssemblyDistance * pDistance = static_cast<PmeStdAssemblyDistance *>( pConstraint );

	PmePart * pPart = pDistance->GetReferencePart();
	hReferencePart = PME_PART2HANDLE( pPart );
}

void PmeStdAssemblyDistanceAPI::GetConstrainedGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hConstrainedGeometry )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyDistance )));
	PmeStdAssemblyDistance * pDistance = static_cast<PmeStdAssemblyDistance *>( pConstraint );

	PmeReference * pReference = pDistance->GetConstrainedGeometry();
	hConstrainedGeometry = PME_REFERENCE2HANDLE( pReference );
}

void PmeStdAssemblyDistanceAPI::GetReferenceGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hReferenceGeometry )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyDistance )));
	PmeStdAssemblyDistance * pDistance = static_cast<PmeStdAssemblyDistance *>( pConstraint );

	PmeReference * pReference = pDistance->GetReferenceGeometry();
	hReferenceGeometry = PME_REFERENCE2HANDLE( pReference );
}