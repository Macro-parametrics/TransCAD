#include "stdAfx.h"
#include ".\PmeAssembly.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeArgumentException.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeSketchUtility.h"

#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeDatumPlane.h"
#include ".\PmeDatumPlaneUtility.h"
#include ".\PmeQuery.h"
#include ".\PmeArgumentTypeException.h"
#include "MrTransformation.h"
#include "MrMath.h"

#include ".\PmeStdAssemblyParallel.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdAssemblyParallel, PmeObject)

PmeStdAssemblyParallel::PmeStdAssemblyParallel(PmeAssembly * pAssembly,
											   PmePart * pConstrainedPart,
											   PmeReference * pConstrainedGeometry,
											   PmePart * pReferencePart,
											   PmeReference * pReferenceGeometry)
: PmeStdAssemblyConstraint(pAssembly)
{
	m_pCoPart		= pConstrainedPart;
	m_pRefPart		= pReferencePart;
	m_pCoGeometry	= pConstrainedGeometry;
	m_pRefGeometry	= pReferenceGeometry;
}

PmeStdAssemblyParallel::~PmeStdAssemblyParallel(void)
{
}

/**
	@brief Apply parallel constraint\n
	co means constrained, ref means reference
	L means local, and G means global
*/
void PmeStdAssemblyParallel::UpdateConstraint()
{
	ENTITY * pCoEntity = GetConstrainedPart()->GetSelectionManager()->GetBrepFromReference( m_pCoGeometry );
	ENTITY * pRefEntity = GetReferencePart()->GetSelectionManager()->GetBrepFromReference( m_pRefGeometry );
		
	MrAxis2 globalCSYS = globalCSYS.OXY();

	// Get coordinate system each part
	MrAxis2 coPartCSYS = GetConstrainedPart()->GetPlacement();
	MrAxis2 refPartCSYS = GetReferencePart()->GetPlacement();

	// Get transformation for translating local coordinate to global coordinate
	m_coLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYS, globalCSYS );
	m_refLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( refPartCSYS, globalCSYS );

	const char * facetype = "face";
	const char * edgetype = "edge";

	// 1. Constrained and reference geometry are "face" type
	if ( *pCoEntity->type_name() == *facetype && *pRefEntity->type_name() == *facetype )
	{
		// Case 1. Constrained and reference geometry are planar face
		if ( IsPlanarFace( (FACE *)pCoEntity ) && IsPlanarFace( (FACE *)pRefEntity) )
		{
			// Get local coordinates each face
			MrAxis2 coFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)pCoEntity );
			MrAxis2 refFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)pRefEntity );

			DoParallel( coFaceLCSYS, refFaceLCSYS );
		}

		// Case 2. Constrained and reference geometry are cylinderical face
		else if ( !IsPlanarFace( (FACE *)pCoEntity ) && !IsPlanarFace( (FACE *)pRefEntity ) )
		{
			// Get local coordinates each face
			MrAxis2 coFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetConstrainedPart(), (FACE *)pCoEntity );
			MrAxis2 refFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetReferencePart(), (FACE *)pRefEntity );

			DoParallel( coFaceLCSYS, refFaceLCSYS );
		}

		// Case 3. Constrained geometry is planar and reference geometry is cylinderical
		else if ( IsPlanarFace( (FACE *)pCoEntity ) && !IsPlanarFace( (FACE *)pRefEntity ) )
		{
			// Get local coordinates each face
			MrAxis2 coFaceLCSYS = PmeQueryFaceLocalCoordinate((FACE *)pCoEntity);
			MrAxis2 refFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate(GetReferencePart(), (FACE *)pRefEntity);

			DoParallel( coFaceLCSYS, refFaceLCSYS );
		}

		// Case 4. Constrained geometry is cylinderical and reference geometry is planar
		else if ( !IsPlanarFace((FACE *)pCoEntity) && IsPlanarFace((FACE *)pRefEntity) )
		{
			// Get local coordinates each face
			MrAxis2 coFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate(GetConstrainedPart(), (FACE *)pCoEntity);
			MrAxis2 refFaceLCSYS = PmeQueryFaceLocalCoordinate((FACE *)pRefEntity);

			DoParallel( coFaceLCSYS, refFaceLCSYS );
		}
	}

	// 2. Constrained and reference geometry are "edge" type
	else if ( *pCoEntity->type_name() == *edgetype && *pRefEntity->type_name() == *edgetype )
	{
		EDGE * coEdge = (EDGE *)pCoEntity;
		EDGE * refEdge = (EDGE *)pRefEntity;

		DoParallel( coEdge, refEdge );
	}

	// 3. Constrained geometry is "edge" type and reference geometry is "face" type
	else if ( *pCoEntity->type_name() == *edgetype && *pRefEntity->type_name() == *facetype )
	{
		MrAxis2 refFaceLCSYS;
		
		EDGE * coEdge = (EDGE *)pCoEntity;
		
		// Case 1. reference geometry is planar
		if ( IsPlanarFace((FACE *)pRefEntity) )
			MrAxis2 refFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)pRefEntity );

		// Case 2. reference geometry is cylinderical
		else
			MrAxis2 refFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetReferencePart(), (FACE *)pRefEntity );
		

		DoParallel( refFaceLCSYS, coEdge, 0 );
	}

	// 4. Constrained geometry is "face" type and reference geometry is "edge" type
	else if ( *pCoEntity->type_name() == *facetype && *pRefEntity->type_name() == *edgetype )
	{
		MrAxis2 coFaceLCSYS;

		// Case 1. constrained geometry is planar
		if ( IsPlanarFace( (FACE *)pCoEntity ) )
			MrAxis2 coFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)pCoEntity );

		// Case 2. reference geometry is cylinderical
		else
			MrAxis2 coFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetConstrainedPart(), (FACE *)pCoEntity );
		

		EDGE * refEdge = (EDGE *)pRefEntity;

		DoParallel( coFaceLCSYS, refEdge, 1 );
	}
}

/**
	@brief					Apply parallel constraint between faces.

	@param coFaceLocalCSYS	Local coordinate system of constrained geometry(Face).

	@param refFaceLocalCSYS	Local coordinate system of constrained geometry(Face).
*/
void PmeStdAssemblyParallel::DoParallel( MrAxis2 coFaceLocalCSYS, MrAxis2 refFaceLocalCSYS )
{
	// Transform coordinates from local to global
	MrAxis2 coFaceGCSYS = MrMath::Transform( coFaceLocalCSYS, m_coLocalToGlobal );
	MrAxis2 refFaceGCSYS = MrMath::Transform( refFaceLocalCSYS, m_refLocalToGlobal );

	// Face normal
	m_coNormal.SetCoordinates( coFaceGCSYS.ZDirection().X(), coFaceGCSYS.ZDirection().Y(), coFaceGCSYS.ZDirection().Z() );
	m_refNormal.SetCoordinates( refFaceGCSYS.ZDirection().X(), refFaceGCSYS.ZDirection().Y(), refFaceGCSYS.ZDirection().Z());

	if ( !MrMath::IsParallel( m_coNormal, m_refNormal) )
	{
		ApplyParallel( GetConstrainedPart(), m_coNormal, m_refNormal );
	}
	else if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
	{
		AfxMessageBox( TEXT("Selected geometries are already paralleled.") );
	}
}

/**
	@brief			Apply parallel constraint between edges.

	@param pCoEdge	Constrained edge.

	@param pRefEdge	Reference edge.
*/
void PmeStdAssemblyParallel::DoParallel( EDGE * pCoEdge, EDGE * pRefEdge )
{
	// Vector of straight edge from start to end
	MrVector coVector = MrVector( pCoEdge->end()->geometry()->coords().x() - pCoEdge->start()->geometry()->coords().x(),
								  pCoEdge->end()->geometry()->coords().y() - pCoEdge->start()->geometry()->coords().y(),
								  pCoEdge->end()->geometry()->coords().z() - pCoEdge->start()->geometry()->coords().z() );
			
	MrVector refVector = MrVector( pRefEdge->end()->geometry()->coords().x() - pRefEdge->start()->geometry()->coords().x(),
								   pRefEdge->end()->geometry()->coords().y() - pRefEdge->start()->geometry()->coords().y(),
								   pRefEdge->end()->geometry()->coords().z() - pRefEdge->start()->geometry()->coords().z() );

	// Transform local to global
	coVector = MrMath::Transform( coVector, m_coLocalToGlobal );
	refVector = MrMath::Transform( refVector, m_refLocalToGlobal );

	// Normalize
	m_coNormal = MrMath::Normalize( coVector );
	m_refNormal = MrMath::Normalize( refVector );

	if ( !MrMath::IsParallel( m_coNormal, m_refNormal ) )
	{
		ApplyParallel( GetConstrainedPart(), m_coNormal, m_refNormal );
	}
	else if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
	{
		AfxMessageBox( TEXT("Selected geometries are already parallel.") );
	}
}

/**
	@brief					Apply parallel constraint between face and edge vice versa.

	@param faceLocalCSYS	Local coordinate system of constrained geometry(Face).

	@param pEdge			Used edge.

	@param flag				identifier which geometry is constrained.\n
							0 : edge is constrained.\n
							1 : face is constrained.
*/
void PmeStdAssemblyParallel::DoParallel( MrAxis2 faceLocalCSYS, EDGE * pEdge, int flag )
{
	// Process edge
	MrVector edgeVector;

	edgeVector = MrVector( pEdge->end()->geometry()->coords().x() - pEdge->start()->geometry()->coords().x(),
						   pEdge->end()->geometry()->coords().y() - pEdge->start()->geometry()->coords().y(),
						   pEdge->end()->geometry()->coords().z() - pEdge->start()->geometry()->coords().z());

	edgeVector = MrMath::Transform( edgeVector, m_coLocalToGlobal );

	edgeVector = MrMath::Normalize( edgeVector );


	// Process face
	MrAxis2 faceGCSYS;
	MrVector faceNormal;

	if ( flag == 0 )
	{
		faceGCSYS = MrMath::Transform( faceLocalCSYS, m_refLocalToGlobal );

		faceNormal.SetCoordinates( faceGCSYS.ZDirection().X(), faceGCSYS.ZDirection().Y(), faceGCSYS.ZDirection().Z() );

		if ( !MrMath::IsParallel( edgeVector, faceNormal ) )
		{
			ApplyParallel( GetConstrainedPart(), edgeVector, faceNormal );
		}
		else if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
		{
			AfxMessageBox( TEXT("Selected geometries are already parallel.") );
		}
	}

	else if ( flag == 1 )
	{
		faceGCSYS = MrMath::Transform( faceLocalCSYS, m_coLocalToGlobal );

		faceNormal.SetCoordinates( faceGCSYS.ZDirection().X(), faceGCSYS.ZDirection().Y(), faceGCSYS.ZDirection().Z() );

		if ( !MrMath::IsParallel( edgeVector, faceNormal ) )
		{
			ApplyParallel( GetConstrainedPart(), faceNormal, edgeVector );
		}
		else if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
		{
			AfxMessageBox( TEXT("Selected geometries are already parallel.") );
		}
	}
}