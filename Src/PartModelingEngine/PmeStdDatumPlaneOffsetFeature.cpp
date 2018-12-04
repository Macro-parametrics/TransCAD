#include "StdAfx.h"
#include ".\PmeStdDatumPlaneOffsetFeature.h"
#include ".\PmeStdDatumPlaneFeature.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeSolid.h"
#include ".\PmeDatumPlaneUtility.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeArgumentTypeException.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeQuery.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdDatumPlaneOffsetFeature, PmeStdDatumFeature)

PmeStdDatumPlaneOffsetFeature::PmeStdDatumPlaneOffsetFeature(PmePart * pPart)
: PmeStdDatumPlaneFeature(pPart)
{
}

PmeStdDatumPlaneOffsetFeature::PmeStdDatumPlaneOffsetFeature(PmePart * pPart,
															PmeReference * pSelectedPlane,
															double distance,
															bool isFlip)
: PmeStdDatumPlaneFeature(pPart)
, m_pSelectedPlane(pSelectedPlane)
, m_distance(distance)
, m_isFlip(isFlip)
{
	m_isFree = false;
}

PmeStdDatumPlaneOffsetFeature::PmeStdDatumPlaneOffsetFeature(PmePart * pPart,
	double ox, double oy, double oz,// Origin location 
	double xx, double xy, double xz,// X axis coords
	double yx, double yy, double yz,// Y axis coords
	bool isFlip)
: PmeStdDatumPlaneFeature(pPart)
, m_origin(ox,oy,oz)
, m_xDir(xx,xy,xz)
, m_yDir(yx,yy,yz)
, m_isFlip(isFlip)
{
	m_distance = 0.0;
	m_isFree = true;
}

PmeStdDatumPlaneOffsetFeature::~PmeStdDatumPlaneOffsetFeature(void)
{
}

void PmeStdDatumPlaneOffsetFeature::Update(void)
{
	if(!m_isFree)
	{
		SetParentName(m_pSelectedPlane);
		
		MrDirection zDir = GetInternalDirection();
		PmeThrowExceptionIf<PmeIlligalOperationException>(m_distance < 0);

		if(m_isFlip)
			zDir = -zDir;
		
		MrVector zOffVec(zDir, m_distance);

		MrAxis2 coordinateSystem;

		// 기본 좌표 평면과 Face 선택을 모두 고려 (17-02-14 권순조)
		switch(m_pSelectedPlane->GetReferenceType())
		{
		case PmeReferenceType_ExplicitModelObject:
			coordinateSystem = PmeDatumPlaneUtility::GetCoordinateSystem(m_pSelectedPlane);
			break;
		case PmeReferenceType_Brep:
			{
				ENTITY * pEntity = GetPart()->GetSelectionManager()->GetBrepFromReference(m_pSelectedPlane);
				PmeThrowExceptionIf<PmeArgumentTypeException>(strcmp(pEntity->type_name(), "face") != 0);

				coordinateSystem = PmeQueryFaceLocalCoordinate((FACE *)pEntity);
			}
			break;
		}
		//

		coordinateSystem.SetLocation(MrMath::Add(coordinateSystem.Location(), zOffVec));

		m_origin = coordinateSystem.Location();
		m_xDir = coordinateSystem.XDirection();
		m_yDir = coordinateSystem.YDirection();

		m_pDatumPlane = new PmeDatumPlane(coordinateSystem);
		m_pDatumPlane->SetOffsetFlag(true);
		m_pDatumPlane->SetName(GetName());
		m_pDatumPlane->SetCreator(this);
		GetPart()->GetExplicitModel()->Add(m_pDatumPlane);
	}
	else
	{
		MrVector vx(m_xDir, 1.0);
		MrVector vy(m_yDir, 1.0);
		MrVector vz = MrMath::Cross(vx, vy);

		MrDirection zDir(vz);

		if(m_isFlip)
			zDir = -zDir;

		m_coordinateSystem = MrAxis2(m_origin, zDir, m_xDir);
		m_coordinateSystem.SetYDirection(m_yDir);
		
		m_pDatumPlane = new PmeDatumPlane(m_coordinateSystem);
		m_pDatumPlane->SetOffsetFlag(true);
		m_pDatumPlane->SetName(GetName());
		m_pDatumPlane->SetCreator(this);
		GetPart()->GetExplicitModel()->Add(m_pDatumPlane);
	}
}

MrDirection PmeStdDatumPlaneOffsetFeature::GetInternalDirection()
{
	MrAxis2 oldCoordinateSystem;

	if(!m_isFree)
	{
		// 기본 좌표 평면과 Face 선택을 모두 고려 (17-02-14 권순조)
		switch(m_pSelectedPlane->GetReferenceType())
		{
		case PmeReferenceType_ExplicitModelObject:
			oldCoordinateSystem = PmeDatumPlaneUtility::GetCoordinateSystem(m_pSelectedPlane);
			break;
		case PmeReferenceType_Brep:
			{
				ENTITY * pEntity = GetPart()->GetSelectionManager()->GetBrepFromReference(m_pSelectedPlane);
				PmeThrowExceptionIf<PmeArgumentTypeException>(strcmp(pEntity->type_name(), "face") != 0);

				oldCoordinateSystem = PmeQueryFaceLocalCoordinate((FACE *)pEntity);
			}
			break;
		}
		//
	}
	else
		oldCoordinateSystem = m_coordinateSystem;
		
	MrDirection zDir = oldCoordinateSystem.ZDirection();
	MrVector zVec(zDir, 1.0);
	MrVector znVec = MrMath::Normalize(zVec);

	return MrDirection(znVec);
}
