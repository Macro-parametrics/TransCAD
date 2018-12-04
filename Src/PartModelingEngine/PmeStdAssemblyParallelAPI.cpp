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

#include ".\PmeStdAssemblyParallelAPI.h"
#include ".\PmeStdAssemblyParallel.h"

bool PmeStdAssemblyParallelAPI::ApplyParallel(PmeHAssembly hAssembly, const CString & name, PmeHPart & hConstrainedPart, PmeHReference & hConstrainedGeometry, PmeHPart & hReferencePart, PmeHReference & hReferenceGeometry)
{
	PmeAssembly * pAssembly = PME_HANDLE2ASSEMBLY(hAssembly);
	PmePart * pConstrainedPart = PME_HANDLE2PART(hConstrainedPart);
	PmeReference * pConstrainedGeometry = PME_HANDLE2REFERENCE(hConstrainedGeometry);
	PmePart * pReferencePart = PME_HANDLE2PART(hReferencePart);
	PmeReference * pReferenceGeometry = PME_HANDLE2REFERENCE(hReferenceGeometry);
	
	if ( isSupportGeometry(pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry) )
	{
		PmeStdAssemblyParallel * pParallel = new PmeStdAssemblyParallel(pAssembly, pConstrainedPart, pConstrainedGeometry, pReferencePart, pReferenceGeometry);
	
		pParallel->UpdateConstraint();
		pParallel->SetName(name);

		hConstrainedPart = PME_PART2HANDLE(pConstrainedPart);

		if(hConstrainedPart)
		{
			PME_UPDATE_PART(hAssembly, hConstrainedPart, PmeUpdateState_Update);
		}

		return true;
	}

	else return false;
}

/**
	@brief
	Check geometries prior to apply parallel constraint\n
	
	@param pConstrainedPart			constrained part
	@param pConstrainedGeometry		selected constrained geometry
	@param pReferencePart			reference part
	@param pReferenceGeometry		selected reference geometry

	@return if selected geometry(ies) is(are) circular edge, return false
**/
bool PmeStdAssemblyParallelAPI::isSupportGeometry(PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry)
{
	ENTITY * pCoEntity = pConstrainedPart->GetSelectionManager()->GetBrepFromReference(pConstrainedGeometry);
	ENTITY * pRefEntity = pReferencePart->GetSelectionManager()->GetBrepFromReference(pReferenceGeometry);
	
	const char * edgetype = "edge";

	// Check constrained and reference geometry
	// parallel constraint support face(planar, cylinderical) and "linear" edge
	if ( *pCoEntity->type_name() == *edgetype && *pRefEntity->type_name() == *edgetype )
	{
		if ( !isLinearEdge((EDGE *)pCoEntity) && !isLinearEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Constrained and reference geometry error : \nTransCAD parallel constraint does not support a circular edge"));

			return false;
		}
		
		else if ( !isLinearEdge((EDGE *)pCoEntity) )
		{
			AfxMessageBox(TEXT("Constrained geometry error : \nTransCAD parallel constraint does not support a circular edge"));

			return false;
		}

		else if ( !isLinearEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Reference geometry error : \nTransCAD parallel constraint does not support a circular edge"));

			return false;
		}
	}

	else if ( *pCoEntity->type_name() == *edgetype )
	{
		if ( !isLinearEdge((EDGE *)pCoEntity) )
		{
			AfxMessageBox(TEXT("Constrained geometry error : \nTransCAD parallel constraint does not support a circular edge"));

			return false;
		}
	}

	else if ( *pRefEntity->type_name() == *edgetype )
	{
		if ( !isLinearEdge((EDGE *)pRefEntity) )
		{
			AfxMessageBox(TEXT("Reference geometry error : \nTransCAD parallel constraint does not support a circular edge"));

			return false;
		}
	}

	else return true;
}

/**
	@brief	Whether this edge is linear or not
	@param	pEdge target edge to check
	@return	linear is true and circular is false
*/
bool PmeStdAssemblyParallelAPI::isLinearEdge(EDGE * pEdge)
{
	CURVE * pCurve = pEdge->geometry();
	const curve & curveEquation = pCurve->equation();
	
	// linear is 0 and circular is 1
	int periodic = curveEquation.periodic();
	
	if ( periodic == 0 ) { return true; }

	else { return false; }
}