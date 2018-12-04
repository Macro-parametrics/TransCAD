#include "StdAfx.h"
#include ".\pmesolid.h"
#include "PmeFaces.h"
#include "PmeFace.h"
#include "PmeEdges.h"
#include "PmeEdge.h"
#include "PmeVertices.h"
#include "PmeVertex.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeSolid, PmeExplicitModelObject)

PmeSolid::PmeSolid(void)
: m_pBody(0)
{
	m_pFaces = new PmeFaces();
	m_pEdges = new PmeEdges();
	m_pVertices = new PmeVertices();
}

PmeSolid::~PmeSolid(void)
{
	m_pBody = NULL;
	delete m_pFaces;
	delete m_pEdges;
	delete m_pVertices;
}

void PmeSolid::UpdateSolid(BODY * pBody)
{
	m_pBody = pBody;
}

PmeFaces * PmeSolid::GetFaces(void)
{
	m_pFaces->Clear();
	
	if (m_pBody != NULL)
	{
		ENTITY_LIST faces;
		
		api_get_faces(m_pBody, faces);
		
		for (int i = 0; i < faces.count(); ++i)
			m_pFaces->Add(new PmeFace((FACE *)faces[i]));
	}

	return m_pFaces;
}

PmeEdges * PmeSolid::GetEdges(void)
{
	m_pEdges->Clear();
	
	if (m_pBody != NULL)
	{
		ENTITY_LIST edges;
		
		api_get_edges(m_pBody, edges);

		for (int i = 0; i < edges.count(); ++i)
			m_pEdges->Add(new PmeEdge((EDGE *)edges[i]));
	}

	return m_pEdges;
}

PmeVertices * PmeSolid::GetVertices(void)
{
	m_pVertices->Clear();
	
	if (m_pBody != NULL)
	{
		ENTITY_LIST vertices;
		
		api_get_vertices(m_pBody, vertices);

		for (int i = 0; i < vertices.count(); ++i)
			m_pVertices->Add(new PmeVertex((VERTEX *)vertices[i]));
	}

	return m_pVertices;
}