#include "StdAfx.h"
#include ".\PmeStdSketchHDirection.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchHDirection, PmeObject)

PmeStdSketchHDirection::PmeStdSketchHDirection(PmeStdSketchFeature * pSketchFeature)
: m_pSketchFeature(pSketchFeature)
, m_pGNode(0)
{
}

PmeStdSketchHDirection::~PmeStdSketchHDirection(void)
{
}

DCM_g_type PmeStdSketchHDirection::DcmGetIdentify()
{
	return DCM_LINE;
}

void PmeStdSketchHDirection::DcmTransform(double [3][3])
{
}

void PmeStdSketchHDirection::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchHDirection::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	m_pGNode = pDcm->add_g(static_cast<IPmeDcmLine *>(this));
	pDcm->fix(m_pGNode);
}

void PmeStdSketchHDirection::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	if(m_pGNode)
        pDcm->erase(m_pGNode);
	m_pGNode = 0;
}

void PmeStdSketchHDirection::DcmGetPosition(double pt[2])
{
	pt[0] = 0.0;
	pt[1] = 0.0;
}

void PmeStdSketchHDirection::DcmGetDirection(double dir[2])
{
	dir[0] = 1.0;
    dir[1] = 0.0;
}