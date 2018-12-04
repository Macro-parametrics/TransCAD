#pragma once

#include "AssemMacro.h"
#include <vector>

class AssemHView;

enum AssemSelectionType
{
	AssemSelectionType_Body,
	AssemSelectionType_Face,
	AssemSelectionType_Edge,
	AssemSelectionType_Vertex
};

class ASSEM_API AssemHSelectionSet
	: public HSelectionSet 
{
public:
	AssemHSelectionSet( AssemHView * pHView );
	~AssemHSelectionSet( void );

    virtual void Select( HC_KEY key, int num_include_keys, HC_KEY * include_keys, bool emit_message = false );
	virtual void DeSelectAll( void );

	virtual ENTITY * GetSelectedEntityAt( int index ) const;
	virtual int GetSelectedListSize( void ) const;
	virtual void ClearSelectedList( void );

	void SetSelectionType( AssemSelectionType type ) { m_selectionType = type; }
    const AssemSelectionType GetSelectionType( void ) { return m_selectionType; } 

	ENTITY * GetSelectedEntity( void ) { return m_pSelectedEntity; }

private:
	AssemSelectionType m_selectionType;
	ENTITY * m_pSelectedEntity;
	std::vector<ENTITY *> m_listSelectedEntity;

	int m_selectLevel;
	bool m_showFacesAsLines;
	bool m_multiSelectActive;
};