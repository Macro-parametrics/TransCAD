#include "StdAfx.h"
#include ".\pmestdsketchParallel.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchParallel, PmeStdSketchConstraint)

PmeStdSketchParallel::PmeStdSketchParallel(PmeStdSketchFeature * pSketchFeature, PmeReference * pReferenceEdit, PmeReference * pTarget)
: PmeStdSketchConstraint(pSketchFeature)
, m_pReferenceEdit(pReferenceEdit)
, m_pTarget(pTarget)
, m_pDNode(0)
{
	
}

PmeStdSketchParallel::~PmeStdSketchParallel(void)
{
}

IPmeConstraintable * PmeStdSketchParallel::GetGeometryPart(PmeReference * pReference)
{
	PmeStdSketchGeometry* pGeometry = pReference->GetPart()->GetSelectionManager()->GetSketchGeometryFromReference(pReference);
	return (IPmeConstraintable*)(pGeometry);

// 	if(pGeometry->GetType() == PmeStdSketchGeometryType_Line)
// 	{
// 		PmeStdSketchLine* pLine = static_cast<PmeStdSketchLine*>(pGeometry);
// 		return (IPmeConstraintable*)(pLine->GetStartPoint());
// 	}
}

void PmeStdSketchParallel::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	g_node * pGNode1 = GetGeometryPart(m_pReferenceEdit)->GetGNode();
	g_node * pGNode2 = GetGeometryPart(m_pTarget)->GetGNode();
	
	d_node * pDNode = pDcm->add_d((void *)static_cast<PmeDcmParallel *>(this), pGNode1, pGNode2);
	SetDNode(pDNode);
}

void PmeStdSketchParallel::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	d_node * pDNode = GetDNode();

	if(pDNode)
        pDcm->erase(pDNode);
	SetDNode(0);
}