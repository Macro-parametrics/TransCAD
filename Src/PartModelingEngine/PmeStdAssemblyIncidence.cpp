#include "stdAfx.h"
#include ".\PmeAssembly.h"
//#include ".\PmeComponent.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeStdAssemblyIncidence.h"
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

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdAssemblyIncidence, PmeObject)

PmeStdAssemblyIncidence::PmeStdAssemblyIncidence(PmeAssembly * pAssembly,
												 PmePart * pConstrainedPart,
												 PmeReference * pConstrainedGeometry,
												 PmePart * pReferencePart,
												 PmeReference * pReferenceGeometry,
												 PmeStdAssemblyIncidenceType incidenceType)
: PmeStdAssemblyConstraint(pAssembly)
{
	m_pCoPart		= pConstrainedPart;
	m_pRefPart		= pReferencePart;
	m_pCoGeometry	= pConstrainedGeometry;
	m_pRefGeometry	= pReferenceGeometry;
	m_incidenceType = incidenceType;
}

PmeStdAssemblyIncidence::~PmeStdAssemblyIncidence(void)
{

}

/**
	@brief PmeStdAssemblyDistance에서 사용하는 약어 설명
	co는 constrained, ref는 reference를 의미
	L은 local, G는 global을 의미
*/
void PmeStdAssemblyIncidence::UpdateConstraint(void)
{
	m_pCoEntity = GetConstrainedPart()->GetSelectionManager()->GetBrepFromReference( m_pCoGeometry );
	m_pRefEntity = GetReferencePart()->GetSelectionManager()->GetBrepFromReference( m_pRefGeometry );
	
	MrAxis2	globalCSYS = globalCSYS.OXY();

	m_coPartCSYS = GetConstrainedPart()->GetPlacement();
	m_refPartCSYS = GetReferencePart()->GetPlacement();

	m_coLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( m_coPartCSYS, globalCSYS );
	m_refLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( m_refPartCSYS, globalCSYS );

	const char * facetype = "face";
	const char * edgetype = "edge";
	const char * vertextype = "vertex";

	// 1. Constrained and reference geometry are "Face" type
	if ( *m_pCoEntity->type_name() == *facetype && *m_pRefEntity->type_name() == *facetype )
	{
		// 1.1 Both geometries are planar face
		if ( IsPlanarFace( (FACE *)m_pCoEntity ) && IsPlanarFace( (FACE *)m_pRefEntity ) )
		{
			// Local coordinates
			m_coFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			m_refFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)m_pRefEntity );

			// Global coordinates
			m_coFaceGCSYS = MrMath::Transform(m_coFaceLCSYS, m_coLocalToGlobal);
			m_refFaceGCSYS = MrMath::Transform(m_refFaceLCSYS, m_refLocalToGlobal);

			// Normal vectors of constrained and reference geometries
			m_coNormal.SetCoordinates(m_coFaceLCSYS.ZDirection().X(), m_coFaceLCSYS.ZDirection().Y(), m_coFaceLCSYS.ZDirection().Z());
			m_refNormal.SetCoordinates(m_refFaceLCSYS.ZDirection().X(), m_refFaceLCSYS.ZDirection().Y(), m_refFaceLCSYS.ZDirection().Z());

			// Already parallel
			// Project constrained part to reference part
			if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
			{
				// 1.1.1 Incidence type is "opposite"
				if ( m_incidenceType == PmeStdAssemblyIncidenceType_Opposite )
				{
					DoIncidencePlanarFacesOpposite();
				}

				// 1.1.2 Incidence type is "same"
				else if ( m_incidenceType == PmeStdAssemblyIncidenceType_Same )
				{
					DoIncidencePlanarFacesSame();
				}
			}

			// if both normal vectors are not parallel
			else
			{
				ApplyParallel( m_pCoPart, m_coNormal, m_refNormal );

				// Get CSYS of constrained part again
				m_coPartCSYS = m_pCoPart->GetPlacement();
				m_coLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( m_coPartCSYS, globalCSYS );

				// constrained geometry의 로컬과 글로벌 좌표정보를 업데이트
				m_coFaceLCSYS = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
				m_coFaceGCSYS = MrMath::Transform( m_coFaceLCSYS, m_coLocalToGlobal );
				m_coNormal.SetCoordinates(m_coFaceLCSYS.ZDirection().X(), m_coFaceLCSYS.ZDirection().Y(), m_coFaceLCSYS.ZDirection().Z());

				if ( m_incidenceType == PmeStdAssemblyIncidenceType_Opposite )
				{
					DoIncidencePlanarFacesOpposite();
				}

				else if ( m_incidenceType == PmeStdAssemblyIncidenceType_Same )
				{
					DoIncidencePlanarFacesSame();
				}
			}
		}

		// 1.2 Both faces are cylinderical face


		// 1.3 Constrained face is planar face and reference face is cylinderical


		// 1.4 Constrained face is cylinderical face and reference face is planar
	}

	// 2. Constrained and reference geometry are "Edge" type
	if ( *m_pCoEntity->type_name() == *edgetype && *m_pRefEntity->type_name() == *edgetype )
	{
		EDGE * coEdge = (EDGE *)m_pCoEntity;
		EDGE * refEdge = (EDGE *)m_pRefEntity;

		DoIncidence( coEdge, refEdge );
	}


	// 3. Constrained geometry is "Face" and reference geometry is "Edge"
	if ( *m_pCoEntity->type_name() == *facetype && *m_pRefEntity->type_name() == *edgetype )
	{
		
	}


	// 4. Constrained geometry is "Edge" and reference geometry is "Face"
	if ( *m_pCoEntity->type_name() == *edgetype && *m_pRefEntity->type_name() == *facetype )
	{

	}


	// Update coordinates of constrained part
	GetConstrainedPart()->SetPlacement( m_translationResult );

	// Save final coordinates
	SetTransformedCSYS( m_translationResult );
}

void PmeStdAssemblyIncidence::DoIncidencePlanarFacesOpposite(void)
{
	MrAxis2	globalCSYS = globalCSYS.OXY();

	if ( IsOutside ( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		// both normal vectors are opposite direction
		if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			// constrained part moves to reference part
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z() );

			double distance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

			m_translationVector = MrMath::Reverse(Translation( m_refNormal, distance ) );

			m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
		}

		// normal vectors of constrained and reference are same direction
		else if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = GetRotationMatrix( m_coNormal, m_refNormal, M_PI );
			MrAxis2 rotatedCSYS = RotateCoordinate( rMatrix, m_coPartCSYS );

			m_pCoPart->SetPlacement( rotatedCSYS );

			// Get CSYS of constrained part again
			MrAxis2 coPartCSYSre = m_pCoPart->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			// constrained geometry의 로컬과 글로벌 좌표정보를 업데이트
			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );

			// Check position relation of constrained and reference part again
			if ( IsOutside ( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				m_translationVector = Translation( m_coNormal, distance );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				m_translationVector = Translation( m_refNormal, distance );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

		}
	}

	else if ( !IsOutside ( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z());

			double distance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

			m_translationVector = Translation( m_refNormal, distance );

			m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
		}

		else if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = GetRotationMatrix( m_coNormal, m_refNormal, M_PI );
			MrAxis2 rotatedCSYS = RotateCoordinate( rMatrix, m_coPartCSYS );

			m_pCoPart->SetPlacement( rotatedCSYS );

			// Get CSYS of constrained part again
			MrAxis2 coPartCSYSre = m_pCoPart->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			// constrained geometry의 로컬과 글로벌 좌표정보를 업데이트
			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );

			// Check position relation of constrained and reference part again
			if ( IsOutside ( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				m_translationVector = MrMath::Reverse( Translation( m_refNormal, distance ) );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				m_translationVector = Translation( m_refNormal, distance );

				m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
			}
		}
	}
}

void PmeStdAssemblyIncidence::DoIncidencePlanarFacesSame(void)
{
	MrAxis2 globalCSYS = globalCSYS.OXY();

	if ( IsOutside ( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = GetRotationMatrix( m_coNormal, m_refNormal, M_PI );
			MrAxis2 rotatedCSYS = RotateCoordinate( rMatrix, m_coPartCSYS );

			m_pCoPart->SetPlacement( rotatedCSYS );

			// Get CSYS of constrained part again
			MrAxis2 coPartCSYSre = m_pCoPart->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			// constrained geometry의 로컬과 글로벌 좌표정보를 업데이트
			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );

			// Check position relation of constrained and reference part again
			if ( IsOutside ( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

				m_translationVector = MrMath::Reverse( Translation( m_refNormal, distance ) );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

				m_translationVector = Translation( m_refNormal, distance );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}
		}

		else if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z() );

			double distance = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

			m_translationVector = MrMath::Reverse( Translation( m_refNormal, distance ) );

			m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
		}
	}

	else if ( !IsOutside ( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z() );

			double distance = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

			m_translationVector = Translation( m_refNormal, distance );

			m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
		}

		else if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = GetRotationMatrix( m_coNormal, m_refNormal, M_PI );
			MrAxis2 rotatedCSYS = RotateCoordinate( rMatrix, m_coPartCSYS );

			m_pCoPart->SetPlacement( rotatedCSYS );

			// Get CSYS of constrained part again
			MrAxis2 coPartCSYSre = m_pCoPart->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			// constrained geometry의 로컬과 글로벌 좌표정보를 업데이트
			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );

			if ( IsOutside ( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

				m_translationVector = MrMath::Reverse( Translation( m_refNormal, distance ) );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else if ( !IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z() );

				double distance = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

				m_translationVector = Translation( m_refNormal, distance );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}
		}
	}
}

void PmeStdAssemblyIncidence::DoIncidence( EDGE * pCoEdge, EDGE * pRefEdge )
{
	MrAxis2	globalCSYS = globalCSYS.OXY();

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

	if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
	{
		MrPosition coMidPoint = MrPosition( pCoEdge->mid_pos().x(), pCoEdge->mid_pos().y(), pCoEdge->mid_pos().z() );
		coMidPoint = MrMath::Transform( coMidPoint, m_coLocalToGlobal );

		MrPosition refMidPoint = MrPosition( pRefEdge->mid_pos().x(), pRefEdge->mid_pos().y(), pRefEdge->mid_pos().z() );
		refMidPoint = MrMath::Transform( refMidPoint, m_refLocalToGlobal );

		MrVector vecCoToRef = MrVector( coMidPoint, refMidPoint );
		MrVector projection = MrMath::Project( vecCoToRef, m_refNormal );

		m_translationVector = Translation( vecCoToRef, projection );

		m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
	}

	else if ( !MrMath::IsParallel( m_coNormal, m_refNormal ) )
	{
		ApplyParallel( m_pCoPart, m_coNormal, m_refNormal );

		m_coPartCSYS = GetConstrainedPart()->GetPlacement();
		m_coLocalToGlobal = MrTransformation::CreateCoordinateSystemTransformation( m_coPartCSYS, globalCSYS );

		MrPosition coMidPoint = MrPosition( pCoEdge->mid_pos().x(), pCoEdge->mid_pos().y(), pCoEdge->mid_pos().z() );
		coMidPoint = MrMath::Transform( coMidPoint, m_coLocalToGlobal );

		MrPosition refMidPoint = MrPosition( pRefEdge->mid_pos().x(), pRefEdge->mid_pos().y(), pRefEdge->mid_pos().z() );
		refMidPoint = MrMath::Transform( refMidPoint, m_refLocalToGlobal );

		MrVector vecCoToRef = MrVector( coMidPoint, refMidPoint );
		MrVector projection = MrMath::Project( vecCoToRef, m_refNormal );

		m_translationVector = Translation( vecCoToRef, projection );

		m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
	}
}