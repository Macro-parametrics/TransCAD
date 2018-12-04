#include "StdAfx.h"
#include ".\pmestdsketchcontrolpoint.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchControlPoint, PmeStdSketchGeometry)

PmeStdSketchControlPoint::PmeStdSketchControlPoint(PmeStdSketchFeature * pSketchFeature, double x, double y)
: PmeStdSketchGeometry(pSketchFeature)
, m_x(x)
, m_y(y)
{
}

PmeStdSketchControlPoint::~PmeStdSketchControlPoint(void)
{
}

void PmeStdSketchControlPoint::SetPosition(double x, double y)
{
	m_x = x;
	m_y = y;
}

DCM_g_type PmeStdSketchControlPoint::DcmGetIdentify()
{
	return DCM_POINT;
}

void PmeStdSketchControlPoint::DcmTransform(double mat[3][3])
{
	double x = GetX();
	double y = GetY();

	double t;
	
	t = mat[0][0] * x + mat[0][1] * y + mat[0][2];
	y = mat[1][0] * x + mat[1][1] * y + mat[1][2];
	x = t;	

	SetPosition(x, y);
}

void PmeStdSketchControlPoint::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchControlPoint::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = pDcm->add_g(static_cast<IPmeDcmPoint *>(this));
	SetGNode(pGNode);
}

void PmeStdSketchControlPoint::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = GetGNode();

	if(pGNode)
        pDcm->erase(pGNode);
	SetGNode(0);
}

void PmeStdSketchControlPoint::DcmGetPosition(double pt[2])
{
	pt[0] = GetX();
	pt[1] = GetY();
}