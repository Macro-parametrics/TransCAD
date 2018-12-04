#include "StdAfx.h"
#include ".\pmestdsketchVertical.h"
#include ".\PmeStdSketchEditor.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmePart.h"
#include ".\PmeSelectionManager.h"
#include ".\PmeStdSketchVDirection.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchVertical, PmeStdSketchConstraint)

PmeStdSketchVertical::PmeStdSketchVertical(PmeStdSketchFeature * pSketchFeature, PmeReference * pTarget)
: PmeStdSketchConstraint(pSketchFeature)
, m_pTarget(pTarget)
, m_pDNode(0)
{
	
}

PmeStdSketchVertical::~PmeStdSketchVertical(void)
{
}

IPmeConstraintable * PmeStdSketchVertical::GetGeometryPart(PmeReference * pReference)
{
	PmeStdSketchGeometry* pGeometry = pReference->GetPart()->GetSelectionManager()->GetSketchGeometryFromReference(pReference);
	return (IPmeConstraintable*)(pGeometry);

// 	if(pGeometry->GetType() == PmeStdSketchGeometryType_Line)
// 	{
// 		PmeStdSketchLine* pLine = static_cast<PmeStdSketchLine*>(pGeometry);
// 		return (IPmeConstraintable*)(pLine->GetStartPoint());
// 	}
}

void PmeStdSketchVertical::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	g_node * pGNode1 = GetSketchFeature()->GetVDirection()->GetGNode();
	g_node * pGNode2 = GetGeometryPart(m_pTarget)->GetGNode();
	
	d_node * pDNode = pDcm->add_d((void *)static_cast<PmeDcmParallel *>(this), pGNode1, pGNode2);
	SetDNode(pDNode);
}

void PmeStdSketchVertical::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	d_node * pDNode = GetDNode();

	if(pDNode)
        pDcm->erase(pDNode);
	SetDNode(0);
}