#include "StdAfx.h"
#include ".\PmHSelectionSet.h"
#include ".\PmHView.h"
#include ".\PmHModel.h"
#include "vlist.h" 

PmHSelectionSet::PmHSelectionSet(PmHView * pHView)
: HSelectionSet(pHView)
, m_pSelectedEntity(0)
{
	m_selectionType = PmSelectionType_Body;
	
	m_showFacesAsLines = false;
	m_multiSelectActive = false;
	SetAllowEntitySelection(true);
	m_selectLevel = FACE_TYPE;
}

PmHSelectionSet::~PmHSelectionSet(void)
{
}

void PmHSelectionSet::Select(HC_KEY key, int num_include_keys, HC_KEY * include_keys, bool emit_message)
{
	HC_KEY keys[40000];
    int count = 0, c;

    ENTITY * entity = 0;

	if(m_selectionType == PmSelectionType_Body)  // && 'body segments is true
        entity = HA_Compute_Entity_Pointer(key, BODY_TYPE);
    else if(m_selectionType == PmSelectionType_Face)
        entity = HA_Compute_Entity_Pointer(key, FACE_TYPE);
    else if(m_selectionType == PmSelectionType_Edge)
        entity = HA_Compute_Entity_Pointer(key, EDGE_TYPE);
	else if(m_selectionType == PmSelectionType_Vertex)
        entity = HA_Compute_Entity_Pointer(key, VERTEX_TYPE);	

	if(entity)
	{
        m_pSelectedEntity = entity;
		m_listSelectedEntity.push_back(entity);

        if(m_selectionType == PmSelectionType_Body)  // && 'body segments is true
            count = HA_Compute_Geometry_Keys(entity, 1, keys, "bodies");
        else if(m_selectionType == PmSelectionType_Face)
            count = HA_Compute_Geometry_Keys(entity, 40000, keys, "faces");
        else if(m_selectionType == PmSelectionType_Edge)
            count = HA_Compute_Geometry_Keys(entity, 40000, keys, "edges");
		else if(m_selectionType == PmSelectionType_Vertex)
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

void PmHSelectionSet::Select(ENTITY * entity, bool emit_message)
{
	HC_KEY	keys[40000];
	int		count = 0, c;
	
	int eclass;	
	eclass = entity->identity();
	HC_KEY incl_keys[1] = {m_pView->GetIncludeLinkKey()};
	
	if (m_pView->GetRenderMode() == HRenderHiddenLine && eclass == FACE_TYPE)
	{
		if (entity)
		{
			m_listSelectedEntity.push_back(entity);
			count = HA_Compute_Geometry_Keys(entity, 40000, keys, "edges");
			
			for (c = 0; c < count; c++)
				HSelectionSet::Select(keys[c], 1, incl_keys, emit_message); // call base class fcn for each key
			
			ENTITY_LIST edges;
			int num_edges;
			outcome result = api_get_edges( entity, edges );
			ASSERT(result.ok());
			num_edges = edges.iteration_count();
			for (int i = 0; i < num_edges; i ++)
			{
				count = HA_Compute_Geometry_Keys(edges[i], 40000, keys, "edges");
				for (c = 0; c < count; c++) 
					HSelectionSet::Select(keys[c], 1, incl_keys, emit_message); // call base class fcn for each key
			}
		}			 			
	}
	else
	{
		if (entity)
		{
			m_listSelectedEntity.push_back(entity);
			if (eclass == BODY_TYPE)  // && body segments is true 
				count = HA_Compute_Geometry_Keys(entity, 1, keys, "bodies");
			else if (eclass == FACE_TYPE)
			{
				count = HA_Compute_Geometry_Keys(entity, 40000, keys, "faces");
				if (m_showFacesAsLines)
				{
					ENTITY_LIST edges;
					int num_edges;
					outcome result = api_get_edges( entity, edges );
					ASSERT(result.ok());
					num_edges = edges.iteration_count();
					for (int i=0;i<num_edges;i++)
					{
						int ecount = HA_Compute_Geometry_Keys(edges[i], 40000-count, &keys[count], "edges");
						count += ecount;
					}
				}
			}			
			else if (eclass == EDGE_TYPE)
				count = HA_Compute_Geometry_Keys(entity, 40000, keys, "edges");
			else if (eclass == VERTEX_TYPE)
				count = HA_Compute_Geometry_Keys(entity, 40000, keys, "vertices");
			
		}
		
		ASSERT(count < 40000);
		
		if (count)
		{
			for (c = 0; c < count; c++)
			{
				HSelectionSet::Select(keys[c], 1, incl_keys, emit_message); // call base class fcn for each key
			}
		}
	}
}

void PmHSelectionSet::DeSelectAll()
{
	ClearSelectedList();

	HSelectionSet::DeSelectAll();
	m_pView->EmitDeSelectAllMessage();
}

ENTITY * PmHSelectionSet::GetSelectedEntityAt(int index) const
{
	return m_listSelectedEntity[index];
}

int PmHSelectionSet::GetSelectedListSize(void) const
{
	return (int)m_listSelectedEntity.size();
}

void PmHSelectionSet::ClearSelectedList(void)
{
	m_listSelectedEntity.clear();
}