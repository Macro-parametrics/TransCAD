#include "stdAfx.h"
#include ".\PmeAssembly.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeStdAssemblyConstraint.h"
#include ".\PmeStdAssemblyConstraints.h"
#include ".\PmeArgumentException.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdAssemblyConstraint, PmeObject)

PmeStdAssemblyConstraint::PmeStdAssemblyConstraint(PmeAssembly * pAssembly)
: m_pAssembly(pAssembly)
{
}

PmeStdAssemblyConstraint::PmeStdAssemblyConstraint(PmeAssembly * pAssembly, const CString & name)
: m_pAssembly(pAssembly)
{
	SetName(name);
}

PmeStdAssemblyConstraint::~PmeStdAssemblyConstraint(void)
{
}

void PmeStdAssemblyConstraint::SetName(const CString & name)
{
	if(!CheckName(name))
		throw PmeArgumentException(_T("동일한 조립체 안에 같은 이름을 가진 구속조건이 존재합니다."));

	m_name = name;
}

void PmeStdAssemblyConstraint::GiveDefaultName(void)
{
	//PmeStdAssemblyConstraints::SizeType size = GetAssembly()->GetConstraints()->GetSize();
	int size = GetAssembly()->GetConstraintList().size();

	CString className = GetRuntimeType()->ClassName();
	className.Delete(0, 3);

	do
	{
        m_name.Format(_T("%s%d"), className, ++ size);
	} while(!CheckName(m_name));
}

bool PmeStdAssemblyConstraint::CheckName(const CString & name) const
{
	//PmeStdAssemblyConstraints * pConstraints = GetAssembly()->GetConstraints();
	
	//return pConstraints->FindByName(name) == NULL;
	return true;
}


/**
	@brief		Calculate rotation matrix by using two vectors.\n
				Rotation matrix is set a normal vector of constrained part to a normal vector of reference part.
	
	@param v1	Normal vector of constrained part.

	@param v2	Normal vector of reference part.

	@return		Rotation matrix calculated by two vectors.
*/
MrMatrix PmeStdAssemblyConstraint::GetRotationMatrix(MrVector v1, MrVector v2)
{
	// rotation axis
	MrVector rAxis;
	rAxis = MrMath::Cross(v1, v2);
	rAxis = MrMath::Normalize(rAxis);

	// rotation angle
	double rAngle;
	rAngle = acos(MrMath::Dot(v1, v2));

	if ( rAngle > M_PI_2 ) { rAngle = (-1) * (rAngle - M_PI_2); }

	// rotation matrix
	double c = cos( rAngle );
	double s = sin( rAngle );
	double t = 1 - c;

	MrMatrix rotationMatrix;
	rotationMatrix.SetRows( MrVector( t * pow(rAxis.X(), 2) + c,
									  t * rAxis.X() * rAxis.Y() - s * rAxis.Z(),
									  t * rAxis.X() * rAxis.Z() + s * rAxis.Y() ),
							MrVector( t * rAxis.Y() * rAxis.X() + s * rAxis.Z(),
									  t * pow(rAxis.Y(), 2) + c,
									  t * rAxis.Y() * rAxis.Z() - s * rAxis.X() ),
							MrVector( t * rAxis.Z() * rAxis.X() - s * rAxis.Y(),
									  t * rAxis.Z() * rAxis.Y() + s * rAxis.X(),
									  t * pow(rAxis.Z(), 2) + c) );

	return rotationMatrix;
}

/**
	@brief			Calculate rotation matrix by using two vectors and an specified angle.
	
	@param v1		Normal vector of constrained part.

	@param v2		Normal vector of reference part.
	
	@param angle	An specified angle wanted to rotate.

	@return			Rotation matrix calculated by two vectors and angle.
*/
MrMatrix PmeStdAssemblyConstraint::GetRotationMatrix( MrVector v1, MrVector v2, double angle )
{
	double cosTheta = MrMath::Dot(v1, v2);
	double rotationAngle = angle;

	// rotation axis and angle
	MrVector rotationAxis;

	// speacial case when vectors in same directions:
	// there is no "ideal" rotation axis
	// So guess one; any will do as long as it's perpendicular to v1
	if ( cosTheta > 1 - 0.001f )
	{
		rotationAxis = MrMath::Cross(v1, MrVector(1.0, 0.0, 0.0));

		if ( MrMath::Norm(rotationAxis) < 0.01 )	// parallel with v1... try again
			rotationAxis = MrVector(0.0, 1.0, 0.0);
					
	}

	// speacial case when vectors in oppsite directions:
	// there is no "ideal" rotation axis
	// So guess one; any will do as long as it's perpendicular to v1
	else if ( cosTheta < -1 + 0.001f )
	{
		rotationAxis = MrMath::Cross(v1, MrVector(1.0, 0.0, 0.0));

		if ( MrMath::Norm(rotationAxis) < 0.01 )	// parallel with v1... try again
			rotationAxis = MrVector(0.0, 1.0, 0.0);
	}

	else
	{
		rotationAxis = MrMath::Cross(v1, v2);
		rotationAxis = MrMath::Normalize(rotationAxis);
	}


	// rotation matrix
	double c = cos( rotationAngle );
	double s = sin( rotationAngle );
	double t = 1 - c;

	MrMatrix rotationMatrix;
	rotationMatrix.SetRows( MrVector( t * pow(rotationAxis.X(), 2) + c,
									  t * rotationAxis.X() * rotationAxis.Y() - s * rotationAxis.Z(),
									  t * rotationAxis.X() * rotationAxis.Z() + s * rotationAxis.Y() ),
							MrVector( t * rotationAxis.Y() * rotationAxis.X() + s * rotationAxis.Z(),
									  t * pow(rotationAxis.Y(), 2) + c,
									  t * rotationAxis.Y() * rotationAxis.Z() - s * rotationAxis.X() ),
							MrVector( t * rotationAxis.Z() * rotationAxis.X() - s * rotationAxis.Y(),
									  t * rotationAxis.Z() * rotationAxis.Y() + s * rotationAxis.X(), 
									  t * pow(rotationAxis.Z(), 2) + c) );

	return rotationMatrix;
}

/**
	@brief					Rotate a constrained part by a rotation matrix

	@param rotationMatrix	Rotation matrix

	@param coordinate		Global coordinate system of constrained part

	@return					Rotated coordinate system
*/
MrAxis2 PmeStdAssemblyConstraint::RotateCoordinate( MrMatrix rotationMatrix, MrAxis2 coordinate )
{
	// Point position after rotation
	MrVector transPos = MrMath::Multiply(rotationMatrix, MrVector(coordinate.Location()));
			
	MrPosition	Position(transPos.X(), transPos.Y(), transPos.Z());
	MrDirection XDir = MrDirection(MrMath::Multiply(rotationMatrix, MrVector(coordinate.XDirection())));
	MrDirection ZDir = MrDirection(MrMath::Multiply(rotationMatrix, MrVector(coordinate.ZDirection())));
			
	MrAxis2 coordinateSystem(Position, ZDir, XDir);
				
	return coordinateSystem;
}

/**
	@brief		Calculate a translation vector between two vectors.

	@param v1	First vector to calculate a translation vector.

	@param v2	Second vector to calculate a translation vector.

	@return		Translation vector
*/
MrVector PmeStdAssemblyConstraint::Translation(MrVector v1, MrVector v2)
{
	MrVector t;

	MrPosition p = MrPosition(v1.X() - v2.X(), v1.Y() - v2.Y(), v1.Z() - v2.Z());


	t.SetCoordinates(p.X(), p.Y(), p.Z());

	return t;
}

/**
	@brief		Calculate a translation vector by using a vector and given distance.

	@param v1	First vector to calculate a translation vector.

	@param d	Distance value to calculate a translation vector.

	@return		Translation vector
*/
MrVector PmeStdAssemblyConstraint::Translation(MrVector v1, double d)
{
	MrVector result;

	result = v1.operator*=(d);

	return result;
}

/**
	@brief			whether this face is planar or not.
	
	@param pFace	target face want to check.

	@return			true if the face is linear, false if not.
*/
bool PmeStdAssemblyConstraint::IsPlanarFace(FACE * pFace)
{
	SURFACE * pSurface = pFace->geometry();
	const surface & surfaceEquation = pSurface->equation();
	int isPlanar = surfaceEquation.planar(SPAposition(0.0,0.0,0.0), SPAunit_vector(0.0, 0.0, 1.0));

	if ( isPlanar == 1 ) { return true; }

	else if ( isPlanar == 0 ) { return false; }
}

/**
	@brief			whether this edge is linear or not.
	
	@param pEdge	target edge want to check.

	@return			true if the edge is linear, false if not.
*/
bool PmeStdAssemblyConstraint::IsLinearEdge(EDGE *pEdge)
{
	CURVE * pCurve = pEdge->geometry();
	const curve & curveEquation = pCurve->equation();
	
	// linear is 0 and circular is 1
	int periodic = curveEquation.periodic();
	
	if ( periodic == 0 ) { return true; }

	else if (periodic == 1 ) { return false; }
}


/**
	@brief			Apply a parallel constraint.

	@param pPart	constrained part to be rotated.
					
	@param v1		constrained geometry vector.\n
					if constrained geometry is face, v1 is (normalized)normal vector.\n
					if constrained geometry is edge, v1 is (normalized)vector start to end point.

	@param v2		reference geometry vector.\n
					if constrained geometry is face, v2 is (normalized)normal vector.\n
					if constrained geometry is edge, v2 is (normalized)vector start to end point.
*/
void PmeStdAssemblyConstraint::ApplyParallel( PmePart * constrainedPart, MrVector v1, MrVector v2 )
{
	// Calculate a rotation matrix
	MrMatrix rMatrix = GetRotationMatrix( v1, v2 );

	MrAxis2 coPartCSYS = constrainedPart->GetPlacement();

	// Adopt a rotation matrix to constrained part
	MrAxis2 rotatedAxis = RotateCoordinate(rMatrix, coPartCSYS);

	// for pivot rotation, go to initial position		
	rotatedAxis.SetLocation(MrPosition( coPartCSYS.Location().X(),
										coPartCSYS.Location().Y(),
										coPartCSYS.Location().Z()));

	rotatedAxis.XDirection() = coPartCSYS.XDirection();
	rotatedAxis.YDirection() = coPartCSYS.YDirection();
	rotatedAxis.ZDirection() = coPartCSYS.ZDirection();
			
	constrainedPart->SetPlacement(rotatedAxis);
}

/**
	@brief			Apply a translation vector to constrained part.

	@param partCSYS	Constrained part to be applied new axis.

	@param t		Translation vector.

	@return			Calculated axis consist of coordinates and directions.
*/
MrAxis2 PmeStdAssemblyConstraint::SetTranslationResult(MrAxis2 partCSYS, MrVector t)
{
	MrAxis2 result;

	result.SetLocation(MrPosition(partCSYS.Location().X() + t.X(),
								  partCSYS.Location().Y() + t.Y(),
								  partCSYS.Location().Z() + t.Z()));

	result.SetXDirection(partCSYS.XDirection());
	result.SetYDirection(partCSYS.YDirection());
	result.SetZDirection(partCSYS.ZDirection());

	return result;
}

/**
	@brief			Whether constrained geometry is located at outside of reference geometry
	@param coAxis	center(or mid) point position of constrained geometry
	@param refAxis	center(or mid) point position of reference geometry
	@return			true if constrained part is located at outside of reference part, false if not.
*/
bool PmeStdAssemblyConstraint::IsOutside( MrAxis2 coAxis, MrAxis2 refAxis )
{
	MrVector ref2co = MrVector(coAxis.Location().X() - refAxis.Location().X(),
							   coAxis.Location().Y() - refAxis.Location().Y(),
							   coAxis.Location().Z() - refAxis.Location().Z());

	MrVector m_refNormal;
	m_refNormal.SetCoordinates(refAxis.ZDirection().X(), refAxis.ZDirection().Y(), refAxis.ZDirection().Z());

	double distWithSign = MrMath::Dot(ref2co, m_refNormal);

	if ( distWithSign >= 0 ) { return true; }
	
	else { return false; }	
}