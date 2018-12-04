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

#include ".\PmeStdAssemblyDistance.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdAssemblyDistance, PmeObject)

PmeStdAssemblyDistance::PmeStdAssemblyDistance(PmeAssembly * pAssembly,
											   PmePart * pConstrainedPart,
											   PmeReference * pConstrainedGeometry,
											   PmePart * pReferencePart,
											   PmeReference * pReferenceGeometry,
											   double distance,
											   PmeStdAssemblyIncidenceType incidenceType)
: PmeStdAssemblyConstraint(pAssembly)
{
	m_pCoPart		= pConstrainedPart;
	m_pRefPart		= pReferencePart;
	m_pCoGeometry	= pConstrainedGeometry;
	m_pRefGeometry	= pReferenceGeometry;
	m_Distance		= distance;
	m_DistanceType	= incidenceType;
}

PmeStdAssemblyDistance::~PmeStdAssemblyDistance(void)
{
}

/**
	@brief PmeStdAssemblyDistance에서 사용하는 약어 설명
	co는 constrained, ref는 reference를 의미
	L은 local, G는 global을 의미
*/
void PmeStdAssemblyDistance::UpdateConstraint()
{
	m_pCoEntity = GetConstrainedPart()->GetSelectionManager()->GetBrepFromReference(m_pCoGeometry);
	m_pRefEntity = GetReferencePart()->GetSelectionManager()->GetBrepFromReference(m_pRefGeometry);
	
	MrAxis2	globalCSYS = globalCSYS.OXY();

	// Constraint에 사용되는 part의 coordinate정보를 저장
	m_coPartCSYS = GetConstrainedPart()->GetPlacement();
	m_refPartCSYS = GetReferencePart()->GetPlacement();

	// 로컬 좌표계를 글로벌 좌표계로 변환하기 위한 Transformation 변수
	// L means Local, G means Global
	MrTransformation coL2G = MrTransformation::CreateCoordinateSystemTransformation(m_coPartCSYS, globalCSYS);
	MrTransformation refL2G = MrTransformation::CreateCoordinateSystemTransformation(m_refPartCSYS, globalCSYS);

	const char * facetype = "face";
	const char * edgetype = "edge";
	const char * vertextype = "vertex";

	// 1. Constrained와 reference geometry가 모두 "Face" type 일 때,
	if ( *m_pCoEntity->type_name() == *facetype && *m_pRefEntity->type_name() == *facetype )
	{
		// 분기점 1.1 두개의 면이 모두 평면일 때,
		if ( IsPlanarFace((FACE *)m_pCoEntity) && IsPlanarFace((FACE *)m_pRefEntity) )
		{
			// 평면의 로컬 좌표계 저장
			m_coFaceLCSYS = PmeQueryFaceLocalCoordinate((FACE *)m_pCoEntity);
			m_refFaceLCSYS = PmeQueryFaceLocalCoordinate((FACE *)m_pRefEntity);

			// 로컬 좌표계를 글로벌 좌표계로 변환
			m_coFaceGCSYS = MrMath::Transform(m_coFaceLCSYS, coL2G);
			m_refFaceGCSYS = MrMath::Transform(m_refFaceLCSYS, refL2G);

			// constrained와 reference 평면의 normal vector
			m_coNormal.SetCoordinates(m_coFaceLCSYS.ZDirection().X(), m_coFaceLCSYS.ZDirection().Y(), m_coFaceLCSYS.ZDirection().Z());
			m_refNormal.SetCoordinates(m_refFaceLCSYS.ZDirection().X(), m_refFaceLCSYS.ZDirection().Y(), m_refFaceLCSYS.ZDirection().Z());

			// 이미 normal vector가 평행인 경우
			// 평면의 중심점을 기준으로 constrained part를 이동시킨다.
			if ( MrMath::IsParallel( m_coNormal, m_refNormal ) )
			{
				// 분기점 1.1.1 Distance constraint에 사용된 옵션이 "opposite" 일 때,
				if ( m_DistanceType == PmeStdAssemblyIncidenceType_Opposite )
				{
					DoDistancePlanarFacesOpposite();
				}

				// 분기점 1.1.2 Distance constraint에 사용된 옵션이 "same" 일 때,
				else if ( m_DistanceType == PmeStdAssemblyIncidenceType_Same )
				{
					DoDistancePlanarFacesSame();
				}
			}

			// Before setting a distance, rotate constrained part parallel to reference part
			else
			{

				if ( m_DistanceType == PmeStdAssemblyIncidenceType_Opposite )
				{
					DoDistancePlanarFacesOpposite();
				}

				else if ( m_DistanceType == PmeStdAssemblyIncidenceType_Same )
				{
					DoDistancePlanarFacesSame();
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
	GetConstrainedPart()->SetPlacement(m_translationResult);

	// Save final coordinates
	SetTransformedCSYS(m_translationResult);
	
}

/**
	@brief 
	Conduct distance constrainet that both geometires are planar face
	and incidence option is opposite
*/
void PmeStdAssemblyDistance::DoDistancePlanarFacesOpposite(void)
{
	MrAxis2	globalCSYS = globalCSYS.OXY();

	// Constraint를 부여하기 위해 선택된 geometry의 위치정보를 확인
	// constrained geometry가 reference geometry보다 바깥쪽에 있거나
	// 동일한 평면을 공유하고 있을 때 진입
	if ( IsOutside( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		// 이미 normal vector가 반대 방향일 때,
		if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			// Constrained part를 reference part방향으로 이동
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates(m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									 m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									 m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z());

			double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

			// 만약 입력 거리 값이 처음 위치한 거리보다 클 때는
			// constrained part가 반대방향으로 이동해야하기 때문에
			// "reference geometry의 normal 방향"으로 이동하고
			// 이동거리는 입력 거리 - 초기 거리로 정의
			if ( m_Distance > initialDist )
			{
				double translationDist = m_Distance - initialDist;

				m_translationVector = Translation( m_refNormal, translationDist );
								
				m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
			}

			// 입력 거리가 처음 위한 거리보다 작을 때는
			// "constrained geometry의 normal 방향"으로 이동
			// 이동거리는 초기 거리 - 입력 거리
			else if ( m_Distance < initialDist )
			{
				double translationDist = initialDist - m_Distance;

				m_translationVector = MrMath::Reverse( Translation(m_refNormal, translationDist) );

				m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
			}						
		}

		// 선택된 geometry의 normal vector가 같은 방향이면,
		// constrained geometry의 normal vector를 
		// reference geometry의 normal vector와 일치시킨다.
		else if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = GetRotationMatrix( m_coNormal, m_refNormal, M_PI );
			MrAxis2 rotatedAxis = RotateCoordinate( rMatrix, m_coPartCSYS );

			GetConstrainedPart()->SetPlacement( rotatedAxis );


			// 회전 후의 constrained part의 좌표정보를 다시 불러온다.
			MrAxis2 coPartCSYSre = GetConstrainedPart()->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			// constrained geometry의 로컬과 글로벌 좌표정보를 업데이트
			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );


			// 회전 후에 constrained part와 reference part의 위치를 다시 확인
			if ( !IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );
							
				double translationDist = initialDist + m_Distance;

				m_translationVector = Translation( m_refNormal, translationDist );
								
				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else if ( IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ));

				if ( initialDist > m_Distance )
				{
					double translationDist = initialDist - m_Distance;

					m_translationVector = MrMath::Reverse ( Translation( m_refNormal, translationDist ) );
								
					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}

				else if ( initialDist < m_Distance )
				{
					double translationDist = m_Distance - initialDist;

					m_translationVector = Translation( m_refNormal, translationDist );
								
					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}
			}
		}
	}

	// constrained geometry가 reference geometry보다 안쪽에 위치하는 경우
	// 원점에 더 가까운 상황
	else if ( !IsOutside( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		// 이미 두개의 normal vector가 반대방향일 때,
		if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z());

			double initialDistance = abs(MrMath::Dot(vecCo2Ref, m_refNormal));
							
			// Add input distance value to initial distance 
			double translationDist = initialDistance + m_Distance;

			m_translationVector = Translation( m_refNormal, translationDist );

			m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
		}


		// 두개의 normal vector가 같은 방향을 향하고 있을 때,
		// 180도 회전하고 distance constraint 수행
		else
		{
			MrMatrix rMatrix = PmeStdAssemblyConstraint::GetRotationMatrix( m_coNormal, m_refNormal, M_PI );

			MrAxis2 rotatedAxis = RotateCoordinate( rMatrix, m_coPartCSYS );

			GetConstrainedPart()->SetPlacement( rotatedAxis );
							
			MrAxis2 coPartCSYSre = GetConstrainedPart()->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );
							
			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );


			if ( IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

								 
				if ( m_Distance > initialDist )
				{
					double translationDist = m_Distance - initialDist;

					m_translationVector = Translation( m_refNormal, translationDist );

					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}
							
				else if ( m_Distance < initialDist )
				{
					double translationDist = initialDist - m_Distance;

					m_translationVector = MrMath::Reverse( Translation( m_refNormal, translationDist ) );

					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}
			}

			else if ( !IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDistance = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );
							
				double translationDist = initialDistance + m_Distance;

				m_translationVector = Translation( m_refNormal, translationDist );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}							
		}
	}
}

/**
	@brief 
	Conduct distance constrainet that both geometires are planar face
	and incidence option is same
*/
void PmeStdAssemblyDistance::DoDistancePlanarFacesSame(void)
{
	MrAxis2	globalCSYS = globalCSYS.OXY();

	// 선택된 geometry의 위치정보 확인
	// constrained geometry가 reference geometry보다 바깥쪽에 있을 때,
	if ( IsOutside( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		// 이미 geometry의 normal vector가 같은 방향을 향할 때,
		if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z());
							
			double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

			double translationDist = initialDist + m_Distance;

			m_translationVector = MrMath::Reverse( Translation( m_refNormal, translationDist ) );
							
			m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
		}

		// geometry의 normal vector가 반대 방향을 향할 때,
		else if ( MrMath::IsOpposite( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = PmeStdAssemblyConstraint::GetRotationMatrix( m_coNormal, m_refNormal, M_PI );

			MrAxis2 rotatedAxis = RotateCoordinate( rMatrix, m_coPartCSYS );

			GetConstrainedPart()->SetPlacement( rotatedAxis );

			MrAxis2 coPartCSYSre = GetConstrainedPart()->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate( (FACE *)m_pCoEntity );
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );

			// 한번 더 서로 간의 위치 확인
			if ( IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_coNormal ) );

				double translationDist = initialDist + m_Distance;

				m_translationVector = MrMath::Reverse( Translation( m_refNormal, translationDist ) );
								
				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else if ( !IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				if ( initialDist > m_Distance )
				{
					double translationDist = initialDist - m_Distance;

					m_translationVector = Translation( m_refNormal, translationDist );

					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}

				else if ( initialDist < m_Distance )
				{
					double translationDist = m_Distance - initialDist;

					m_translationVector = MrMath::Reverse( Translation( m_refNormal, translationDist ) );

					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}
			}
		}
	}

	// constrained geometry가 reference geometry보다 안쪽에 있을 때,
	else if ( !IsOutside( m_coFaceGCSYS, m_refFaceGCSYS ) )
	{
		if ( MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrVector vecCo2Ref;
			vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - m_coFaceGCSYS.Location().X(),
									  m_refFaceGCSYS.Location().Y() - m_coFaceGCSYS.Location().Y(),
									  m_refFaceGCSYS.Location().Z() - m_coFaceGCSYS.Location().Z());

			double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

			if ( initialDist > m_Distance )
			{
				double translationDist = initialDist - m_Distance;

				m_translationVector = Translation( m_refNormal, translationDist );

				m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
			}

			else if ( initialDist < m_Distance )
			{
				double translationDist = m_Distance - initialDist;

				m_translationVector = MrMath::Reverse( Translation( m_refNormal, translationDist ) );

				m_translationResult = SetTranslationResult( m_coPartCSYS, m_translationVector );
			}
		}

		else if ( !MrMath::IsEqual( m_coNormal, m_refNormal ) )
		{
			MrMatrix rMatrix = PmeStdAssemblyConstraint::GetRotationMatrix( m_coNormal, m_refNormal, M_PI );

			MrAxis2 rotatedAxis = RotateCoordinate( rMatrix, m_coPartCSYS );

			GetConstrainedPart()->SetPlacement( rotatedAxis );

			MrAxis2 coPartCSYSre = GetConstrainedPart()->GetPlacement();
			MrTransformation coL2Gre = MrTransformation::CreateCoordinateSystemTransformation( coPartCSYSre, globalCSYS );

			MrAxis2 coFaceLCSYSre = PmeQueryFaceLocalCoordinate((FACE *)m_pCoEntity);
			MrAxis2 coFaceGCSYSre = MrMath::Transform( m_coFaceLCSYS, coL2Gre );


			if ( IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				double translationDist = initialDist + m_Distance;

				m_translationVector = MrMath::Reverse(Translation( m_refNormal, translationDist ) );

				m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
			}

			else if ( !IsOutside( coFaceGCSYSre, m_refFaceGCSYS ) )
			{
				MrVector vecCo2Ref;
				vecCo2Ref.SetCoordinates( m_refFaceGCSYS.Location().X() - coFaceGCSYSre.Location().X(),
										  m_refFaceGCSYS.Location().Y() - coFaceGCSYSre.Location().Y(),
										  m_refFaceGCSYS.Location().Z() - coFaceGCSYSre.Location().Z());

				double initialDist = abs( MrMath::Dot( vecCo2Ref, m_refNormal ) );

				if ( initialDist > m_Distance )
				{
					double translationDist = initialDist - m_Distance;

					m_translationVector = Translation( m_refNormal, translationDist );

					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}

				else if ( initialDist < m_Distance )
				{
					double translationDist = m_Distance - initialDist;

					m_translationVector = MrMath::Reverse( Translation( m_refNormal, translationDist ) );

					m_translationResult = SetTranslationResult( coPartCSYSre, m_translationVector );
				}
			}
		}
	}
}