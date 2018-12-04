#include "StdAfx.h"
#include <math.h>
#include ".\PmeStdSketchCircularArc.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchCircularArc, PmeStdSketchGeometry)

PmeStdSketchCircularArc::PmeStdSketchCircularArc(PmeStdSketchFeature * pSketchFeature, PmeStdSketchControlPoint * pCenterPoint, double radius, PmeStdSketchControlPoint * pStartPoint, PmeStdSketchControlPoint * pEndPoint)
: PmeStdSketchGeometry(pSketchFeature)
, m_pCenterPoint(pCenterPoint)
, m_radius(radius)
, m_pStartPoint(pStartPoint)
, m_pEndPoint(pEndPoint)
, m_pConcentricCenterPoint(0)
, m_pStartPointOnArc(0)
, m_pEndPointOnArc(0)
{
}

PmeStdSketchCircularArc::~PmeStdSketchCircularArc(void)
{
	if(m_pConcentricCenterPoint)
		delete m_pConcentricCenterPoint;
	m_pConcentricCenterPoint = 0;

	if(m_pStartPointOnArc)
		delete m_pStartPointOnArc;
	m_pStartPointOnArc = 0;

	if(m_pEndPointOnArc)
		delete m_pEndPointOnArc;
	m_pEndPointOnArc = 0;
}

double PmeStdSketchCircularArc::GetStartAngle(void) const
{
	PmeStdSketchControlPoint * pCenterPoint = GetCenterPoint();
	PmeStdSketchControlPoint * pStartPoint = GetStartPoint();
	
	double startAngle;
	
	startAngle = atan2(pStartPoint->GetY() - pCenterPoint->GetY(), pStartPoint->GetX() - pCenterPoint->GetX());
	if(startAngle < 0)
		startAngle += 2.0 * M_PI;

	return startAngle;
}

double PmeStdSketchCircularArc::GetEndAngle(void) const
{
	PmeStdSketchControlPoint * pCenterPoint = GetCenterPoint();
	PmeStdSketchControlPoint * pEndPoint = GetEndPoint();
	
	double endAngle;
	
	endAngle = atan2(pEndPoint->GetY() - pCenterPoint->GetY(), pEndPoint->GetX() - pCenterPoint->GetX());
	if(endAngle < 0)
		endAngle += 2.0 * M_PI;

	return endAngle;
}

DCM_g_type PmeStdSketchCircularArc::DcmGetIdentify()
{
	return DCM_CIRCLE;
}

void PmeStdSketchCircularArc::DcmTransform(double mat[3][3])
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

void PmeStdSketchCircularArc::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchCircularArc::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = pDcm->add_g(static_cast<IPmeDcmCircle *>(this));
	SetGNode(pGNode);	

	m_pConcentricCenterPoint = new PmeDcmConcentric();
	pDcm->add_d(m_pConcentricCenterPoint, pGNode, GetCenterPoint()->GetGNode());	

	m_pStartPointOnArc = new PmeDcmCoincident();
	m_pEndPointOnArc = new PmeDcmCoincident();
	pDcm->add_d(m_pStartPointOnArc, pGNode, GetStartPoint()->GetGNode());
	pDcm->add_d(m_pEndPointOnArc, pGNode, GetEndPoint()->GetGNode());
}

void PmeStdSketchCircularArc::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = GetGNode();

	if(pGNode)
        pDcm->erase(pGNode);
	SetGNode(0);
}

void PmeStdSketchCircularArc::DcmGetCenter(double pt[2])
{
	PmeStdSketchControlPoint * pCenterPoint = GetCenterPoint();

	pt[0] = pCenterPoint->GetX();
	pt[1] = pCenterPoint->GetY();
}

double PmeStdSketchCircularArc::DcmGetRadius()
{
	return m_radius;
}

void PmeStdSketchCircularArc::DcmSetRadius(double radius)
{
	m_radius = radius;
}