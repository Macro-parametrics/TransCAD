#include "StdAfx.h"
#include ".\pmestdsketchPerpendicular.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchPerpendicular, PmeStdSketchConstraint)

PmeStdSketchPerpendicular::PmeStdSketchPerpendicular(PmeStdSketchFeature * pSketchFeature, PmeReference * pReferenceEdit, PmeReference * pTarget)
: PmeStdSketchConstraint(pSketchFeature)
, m_pReferenceEdit(pReferenceEdit)
, m_pTarget(pTarget)
, m_pDNode(0)
{
	
}

PmeStdSketchPerpendicular::~PmeStdSketchPerpendicular(void)
{
}

IPmeConstraintable * PmeStdSketchPerpendicular::GetGeometryPart(PmeReference * pReference)
{
	PmeStdSketchGeometry* pGeometry = pReference->GetPart()->GetSelectionManager()->GetSketchGeometryFromReference(pReference);
	return (IPmeConstraintable*)(pGeometry);

// 	if(pGeometry->GetType() == PmeStdSketchGeometryType_Line)
// 	{
// 		PmeStdSketchLine* pLine = static_cast<PmeStdSketchLine*>(pGeometry);
// 		return (IPmeConstraintable*)(pLine->GetStartPoint());
// 	}
}

void PmeStdSketchPerpendicular::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	g_node * pGNode1 = GetGeometryPart(m_pReferenceEdit)->GetGNode();
	g_node * pGNode2 = GetGeometryPart(m_pTarget)->GetGNode();
	
	d_node * pDNode = pDcm->add_d((void *)static_cast<PmeDcmPerpendicular *>(this), pGNode1, pGNode2);
	SetDNode(pDNode);
}

void PmeStdSketchPerpendicular::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	d_node * pDNode = GetDNode();

	if(pDNode)
        pDcm->erase(pDNode);
	SetDNode(0);
}