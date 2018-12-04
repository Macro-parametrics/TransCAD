#pragma once

#include ".\PmMacro.h"
#include <vector>

class PmHView;

enum PmSelectionType
{
	PmSelectionType_Body,
	PmSelectionType_Face,
	PmSelectionType_Edge,
	PmSelectionType_Vertex
};

class PM_API PmHSelectionSet
	: public HSelectionSet
{
public:
	PmHSelectionSet(PmHView * pHView);
	~PmHSelectionSet(void);

    virtual void Select(HC_KEY key, int num_include_keys, HC_KEY * include_keys, bool emit_message = false);
	virtual void Select(ENTITY* entity, bool emit_message = true);
	virtual void DeSelectAll(void);

	virtual ENTITY * GetSelectedEntityAt(int index) const;
    virtual int  GetSelectedListSize(void) const;
	virtual void ClearSelectedList(void);

	void SetSelectionType(PmSelectionType type) { m_selectionType = type; }
    const PmSelectionType GetSelectionType(void) { return m_selectionType;} 

	ENTITY * GetSelectedEntity(void) {return m_pSelectedEntity;}

private:
	PmSelectionType m_selectionType;
	ENTITY * m_pSelectedEntity;
	int	m_selectLevel;
	std::vector<ENTITY *> m_listSelectedEntity;
	bool m_showFacesAsLines;
	bool m_multiSelectActive;
};