#include "StdAfx.h"
#include "PmeFace.h"
#include "PmeFaces.h"
#include ".\PmePersistentName.h"
#include "PmeEdge.h"
#include "PmeEdges.h"
#include "PmeVertex.h"
#include "PmeVertices.h"
#include "MrMath.h"
#include "PmeQuery.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeFace, PmeObject)

PmeFace::PmeFace(FACE * pFace)
	:m_pFace(pFace)
{
	m_pEdges = new PmeEdges();
	m_pVertices = new PmeVertices();
	GetProperties();
}

PmeFace::~PmeFace(void)
{
	delete m_pEdges;
	delete m_pVertices;
}

CString PmeFace::GetName(void)
{
	m_name = PmePersistentName::FindFaceName(m_pFace);
	return m_name;
}

PmeFaceType PmeFace::GetFaceType(void)
{
	if (is_planar_face(m_pFace))
		m_pFaceType = PmeFaceType_Plane;
	else if (is_cylindrical_face(m_pFace))
		m_pFaceType = PmeFaceType_Cylinder;
	else if (is_conical_face(m_pFace))
		m_pFaceType = PmeFaceType_Cone;
	else if (is_spherical_face(m_pFace))
		m_pFaceType = PmeFaceType_Sphere;
	else if (is_toroidal_face(m_pFace))
		m_pFaceType = PmeFaceType_Torus;
	else if (is_spline_face(m_pFace))
		m_pFaceType = PmeFaceType_Spline;

	return m_pFaceType;
}

PmeEdges * PmeFace::GetEdges(void)
{
	m_pEdges->Clear();
	
	if (m_pFace != NULL)
	{
		ENTITY_LIST edges;
		
		api_get_edges(m_pFace, edges);

		for (int i = 0; i < edges.count(); ++i)
			m_pEdges->Add(new PmeEdge((EDGE *)edges[i]));
	}

	return m_pEdges;
}

PmeVertices * PmeFace::GetVertices(void)
{
	m_pVertices->Clear();
	
	if (m_pFace != NULL)
	{
		ENTITY_LIST vertices;
		
		api_get_vertices(m_pFace, vertices);

		for (int i = 0; i < vertices.count(); ++i)
			m_pVertices->Add(new PmeVertex((VERTEX *)vertices[i]));
	}

	return m_pVertices;
}

void PmeFace::GetProperties(void)
{
	double area;					// area returned
	SPAposition centre;				// centroid return
	
	API_BEGIN
		double req_rel_accy = 0;		// relative precision desired
		double moment_a;				// first principal moment
		double moment_b;				// second principal moment
		SPAunit_vector axis_a;			// first principal axis
		SPAunit_vector axis_b;			// second principal axis
		double est_rel_accy_achieved;	// estimate of relative accuracy achieved
		AcisOptions* ao = NULL;
		
		result = api_planar_face_pr(m_pFace, req_rel_accy, area, centre, moment_a, moment_b, axis_a, axis_b, est_rel_accy_achieved, ao);
		check_outcome(result);
	API_END

	SPAtransf transform;

	if (m_pFace->shell()->lump()->body()->transform())
		transform = m_pFace->shell()->lump()->body()->transform()->transform();
	
	centre *= transform;

	m_pCentroid.SetCoordinates(centre.x(), centre.y(), centre.z());

	MrAxis2 axis = PmeQueryFaceLocalCoordinate(m_pFace);
	m_pXDirection = axis.XDirection();
	m_pYDirection = axis.YDirection();
	m_pZDirection = axis.ZDirection();

	m_pArea = area;
}