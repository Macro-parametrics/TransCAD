#include "StdAfx.h"
#include "PmeEdge.h"
#include "PmeEdges.h"
#include "PmeVertex.h"
#include ".\PmePersistentName.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeEdge, PmeObject)

PmeEdge::PmeEdge(EDGE * pEdge)
	:m_pEdge(pEdge)
{
	m_pStartPoint = new PmeVertex(pEdge->start());
	m_pEndPoint = new PmeVertex(pEdge->end());
}

PmeEdge::~PmeEdge(void)
{
	delete m_pStartPoint;
	delete m_pEndPoint;
}

CString PmeEdge::GetName(void)
{
	m_name = PmePersistentName::FindEdgeName(m_pEdge);
	return m_name;
}

PmeEdgeType PmeEdge::GetEdgeType(void)
{
	if (is_linear_edge(m_pEdge))
		m_pEdgeType = PmeEdgeType_Line;
	else if (is_circular_edge(m_pEdge))
		m_pEdgeType = PmeEdgeType_Circle;
	else if (is_elliptical_edge(m_pEdge))
		m_pEdgeType = PmeEdgeType_Ellipse;
	else if (is_helical_edge(m_pEdge))
		m_pEdgeType = PmeEdgeType_Helix;
	else if (is_intcurve_edge(m_pEdge))
		m_pEdgeType = PmeEdgeType_Spline;
	
	return m_pEdgeType;
}
