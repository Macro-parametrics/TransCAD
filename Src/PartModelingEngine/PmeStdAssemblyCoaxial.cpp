#include "stdAfx.h"
#include ".\PmeAssembly.h"
//#include ".\PmeComponent.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeStdAssemblyCoaxial.h"
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
#include "cone.hxx"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdAssemblyCoaxial, PmeObject)

PmeStdAssemblyCoaxial::PmeStdAssemblyCoaxial(PmeAssembly * pAssembly, PmePart * pConstrainedPart, PmeReference * pConstrainedGeometry, PmePart * pReferencePart, PmeReference * pReferenceGeometry)
: PmeStdAssemblyConstraint(pAssembly)
,m_pCoPart(pConstrainedPart)
,m_pCoGeometry(pConstrainedGeometry)
,m_pRefPart(pReferencePart)
,m_pRefGeometry(pReferenceGeometry)
{
}

PmeStdAssemblyCoaxial::~PmeStdAssemblyCoaxial(void)
{
	
}

/**
	@brief Apply parallel constraint\n
	co means constrained, ref means reference
	L means local, and G means global
*/
void PmeStdAssemblyCoaxial::UpdateConstraint()
{
	ENTITY * pCoEntity = GetConstrainedPart()->GetSelectionManager()->GetBrepFromReference( m_pCoGeometry );
	ENTITY * pRefEntity = GetReferencePart()->GetSelectionManager()->GetBrepFromReference( m_pRefGeometry );

	const char * facetype = "face";
	const char * edgetype = "edge";
	
	// 1. Constrained geometry and reference geometry are "Face" type
	// CATIA only uses this geometry type
	// NX can use this method through "infer Center/Axis"
	if (*pCoEntity->type_name() == *facetype && *pRefEntity->type_name() == *facetype)
	{
		// Get local coordinate each cylinderical face(centroid point and normal)
		MrAxis2 coFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetConstrainedPart(), (FACE *)pCoEntity );
		MrAxis2 refFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetReferencePart(), (FACE *)pRefEntity );

		DoCoaxial( coFaceLCSYS, refFaceLCSYS );
	}

	
	// 2. Constrained geometry and reference geometry are "Edge" type
	// NX uses this method through cocentric
	else if ( *pCoEntity->type_name() == *edgetype && *pRefEntity->type_name() == *edgetype )
	{
		// Get local coordinate each circular edge(center point and normal)
		MrAxis2 coEdgeLCSYS = PmeQueryEdgeLocalCoordinate( (EDGE *)pCoEntity );
		MrAxis2 refEdgeLCSYS = PmeQueryEdgeLocalCoordinate( (EDGE *)pRefEntity );

		DoCoaxial( coEdgeLCSYS, refEdgeLCSYS );
	}

	// 3. Constrained geometry is "Face" type and reference geometry is "Edge" type
	// NX can use this method through "infer Center/Axis"
	else if (*pCoEntity->type_name() == *facetype && *pRefEntity->type_name() == *edgetype)
	{
		MrAxis2 coFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetConstrainedPart(), (FACE *)pCoEntity );
		MrAxis2 refEdgeLCSYS = PmeQueryEdgeLocalCoordinate( (EDGE *)pRefEntity );

		DoCoaxial( coFaceLCSYS, refEdgeLCSYS );
	}

	// 4. Constrained geometry is "Edge" type and reference geometry is "Face" type
	// NX can use this method through "infer Center/Axis"
	else if ( *pCoEntity->type_name() == *edgetype && *pRefEntity->type_name() == *facetype )
	{
		MrAxis2 coEdgeLCSYS = PmeQueryEdgeLocalCoordinate( (EDGE *)pCoEntity );
		MrAxis2 refFaceLCSYS = PmeQueryCylindericalFaceLocalCoordinate( GetReferencePart(), (FACE *)pRefEntity );

		DoCoaxial( coEdgeLCSYS, refFaceLCSYS );
	}

	// Update coordinates of constrained part
	GetConstrainedPart()->SetPlacement(m_translationResult);

	// Save final coordinates
	SetTransformedCSYS(m_translationResult);
}

/**
	@brief							Apply coaxial constraint

	@param constrainedLocalCSYS		Local coordinate system of constrained geometry

	@param referenceLocalCSYS		Local coordinate system of reference geometry
*/
void PmeStdAssemblyCoaxial::DoCoaxial( MrAxis2 constrainedLocalCSYS, MrAxis2 referenceLocalCSYS )
{
	MrAxis2 globalCSYS = globalCSYS.OXY();

	// Get coordinate system each part
	MrAxis2 coPartCSYS = GetConstrainedPart()->GetPlacement();
	MrAxis2 refPartCSYS = GetReferencePart()->GetPlacement();

	// Get transformation for translating local coordinate to global coordinate
	MrTransformation coLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYS, globalCSYS );
	MrTransformation refLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( refPartCSYS, globalCSYS );

	// Transform coordinates from local to global
	MrAxis2 coFaceGCSYS = MrMath::Transform( constrainedLocalCSYS, coLocalToGlobal );
	MrAxis2 refFaceGCSYS = MrMath::Transform( referenceLocalCSYS, refLocalToGlobal );


	// °¢ cylinderical faceÀÇ normal(Same to part's normal)
	MrVector coNormal, refNormal;
	coNormal.SetCoordinates(coFaceGCSYS.ZDirection().X(), coFaceGCSYS.ZDirection().Y(), coFaceGCSYS.ZDirection().Z());
	refNormal.SetCoordinates(refFaceGCSYS.ZDirection().X(), refFaceGCSYS.ZDirection().Y(), refFaceGCSYS.ZDirection().Z());


	// If both geometries aleady parallel, constrained part's center point project to
	// reference part's normal axis without rotation
	if ( MrMath::IsParallel( coNormal, refNormal ) )
	{
		MrVector vecBtwCoAndRef;
		vecBtwCoAndRef.SetCoordinates( coPartCSYS.Location().X() - refPartCSYS.Location().X(),
										coPartCSYS.Location().Y() - refPartCSYS.Location().Y(),
										coPartCSYS.Location().Z() - refPartCSYS.Location().Z() );
    
		MrVector projVec;
		projVec = MrMath::Project( vecBtwCoAndRef, refNormal);

		// Calculate a translation vector
		m_translationVector = Translation( projVec, vecBtwCoAndRef );

		// Calculate a final position after applying a coaxial constraint
		m_translationResult = SetTranslationResult( coPartCSYS, m_translationVector );		
	}

	// normal vectors of constrained and reference are not parallel.
	else
	{
		// Firstly, apply parallel constraint
		ApplyParallel( GetConstrainedPart(), coNormal, refNormal );
    
		// Get coordinate system of constrained part again
		MrAxis2 coPartCSYSre = GetConstrainedPart()->GetPlacement();

		// Project constrained part onto normal axis of reference part
		MrVector projVec, u, v;
    
		u.SetCoordinates( GetConstrainedPart()->GetPlacement().Location().X(),
						  GetConstrainedPart()->GetPlacement().Location().Y(),
						  GetConstrainedPart()->GetPlacement().Location().Z() );

		v = refNormal;
    
		projVec = MrMath::Project( u, v );
    
		m_translationVector = Translation( projVec, u );

		m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );

	}
}