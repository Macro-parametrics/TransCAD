#include "StdAfx.h"
#include ".\PmeStdSketchVDirection.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchVDirection, PmeObject)

PmeStdSketchVDirection::PmeStdSketchVDirection(PmeStdSketchFeature * pSketchFeature)
: m_pSketchFeature(pSketchFeature)
{
}

PmeStdSketchVDirection::~PmeStdSketchVDirection(void)
{
}

DCM_g_type PmeStdSketchVDirection::DcmGetIdentify()
{
	return DCM_LINE;
}

void PmeStdSketchVDirection::DcmTransform(double [3][3])
{
}

void PmeStdSketchVDirection::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchVDirection::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	m_pGNode = pDcm->add_g(static_cast<IPmeDcmLine *>(this));
	pDcm->fix(m_pGNode);
}

void PmeStdSketchVDirection::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	if(m_pGNode)
        pDcm->erase(m_pGNode);
	m_pGNode = 0;
}

void PmeStdSketchVDirection::DcmGetPosition(double pt[2])
{
	pt[0] = 0.0;
	pt[1] = 0.0;
}

void PmeStdSketchVDirection::DcmGetDirection(double dir[2])
{
	dir[0] = 0.0;
    dir[1] = 1.0;
}