#include "StdAfx.h"
#include ".\pmestdsketchcoincident.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchCircle.h"
#include ".\PmeStdSketchCircularArc.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchCoincident, PmeStdSketchConstraint)

//PmeStdSketchCoincident::PmeStdSketchCoincident(PmeStdSketchFeature * pSketchFeature, IPmeConstraintable * pFirstGeometry, IPmeConstraintable * pSecondGeometry)
PmeStdSketchCoincident::PmeStdSketchCoincident(PmeStdSketchFeature * pSketchFeature, PmeReference * pFirstGeometry, PmeSamePointsType firstType, PmeReference * pSecondGeometry, PmeSamePointsType secondType)
: PmeStdSketchConstraint(pSketchFeature)
, m_pFirstGeometry(pFirstGeometry)
, m_FirstType(firstType)
, m_pSecondGeometry(pSecondGeometry)
, m_SecondType(secondType)
, m_pDNode(0)
{
	
}

PmeStdSketchCoincident::~PmeStdSketchCoincident(void)
{
}

// 2009.10.29, Suchul Shin
IPmeConstraintable * PmeStdSketchCoincident::GetGeometryPart(PmeReference * pReference, PmeSamePointsType type)
{
	PmeStdSketchGeometry* pGeometry = pReference->GetPart()->GetSelectionManager()->GetSketchGeometryFromReference(pReference);

	if(type == PmeSamePointsType_StartPoint)
	{
		if(pGeometry->GetType() == PmeStdSketchGeometryType_Line)
		{
			PmeStdSketchLine* pLine = static_cast<PmeStdSketchLine*>(pGeometry);
			return (IPmeConstraintable*)(pLine->GetStartPoint());
		}
		else if(pGeometry->GetType() == PmeStdSketchGeometryType_CircularArc)
		{
			PmeStdSketchCircularArc* pArc = static_cast<PmeStdSketchCircularArc*>(pGeometry);
			return (IPmeConstraintable*)(pArc->GetStartPoint());
		}
		else
			return NULL;
	}
	else if(type == PmeSamePointsType_EndPoint)
	{
		if(pGeometry->GetType() == PmeStdSketchGeometryType_Line)
		{
			PmeStdSketchLine* pLine = static_cast<PmeStdSketchLine*>(pGeometry);
			return (IPmeConstraintable*)(pLine->GetEndPoint());
		}
		else if(pGeometry->GetType() == PmeStdSketchGeometryType_CircularArc)
		{
			PmeStdSketchCircularArc* pArc = static_cast<PmeStdSketchCircularArc*>(pGeometry);
			return (IPmeConstraintable*)(pArc->GetEndPoint());
		}
		else
			return NULL;
	}
	else if(type == PmeSamePointsType_CenterPoint)
	{
		if(pGeometry->GetType() == PmeStdSketchGeometryType_Circle)
		{
			PmeStdSketchCircle* pCIrcle = static_cast<PmeStdSketchCircle*>(pGeometry);
			return (IPmeConstraintable*)(pCIrcle->GetCenterPoint());
		}
		else if(pGeometry->GetType() == PmeStdSketchGeometryType_CircularArc)
		{
			PmeStdSketchCircularArc* pArc = static_cast<PmeStdSketchCircularArc*>(pGeometry);
			return (IPmeConstraintable*)(pArc->GetCenterPoint());
		}
		else
			return NULL;
	}
	else
		return NULL;
}

void PmeStdSketchCoincident::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	g_node * pGNode1 = GetGeometryPart(m_pFirstGeometry, m_FirstType)->GetGNode();
	g_node * pGNode2 = GetGeometryPart(m_pSecondGeometry, m_SecondType)->GetGNode();

// 	g_node * pGNode1 = GetFirstGeometry()->GetGNode();
// 	g_node * pGNode2 = GetSecondGeometry()->GetGNode();
	
	d_node * pDNode = pDcm->add_d((void *)static_cast<PmeDcmCoincident *>(this), pGNode1, pGNode2);
	SetDNode(pDNode);
}

void PmeStdSketchCoincident::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	d_node * pDNode = GetDNode();

	if(pDNode)
        pDcm->erase(pDNode);
	SetDNode(0);
}