#include "StdAfx.h"
#include ".\PmeStdSketchLine.h"
#include ".\PmeStdSketchFeature.h"
#include ".\PmeStdSketchGeometries.h"
#include ".\PmeStdSketchControlPoint.h"
#include ".\PmeStdSketchEditor.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeStdSketchLine, PmeStdSketchGeometry)

PmeStdSketchLine::PmeStdSketchLine(PmeStdSketchFeature * pSketchFeature, PmeStdSketchControlPoint * pStartPoint, PmeStdSketchControlPoint * pEndPoint)
: PmeStdSketchGeometry(pSketchFeature)
, m_pStartPoint(pStartPoint)
, m_pEndPoint(pEndPoint)
, m_pStartPointOnLine(0)
, m_pEndPointOnLine(0)
{
}

PmeStdSketchLine::~PmeStdSketchLine(void)
{
	if(m_pStartPointOnLine)
		delete m_pStartPointOnLine;
	m_pStartPointOnLine = 0;

	if(m_pEndPointOnLine)
		delete m_pEndPointOnLine;
	m_pEndPointOnLine = 0;
}

DCM_g_type PmeStdSketchLine::DcmGetIdentify()
{
	return DCM_LINE;
}

void PmeStdSketchLine::DcmTransform(double mat[3][3])
{
	PmeStdSketchControlPoint * pStartPoint = GetStartPoint();
	PmeStdSketchControlPoint * pEndPoint = GetEndPoint();

	double x = pStartPoint->GetX();
	double y = pStartPoint->GetY();

	double dx = pEndPoint->GetX() - x;
	double dy = pEndPoint->GetY() - y;
	
	double t;
	
	t = mat[0][0] * x + mat[0][1] * y + mat[0][2];
	y = mat[1][0] * x + mat[1][1] * y + mat[1][2];
	x = t;
	
	t = mat[0][0] * dx + mat[0][1] * dy;
	dy = mat[1][0] * dx + mat[1][1] * dy;
	dx = t;

	pStartPoint->SetPosition(x, y);
	pEndPoint->SetPosition(x + dx, y + dy);
}

void PmeStdSketchLine::DcmSetStatus(g_node_status status)
{
}

void PmeStdSketchLine::UpdateDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = pDcm->add_g(static_cast<IPmeDcmLine *>(this));
	SetGNode(pGNode);	

//  2009-04-23, removed by suchul
//	m_pStartPointOnLine = new PmeDcmCoincident();
//	m_pEndPointOnLine = new PmeDcmCoincident();
//	pDcm->add_d(m_pStartPointOnLine, pGNode, GetStartPoint()->GetGNode());
//	pDcm->add_d(m_pEndPointOnLine, pGNode, GetEndPoint()->GetGNode());
}

void PmeStdSketchLine::CleanDcmInfo(PmeStdSketchEditor * pEditor)
{
	dimension_system * pDcm = pEditor->GetDcm();
	g_node * pGNode = GetGNode();

	if(pGNode)
        pDcm->erase(pGNode);
	SetGNode(0);
}

void PmeStdSketchLine::DcmGetPosition(double pt[2])
{
	PmeStdSketchControlPoint * pStartPoint = GetStartPoint();

	pt[0] = pStartPoint->GetX();
	pt[1] = pStartPoint->GetY();
}

void PmeStdSketchLine::DcmGetDirection(double dir[2])
{
	PmeStdSketchControlPoint * pStartPoint = GetStartPoint();
	PmeStdSketchControlPoint * pEndPoint = GetEndPoint();

	double x = pStartPoint->GetX();
	double y = pStartPoint->GetY();

	double dx = pEndPoint->GetX() - x;
	double dy = pEndPoint->GetY() - y;

	dir[0] = dx;
    dir[1] = dy;
}