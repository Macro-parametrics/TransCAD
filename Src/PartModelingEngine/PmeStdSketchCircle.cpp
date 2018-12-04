#include "StdAfx.h"
#include ".\pmestdsketchcircle.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchCircle, PmeStdSketchGeometry)

PmeStdSketchCircle::PmeStdSketchCircle(PmeStdSketchFeature * pSketchFeature, PmeStdSketchControlPoint * pCenterPoint, double radius)
: PmeStdSketchGeometry(pSketchFeature)
, m_pCenterPoint(pCenterPoint)
, m_radius(radius)
, m_pConcentricCenterPoint(0)
{
}

PmeStdSketchCircle::~PmeStdSketchCircle(void)
{
	if(m_pConcentricCenterPoint)
		delete m_pConcentricCenterPoint;
	m_pConcentricCenterPoint = 0;
}

DCM_g_type PmeStdSketchCircle::DcmGetIdentify()
{
	return DCM_CIRCLE;
}

void PmeStdSketchCircle::DcmTransform(double mat[3][3])
{
	PmeStdSketchControlPoint * pCenterPoint = GetCenterPoint();

	double x = pCenterPoint->GetX();
	double y = pCenterPoint->GetY();

	double t;
	
	t = mat[0][0] * x + mat[0][1] * y + mat[0][2];
	y = mat[1][0] * x + mat[1][1] * y + mat[1][2];
	x = t;

	pCenterPoint->SetPosition(x, y);
}

void PmeStdSketchCircle::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchCircle::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = pDcm->add_g(static_cast<IPmeDcmCircle *>(this));
	SetGNode(pGNode);	

	m_pConcentricCenterPoint = new PmeDcmConcentric();
	pDcm->add_d(m_pConcentricCenterPoint, pGNode, GetCenterPoint()->GetGNode());	
}

void PmeStdSketchCircle::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = GetGNode();

	if(pGNode)
        pDcm->erase(pGNode);
	SetGNode(0);
}

void PmeStdSketchCircle::DcmGetCenter(double pt[2])
{
	PmeStdSketchControlPoint * pCenterPoint = GetCenterPoint();

	pt[0] = pCenterPoint->GetX();
	pt[1] = pCenterPoint->GetY();
}

double PmeStdSketchCircle::DcmGetRadius()
{
	return m_radius;
}

void PmeStdSketchCircle::DcmSetRadius(double radius)
{
	m_radius = radius;
}