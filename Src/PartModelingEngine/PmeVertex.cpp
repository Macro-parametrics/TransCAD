#include "StdAfx.h"
#include "PmeVertex.h"
#include "PmeVertices.h"
#include ".\PmePersistentName.h"

PME_IMPLEMENT_RUNTIME_TYPE(PmeVertex, PmeObject)

PmeVertex::PmeVertex(VERTEX * pVertex)
	:m_pVertex(pVertex)
{
	SPAposition coords = pVertex->geometry()->coords();
	
	SPAtransf transform;

	if (m_pVertex->edge()->coedge()->loop()->face()->shell()->lump()->body()->transform())
		transform = m_pVertex->edge()->coedge()->loop()->face()->shell()->lump()->body()->transform()->transform();
	
	coords *= transform;
	
	m_pCoordinates.SetX(coords.x());
	m_pCoordinates.SetY(coords.y());
	m_pCoordinates.SetZ(coords.z());
}

PmeVertex::~PmeVertex(void)
{
}

CString PmeVertex::GetName(void)
{
	m_name = PmePersistentName::FindVertexName(m_pVertex);
	return m_name;
}
