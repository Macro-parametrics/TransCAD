#include "stdafx.h"
#include ".\AssemHSelectionSet.h"
#include ".\AssemHView.h"
#include ".\AssemHModel.h"
#include "vlist.h" 

AssemHSelectionSet::AssemHSelectionSet(AssemHView * pHView)
: HSelectionSet(pHView)
, m_pSelectedEntity(0)
{
	m_selectionType = AssemSelectionType_Body;

	m_showFacesAsLines = false;
	m_multiSelectActive = false;
	SetAllowEntitySelection(true);
	m_selectLevel = FACE_TYPE;
}

AssemHSelectionSet::~AssemHSelectionSet(void)
{
}

void AssemHSelectionSet::Select(HC_KEY key, int num_include_keys, HC_KEY * include_keys, bool emit_message)
{

	//HSelectionSet::SetSelectionEdgeWeight( 1.5 );
	HC_KEY keys[40000];
	
	int count = 0, c;
 	
	ENTITY * entity = 0;
 
	if(m_selectionType == AssemSelectionType_Body)  // && 'body segments is true
		entity = HA_Compute_Entity_Pointer(key, BODY_TYPE);
	else if(m_selectionType == AssemSelectionType_Face)
		entity = HA_Compute_Entity_Pointer(key, FACE_TYPE);
	else if(m_selectionType == AssemSelectionType_Edge)
		entity = HA_Compute_Entity_Pointer(key, EDGE_TYPE);
	else if(m_selectionType == AssemSelectionType_Vertex)
		entity = HA_Compute_Entity_Pointer(key, VERTEX_TYPE);	
 
	if(entity)
	{
		m_pSelectedEntity = entity;
 
		if(m_selectionType == AssemSelectionType_Body)  // && 'body segments is true
			count = HA_Compute_Geometry_Keys(entity, 1, keys, "bodies");
		else if(m_selectionType == AssemSelectionType_Face)
			count = HA_Compute_Geometry_Keys(entity, 40000, keys, "faces");
		else if(m_selectionType == AssemSelectionType_Edge)
			count = HA_Compute_Geometry_Keys(entity, 40000, keys, "edges");
 		else if(m_selectionType == AssemSelectionType_Vertex)
			count = HA_Compute_Geometry_Keys(entity, 40000, keys, "vertices");
	}
 
	assert(count < 40000);
   
	if(count)
	{
		for(c = 0; c < count; c ++)
 		{
			// call base class for each key
			HSelectionSet::Select(keys[c], 0, 0, emit_message);
 		}
	}

	else
		HSelectionSet::Select(key, num_include_keys, include_keys, emit_message);

}

void AssemHSelectionSet::DeSelectAll( void )
{
	ClearSelectedList();

	HSelectionSet::DeSelectAll();
	m_pView->EmitDeSelectAllMessage();
}

void AssemHSelectionSet::ClearSelectedList(void)
{
	m_listSelectedEntity.clear();
}

ENTITY * AssemHSelectionSet::GetSelectedEntityAt( int index ) const
{
	return m_listSelectedEntity[ index ];
}

int AssemHSelectionSet::GetSelectedListSize(void) const
{
	return (int)m_listSelectedEntity.size();
}