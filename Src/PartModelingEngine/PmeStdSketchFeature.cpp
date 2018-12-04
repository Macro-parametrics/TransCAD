#include "StdAfx.h"
#include ".\pmestdsketchfeature.h"
#include ".\PmeStdSketchOrigin.h"
#include ".\PmeStdSketchHDirection.h"
#include ".\PmeStdSketchVDirection.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchGeometry.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchConstraints.h"
#include ".\PmeStdSketchConstraint.h"
#include ".\PmeSketch.h"
#include ".\PmePart.h"
#include ".\PmeExplicitModel.h"
#include ".\PmeBrepReference.h"
#include ".\PmeExceptionTest.h"
#include ".\PmeIlligalOperationException.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeDatumPlane.h"
#include ".\PmeDatumPlaneUtility.h"
#include ".\PmeQuery.h"
#include ".\PmeArgumentTypeException.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchFeature, PmeStdFeature)

PmeStdSketchFeature::PmeStdSketchFeature(PmePart * pPart, PmeReference * pSketchPlane)
: PmeStdFeature(pPart)
, m_pSketchPlane(pSketchPlane)
, m_pSketch(0)
{
	m_coordinateSystem = GetReferenceCoordinateSystem(pSketchPlane);

	Initialize();
}

PmeStdSketchFeature::~PmeStdSketchFeature(void)
{
	Uninitialize();
}

void PmeStdSketchFeature::Initialize(void)
{
	m_pOrigin = new PmeStdSketchOrigin(this);
	m_pHDirection = new PmeStdSketchHDirection(this);
	m_pVDirection = new PmeStdSketchVDirection(this);
	m_pGeometries = new PmeStdSketchGeometries();
	m_pConstraints = new PmeStdSketchConstraints();
}

void PmeStdSketchFeature::Uninitialize(void)
{
	ClearConstraints();
	ClearGeometries();

	ASSERT(m_pConstraints);
	delete m_pConstraints;

	ASSERT(m_pGeometries);
	delete m_pGeometries;

	ASSERT(m_pVDirection);
	delete m_pVDirection;

	ASSERT(m_pHDirection);
	delete m_pHDirection;

	ASSERT(m_pOrigin);
	delete m_pOrigin;
}

void PmeStdSketchFeature::ClearConstraints(void)
{
	PmeStdSketchConstraints::SizeType size = m_pConstraints->GetSize();

	for(PmeStdSketchConstraints::SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchConstraint * pConstraint = m_pConstraints->GetItem(i);
		if(pConstraint)
			delete pConstraint;
	}
}

void PmeStdSketchFeature::ClearGeometries(void)
{
	PmeStdSketchGeometries::SizeType size = m_pGeometries->GetSize();
	
	for(PmeStdSketchGeometries::SizeType i = 0; i < size; ++ i)
	{
		PmeStdSketchGeometry * pGeometry = m_pGeometries->GetItem(i);
		if(pGeometry)
			delete pGeometry;
	}
}

// 아직 이미 만들어진 스케치를 수정하는 기능은 없다.
void PmeStdSketchFeature::Update(void)
{
	SetParentName(m_pSketchPlane);
	
	PmePart * pPart = GetPart();

	MrAxis2 temp = GetReferenceCoordinateSystem(m_pSketchPlane);

	if(!MrMath::IsCoplanar(m_coordinateSystem, temp))
	{
		m_coordinateSystem = temp;
	}

	/// 17-03-13 권순조 수정
	// 스케치 평면의 방향이 반전되었을 때 스케치 방향도 반전 (ex. Datum Plane이 Flip된 경우)
	// 임의로 스케치 좌표계를 스케치 평면의 방향과 반대로 설정한 경우에도 진입
	if(MrMath::IsOpposite(m_coordinateSystem.ZDirection(), temp.ZDirection()))
	{
		m_coordinateSystem.SetXDirection(temp.XDirection());
		m_coordinateSystem.SetYDirection(temp.YDirection());
		m_coordinateSystem.SetZDirection(temp.ZDirection());
	}
	///

	PmeExplicitModel * pExplicitModel = pPart->GetExplicitModel();

	m_pSketch = new PmeSketch();
	pExplicitModel->Add(m_pSketch);
	
	m_pSketch->SetName(GetName());
	m_pSketch->SetCreator(this);
}

MrAxis2 PmeStdSketchFeature::GetReferenceCoordinateSystem(PmeReference * pSketchPlane)
{
	MrAxis2 coordinateSystem;

	switch(pSketchPlane->GetReferenceType())
	{
	case PmeReferenceType_ExplicitModelObject:
		coordinateSystem = PmeDatumPlaneUtility::GetCoordinateSystem(pSketchPlane);
		break;
	case PmeReferenceType_Brep:
		{
			ENTITY * pEntity = GetPart()->GetSelectionManager()->GetBrepFromReference(pSketchPlane);
			PmeThrowExceptionIf<PmeArgumentTypeException>(strcmp(pEntity->type_name(), "face") != 0);

            coordinateSystem = PmeQueryFaceLocalCoordinate((FACE *)pEntity);
		}
		break;
	}

	return coordinateSystem;
}

void PmeStdSketchFeature::DeleteItemByName(CString name)
{
	PmeStdSketchGeometry * pGeometry = m_pGeometries->FindByName(name);
	
	if(pGeometry)
		delete pGeometry;
}

bool PmeStdSketchFeature::IsInversed(void)
{
	MrAxis2 temp = GetReferenceCoordinateSystem(m_pSketchPlane);
	
	if (MrMath::IsEqual(temp.ZDirection(), m_coordinateSystem.ZDirection()))
		return false;
	else
		return true;
}

bool PmeStdSketchFeature::HasCenterLine(void)
{
	for (int i = 0; i < m_pGeometries->GetSize(); ++i)
	{
		if (m_pGeometries->GetItem(i)->GetType() == PmeStdSketchGeometryType_Centerline)
			return true;
	}

	return false;
}