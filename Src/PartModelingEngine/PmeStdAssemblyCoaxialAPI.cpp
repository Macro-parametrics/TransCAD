#include "stdafx.h"
#include ".\PmeStdAssemblyCoaxialAPI.h"
#include ".\PmeStdAssemblyCoaxial.h"
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

void PmeStdAssemblyCoaxialAPI::ApplyCoaxial
	(
		PmeHAssembly hAssembly, 
		const CString & name, 
		PmeHPart & hConstrainedPart, 
		PmeHReference & hConstrainedGeometry, 
		PmeHPart & hReferencePart, 
		PmeHReference & hReferenceGeometry,
		PmeHStdAssemblyConstraint & hConstraint )
{
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmePart * pConstrainedPart = PME_HANDLE2PART(hConstrainedPart);
	PmeReference * pConstrainedGeometry = PME_HANDLE2REFERENCE(hConstrainedGeometry);
	PmePart * pReferencePart = PME_HANDLE2PART(hReferencePart);
	PmeReference * pReferenceGeometry = PME_HANDLE2REFERENCE(hReferenceGeometry);
	
	//PmeStdAssemblyConstraints * pConstraints = pAssembly->GetConstraints();

	if ( isSupportGeometry(pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry) )
	{
		PmeStdAssemblyCoaxial * pCoaxial = new PmeStdAssemblyCoaxial(pAssembly, pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry);
	
		pCoaxial->UpdateConstraint();
		pCoaxial->SetName(name);
		
		//pConstraints->Add( pCoaxial );
		pAssembly->AddConstraint(pCoaxial);

		hConstraint = PME_STDASSEMBLYCONSTRAINT2HANDLE( pCoaxial );
		if ( hConstraint )
		{
			//PME_UPDATE_CONSTRAINT( hAssembly, hConstraint, PmeUpdateState_Update );
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}

		/*hConstrainedPart = PME_PART2HANDLE(pConstrainedPart);

		if(hConstrainedPart)
		{
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}*/

		//return true;
	}
	//else return false;
}

/**
 * 17-03-21 Added by YK
 * Check geometries prior to do coaxial constraint
 * Coaxial constraint support cylinderical face and circular edge
 * @param pConstrainedPart
 * 
 * @param pConstrainedGeometry
 *
 * @param pReferencePart
 *
 * @param pReferenceGeometry
 *
**/
bool PmeStdAssemblyCoaxialAPI::isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry)
{
	ENTITY * pCoEntity = pConstrainedPart->GetSelectionManager()->GetBrepFromReference(pConstrainedGeometry);
	ENTITY * pRefEntity = pReferencePart->GetSelectionManager()->GetBrepFromReference(pReferenceGeometry);

	const char * facetype = "face";
	const char * edgetype = "edge";

	// Check constrained geometry
	if (*pCoEntity->type_name() == *facetype )
	{
		if ( !isCylindericalFace((FACE *)pCoEntity) )
		{
			AfxMessageBox(TEXT("Constrained geometry error :\nTransCAD coaxial constraint does not support planar face.\n\nPlease select a cylinderical face."));

			return false;
		}
	}

	else if ( *pCoEntity->type_name() == *edgetype )
	{
		if ( !isCircularEdge((EDGE *)pCoEntity) )
		{
			AfxMessageBox(TEXT("Constrained geometry error : \nTransCAD coaxial constraint does not support linear edge.\n\nPlease select a circular edge."));

			return false;
		}
	}

	// Check reference geometry
	if ( *pRefEntity->type_name() == *facetype )
	{
		if ( !isCylindericalFace((FACE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Reference geometry error : \nTransCAD coaxial constraint does not support planar face.\n\nPlease select a cylinderical face."));

			return false;
		}
	}

	else if ( *pRefEntity->type_name() == *edgetype )
	{
		if ( !isCircularEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Reference geometry error : \nTransCAD coaxial constraint does not support linear edge.\n\nPlease select a circular edge."));

			return false;
		}
	}

	return true;
}

bool PmeStdAssemblyCoaxialAPI::isCircularEdge(EDGE * pEdge)
{
	CURVE * pCurve = pEdge->geometry();
	const curve & curveEquation = pCurve->equation();
	
	// linear is 0 and circular is 1
	int periodic = curveEquation.periodic();
	
	return ( periodic == 1 ) ? true : false;
}

bool PmeStdAssemblyCoaxialAPI::isCylindericalFace(FACE * pFace)
{
	SURFACE * pSurface = pFace->geometry();
	const surface & surfaceEquation = pSurface->equation();
	int isPlanar = surfaceEquation.planar(SPAposition(0.0,0.0,0.0), SPAunit_vector(0.0, 0.0, 1.0));

	return ( isPlanar == 0) ? true : false;
}

void PmeStdAssemblyCoaxialAPI::GetConstrainedPart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hConstrainedPart )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyCoaxial )));
	PmeStdAssemblyCoaxial * pCoaxial = static_cast<PmeStdAssemblyCoaxial *>( pConstraint );

	PmePart * pPart = pCoaxial->GetConstrainedPart();
	hConstrainedPart = PME_PART2HANDLE( pPart );
}

void PmeStdAssemblyCoaxialAPI::GetReferencePart( PmeHStdAssemblyConstraint hConstraint, PmeHPart & hReferencePart )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyCoaxial )));
	PmeStdAssemblyCoaxial * pCoaxial = static_cast<PmeStdAssemblyCoaxial *>( pConstraint );

	PmePart * pPart = pCoaxial->GetReferencePart();
	hReferencePart = PME_PART2HANDLE( pPart );
}

void PmeStdAssemblyCoaxialAPI::GetConstrainedGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hConstrainedGeometry )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyCoaxial )));
	PmeStdAssemblyCoaxial * pCoaxial = static_cast<PmeStdAssemblyCoaxial *>( pConstraint );

	PmeReference * pReference = pCoaxial->GetConstrainedGeometry();
	hConstrainedGeometry = PME_REFERENCE2HANDLE( pReference );
}

void PmeStdAssemblyCoaxialAPI::GetReferenceGeometry( PmeHStdAssemblyConstraint hConstraint, PmeHReference & hReferenceGeometry )
{
	PmeThrowExceptionIf< PmeArgumentNullException >(!hConstraint);
	PmeStdAssemblyConstraint * pConstraint = PME_HANDLE2STDASSEMBLYCONSTRAINT( hConstraint );
	PmeThrowExceptionIf<PmeArgumentTypeException>(!pConstraint->IsInstanceOf(PME_RUNTIME_TYPE( PmeStdAssemblyCoaxial )));
	PmeStdAssemblyCoaxial * pCoaxial = static_cast<PmeStdAssemblyCoaxial *>( pConstraint );

	PmeReference * pReference = pCoaxial->GetReferenceGeometry();
	hReferenceGeometry = PME_REFERENCE2HANDLE( pReference );
}