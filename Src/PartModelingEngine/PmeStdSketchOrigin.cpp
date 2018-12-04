#include "StdAfx.h"
#include ".\pmestdsketchorigin.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchOrigin, PmeObject)

PmeStdSketchOrigin::PmeStdSketchOrigin(PmeStdSketchFeature * pSketchFeature)
: m_pSketchFeature(pSketchFeature)
{
}

PmeStdSketchOrigin::~PmeStdSketchOrigin(void)
{
}

DCM_g_type PmeStdSketchOrigin::DcmGetIdentify()
{
	return DCM_POINT;
}

void PmeStdSketchOrigin::DcmTransform(double [3][3])
{
}

void PmeStdSketchOrigin::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchOrigin::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	m_pGNode = pDcm->add_g(static_cast<IPmeDcmPoint *>(this));
	pDcm->fix(m_pGNode);
}

void PmeStdSketchOrigin::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();

	if(m_pGNode)
        pDcm->erase(m_pGNode);
	m_pGNode = 0;
}

void PmeStdSketchOrigin::DcmGetPosition(double pt[2])
{
	pt[0] = 0.0;
	pt[1] = 0.0;
}